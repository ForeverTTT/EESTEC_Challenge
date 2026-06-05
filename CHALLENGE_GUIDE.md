# Challenge 执行手册 — 警笛方向识别

**目标：** 双麦 + AI，识别警笛来自 E/S/W/N（可扩到 8 方向）  
**工程：** `test/` · 推理核 **CM55 + U55** · 工具 **DEEPCRAFT Studio + Eclipse ModusToolbox**

---

## 一、核心策略（先读这个）

> **神经网络选哪条方案、何时升级：** 见 **§2.0 推荐执行思路**（在 §2.2 所有方案细节之前）。

### 1.1 怎么拿分

| 权重 | 策略 |
|------|------|
| **55% 模型** | 每方向 5 次测试，记 r_i；**先 4 方向每向 ≥4/5，再扩 n** |
| **20% 创新** | 固定角度支架 + 多帧投票 + 采集自动化（写进文档） |
| **20% 文档** | 07.06 前 GitHub 链接或邮件 |
| **5% 反馈** | 发 `ericjoerg.schulze@infineon.com` |

**Task 1 公式：**

\[
\text{Score} = \frac{1}{n}\sum_{i=1}^{n}\frac{r_i}{5} \times (1 - e^{-0.15n})
\]

- n=4 且全对 → 加成约 0.45  
- n=8 且全对 → 加成约 0.70  
- **8 方向半对 < 4 方向全对** → 不要急着加方向

### 1.2 扩方向路线

```
4 方向 (E/S/W/N + unlabeled)  →  每向 r_i ≥ 4/5
        ↓
8 方向 (+ NE/SE/SW/NW)        →  再测 5×8 次
        ↓
12 方向                       →  仅当 8 方向已很稳（hackathon 一般不推荐）
```

### 1.3 物理策略（决定成败）

Kit 只有 **2 个麦（左/右）**，不是 4 麦阵列。

- **固定一种几何：** 要么固定板子移音箱，要么固定音箱转板子 — **训练与测试必须相同**
- 地面贴胶带标 0°/90°/180°/270°（扩 8 方向再加 45°/135°…）
- 警笛声：**训练和正式测试用同一个音频文件**

---

## 二、神经网络方案（详细）

### 2.0 推荐执行思路（先看这个）

> 下面 §2.2～§2.6 是 baseline 细节，§2·5 是进阶方案 A～F。**不要一上来全试**——按本节的顺序做，时间最省、板上最稳。

#### 总原则

| 优先级 | 做什么 | 对应方案 | 何时停 |
|--------|--------|----------|--------|
| **1** | 自采数据 + 固定几何 + **方案 A 重训** | §2.2 时域 2D CNN | 每向 r_i ≥ 4/5 |
| **2** | **`audio.c` 3 帧投票 + margin** | §六（不改模型） | 输出不再乱跳 |
| **3** | E/W 准、**N/S 仍混** → 上双分支 | §2.5.3 **方案 B** | N/S 混淆矩阵改善 |
| **4** | 4 方向稳了再扩 **8 方向** | §2.5.7 **方案 F** + 每级小 B 网 | 单模型 9 类仍混时 |
| **暂缓** | Mel / TCN / CRNN | §2.3 E、§2.5.4 C、§2.5.5 D | A+B+投票仍不够再考虑 |

**当前工程 `test/proj_cm55/model/` 已是方案 A pipeline**（2048×2 窗 + int8 + U55）。**最该做的是用自采警笛数据重训，而不是换架构。**

#### 为什么这样排

- **方案 A**：Studio / U55 已跑通，hackathon 时间成本最低；数据与摆放往往比换网络更能提分。
- **板端投票**：零 Studio 工作量，常能 +1～2 次 r_i，可写 Innovation。
- **方案 B**：2 麦 DOA 最对症——显式 ILD/ITD/GCC，补 N/S 在单窗 CNN 上的短板。
- **方案 F**：仅当 **4 方向已稳** 且要冲 8 方向；不要用一个 9 类大 softmax 硬啃相邻方向。
- **暂不优先 E/C/D**：Mel 要改 preprocessor；TCN 的 dilation、CRNN 的 LSTM 更重且小数据易过拟合——**deadline 紧时 ROI 低**。

#### 决策流程（简版）

```
有自采数据？
  └─ 否 → 先 Step 1～2 采集，仍用方案 A 结构
  └─ 是 → Studio 重训方案 A → Code Gen → 烧录

板上 5×4 自测
  └─ 每向 r_i ≥ 4 → 定版（可选扩 8 方向），不要换网
  └─ 输出乱跳 → 先加 §六 投票 + 调 OUTPUT_THRESHOLD_SCORE
  └─ E/W 好、N/S 差 → 方案 B（别并行试 C/D/E）
  └─ 4 方向稳 + 要 8 方向 → 方案 F 层次 + 方案 B 小网
```

#### 时间紧时的裁剪顺序

```
砍掉 8 方向
  → 保证 4 方向每向 r_i ≥ 4
  → 文档最简版也要交（07.06）
```

#### 与「集大成」的关系

没有需要把所有字母方案堆在一起的万能架构。**实用集大成 = 方案 A（或 B）+ 板端投票 +（8 方向时）方案 F 层次**。Mel 可作 B 的第三分支，TCN/CRNN 与 B **二选一**，不要叠加。

---

### 2.1 设计目标与硬件约束

| 约束 | 数值 / 要求 |
|------|-------------|
| 麦克风 | 2× PDM，Ch2=左，Ch3=右，板载间距固定 |
| 采样率 | 16 kHz，16-bit PCM |
| 推理核 | CM55 + **Ethos-U55** NPU |
| 量化 | **int8x8**（权重 + 激活） |
| 权重 Flash | 目标 **< 80 KB**（现工程 ~33 KB） |
| RAM (arena+state) | 目标 **< 120 KB**（现工程 ~100 KB） |
| 推理延迟 | ~10 次/秒（128 ms 窗 + 100 ms hop） |
| 任务类型 | **多类分类**（非回归角度） |

