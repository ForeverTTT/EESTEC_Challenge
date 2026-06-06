import os
import re
import sys
import termios
import select


PORT = "/dev/cu.usbmodem103"
BAUD = termios.B115200
ANSI_RE = re.compile(r"\x1b\[[0-9;?]*[A-Za-z]")
LABEL_RE = re.compile(r"^label:\s*(?P<label>.+?)\s*:\s*score:\s*(?P<score>[0-9.]+)")
LABEL_ORDER = ["unlabeled", "East", "Nord", "South", "West"]
LABEL_SHORT = {
    "unlabeled": "U",
    "East": "E",
    "Nord": "N",
    "South": "S",
    "West": "W",
}
last_line_len = 0


def configure_serial(fd):
    attrs = termios.tcgetattr(fd)
    attrs[0] = 0
    attrs[1] = 0
    attrs[2] = termios.CS8 | termios.CREAD | termios.CLOCAL
    attrs[3] = 0
    attrs[4] = BAUD
    attrs[5] = BAUD
    termios.tcsetattr(fd, termios.TCSANOW, attrs)


def clean_text(data):
    return ANSI_RE.sub("", data.decode("utf-8", errors="replace")).replace("\r", "")


def render(labels, output):
    global last_line_len

    scores = " ".join(
        f"{LABEL_SHORT[label]}={labels[label]:.2f}"
        for label in LABEL_ORDER
        if label in labels
    )
    prediction = output.removeprefix("Output:").strip() or "-"
    line = f"Current: {prediction:<9} | {scores}"

    try:
        columns = os.get_terminal_size().columns
    except OSError:
        columns = 80
    line = line[: max(1, columns - 1)]

    sys.stdout.write("\r" + " " * last_line_len + "\r" + line)
    sys.stdout.flush()
    last_line_len = len(line)


def handle_line(line, labels):
    line = line.strip()
    if not line:
        return

    match = LABEL_RE.match(line)
    if match:
        labels[match.group("label").strip()] = float(match.group("score"))
        return

    if line.startswith("Output:"):
        render(labels, line)


def main():
    fd = os.open(PORT, os.O_RDWR | os.O_NOCTTY | os.O_NONBLOCK)
    try:
        configure_serial(fd)
        print(f"Listening on {PORT} at 115200. Press Ctrl+C to stop.", flush=True)

        buffer = ""
        labels = {}

        while True:
            ready, _, _ = select.select([fd], [], [], 0.25)
            if fd not in ready:
                continue

            try:
                data = os.read(fd, 4096)
            except BlockingIOError:
                continue
            if not data:
                continue

            buffer += clean_text(data)
            lines = buffer.split("\n")
            buffer = lines.pop()
            for line in lines:
                handle_line(line, labels)

    except KeyboardInterrupt:
        print("\nStopped.")
    finally:
        os.close(fd)


if __name__ == "__main__":
    main()
