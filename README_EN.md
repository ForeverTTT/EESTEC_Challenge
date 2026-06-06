<img src="./img/infineon_logo.png" alt="Infineon Logo" height="50"/>

# Emergency Vehicle Direction of Arrival

**Extended implementation of the Infineon Hackathon Challenge**

> **Languages:** [English](./README_EN.md) · [中文](./README.md)

This project extends the official [Infineon Emergency Vehicle Direction of Arrival Hackathon](https://github.com/Infineon/hackathon) repository. The original challenge requires a PSOC™ Edge E84 AI Kit with a dual-microphone array to classify, in real time, which direction an emergency vehicle siren (East, Nord, South, or West) is coming from.

Building on the official example and the DEEPCRAFT™ Studio workflow, we implemented the full pipeline — **data collection → model fine-tuning → embedded deployment → live validation** — and simplified the development flow significantly: **no Eclipse ModusToolbox™ IDE required; one command to build and flash; plug in the board and run.**

---

## Table of Contents

- [Project Background](#project-background)
- [What's New](#whats-new)
- [Directory Structure](#directory-structure)
- [Approach & Methodology](#approach--methodology)
  - [1. Problem Formulation & Motivation](#1-problem-formulation--motivation)
  - [2. Overall Pipeline](#2-overall-pipeline)
  - [3. Data Collection & Labeling Strategy](#3-data-collection--labeling-strategy)
  - [4. Feature Engineering](#4-feature-engineering)
  - [5. Model Architecture Design](#5-model-architecture-design)
  - [6. Training Strategy & Convergence Analysis](#6-training-strategy--convergence-analysis)
  - [7. Experimental Results & Model Selection](#7-experimental-results--model-selection)
  - [8. Conclusion](#8-conclusion)
- [Key Highlights](#key-highlights)
- [Quick Start](#quick-start)
- [Requirements](#requirements)
- [References](#references)

---

## Project Background

| Item | Description |
|------|-------------|
| Original challenge | Infineon Hackathon — Emergency Vehicle Direction of Arrival |
| Hardware | PSOC™ Edge E84 AI Kit (dual PDM microphones) |
| ML toolchain | DEEPCRAFT™ Studio (collection, labeling, training, export) |
| Deployment | ModusToolbox™ + TensorFlow Lite for Microcontrollers |
| Classification | 5 classes: East / Nord / South / West / unlabeled |

The original repository provides a deployment example and Hackathon materials. Our core contributions are: **custom directional data collection, Conv1D model fine-tuning, and a fully scripted deployment workflow**.

Related Hackathon materials:
- [Topic Introduction Slides](./topic_introduction.pdf)
- [Challenge Introduction Slides](./challenge_introduction.pdf)
- Original README backup: [README_challenge.md](./README_challenge.md)

---

## What's New

The following directories and files were added on top of the official Git repository:

| Path | Type | Purpose |
|------|------|---------|
| `finetuned_model/` | DEEPCRAFT project | Final fine-tuned model (trained `.h5` weights and export config) |
| `LiveDataCollection/` | DEEPCRAFT project | Live data collection project with 40 directional recordings (10 per direction) |
| `sounds/` | Audio assets | Reference siren/ambulance sounds for playback during collection |
| `test_models/` | Model candidates | Alternative model versions kept for comparison during training |
| `test/` | Embedded project | PSOC Edge deployment project with the fine-tuned model (ModusToolbox tri-core) |
| `flash_model.sh` | Shell script | One-command build and flash to the board |
| `model.py` | Python | DEEPCRAFT-exported preprocessing pipeline (Mel features, reproducible on PC) |
| `test.py` | Python | Serial monitor script for live on-board inference output |
| `assets/` | Documentation images | Methodology, training curves, confusion matrices, etc. |

---

## Directory Structure

### `finetuned_model/` — Final Fine-Tuned Model

DEEPCRAFT™ Studio ML project, adapted from the official Siren Detection Accelerator for direction-of-arrival classification.

```
finetuned_model/
├── SirenDetection.improj      # DEEPCRAFT project file
├── Models/
│   └── conv1d-medium-balanced-1/   # Final selected model
│       ├── conv1d-medium-balanced-1.h5
│       ├── conv1d-medium-balanced-1_min_max.md
│       └── ... (test input/output files)
└── metadata.json
```

- Contains full training history and model export configuration
- The C code deployed in `test/` is generated from this project
- Open the `.improj` in DEEPCRAFT Studio to inspect or continue training

### `LiveDataCollection/` — Live Data Collection

DEEPCRAFT Studio live data collection starter project. Labels are applied during recording, which greatly reduces data preparation time.

```
LiveDataCollection/
├── Main.imunit                # Collection graph (PC mic + serial device inputs)
├── LiveDataCollection.improjv
├── model.py                   # Preprocessing reference implementation
├── east1 … east10             # East direction recordings (10)
├── nord1 … nord10             # Nord direction recordings (10)
├── south1 … south10           # South direction recordings (10)
├── west1 … west10             # West direction recordings (10)
└── conv1d-small-balanced-1/   # Early training model snapshot
```

**Collection workflow:**
1. Pick a consistent sound source from `sounds/` (recommended: `chirp_beacon` or `wws_fireengine_siren.ogg`)
2. Place a single speaker at a fixed direction (e.g. East)
3. Run `Main.imunit` in DEEPCRAFT Studio; record and click direction label buttons in real time
4. Save the session and repeat for the other three directions

Directional waveforms are shown in [Approach & Methodology — Data Collection](#3-data-collection--labeling-strategy) (Figures 2–4).

### `sounds/` — Reference Audio

Standardized playback sources for data collection. Using the same signal for all directions avoids source variation interfering with direction learning.

| File | Description |
|------|-------------|
| `chirp_beacon_600_3500hz_100ms_gap20ms_2min.wav` | **Recommended primary source**: locally generated wideband chirp beacon, highly repeatable, suited for dual-mic DOA |
| `wws_fireengine_siren.ogg` | Fire engine siren (Work With Sounds, CC-BY-4.0) |
| `wws_policecar_siren.ogg` | Two-tone police siren |
| `ambulance_sound_1/2.wav` | Short ambulance clips (loop for longer sessions) |
| `SOURCES.md` | Full attribution, licenses, and selection guide |

> **Collection tip:** Use one sound source throughout the experiment; use a single physical speaker (no stereo spread). See `sounds/SOURCES.md` for details.

### `test_models/` — Model Comparison Candidates

Alternative model versions kept during training for side-by-side evaluation:

```
test_models/
├── conv1d-small-balanced-2/   # Candidate B
└── conv1d-small-balanced-4/   # Candidate D (contains balanced-3 weights)
```

Each directory includes `.h5` weights, quantization min/max config, and preprocessor/network test files for quick switching in DEEPCRAFT.

### `test/` — Embedded Deployment Project

Adapted from Infineon's official `PSOC_Edge_Machine_Learning_DEEPCRAFT_Deploy_Audio` example, with the fine-tuned model and preprocessing integrated.

```
test/
├── Makefile              # Top-level Application Makefile (MTB_TYPE=APPLICATION)
├── common.mk             # Shared config (TARGET, TOOLCHAIN, ML_DEEPCRAFT_CPU, etc.)
├── common_app.mk         # Application-level shared config
├── proj_cm33_s/          # CM33 Secure project
├── proj_cm33_ns/         # CM33 Non-Secure project (contains model.c/.h)
├── proj_cm55/            # CM55 project (default inference core, contains model.c/.h)
├── bsps/                 # Board support package
└── configs/              # Boot/signing configuration
```

- Tri-core layout: CM33 Secure → CM33 Non-Secure → CM55, all running XIP from external QSPI Flash
- Default inference on **CM55** with INT8 quantization (`ML_DEEPCRAFT_CPU=cm55`, `NN_TYPE=int8x8`)
- Board outputs per-direction confidence scores and final prediction over UART (115200 baud)

### `flash_model.sh` — One-Command Build & Flash

```bash
#!/usr/bin/env bash
make -C test build TOOLCHAIN=GCC_ARM
make -C test program TOOLCHAIN=GCC_ARM
```

Replaces the Build + Program steps in Eclipse ModusToolbox™. Requires ModusToolbox™ installed and `CY_TOOLS_DIR` configured.

### `model.py` — Preprocessing Pipeline (Python)

DEEPCRAFT Studio auto-generated Python preprocessing code, **bit-for-bit equivalent** to the on-device C preprocessing. Use it to:

- Verify feature extraction offline on PC
- Understand or debug Mel spectrogram generation
- Integrate as a standalone Python module in other test scripts

The core `Model` class exposes a queue-based API (`enqueue` / `dequeue`):

```
Raw PCM (2ch) → 512-sample sliding window → Hann window → RDFT → Frobenius norm
→ 30-band Mel filterbank → Clip → Log → 50×30 feature matrix
```

### `test.py` — Live Inference Monitor

Reads UART output from the board and displays the current predicted direction and per-class confidence in the terminal:

```
Current: East      | U=0.12 E=0.87 N=0.03 S=0.01 W=0.02
```

**Set the serial port before running:**

```python
PORT = "/dev/cu.usbmodem103"   # macOS
# PORT = "COM3"                # Windows
```

Run:

```bash
python test.py
```

---

## Approach & Methodology

This section presents the full research rationale from problem definition to model deployment, written in the style of a technical report. All experimental screenshots come from DEEPCRAFT™ Studio training and evaluation interfaces; original files are stored in `assets/`.

### 1. Problem Formulation & Motivation

The Infineon Hackathon task is **Emergency Vehicle Direction of Arrival**: given a dual-PDM-microphone audio stream on the PSOC™ Edge E84 AI Kit, classify in real time whether an emergency siren is coming from **East, Nord, South, or West**.

Unlike the official Siren Detection Accelerator (binary: siren / no siren), we reformulate the problem as **five-class classification** — adding an `unlabeled` class for scenes without a valid siren signal. This design is motivated by:

1. **Deployment reality:** Vehicles are not always near sirens; the model must distinguish directional sirens from background noise.
2. **Dual-mic DOA information:** Direction is encoded in **inter-aural time difference (ITD)** and **level difference (ILD)** between the two microphone channels, not in single-channel spectral content alone. A controlled, repeatable sound source is needed to elicit these cues.
3. **Edge constraints:** Inference on PSOC Edge CM55 must run under INT8 quantization with low memory and low latency, which directly limits model size and feature dimensionality.

### 2. Overall Pipeline

Given these constraints, we designed the following end-to-end pipeline:

```
Reference audio (sounds/) → Directional playback + Live Labeling (LiveDataCollection/)
    → Mel spectrogram features (preprocessing pipeline)
    → Lightweight Conv1D classifier (conv1d-small / medium)
    → INT8 deployment (test/) → UART live output (test.py)
```

Key design principles:

| Stage | Approach | Rationale |
|-------|----------|-----------|
| Sound source | Single chirp beacon or fixed siren file | Avoid spurious features from playing different sounds at different directions |
| Collection | Live Labeling during recording | Eliminate post-hoc segmentation errors; shorten data prep cycle |
| Features | Log-Mel spectrogram (50×30) | Compatible with DEEPCRAFT/Imagimob ecosystem; mature on-device C implementation |
| Model | 1D CNN (~4.5K params) | Balance accuracy and MCU compute budget |
| Deployment | Makefile CLI build | Remove Eclipse IDE dependency; enable scriptable CI/CD |

### 3. Data Collection & Labeling Strategy

#### 3.1 Collection Protocol

Data was collected in a controlled lab setup:

- **Hardware:** PSOC™ Edge E84 AI Kit with fixed dual-PDM microphone array
- **Source:** Single speaker, 30–50 cm from the board, placed sequentially at East / Nord / South / West
- **Signal:** Prefer locally generated `chirp_beacon` (600–3500 Hz wideband chirp, 100 ms pulse + 20 ms gap) — its wideband nature is more sensitive to dual-mic phase/amplitude differences and far more repeatable than real siren recordings
- **Tool:** DEEPCRAFT Studio `LiveDataCollection` project with PC microphone recording and synchronized Live Labeling

#### 3.2 Dataset Composition & Split

The final dataset contains **11 min 48 s** of labeled audio, split approximately 80/10/10 into train, validation, and test sets. Four directional classes each have ~2.5 min of balanced data; the `unlabeled` class (2 min 03 s) captures ambient noise without siren.

<p align="center">
  <img src="./assets/data%20split.png" alt="Dataset split statistics" width="900"/>
  <br/>
  <em><strong>Figure 1.</strong> Class distribution and Train / Validation / Test split (DEEPCRAFT Studio Data Explorer). Four directional classes are balanced (~02:20–02:31 each); total labeled data 09:44, 11:48 including unlabeled.</em>
</p>

| Class | Total duration | Train | Val | Test |
|-------|----------------|-------|-----|------|
| East | 02:31 | 77% | 14% | 9% |
| Nord | 02:25 | 81% | 9% | 11% |
| South | 02:20 | 78% | 11% | 11% |
| West | 02:27 | 80% | 10% | 10% |
| unlabeled | 02:03 | 85% | 9% | 6% |

#### 3.3 Directional Waveforms

The following figures show typical Live Labeling sessions for East, Nord, and West. Each session contains multiple short pulse segments (chirp beacon playback) separated by silence; the Live Labeling track (blue blocks) aligns precisely with energy bursts in the waveform, confirming temporal annotation accuracy.

<p align="center">
  <img src="./assets/data%20east.png" alt="East direction waveform" width="900"/>
  <br/>
  <em><strong>Figure 2.</strong> East direction session: microphone waveform aligned with Live Labeling track ("East 100%"), session length 26.2 s.</em>
</p>

<p align="center">
  <img src="./assets/data%20nord.png" alt="Nord direction waveform" width="900"/>
  <br/>
  <em><strong>Figure 3.</strong> Nord direction session: clear chirp pulse structure, labeling track shows "Nord 100%".</em>
</p>

<p align="center">
  <img src="./assets/data%20west.png" alt="West direction waveform" width="900"/>
  <br/>
  <em><strong>Figure 4.</strong> West direction session: same sound source and distance as East/Nord — only the speaker position changes, ensuring directional differences arise purely from spatial geometry.</em>
</p>

> South direction data follows the same protocol (10 sessions per direction); waveforms are similar and omitted here for brevity.

### 4. Feature Engineering

Raw dual-channel PCM cannot be fed directly into a neural network. We adopt DEEPCRAFT Studio's standard **Log-Mel spectrogram** pipeline, natively compatible with the Imagimob deployment framework and auto-exportable as Python (`model.py`) and C (`model.c/.h`).

<p align="center">
  <img src="./assets/preprocessing.png" alt="DSP preprocessing pipeline" width="900"/>
  <br/>
  <em><strong>Figure 5.</strong> DSP preprocessing pipeline: 16 kHz dual-channel input → frame-level sliding window (512/320) → Hann window → RDFT → Mel filterbank (30 bands, 200–7000 Hz) → Log → feature-level sliding window (50×30).</em>
</p>

Design rationale:

1. **Frame-level sliding window (512 samples, stride 320):** At 16 kHz, each frame is 32 ms with 20 ms hop, yielding 100 Hz frame rate — sufficient to capture chirp time-frequency structure while keeping compute manageable.
2. **Hann window + RDFT:** Windowed 512-point real FFT reduces spectral leakage; Frobenius norm converts complex spectrum to power spectrum.
3. **Mel filterbank (30 bands, 200–7000 Hz):** Maps linear frequency to Mel scale; 30 bands uniformly cover the chirp beacon's main energy range. HTK formula matches DEEPCRAFT defaults.
4. **Log compression + feature-level window (50×30):** Natural log of Mel energy, stacked over 50 frames into a `[50, 30]` matrix — equivalent to 0.5 s of temporal context for the Conv1D network to discriminate direction.

Each inference window input is **50 frames × 30 Mel bands = 1,500 features** (reshaped as a `[50, 30]` matrix).

### 5. Model Architecture Design

With feature shape `[50, 30]` fixed, model selection involves an **accuracy vs. compute** trade-off. We chose DEEPCRAFT's built-in **`conv1d-small`** — only ~4,512 parameters, 14 layers, optimized for INT8 inference on MCU.

<p align="center">
  <img src="./assets/model%20architecture.png" alt="Conv1D model architecture" width="900"/>
  <br/>
  <em><strong>Figure 6.</strong> conv1d-small architecture: input [50, 30] → 4 Conv1D layers + BatchNorm + MaxPool + Dropout → GlobalAvgPool → Dense [5]. Total parameters: 4,512.</em>
</p>

Architecture rationale:

| Design choice | Rationale |
|---------------|-----------|
| 1D convolution (not 2D) | In `[50, 30]`, 50 is time and 30 is frequency; 1D conv slides along time per frequency band, far cheaper than 2D conv |
| Progressive channel compression (30→24→12→24) | Expand-then-compress funnel structure, classic CNN pattern |
| BatchNorm + Dropout | Small dataset (~12 min) prone to overfitting; BN stabilizes training, Dropout regularizes |
| Global Average Pooling | Replaces Flatten + large FC layers; Dense layer has only 125 params, suitable for edge deployment |
| Softmax 5-class output | Direct probability over East / Nord / South / West / unlabeled |

### 6. Training Strategy & Convergence Analysis

#### 6.1 Hyperparameter Configuration

We systematically compared multiple `conv1d-small` variants, varying data balancing strategy (parameter P) and model depth. All experiments share these base hyperparameters:

<p align="center">
  <img src="./assets/training%20paras.png" alt="Training hyperparameters" width="900"/>
  <br/>
  <em><strong>Figure 7.</strong> Training hyperparameters: Batch Size = 4, Split Count = 16, four conv1d-small runs (P = 35/45/67/89), Epochs = 10, LR = 0.0003, Weight Decay = 0.001.</em>
</p>

| Hyperparameter | Value | Rationale |
|----------------|-------|-----------|
| Batch size | 4 | Small batches add gradient noise, aiding generalization on small datasets |
| Epochs | 10 | With Patience=20 early stopping, avoids over-training |
| Learning rate | 0.0003 | DEEPCRAFT default; stable convergence on conv1d-small |
| Weight decay | 0.001 | L2 regularization against overfitting |
| Class weights | Shared | Classes already manually balanced; no extra weighting needed |

#### 6.2 Loss Convergence

<p align="center">
  <img src="./assets/loss.png" alt="Training and validation loss curves" width="700"/>
  <br/>
  <em><strong>Figure 8.</strong> Train and validation loss over 10 epochs. Train loss drops from 0.68 to 0.42; validation loss from 0.50 to 0.36, consistently below train loss.</em>
</p>

The loss curves show healthy convergence: both curves decrease together, validation loss stays below train loss throughout — no overfitting, good generalization. Local minima near epochs 3, 6, and 9 (~0.36) suggest 10 epochs is sufficient; further training yields diminishing returns.

#### 6.3 Accuracy Convergence

<p align="center">
  <img src="./assets/accuracy.png" alt="Training and validation accuracy curves" width="700"/>
  <br/>
  <em><strong>Figure 9.</strong> Train and validation accuracy. Train acc rises from 74% to 86.5%; validation acc from 76% to ~84%, plateauing after epochs 4–5.</em>
</p>

Validation accuracy plateaus at ~84% after epochs 4–5 while train accuracy continues rising (final 86.5%), a ~2.5% gap typical of mild overfitting on small datasets — within acceptable bounds.

### 7. Experimental Results & Model Selection

#### 7.1 Candidate Models

| Model | Location | Description |
|-------|----------|-------------|
| `conv1d-small-balanced-1` | `LiveDataCollection/` | First balanced training run |
| `conv1d-small-balanced-2` | `test_models/` | Candidate B |
| `conv1d-small-balanced-3/4` | `test_models/` | Candidates C/D |
| `conv1d-medium-balanced-1` | `finetuned_model/` | **Final selection** |

#### 7.2 Training Set Evaluation

<p align="center">
  <img src="./assets/confusion%20metrices_train.png" alt="Training set confusion matrix" width="900"/>
  <br/>
  <em><strong>Figure 10.</strong> Training set confusion matrix: Accuracy = 91.08%, F1 = 91.15%. Diagonal (green) dominates; Nord (94.2%) and West (94.0%) have highest recall.</em>
</p>

Strong training performance (91.08%) with all class recalls > 86%. Main confusion: `unlabeled` misclassified as directional classes (4–6%), likely because ambient noise segments occasionally contain faint environmental sounds resembling low-energy chirp segments.

#### 7.3 Test Set Evaluation

<p align="center">
  <img src="./assets/confusion%20metrices.png" alt="Test set confusion matrix" width="900"/>
  <br/>
  <em><strong>Figure 11.</strong> Test set confusion matrix: Accuracy = 82.50%, F1 = 83.50%. West (87.3%) performs best; East (74.5%) is the weakest direction.</em>
</p>

Test accuracy (82.50%) is lower than training (91.08%), expected for a ~12-minute dataset. Key findings:

- **West best (87.3%):** Possibly due to microphone array geometry — ITD/ILD patterns may be most discriminative in the West direction.
- **East weakest (74.5%):** Mainly confused with `unlabeled` (14.4%) and West (9.6%); East and West may produce near-symmetric phase-difference patterns on the dual-mic array, making boundary samples hard to separate.
- **Nord / South stable (~84%):** No anomalous confusion patterns.

#### 7.4 Final Model Selection

Based on training curves (Figures 8–9), train/test confusion matrices (Figures 10–11), and on-board live tests, we selected **`conv1d-medium-balanced-1`** (`finetuned_model/`) as the final deployment model:

1. **Generalization:** Validation loss keeps decreasing with no overfitting inflection (Figure 8)
2. **Class balance:** No single class collapse on test set; weakest direction East still > 74% (Figure 11)
3. **Deployment fit:** ~4.5K parameters; real-time INT8 inference on CM55 without latency
4. **Live validation:** Fast UART response, reasonable confidence distribution; `test.py` provides plug-and-play monitoring

### 8. Conclusion

This project extends the Infineon Hackathon siren detection task into a **four-direction + background** five-class DOA problem. Through a complete pipeline of **controlled chirp beacon + Live Labeling collection + Log-Mel features + lightweight Conv1D + INT8 edge deployment**, we achieve 82.5% test accuracy for real-time direction classification on the PSOC Edge E84 AI Kit. Future work includes: increasing East-direction training samples, data augmentation (reverb/noise mixing), and exploring finer-grained angle regression instead of four-way classification.

---

## Key Highlights

### 1. Command-Line Build & Flash — No Eclipse IDE Required

The official flow requires importing the project in Eclipse ModusToolbox™, then Build and Program. We analyzed the **`Makefile`** and **`common.mk`** under `test/` and found ModusToolbox supports native CLI builds:

```bash
# Build
make -C test build TOOLCHAIN=GCC_ARM

# Flash
make -C test program TOOLCHAIN=GCC_ARM

# Or both in one step
./flash_model.sh
```

Key config files:
- `test/Makefile` — Top-level Application Makefile; defines tri-core projects `proj_cm33_s / proj_cm33_ns / proj_cm55`
- `test/common.mk` — Shared settings: `TARGET=APP_KIT_PSE84_AI`, `TOOLCHAIN=GCC_ARM`, `ML_DEEPCRAFT_CPU=cm55`
- `test/common_app.mk` — Application-level paths and dependencies

### 2. Python Toolchain Loop

| Script | Role |
|--------|------|
| `model.py` | Reproduce preprocessing on PC; debug feature extraction |
| `test.py` | Monitor on-board inference over serial; no extra GUI needed |

Plug in the board → run `python test.py` → live direction predictions in the terminal. **Ready to use out of the box.**

### 3. Fully Reproducible Data → Model → Deploy Pipeline

From `sounds/` source selection, `LiveDataCollection/` capture, `finetuned_model/` training, to `test/` deployment — each stage has its own directory and documentation. New team members can reproduce the full workflow from this README.

---

## Quick Start

### Prerequisites

1. Install [ModusToolbox™](https://www.infineon.com/modustoolbox) (with GCC_ARM toolchain)
2. Install [DEEPCRAFT™ Studio](https://softwaretools.infineon.com/assets/com.ifx.tb.tool.deepcraftstudio) (Windows)
3. PSOC™ Edge E84 AI Kit + USB cable
4. Python 3.x (for `test.py`)

> **Do not use spaces in folder paths.** ModusToolbox tools package 3.6.0 or 3.8.0 recommended.

### Step 1: Clone the Repository

```bash
git clone <this-repo-url>
cd EESTEC_Challenge
```

### Step 2: Build and Flash

```bash
chmod +x flash_model.sh
./flash_model.sh
```

Windows (PowerShell / Git Bash):

```bash
bash flash_model.sh
```

### Step 3: Monitor Inference Output

1. Set BOOT SW to ON; connect USB via KitProg3
2. Update `PORT` in `test.py` to your serial port
3. Run:

```bash
python test.py
```

4. Play siren audio from `sounds/` at different directions near the board and watch terminal output

### Step 4 (Optional): Retrain the Model

1. Open `LiveDataCollection/` in DEEPCRAFT Studio and collect new data
2. Train or fine-tune in `finetuned_model/`
3. Export C code and replace files under `test/proj_cm55/model/` and `test/proj_cm33_ns/model/`
4. Run `./flash_model.sh` again

---

## Requirements

| Component | Version / Notes |
|-----------|-----------------|
| ModusToolbox™ | ≥ 3.6 (3.6.0 or 3.8.0 recommended) |
| Arm GNU Toolchain | GCC 14.2.1 |
| DEEPCRAFT™ Studio | 5.12+ |
| Python | 3.8+ |
| Target board | PSOC™ Edge E84 AI Kit (`APP_KIT_PSE84_AI`) |

Recommended ModusToolbox components:
- Eclipse IDE for ModusToolbox™
- ModusToolbox™ Tools Package
- ModusToolbox™ Programming Tools
- ModusToolbox™ Machine Learning Pack

Installation guide: [ModusToolbox Installation Guide](https://www.infineon.com/row/public/documents/30/68/infineon-modustoolbox-software-installation-guide-gettingstarted-en.pdf)

---

## References

### Official Documentation

- [Infineon Hackathon original repository](https://github.com/Infineon/hackathon)
- [DEEPCRAFT Studio deployment guide — PSOC Edge](https://developer.imagimob.com/deployment/deploy-models-supported-boards/deploy-siren-detection-model-PSoC-boards)
- [PSOC Edge ML Deploy Audio example](https://github.com/Infineon/mtb-example-psoc-edge-ml-deepcraft-deploy-audio)
- [Online flash tool (restore data collection firmware)](https://osts.infineon.com/devkit/ai-mcu-applications?id=5)

### Project Documentation

- [Original Challenge README](./README_challenge.md)
- [Sound sources & licenses](./sounds/SOURCES.md)
- [Live Data Collection guide](./LiveDataCollection/README.md)
- [Deployment project README](./test/README.md)

### Visual Assets Index (`assets/`)

All 11 figures are embedded in [Approach & Methodology](#approach--methodology):

| Figure | File | Section |
|--------|------|---------|
| 1 | `data split.png` | §3.2 Dataset composition |
| 2 | `data east.png` | §3.3 East waveform |
| 3 | `data nord.png` | §3.3 Nord waveform |
| 4 | `data west.png` | §3.3 West waveform |
| 5 | `preprocessing.png` | §4 Feature engineering |
| 6 | `model architecture.png` | §5 Model architecture |
| 7 | `training paras.png` | §6.1 Hyperparameters |
| 8 | `loss.png` | §6.2 Loss curves |
| 9 | `accuracy.png` | §6.3 Accuracy curves |
| 10 | `confusion metrices_train.png` | §7.2 Training evaluation |
| 11 | `confusion metrices.png` | §7.3 Test evaluation |

---

## Infineon Team (Original Hackathon)

**Eric** (Embedded Systems Engineer) · **Olaf** (Principal Engineer)

For questions about the original challenge, open an issue on [Infineon Hackathon Issues](https://github.com/Infineon/hackathon/issues).

---

*Documentation last updated: June 2026*