**核心思路：** 2 麦无法做精确波束形成，但可以通过 **左右通道的时域/能量/相位差模式** 区分「声源相对板子的方位类别」。网络学的是「这一窗立体声波形 → 方向标签」的映射。

---

### 2.2 方案 A（推荐）：Stereo 时域 + 2D CNN

与当前 `test/proj_cm55/model/` 已部署 pipeline **完全一致**，只需用 **自采警笛数据重训**。

#### 2.2.1 端到端数据流

```
[板端 audio.c]
  PDM Ch2(左) + Ch3(右)
       ↓ 16 kHz, int16
  sample / 32768 → float ∈ [-1, 1]
       ↓ 每采样点
  IMAI_enqueue([L, R])          ← 每次 1× float[2]

[model.c 预处理 — PREPROCESSOR 区]
  fixwin 环形缓冲：2048 帧 × 2 通道
       ↓ 凑满 2048 帧且 hop=1600 样本
  tensor X: float[2048, 2]     ← 16384 bytes

[model.c 推理 — NETWORK 区]
  float → int8 量化 (scale/offset 由 TFLM 定)
       ↓
  network_int8x8 (TFLM + U55)
       ↓
  int8 logits[5] → float[5] 反量化
       ↓ scale=0.00390625, offset=-128

[板端 audio.c]
  argmax + 阈值 → UART 打印方向
```

#### 2.2.2 预处理参数（与现 model.c 对齐）

| 参数 | 值 | 含义 |
|------|-----|------|
| `fixwin input_size` | 8 bytes = 2×float | 每次 enqueue 一个立体声样本 |
| `fixwin count` | 2048 | 窗口长度（样本点数） |
| 窗口时长 | 2048/16000 = **128 ms** | 覆盖警笛 1～2 个周期 |
| `stride` (dequeue) | 1600 样本 | hop = **100 ms** |
| 推理频率 | ~**10 Hz** | `model.h` frequency=10 |
| 输入 tensor | `[2048, 2]` | 时间 × (左, 右) |
| 输出 tensor | `[5]` 或 `[n+1]` | softmax 概率 |

**为何 128 ms 窗：** 警笛/ siren 有周期性 AM/FM 调制，128 ms 足够捕获包络；更短（512）丢周期，更长（4096）延迟大且占 RAM。

**为何 hop 100 ms：** 平衡响应速度与稳定性；配合板端 3 帧投票效果更好。

#### 2.2.3 输入 tensor 布局（Studio 里怎么设）

在 DEEPCRAFT Studio 训练图中：

```
Input shape: (window_length, channels) = (2048, 2)
dtype: float32
sample_rate: 16000
channels: [Left, Right]   ← 顺序必须与 audio.c 一致
```

`audio.c` 中：

```c
input_features[0] = sample_left;   // Ch2
input_features[1] = sample_right;  // Ch3
```

**顺序反了 = 东/西对调，训练必崩。**

#### 2.2.4 网络结构 — 4 方向 Baseline

把输入 `X` reshape 为 **(1, 2048, 2, 1)** 供 2D Conv 使用（H=时间, W=通道）。

```
Input:      (1, 2048, 2, 1)

Block 1 — 粗粒度时序 + 跨通道
  Conv2D:   kernel (64, 1), filters=16, stride (8, 1), padding=same
  ReLU
  MaxPool2D: pool (4, 1)
  → shape ≈ (1, 512, 2, 16)

Block 2 — 中等尺度
  Conv2D:   kernel (16, 2), filters=32, stride (4, 1), padding=valid
            ↑ kernel 高 16×宽 2：同时在「时间×左右」上卷积，提取 ILD/ITD 局部模式
  ReLU
  MaxPool2D: pool (4, 1)
  → shape ≈ (1, 128, 1, 32)

Block 3 — 高层语义
  Conv2D:   kernel (8, 1), filters=64, stride (2, 1), padding=same
  ReLU
  GlobalAveragePooling2D
  → shape (1, 64)

Head
  Dense(5) + Softmax
  输出: [unlabeled, East, South, West, Nord]
```

**参数量估算：** ~20k–40k → int8 权重 ~25–50 KB，在 U55 预算内。

**各层在学什么（物理含义）：**

| 层 | 学什么 |
|----|--------|
| Conv (64,1) stride 8 | 警笛音调、调制频率、能量包络 |
| Conv (16,2) | **左-右通道关系**：哪边响、相位领先 |
| Conv (8,1) | 组合特征 → 方向模式 |
| GAP + Dense | 方向分类 |

#### 2.2.5 网络结构 — 8 方向扩展版

在 Baseline 上只改 **Head + 略增宽度**，不要换 pipeline：

```
Block 1: filters 16 → 24
Block 2: filters 32 → 48
Block 3: filters 64 → 96
Head:    Dense(9) + Softmax
         [unlabeled, N, NE, E, SE, S, SW, W, NW]
```

| 对比 | 4 方向 | 8 方向 |
|------|--------|--------|
| 输出类数 | 5 | 9 |
| 每类数据 | 2–3 min | 3–4 min |
| 权重 Flash | ~35 KB | ~50–70 KB |
| 易混类 | E↔W | E↔NE, N↔NE |

**8 方向关键：** Block 2 的 `(16, 2)` 卷积更重要 — 相邻 45° 差别更小，靠更细的双通道模式区分。

#### 2.2.6 Studio 训练超参（建议起点）

| 参数 | 4 方向 | 8 方向 | 说明 |
|------|--------|--------|------|
| Optimizer | Adam | Adam | Studio 默认 |
| Learning rate | 1e-3 | 5e-4 | 8 类易过拟合，略降 |
| Epochs | 50–100 | 80–150 | 看 val loss  plateau |
| Batch size | 32 | 32 | 受 Studio / GPU 限制 |
| Train/Val split | 80/20 | 80/20 | **按 clip 分层**，每类都要有 val |
| Loss | categorical_crossentropy | 同左 | 多类分类 |
| Class weight | 可选：unlabeled×0.5 | 弱方向×1.5 | 防背景类过多 |

