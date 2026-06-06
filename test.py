
import os, sys, time, termios, select

port = '/dev/cu.usbmodem103'
fd = os.open(port, os.O_RDWR | os.O_NOCTTY | os.O_NONBLOCK)

try:
    attrs = termios.tcgetattr(fd)
    attrs[0] = 0
    attrs[1] = 0
    attrs[2] = termios.CS8 | termios.CREAD | termios.CLOCAL
    attrs[3] = 0
    attrs[4] = termios.B115200
    attrs[5] = termios.B115200
    termios.tcsetattr(fd, termios.TCSANOW, attrs)

    print(f'Listening on {port} at 115200. Press Ctrl+C to stop.')
    while True:
        r, _, _ = select.select([fd], [], [], 0.25)
        if fd in r:
            data = os.read(fd, 4096)
            if data:
                sys.stdout.write(data.decode('utf-8', errors='replace'))
                sys.stdout.flush()
except KeyboardInterrupt:
    print('\nStopped.')
finally:
    os.close(fd)