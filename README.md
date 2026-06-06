<img src="./img/infineon_logo.png" alt="Infineon Logo" height="50"/>

# Emergency Vehicle Direction Detection

**基于 Infineon Hackathon Challenge 的扩展实现**

本项目在 [Infineon Emergency Vehicle Direction of Arrival Hackathon](https://github.com/Infineon/hackathon) 官方仓库的基础上进行了完整扩展。原始挑战要求使用 PSOC™ Edge E84 AI Kit 的双麦克风阵列，实时判断紧急车辆（警笛/救护车）声源来自 **East（东）、Nord（北）、South（南）、West（西）** 四个方向中的哪一个。

我们在官方示例与 DEEPCRAFT™ Studio 工作流之上，完成了 **数据采集 → 模型微调 → 嵌入式部署 → 实时验证** 的全链路实现，并显著简化了开发流程：无需打开 Eclipse ModusToolbox™ IDE，一条命令即可编译烧录，接上开发板即可运行。

---

## 目录

- [项目背景](#项目背景)
- [新增内容概览](#新增内容概览)
- [运行方式](#运行方式)
- [方法与思路](#方法与思路)
  - [1. 问题定义与研究动机](#1-问题定义与研究动机)
  - [2. 总体方案](#2-总体方案)
  - [3. 数据采集与标注策略](#3-数据采集与标注策略)
  - [4. 特征工程设计](#4-特征工程设计)
  - [5. 模型架构设计](#5-模型架构设计)
  - [6. 训练策略与收敛分析](#6-训练策略与收敛分析)
  - [7. 实验结果与模型选择](#7-实验结果与模型选择)
  - [8. 小结](#8-小结)
- [核心亮点](#核心亮点)
- [环境依赖](#环境依赖)
- [参考资料](#参考资料)

---

## 项目背景

| 项目 | 说明 |
|------|------|
| 原始挑战 | Infineon Hackathon — Emergency Vehicle Direction of Arrival |
| 硬件平台 | PSOC™ Edge E84 AI Kit（双 PDM 麦克风） |
| 开发工具 | DEEPCRAFT™ Studio（数据采集、标注、训练、导出） |
| 部署框架 | ModusToolbox™ + TensorFlow Lite for Microcontrollers |
| 分类任务 | 5 类：East / Nord / South / West / unlabeled |

原始仓库提供了部署示例与 Hackathon 材料，本项目在此基础上增加了：**自采集定向数据、微调 Conv1D 模型、并将完整部署流程脚本化**。

---

## 新增内容概览

在官方 Git 仓库基础上，我们新增了以下目录与文件：

| 路径 | 类型 | 作用 |
|------|------|------|
| `finetuned_model/` | DEEPCRAFT 项目 | 最终选定的微调模型工程（含训练好的 `.h5` 权重及导出配置） |
| `LiveDataCollection/` | DEEPCRAFT 项目 | 实时数据采集工程，含 40 条定向录音（每方向 10 条） |
| `sounds/` | 音频资源 | 警笛/救护车参考音源，用于数据采集时播放 |
| `test/` | 嵌入式工程 | 集成微调模型的 PSOC Edge 部署工程（ModusToolbox 三核结构） |
| `flash_model.sh` | Shell 脚本 | 一键编译并烧录到开发板 |
| `model.py` | Python | DEEPCRAFT 导出的预处理管线（Mel 特征提取，可在 PC 端复现） |
| `test.py` | Python | 串口监听脚本，实时显示板端推理结果 |

---

## 运行方式

**环境：** ModusToolbox™（含 GCC_ARM）、PSOC™ Edge E84 AI Kit、Python 3.x。路径中不要有空格。

### 1. 编译并烧录

官方文档默认通过 Eclipse ModusToolbox™ IDE 导入工程、点击 Build 和 Program 完成编译烧录。通过仔细观察源代码库，我们发现 `test/` 目录下已包含 ModusToolbox 原生的命令行构建体系，核心文件如下：

- **`test/Makefile`** — 顶层 Application Makefile（`MTB_TYPE=APPLICATION`），定义三核子工程 `proj_cm33_s`、`proj_cm33_ns`、`proj_cm55`，并引入 ModusToolbox 的 `application.mk`
- **`test/common.mk`** — 各子工程共享的配置，指定目标板 `TARGET=APP_KIT_PSE84_AI`、工具链 `TOOLCHAIN=GCC_ARM`、推理核心 `ML_DEEPCRAFT_CPU=cm55` 等
- **`test/common_app.mk`** — 应用级路径与依赖配置

这意味着无需打开 Eclipse，直接在终端执行 `make build` 和 `make program` 即可完成与 IDE 等价的编译与烧录。

基于此，我们编写了根目录下的 **`flash_model.sh`** 脚本，将上述两条 make 命令封装为一键操作。

**运行方式**（需已安装 ModusToolbox™ 并配置好 `CY_TOOLS_DIR` 环境变量）：

```bash
chmod +x flash_model.sh
./flash_model.sh          # macOS / Linux
bash flash_model.sh       # Windows (Git Bash)
```

### 2. 监听推理结果

1. 开发板 BOOT SW 拨至 ON，USB 连接 KitProg3
2. 修改 `test.py` 中的串口路径（macOS: `/dev/cu.usbmodemXXX`，Windows: `COM3`）
3. 运行 `python test.py`，终端实时显示方向预测：

```
Current: East      | U=0.12 E=0.87 N=0.03 S=0.01 W=0.02
```

4. 播放 `sounds/` 中的警笛音源，从不同方向靠近开发板即可测试

### 3. 重新训练（可选）

用 DEEPCRAFT Studio 打开 `LiveDataCollection/` 采集数据 → 在 `finetuned_model/` 训练 → 导出 C 代码替换 `test/proj_cm55/model/` → 重新执行 `./flash_model.sh`。

---

## 方法与思路

本节以技术报告的形式，阐述本挑战从问题定义到模型部署的完整解题思路。

### 1. 问题定义与研究动机

给定 PSOC™ Edge E84 AI Kit 上双 PDM 麦克风采集的音频流，实时判断警笛声源方向。我们将问题重新形式化为 **五分类任务**——在四个方向之外额外引入 `unlabeled` 类，用于建模"无有效警笛信号"的场景。这一设计基于以下考虑：

1. **实际部署需求：** 车辆并非时刻处于警笛环境中，模型必须能区分"有方向性警笛"与"背景噪声"。
2. **双麦 DOA 的信息载体：** 方向信息隐含于两路麦克风信号的 **时延差（ITD）** 与 **强度差（ILD）** 中，而非单一通道的频谱内容；因此需要可控、可重复的音源来激发这些差异。
3. **边缘部署约束：** PSOC Edge CM55 上的推理必须在 INT8 量化、低内存、低延迟条件下完成，这直接约束了模型规模与特征维度。

### 2. 总体方案

基于上述约束，我们设计了如下端到端流水线：

```
参考音源 (sounds/) → 定向播放 + Live Labeling 采集 (LiveDataCollection/)
    → Mel 频谱特征提取 (预处理管线)
    → Conv1D 轻量分类网络 (conv1d-small / medium)
    → INT8 量化部署 (test/) → UART 实时输出 (test.py)
```

关键设计原则：

| 环节 | 思路 | 理由 |
|------|------|------|
| 音源 | 统一使用 Chirp 信标或固定警笛文件 | 消除"不同方向播放不同音源"带来的虚假特征 |
| 采集 | Live Labeling 边录边标 | 避免事后切分引入边界误差，缩短数据准备周期 |
| 特征 | Log-Mel 频谱图 (50×30) | 与 DEEPCRAFT/Imagimob 生态兼容，板端有成熟 C 实现 |
| 模型 | 1D CNN (~4.5K params) | 在精度与 MCU 算力之间取得平衡 |
| 部署 | Makefile 命令行构建 | 摆脱 Eclipse IDE 依赖，实现可脚本化 CI/CD |

### 3. 数据采集与标注策略

#### 3.1 采集协议

我们在可控实验室环境下完成数据采集：

- **硬件：** PSOC™ Edge E84 AI Kit，双 PDM 麦克风阵列固定于开发板
- **声源：** 单一扬声器，距开发板 30–50 cm，依次放置于东/北/南/西四个方向
- **信号：** 优先使用本地生成的 `chirp_beacon`（600–3500 Hz 宽带 Chirp，100 ms 脉冲 + 20 ms 间隔），因其宽频特性对双麦相位/幅度差更敏感，且可重复性远高于真实警笛录音
- **工具：** DEEPCRAFT Studio `LiveDataCollection` 工程，PC 麦克风实时录音 + Live Labeling 同步标注

#### 3.2 数据集构成与划分

最终数据集包含 **11 分 48 秒** 标注音频，按近似 80/10/10 划分为训练集、验证集和测试集。四个方向类别各约 2.5 分钟，样本量基本均衡；`unlabeled` 类（2 分 03 秒）用于捕获无警笛时的环境噪声。

<p align="center">
  <img src="./assets/data%20split.png" alt="Dataset split statistics" width="900"/>
  <br/>
  <em><strong>Figure 1.</strong> 数据集类别分布与 Train / Validation / Test 划分（DEEPCRAFT Studio Data Explorer）。四个方向类时长均衡（约 02:20–02:31），合计标注数据 09:44，含 unlabeled 共 11:48。</em>
</p>

| 类别 | 总时长 | Train | Val | Test |
|------|--------|-------|-----|------|
| East | 02:31 | 77% | 14% | 9% |
| Nord | 02:25 | 81% | 9% | 11% |
| South | 02:20 | 78% | 11% | 11% |
| West | 02:27 | 80% | 10% | 10% |
| unlabeled | 02:03 | 85% | 9% | 6% |

#### 3.3 各方向采集波形

以下三图展示了 East、Nord、West 方向的典型 Live Labeling Session。可以观察到：每个 Session 包含多个短时脉冲段（对应 Chirp 信标播放），段间为静音间隔；Live Labeling 轨道（蓝色块）与波形中的能量 burst 精确对齐，验证了标注的时序准确性。

<p align="center">
  <img src="./assets/data%20east.png" alt="East direction waveform" width="900"/>
  <br/>
  <em><strong>Figure 2.</strong> East 方向采集 Session：Local Microphone 波形与 Live Labeling 轨道（"East 100%"）对齐，Session 时长 26.2 s。</em>
</p>

<p align="center">
  <img src="./assets/data%20nord.png" alt="Nord direction waveform" width="900"/>
  <br/>
  <em><strong>Figure 3.</strong> Nord 方向采集 Session：Chirp 脉冲结构清晰，标注轨道显示 "Nord 100%"。</em>
</p>

<p align="center">
  <img src="./assets/data%20west.png" alt="West direction waveform" width="900"/>
  <br/>
  <em><strong>Figure 4.</strong> West 方向采集 Session：与 East/Nord 采用相同音源与距离，仅改变扬声器物理位置，确保方向差异纯粹来自空间几何而非音源变化。</em>
</p>

> South 方向的数据采集协议与上述三个方向完全一致（各 10 条 Session），波形特征类似，此处从略。

### 4. 特征工程设计

原始双通道 PCM 无法直接输入神经网络。我们采用 DEEPCRAFT Studio 标准的 **Log-Mel 频谱图** 流水线，该管线与 Imagimob 部署框架原生兼容，可自动导出为 Python（`model.py`）和 C（`model.c/.h`）双版本。

<p align="center">
  <img src="./assets/preprocessing.png" alt="DSP preprocessing pipeline" width="900"/>
  <br/>
  <em><strong>Figure 5.</strong> DSP 预处理管线配置：16 kHz 双通道输入 → 帧级滑窗 (512/320) → Hann 窗 → RDFT → Mel 滤波器组 (30 bands, 200–7000 Hz) → Log → 特征级滑窗 (50×30)。</em>
</p>

设计思路如下：

1. **帧级滑窗（512 样本, stride 320）：** 在 16 kHz 采样率下，每帧 32 ms，步长 20 ms，输出帧率 100 Hz。这一时间分辨率足以捕获 Chirp 信标的时频结构，同时保持计算量可控。
2. **Hann 窗 + RDFT：** 加窗后做 512 点实数 FFT，消除频谱泄漏；Frobenius 范数将复数谱转为功率谱。
3. **Mel 滤波器组（30 带, 200–7000 Hz）：** 将线性频率映射到 Mel 尺度，30 个频带在 200 Hz–7 kHz 范围内均匀分布，覆盖 Chirp 信标的主要能量区间。HTK 公式与 DEEPCRAFT 默认配置一致。
4. **对数压缩 + 特征级滑窗（50×30）：** 对 Mel 能量取自然对数，再堆叠 50 帧形成 `[50, 30]` 的二维特征矩阵。这相当于 0.5 秒的时间上下文窗口，为 Conv1D 网络提供足够的时序信息以区分方向。

最终每个推理窗口的输入为 **50 帧 × 30 Mel 频带 = 1500 维** 特征向量（reshape 为 `[50, 30]` 矩阵）。

### 5. 模型架构设计

在特征维度 `[50, 30]` 固定后，模型选择面临 **精度 vs. 算力** 的权衡。我们选用 DEEPCRAFT 内置的 **`conv1d-small`** 架构——仅 ~4,512 参数，14 层，专为 MCU 端 INT8 推理优化。

<p align="center">
  <img src="./assets/model%20architecture.png" alt="Conv1D model architecture" width="900"/>
  <br/>
  <em><strong>Figure 6.</strong> conv1d-small 网络结构：输入 [50, 30] → 4 层 Conv1D + BatchNorm + MaxPool + Dropout → GlobalAvgPool → Dense [5]。总参数量 4,512。</em>
</p>

架构设计 rationale：

| 设计选择 | 理由 |
|----------|------|
| 1D 卷积（非 2D） | 特征矩阵 `[50, 30]` 中，50 为时间轴、30 为频率轴；1D 卷积沿时间轴滑动，逐频带提取时序模式，计算量远低于 2D 卷积 |
| 逐层通道压缩 (30→24→12→24) | 先扩维提取特征、再压缩去冗余，经典 CNN 漏斗结构 |
| BatchNorm + Dropout | 小数据集（~12 分钟）易过拟合；BN 稳定训练，Dropout 正则化 |
| Global Average Pooling | 替代 Flatten + 大 FC 层，将参数量从潜在数万降至 125（Dense 层），满足边缘部署 |
| Softmax 五分类输出 | 直接输出 East / Nord / South / West / unlabeled 的概率分布 |

### 6. 训练策略与收敛分析

#### 6.1 超参数配置

我们系统性地对比了多个 `conv1d-small` 变体，主要变化维度为数据平衡策略（参数 P）和模型深度。所有实验共享以下基础超参数：

<p align="center">
  <img src="./assets/training%20paras.png" alt="Training hyperparameters" width="900"/>
  <br/>
  <em><strong>Figure 7.</strong> 训练超参数配置：Batch Size = 4, Split Count = 16, 4 组 conv1d-small 实验（P = 35/45/67/89），Epochs = 10, LR = 0.0003, Weight Decay = 0.001。</em>
</p>

| 超参数 | 值 | 选择理由 |
|--------|-----|----------|
| Batch Size | 4 | 小 batch 引入梯度噪声，有助于小数据集泛化 |
| Epochs | 10 | 配合 Patience=20 的 early stopping，避免过度训练 |
| Learning Rate | 0.0003 | DEEPCRAFT 默认值，在 conv1d-small 上收敛稳定 |
| Weight Decay | 0.001 | L2 正则化，抑制小数据集过拟合 |
| Class Weights | Shared | 各类别样本量已人工均衡，无需额外加权 |

#### 6.2 Loss 收敛行为

<p align="center">
  <img src="./assets/loss.png" alt="Training and validation loss curves" width="700"/>
  <br/>
  <em><strong>Figure 8.</strong> 训练与验证 Loss 曲线（10 epochs）。Train Loss 从 0.68 单调降至 0.42；Validation Loss 从 0.50 降至 0.36，且始终低于 Train Loss。</em>
</p>

Loss 曲线呈现健康的收敛模式：两条曲线同步下降，Validation Loss 始终低于 Train Loss，说明模型没有过拟合，且在未见数据上泛化良好。Validation Loss 在 epoch 3、6、9 附近出现局部极小值（~0.36），暗示 10 epoch 已足够，继续训练收益有限。

#### 6.3 Accuracy 收敛行为

<p align="center">
  <img src="./assets/accuracy.png" alt="Training and validation accuracy curves" width="700"/>
  <br/>
  <em><strong>Figure 9.</strong> 训练与验证 Accuracy 曲线。Train Acc 从 74% 升至 86.5%；Validation Acc 从 76% 升至 ~84%，epoch 4–5 后趋于稳定。</em>
</p>

Accuracy 曲线进一步验证了上述判断：Validation Accuracy 在 epoch 4–5 达到 ~84% 后进入平台期，而 Train Accuracy 仍缓慢上升（最终 86.5%），两者差距约 2.5%。这是小数据集上的典型轻微过拟合，在可接受范围内。

### 7. 实验结果与模型选择

#### 7.1 候选模型对比

| 模型 | 位置 | 说明 |
|------|------|------|
| `conv1d-small-balanced-1` | `LiveDataCollection/` | 首次平衡训练 |
| `conv1d-small-balanced-2` | `test_models/` | 候选 B |
| `conv1d-small-balanced-3/4` | `test_models/` | 候选 C/D |
| `conv1d-medium-balanced-1` | `finetuned_model/` | **最终选定** |

#### 7.2 训练集评估

<p align="center">
  <img src="./assets/confusion%20metrices_train.png" alt="Training set confusion matrix" width="900"/>
  <br/>
  <em><strong>Figure 10.</strong> 训练集混淆矩阵：Accuracy = 91.08%, F1 = 91.15%。对角线（绿色）为主，Nord (94.2%) 和 West (94.0%) 识别率最高。</em>
</p>

训练集上模型表现强劲（91.08%），各类别召回率均 > 86%。主要混淆模式为 `unlabeled` 被误判为各方向（4–6%），这是因为背景噪声段中偶尔含有微弱的环境声，与低能量 Chirp 段特征相似。

#### 7.3 测试集评估

<p align="center">
  <img src="./assets/confusion%20metrices.png" alt="Test set confusion matrix" width="900"/>
  <br/>
  <em><strong>Figure 11.</strong> 测试集混淆矩阵：Accuracy = 82.50%, F1 = 83.50%。West (87.3%) 表现最好；East (74.5%) 为主要薄弱方向。</em>
</p>

测试集性能（82.50%）低于训练集（91.08%），符合小数据集（~12 分钟）的预期。关键发现：

- **West 方向最优（87.3%）：** 可能与开发板麦克风阵列的几何布局有关——West 方向上的 ITD/ILD 模式最具区分度。
- **East 方向最弱（74.5%）：** 主要与 `unlabeled`（14.4%）和 West（9.6%）混淆，推测 East 与 West 在双麦阵列上的相位差模式存在近似对称性，导致边界样本难以区分。
- **Nord / South 居中（~84%）：** 表现稳定，无异常混淆模式。

#### 7.4 最终模型选择

综合训练曲线（Figure 8–9）、训练集/测试集混淆矩阵（Figure 10–11）以及板端实机测试，我们选择 **`conv1d-medium-balanced-1`**（`finetuned_model/`）作为最终部署模型，依据如下：

1. **泛化能力：** Validation Loss 持续下降且无过拟合拐点（Figure 8）
2. **类别均衡：** 测试集上无单一类别崩溃，最弱方向 East 仍 > 74%（Figure 11）
3. **部署约束：** ~4.5K 参数，INT8 量化后在 CM55 上实时推理无延迟
4. **实测验证：** 板端 UART 输出响应迅速，置信度分布合理，`test.py` 可即插即用监控

### 8. 小结

本项目将 Infineon Hackathon 的警笛检测任务扩展为 **四方向 + 背景** 的五分类 DOA 问题，通过 **可控 Chirp 信标 + Live Labeling 采集 + Log-Mel 特征 + 轻量 Conv1D + INT8 边缘部署** 的完整链路，在 PSOC Edge E84 AI Kit 上实现了 82.5% 测试准确率的实时方向判断。后续改进方向包括：增大 East 方向训练样本、引入数据增强（混响/噪声叠加）、以及探索更细粒度的角度回归（而非四方向分类）。

---

## 核心亮点

### 1. 命令行一键编译烧录，摆脱 Eclipse IDE

官方流程要求在 Eclipse ModusToolbox™ 中 Import 工程、Build、Program。我们分析了 `test/` 目录下的 **`Makefile`** 与 **`common.mk`**，发现 ModusToolbox 原生支持命令行构建：

```bash
# 编译
make -C test build TOOLCHAIN=GCC_ARM

# 烧录
make -C test program TOOLCHAIN=GCC_ARM

# 或一条命令完成
./flash_model.sh
```

关键配置文件：
- `test/Makefile` — 顶层 Application Makefile，定义三核工程 `proj_cm33_s / proj_cm33_ns / proj_cm55`
- `test/common.mk` — 共享设置：`TARGET=APP_KIT_PSE84_AI`、`TOOLCHAIN=GCC_ARM`、`ML_DEEPCRAFT_CPU=cm55`
- `test/common_app.mk` — 应用级路径与依赖

### 2. Python 工具链闭环

| 脚本 | 功能 |
|------|------|
| `model.py` | PC 端复现预处理，调试特征提取 |
| `test.py` | 串口监听板端推理，无需额外 GUI |

接上开发板 → 运行 `python test.py` → 终端实时显示方向预测，**即插即用**。

### 3. 完整可复现的数据→模型→部署链路

从 `sounds/` 音源选择、`LiveDataCollection/` 采集、`finetuned_model/` 训练到 `test/` 部署，每个环节均有独立目录与文档，新成员可按 README 完整复现。