**停止训练条件：**

- Val accuracy **每类** > 80%（4 方向）或 > 70%（8 方向）
- 混淆矩阵：非对角线 < 15%

**不要 early deploy 的信号：** 训练 99%、验证 60% → 过拟合，回去加数据。

#### 2.2.7 Code Gen / 量化（U55）

| Code Gen 项 | 设置 |
|-------------|------|
| Architecture | Infineon PSOC |
| Target | **PSOC Edge M55/U55** |
| Enable Network Quantization | ✅ |
| Calibration | **Use Project file (.improj)**，必须含 **全部方向** 的样本 |
| Preprocessor Acceleration | CMSIS Float32 或 None（与训练一致） |
| Ethos-U Optimize | **Performance**（hackathon 优先延迟） |
| Ethos-U Memory Mode | Shared SRAM |
| Output | `test/proj_cm55/model/` |

量化后输出反量化（现 model.c）：

```
dequantize: out_float = (int8 - (-128)) × 0.00390625
```

---

### 2.3 方案 B（备选）：Stereo Log-Mel + 2D CNN

当方案 A 在 N/S 方向始终不准时可试。参考 `proj_cm33_ns` baby cry 流水线，改为 **双声道**。

#### 2.3.1 预处理链

```
float[L,R] 逐样本 enqueue
    ↓
fixwin: 512 样本 × 1 通道  ← 需改为 stereo 或分两路再 stack
    ↓
Hann 窗 → RFFT 512
    ↓
幅度归一化
    ↓
Mel 滤波器组: 20~40 bins, 16 kHz
    ↓
Clip + Log
    ↓
fixwin: 60 帧 × 20 mel → 输入 (60, 20, 2) 或 (60, 40) concat
    ↓
2D CNN → Dense(n+1)
```

| 参数 | 建议值 |
|------|--------|
| FFT size | 512 |
| Hop | 160（10 ms） |
| Mel bins | 32 |
| 帧数 | 60（≈600 ms 上下文） |
| 输入 shape | `(60, 32, 2)` 两通道作 depth |

#### 2.3.2 Mel 版 CNN

```
Input: (1, 60, 32, 2)

Conv2D 3×3, 16, stride (2,2) → ReLU → MaxPool
Conv2D 3×3, 32, stride (2,2) → ReLU → MaxPool
Conv2D 3×3, 64, stride (1,1) → ReLU
GlobalAveragePooling2D
Dense(n+1) → Softmax
```

**优缺点：**

| | 方案 A 时域 | 方案 B Mel |
|--|------------|-----------|
| 警笛频谱特征 | 网络自己学 | 显式提取，可能更稳 |
| 双麦空间信息 | Conv(16,2) 直接学 | 需在 channel 维 stack |
| RAM | ~100 KB | ~120–150 KB |
| Studio 成熟度 | 现工程已验证 | 需改 preprocessor 图 |
| hackathon 时间 | ⭐ 优先 | 方案 A 失败再用 |

---

### 2.4 双麦方向识别的特征逻辑（写进文档用）

2 麦分类 **不是** 测精确角度，而是学 **类别边界**：

```
声源在东侧 → 右麦(Ch3) 通常更响 / 相位领先（取决于板子朝向定义）
声源在西侧 → 左麦(Ch2) 更响
声源在北/南 → 左右差异小，但仍有 **板载几何 + 反射** 导致的可重复模式
```

**因此必须：**

1. 训练与测试 **板子朝向定义不变**（例如 USB 口朝你时为 N）
2. **距离固定范围**（0.5–1.5 m），否则 ILD 变
3. N/S 类 **多采数据** — 左右差小，最难

**数据增强 — 可用 / 禁用：**

| 增强 | 4/8 方向 DOA |
|------|--------------|
| 加高斯噪声 | ✅ 少量 |
| 音量缩放 ±6 dB | ✅ |
| 左右声道 **swap** | ❌ 会把 E/W 标签弄反 |
| 随机 time shift ±50 ms | ✅ 小范围 |
| 重采样变采样率 | ❌ |

---

### 2.5 内存与算力预算（现工程实测）

来自 `proj_cm55/model/model.h` / `model.c`：

| 区域 | 大小 | 内容 |
|------|------|------|
| Buffers (RAM) | 20,485 B | `_buffer`，含 float[2048,2] |
| State (RAM) | 101,600 B | fixwin 状态 + **TFLM arena 84992 B** |
| Readonly (Flash) | 33,488 B | int8 TFLite flatbuffer |
| 推理引擎 | TFLM + U55 | `network_int8x8` |

扩 8 方向时若 Flash > 80 KB 或 arena > 100 KB：

- Code Gen → Ethos-U Optimize 改 **Size**
- 减少 Conv filters（96→64）
- 勿加第 4 个 Conv block

---

### 2.6 Studio 构图检查清单（逐步）

**Preprocessor 图：**

- [ ] Input：2 channels, 16 kHz, float
- [ ] Fixed Window：length=**2048**, stride=**1600**（或与 Studio 等价配置）
- [ ] Output to Network：shape `(2048, 2)`

**Network 图：**

- [ ] 2D Conv 在 (time, channel) 维
- [ ] 含 **跨通道卷积**（kernel width=2 或 input channels=2）
- [ ] 输出 Softmax，类数 = n+1
- [ ] 标签名与 `audio.c` / 评测一致

**Train：**

- [ ] 每类 val set 非空
- [ ] 混淆矩阵对角线主导

**Code Gen：**

- [ ] M55/U55 + int8 + calibration 全覆盖
- [ ] Project Path = `test/proj_cm55`

---

### 2.7 工程关键路径

| 文件 | 作用 |
|------|------|
| `test/common.mk` | `ML_DEEPCRAFT_CPU=cm55` |
| `test/proj_cm55/model/model.c/h` | **Studio Code Gen 生成，勿手改** |
| `test/proj_cm55/audio.c` | 双麦 `[L,R]`、`OUTPUT_THRESHOLD_SCORE`、`PDM_PCM_GAIN` |
| `LiveDataCollection/` | Studio 录音打标签 |

---

## 二·五、进阶神经网络方案（冲精度）

> **执行顺序见 §2.0。** 本节是 baseline（§2.2）仍不够时的升级菜单——默认先试 **方案 B**，不要按 A→C→D→E→F 逐个全试。

### 2.5.0 物理基础：ILD / ITD 从哪来？（所有方案共用）

双麦 DOA 不靠「魔法」，靠 **两麦到声源路径不同**。下面公式和数值直接决定你该采什么数据、该用哪种网络。

#### 几何模型

```
        声源 ●
         \   \
          \   \      θ = 入射角（相对板子法线/前方）
           \   \
        ┌───\───\───┐
        │  L      R  │   间距 d（Kit 上约 3~5 cm）
        └────────────┘
   到 L 的路程 ≠ 到 R 的路程
```

#### ITD（Interaural Time Difference，到达时间差）

**物理来源：** 路程差 → 声波到达两麦的时间不同。

\[
\Delta d = d \cdot \sin\theta, \qquad \text{ITD} = \frac{d \cdot \sin\theta}{c}
\]

- `d` = 麦间距（m），`c` ≈ 343 m/s，`θ` = 声源方向角

**Kit 数量级（d≈0.04 m）：**

| θ | ITD |
|---|-----|
| 0°（正前/正后） | **≈ 0 µs** |
| 45° | ≈ 83 µs ≈ **1.3 采样点** @16kHz |
| 90°（正侧） | ≈ 117 µs ≈ **1.9 采样点** |

> 16 kHz 下每采样点 = 62.5 µs → **ITD 往往只有 1~2 点**，单看原始波形很难；要靠 **互相关峰值 lag** 或让 CNN 在局部 pattern 里隐式学。

**各方向 ITD 直觉（板子前方为 N，L=左 Ch2，R=右 Ch3）：**

| 方向 | 典型 ITD 符号 | 说明 |
|------|---------------|------|
| East | R 先到（lag < 0） | 声源在右 |
| West | L 先到（lag > 0） | 声源在左 |
| North / South | **≈ 0** | 对称，ITD 弱 → **最难** |

#### ILD（Interaural Level Difference，强度差）

**物理来源：**

1. **距离差** → 远侧麦声压更小（∝ 1/r）
2. **板体/外壳遮挡** → 背侧或远侧高频衰减（声学阴影）
3. **麦指向性 / 开孔** → 不同角度灵敏度不同

**常用特征（对一个 2048 窗）：**

```text
RMS_L = sqrt(mean(L^2))
RMS_R = sqrt(mean(R^2))

ILD_dB   = 20 * log10(RMS_R / RMS_L)     # >0 表示右侧更响
ILD_ratio = RMS_R / RMS_L
```

**各方向 ILD 直觉：**

| 方向 | 典型 ILD | 说明 |
|------|----------|------|
| East | R >> L | 最清晰 |
| West | L >> R | 最清晰 |
| North / South | L ≈ R | **差异小** → 要靠 ITD + 板体反射模式 |

#### GCC-PHAT（估计 ITD 的标准做法）

互相关 + PHAT 加权，在 **±max_lag** 内找峰值：

```text
1. 对 L, R 做 FFT → G_L(f), G_R(f)
2. 互谱：G_LR = G_L * conj(G_R)
3. PHAT 归一化：G_LR /= (|G_LR| + eps)
4. IFFT → 互相关曲线 R(τ)
5. argmax R(τ) → lag 样本数 → ITD ≈ lag / 16000 秒
```

`max_lag` 建议 **±32~±64 样本**（±2~4 ms），覆盖 Kit 上可能的 ITD。

#### 为什么 2 麦能分 4 方向（E/S/W/N）却不能无限细分？

- **E/W**：ILD 强 + ITD 有符号 → 好分
- **N/S**：ILD≈0、ITD≈0 → 靠 **板体几何 + 房间反射 + 警笛频谱** 的**可重复模式**（必须固定摆放）
- **8 方向（45°）**：ILD/ITD 变化更小 → 需要 **更多数据 + 更强模型（方案 B/F）**

---

### 2.5.1 方案对比总览

| 方案 | 预期精度 | 边端可行性 | Studio / U55 | hackathon 时间 | 何时用 |
|------|----------|------------|--------------|----------------|--------|
| A. 2D CNN 时域（§2.2） | ★★★ | ★★★★★ | ✅ 已跑通 | ★★★★★ | baseline |
| **B. 双分支（CNN + ILD/ITD）** | ★★★★★ | ★★★★ | 需 preprocessor | ★★★ | **2 麦最对症** |
| C. TCN / Dilated Conv1D | ★★★★ | ★★★★ | 需验证 | ★★★★ | 长程时序 |
| D. CRNN（Conv + LSTM） | ★★★★ | ★★★ | ✅ LSTM | ★★★ | N/S 混淆 |
| E. Stereo Mel + CNN（§2.3） | ★★★★ | ★★★★ | ✅ | ★★★ | 窄带警笛 |
| F. 层次分类 | ★★★★ | ★★★★ | ✅ | ★★★ | n≥8 |

---

### 2.5.2 方案 A：Stereo 时域 + 2D CNN（Baseline 详解）

#### 原理

网络把 `[2048, 2]` 当作 **「时间 × 左右通道」的图像**，用 Conv2D 同时扫：

- **时间维**：警笛周期、AM 包络、频率轮廓
- **通道维（kernel width=2）**：左右样本的 **联合模式** → 等价于「可学习的 ILD/ITD 提取器」

#### 它隐式在学什么？

| 卷积块 | 等价于 |
|--------|--------|
| Conv (64,1) stride 8 | 粗时间包络 / 基频段 |
| Conv (16,**2**) | **显式跨左右** → ILD+相位差局部特征 |
| Conv (8,1) + GAP | 方向判别 |

#### 优点 / 局限

| 优点 | 局限 |
|------|------|
| 已在你 `proj_cm55` 跑通 | N/S 无强 ILD 时易混 |
| 无需手工特征 | 完全靠数据学几何 |
| Flash ~33KB，最快 | 8 方向时相邻类易混 |

#### Studio 怎么建

- Preprocessor：Fixed Window **2048**，stride **1600**，2ch float
- Network：§2.2.4 三层 Conv2D + GAP + Dense(5)
- **关键层**：必须有 **kernel 宽度覆盖 2 通道** 的 Conv

#### 何时停止升级

4 方向自测 **每向 r_i ≥ 4/5** → 不必换架构，直接扩数据或上 8 方向。

---

### 2.5.3 方案 B：双分支融合（CNN + 物理特征）⭐ 最推荐升级

#### 原理

**Branch A** 学任意复杂模式；**Branch B** 显式注入 §2.5.0 的 ILD/ITD/GCC 特征。  
N/S 时 ILD≈0，但 **GCC lag 分布、频带能量比** 仍可能有稳定差异 → 补 Branch A 的短板。

#### 结构

```
Input window: L[2048], R[2048]
        │
        ├─ Branch A ──────────────────────────────┐
        │   reshape (2048,2,1)                    │
        │   Conv2D×2 (§2.2.4) → GAP → fa (64)    │
        │                                           │
        └─ Branch B（每窗算一次）──────────────────┤
            f1 = ILD_dB = 20*log10(RMS_R/RMS_L)   │
            f2 = ILD_ratio = RMS_R/RMS_L           │
            f3 = GCC-PHAT lag (samples)            │→ fb (8~16)
            f4 = |f3|                              │
            f5~f8 = 分频段 ILD（低/中/高 4 段）     │
                                                   │
        Concat(fa, fb) → Dense(64) → Dense(n+1) → Softmax
```

#### Branch B 特征清单（建议 8 维）

| # | 特征 | 公式 | 物理意义 |
|---|------|------|----------|
| 1 | `ild_db` | `20*log10(RMS_R/RMS_L+ε)` | 左右响度差（dB） |
| 2 | `ild_ratio` | `RMS_R/RMS_L` | 线性能量比 |
| 3 | `gcc_lag` | GCC-PHAT 峰值 lag | ITD 估计（样本） |
| 4 | `gcc_peak` | 互相关峰值高度 | 双麦相干性 / 是否有警笛 |
| 5~8 | `ild_band_k` | 各频段 RMS 比 | 高频遮挡 → N/S 可能靠频带差 |

#### Branch B 伪代码（2048 样本窗）

```c
// 对一个窗 L[], R[]，长度 N=2048
float rms_L = sqrtf(sum(L[i]*L[i]) / N);
float rms_R = sqrtf(sum(R[i]*R[i]) / N);
float ild_db = 20.0f * log10f((rms_R + 1e-8f) / (rms_L + 1e-8f));

// GCC-PHAT: 在 lag ∈ [-32, +32] 搜峰值（可用 CMSIS FFT）
int lag = gcc_phat_peak_lag(L, R, N, 32);
float features[8] = { ild_db, rms_R/rms_L, (float)lag, ... };
```

#### 在 DEEPCRAFT / 板端怎么实现

| 路径 | 做法 |
|------|------|
| **Studio preprocessor** | 用 CMSIS 单元算 GCC/Mel，输出 `[2048,2]` + `[8]` concat 后进 Network |
| **改 audio.c** | 每凑满 2048 样本算 `features[8]`，enqueue 时扩维（需 Studio 输入改为 2048×2+8 或双路输入） |
| **Innovation** | 文档写清「物理特征 + 深度学习融合」 |

#### 训练注意

- Branch B 特征 **必须归一化**（如 lag/32，ild_db/20）再进 Dense
- 校准集 int8 量化时，Branch B 数值范围要稳定
- **禁止** 对 Branch B 做「左右 swap」数据增强

#### 适用场景

- baseline CNN 在 **E/W 准、N/S 差**
- 想拿 **Innovation 20%**
- 8 方向相邻类混淆

---

### 2.5.4 方案 C：TCN / Dilated Conv1D

#### 原理

**膨胀卷积（Dilated Convolution）**：kernel 元素之间插入空洞，**不增加参数**却指数扩大感受野。

感受野近似：

\[
\text{RF} \approx 1 + \sum_i (k_i - 1) \cdot d_i
\]

5 层 k=7，dilation=1,2,4,8,16 → RF ≈ **1 + 6×(1+2+4+8+16) = 187 样本 ≈ 11.7 ms**（单层堆叠）；多层串联后可达 **整窗 2048** 甚至更长上下文。

对警笛：能同时看到 **单个周期内的波形** 和 **跨周期的 AM 调制**，比浅层 CNN 更懂「这是警笛而不是说话」。

#### 结构

```
Input: (2048, 2)  → 可 reshape 为 (2048, 2) 或 interleave 为 (4096, 1)

Conv1D 32, k=7, dilation=1,  padding=same  → ReLU
Conv1D 32, k=7, dilation=2,  padding=same  → ReLU
Conv1D 64, k=7, dilation=4,  padding=same  → ReLU
Conv1D 64, k=7, dilation=8,  padding=same  → ReLU
Conv1D 64, k=7, dilation=16, padding=same  → ReLU
GlobalAveragePooling1D
Dense(n+1) → Softmax
```

#### vs 普通 CNN / vs LSTM

| | TCN | 普通 CNN | LSTM |
|--|-----|----------|------|
| 长程依赖 | ✅ 大感受野 | 需深/大 kernel | ✅ |
| 并行 | ✅ | ✅ | ❌ |
| 边端 RAM | 中 | 低 | 高 |
| 小数据 | 中 | **最稳** | 易过拟合 |
| U55 | Conv ✅ | ✅ | — |

#### Studio / Code Gen

- Network 用 **Conv1D + dilation** 层（Keras `dilation_rate`）
- Code Gen 后 **必须** Build + 板上测；若 dilation 不支持 → 改为 **stride 卷积** 或回方案 A
- 输入可仍为 `(2048, 2)`，第一层 `Conv1D(32, 7, dilation=1)` 在最后一维扫

#### 适用场景

- unlabeled vs 警笛 分不清（需要更长上下文看周期）
- 方案 A 欠拟合（train/val 都低）
- 需要更长时序上下文，但 CRNN 的 LSTM 开销太大

---

### 2.5.5 方案 D：CRNN（Conv + LSTM）

#### 原理

**CNN** 在局部时频/时域 patch 上提特征 → **LSTM** 沿时间轴聚合 **「过去几十帧的状态序列」**。

对 DOA：LSTM 能记住 **ILD/ITD 随时间的缓慢变化** 和 **警笛调制节奏**，对 **N/S 这种单帧特征弱的类** 有时比单帧 CNN 好。

#### 两种输入形态

**D1 — Mel + CRNN（更常见）**

```
Mel 谱 (T_frames, 32, 2)   # 如 60 帧 × 32 mel × 2ch
→ Conv2D 16 → Pool → Conv2D 32 → Pool
→ Reshape (T', F)            # T'≈15 帧
→ LSTM(64)                   # 沿时间
→ Dense(n+1)
```

**D2 — 时域下采样 + CRNN**

```
(2048, 2) → Conv1D 降采样到 (128, 32)
→ LSTM(64) → Dense(n+1)
```

#### Mel 前端参数（与 §2.3 一致）

| 参数 | 值 |
|------|-----|
| FFT | 512 |
| Hop | 160 (10 ms) |
| Mel bins | 32 |
| 帧数 | 60 (~600 ms 上下文) |
| 输入 shape | `(60, 32, 2)` |

#### LSTM 训练技巧

| 技巧 | 原因 |
|------|------|
| `LSTM(64)` 不要更大 | RAM + 过拟合 |
| Dropout 0.2~0.3 | 小数据集 |
| 双向 LSTM 慎用 | 边端延迟翻倍，Code Gen 可能不支持 |
| 先看 **混淆矩阵 N/S** | 没改善就回方案 A/B |

#### Studio 支持

DEEPCRAFT PSOC 层表 **含 LSTM**；GRU 仅 ANSI C99，U55 上慎用。

#### 适用场景

- 警笛 **频率扫描（sweep）** 明显，时序结构强
- N/S 在方案 A/B 下仍混
- 可接受 RAM +10~20 KB

---

### 2.5.6 方案 E：Stereo Log-Mel + 2D CNN

#### 原理

人耳/语音识别常用 **Mel 频谱**：把 FFT 能量映射到 Mel 刻度，强调 **低中频结构**（警笛能量集中区）。

**Stereo**：左右各做 Mel，在 **channel 维 stack** → CNN 同时看 **频谱形状 + 左右差异**。

```
L → STFT → |·| → Mel → log → Mel_L (T, 32)
R → STFT → |·| → Mel → log → Mel_R (T, 32)
Stack → (T, 32, 2)
→ Conv2D 在 (time, mel) 上扫，2 通道 = 左右
```

#### 为何对警笛有效？

| 警笛特性 | Mel 的好处 |
|----------|------------|
| 窄带 + 扫频 | Mel 轴上轨迹清晰 |
| 高 SNR 尖峰 | log 压缩后动态范围稳 |
| 与语音区别大 | 频谱纹理不同 → unlabeled 好分 |

#### 网络结构

```
Input (1, 60, 32, 2)

Conv2D 16, 3×3, stride (2,2) → ReLU → MaxPool
Conv2D 32, 3×3, stride (2,2) → ReLU → MaxPool
Conv2D 64, 3×3 → ReLU
GlobalAveragePooling2D
Dense(n+1) → Softmax
```

#### 与方案 A 对比

| | 时域 CNN (A) | Mel CNN (E) |
|--|-------------|-------------|
| 空间特征 | 波形级 ILD/ITD | 频谱级 ILD |
| N/S | 靠波形反射模式 | 靠 **频谱左右差** |
| RAM | ~100 KB | ~120–150 KB |
| Studio | 现成 pipeline | 参考 `proj_cm33_ns` baby cry 改 stereo |

#### 适用场景

- 方案 A 对 **unlabeled vs 警笛** 分不清
- 环境噪声偏 **宽带**（说话、拍手）
- 愿意改 preprocessor 为 Mel 链

---

### 2.5.7 方案 F：层次分类（8 方向）

#### 原理

单模型 9-way softmax 在 **类间边界复杂** 时，决策边界扭曲 → 相邻方向互混。

**层次分解** = 多个 **简单二/三分类**，每级决策边界更干净：

```
                    ┌─ no  → unlabeled
Input window ──→ Stage1 (siren?)
                    └─ yes ↓
                         Stage2 (hemisphere?)
                    ┌─ left  → W, NW, SW
                    └─ right → E, NE, SE
                         ↓
                    Stage3 (quadrant / fine)
                    → 最终 {N, NE, E, SE, S, SW, W, NW}
```

#### 一种具体 4→8 方向映射（板子前方=N）

| Stage | 分类器 | 输出 |
|-------|--------|------|
| 1 | Siren detector | siren / unlabeled |
| 2 | E-W vs N-S 粗分 | 4 象限 |
| 3 | 象限内 2 分 | 最终 8 向 |

也可 **Stage2 = Left vs Right**，**Stage3 = Front vs Back**（2 麦分前后仍难，需数据支撑）。

#### 板端部署

```text
if (stage1 == unlabeled) return;
hemi = stage2(window);
direction = stage3(window, hemi);
```

- 3 次小模型推理；每个模型 **Flash 10~25 KB**，总计可能 < 单个大模型
- U55 上单次 <10 ms 级 → 3 次仍实时

#### 训练

- **每级单独** 采数据 / 打标签（或从原标签自动派生）
- Stage1 用 **unlabeled + 所有方向** 混合
- Stage3 只用 **该 hemispher 的子集**

#### 适用场景

- **8 方向** 且单模型混淆矩阵 ** off-diagonal 高**
- 有精力训 2~3 个小模型
- Innovation：「Hierarchical DOA for resource-constrained edge」

---

### 2.5.8 方案选型决策树

```
开始
  │
  ├─ example 能跑 + 有自采数据？ ─否→ Step 0~2
  │
  ├─ 4方向每向 r_i≥4/5？ ─是→ 扩 8 方向或交文档
  │
  ├─ E/W 准、N/S 差？ ─是→ 方案 B（+ 补 N/S 数据）
  │
  ├─ 全无警笛也乱报？ ─是→ 方案 E（Mel）或 Stage1 层次
  │
  ├─ 单帧分警笛但方向抖？ ─是→ audio.c 投票 + 方案 C（TCN）
  │
  ├─ 8方向相邻互混？ ─是→ 方案 F 层次 + 方案 B
  │
  └─ 仍不够且确认 Code Gen 支持？ ─→ 试 D（CRNN）
```

---

### 2.5.9 升级优先级（总结）

```
1. 数据 + 几何（固定角度/同警笛/N-S 加采）     ← +10% 常见，零模型改动
2. 方案 B（CNN + ILD/ITD/GCC 物理特征）        ← 2 麦 DOA 最对症
3. 方案 C（TCN）或 D（CRNN）                   ← 时序 / N-S
4. 方案 E（Mel CNN）                           ← 窄带警笛 / 抗噪
5. 方案 F（层次分类）                          ← n≥8
```

> **结论：** ILD/ITD 来自 **路径差**；E/W 靠 ILD+ITD，N/S 靠 **弱特征+固定几何+多数据**。  
> 冲精度首选 **方案 B 双分支**；要长程时序用 **TCN**；8 方向用 **层次 F + B**。

---

## 三、技术难点与解法

| # | 难点 | 为什么难 | 怎么解决 |
|---|------|----------|----------|
| 1 | **2 麦分 4 方向** | 前后方向特征弱 | 固定距离(0.5~1.5m)；N/S 多加数据；不自创第三种摆放方式 |
| 2 | **扩到 8 方向** | 相邻方向(E/NE)易混 | 每向 3~4min 数据；贴 45° 标记；混淆矩阵补采弱类 |
| 3 | **model.c 不能编辑** | 是编译产物 | 在 Studio 改 `.h5` → Train → Code Gen 覆盖 `model/` |
| 4 | **Studio 只显示 Welcome** | 无 `.improj` / `Design.deepcraft` | Accelerators 新建 Audio 工程，或 File→Open 已有工程 |
| 5 | **训练准、板上不准** | 增益/量化/过拟合 | 多种音量训练；校准集覆盖全方向；统一 `PDM_PCM_GAIN` |
| 6 | **输出乱跳** | 单帧不稳定 | `audio.c` 加：连续 3 帧同向才输出；最高分−次高分 > 0.15 |
| 7 | **int8 量化掉精度** | 校准不足 | Code Gen 勾选量化 + 用训练集作 calibration |
| 8 | **Build 失败** | GCC Release 不支持 | `common.mk` 保持 `CONFIG=Debug` |

---

## 四、分步执行

### Step 0 — 环境（Day 0，~1h）

1. 安装 [DEEPCRAFT Studio](https://softwaretools.infineon.com/assets/com.ifx.tb.tool.deepcraftstudio) + [ModusToolbox](https://www.infineon.com/design-resources/development-tools/sdk/modustoolbox-software)（含 ML pack、GCC 14.2）
2. Eclipse 打开 `test/` → Quick Panel → **Build Application**（必须通过）
3. Quick Panel → **Program** → 串口 115200 确认 example 能跑
4. 路径无空格、不要太深

---

### Step 1 — 搭采集环境（~1h）

**选 A 或 B，全程只用一种：**

- **A 固定板子移手机/音箱** — 板子标前方为 N，音箱依次放 N/E/S/W  
- **B 固定音箱转板子** — 音箱不动，板子转 4 个朝向  

1. 准备警笛 `.wav`/`.mp3`（比赛也用这个）
2. 地面胶带标方向角
3. （可选）Studio → Open `LiveDataCollection/` → `Main.imunit` → ▶ 试录一条

**板端采数据（双麦立体声）：**

1. 打开 https://osts.infineon.com/devkit/ai-mcu-applications?id=5  
2. Gesture detection → + → 选板 → **Experience Application with DEEPCRAFT Studio**（浏览器用 Edge/Opera）
3. Studio 连板采集，或 Accelerators 工程内采

---

### Step 2 — 采训练数据（~2~3h，4 方向 baseline）

| 标签 | 时长 | 内容 |
|------|------|------|
| `unlabeled` | 2 min | 无警笛、环境声 |
| `East/South/West/Nord` | 各 2~3 min | 同警笛；2 种音量；2 种距离 |

**操作：** Record → 播放警笛 → 按方向点标签 → Ctrl+S 保存 → 换方向重复  

**完成标准：** 每类至少几十段有效片段，Studio 里能看图谱/波形。

---

### Step 3 — 建 Studio 训练工程（~30min）

> 网络细节见 **§2.2～§2.6**

1. Eclipse → 选 `proj_cm55` → Quick Panel → **DEEPCRAFT Studio 5.12**
2. Welcome → **DEEPCRAFT Studio Accelerators** → **Audio** starter → 创建工程
3. 导入 Step 2 数据
4. 标签：`unlabeled`, `East`, `South`, `West`, `Nord`
5. Preprocessor：**2048 窗 × 2 通道**，16 kHz，stride≈1600（§2.2.2）
6. Network：按 §2.2.4 三层 Conv2D + GAP + Dense(**5**) + Softmax
7. 确认 Conv 含 **kernel (16,2)** 跨左右通道（§2.2.4 Block 2）

---

### Step 4 — 训练 + 评估（~1~2h）

> 超参见 **§2.2.6**

1. **Train** — Adam lr=1e-3，50–100 epoch
2. **Evaluate** — per-class accuracy + 混淆矩阵
3. 弱方向（常见 **N/S**，§2.4）→ 补采 → 再 Train
4. **过关线：** 每类 val > 80%，非对角混淆 < 15%
5. 通过后再 Code Gen

---

### Step 5 — Code Gen 写回板子（~30min）

1. 打开 `.h5` → 左侧 **Code Gen**
2. 设置：

   | 参数 | 值 |
   |------|-----|
   | Architecture | Infineon PSOC |
   | Target | **PSOC Edge M55/U55** |
   | Project Path | `...\hackathon_backup\test\proj_cm55` |
   | Output Directory | `model` |
   | Quantization | ✅ int8x8，校准用训练集 |

3. **Update Dependencies**（首次）→ **Generate Code**
4. 确认生成 `model.c`, `model.h`

---

### Step 6 — 编译烧录（~30min）

1. Eclipse → Refresh `test`
2. 确认 `common.mk`: `ML_DEEPCRAFT_CPU=cm55`
3. Quick Panel → **Build Application** → **Program**
4. 串口 115200：对四个方向播放警笛，看 `Output: East` 等

**不准时先调 `audio.c`（不用重训）：**

```c
#define OUTPUT_THRESHOLD_SCORE   0.6f   // 降低=更敏感
#define PDM_PCM_GAIN             CY_PDM_PCM_SEL_GAIN_5DB  // 可试 10dB
```

仍不准 → 回 Step 2 补数据或 Step 4 重训。

---

### Step 7 — 正式自测（~1h）

对每个方向 **5 次**，填 r_i：

| 方向 | ×5 测试 | r_i |
|------|---------|-----|
| East | 对/错 | /5 |
| South | | /5 |
| West | | /5 |
| Nord | | /5 |

**过关线：每向 r_i ≥ 4** → 可进 Step 8 扩 8 方向。

---

### Step 8 — 扩 8 方向（可选，~3~4h）

> 网络改动见 **§2.2.5**

1. 加标签：`NE`, `SE`, `SW`, `NW`（共 **9 类**）
2. 每新方向采 **3~4 min**；相邻方向边界样本（§2.4）
3. filters 16→24, 32→48, 64→96；Head Dense(**9**)
4. lr=5e-4，重新 Train + Code Gen
5. 再测 8×5=40 次

---

### Step 9 — 交付（截止前）

| 截止 | 动作 |
|------|------|
| **06.06 20:30** | Evaluation Kit 上 **Program** 最终固件 |
| **07.06** | GitHub 推代码 + 短文档（方案/数据/自测 r_i/创新点） |
| 随时 | 反馈邮件或 [GitHub Issue](https://github.com/Infineon/hackathon/issues) |

---

## 五、时间线

假设 hackathon **有效开发 ~12h**，按块执行：

| 时段 | 时长 | 做什么 | 怎么做 | 产出 |
|------|------|--------|--------|------|
| **T0** | 1h | 环境 + example 跑通 | Step 0 | Build/Program OK，串口有输出 |
| **T1** | 1h | 采集支架 + 警笛源 | Step 1 | 地面角度标记、采集链路通 |
| **T2** | 2~3h | 4 方向数据 | Step 2 | 5 类 labeled 数据集 |
| **T3** | 0.5h | Studio 工程 | Step 3 | `.improj` + 5 类标签 |
| **T4** | 1~2h | 训练评估 | Step 4 | 混淆矩阵可接受 |
| **T5** | 0.5h | Code Gen | Step 5 | 新 `model.c/h` |
| **T6** | 0.5h | 烧录初测 | Step 6 | 四方向基本能认 |
| **T7** | 1h | 调参 + 5×4 自测 | Step 6~7 | 每向 r_i 记录 |
| **T8** | 3~4h | （可选）8 方向 | Step 8 | n=8 模型 |
| **T9** | 1~2h | 文档 + GitHub | Step 9 | 提交物 |

**硬截止：**

```
06.06 20:30  →  板子烧最终版
07.06        →  文档 + 代码链接 + 反馈
```

**时间不够时的裁剪顺序：** 砍掉 8 方向 → 保证 4 方向 r_i≥4 → 文档最简版也要交。

---

## 六、推理稳定性实现（Innovation + 提分）

在 `audio.c` 的 `IMAI_dequeue` 结果处理处增加逻辑（概念）：

```c
// 1. 阈值：max_score >= OUTPUT_THRESHOLD_SCORE
// 2. Margin：max_score - second_best >= 0.15f
// 3. 投票：连续 3 次相同 best_label 才 printf Output
// 4. 否则输出空或 unlabeled
```

不改模型权重，Often 可 +1~2 次 r_i。

---

## 七、链接

| 用途 | 链接 |
|------|------|
| Hackathon 仓库 | https://github.com/Infineon/hackathon |
| 板端双麦采集固件 | https://osts.infineon.com/devkit/ai-mcu-applications?id=5 |
| DEEPCRAFT Studio 下载 | https://softwaretools.infineon.com/assets/com.ifx.tb.tool.deepcraftstudio |
| ModusToolbox 安装 | https://www.infineon.com/design-resources/development-tools/sdk/modustoolbox-software |
| ModusToolbox 安装指南 PDF | https://www.infineon.com/row/public/documents/30/68/infineon-modustoolbox-software-installation-guide-gettingstarted-en.pdf |
| Code Gen（M55/U55） | https://developer.imagimob.com/deepcraft-studio/code-generation/code-gen-infineon-boards |
| 部署到 PSOC Edge | https://developer.imagimob.com/deepcraft-studio/deployment/deploy-models-supported-boards/deploy-model-PSOC-6-PSOC-Edge |
| 提问 / Issue | https://github.com/Infineon/hackathon/issues |
| 反馈邮箱 | ericjoerg.schulze@infineon.com |

---

*策略 · 方案 · 步骤 · 时间线 — 2026 EESTech Challenge LC Munich*
