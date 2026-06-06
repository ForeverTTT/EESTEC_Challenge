/*
* ImagiNet Compiler 5.12.5418.0+7793ebcc9f383586f202c2d2f6eafbd7ebe6519d
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 06/06/2026 18:34:56 UTC. Any changes will be lost.
* 
* Model ID  a5c00468-3756-40fc-a4b7-e91654ac78dd
* 
* Memory    Size                      Efficiency
* Buffers   10256 bytes (RAM)         80 %
* State     25992 bytes (RAM)         100 %
* Readonly  42000 bytes (Flash)       100 %
* 
* Exported functions:
* 
*  @description: Try read data from model.
*  @param data_out Output features. Output float[5].
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*  int IMAI_dequeue(float *data_out);
* 
*  @description: Try write data to model.
*  @param data_in Input features. Input float[2].
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*  int IMAI_enqueue(const float *data_in);
* 
*  @description: Closes and flushes streams, free any heap allocated memory.
*  void IMAI_finalize(void);
* 
*  @description: Resets windows and neural networks(i.e. RNNs) to initial state.
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*  int IMAI_soft_reset(void);
* 
*  @description: Initializes buffers to initial state.
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*  int IMAI_init(void);
* 
* 
* Disclaimer:
*   The generated code relies on the optimizations done by the C compiler.
*   For example many for-loops of length 1 must be removed by the optimizer.
*   This can only be done if the functions are inlined and simplified.
*   Check disassembly if unsure.
*   tl;dr Compile using gcc with -O3 or -Ofast
* 
* Notes:
* 	-> This code was generated with DEEPCRAFT Studio using:
* 		ml-coretools 3.1.0.9404.
* 		tensorflow 2.19.0.
* 		ethos-u-vela 4.5.0.
* 	-> This code requires the following Modus Toolbox libraries (add them to your
* 	project using the Library Manager):
* 		ml-middleware 3.2.0.
* 		ml-tflite-micro 3.2.0.
*/

// Global symbol checks
#ifndef COMPONENT_ML_TFLM
	#error Symbol COMPONENT_ML_TFLM is not defined. Visit the Infineon ML\
	deployment example to see how to define this symbol. Add 'COMPONENTS+=ML_TFLM'\
	to your Makefile to enable this symbol.
#endif

#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include "cy_retarget_io.h"
#include "cy_utils.h"
#include "mtb_ml_model.h"
#include "mtb_ml_utils.h"
#include "mtb_ml.h"

#include "model.h"

#ifdef __GNUC__
	#define ALIGNED(x) __attribute__((aligned(x)))
#else
	#define ALIGNED(x) __declspec(align(x))
#endif

#if defined(__GNUC__) || defined(__clang__)
	#define ATTRIB_WEAK  __attribute__((weak))
#else
	#define ATTRIB_WEAK 
#endif

#ifdef CY_ML_MODEL_MEM
 #define IM_ML_MODEL_MEM CY_SECTION(EXPAND_AND_STRINGIFY(CY_ML_MODEL_MEM))
#else
 #define IM_ML_MODEL_MEM
#endif

#ifdef CY_ML_ARENA_MEM
 #define IM_ML_ARENA_MEM CY_SECTION(EXPAND_AND_STRINGIFY(CY_ML_ARENA_MEM))
#else
 #define IM_ML_ARENA_MEM CY_SECTION(".cy_socmem_data")
#endif

#ifdef CY_ML_WORKING_MEM
 #define IM_ML_WORKING_MEM CY_SECTION(EXPAND_AND_STRINGIFY(CY_ML_WORKING_MEM))
#else
 #define IM_ML_WORKING_MEM CY_SECTION(".cy_socmem_data")
#endif

// Working memory
static IM_ML_WORKING_MEM ALIGNED(16) int8_t _buffer[10256];
static IM_ML_ARENA_MEM ALIGNED(16) int8_t _state[25992];

// Parameters
static IM_ML_MODEL_MEM ALIGNED(16) uint32_t _k7[] = {
    0x0000001c, 0x334c4654, 0x00200014, 0x0018001c, 0x00100014, 0x0000000c, 0x00040008, 0x00000014, 
    0x0000001c, 0x00000090, 0x000000e8, 0x00008d00, 0x00008d10, 0x00009b2c, 0x00000003, 0x00000001, 
    0x00000010, 0x000a0000, 0x000c0010, 0x00040008, 0x0000000a, 0x0000000c, 0x0000001c, 0x0000003c, 
    0x0000000f, 0x76726573, 0x5f676e69, 0x61666564, 0x00746c75, 0x00000001, 0x00000004, 0xffffff98, 
    0x00000019, 0x00000004, 0x00000008, 0x6579616c, 0x33315f72, 0x00000000, 0x00000001, 0x00000004, 
    0xffff72da, 0x00000004, 0x00000007, 0x6579616c, 0x00305f72, 0x00000002, 0x00000034, 0x00000004, 
    0xffffffdc, 0x0000001c, 0x00000004, 0x00000013, 0x564e4f43, 0x49535245, 0x4d5f4e4f, 0x44415445, 
    0x00415441, 0x000c0008, 0x00040008, 0x00000008, 0x0000001b, 0x00000004, 0x00000013, 0x5f6e696d, 
    0x746e7572, 0x5f656d69, 0x73726576, 0x006e6f69, 0x0000001d, 0x00008c14, 0x00008c0c, 0x00008b7c, 
    0x00008aec, 0x00005adc, 0x0000474c, 0x00004708, 0x000046ec, 0x000046cc, 0x000016bc, 0x0000162c, 
    0x000003d4, 0x00000144, 0x00000120, 0x0000010c, 0x000000ec, 0x000000e4, 0x000000dc, 0x000000d4, 
    0x000000cc, 0x000000c4, 0x000000bc, 0x000000b4, 0x000000ac, 0x000000a4, 0x0000009c, 0x00000094, 
    0x00000074, 0x00000004, 0xffff73c2, 0x00000004, 0x00000060, 0x00000010, 0x00000000, 0x000e0008, 
    0x00040008, 0x00000008, 0x00000010, 0x00000024, 0x00060000, 0x00040008, 0x00000006, 0x00000004, 
    0x00000000, 0x0018000c, 0x00100014, 0x0004000c, 0x0000000c, 0xf709d43d, 0x4973759e, 0x00000003, 
    0x00000002, 0x00000004, 0x00000006, 0x39312e32, 0x0000302e, 0xffff742e, 0x00000004, 0x00000010, 
    0x2e362e31, 0x00000030, 0x00000000, 0x00000000, 0xffff66e8, 0xffff66ec, 0xffff66f0, 0xffff66f4, 
    0xffff66f8, 0xffff66fc, 0xffff6700, 0xffff6704, 0xffff6708, 0xffff670c, 0xffff6710, 0xffff7476, 
    0x00000004, 0x00000010, 0x00000001, 0x00000001, 0x00000032, 0x0000001e, 0xffff7492, 0x00000004, 
    0x00000004, 0x00000001, 0xffff74a2, 0x00000004, 0x00000014, 0xbd27c601, 0x3d055627, 0xbc16971e, 
    0x3db5bf2b, 0xbda4ae27, 0xffff74c2, 0x00000004, 0x00000280, 0x3e8aa0f0, 0xbefca42f, 0xbdd99dc2, 
    0xbdeebeef, 0xbe9a79a0, 0xbe54b698, 0xbe1747c2, 0xbc1f1d29, 0x3eca3c5e, 0x3e25b2df, 0x3eb8bf88, 
    0xbea59aa0, 0x3eb0bc79, 0xbe89df4f, 0x3d7ec491, 0xbdf8b334, 0x3e717aa1, 0x3ead4434, 0x3dc6fb1b, 
    0xbe94cab6, 0x3dc7b008, 0xbe4c661a, 0x3e868a7c, 0x3ebdcbb1, 0xbdef0f84, 0xbda0f7ea, 0xbe88e230, 
    0x3dca0248, 0xbeff8459, 0x3dff4fa7, 0x3d89c471, 0x3ed20af8, 0x3eac742b, 0x3e9683e5, 0xbef99165, 
    0x3eed751d, 0x3dac6520, 0xbe54011b, 0xbde57f99, 0xbddc0495, 0xbe4590a6, 0x3d3c12bb, 0xbeb04d5c, 
    0x3ee7642f, 0xbeecee78, 0xbea11fdf, 0xbe0aef72, 0xbee62f37, 0xbf0daee8, 0xbec75418, 0xbef503dd, 
    0xbe9fef08, 0x3eeb516c, 0x3d2de8cd, 0x3e44f15f, 0xbeb8f0f0, 0x3dba3127, 0xbf037415, 0x3e982e4c, 
    0x3e8ced41, 0x3ccf6d8f, 0xbec2a10c, 0x3e033af4, 0x3c0937a9, 0xbe487fe7, 0x3e99259c, 0xbcd28b1b, 
    0xbd512a9a, 0xbe5e915e, 0xbdbc1eb5, 0xbf00aaa4, 0xbf06abd4, 0xbe4969d1, 0xbd655927, 0xbe57d003, 
    0xbe8485fe, 0xbba3ff39, 0xbef39c10, 0x3e47e846, 0x3ecd6f1c, 0x3ecfef17, 0x3ebf4533, 0xbe3a21a7, 
    0xbe9ad330, 0xbebdca03, 0x3ee43b5b, 0xbec5e904, 0xbe6466d2, 0xbe8672b2, 0x3eb03910, 0xbe51f00b, 
    0x3e87ca89, 0x3e93ed44, 0xbe2627bb, 0xbedcbe57, 0x3ea528c3, 0x3d528783, 0xbedba987, 0x3f0813e7, 
    0xbe8275d8, 0x3f0280cf, 0xbe400af8, 0xbebfc11f, 0x3db8f006, 0xbeae3ef8, 0xbd3b9f9c, 0xbdbebcd9, 
    0xbeacb223, 0xbe6ee475, 0xbea10e58, 0x3d9ba719, 0x3e829f9e, 0xbd5c86d9, 0xbe8be552, 0x3ef356ec, 
    0xbe81e14b, 0xbece1f3a, 0x3d9b85f3, 0xbd6d80b4, 0xbdfe3b1a, 0xbe59a99e, 0xbd3b12ff, 0xbe9a0267, 
    0x3d9d38bc, 0x3e894c1e, 0xbe1230e0, 0x3e4f3d74, 0xbed771c5, 0xbf0d9a98, 0xbe229f70, 0x3ea65e1c, 
    0x3e97383e, 0xbf0d2bf5, 0x3cf18b61, 0xbdd89c8e, 0x3eaa2188, 0x3ebb3e44, 0x3d5afa1d, 0x3e990e04, 
    0x3eb21485, 0x3e6a9446, 0x3e3da0af, 0x3ed53ee8, 0xbeb86e1f, 0x3d9ff78d, 0xbe1e2841, 0xbe05be54, 
    0x3dfa15f1, 0xbeac3907, 0xbe36e24e, 0x3d5f0325, 0xbdf83f6d, 0x3e0eacad, 0xbe207918, 0xbec10d49, 
    0x3eade795, 0xbec5c365, 0xbed39edc, 0xbf0676df, 0x3e1f6175, 0xffff774e, 0x00000004, 0x00001248, 
    0xbd83a1a7, 0xbcc761be, 0xbdd6a13c, 0x3e3f885a, 0x3d6d2323, 0xbdc6073a, 0x3d5a5fed, 0xbd8d45a3, 
    0x3e2ecfb9, 0x3d06b1d3, 0xbd9fc27d, 0x3ce8b75b, 0xbdcc7ceb, 0x3d87d091, 0xbe700851, 0x3de64aca, 
    0x3e028779, 0x3e296464, 0x3c1d4835, 0xbcc20751, 0x3c39c139, 0x3e342aee, 0xbdab706d, 0x3def8a77, 
    0x3c33d085, 0x3dd398c2, 0x3e0a2272, 0xbb9d713c, 0xbe4421f7, 0xbd8775e4, 0xbdf7c350, 0x3dcf8022, 
    0x3df0b08b, 0xbcfbfc56, 0x3e532338, 0xbda1c588, 0xbd61c451, 0xbc0d78ee, 0xbe23337c, 0x3db94a95, 
    0xbd5dfed0, 0xbda0909d, 0xbdbabf6f, 0xbdd44cb2, 0xbd708b0b, 0xbd728d33, 0xbe3f18ec, 0xbe1f43a2, 
    0x3e31fa10, 0x3e0440d1, 0x3d420bb9, 0xbe0c494f, 0xbddcf394, 0xbe336553, 0x3e099f1c, 0x3de0b8c9, 
    0x3dd70952, 0xbde2e1d9, 0xbe2bdf8a, 0xbe183573, 0x3e286aeb, 0x3da2a1e4, 0x3dc1e5c9, 0x3d307230, 
    0x3ddfd450, 0x3dd1ffcb, 0x3e40ec94, 0xbe26c30d, 0xbe355f66, 0xbe33a7a6, 0x3e5621dc, 0x3dd9556a, 
    0xbdce1156, 0xbdd2e629, 0xbdd4f57e, 0x3e49e5cc, 0xbd5f6bf1, 0x3d90daa4, 0xbcaa388e, 0xbe0f8e1f, 
    0xbde4aa6a, 0xbe3f0e39, 0xbde593d0, 0xbe12b775, 0x3e794f11, 0xbe306d12, 0xbe588769, 0xbd74c74b, 
    0x3cf9ef87, 0xbe5d56fe, 0x3bf3f410, 0xbddaa71a, 0xbe24fa69, 0x3d86e346, 0x3e6bfcf8, 0xbe063ca8, 
    0xbe6a6cff, 0xbde265be, 0x3da4fde6, 0xbcb16771, 0x3da55a95, 0xbc3cc248, 0xbdb17288, 0xbdf4f3c2, 
    0x3dd833ae, 0x3e275efc, 0x3e052c0a, 0x3de864e5, 0xbdc9a854, 0x3b63c135, 0xba93683c, 0xbe0e34e3, 
    0x3e008e2f, 0x3e447e7a, 0x3d8c71f3, 0xbe6026f9, 0xbe1ff8fb, 0xbdd6b7d1, 0x3e5eb624, 0xbe2e3d93, 
    0xbd705f6e, 0x3d8a6431, 0xbdcba1bd, 0xbd23280f, 0xbe01c419, 0xbd17aa70, 0x3e02e22b, 0xbe2a6dba, 
    0xbdb3daa4, 0x3da3f102, 0xbc1f144d, 0xbdcf1438, 0x3e452542, 0xbe84447f, 0xbcf25c56, 0xbcb5bacd, 
    0x3e42d4a4, 0xbdf19b4c, 0x3c9eb0e9, 0xbe2b409a, 0x3e0b2fd7, 0xbd00619a, 0xbdd5ab87, 0xbde00c8a, 
    0x3e172711, 0x3dddc00b, 0x3e00f0cb, 0x3e83abe8, 0x3ba2004a, 0x3d805f22, 0xbdffb39f, 0x3b00616e, 
    0x3e3aa5f9, 0xbcca3df6, 0x3d06879f, 0x3e06957b, 0xbe2bf991, 0x3de2ef14, 0xbe13c65a, 0x3bd14552, 
    0xbdec8b3e, 0xbe40549a, 0x3ce4e10a, 0x3cc42bf3, 0x3cf89cca, 0x3e3597d0, 0xbdc5a8c7, 0xbde4595e, 
    0x3cf7090b, 0xbd3dc6e8, 0xbe0f51a7, 0xbe20e8f9, 0xbddbf10f, 0xbd0b4a6a, 0x3de46820, 0xbe4e9377, 
    0xbd019862, 0xbe228604, 0x3c8ea637, 0x3da43d0e, 0x3e0ea275, 0xbe5260ac, 0x3e49c8b6, 0x3d903cc2, 
    0xbd8c810b, 0xbe5a2ba7, 0xbd4e412c, 0x3e6a94be, 0xbe32739b, 0xbe47263e, 0x3d985c47, 0x3cd6d684, 
    0x3dcd2f76, 0x3e01c49e, 0xbe5821fa, 0xbd59a728, 0x3e1836bc, 0xbd25a199, 0xbd9f619d, 0x3c968f45, 
    0xbd92283d, 0xbe136cb0, 0xbd08d5d2, 0x3db5d090, 0xbd034762, 0xbe0b36bf, 0x3e464605, 0xbe213ffb, 
    0xbc3201e9, 0xbdda329b, 0xbe0f9019, 0x3e422322, 0xbd138b32, 0xbe21baa8, 0xbd15cf54, 0x3e0dea00, 
    0x3b63e6e5, 0x3e22ccbf, 0x3d80c2f2, 0xbe0f67f5, 0x3ded4b77, 0x3e08c526, 0x3ce765ad, 0xbe3ae74c, 
    0x3e0e5fd5, 0x3d9ea26a, 0xbde099b8, 0xbdeaaf8a, 0xbdbff1f6, 0xbe1f5bd2, 0xbdf5a4ff, 0xbe2f0ca0, 
    0xbe23fcfa, 0xbe546947, 0x3da56467, 0x3c6fe457, 0x3e00259e, 0xbdefad95, 0x3e21f1f7, 0x3e346adc, 
    0xbddcf535, 0x3c12ce4d, 0xbdeb5908, 0xbde50b88, 0xbcbdf572, 0x3e0b8f91, 0x3e11f49d, 0xbe43c3a7, 
    0xbd9a14a1, 0xbe1da725, 0x3e5cad11, 0xbd140719, 0xbcbf8b04, 0xbd987fb7, 0x3d90adc0, 0xbe309831, 
    0xbd1a9e55, 0x3daf789b, 0x3e6e50d5, 0x3e20b5ee, 0xbe768751, 0xbbf251d5, 0xbd8b2f19, 0x3d9ee972, 
    0x3d943f56, 0x3d7cea75, 0xbcf9e60c, 0xbe389989, 0x3d9154e7, 0x3e07739e, 0x3e15c60d, 0xbdd65edc, 
    0x3da42244, 0x3c947356, 0xbd1ce7f5, 0xbd9df2c1, 0x3e1656dc, 0x3dbb28fb, 0x3c8b87e4, 0x3e485bf1, 
    0x3e1d0b44, 0xbd03426a, 0x3c070591, 0xbe273327, 0xbe78c297, 0xbdc4a062, 0xbd08bb35, 0x3e050d15, 
    0x3cda1c12, 0xbe186897, 0x3e03230a, 0xbe82a1e7, 0xbdbed086, 0xbdf33781, 0xbe33bd4b, 0x3c062f21, 
    0x3dafb428, 0xbd322a5e, 0x3e90829e, 0x3e8b6709, 0x3c0c0ea4, 0xbe37645b, 0xbd053a43, 0x3da265c1, 
    0x3bf10364, 0xbe42be80, 0xbdbfd8d8, 0xbdd80c1e, 0x3e15e59d, 0xbde418cb, 0xbe18e293, 0xbd4e7a57, 
    0xbdf47399, 0xbcecc6e3, 0xbdb592b1, 0xbdb776b0, 0xbe34b806, 0x3e56d2d6, 0xbdd67a2a, 0xbe283c21, 
    0xbd097210, 0xbcd522e2, 0x3d0cdd20, 0x3ce6e7e9, 0x3e28b360, 0x3e139d54, 0x3c6a4842, 0xbe46c8de, 
    0x3de6b49f, 0x3daa21df, 0x3caf5ac3, 0x3db8a4cc, 0xbc2ad3fc, 0x3db1e4f0, 0xbc14ee04, 0x3e03493a, 
    0xbe10afa0, 0x3defb6e4, 0xbdb658c6, 0x3e144f74, 0xbd4d636a, 0x3d293117, 0xbddc3bda, 0xbd45dc7c, 
    0x3c8edc4b, 0x3e1bffe5, 0x3c5bb30e, 0xbd2c8823, 0x3dcbb10b, 0x3e559b3d, 0x3dff2b01, 0xbc9c90d1, 
    0xbd90188f, 0xbdd4eed5, 0x3e1f9470, 0xbe32741a, 0xbe65955b, 0xbd1dac59, 0xbd91694b, 0x3e122af1, 
    0xbd9d4b5f, 0xbcca19c2, 0xbe08b7d7, 0xbe3948c5, 0x3d60ec32, 0xbcc01f20, 0x3d206bb5, 0x3d77b07b, 
    0x3ddd2e81, 0x3dd1f131, 0x3e18039b, 0xbde242a8, 0x3d04d50b, 0xbe38c759, 0xbd1725ff, 0x3dfdc60f, 
    0x3acc49ec, 0xbe3e019c, 0xbd417390, 0xbdd01765, 0xbd3989f5, 0x3d9e4581, 0x3e014d0b, 0x3d9b44cb, 
    0xbda00284, 0x3d9daffa, 0x3e34a05a, 0xbe2057f6, 0x3e3ad57f, 0x3e846aeb, 0x3dca9bfb, 0x3dcfc2cb, 
    0x3e2c2ae4, 0xbbfc3753, 0xbdba39c0, 0xbe06e45e, 0x3e09a13b, 0xbd33260e, 0xbd78c3fe, 0xbe14bae4, 
    0x3d910a87, 0x3d44bd6c, 0xbd7bec73, 0xbe1de007, 0xbe0bc0e6, 0xbc0a3b67, 0xbd39c7cf, 0xbbe2fa21, 
    0x3de4a4b2, 0x3c10970e, 0x3e45406a, 0x3dab2661, 0x3e3a5e33, 0x3c8670fb, 0x3e55b4aa, 0xbe3095df, 
    0xbc9890f1, 0x3e0582a3, 0x3cb739ec, 0x3e0c01f4, 0xbc1395a7, 0xba982490, 0xbe1dea67, 0x3e2066ba, 
    0x3d3545ee, 0x3e49a710, 0xbd928181, 0xbdae197a, 0xbe06fa12, 0xbc60b3b2, 0xbe6089cc, 0xbe355f60, 
    0xbdfc3105, 0x3d9e705d, 0xbddca0e6, 0xbe74e3d6, 0xbd6311e4, 0xbe0f7ac2, 0xbdeea930, 0x3e3e7fb5, 
    0x3d07cd60, 0x3c2b3e7e, 0xbdfcb152, 0xbd5f4b3f, 0xbd21c3f6, 0xbda33ffb, 0x3df34bfb, 0x3e21c3f4, 
    0xbe0de52e, 0x3e61063b, 0x3d0037f7, 0xbe36034d, 0x3e2d5143, 0xbdf9363f, 0xbe7a0409, 0x3dda8fad, 
    0xbce7bf1e, 0xbd4264da, 0xbcfed7aa, 0xbae3bb2f, 0x3e1753df, 0xbe350cb0, 0x3e63e4e5, 0xbd472585, 
    0xbda5f21f, 0x3e8c1b0f, 0x3d7ab0f1, 0x3d4159e2, 0x3dfa5e88, 0xbe2ccf91, 0x3da1fe99, 0xbadcc3aa, 
    0xbe5a8d21, 0x3d3d9267, 0xbca55cd8, 0xbe094213, 0xbe3324ca, 0xbd51a608, 0x3ac98905, 0xbe81c5c2, 
    0x3e1fe8ac, 0x3d835ca9, 0xbe19cddb, 0x3e6145fd, 0xbd470462, 0x3c7f83ee, 0x3ce01177, 0x3e6455a1, 
    0xbe1c45bc, 0x3e26d06f, 0xbdc082f9, 0xbd864324, 0x3d51c7b2, 0x3d0a08dd, 0xbdfc6e0c, 0x3db38823, 
    0x3e140c95, 0xbdadf013, 0xbdec4692, 0xbbd7ad64, 0x3e0387ee, 0xbd4619df, 0xbd01d830, 0xbe098d7b, 
    0x3e2fbc7e, 0x3d811503, 0xbd8e8bf4, 0xbd8d892c, 0xbe8c7e94, 0x3c82db0a, 0xbd285052, 0xbd029aaf, 
    0xbdc836a1, 0x3d35e2d4, 0xbda4185b, 0x3d920db9, 0xbe270e3c, 0x3da40b31, 0xbdf16a7e, 0xbda2ad58, 
    0x3e0eb075, 0xbc99a18c, 0x3e135641, 0xbd29bb12, 0x3e676dc7, 0x3de89d13, 0x3e59b120, 0xbc69d242, 
    0xbdb2d100, 0xbe0ee28b, 0x3e66940c, 0x3d1a5d12, 0x3dac5130, 0x3e2e0118, 0xbe0b02f7, 0xbd98a046, 
    0xbd01c480, 0x3bffeff9, 0xbe8a3e30, 0xbd88d933, 0x3bfba83b, 0x3c42b1eb, 0x3d2cd926, 0xbdc5d6a2, 
    0xbe0a442e, 0x3e13b702, 0xbd85444d, 0xbe11250b, 0xbd569d50, 0x3dddabb3, 0xbe189dc5, 0x3df8358e, 
    0x3e275a35, 0xbdfd6fbe, 0xbe010fcc, 0xbd995f59, 0xbd931510, 0xbe307f08, 0xbe5b4333, 0x3cb729ad, 
    0x3dd35d90, 0xbdcb77c6, 0xbc65009e, 0x3d8d5d0c, 0xbdb618c6, 0xbdb5ddc6, 0x3c54c777, 0x3e25036a, 
    0xbcf4fba9, 0x3e6360ab, 0x3d8c87c0, 0xbd708406, 0x3dc3c6a7, 0x3d18def3, 0xbdeb5172, 0xbd16ec77, 
    0x3e283dac, 0x3d6fc9c4, 0xbe0f7f71, 0xbe8a9ec8, 0x3e0782c8, 0x3c9f9542, 0xbcb2f9c1, 0x3e2c2025, 
    0xbc9a6d77, 0x3d907e70, 0x3ba36553, 0xbdf4a1fc, 0x3e109828, 0x3db5b9d5, 0x3dead2be, 0x3dde8462, 
    0xbd4d53bb, 0xbdbc3880, 0x3e48ea0a, 0x3c0b0540, 0x3d9af3c2, 0xbd4baf96, 0x3d924bbd, 0xbda2e502, 
    0xbbffb3e0, 0xbdc06c53, 0x3e2522c7, 0xba948e2b, 0x3d9b92d8, 0xbc27efbe, 0x3e50a8d4, 0x3d852a47, 
    0x3b9335ea, 0x3c6fb734, 0x3db0005b, 0xbe1f5093, 0xbe19395c, 0x3d415889, 0xbd05225e, 0x3d4a0a38, 
    0x3e569e6d, 0xbd61a0c2, 0x3daa7145, 0xbe520e08, 0x3e750528, 0xbe530c39, 0x3d91b4ee, 0x3e38446a, 
    0x3e70efc3, 0xbe3dec94, 0xbdf046fb, 0xbe020d7b, 0xbd93617c, 0x3e196b8f, 0xbdf17031, 0x3e0cb11b, 
    0xbcdb6fb6, 0x3e58dabb, 0xbe2ad63c, 0x3e04a5f8, 0x3e42ed02, 0xbe171944, 0xbdd8e0ac, 0x3d44b24b, 
    0xbe70e3f0, 0x3de96e64, 0xbe2feb15, 0xbe3c8c69, 0xbd25159e, 0x3ca3f4e3, 0x3e298142, 0x3e5035f8, 
    0x3e7d2609, 0x3dcc6e95, 0xbe08c293, 0x3dd62d13, 0x3cae7fab, 0xbd4f97b8, 0xbd66c0ff, 0xbddebd44, 
    0xbe6b33dd, 0xbe88fbb3, 0x3db130a7, 0x3debb2a9, 0xba84da21, 0xbe395d28, 0x3d59e9c4, 0x3d8e072a, 
    0x3dd83094, 0xbd04ad14, 0x3dbaa897, 0x3e012df0, 0xbd3c1cf5, 0x3d224e13, 0x3e22643a, 0xbdc3b809, 
    0x3e06495a, 0xbb2610aa, 0x3d26e4f8, 0xbe470744, 0x3c57d115, 0x3e540b9d, 0x3d4adcc4, 0xbdceaaa6, 
    0x3c9cf591, 0x3e776053, 0xbcd03a8e, 0xbd31d0e3, 0x3e291509, 0x3e395376, 0xbdd9580f, 0xbdbe61ed, 
    0xbda8b3b6, 0xbd40c64d, 0xbe141507, 0x3e46e1f6, 0x3d67a9f0, 0xbe046409, 0xbda183f5, 0xbd8c2aec, 
    0x3c91a2c3, 0x3d5d90db, 0xbe7b6da7, 0xbda26a45, 0xbd9de832, 0x3ac52de7, 0xbe40b29e, 0x3db44ba3, 
    0x3d7a5758, 0xbe20eb24, 0x3d421c5f, 0xbe30147a, 0xbd61dc64, 0xbbeeac86, 0x3e059d49, 0xbd977920, 
    0x3d0d56db, 0x3dc2708c, 0xbe3bf428, 0xbda7c9a2, 0x3ce47a8f, 0x3ddbeedc, 0x3daba323, 0xbdb1fce2, 
    0xbde11eef, 0x3d52957b, 0x3d6b184d, 0x3dd78c0c, 0x3e732afa, 0x3d8c6af5, 0x3dc05efe, 0xbe3f36cc, 
    0xbd6d8ecf, 0x3deab0ac, 0x3d0a6c59, 0x3e1fedc1, 0xbdbe7365, 0x3df7677a, 0x3d7ad3f9, 0x3da2acab, 
    0xbabf0280, 0x3e57b0b9, 0xbdbc55a6, 0x3e1c5b04, 0xbdb0f050, 0xbe0a8cb5, 0xbdac9d81, 0x3e3b1cdf, 
    0x3c7263d8, 0x3dea9dfa, 0xbe1cc88e, 0xbe055c07, 0x3e556d87, 0xbe5ba7b9, 0x3e1f2f5a, 0xbd0d63b6, 
    0xbdeb53fd, 0x3dc73bbb, 0xbda8ebe9, 0xbca04ab5, 0x3e2bc712, 0xbd30765e, 0x3dc7993e, 0x3e3969ba, 
    0x3c695f1a, 0xbd4f66c2, 0xbd08ee1a, 0x3e309fa7, 0xbd46adda, 0xbe1ec89f, 0x3e249b69, 0x3e4c21df, 
    0xbb7696c3, 0xbb8ca215, 0xbe1cb43c, 0xbe2b13ea, 0xbcd5470f, 0xbd9686a7, 0xbbf7021f, 0x3e4eaf27, 
    0xbda558fc, 0xbddf292d, 0xbdd5b026, 0x3dbcc856, 0xbdcba467, 0x3dc45014, 0xbe56d20f, 0x3d9a38c7, 
    0x3dcc99e6, 0xbdba9781, 0x3d4f9c29, 0xbc3b3752, 0x3e1817fc, 0xbc887d02, 0x3d2d507d, 0xbe19d31c, 
    0x3e060b63, 0x3d332812, 0xbc7e9064, 0x3da0ce1e, 0x3db2db25, 0x3c6ade63, 0xbe3d6bc7, 0xbb420d55, 
    0x3d5145ae, 0xbe0f4a88, 0xbd175f66, 0x3e33c862, 0xbdfe771a, 0x3dbe1b51, 0xbe3d3e23, 0xbe2ab28f, 
    0x3d85d731, 0xbdddfd5e, 0x3e344538, 0x3d4a740b, 0xbd9c4f9e, 0xbdc71bc6, 0xbe02695b, 0xbdd96a66, 
    0xbd19a075, 0xbdfbb9c2, 0x3cc9c74a, 0x3d0e54e6, 0xbd353df0, 0x3e17869b, 0xbdf41aa4, 0xbb481c70, 
    0xbd8a7e20, 0xbddff393, 0xbe601885, 0x3d1b29c4, 0x3cd3edea, 0xbe422efb, 0xbe6c969e, 0xbd84ea36, 
    0x3e05a039, 0x3ceb0410, 0xbe016ca6, 0x3e2b11e8, 0xbe43ef2f, 0xbd1410d0, 0xbe273e6a, 0x3cc81045, 
    0xbddd63cd, 0xbae3b8f6, 0x3dd21509, 0x3d948e34, 0xbcc4cec5, 0x3dbe1b44, 0xbd9053a7, 0x3e132b20, 
    0x3d81b71f, 0x3dd9f19e, 0x3e5dc9fa, 0x3d8637a9, 0xbdb6268c, 0xbd9e89da, 0xbe18ae22, 0x3c7eb15c, 
    0xbe9d67c1, 0xbd842e2c, 0xbd91ede3, 0x3e275574, 0xbd2783cd, 0x3db68fc7, 0x3da0f215, 0x3d3bd4a0, 
    0xbe20da06, 0x3e529097, 0xbe27f7a4, 0xbe5ad5e4, 0x3dad32e7, 0xbe0de108, 0xbd968b66, 0xbe55988c, 
    0x3e3f58e2, 0x3e064cfd, 0x3dd09bcf, 0x3cd9b449, 0x3dc065c4, 0xbd7b0ea4, 0xbcb7e491, 0x3e4f0e4d, 
    0xbd26a907, 0x3d92f04a, 0x3dab053f, 0xbdd3ab3e, 0x3d81f899, 0x3db8a1c8, 0xbe066b5d, 0xbe38dae0, 
    0x3d9e92e5, 0x3e4bea0b, 0xbe0c6777, 0xbc5b9699, 0x3e3adc6f, 0x3dc6f6a7, 0x3c9da696, 0x3900fa0a, 
    0x3e3b1ea4, 0x3db8a2bd, 0xbe2b7d98, 0x3dcd736e, 0x3db4a4db, 0xbe3c6380, 0xbdf3c275, 0xbd95da0c, 
    0xbe35b3ce, 0x3e1eb822, 0x3cce34c4, 0x3e0bfbed, 0x3dd612bb, 0xbd90c33c, 0x3e5ca2d3, 0x3d95f366, 
    0xbde909a7, 0x3cf08c12, 0x3dd04b59, 0xbda2aaea, 0x3e3d5547, 0x3ddf99f4, 0xbdd32d9b, 0xbe361a63, 
    0xbe5afc66, 0xbd8baebb, 0xbde4b643, 0xbe31cb3d, 0x3dc95e52, 0x3d2d3fa2, 0x3d5fbc3d, 0xbe6336d2, 
    0xbc93a1e7, 0x3d422494, 0x3e4bb697, 0x3db0a2fe, 0x3e003cae, 0xbde067b2, 0x3d37752e, 0xbd847916, 
    0x3dfef206, 0x3dff9ba8, 0x3cac2c55, 0x3e6b4418, 0x3da688e2, 0xbe5b1ced, 0xbe3574b5, 0x3e524ce3, 
    0xbc877a60, 0x3e66172a, 0xbca11f44, 0x3da09b14, 0xbd00136f, 0x3c56ef6b, 0xbe60cf9f, 0x3e4c78f1, 
    0x3d356dd5, 0x3d932933, 0x3d394e3a, 0xbe0ea034, 0x3e4ecc79, 0xbe21e923, 0x3deb95e3, 0x3e12ffe2, 
    0xbe244792, 0xbb7ead20, 0xbd307266, 0x3d967c33, 0xbe3b656e, 0xbe011662, 0xbe3e21dc, 0xbd1ec98b, 
    0xbddba2cb, 0xbddd5ca4, 0xbdbcd75e, 0xbe2d0c06, 0xbc133118, 0x3e3197d4, 0x3e343dd1, 0xbdf72042, 
    0x3d22774d, 0x3e0153e6, 0x3e104cd4, 0xbd01d333, 0xbcc61d07, 0x3d8b76cb, 0xbd854ff4, 0x3dfc11a9, 
    0x3e181791, 0xbd75231b, 0x3e08bc2a, 0xbe57d5e9, 0x3dea2b1c, 0x3e07eea2, 0xbe1fcc97, 0xbd869984, 
    0xbdd15ab1, 0xbdf0eb52, 0x3ddf6186, 0xbb8404da, 0x3e4bb982, 0x3d7a330c, 0xbe12724b, 0xbe18609d, 
    0xbdc8398e, 0x3e6c4227, 0xbbb8110b, 0xbe00fbd8, 0x3e4fc665, 0xbe48157a, 0xbd6f3d05, 0x3d9707cd, 
    0x3d042c51, 0xbd05c2fb, 0xbd8fe1fb, 0xbe12c383, 0xbe5b2e31, 0xbe380ca7, 0xbe3abb81, 0xbdef0172, 
    0xbdd09ff3, 0xbdf559ac, 0xbdf46655, 0xbc6e57b5, 0x3ce99d9a, 0x3d10cef6, 0xbc98f5b5, 0xbd20eaee, 
    0xbe24e50a, 0xbd04b2c8, 0x3ded7c54, 0xbdb29819, 0x3e44666f, 0xbe08ffdd, 0x3e2e2991, 0xbd2a249d, 
    0xbdfa56a9, 0x3e5ecbc1, 0x3e3264ad, 0x3d49f25d, 0x3e2b2b4b, 0xbe128d73, 0x3c944ab4, 0x3e30124e, 
    0x3e6e46e7, 0xbd88ea71, 0xbe32a94e, 0x3e3c8230, 0xbddbc020, 0x3e3e43fd, 0xbd9bc538, 0xbcf1d847, 
    0xbe3529e5, 0x3e74e189, 0x3e567c58, 0xbe1132a8, 0x3d8048c8, 0xbdcd1559, 0x3dbcbd57, 0xbab90fc5, 
    0x3e6bd797, 0xbe33747e, 0x3df4ce09, 0x3d15615b, 0x3dd6f13a, 0x3dd88f86, 0x3e00c30c, 0xbdf8d1b7, 
    0x3d94df2a, 0xbe4efc01, 0x3d00b9db, 0x3e0308f3, 0xbd33f515, 0xbe0d2a5d, 0x3e0fe78f, 0xbe204112, 
    0x3d9432f5, 0xbe401c3e, 0xbdf84415, 0x3ba404c3, 0x3d841a37, 0xbe0d4908, 0xbc63f203, 0xbdd4a6b1, 
    0xbc9187d2, 0x3d963b97, 0x3c68d4cf, 0x3d6925f8, 0xbdce6610, 0x3e40e165, 0xbb7eb245, 0x3d074cb5, 
    0xbe2b5384, 0x3c88fc82, 0x3d0c5680, 0x3ba27f14, 0x3d1389be, 0xbd9b19fa, 0xbe1051bf, 0xbd93d2cd, 
    0x3dc67df1, 0x3d2f4a64, 0x3d1a1a01, 0x3e03a3c9, 0x3de5df36, 0x3d976a2a, 0xbd32f557, 0x3e0f9b3b, 
    0xbe002519, 0xbc171862, 0x3df13d4e, 0x3e56fda5, 0x3e062083, 0x3e197883, 0xbd22fa06, 0xbcc63248, 
    0x3da6e011, 0x3e18db9b, 0xbd2b8b5a, 0x3d08bf23, 0xbe023178, 0xbe21427c, 0xbe424d90, 0xbd1d4e3a, 
    0x3e430d79, 0xbc9a7deb, 0x3cc1a7ea, 0x3dcd7638, 0xbe4b1f22, 0xbcdc2467, 0x3dc593f5, 0x3d922eba, 
    0xbe010a89, 0x3d5e1cbe, 0x3ddd3afa, 0xbe372dec, 0x3d81b033, 0xbe3e72dc, 0xbca1eed8, 0xbd023e8f, 
    0x3d581d15, 0x3e21fd31, 0x3cf73c26, 0x3d7d2532, 0x3e036dd4, 0x3bca7b3e, 0xbe2dde45, 0xbe0c9aec, 
    0x3e4185f5, 0x3dd8a139, 0xbd42a0df, 0xbd0e93bd, 0x3d12cdfd, 0x3d1e756c, 0xbe0eea9c, 0x3df039ec, 
    0x3d702f48, 0x3e0eb5e5, 0xbe09ac95, 0xbd9bfe43, 0x3dae8a13, 0xbe38bc1c, 0xbded57bf, 0x3ddfc410, 
    0xbd62e72c, 0x3db155b9, 0x3dc8b8b6, 0xb9693b2d, 0xbe062da4, 0x3db3ee90, 0x3e288478, 0x3c004874, 
    0xbe1e1c7b, 0x3e5c30be, 0xffff89a2, 0x00000004, 0x00000080, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xffff8a2e, 0x00000004, 0x00003000, 
    0xbde02703, 0xbe070b0d, 0x3d7dd3a9, 0x3d62ded9, 0x3d5c2271, 0xbe420a6b, 0xbe3da943, 0x3e28670f, 
    0x3e0224ab, 0xbe1c8b2d, 0xbd5f0ca2, 0x3e24a5d9, 0xbd5d2758, 0xbdd60bca, 0xbb5e2b7d, 0xbcc71704, 
    0xbe7ff2da, 0xbe2dafde, 0x3d9f4aca, 0x3dafc5e1, 0x3cdffc3d, 0x3e2ff1dd, 0xbc65e98b, 0x3db90ed2, 
    0xbdecd7f8, 0xbdddbf4b, 0x3ce9c8fd, 0x3e0e318e, 0xbe1c0554, 0x3e239f5c, 0xb8888636, 0xbe18afa9, 
    0xbe1038e6, 0x3e361fdc, 0x3dd25509, 0xbe37ddae, 0x3d9d6f5f, 0xbe351e30, 0xbc9dd0db, 0x3de8b267, 
    0x3dc72cd1, 0x3da2b87b, 0x3dcf60b5, 0x3cb62c31, 0xbdc44167, 0x3e2ac99c, 0xbd38011f, 0x3e1e7260, 
    0x3d95e1b6, 0xbdea68c7, 0x3d22e61f, 0x3cf99c69, 0xb98cd538, 0xbd2fdcaf, 0xbc894f45, 0x3d27f5fe, 
    0xbd3643cc, 0x3dc07b3a, 0xbdaeaa33, 0xbc128aa9, 0xbca9a734, 0x3e6ecce8, 0x3e10e615, 0x3ca214c2, 
    0x3e1168a9, 0x3bfc1c48, 0x3dfbec16, 0x3de6eb03, 0x3e15199f, 0xbde22daf, 0xbd30a01b, 0x3e1becd0, 
    0x3e2bb2c4, 0xbc98934f, 0x3dace3b6, 0x3e0bf23f, 0xbe479a94, 0xbe02c7a3, 0xbe62760c, 0x3dd79d31, 
    0x3c4c267e, 0xbdbb7a2d, 0xbd86137e, 0x3d9165df, 0x3c836b6b, 0x3df2ad1a, 0x3da6ffde, 0xbd31403f, 
    0x3d19af91, 0x3e01ac65, 0x3e0baa1c, 0x3e0e15e1, 0xbcd8f576, 0xbdff212e, 0xbddc021f, 0x3e20bcd4, 
    0x3dcd6457, 0xbc64f214, 0xbb6d0148, 0xbd17224d, 0x3e451362, 0xbdf04121, 0xbdf0483a, 0x3d345eaa, 
    0xbc22c887, 0xbca2f28f, 0x3c34a610, 0x3e28feea, 0xbc3a168e, 0xbdd253d2, 0x3e1f63d0, 0x3e38ef4f, 
    0xbe42a3e5, 0x3bee0470, 0x3d80e671, 0xbcc62ad7, 0xbd789d35, 0x3d0dad0b, 0xbd67de0a, 0xbd9f407f, 
    0xbc9c1bae, 0x3deb7b15, 0xbe444d36, 0x3d984d36, 0xbd2aaa17, 0x3c80bce3, 0x3df2dab2, 0x3cea4041, 
    0x3d2cab23, 0x3d8bce69, 0xbe2040a1, 0x3dc16fb5, 0x3d1f30f7, 0x3d6d0e40, 0x3c00af2a, 0x3d053dff, 
    0x3da2ec8d, 0xbdd7c14a, 0xbe493aa0, 0x3b97d89a, 0xbd90b499, 0xbe1882a6, 0xbe2c0d3e, 0x3d2c89ff, 
    0xbd804715, 0x3d75474d, 0xbd969193, 0xbcdabdb4, 0xbbcb07e5, 0xbca2e495, 0xbe60700a, 0x3d455801, 
    0x3d9d741c, 0xbd793dbb, 0xbe48aba2, 0x3db81314, 0xbde8b202, 0x3e10b451, 0x3dbf5632, 0x3d6a1de4, 
    0x3db4416e, 0xbddfccb4, 0xbdd01ad0, 0xbe317a55, 0x3d217294, 0xbd7561d4, 0xbd1df984, 0xbe0a8246, 
    0xbdf2d7f3, 0x3e2159fb, 0x3df21f86, 0x3d99c315, 0xbd9d48ce, 0x3d3bf1c3, 0x3e1d5c18, 0x3dc85821, 
    0x3cb0f4d4, 0xbd890932, 0xbd97862d, 0x3c900035, 0x3e22692c, 0x3c9b064c, 0xbe0b229b, 0x3e4d3cf2, 
    0x3e233ecd, 0x3b82aa09, 0xbdd142f1, 0x3e10f1a9, 0xbd93f970, 0x3defaf27, 0xbb35b4e3, 0x3c51faa0, 
    0x3e11e13e, 0xbe142582, 0xbdb5e200, 0xbd6b2b61, 0xbdeadbd0, 0x3e102b42, 0x3cc46893, 0x3df6a6d0, 
    0xbe0e3de4, 0xb94091ee, 0xbcdd7c2c, 0x3beae44c, 0x3ce78654, 0x3cfe8c21, 0x3c8db60f, 0x3df55959, 
    0xbda6235e, 0xbd5c4322, 0x3d4d3d65, 0xbd6d9abe, 0xbe4c94cc, 0x3c1b7514, 0xbdd895c5, 0xbdde106a, 
    0x3c61ed99, 0x3e019b1a, 0x3d6ac2db, 0x3e0a628d, 0xbd96fc70, 0xbdb046d8, 0xbd88bd75, 0xbd3c5ebe, 
    0x3e218055, 0x3e08a7b2, 0xbd94db08, 0xbe2a74f2, 0x3de66018, 0xbdcbff1e, 0x3d103e00, 0x3e1efc80, 
    0x3da4ffbe, 0x3bd6a7e6, 0xbd7480d7, 0xbe130059, 0x3e37b33f, 0xbc4852bb, 0x3e2a5698, 0xbde82263, 
    0xbd543c17, 0xbe08ada0, 0x3d879b93, 0xbd844d33, 0xbdcf18d9, 0xbe54e884, 0xbe27030a, 0xbe26e589, 
    0x3d00a453, 0xbb81f033, 0x3dc9f526, 0x39e5d6d1, 0x3e019469, 0xbcad9598, 0xbc0ca5b0, 0x3dcfbef0, 
    0xbe545e64, 0xbe31f8be, 0xbd29ab79, 0xbd949a6a, 0xbd62588f, 0x3c0c3ef9, 0xbcb0276c, 0xbdad4546, 
    0x3da403c3, 0xbba4db69, 0x3d1058dc, 0xbda72beb, 0xbdc7bee1, 0x3ca7aca2, 0xbd7b9556, 0xbb3de9a6, 
    0x3e18a902, 0xbe211480, 0x3df4acaa, 0xbd9f4187, 0xbd43673e, 0xbd5ea353, 0xbe836560, 0x3d76b3a4, 
    0xbd9c9a6b, 0x3e4c2490, 0xbe112802, 0x3e252b4c, 0xbcabb0e2, 0x3de3df92, 0xbd8e1613, 0x3e2af588, 
    0xbdbe976e, 0x3e1d2896, 0xbe1273d0, 0x3cee199b, 0xbe0b8436, 0x3d7ec042, 0xbe0f9ac9, 0xbdf70f34, 
    0x3d8b1fc7, 0xbdee8ce5, 0xbd6bbb77, 0x3b1e3afb, 0x3e090901, 0xbe0356d2, 0x3d1449c4, 0x3d6560c0, 
    0xbe375c48, 0x3e1741e0, 0x3ddefc80, 0xbe287bd5, 0xbdefed48, 0xbc99b610, 0x3e097989, 0x3e11afb0, 
    0xbe000fce, 0xbe2e9c6c, 0x3e1a0ab5, 0x3a531afc, 0x3df02d66, 0xbda5d2c0, 0xbe753498, 0x3d9739ad, 
    0x3e13ca28, 0x3e0975e5, 0x3d418907, 0x3d30997a, 0xbc4eb9da, 0x3de75097, 0xbcd8c854, 0xbdbfcb17, 
    0x3d51eaaa, 0x3c399e63, 0xbe24f397, 0x3dbac5c3, 0xbd44dd97, 0x3da1f8ee, 0x3d197a3c, 0xbd57000c, 
    0x3db4f99f, 0xbbf34d26, 0xbe04b7d7, 0xbb60f4ca, 0x3df47bc5, 0x3d1fd7f0, 0xbdbf5799, 0xbd222eb9, 
    0x3d832b1c, 0xbdef5ea3, 0x3c16ebe7, 0x3dfb9ffb, 0x3cb2e9ec, 0xbd0f1f34, 0xbdda8c4e, 0xbaed060f, 
    0x3dfc1d4a, 0xbc8bd81a, 0x3a0a72b2, 0xbe1adf21, 0x3e030149, 0x3de8a196, 0xbe74b8a7, 0x3dbfcfb0, 
    0x3c409971, 0x3e48960b, 0x3d75fb40, 0xbe0c0774, 0x3dad0cef, 0x3dfa6825, 0xbc73af2b, 0x3a9a6278, 
    0xbd97be82, 0xbdfc362f, 0xbd505d53, 0xbe109f57, 0xbc9dcca5, 0xbe13e75b, 0x3d989601, 0xbda3330a, 
    0x3dd2f189, 0x3e414091, 0x3cdab642, 0x3d9e4a40, 0x3c2643f7, 0xbe352540, 0x3df60dd4, 0xbde66c66, 
    0x3d68ecad, 0x3e233def, 0xbcce566f, 0xbe3971ab, 0x3e1525a7, 0xbd5a1ba0, 0xbe0de778, 0xbe467f77, 
    0xbe18e49c, 0x3d9c59f1, 0xbdd2ff52, 0xbd33ffd7, 0xbe2b4245, 0xbe25883b, 0x3db94b3f, 0x3d81147d, 
    0xbd64eee6, 0x3db6a477, 0x3d7ddec8, 0x3e11f81d, 0xbdce6880, 0x3daf9640, 0x3e3f605a, 0x3e43c6cf, 
    0xbdc5fda3, 0xbe44d26c, 0xbd8c7ce5, 0xbc20df7c, 0xbd9fb7a5, 0x3e2a7d2e, 0xbe225022, 0x3e0341f1, 
    0xbd8f400c, 0x3e157e7f, 0xbd7730be, 0x3c725406, 0xbdba5eb8, 0x3d121e18, 0x3ceecae1, 0x3e271372, 
    0x3e1000e6, 0xbe277c5f, 0xbbdfd9da, 0x3d0cd6e2, 0x3ddbe274, 0x3c71f39f, 0xbe17436d, 0x3e1be629, 
    0x3dd5b05d, 0x3c9d4f91, 0x3dbf33ad, 0x3d094ab4, 0x3b17b049, 0x3e1d4df6, 0xbd06aff4, 0x3e3d4a86, 
    0xbd98613e, 0xbcbe486a, 0x3d6cde48, 0x3e06237f, 0x3d048416, 0x3da70ef2, 0x3e088040, 0x3da5545f, 
    0x3d25dd05, 0xbd59f966, 0xbb36fb4f, 0x3d81d9cd, 0xbd3d140f, 0xbdba6b57, 0x3dd080aa, 0xbdbb0dc2, 
    0x3cd116b2, 0xbcb4ce32, 0xbe108e65, 0x3e38fa27, 0xbe167586, 0x3cef0f4c, 0xbdc52988, 0x3db8be14, 
    0x3e01c009, 0xbcde819a, 0xbbcc6211, 0x3c08b6eb, 0x3d30db8a, 0x3d710910, 0xbdcfed00, 0xbda18095, 
    0x3cf04751, 0xbced12eb, 0xbd1d90ee, 0x3b7cdc7a, 0x3c6b79e1, 0x3e394a2e, 0x3dc4bc87, 0xbd3868cb, 
    0xbdbf545b, 0xbd9556fe, 0xbd20b96f, 0xbc87f375, 0xbd93d7b8, 0x3c094f81, 0x3da80e5e, 0xbdc9649c, 
    0xbc77c0c4, 0x3d9b7afc, 0x3c0261f4, 0x3ddbdb5a, 0xbcbdd92d, 0xbd406548, 0x3b9bfc56, 0xbd71b617, 
    0x3d576519, 0x3dd8da38, 0xbc9058f1, 0x3dad993c, 0x3d9ac6df, 0x3d9f56e9, 0xbd1a0804, 0xbd1c1c89, 
    0x3d8e75db, 0x3dbfffcb, 0x3d821a13, 0x3db160a1, 0x3e0cea78, 0xbdb827d7, 0xbe318dc2, 0xbd775975, 
    0x3d4e101b, 0x3cbf307b, 0x3cdf499e, 0xbdbd6738, 0x3c92ec8a, 0x3ceb76e4, 0x3d7d9ce0, 0x3d032fe9, 
    0xbe166344, 0xbdafef06, 0x3e12ae49, 0x3ded6bcf, 0xbaa8a9d5, 0x3df3e678, 0x3e0fc0b5, 0x3ca135dc, 
    0x3ccfa27b, 0x3d27c2ab, 0xbb8f3520, 0xbc6a3c70, 0x3da0ece9, 0xbe298ef3, 0x3df36f76, 0x3e0a641e, 
    0x3d23999f, 0xbd56e639, 0x3a0d4bc4, 0xbdc5c6e8, 0xbd732ec5, 0x3e05cf6b, 0x3d8fe2bb, 0xbe1fe6c4, 
    0xbd433b12, 0x3c979b9b, 0x3dba023a, 0xbcab417e, 0x3e002cc9, 0xbd016aaa, 0x3ce7fa0d, 0x3da31878, 
    0xbdbc4b6a, 0xbdbdcedc, 0x3d98d39f, 0xbd9ec54f, 0x3e499ad4, 0x3c9a1c35, 0x3df591ec, 0x3de0161f, 
    0xbdb85240, 0xbdf152f9, 0x3e2f10fe, 0xbd568184, 0xbdfd907d, 0xbdb9839d, 0x3e1bb8af, 0x3e07e7e6, 
    0xbc408463, 0x3df06729, 0xbcf6847c, 0x3dfe08fd, 0x3d58f3fe, 0xbe04b38a, 0x3e112ca2, 0x3d71fa1d, 
    0xbdf3b332, 0x3e556f41, 0x3ddfea31, 0xbdb26e45, 0xbd7cf67e, 0xbd55953f, 0x3e404045, 0xbaf39fad, 
    0xbdb85c76, 0x3d3d314c, 0xbbf7c9c7, 0xbdb1ea65, 0xbc42a381, 0x3c99386c, 0x3e42e560, 0x3e02f5ae, 
    0xbe2218f6, 0x3e07e924, 0x3e2c66ce, 0x3dab398b, 0xbcb90be3, 0xbdf73f48, 0xbe2b3283, 0x3e2e8d77, 
    0xbe309cdc, 0x3dac1922, 0xbd08f30d, 0x3d89cb10, 0xbbc8a01b, 0xbdf0451a, 0xbe0ee87e, 0x3d9129d8, 
    0x3d911f86, 0xbda937fb, 0x3e0f89b7, 0x3d7b2ad6, 0xbb8c6811, 0x3e1caca4, 0xbdfc4b17, 0x3d595b86, 
    0x3de2f502, 0x3e0ba0a0, 0x3d979681, 0xbdbe8342, 0x3d95430c, 0x3d30c607, 0xbdc92f43, 0xbd958442, 
    0x3d5a5b97, 0xbd1687ed, 0xbc7d2115, 0x3e07768b, 0xbe0e6ace, 0xbd1bdad2, 0x3d622785, 0x3cd41a01, 
    0x3e1e3d86, 0xbd6a5326, 0x3e46e915, 0xbe103268, 0xbe0e4fd2, 0xbc61ff90, 0xbbd4bce8, 0x3dff3ec3, 
    0xbe04cdd3, 0xbe181a01, 0x3d4e213f, 0xbc94e4ee, 0xbdb8f783, 0x3d59119d, 0x3e17aea5, 0xbe30abe1, 
    0xbd708d05, 0x3dca12ee, 0xbe106e92, 0x3d563fcc, 0xbe4058b8, 0x3d483de5, 0xbd8e328a, 0x3dc58827, 
    0xbe489def, 0x3dc70f3e, 0xbe103877, 0x3e0c9199, 0xbe16549d, 0x3bbae4be, 0x3c82d458, 0xbe0416ab, 
    0xbdb7a920, 0x3af56ecc, 0xbdfc6b59, 0xbdba034e, 0xbda8c3e4, 0xbe0b381f, 0xbdd3c8d7, 0xbcc01c04, 
    0xbe1ac396, 0xbe1ee31f, 0x3dd685ce, 0xbb224034, 0x3d913380, 0xbe2067cd, 0xbd3a846a, 0x3dd6a970, 
    0xbdf1c745, 0x3d9317a5, 0x3cdb5472, 0x3d14ef0d, 0x3d950f4a, 0xbdb09594, 0x3e1d5ba2, 0xbdfa65ac, 
    0x3db191c6, 0x3dd34eb6, 0xbdb50588, 0xbe1777e3, 0xbd7939a7, 0x3e094707, 0xbdd34038, 0xbe3a9d83, 
    0xbe210e40, 0xbe2f637d, 0xbce0683e, 0xbe1d5278, 0xbe0062c0, 0x3deaf86a, 0x3d246d70, 0x3d6fe5d4, 
    0xbcd46ad9, 0x3e04e427, 0xbe28e3a8, 0x37da52e8, 0x3e3ba1fa, 0x3e22d3c6, 0xbe301923, 0xbe30a875, 
    0x3dfca861, 0x3c8aee40, 0xbe1e1726, 0x3da0d414, 0xbdddddb3, 0x3e096c92, 0xbdfedb99, 0x3e299427, 
    0xbe2c19d5, 0x3e018948, 0xbd99f5f0, 0xbd8a8d10, 0xbe3f7419, 0xbe08651d, 0x3e1921b3, 0xbe462b99, 
    0x3e2ba9f0, 0x3d841d6c, 0xbd0b548d, 0xbc96d2c9, 0xb9d737d0, 0xbdd592de, 0x3e0f3cb6, 0x3e0c5098, 
    0x3e20f8bd, 0x3cead96d, 0xbd83a9c6, 0x3d5f9201, 0xbb3ac68b, 0xbe1e21ff, 0x3d8b298e, 0x3e077f68, 
    0xbe494503, 0xbdec3a5c, 0xbde88422, 0xbda94490, 0x3caf4c80, 0x3d03cb12, 0xbc7a4d0a, 0x3de97785, 
    0xbd7ba77a, 0xbcfbf69a, 0x3c1c3d4b, 0x3dee6de1, 0xbcd17e11, 0x3e284adb, 0xbe2b851a, 0x3e00e789, 
    0x3ce73633, 0xbe3dc116, 0x3e07af02, 0x3e015e8a, 0x3dad8800, 0xbe253002, 0x3dfe8495, 0xbc1b254c, 
    0x3cd7ecc7, 0x3d69694d, 0xbc9521ee, 0x3cad94fe, 0xbe051b83, 0xbd8495b7, 0xbdd3509c, 0xbe088199, 
    0xbe4edf2c, 0xbbc8c001, 0xbd71416d, 0xbe0da4d1, 0xbda62ae8, 0xbe33d7cf, 0x3d240c84, 0xbe087575, 
    0x3d74be99, 0x3dc0b8d5, 0xbdd6235d, 0xbcaad047, 0xbe150ac9, 0x3da6ce9d, 0x3e024563, 0xbe186060, 
    0xbda2d4c4, 0xbd071650, 0xbde3600d, 0x3e287d05, 0xbcefdd3e, 0xbe3a721c, 0x3da7b45a, 0x3dc0598b, 
    0xbe2ce0bb, 0x3d637e5f, 0x3e13fddb, 0xbd797de3, 0xbcb73965, 0x3dd62715, 0x3e13f86f, 0x3db03b14, 
    0xbded53a2, 0xbe1ab9a3, 0x3d38e70e, 0xbd0114db, 0x3d6c6b9b, 0xbc67af70, 0x3da7d2cf, 0xbe29a2b7, 
    0xbd2d4e2e, 0xbd94272c, 0xbc94731c, 0xbd472966, 0x3db51523, 0x3decbe07, 0x3ca17c52, 0x3dc0cbca, 
    0xbdd06f1d, 0xbc65f137, 0xbc904d15, 0x3e2dd0b0, 0x3d24b7ee, 0xbe454650, 0xbddf4288, 0xbc796f32, 
    0xbdbb91c9, 0x3e16aa3d, 0xbc63cc1d, 0xbdf81024, 0x3d54214a, 0x3dfd2ec5, 0x3dada869, 0x3dece62d, 
    0xbbfebfba, 0xbe30452b, 0xbc00bf3b, 0xbd263f91, 0xbdf01749, 0xbd923caf, 0xbdd1de06, 0x3ca54654, 
    0xbe1013fc, 0xbd998dc5, 0xbdfd4b60, 0xbe0ab3ad, 0x3daf3806, 0x3e29363c, 0x3b65bc99, 0x3bd11cf4, 
    0x3d89c212, 0xbd3809cc, 0x3def0b9e, 0x3cf7110b, 0x3d180dcd, 0xbc867239, 0x3d88db0a, 0x3e084594, 
    0x3d270867, 0xbd1bef1f, 0x3e1048e3, 0xbd3f3410, 0x3de956fd, 0x3d69e2b3, 0x3d91098a, 0x3d5ae0a5, 
    0xbdb988c2, 0xbdfc85f6, 0x3e244352, 0x3df1ca4d, 0xbbac712f, 0x3ddf4f53, 0xbdd49fe5, 0x3c9443fd, 
    0x3daf5b11, 0x3dbad77a, 0x3db82d42, 0x3db278e7, 0xbe133abe, 0xbde8d0a7, 0xbcceff7a, 0xbe2fc71b, 
    0x3d6679cd, 0xbd1bc6ab, 0xbe0311a2, 0x3dccaa1b, 0x3d936bc4, 0x3d94cc9e, 0xbdd46cc8, 0xbd81b251, 
    0xbe0ad5b6, 0xbdc02a05, 0x3e44ad21, 0xbdab02d4, 0xbd97edbc, 0xbe01cfe5, 0xbe35c8e3, 0x3ce520c2, 
    0x3dd054ca, 0x3db7cf3f, 0x3aa6b1d8, 0x3e60581f, 0xbe0b038d, 0x3e21c9fb, 0x3dfd290d, 0x3cb1b1a3, 
    0xbcc35041, 0xbddbc20d, 0xbba29b7e, 0xbca46c54, 0x3e308073, 0x3d02675b, 0xbc87c401, 0xbe2052e7, 
    0xbe09c300, 0x3d1c012d, 0xbe1eee0d, 0x3d65f393, 0x3da554a1, 0x3dc56220, 0x3e14ac3e, 0xbddceb2f, 
    0x3e07fd7e, 0x3ddb2ec2, 0x3e43c0a8, 0xbbcd5fb1, 0x3c6c0501, 0xbb5e4614, 0xbd9df1c6, 0x3e5972b8, 
    0xbd033a62, 0x3d7940aa, 0xbe14b3d0, 0xbd80dc40, 0xbe0e5a69, 0xbccd5903, 0xbd088082, 0xbe22e872, 
    0xbe2ec5b5, 0xbdb8cc2f, 0x3e118902, 0xbcc1ed4a, 0xbe0bab03, 0xbe0f8a29, 0x3e6a4253, 0xbd489aeb, 
    0x3d8ccc1a, 0xbd84bdc3, 0x3d978e7b, 0x3db5c6d9, 0x3e20b120, 0xbde31ed4, 0x3d29e3f9, 0x3de98d9c, 
    0xbc77a253, 0xbe047c6e, 0x3e1e08da, 0x3cbe35e2, 0x3e35ac7d, 0xbe296180, 0x3d3ab002, 0xbe0f5fe6, 
    0x3e2c85fc, 0x3b24a52a, 0x3d8c9613, 0xbdaddad8, 0xbcacba60, 0xbe062177, 0xbd8cab6a, 0x3d0fe6ea, 
    0xbe30dc56, 0x3bbaedca, 0x3d4b29ee, 0xbe281002, 0x3c848b9c, 0x3de2b4e7, 0x3dd79c1f, 0xbde68bf1, 
    0xbdcdb1e4, 0xbe213eab, 0x3dcdaea2, 0x3e04668c, 0xbdf96815, 0xbb76fc45, 0xbd20df41, 0x3d94aa56, 
    0x3e07fa79, 0xbcffebf6, 0x3e220099, 0xbe165fb3, 0xbe0e2e0c, 0xbe00962a, 0xbe20718f, 0xbc27304b, 
    0xbdbf499d, 0x3c6542fb, 0xbda6c5ff, 0x3bb2af2d, 0x3ded6721, 0xbcd6433d, 0x3dae4b4d, 0xbbfdfc53, 
    0x3d333931, 0xbc83ba31, 0x3ddc1506, 0xbdd6bb91, 0xbe087f96, 0x3cbf7d38, 0x3d61d8ea, 0x3cba9bbc, 
    0xbcb3971a, 0xbc18b898, 0x3cbcf796, 0x3e33c6cb, 0xbdf9ce18, 0x3dfe7154, 0xbcc20f16, 0x3e06a945, 
    0x3e4e8a1d, 0xbd4dd27b, 0x3c932a4d, 0xbdc329f8, 0xbdec36f4, 0x3ceec058, 0x3e15b353, 0x3dd4dc1d, 
    0x3e304735, 0x3daa4929, 0x3b47286b, 0x3e232458, 0x3d1d0686, 0x3dd31471, 0xbd8e0eaa, 0x3e01c444, 
    0xbe227650, 0xbd9cef4c, 0xbd33fc6e, 0xbe4c284c, 0x3d13f4a5, 0x3e75fd14, 0x3e37fdf6, 0x3de736c4, 
    0xbdc9148c, 0xbd8abbe3, 0xbdfb3e31, 0xbd0870e4, 0x3d0f500a, 0x3e4852cd, 0x3e65c9c7, 0x3e1a2863, 
    0xbdeacfcf, 0x3c8a93f6, 0x3de83839, 0x3bf054c7, 0x3de8dfb2, 0x3ce9c45c, 0x3bac36ad, 0x3e0c68a3, 
    0xbdf6af46, 0xb9aeb19c, 0x3d95b121, 0xbd733a23, 0xbd61fe89, 0xbdf8c683, 0x3dc90b48, 0xbe544f5f, 
    0x3e083f5e, 0x3d0192a4, 0xbcfea118, 0xbae6bd0a, 0x3d83135c, 0xbdfeb689, 0x3e25dbff, 0xbe0fac43, 
    0x3cd2edbb, 0x3ce47133, 0x3dd98cb5, 0xbdd5e6fb, 0xbd0927ef, 0xbd8e1f41, 0x3e24d551, 0xbcfc30fa, 
    0x3c178fe1, 0x3d974a5d, 0xbcb8dc62, 0x3dbe4200, 0x3e123ca4, 0x3e23af6b, 0x3ab386ef, 0xbd48c040, 
    0x3cbfca74, 0xbe15e520, 0x3e112da8, 0x3e36e571, 0xbd1ccde3, 0x3e39e83f, 0xbe71b1f2, 0xbbf81ba7, 
    0xbd4ef9e3, 0xbb9b407f, 0x3c2bf4d2, 0xbe06733e, 0x3d604f84, 0xbc85a343, 0x3d25d70b, 0x3d821458, 
    0xbde55d69, 0xbe5b91d9, 0x3e24db72, 0x3d24dc13, 0x3dbbca53, 0xbe36f68b, 0x3e0de8ea, 0xbc8c1936, 
    0x3cb8dc89, 0x3e1344f1, 0x3dbee948, 0x3d58dc89, 0x3e3b6814, 0xbd9e98f6, 0xbdf16908, 0x3e0706c3, 
    0x3ce9ba8a, 0x3d08e214, 0x3dc4a131, 0x3d574602, 0x3bde20fe, 0x3e026401, 0x3de3b4d9, 0xbe08b9a2, 
    0xbd1cda5e, 0xbde27603, 0xbe1e5cf5, 0xbc290ed5, 0xbe0fb144, 0x3d477cd6, 0x3deeeb3b, 0xbcba54ba, 
    0xbd554c9a, 0xbdf192a7, 0x3e34ea05, 0x3d382a6d, 0xbd45df72, 0xbd88ef58, 0x3ca9dfbd, 0x3d8caa60, 
    0xbcb40930, 0xbe59fa43, 0x3d9cee68, 0xbda59d59, 0xbcf37816, 0xbdf514bb, 0xbe20d3e2, 0xbdf043c2, 
    0x3e2cdb49, 0x3d985bcd, 0xbd7efafd, 0x3dfde9ba, 0x3ba1d204, 0xbdd7ea99, 0xbdc74281, 0xbdab5a55, 
    0x3e24673f, 0x3e132bcc, 0x3d5403c1, 0x3e1a1946, 0xbc64b8cc, 0x3c2062e9, 0xbe2fa3e6, 0x3d1e727b, 
    0x3e163470, 0xbae37a11, 0xbdbf6784, 0x3e2143f3, 0x3c28c863, 0x3e0be5b9, 0xbd6ba506, 0xbd52bb4c, 
    0xbe11b53b, 0x3e0adf8c, 0x3e1b034e, 0x3e2ca5b7, 0xbd84a4e6, 0xbd039f2e, 0xbc6c056e, 0xbda6f472, 
    0x3ca6e96a, 0x3d2d03a7, 0xbd635abf, 0x3840a7ff, 0x3dda93e3, 0x3dd4d481, 0xbe0f6055, 0xbe038d78, 
    0xbdb94d3f, 0xbdc855f8, 0xbd963d84, 0xbda6ac23, 0x3dd98c42, 0x3cb264e2, 0xbd929be5, 0x3e1c0349, 
    0xbd9a1310, 0x3ddfe743, 0xbe4454b4, 0x3cbbedd8, 0xbd9ff159, 0x3df91c89, 0xbd87c7d7, 0x3d964197, 
    0xbcde7696, 0xbe26c710, 0xbd6ded51, 0x3df5f791, 0x3d606246, 0x3db777a2, 0xb9929a78, 0xbe07760c, 
    0x3dd6b1c1, 0x3c9efebd, 0xbd0eb19c, 0x3da33c07, 0x3d850a18, 0x3e327b6f, 0xbdf96cf3, 0xbda7bbe7, 
    0xbe3d84c5, 0xbe317bf7, 0xbd7f738b, 0x3e2f16a8, 0x3dd5ecf5, 0x3d019d40, 0x3e09f252, 0x3dd15109, 
    0x3d2d15b2, 0xbd20a4c1, 0x3d542384, 0xbc30b3ed, 0xbe11e77d, 0x3dba86b7, 0x3c9d1d24, 0x3de68bed, 
    0x3c8992ca, 0xbcef7d8a, 0xbe09637a, 0x3e0bc6f8, 0xbd3a759f, 0x3d9905d4, 0xbe36e339, 0xbe4521ae, 
    0x3d9271bf, 0x3d942757, 0xbd1eefb2, 0x3dcd67bb, 0x3cfaa2b0, 0xbd923dd6, 0x3e06471d, 0xbdbeb9d5, 
    0x3c340bc3, 0x3d51fcc5, 0x3e0d889b, 0xbd663153, 0xbcbbabb4, 0xbce9b8f7, 0xbe208dea, 0x3d5cb7d4, 
    0x39ebbfda, 0x3b7286c2, 0x3d8ad000, 0x3d19bce6, 0x3d937d81, 0x3e02a336, 0x3d929f1b, 0xbd9abc40, 
    0x3c497975, 0x3dfda13e, 0xbcd7661c, 0xbda65d90, 0xbe307aef, 0xbcca7b58, 0xbd0e1bf0, 0xbe31b520, 
    0x3c93ae77, 0x3d0c5e0e, 0xbdabc4fb, 0x3b59d174, 0xbd565cfe, 0x3c9bbf85, 0x3d83d5d2, 0xbe3357c9, 
    0xbd8c0e38, 0xbc66b706, 0x3dcdd535, 0x3d3bbd48, 0x3cb408a0, 0x3d9c3d2a, 0xbd8ffbc3, 0x3d437c19, 
    0xbd3e3e77, 0x3c1a3cc4, 0x3e1b9d43, 0x3dbfd320, 0x3e41e290, 0x3dacf9e0, 0xbe2c03b8, 0xbb83aa99, 
    0xbe2160a3, 0x3dedc79e, 0xbd52ac6e, 0xbdec6cc0, 0xbe49b807, 0xbd1dd6bc, 0x3da0d5cf, 0xbcd91593, 
    0xbc43f37b, 0xbe1bd718, 0xbe009603, 0x3da66414, 0x3dc514d8, 0xbe341b17, 0x3d7b50fc, 0xbca51059, 
    0x3d886ec0, 0xbdff1450, 0x3e26d31c, 0x3b5cf99b, 0xbcf05676, 0x3e2f0991, 0x3e15da8b, 0xbe5b2ef4, 
    0xbdb930b0, 0x3cee6b76, 0x3b39bd39, 0xbd609ac2, 0xbe0ac7f9, 0x3d9dc78f, 0xbd12fff9, 0xbbc895d0, 
    0xbcff6c8d, 0x3de33f78, 0xbd150aa6, 0xbdc901f7, 0xbdd1b206, 0x3c108b04, 0x3d0d653f, 0x3c081ec4, 
    0xbe3f1063, 0xbca5debe, 0xbdd00b03, 0xbe16d222, 0x3e1dc958, 0xbd307f22, 0xbd648bde, 0xbda7a3b8, 
    0x3b5d2b6f, 0x3d55d0e3, 0x3db9e481, 0xbd9f62d2, 0xbd73e901, 0x3dc04b4a, 0xbd87c654, 0x3e1a6ae4, 
    0x3d296489, 0xbe0f3105, 0xbc89edb9, 0x3e087a39, 0x3dac50b1, 0x3d5b0105, 0xbe4daf5d, 0x3e0bdbbc, 
    0x3e15cc39, 0xbd4f52a0, 0xbdd2b6ef, 0xbd843be2, 0xbddc6d10, 0x3e2298f1, 0x3d2db90b, 0xbce3e09d, 
    0xbdc21b11, 0x3cd55bd5, 0x3e184a08, 0xbc4b959d, 0xbc841031, 0x3ccbb366, 0x3d931da2, 0x3e3112be, 
    0xbe27029f, 0xbd88044a, 0xbd522a77, 0xbc9e150a, 0xbdb54576, 0xbc61caa9, 0xbdfd4305, 0xbd0600fd, 
    0x3e18fa96, 0xbd21b194, 0xbe3ef260, 0x3d9810f2, 0xbe0840e3, 0xbd1c969c, 0x3e194baa, 0x3dd5a3ad, 
    0x3e10d8cf, 0x3df7407b, 0x3e06a6a7, 0xbe2a27c5, 0x3e1fb9bb, 0x3da7cb8f, 0x3c91ed99, 0xbd80aae0, 
    0x3e257852, 0x3e32ae34, 0xbdd617d3, 0x3de6628f, 0x3da96cc9, 0xbdbc8780, 0xbdf583ca, 0x3dbc3304, 
    0xbd1f92d0, 0x3e12f79d, 0xbd3994ea, 0xbdf94a10, 0x3d2e7ffe, 0x3a013839, 0xbccab7c1, 0xbe0e89ed, 
    0x3e13ad64, 0x3bb5af91, 0x3d9df907, 0xbdea00b2, 0x3e112c21, 0xbdaf1f79, 0x3d93f8bf, 0x3d05c4b4, 
    0x3db4fe38, 0xbda2509e, 0xbcc6a5f3, 0xbe3c97b0, 0xbe131a31, 0xbdd93b49, 0xbdf827a3, 0x3ce3c523, 
    0xbd20f785, 0xbc9d68a5, 0xbd972833, 0xbe288675, 0x3d46f5ad, 0x3d53f6ea, 0x3c889691, 0x3e180676, 
    0x3d8bd9db, 0x3d20d3b6, 0xbe2015ac, 0x3c8f6c1e, 0x3e3ac6c5, 0xbc5b41d6, 0xbccecbb0, 0xbe25dec1, 
    0xbe270320, 0x3d71b437, 0x3cc0efa4, 0xbdcb2c75, 0x3da42ec2, 0xbe3b1b82, 0xbd5a5dcb, 0xbdbbf4ab, 
    0x3def2971, 0x3e15ce94, 0x3d9a0f97, 0xbd598a34, 0xbe2b7574, 0xbde3067e, 0x3db6b83f, 0xbcfc0666, 
    0x3d2b0189, 0x3d013595, 0x3e07605c, 0x3dcb2a1d, 0xbc221e89, 0x3beaefa3, 0xbdfda4fa, 0xbc1f2428, 
    0x3d874480, 0x3d0d2561, 0x3da6d35f, 0x3a8bfcdd, 0x3d9bc7bd, 0x3da525db, 0xbd2fcef6, 0xbcbc378b, 
    0xbe2ab6db, 0xbcda372e, 0x3e3fd58d, 0x3e37da59, 0xbdaf9783, 0x3c8b3cb8, 0xbdd06757, 0xbd93d0ef, 
    0xbde992a7, 0x3c990271, 0x3ce35a90, 0xbe0e8654, 0xbe265146, 0x3e0129e7, 0x3e082c5a, 0x3de1962b, 
    0x3dda8a4c, 0x3dd71056, 0xbd55fc79, 0xbdd6caf8, 0xbe0e881c, 0xbdf5a217, 0xbcfbac1e, 0x3d87acf6, 
    0x3e3f1dfc, 0x3c045fe9, 0x3d062fad, 0x3d5c9e56, 0x3d025a2b, 0xbda071fe, 0xbe06fa26, 0xbe24f457, 
    0x3d8a92e2, 0x3c1f9d28, 0x3dcbc2b3, 0xbdbeadc6, 0x3d666aad, 0x3e0ef6bb, 0x3d455542, 0xbd4f4a73, 
    0x3dd5450e, 0xbd84b20a, 0xbd08864c, 0xbde18256, 0xbdbd43d5, 0x3da0473a, 0xbd80957c, 0xbdeb7760, 
    0xbbdc9459, 0xbe3aa5e6, 0xbe255740, 0xbaaa0b15, 0xbdfcdd9d, 0xbb85c83b, 0xbe0d280e, 0xbe1b19fe, 
    0xbd9bcc77, 0x3e1f7f82, 0xbd7326bb, 0xbdf20e91, 0xbdda4cd3, 0x3dbf5560, 0xbe1b66ef, 0xbe149ef6, 
    0xbe2fb6e3, 0xbde406a9, 0x3e31429d, 0xbe2e655e, 0x3da079ad, 0xbcf4125c, 0xbca763bc, 0xbd91fdc6, 
    0xbd216b19, 0xbd216691, 0x3d944876, 0x3e17ff97, 0x3d0507cc, 0x3bb40d37, 0x3de93fdc, 0xbda2768a, 
    0xbd1d5c15, 0xbd7c77a0, 0xbe23247e, 0x3de0422c, 0xbd095d84, 0x3e2c18c2, 0xbe059e46, 0xbde1340e, 
    0xbbdb1eb1, 0x3d548be2, 0xbdccdde3, 0x3dce97d3, 0xbd159b0a, 0xbde85944, 0x3e1b5a84, 0xbe155988, 
    0x3c34fc5d, 0x3e5e4ced, 0x3df4efb9, 0xbe1c3961, 0x3e44a3ba, 0x3e174d3b, 0x3dcc55f9, 0xbdafe40e, 
    0xbe1b28b1, 0x3dedf5ed, 0x3dc2a75a, 0x3dc2b806, 0xbcd1f0e0, 0xbe3db427, 0x3df4641c, 0x3d3d0f83, 
    0x3e0b652d, 0x3ddd3cc3, 0xbdda5f8e, 0x3ca98fb5, 0x3cd19d68, 0x3bc2c74d, 0xbe5bf4bd, 0xbe32ca17, 
    0xbe21ebe6, 0xbca943bd, 0x3dd77b21, 0xbdb3144d, 0x3dabe1d6, 0xbd028d85, 0xbe0cc873, 0xbdb5c684, 
    0x3d4a41a2, 0x3dcff750, 0xbc54c5c7, 0xbdafcf42, 0x3e0e8ca5, 0xbdce9611, 0xbe3e8e4a, 0x3d5ccdd3, 
    0xbd92a815, 0xbd48dde1, 0xbda83fa3, 0x3d5f103a, 0x3d1c2209, 0xbe00409b, 0xbd352e9a, 0x3c83033f, 
    0xbe48ce45, 0x3e1a58c5, 0x3de26dbe, 0x3da51a40, 0x3d648627, 0x3d7e835f, 0x3e2e9b81, 0x3dc7a93b, 
    0x3dbe2ed3, 0x3dcae76c, 0xbda08081, 0x3cb675ba, 0x3da3b364, 0x3e2143c7, 0xbe16c0fd, 0xbdb093bc, 
    0x3ddf5c58, 0x3e090be6, 0xbdacf5e5, 0xbd1594a9, 0x3d7b1faa, 0xbdb5e7e4, 0xbb06fe1f, 0xbde6c083, 
    0xbe45304f, 0x3aa3b090, 0xbda50dfe, 0xbd02d288, 0x3c617bb9, 0xbca7be07, 0x3e183a12, 0x3daff2f1, 
    0xbd6273ca, 0x3d6680cc, 0x3dcd6f31, 0xbb87b481, 0xbe09560a, 0x3a6839d2, 0x3daefb27, 0xbcbedd95, 
    0x3b753602, 0x3db22ae1, 0xbc63b81e, 0x3cbed10a, 0x3e4bf680, 0x3de4fb01, 0xbd4ec69b, 0x3d5c5d2b, 
    0xbe2fc03d, 0xbd5d1b93, 0xbd787ab2, 0xbe33eea8, 0x3df1d563, 0xbd019c1f, 0x3b6c3b0e, 0x3dec6d47, 
    0xbdcf2be7, 0x3da19a68, 0xbe1070eb, 0xbde09694, 0x3e0a922d, 0xbdd1e98a, 0x3bb99a41, 0xbdca4ecf, 
    0xbdf31515, 0xbdf75043, 0xbdb07574, 0xbe23ef0c, 0x3de09884, 0x3cee6ee6, 0x3ced20eb, 0xbdc32c94, 
    0x3c363610, 0x3da04e59, 0x3d4bc419, 0xbe17786b, 0x3ddf82e4, 0xbe194a15, 0xbe5a1a3d, 0x3e09fe05, 
    0xbcc9281b, 0x3c88004b, 0x3d190192, 0x3e103ac7, 0x3dd86593, 0x3c8507c2, 0xbdfefd17, 0x3de95eee, 
    0x3cb77dbd, 0xbdd9c01b, 0x3de37fcc, 0x3d8a2f56, 0xbc0459ec, 0xbd9292d0, 0xbdfd4c2e, 0xbdc3c92b, 
    0x3bb31667, 0x3c8b1c04, 0x3cd4b32c, 0xbe283310, 0xbd3dfb53, 0x3d71ebc5, 0x3c0f680f, 0x3e315a7d, 
    0x3cecf542, 0x3e374d85, 0xbd7d586a, 0xbdaa4173, 0x3c915d5a, 0xbdf20a87, 0xbe216db2, 0x3da8787a, 
    0x3e1a67cb, 0x3dd14fcf, 0x3d0734ee, 0xbdf61a40, 0x3d084c7a, 0x3c0c184a, 0x3e1de813, 0x3d5798c2, 
    0xbd8cf76d, 0x3dfda93d, 0x3c4f2e82, 0x3d7ba499, 0x3db01f1c, 0x3de14239, 0x3e4073d3, 0x3d17aa6d, 
    0xbe0df521, 0x3d8c73dd, 0xbe3f55ba, 0xbe2abb0a, 0x3cad1529, 0xbe014a87, 0xbe07432b, 0x3d6ca480, 
    0x3db4acb2, 0xbe286e62, 0x3c0aacf9, 0xbc190cb0, 0x3db5e666, 0xbe141b05, 0xbc9d5f1c, 0x3d87c648, 
    0x3dcb69f0, 0xbd71a1ec, 0x3d5a6699, 0x3d3729b4, 0x3dec49d4, 0xbd4ab11d, 0xbd91bbfa, 0x3d65e1a0, 
    0x3dcf5b50, 0xbe00c7a5, 0xbd537a7f, 0x3d225eda, 0x3e09d176, 0xbe26bab8, 0xbd0884fa, 0x3d6064a6, 
    0xbd1c5fb6, 0xbde1d4f0, 0xbbd88d58, 0xbd98503f, 0xbc85871d, 0x3e1438e2, 0x3e074a52, 0x3ad52121, 
    0x3a740bb4, 0xbca94fff, 0x3e22e163, 0x3d19a80d, 0xbbec2071, 0xbe0488c9, 0x3d6a091e, 0xbdbf775a, 
    0xbde92e91, 0x3d9ef5dd, 0x3caa6079, 0xbd3ebdbc, 0xbd66e160, 0x3da53d42, 0xbd23182d, 0x3e3e4096, 
    0xbe058d06, 0xbdc5f272, 0xbe3193ce, 0x3d4122ef, 0x3d4e914b, 0xbc46dd9e, 0x3e3a06b8, 0x3e306a9f, 
    0xbe04b0cd, 0xbc6b1765, 0xbd57cd62, 0x3e10110e, 0x3ded54ed, 0x3e30eec5, 0xbc8a56c6, 0x3d0b4509, 
    0xbd437967, 0xbd932378, 0xbda34a6a, 0x3c9f6d68, 0x3e36aca3, 0xbe4e97f6, 0xbd1c60ce, 0x3da8dc1e, 
    0x3d2c6da2, 0x3df5c37d, 0xbc349692, 0xbe075bdb, 0x3d6527b3, 0xbe716fc6, 0xbde392cd, 0xbe3e9d95, 
    0xbd537542, 0x3d23e7c8, 0xbe29a3ae, 0xbcefdbc1, 0xbd3a35de, 0x3d813e8f, 0x3db9df04, 0x3e1d8f73, 
    0x3e4247b0, 0xbba756fb, 0xbda224e5, 0x3d48e354, 0x3d4a7fb5, 0xbc928237, 0xbd4f575a, 0xbe07c848, 
    0x3d151ced, 0x3ce336fa, 0xbe2dc8d1, 0xbe2558cf, 0x3e3deff5, 0xbd084929, 0xbde0b9de, 0xbc6f838a, 
    0x3dd552af, 0x3c88cb1e, 0xbe011422, 0xbba3d0e8, 0xbe348e2d, 0x3d26ee0f, 0x3cbbd60a, 0x3e0c8a77, 
    0xbe1958b7, 0x3b3f24ef, 0x3db7aae7, 0x3c5d56a9, 0x3d26b6ab, 0x3dc269e6, 0xbe13601c, 0x3df8d2e7, 
    0xbd3b28a4, 0x3de48556, 0xbde1b178, 0xbd83b640, 0xbd41b4e9, 0xbde3dacf, 0x3cf3f387, 0x3dc77849, 
    0xbde1e453, 0x3c811034, 0xbd9c606e, 0x3b9742f9, 0xbd70280c, 0xbd270b7d, 0x3dd4bf50, 0x3d3e817b, 
    0xbd1b205b, 0xbe3d9307, 0x3e4a3997, 0x3dd43b1b, 0x3d957b1d, 0x3df4712a, 0x3cd05758, 0x3e013e10, 
    0xbe2019ce, 0xbdd0ea63, 0x3d0fca10, 0xbdca3891, 0x3dde7801, 0xbe002537, 0x3e044ef2, 0xbe4136c8, 
    0xbcac6040, 0x3e2ff566, 0xbe196039, 0xbe1c1ab1, 0xbce6ba87, 0x3e20933d, 0xbdbb349b, 0xbdc9a007, 
    0xbe0449c8, 0x3c0b782b, 0xbe303a9d, 0xbd553107, 0x3e4a9606, 0xbe012c05, 0x3d87038f, 0x3dd64a7b, 
    0xbe139b34, 0xbe058aae, 0xbd469b15, 0x3da983bd, 0xbe46a2c8, 0x3de5aefd, 0x3e18d9a4, 0xbcc1696c, 
    0xbcdb1dda, 0xbdc01ede, 0x3df736d7, 0xbd054a57, 0x3ddd9d38, 0x3d49e3df, 0xbc4ce916, 0xbe09534c, 
    0xbd357ff5, 0x3d25bfdf, 0x3da61525, 0xbdb999bc, 0xbd9c0398, 0xbcd8b1e0, 0xbe531929, 0xbde72556, 
    0xbd689afe, 0xbdaef5b8, 0xbe316e16, 0x3dc442c1, 0xb8886849, 0xbe434c24, 0xbe7502d2, 0xbd9733dc, 
    0x3de6c897, 0x3e0d8fdc, 0x3d9fd6f4, 0xbd2ff4d1, 0x3d1f7d9f, 0xbe00f327, 0xbe0cd090, 0x3dff41d2, 
    0xbde1ad6a, 0xbe412097, 0x3c8bcef6, 0xbdcadc69, 0x3d907b5d, 0xbcfe3099, 0xbdb10351, 0xbddc8a5c, 
    0x3ddb5f23, 0x3d9fa096, 0x3d2b1ac7, 0xbcf8dd1f, 0x3d2b9bf5, 0x3e19f865, 0x3d95b205, 0x3e2eaaef, 
    0x3dee1b02, 0xbe474cc1, 0x3ddb6e6e, 0xbe021e0c, 0x3e04d76a, 0x3d18ca4c, 0xbb2759a3, 0xbc4f4a09, 
    0x3d06fce4, 0xbd9bc9eb, 0xbe0fd572, 0x3e236b77, 0xbe134c42, 0x3e1bd8ae, 0x3e1ecfe3, 0xbdfbd988, 
    0xbd4b5268, 0xbdd767b8, 0xbe0a273b, 0x3db6aea5, 0xbe37d48d, 0xbe32f8c6, 0xbbac0d9c, 0x3e06b281, 
    0xbda8066f, 0x3d1cdd36, 0xbd182d08, 0x3cbd8bdf, 0x3c00fb92, 0xbdc31aaa, 0x3dff079e, 0xbc535e01, 
    0x3d1bd677, 0x3e2ef653, 0x3cbf4c72, 0xbd3aa1a4, 0xbdbd4792, 0xbe3209b7, 0xba55a90e, 0xbe1d1298, 
    0x3ce65098, 0xbd48d300, 0xbdad1d1f, 0xbd3f4b0f, 0xbdc33d4f, 0xbe15f44d, 0xbd5869c5, 0x3d875333, 
    0x3e156cd3, 0x3d5c0af8, 0x3e0950aa, 0xbd93d78c, 0xbd9dd94e, 0xbe372589, 0x3ddf257e, 0xbcd67609, 
    0x3e0853e7, 0xbdc60f6e, 0x3dac3dc7, 0xbe24c46c, 0x3c14a50f, 0x3e09e7be, 0xbd8e4469, 0x3ddcd56a, 
    0xbdcebe30, 0x3e2557ee, 0xbdf8a5a2, 0xbe2a8f5b, 0x3e18ce96, 0x3e14e27b, 0x3d7d738b, 0xbcfd480e, 
    0xbe426021, 0xbd2add9f, 0x3e13c273, 0x3d7a7ed3, 0x39e1a9d3, 0xbdec564b, 0x3bbe7603, 0xbdf5ff4d, 
    0xbe19bd1a, 0x3e084d17, 0x3e14c73d, 0xbdbdb52a, 0xbb875b0f, 0x3ccb0262, 0x3e1ff75e, 0xbe0276da, 
    0x3d1565b7, 0x3d8867ef, 0x3e04befa, 0x3e03ef01, 0xbc834af3, 0xbe13949e, 0x3e87e720, 0xbc9eefe7, 
    0xbe2f9b81, 0x3e0d46f6, 0xbc8119ba, 0xbd883f41, 0xbdc7cb4c, 0xbdc07be8, 0xbd481f96, 0x3e233797, 
    0xbc62e92b, 0x3e3b141d, 0xbd371aeb, 0xbd9d0ccc, 0xbd9784b3, 0x3ceff645, 0x3e0bedc2, 0x3e28cf90, 
    0x3e189d2a, 0xbe307b93, 0x3cf9a970, 0x3cb8c212, 0xbd96a41f, 0xbc185963, 0xbd847df0, 0xbe27d44d, 
    0x3d6a18ff, 0xbe4606cf, 0xbcfc886c, 0xbde35c2c, 0x3e15fdf0, 0x3b080f8b, 0x3e0d5102, 0x3d8fa8b1, 
    0xbd893d78, 0xbd475ce3, 0x3d4f0555, 0xbd76513f, 0xbe524895, 0xbd9757ce, 0x3dbdaa71, 0xbdf11859, 
    0xbd883ec5, 0xbd0b390b, 0x3e045533, 0xbe0c14a9, 0x3e46f597, 0x3e31aa47, 0xbe3c0d32, 0xbbaa3e62, 
    0xbd7643e6, 0x3df46582, 0xbdb04c58, 0xbd949792, 0xbcfb4f67, 0x3ca95d66, 0xbdf48f16, 0x3bb2025d, 
    0xbddba7a8, 0xbd7f1c33, 0x3d59f857, 0x3d284d14, 0xbe2b6f2a, 0xbde6c63c, 0x3d8c7d46, 0xbe1a25c3, 
    0x3c75903d, 0x3de7ff29, 0x3e0e0457, 0x3cf5c0ea, 0xbd882abd, 0x3df8c1d9, 0x3e469a48, 0xbcb950fc, 
    0x3c90017d, 0xbe2c6c85, 0xbd3cce3a, 0x3bc8b3ec, 0x3db92154, 0x3cd8f85a, 0xbd80337e, 0xbdb8b8fd, 
    0x3d882ed7, 0x3d9fdeff, 0x3e1dc174, 0x3dd3b6bd, 0x3db5579d, 0x3e320b87, 0x3e079670, 0x3d9c3e82, 
    0xbc92e693, 0xbe86649d, 0x3d3300cc, 0x3df32d12, 0xbd98146f, 0xbc187c59, 0x3b24f7e8, 0xbe4ebe0b, 
    0xbe247f55, 0x3e1d6a05, 0x3ddc8977, 0xbe2bf67b, 0xbe1c1627, 0x3da38f30, 0xbe33099f, 0xbe458f23, 
    0xbdc99a3f, 0xbe53efd2, 0x3dd1b4b6, 0x3e017a17, 0xbdcd3cc2, 0xbd22d1d0, 0xbd9dcfe6, 0xbd965dff, 
    0x3cbd8234, 0xbd6bc25f, 0x3db503a2, 0x3e247416, 0xbd847169, 0x3c6f892d, 0xbe1a0f53, 0x3d9dbaa5, 
    0xbe04f232, 0x3db87dca, 0xbd9de332, 0x3dc44f21, 0xbb06bb06, 0xbd2acade, 0xbc4a829d, 0x3e30b281, 
    0x3d8b0bfd, 0xbe150395, 0xbe2aba53, 0xbe1db6b8, 0x3c72b82d, 0x3caa0226, 0x3dca619f, 0x3d3920c9, 
    0xbdbc5f29, 0x3de2b2d9, 0x3da380ea, 0x3d8174ca, 0xbe2a7fd2, 0x3d566165, 0xbc800e6f, 0xbd129891, 
    0x3e2c744f, 0x3e3e62f3, 0xbe2b3055, 0x3da136ff, 0x3c894cd9, 0xbdc9b23a, 0xbdd42c38, 0xbdba7fe9, 
    0xbde1529d, 0xbd45380f, 0xbd58604e, 0xbde02999, 0x3e0bbb66, 0x3e18e12d, 0xbd15c784, 0x3da520ad, 
    0xbcc2a891, 0xbe150b33, 0xbe310896, 0x3d099820, 0x3e14c5ff, 0x3e1a8228, 0x3deb93ba, 0xbe026f9e, 
    0x3e0b8a9b, 0x3e0977b8, 0xbe47846e, 0x3e16310f, 0x3d76691e, 0x3d24e139, 0xbda59ad8, 0x3e19613d, 
    0xbe228637, 0xbc10c775, 0xbdac92de, 0xbc1060c6, 0x3ddf4ad6, 0xbe10ad9a, 0xbe3d520a, 0xbdd88b3a, 
    0x3d9d24c1, 0xbd4f2fbd, 0x3d67ca7c, 0x3d334273, 0x3d927620, 0xbdf7ec87, 0xbe2b7c5d, 0x3d0579f5, 
    0xbd5944b0, 0xbd5b60a8, 0xbe2886fa, 0x3b9cedbe, 0x3d9c6572, 0x3defb860, 0x3db5f065, 0x3df02b52, 
    0x3d9a84b7, 0xbe0abf99, 0xbd968f24, 0x3e56de1e, 0xbe3a9a86, 0xbdf76cf6, 0x3c900e24, 0xbd4e2d74, 
    0xbdf394b3, 0xbe4ba55b, 0x3e4b721c, 0xbcc71aa2, 0x3c61441a, 0xbbaf797a, 0xbd0c6fa9, 0xbe0d5965, 
    0x3e149879, 0x3e4e5679, 0xbe116dc2, 0xbce4d25e, 0xbe16ccca, 0xbd05e1b6, 0x3c5978a2, 0xbdf52383, 
    0x3da479db, 0xbe1f52db, 0xbd4a2a21, 0x3c7d6f02, 0xbd9e022a, 0x3e2d01f4, 0xbd86614b, 0xbdcf53f8, 
    0xbe0ba1f2, 0x3c0fe67c, 0x3de43fb0, 0xbd8e7d9d, 0x3db2938b, 0x3e102563, 0xbd881664, 0x3de9239b, 
    0xbdd0cbea, 0xbdc8fb07, 0x3e3da287, 0xbd7a64bf, 0xbcbccc1f, 0xbd94d999, 0xbc78ff42, 0x3e2a166a, 
    0x3da4a1d0, 0xbddc4760, 0xbd8cfbcc, 0xbc9862c8, 0x3ddc411d, 0xbd8dee8f, 0xbd760354, 0x3da7e131, 
    0xbe219bed, 0xbdb9d263, 0xbe0b822e, 0x3db6b1c7, 0x3e0a0499, 0x3d5e1860, 0x3e16add2, 0x3ca28bf5, 
    0x3cff6a68, 0xbc582e4c, 0xbcac1348, 0xbd3f01b1, 0x3d706817, 0x3cbff354, 0x3e02e091, 0xbc451292, 
    0xbd3d48ff, 0x3dab72cd, 0x3ceb131c, 0x3df51132, 0x3d8a47ed, 0x3d5bef74, 0x3dde60d9, 0x3e04b4d7, 
    0x3db6cd5e, 0x3e275fbe, 0xbe31f51f, 0xbd34fddd, 0xbdfc6975, 0xbde8af1f, 0x3e1ea8d0, 0x3c4de16e, 
    0x3de5cbfc, 0xbd3f04a3, 0xbdff4172, 0x3d847f27, 0x3e37474c, 0xbe23abe6, 0x3e170075, 0x3d15dff1, 
    0x3d909ce5, 0x3d22a2ad, 0x3d5de9ed, 0xbc4d6153, 0xbd89447b, 0xbcef8b7f, 0xbe2722ee, 0x3e241430, 
    0xbe384621, 0x3e0ae022, 0xbc081fac, 0x3da33017, 0xbe06808e, 0x3e23de8f, 0xbdf890df, 0x3de13406, 
    0x3e259343, 0x3e1bf44f, 0x3e0f4e3f, 0xbdff888e, 0xbdc2ddaf, 0x3dcede4c, 0x3e37ccd5, 0x3c6bb35e, 
    0xbd576097, 0x3d7c24a3, 0x3deaafd3, 0x3d55976c, 0xbd97716b, 0xbe2bd80e, 0x3e22e58f, 0xbdfa45fc, 
    0x3da4b83d, 0xbe35a0f8, 0xbe09e366, 0xbda4fe82, 0x3db3a236, 0x3e1f06cd, 0xbcdf6595, 0xbb3644d3, 
    0xbda0a05b, 0xbc0d87f8, 0xbcaeda45, 0xbdd79438, 0xbd4252a8, 0x3ce04008, 0xbdcae37f, 0x3e2aac79, 
    0x3dd7daa9, 0xbd312453, 0x3d1602a8, 0x3c37ca9f, 0xbe256cb0, 0x3d3247a4, 0x3e3dfa11, 0xbddae6f7, 
    0xbdcb858a, 0xbe196b96, 0x3e12373e, 0xbc60a137, 0x3df764c7, 0x3e12636a, 0x3e094d8a, 0x3c8aa53f, 
    0xbe22af9d, 0xbdee1277, 0x3ddab1e2, 0xbdad91ec, 0x3ca0dd05, 0x3e07cc23, 0x3d8228a1, 0x3de61627, 
    0x3d142ec0, 0x3e12750a, 0x3d9a3a1f, 0x3d858905, 0x3c3147fc, 0xbda589f3, 0x3e041584, 0x3e1564e9, 
    0x3dc1da7b, 0xbe055442, 0x3d29ba03, 0xbd80407d, 0xbd86947e, 0x3cdcd9bb, 0x3d3c437e, 0x3dd6de66, 
    0xbd46aacd, 0x3e3e4fe3, 0x3e1598a2, 0x3c3f7780, 0x3d8dea6e, 0x3d027fc9, 0xbdb1a2ab, 0xbe18524b, 
    0x3c98eb87, 0xbe00fa1c, 0xbd7d7bfc, 0xbdcf9a24, 0x3e31b25b, 0xbc85c387, 0xbe41819b, 0x3e34003c, 
    0x3c1b7d4d, 0xbc6dfb8c, 0x3e0d2a22, 0x3dbd6cc6, 0xbe225f70, 0x3e6cace1, 0xbe158c6a, 0xbdeaf6ac, 
    0x3d28f834, 0x3e54132d, 0xbccd4dcc, 0xbe04227c, 0xbe115e92, 0xbcaebd7c, 0x3d78ac8a, 0xbda1befc, 
    0x3e008cd6, 0x3d18ca1b, 0x3c930f37, 0x3e1932b2, 0xbd4cf58b, 0x3d88828a, 0xbe01d714, 0xbe1c2436, 
    0x3dc10fd9, 0xbe2a6ec5, 0x3de2f26a, 0xbd889d53, 0x3d8f9556, 0xbdb2f09c, 0xbe464934, 0x3d96b62c, 
    0xbdec009c, 0xbc1027fe, 0xbe0aa48b, 0x3d0dacf1, 0x3dfa6e10, 0xbd843dd0, 0xbd60e969, 0x3dbd755d, 
    0x3e0e536a, 0x3e245966, 0xbd9ee99a, 0xbe2306f2, 0xbdbee969, 0xbceb3b3c, 0xbd74969a, 0x3dbe5827, 
    0x3df4e02a, 0x3dd6f7a9, 0x3e11d3c7, 0xbe1f03f6, 0x3e697056, 0xbdc98b33, 0xbded0096, 0xbd11afe9, 
    0xbdf46b39, 0xbe0a8c9f, 0xbe240971, 0xbdeb85da, 0xbe26931c, 0xbde29804, 0xbdbaf44a, 0xbd2a5174, 
    0xbe45e8e4, 0x3ca109f7, 0x3d543a10, 0x3e08f219, 0x3dd222e4, 0xbd8c1f4e, 0x3dde16cd, 0xbe07fb90, 
    0x3e1460cd, 0x3d6bb4b2, 0xbc70c45d, 0x3e1fc973, 0xbd8fba34, 0x3c666a4b, 0x3cf30d6d, 0xbcedbf49, 
    0x3d537b1d, 0xbe0aa731, 0xbe0e9a24, 0x3e1d2f9c, 0xbdc9359e, 0x3e07f04a, 0x3d442e0c, 0xbda92b17, 
    0xbe0bd200, 0x3d9ee719, 0x3dad5e4b, 0xbd40d75c, 0xbd0902f5, 0xbdfebac5, 0xbe12809d, 0x3d7c0cc4, 
    0xbd8254f6, 0xbde77e4e, 0xbe189095, 0x3e18c2b5, 0xbd295fd3, 0x3c843c1e, 0xbe1e31e0, 0xbd3784a8, 
    0xbdba3f30, 0xbdfb74e4, 0x3db337b7, 0xbe148d04, 0xbcbf0ec0, 0x3d3acfc1, 0x3c91041d, 0x3db4f08e, 
    0xbd8add8b, 0xbe13adb5, 0x3ba41f6d, 0x3e03ecaa, 0x3d2414b9, 0x3d024e4b, 0xbde4c944, 0xbe141542, 
    0x3d139a1e, 0xbe0b42c7, 0x3de88093, 0xbd080c90, 0x3e1cd2f2, 0xbde7b96f, 0x3df33897, 0x3e0a03e5, 
    0x3dd5afbe, 0xbe202bb2, 0x3e166e74, 0xbd276204, 0x3dbf9728, 0x3c89c642, 0xbe5909be, 0x3dd5ac25, 
    0x3df53bb6, 0xbd9be97d, 0xbd6c72b2, 0xbe16445b, 0x3da1c308, 0x3dfe47d0, 0x3d8150e4, 0x3d800db4, 
    0xbe1d62bc, 0xbd404c0f, 0xbe28ef04, 0x3e0a6ed3, 0xbdb6a4d8, 0xbd8cf956, 0x3d7c7f83, 0x3cdaac9e, 
    0x3d6aff9e, 0xbdce215d, 0x3de762a2, 0x3b891ac5, 0xbd94dcf1, 0xbdfffca5, 0xbca3a3c3, 0xbace63cc, 
    0xbe53e77c, 0xbb9a7370, 0xbb02b44a, 0x3da09588, 0xbcb36283, 0x3e0b1bdf, 0xbd44628f, 0xbe11e954, 
    0xbded925a, 0x3e44961b, 0x3d2dbe4d, 0xbe1d78a1, 0x3dc363f1, 0xbb9f4adb, 0xbd46cdb6, 0x3dc32090, 
    0x3dbeb1ec, 0xbcf3d11c, 0x3e1586cb, 0x3d2f59d1, 0xbdbd8d3d, 0x3c3c496c, 0xbd743cd2, 0x3e0dbd47, 
    0x3e0c5d54, 0xbdf754e4, 0x3ce5dd98, 0x3db74f56, 0xbd33c3b1, 0x3d135e0e, 0x3dd5865b, 0x3d866387, 
    0x3e0f05c0, 0xbd4dee27, 0xbe460671, 0x3d1684c9, 0x3dfda4a0, 0x3d5052e3, 0xbd384156, 0xb9c643b9, 
    0xbdeb5984, 0xbc11385f, 0x3cdac9fc, 0x3e47ddaf, 0x3e0d9efe, 0xbc17465d, 0x3e14d29f, 0xbe208eba, 
    0xbe0af127, 0x3e150972, 0xbd0b6d9a, 0xbdcd166f, 0xbd42cbf5, 0x3e19eef7, 0xbdd89365, 0xbe3b0fa9, 
    0xbd90d369, 0x3e25abc4, 0x3dedb5c6, 0xbcb73ee5, 0x3e00b843, 0xbd0bad24, 0x3e26a13a, 0xbe26cdb8, 
    0x3d143bfb, 0x3dfda14f, 0xbacb2b54, 0x3e134ab9, 0x3d4257ab, 0x3cc6c1e1, 0x3cdd2461, 0xbd197c34, 
    0x3dd066ca, 0x3d98ae07, 0x3e22bc39, 0x3e26e0f6, 0x3dac1c49, 0x3dc897e7, 0xbd25cf75, 0xbdde26ac, 
    0xbdc97aab, 0xbe0fef5a, 0x3d8cdff6, 0x3db4da7f, 0xbe853d80, 0xbe39b372, 0x3dfe1a38, 0x3e0e09cb, 
    0xbd42b4bf, 0xbd757fdc, 0x3b3094b3, 0x3dd40c94, 0xbdbb4470, 0xbd56dad1, 0xbd6a9ae3, 0x3dd210ab, 
    0xbd91d1c7, 0xbde09b10, 0xbd6f9cc3, 0xbb7d9e5b, 0x3ced1351, 0xbc40d28f, 0xbe32ca5b, 0xbdb2f707, 
    0xbc33138f, 0xbe3f9d7d, 0xbe077473, 0x3d97de08, 0x3c822a6c, 0x3c5ca1f5, 0xbd733cd1, 0xbd56a693, 
    0xbc1764aa, 0xbdc89fe2, 0x3e0fee6a, 0x3d83c6e0, 0xbd927c1e, 0xbda42bec, 0xbdc406ee, 0x3e2e4abd, 
    0x3d098839, 0x3d4d10b2, 0xbd5424ba, 0x3df3a7a3, 0x3d0845e0, 0xbe1967e6, 0xbd0d1c42, 0x3ce50e91, 
    0x3daaf82a, 0x3d73936a, 0x3d97bf01, 0x3e2eea88, 0xbe6af164, 0x3e54f4e5, 0x3cbfc693, 0x3dfe3a09, 
    0xbdbf8e3c, 0xbd45e678, 0x3c5d9d39, 0x3e044083, 0x3deaf939, 0x3e0bcf7e, 0xbc5d64f9, 0x3c11ae2f, 
    0x3b25173b, 0xbe0e5ba3, 0x3e058325, 0x3ddbc32d, 0xbd1362c0, 0xbe1c9e57, 0xbc1de8bc, 0xbe0a360a, 
    0xbd8ba7cf, 0x3d457ad6, 0x3e3e20cf, 0xbbbc143b, 0xbe3358e3, 0xbe08f451, 0x3c7242ab, 0x3df0a835, 
    0xbe21f5a0, 0xbd55b77c, 0xbdf09806, 0xbc8dd9bb, 0x3c28056c, 0x3cfd6e04, 0xbdcc3db2, 0xbe35b875, 
    0x3db9fa21, 0x3e0e9e0f, 0xbcff940e, 0x3cb6b573, 0xbe2e48a3, 0x3e192244, 0xbe221a58, 0xbe5ae97a, 
    0x3da0c96e, 0x3d131f32, 0x3e2a1ca2, 0xbc4d4d0c, 0x3e0b9f3d, 0x3e176c21, 0xbe224426, 0xbe354eb8, 
    0x3e03bbba, 0xbe121e1f, 0xbe054f21, 0xbe20d97e, 0x3c43db1a, 0xbe1a126a, 0xbd229973, 0xbe12ff84, 
    0x3b231788, 0x3dcb1e01, 0x3e510493, 0xbdc2a949, 0xbe203253, 0xbe38e239, 0x3e01b5ab, 0xbdde2ec8, 
    0x3ca0bc2b, 0xbdbbe0ae, 0xbd982d1e, 0x3dbec9ee, 0x3e38577e, 0xbdbfb3bd, 0x3da1e28a, 0x3d70c45c, 
    0xbdb210cf, 0x3e118fee, 0xbd878ffb, 0x3d2afd50, 0xbe18a3af, 0x3de5ab2c, 0x3ddf754b, 0xbc94bcab, 
    0x3dce8b6d, 0x3db1678a, 0xbe0b5af8, 0xbde6ab70, 0xbe243f80, 0x3e1305b3, 0x3e36b9ec, 0xbd604bd2, 
    0x3dcd2b91, 0x3d41d878, 0xbe57ae1f, 0x3d163f00, 0xbdf48f0e, 0x3be242b6, 0x3d07727d, 0xbde10401, 
    0xbe0f7193, 0xbd7b8900, 0xbdb67972, 0x3d49b165, 0xbdbb1a94, 0xbd1b1c3b, 0xbe1e4ed6, 0xbdee2035, 
    0x3b6cd0b7, 0x3dae4241, 0x3e356c5a, 0xbe36a4a7, 0x3d872f6e, 0x3e4cb9bf, 0xbe1b581f, 0x3e0e28b3, 
    0xbdf85919, 0x3e21aa72, 0xbdedfbb7, 0xbd07abd3, 0x3dade4f2, 0x3e60a93e, 0xbdfd0298, 0x3dc3a9f7, 
    0x3dace6c2, 0xbe13cdad, 0xbb4bc6cc, 0xbe243df5, 0xbcc7be58, 0x3d762f3c, 0xbe03c10a, 0x3dcc5280, 
    0x3e0062ee, 0xbde17ad3, 0x3d94703a, 0xbe2f5346, 0xbd521933, 0x3e2bc4d9, 0xbdab95dc, 0x3dd06b2e, 
    0xbde495fc, 0xbcc6829f, 0xbd9192cf, 0xbe2a82fa, 0x3db5601e, 0x3e457fe4, 0xbb03d402, 0xbde0b723, 
    0x3cc5ddd0, 0xbe1cbb84, 0xbda373bc, 0xbd9e12aa, 0xbe0f6103, 0xbe0b657e, 0xbda9b89f, 0x3e21c0a7, 
    0xbdc51afa, 0xbc86d6a5, 0xbe21e205, 0x3e459ccf, 0x3da635c4, 0x3e34c0e4, 0xbe144d7c, 0x3de1ba33, 
    0x3dad2653, 0x3d52cfa2, 0xbd52aef7, 0x3dee02ef, 0xbc87808a, 0xbd4f14b3, 0x3df215a8, 0x3e04801a, 
    0x3e4baa91, 0xbe237442, 0xbe643deb, 0x3e2116c8, 0xbc8f1cf0, 0xbcbaa52e, 0xbdbd8063, 0xbdfda1dc, 
    0x3e54d3b2, 0x3e03ed8f, 0x3c6aa381, 0x3da93d0e, 0xbe7f328f, 0xbd23bbef, 0xbe0e3ad0, 0xbd2c0bf8, 
    0x3db7cb6b, 0x3cbd7b4b, 0xbe2e95f9, 0x3e0b7089, 0x3dabcd74, 0x3d0d5648, 0x3d126372, 0x3da0b1aa, 
    0x3abd2a60, 0xbd134a55, 0xbc83084c, 0xbdc3dc06, 0xbe039c0b, 0x3e0fe82a, 0x3e057fec, 0x3d45e132, 
    0xbd045ad1, 0xbe14c8ab, 0xbbb306b7, 0x3dbf3114, 0xbdf6f6cf, 0xbe17f827, 0x3dbcc2f0, 0x3e0197b3, 
    0x3d3f950a, 0x3bee90d2, 0x3d2ccad8, 0xbd66d1e6, 0x3e2afae8, 0xbdd40e24, 0x3d4b979c, 0xbe037cd4, 
    0x3d9def91, 0xbc9a7948, 0xbdc3fd0b, 0x3dc958d3, 0xbe20d72a, 0x3e1139fa, 0x3d3cb303, 0xbd34c743, 
    0x3d2b9602, 0xbe72232c, 0xbd9bd593, 0x3d8528af, 0x3e1f16e0, 0x3dc8e6a1, 0xbd9415ff, 0xbe37ca4c, 
    0x3d140ff8, 0xbcdda033, 0x3df685c0, 0xbdce0e0a, 0xbe6653de, 0x3de37718, 0x3dc18e5d, 0x3dde3343, 
    0x3d3897df, 0xbdc68666, 0x3cbf9022, 0xbe1e4ef0, 0x3deae3c3, 0xbd77032d, 0x3d4b7708, 0x3d9853b3, 
    0xbd98106b, 0x3d0179d4, 0xbe2cfaca, 0x3e252054, 0xbd37a3b6, 0x3d3be090, 0x3e13bf40, 0xbdfde6f8, 
    0xbd3216a9, 0xbdbcac90, 0xbcc82bb7, 0x3df28d54, 0x3d494005, 0x3d7fa12f, 0xbcfdf27c, 0x3d996605, 
    0xbe1d2888, 0xbc2afa0f, 0x3e2271d2, 0xbc694575, 0xbe86506f, 0xbe00e82a, 0xbd25553d, 0xbbe0a0c4, 
    0xbcd3db12, 0x3e59a9b9, 0x3e1151fa, 0x3c2fb18f, 0xbe1a7ccc, 0x3da6553d, 0x3d7e232c, 0x3e234adf, 
    0xffffba3a, 0x00000004, 0x00000010, 0x00000001, 0x0000000c, 0x00000001, 0x00000020, 0xffffba56, 
    0x00000004, 0x0000000c, 0x00000001, 0x00000006, 0x00000020, 0xffffba6e, 0x00000004, 0x00000034, 
    0xbbe3e674, 0x3b9a7d9e, 0x3d29a248, 0xbc8e5b79, 0xbbe872a5, 0x3d28d5e9, 0x3d157370, 0x3ce48269, 
    0x3d0582fe, 0x3bdc90c1, 0xbd5accff, 0x3cb0d10b, 0xbd0d857e, 0xffffbaae, 0x00000004, 0x00001380, 
    0x3e0b4a59, 0x3e169844, 0xbcbe6c7a, 0xbe17341b, 0xbe79d3c9, 0xbe4a9c63, 0xbda712d9, 0x3e251b27, 
    0x3e56cd39, 0x3e23204d, 0x3db1ce4d, 0xbded2b29, 0xbe495687, 0x3e33d218, 0xbdb69477, 0x3e480782, 
    0xbe227442, 0xbe031efc, 0xbde04388, 0xbdbec793, 0xbdf7b308, 0xbe3fc077, 0x3d8fe507, 0xbc5cc4f4, 
    0xbde7ce80, 0x3e4b6e47, 0xbc808d38, 0xbdb99774, 0x3e7ebcee, 0xbd62e3c0, 0x3e03c257, 0x3d2473e1, 
    0x3e03cff2, 0x3dc6d298, 0xbbc65b3e, 0x3e48e9e8, 0xbe34a3b0, 0x3dfbaea9, 0x3d8e644e, 0xbd5d1ff0, 
    0x3e215f52, 0x3e614bf6, 0x3de5abfc, 0xbe8b5b32, 0x3c906341, 0xbe3b68f7, 0xbe454412, 0xbde08dd4, 
    0x3e0d39cc, 0xbca461b2, 0x3d9d740f, 0xbe4a57aa, 0xbd27a37c, 0xbe7df0c8, 0xbd6db3a4, 0xbe847af5, 
    0xbe8107e4, 0xbc292f76, 0xbe817e1f, 0x3e525c99, 0xbe42e018, 0x3e4131ee, 0x3de348b3, 0x3e21c9e1, 
    0x3df599f4, 0xbd7159f3, 0x3e06d642, 0xbe16253e, 0xbe485630, 0x3e1ba246, 0x3e9d2996, 0xbe44ac0b, 
    0x3e165974, 0xbdc1b347, 0xbe542718, 0x3e5e4ecd, 0xbcb4eba4, 0xbe050504, 0x3e85eb66, 0xbe580948, 
    0x3df49ccc, 0xbdead04e, 0x3cad9c52, 0xbb3943ae, 0x3e0a833c, 0x3e9ca91f, 0x3e411733, 0xbcbd8b00, 
    0xbe4eda17, 0xbe35e368, 0xbe169ba8, 0xbe3e5b22, 0x3e38b051, 0x3e4ff17c, 0x3e94caa4, 0x3e97853b, 
    0x3de70b12, 0x3e76b951, 0xbe42e8af, 0xbe63998d, 0x3e532fc3, 0x3dff93c6, 0xbdd86e43, 0x3e285a56, 
    0xbea6f694, 0xbe315609, 0x3d02fdf4, 0xbdf74493, 0x3ddcb01e, 0x3c826289, 0x3d17e804, 0xbc5cdf9b, 
    0xbecc474a, 0x3d97270a, 0x3c204193, 0x3e54f747, 0x3e4beee2, 0xbd94e50c, 0x3e2d90ca, 0x3c5c53f3, 
    0xbea6593f, 0xbb11d6ff, 0xbdf52eb2, 0xbe866271, 0xbe51dbb0, 0x3e5a1f23, 0x3df6ea8e, 0x3d8c912e, 
    0x3e4bd440, 0x3da0a8be, 0x3e130c5a, 0x3e5f167b, 0x3e9556d2, 0xbe50fa16, 0x3d809487, 0x3eb2970f, 
    0x3e284582, 0xbdaa8953, 0x3ed4dc37, 0x3e885c4f, 0x3db6be9d, 0x3da0207e, 0x3e3a69ca, 0x3dc9da68, 
    0x3e2a95fe, 0x3c7abbb7, 0xbea3c985, 0x3e42fc49, 0xbc4bf734, 0x3d3a56cd, 0x3d93335e, 0xbe0ff1d1, 
    0xbe95f9ff, 0xbe93c2fb, 0x3db4f273, 0x3ec3b043, 0xbda234bf, 0x3e0c689a, 0x3da9ba69, 0x3dace366, 
    0x3e35fc6b, 0xbd87da63, 0x3cd9978a, 0xbdf5fc2c, 0x3dcc8514, 0x3e4d6640, 0x3d95a810, 0xbd77fe6e, 
    0xbd20db4e, 0x3e4d71cd, 0x3e3f6006, 0x3db5d21a, 0xbe43c23b, 0x3db354d3, 0xbe5996b6, 0x3dfc496d, 
    0x3e1c6e79, 0x3e11732e, 0xbd7024a8, 0x3d459916, 0x3d19491e, 0x3e3d913d, 0x3db4a271, 0x3d953d85, 
    0x3db48d36, 0x3e55642c, 0x3e423176, 0xbe327994, 0xbe18d3de, 0x3d65a7c6, 0x3c6d5a33, 0xbba20987, 
    0x3e215a2d, 0x3dad328f, 0xbcb04074, 0x3e3b4699, 0x3da08f0d, 0x3e90e921, 0x3e4d55a6, 0xbdd1ad94, 
    0x3de383fe, 0x3e02a864, 0x3dff6756, 0xbdd7373b, 0x3e057847, 0xbd9182b5, 0x3e266b9e, 0xbd336e48, 
    0xbe551fe3, 0xbdf82ce6, 0x3e31ecdd, 0x3e88f02d, 0xbe655298, 0x3e55cc36, 0xbe2c9afe, 0xbe378ba1, 
    0x3e5e1c4a, 0xbd77121b, 0x3d9cdddf, 0xbda049e7, 0x3bea7282, 0x3c393335, 0x3d0f0b37, 0xbe295e77, 
    0x3d03d3d2, 0x3da75b8c, 0xbd6ae24e, 0x3e17f9f7, 0xbdf1b9c5, 0xbde90cab, 0xbe2319fc, 0xbc46ce49, 
    0xbe54023c, 0xbe1e2cba, 0x3c8b9a5b, 0x3e0654ff, 0xbe1c8eb9, 0xbd82bfa9, 0x3dc201e6, 0x3e13932d, 
    0x3c9baffd, 0x3e0bd313, 0x3e39aa8c, 0xbe55f03e, 0xbc01f5cc, 0x3e9ec14f, 0xbe67cb90, 0xbe3a74c6, 
    0xbe459ed1, 0xbe0e8ffc, 0xbd2ba7a1, 0xbe444ff3, 0xbd4aea12, 0x3df9f4a2, 0xbe83dc6d, 0xbe4ca663, 
    0xbe2bfd1a, 0xbd5d23a6, 0xbe111835, 0x3d54bc0b, 0x3e1e872c, 0xbd365640, 0xbe0ef989, 0xbe70e220, 
    0x3e5f0a30, 0x3e700cb3, 0x3df743e8, 0xbea263a7, 0xbddebb00, 0xbe758eb0, 0x3de8d5b3, 0x3e3b44fd, 
    0xbe8bcf1d, 0x3d97bae1, 0x3e09035e, 0xbdae165d, 0xbd82d4d5, 0xbdb2a765, 0x3dc761c5, 0xbbbf569b, 
    0x3c296837, 0x3df9bc4e, 0xbe071d76, 0xbdfbb487, 0x3d0c6458, 0xbdd5e863, 0x3da6c841, 0x3d9fa4ee, 
    0x3cd62d6e, 0x3df38c2c, 0x3d998882, 0xbd642583, 0x3dd90c5c, 0x3df8b514, 0xbd32e1e5, 0x3db46094, 
    0xbda0cf26, 0xbd8cf8d4, 0x3c68b9b3, 0xbddacdd0, 0xbd956886, 0x3d0e9ba1, 0xbde13c30, 0xbd23d691, 
    0x3dd2232d, 0xbb094ec1, 0x3c94cccf, 0x3dd63b9b, 0xbdab2565, 0xbe1c5a96, 0x3d9c99de, 0xbd87e17d, 
    0x3c5b1c02, 0xbdb8a1a1, 0xbe8a2b58, 0xbe0a82e3, 0x3e9418b9, 0x3e1c369d, 0xbe174dbc, 0xbe7aa5ab, 
    0x3c5cfe5e, 0x3ea75844, 0xbe8196f4, 0x3e201baa, 0x3d3ba37c, 0x3df6dba5, 0xbe6cf567, 0xbe4c14dc, 
    0x3ebe3ff0, 0xbe87454d, 0xbe29056f, 0x3e0a14c4, 0xbe6be5dd, 0xbd73bb17, 0xbe2f3798, 0x3e0fbd6b, 
    0x3dedcdd5, 0xbea2c6a1, 0x3e2f6b9b, 0xbe6c3689, 0x3d2b20e9, 0x3e257322, 0xbe446b20, 0xbe26c01c, 
    0xbe36e6e5, 0xbe7c498d, 0xbdd7053c, 0x3df6458d, 0x3d837d1f, 0xbdb88fa9, 0xbe0410d0, 0x3ed0d069, 
    0xbe58b041, 0x3e8e77bf, 0x3ef46cfa, 0xbe10ca8e, 0xbe681128, 0x3e25e2d9, 0xbe9876a0, 0x3ecb0d74, 
    0x3df84c5e, 0x3d60d59a, 0xbdd825b2, 0xbe1ee0f7, 0xbdd77dc0, 0xbeb4985a, 0xbdd45094, 0x3ecb04ed, 
    0xbe255bf8, 0xbe468905, 0x3e690dfd, 0xbd257ef7, 0xbe40cd53, 0x3d19ffb6, 0xbc0cbbc1, 0xbd5ddbc6, 
    0x3ea99842, 0xbeab5715, 0x3dd5ff00, 0x3d9a49c2, 0xbe88e3fd, 0x3e399bd3, 0xbe06ecad, 0xbd9b296d, 
    0x3e80529c, 0xbec3ff33, 0x3cb7087b, 0xbeb42b55, 0xbe496042, 0xbec192cc, 0xbddd133d, 0xbd909f60, 
    0x3d966821, 0x3d784a7e, 0x3dcfc866, 0xbd214a12, 0x3dcee53e, 0xbd3c22f8, 0xbd44ed16, 0x3c33e9ad, 
    0xbd32afaa, 0xbd9c727e, 0xbd724471, 0x3c9b037b, 0xbe177b07, 0x3e4b6770, 0xbe2a37a7, 0x3c42559c, 
    0x3dd8b262, 0x3dec849b, 0xbe36bc55, 0x3dd52b2d, 0xbd44fc4e, 0x3daa0e3a, 0x3d8118f9, 0x3e2829f9, 
    0x3d5f330c, 0xbe22294b, 0xbde773b0, 0x3ddc8f15, 0xbdd68a7a, 0x3d00e1ec, 0x3d1425c8, 0xbe0d37d1, 
    0xbcc1d7b1, 0x3da98726, 0x3c7215a6, 0x3cb92ed2, 0xbd63b623, 0xbdf76fda, 0xbe1e489f, 0x3dbf4455, 
    0xbe210081, 0xbe25eff6, 0xbc94d34c, 0xbd68ee5d, 0xbde19166, 0x3e1bb71d, 0x3dbd997a, 0x3ce71916, 
    0x3d15ee26, 0x3d81628f, 0xbe04d699, 0xbcf75550, 0x3d9e1fcc, 0xbe271b95, 0x3d8248e8, 0x3e48e365, 
    0xbe254c3e, 0x3e0961bb, 0xbc61ece2, 0x3e110a01, 0x3e2f860b, 0xbd513c45, 0xbc54cc80, 0x3e25d715, 
    0xbcb163f4, 0xbe1e3724, 0x3dbaf1ae, 0x3e1aaafd, 0xbda22c5a, 0xbd9e62b1, 0xbdc06166, 0x3b68f4d2, 
    0x3de1ab7c, 0x3cd75ffa, 0xbe127d85, 0x3d92c4aa, 0x3e09cae8, 0xbdade442, 0x3dde1887, 0x3c82eba5, 
    0x3dfeadca, 0x3d27ef3d, 0xbcc82c95, 0x3dfc6817, 0x3d2099fd, 0xbd288cfc, 0xbd41fc3b, 0xbd3713f1, 
    0xba9c7713, 0x3cf9bdbe, 0x3d2c618e, 0x3e056128, 0xbdbceb6d, 0xbd0f6456, 0x3ddd167e, 0xbe13a3f1, 
    0x3d1b22b7, 0xbc80962a, 0xbc3cf78a, 0xbd45f938, 0xbdc2ced8, 0x3d307ee2, 0x3d76e750, 0x3da629a7, 
    0xbe054752, 0x3dc60bef, 0x3ddd51d6, 0xbcaa4e94, 0x3da04af5, 0xbdb6ec67, 0x3c75e14f, 0x3e0b8212, 
    0xbd6f78b0, 0x3de410d5, 0xbcd67011, 0xbe18bb9a, 0x3e291d87, 0x3d0cc16f, 0x3e396e87, 0x3d54d52d, 
    0xbdfdca4b, 0x3df3722a, 0xbdef5bfe, 0x3dc31074, 0x3dda5507, 0x3e087192, 0x3e235216, 0xbdcdaeb6, 
    0xbe557344, 0xbe1747b7, 0xbe1f472d, 0xba519e9e, 0x3d665f93, 0xbe4ed4ef, 0xbcd7c4e7, 0x3bdfdbc6, 
    0x3cf86134, 0x3c2a4d69, 0xbe170233, 0xbe3f7fb7, 0x3ba8559f, 0x3db77705, 0x3d922f8f, 0x3ddccced, 
    0xbd8f12b2, 0x3d868613, 0x3e3007b6, 0x3e04fd19, 0xbe53aceb, 0x3e8bd8c5, 0xbe3a5620, 0x3d3a2f18, 
    0x3d42dc1e, 0xbd5b529a, 0xbe84828f, 0xbe04ae60, 0x3e844cab, 0xbe74ac9c, 0x3e35234e, 0x3dd14e95, 
    0xbc41bf6b, 0xbeb802ad, 0xbe6c0e87, 0xbe123807, 0x3ebe860b, 0x3e7ad446, 0xbcdace62, 0xbea84057, 
    0x3e9d561d, 0x3d7b1862, 0xbe9e3a5f, 0xbbca48f0, 0x3a5244d5, 0xbe80a625, 0xbe2c24dd, 0xbd830968, 
    0xbed0de38, 0xbea7e76c, 0xbc1f506d, 0xbccfdaa0, 0x3e964b88, 0xbdbca3e2, 0x3cd0e8b8, 0x3e675a64, 
    0xbebd2627, 0x3da85e91, 0xbeda2911, 0xbe7f875b, 0xbe4653fc, 0xbbf912c3, 0xbe347eba, 0x3d0881e7, 
    0xbda1b907, 0x3e0d8956, 0x3e473768, 0xbd31c192, 0xbe310ea3, 0x3ea24d13, 0xbd96f3fb, 0xbeb9a5ca, 
    0x3e59449b, 0xbd5d288f, 0xbe524136, 0x3eb1ceb3, 0x3f00249d, 0xbd9dbd4e, 0xbe6945a6, 0x3dc1b71f, 
    0x3d121177, 0x3eb83390, 0xbea431c9, 0xbe1efa8c, 0x3e917128, 0xbe1d1424, 0xbd7c60ec, 0x3ec19c8c, 
    0xbe9a5ecb, 0xbe7e951a, 0x3e5f1dad, 0xbe853ac7, 0x3dc9fa90, 0x3ea57157, 0xbe3c7b6c, 0x3dbe79a5, 
    0xbefca031, 0xbed0944e, 0xbd6d90bf, 0xbd9f418b, 0x3d4ef14f, 0xba82cb16, 0xbec05c00, 0x3e35b6d9, 
    0x3da2c054, 0xbe85c54e, 0x3cb08ab8, 0x3e74ebac, 0xbdda94d6, 0xbd90ddb3, 0x3d4dee28, 0xbe3461d3, 
    0x3e5eabc6, 0x3d44484f, 0x3e1e19bf, 0x3e1cffc9, 0xbe8ebcf9, 0x3e4f88b4, 0x3e5bee17, 0xbd5b8489, 
    0x3e876b65, 0x3cd56135, 0xbe7d67d6, 0x3d2afbe9, 0x3e4dd7ba, 0x3c252a6b, 0x3da14e92, 0x3d726fdc, 
    0x3cd7dca3, 0xbe33478d, 0x3d0ccc74, 0x3cb6f742, 0x3e0e60de, 0xbe6aeae1, 0x3d810f01, 0x3c4aa685, 
    0x3eb13657, 0x3e721fb7, 0x3dbe233c, 0x3d92fc35, 0x3ea73cd5, 0xbdc52b44, 0x3c08c7c2, 0x3d000936, 
    0xbe21b5c1, 0xbe2e3c6b, 0xbc328576, 0xbd482d97, 0x3daa66a3, 0xbd73c75f, 0x3d5e33f5, 0xbda0aebf, 
    0x3d5e4d5c, 0xbd4ac29b, 0x3e24fd12, 0x3b9fbf9f, 0x3d0dc379, 0xbd090682, 0x3dd27770, 0x3da4efad, 
    0xbe1ffca8, 0x3dffe025, 0x3cb17287, 0x3cdc68fd, 0xbd0111dc, 0xbe15c4af, 0x3dc8aca2, 0xbc02d47a, 
    0xbd4d5a52, 0x3e346eb4, 0x3c9e0fdf, 0xbd473f62, 0x3e00d0a4, 0xbdf82139, 0x3cbdd745, 0x3d046fe2, 
    0x3dd2e3e9, 0x3d46ae54, 0x3c397d33, 0xbdd29074, 0x3da9394a, 0xbd607690, 0xbe9d6fb6, 0x3e536105, 
    0x3d6db948, 0xbe8ed867, 0xbe638f41, 0x3e2e1d07, 0x3e9c92f2, 0x3d69ba8f, 0xbe4eba96, 0x3e561cac, 
    0x3ea6a2ed, 0x3e88d0c8, 0x3d8a8972, 0x3e7f3301, 0xbeaa1544, 0xbe890e2f, 0xbe368e16, 0xbd782881, 
    0xbe156cb8, 0xbe52891a, 0xbe5d0532, 0x3e7ea577, 0xbd03a19b, 0x3e956f92, 0x3d7d0950, 0xbe2e66c8, 
    0x3e5bb085, 0x3d9a2681, 0x3c00ef87, 0x3e18c79e, 0xbd2c1d13, 0x3e908111, 0xbc9adf18, 0x3e131c0f, 
    0xbe34709f, 0x3e76eb67, 0x3e8a2109, 0x3d32aeab, 0x3daea489, 0x3d0dea12, 0xbcdee4bd, 0xbd788337, 
    0x3c4555da, 0xbce30e16, 0x3d51b86b, 0x3c549c14, 0x3d15843a, 0x3e12c3e1, 0x3de4c3d4, 0x3dea4fd6, 
    0x3dd31891, 0xbe025f0b, 0x3cf671e3, 0xbd9d44f9, 0x3c8d00ab, 0x3d860cd8, 0xbdee103f, 0x3ddb0edd, 
    0x3dd8a170, 0x3df6a487, 0xbdfb9e44, 0xbd4c89e4, 0xbe08da40, 0xbd05ccbf, 0xbd6d76a9, 0x3d17a701, 
    0x3e14f308, 0x3d8fbf29, 0x3c895496, 0x3e12cb71, 0xbe050353, 0x3b00f175, 0x3e0819a7, 0x3e1c4e21, 
    0x3deb74f1, 0xbe0951f4, 0x3dd6aa60, 0x3db1ea8c, 0xbe84d096, 0x3e109dad, 0x3c208085, 0x3e2be15a, 
    0x3eb99406, 0xbe3e95ea, 0x3eb6861b, 0x3da9e8ff, 0xbdc5c5d6, 0xbd8234b6, 0xbd86873c, 0x3e72d8b4, 
    0x3eafc5ae, 0x3e791ee1, 0xbe0ad72a, 0x3cdaad1d, 0xbe34a0fb, 0xbc66986f, 0xbdd68ed9, 0xbe17fa57, 
    0x3e714cbd, 0x3d1f4bfa, 0xbe571375, 0xbdd7e411, 0x3edb542c, 0x3e857cbe, 0xbe0f718f, 0x3e2d2b7e, 
    0x3d996233, 0xbd607719, 0xbd3712aa, 0x3eb1d38a, 0x3ecac8d8, 0xbe578807, 0xbecdaead, 0x3d20cd24, 
    0xbe3ff4dd, 0x3e83863e, 0x3e893584, 0xbe6929e7, 0xbd59b4fe, 0x3d909d96, 0xbdd5cc65, 0xbdd78798, 
    0xbda38038, 0xbe65490e, 0xbecb85ca, 0xbe31f1c6, 0x3ee0e462, 0x3dcd47ea, 0x3ee73e3c, 0x3e6690cb, 
    0x3ca59212, 0xbe974a35, 0x3c9bdc04, 0x3d68c1ef, 0xbe459cba, 0xbe3bf1e9, 0x3d08ec84, 0x3e926656, 
    0x3e013d10, 0xbc963a34, 0x3f155a69, 0x3bd542eb, 0x3da2a8dc, 0x3e109c9e, 0x3b146f7d, 0x3ea6ada1, 
    0xbe43934c, 0xbb2e83cc, 0x3e96faa9, 0x3e76e396, 0x3f08bcae, 0x3e5447e2, 0x3ea57acc, 0xbe94aacd, 
    0xbe7fb320, 0xbec0f7f9, 0x3deb9da2, 0xbddae84d, 0xbe4dc364, 0xbe538418, 0x3e28f147, 0x3cf2193c, 
    0xbddc3cd8, 0xbe239987, 0xbe20e2f7, 0x3d625a55, 0xbe54a5f5, 0xbe6a196d, 0x3da7be1f, 0x3e03f73a, 
    0xbdaa0b38, 0xbcf81e78, 0xbe26b88a, 0xbdcd1a64, 0x3dc1c50d, 0xbde1c724, 0x3d77b449, 0xbe3e385c, 
    0xbc5f6aa0, 0xbd9aac6e, 0x3e0038fa, 0xbe6cd6c9, 0x3e8b7231, 0x3d436042, 0x3e0a433f, 0x3d6dbc00, 
    0xbe34f72b, 0xbe3dda61, 0xbe1ed8a4, 0x3de83d04, 0x3d8b81a0, 0xbdea6027, 0xbb9a3a3f, 0x3c5ca140, 
    0x3e2e5a4e, 0xbe4c2313, 0x3e977e07, 0x3e99e2fa, 0x3dc72f60, 0x3e45807a, 0xbe5ca610, 0x3e73ca83, 
    0xbe4325b0, 0xbe6b3d2e, 0xbd2a0d34, 0x3e58d3dd, 0x3e809925, 0x3e51b19f, 0x3dff9ec5, 0x3e9dc6b4, 
    0xbdef7266, 0xbdc5bab2, 0x3b7f006a, 0xbe3493cc, 0x3d1e9cd3, 0xbe7c622e, 0xbe599c07, 0x3d8ca40b, 
    0x3e715f8d, 0x3e4057aa, 0x3d98f1f6, 0xbdb9882e, 0xbdc88257, 0x3e7df26d, 0x3e04c525, 0xbe23d30a, 
    0xbde6ec86, 0xbe8cc6ea, 0x3e13bd14, 0x3d1898f4, 0x3e28ac89, 0xbe3af88c, 0xbe7d0f6e, 0xbe823de2, 
    0x3d9ab0f5, 0x3e2b008f, 0x3de307f2, 0x3e2c7f30, 0xbd4a9658, 0xbe268711, 0xbcaab824, 0xbdf6bd0a, 
    0x3e6504be, 0x3e3a27cb, 0xbe7700ab, 0x3e1bbd3d, 0x3e88b0f6, 0xbe8cc52b, 0xbe0595c2, 0x3eb12e5c, 
    0x3ced6643, 0xbdbf1338, 0x3e190680, 0xbdff8c44, 0x3e5986e6, 0x3d09db64, 0xbd545862, 0xbe3a7770, 
    0xbe81124b, 0x3e5798be, 0x3e69da59, 0x3e0723fc, 0xbe237bb8, 0x3de57bd0, 0x3c8f18d8, 0x3c78f81d, 
    0xbda62ce9, 0xbe034a63, 0xbcc26746, 0x3e1fb807, 0xbe29cd61, 0xbe7f0435, 0x3e2bcbbf, 0xbe1653a9, 
    0x3d50d79d, 0x3e6cbfd3, 0x3dc1d5ba, 0xbab93974, 0xbe0affe6, 0x3e6983c1, 0xbe901dc2, 0x3d4a33d2, 
    0xbe978f96, 0x3e25ebea, 0xbe8cda8a, 0x3c551790, 0xbe62f5bb, 0x3e96d37e, 0xbd8a090c, 0x3e18eeca, 
    0xbe1a4b70, 0xbe5f0b8e, 0xbe6c4685, 0xbe859043, 0x3e620c6b, 0xbc2b37b4, 0x3dc6a7aa, 0xbe303590, 
    0xbe387634, 0x3e79ff5e, 0x3e81b932, 0x3dad9c12, 0xbd7712f8, 0xbe8722dc, 0xbe418181, 0x3e917130, 
    0xbb43267e, 0xbe2db50f, 0xbe8ad473, 0x3e0630c6, 0xbdfbb5dc, 0x3e8e1900, 0xbe014ef5, 0xbd1cb8d9, 
    0xbe3c0c5e, 0x3e7ab77a, 0xbe5067b1, 0x3e36fab5, 0x3d77a540, 0xbe302cc3, 0x3d963150, 0xbe0df149, 
    0xbd4da568, 0x3e61c2ee, 0x3be48ce9, 0x3e695bed, 0xbe9d7d2d, 0xbe5f5d08, 0xbe750624, 0xbdc5bce1, 
    0x3e7de5cf, 0x3d9017b8, 0x3e2f524d, 0xbe040f66, 0xbe1c2faa, 0xbdf3260c, 0x3e127dd2, 0x3d8dd29c, 
    0x3e142ca4, 0xbea3ebdf, 0x3e8add1c, 0x3e8ab730, 0xbe4aca4a, 0x3dc13cb7, 0x3e7f0ede, 0xbe32d632, 
    0x3e8b7eb0, 0xbdf536af, 0xbd8f7a18, 0x3e2e8dbf, 0xbe673cf1, 0xbe95bacc, 0x3e90f470, 0xbd4ddd4f, 
    0xbeb59bf1, 0xbe736902, 0x3de1fdb3, 0xbe549edb, 0x3e117c21, 0xbeb365f3, 0xbdc8bb67, 0xbd8dc75b, 
    0x3d79eeba, 0xbe84b659, 0xbeb299b4, 0x3d24041e, 0x3d871f89, 0x3e064857, 0xbc9ae43f, 0xbdfe8b1d, 
    0xbdc6ac0c, 0x3eb8524d, 0x3cc6af41, 0xbc802ee2, 0xbea572b0, 0xbda646af, 0xbe5ea095, 0x3dc045eb, 
    0x3c796a14, 0xbea4ad08, 0xbe2b1ea7, 0x3e01dddf, 0x3ea988f4, 0xbda9a44b, 0x3ebb7ebc, 0x3e7f28e4, 
    0x3e8c4987, 0x3ebe798e, 0xbe931628, 0x3e473b8c, 0x3e80f0d5, 0xbe2f9ad2, 0xbe6f0af9, 0xbe939d14, 
    0xbdd6a643, 0x3dcd6d2b, 0x3e8acb92, 0xbdcc7886, 0x3e2cd00b, 0xbe8fd057, 0xbe82e7af, 0xbdd10af5, 
    0xbe53307e, 0x3e1ea95c, 0xbe7a049c, 0x3d02d57d, 0xbe84c410, 0xbe5febbd, 0xbddc695b, 0x3e38804c, 
    0xbe45a889, 0x3e0543b9, 0xbc5ac48f, 0xbde25b2d, 0xbe4b11ed, 0x3e886499, 0xbe148e45, 0x3e58e416, 
    0x3e608810, 0xbe0fcbfe, 0xbdb4c749, 0x3e32304f, 0xbd82db83, 0x3e502b0a, 0xbd62edfd, 0xbdb18d1a, 
    0xbe551d6b, 0xbaa0df2b, 0x3c31553a, 0x3e3a1202, 0xbdaa33fd, 0x3e10db25, 0xbdc71b6d, 0x3dea5dad, 
    0x3c91fb07, 0xbe654f00, 0xbe974d23, 0xbddf74da, 0x3ddf31ae, 0x3e8845b5, 0x3b8e650f, 0x3e8af916, 
    0x3e81d289, 0xbe9edd6f, 0xbe147a5f, 0xbe82fd4f, 0x3d4fe872, 0xbe2eca93, 0xbec2a24d, 0x3e4bef7f, 
    0xbe7d4a3e, 0xbe9817bf, 0x3e0192e2, 0xbeabaae7, 0x3e846791, 0x3eaa4d37, 0x3e2d6655, 0xbd04b002, 
    0x3d07532e, 0x3c7307c3, 0x3e8ac7c6, 0x3e52c0d8, 0xbc00f680, 0x3e48d6de, 0xbe996c36, 0x3dd2a863, 
    0xbdfbd0ce, 0xbe3f358c, 0xbd8db799, 0xbdc44b58, 0xbdd69303, 0xbc389dd8, 0xbbcfea9b, 0xbdbcff7b, 
    0xbe1da217, 0xbd9d0b65, 0xbdc4cdfd, 0xbdaa1f9d, 0xbc1f0b25, 0xbd921705, 0x3ce1d482, 0x3dca6b3a, 
    0xbdee0da0, 0xbd33518c, 0xbd7d3c76, 0x3d453b3b, 0xbdbb0d51, 0x3d0cfab9, 0xbd56ece7, 0xbdb45a37, 
    0xbd9d7e59, 0x3e3734f9, 0x3bc68cff, 0xbde92fd5, 0xbd862b17, 0xbe048c08, 0x3e022520, 0x3d7bac7d, 
    0xbe225f88, 0xbd2ac614, 0xbdc455d6, 0xbc95457b, 0xbc1aa31d, 0x3dff1f98, 0x3df62646, 0x3d6637a8, 
    0xbdaed369, 0xbed85dd1, 0xbeaf39fd, 0xbbdec950, 0x3e2c0685, 0x3dbc57f7, 0x3e9d56d6, 0x3e298264, 
    0x3d907caa, 0x3e91d952, 0xbe56a276, 0xbe8b2507, 0xbe502c04, 0x3e3cfeb8, 0x3ebe5e75, 0x3e80baaf, 
    0x3e1509a4, 0x3eca763c, 0xbd38077c, 0x3ecc18db, 0xbe4c802d, 0x3e8c6974, 0xbe18001e, 0x3ddd3a82, 
    0xbdf9eaef, 0xbdf6ab40, 0x3e9fdc70, 0xbe8b8b84, 0xbd948762, 0x3e659569, 0xbea97dc4, 0xbee9fecd, 
    0xbeba4e15, 0xbee4e4e6, 0x3ead64d4, 0xbe7d04dc, 0xbf0ad281, 0x3e9a8401, 0xbeaf1341, 0xbe31f7e1, 
    0xffffce3a, 0x00000004, 0x00003000, 0xbeffaf6e, 0xbf17c2ca, 0xbcfa7186, 0xbeb0b06a, 0xbe89ad21, 
    0x3d3eb4eb, 0x3f17060f, 0xbe871faa, 0xbee49d7d, 0x3ebb3dfb, 0xbf42573d, 0xbe8fdefd, 0xbf262f0f, 
    0xbe373471, 0xbe2cc9bc, 0x3f0a6542, 0x3d225eb1, 0xbe4093b0, 0xbed744a9, 0x3f02cb7c, 0x3df14476, 
    0x3e4d5ff6, 0xbebf3db0, 0x3ef749ae, 0x3f0d622d, 0x3ef4704e, 0x3ede299a, 0x3ec5ce6d, 0xbdfa3e65, 
    0x3f248505, 0x3f0dce91, 0x3ea816bd, 0xbe88fe45, 0x3cb32f72, 0x3eccf370, 0xbee4341b, 0x3e9b3606, 
    0x3d483035, 0xbe3f20a2, 0xbe3b47a0, 0xbf099c2f, 0xbed8c6e2, 0x3ea9c2b9, 0x3ebf6df3, 0x3e2a9721, 
    0xbe17cae3, 0x3e50cf2a, 0x3de399c2, 0xbd84beb2, 0xbe336a82, 0xbd8eef0b, 0x3de6a7f3, 0x3eb6ae44, 
    0xbe732a96, 0x3ebde61a, 0x3e170597, 0xbeab1c07, 0xbeab044f, 0x3ea14932, 0xbec7173a, 0xbecd3dc3, 
    0x3f0410e2, 0x3df5ca5c, 0xbf39217f, 0xbcc00c56, 0xbf3742fc, 0x3f3afea2, 0x3f0b3e4f, 0xbc43fbf2, 
    0xbc4b14ba, 0x3dd81dff, 0x3ec3b77e, 0x3e36435d, 0xbe341214, 0xbf44ee91, 0xbf216b75, 0xbee336a7, 
    0xbde726d1, 0x3e68cffb, 0xbdb5aadb, 0x3e9f0799, 0x3eb173d5, 0xbdb6bf4e, 0x3e9ff178, 0xbdd4d076, 
    0xbd89c486, 0x3e86d828, 0xbf16499b, 0x3f1b16cc, 0x3f31135c, 0xbec44c99, 0xbed4bb69, 0xbe24b599, 
    0x3ec002e8, 0x3f32a6b2, 0xbeba27cc, 0x3e06af26, 0xbee45459, 0x3e39a84f, 0xbdea116c, 0xbe8dc7f9, 
    0xbdf26272, 0xbd31b93c, 0x3e84f70c, 0x3efadc8b, 0x3ee08c82, 0xbd6c03a9, 0xbdf9e823, 0xbeb6553b, 
    0xbf468444, 0xbe3ec012, 0xbefed056, 0xbe1dc38c, 0x3e38b4dd, 0x3e5f391a, 0xbf090db7, 0x3d49b8c0, 
    0x3e90e9a8, 0xbf3a9cdd, 0x3d4fda2a, 0x3e8ee6a2, 0x3d9668a8, 0x3d96564d, 0x3dcd7ed2, 0xbf272c35, 
    0x3e81cb2e, 0x3dcc53e2, 0xbd0677b2, 0xbeff6c46, 0xbee9bbae, 0xbdd1dcb7, 0x3ed097c3, 0xbdab5431, 
    0xbe7b6801, 0xbe71e051, 0x3d819623, 0x3ad826c4, 0x3ec050fc, 0x3f1c4729, 0x3f00b6f7, 0xbe21fd1e, 
    0xbe9b5ea1, 0xbe84fad6, 0xbe994039, 0xbf25e346, 0x3e66d471, 0xbd4af117, 0x3e698202, 0xbf209f93, 
    0xbedf8639, 0x3e4a9f1a, 0xbe99b99e, 0xbeb9a2f9, 0x3e31ac59, 0x3ed4dae9, 0xbe989b3e, 0xbf2ac10d, 
    0x3dbf23dc, 0xbdc579bd, 0xbf1441d1, 0x3ea99b7d, 0x3d7fd6ef, 0x3e26d5e2, 0xbea7c083, 0x3f022e0b, 
    0xbdd2af41, 0xbf1eb08c, 0x3d8cb18d, 0xbe4d6f7e, 0x3e62fdb6, 0x3f09c3b0, 0xbf14efd0, 0x3f11d23a, 
    0xbf0678f3, 0x3e90de60, 0x3f0dc175, 0x3bd82ced, 0x3e835d47, 0xbe8012ea, 0x3db28cdf, 0xbebc2bc5, 
    0x3e2dfa32, 0x3e84fb60, 0x3e98aeef, 0xbe003a5d, 0xbe751513, 0xbed68a04, 0xbeb8d951, 0xbecb30bf, 
    0x3eae3bcf, 0xbd347996, 0x3df54d30, 0x3e1e90cf, 0x3f133413, 0x3ed00ce5, 0x3e658ddf, 0x3d8b34ca, 
    0x3e999204, 0xbe146fbd, 0x3d1b3713, 0xbec17497, 0xbd4631e6, 0xbee29d30, 0xbf02f639, 0x3e3c5a84, 
    0xbe6af623, 0xbde8eaea, 0xbe9ca8d8, 0x3e60ef01, 0xbe7d8169, 0xbe9e0910, 0x3e326a03, 0x3ef67aff, 
    0x3ea96e47, 0x3d4edcf5, 0xbea7efa1, 0xbed072c4, 0x3daefdf6, 0xbe0e87d0, 0x3d5f4871, 0x3e8516ca, 
    0xbee11592, 0xbe96b224, 0x3db43efc, 0xbd709ef1, 0x3e26a7f0, 0x3f19f124, 0xbedbd321, 0x3e08c408, 
    0x3e470f59, 0x3da6266d, 0xbee3beac, 0x3eea7470, 0xbea00f26, 0xbf07848e, 0xbe48ba67, 0xbd91b539, 
    0xbe67bf2c, 0xbdb65424, 0x3ecf9f10, 0xbe7a3c69, 0xbe3daa22, 0xbe8f01b7, 0xbeb45558, 0x3e4a6489, 
    0xbe51ea45, 0xbdad3f40, 0x3ef3dcba, 0xbd9b1d12, 0x3d8235de, 0x3dea96ce, 0x3d88c53b, 0xbe4f723f, 
    0x3e63b8cd, 0xbf01ed52, 0x3efe58e2, 0x3e7413e2, 0x3f0b34dd, 0x3e91b837, 0xbcfe4cd1, 0xbcff01cb, 
    0x3da0db4d, 0x3e51faf7, 0xbcbf5417, 0x3eafaccf, 0x3e4bea38, 0xbf02f0ca, 0xbeec0731, 0xbf022138, 
    0x3f15bc5e, 0xbe3fe499, 0x3e924e9f, 0xbdd13d64, 0xbe628918, 0x3d100d03, 0xbcbb734d, 0x3d3f771d, 
    0x3ed0ed15, 0xbd729d5a, 0xbdbf0e82, 0xbb1f91c1, 0xbe24002b, 0xbe26740b, 0xbea65dd6, 0xbeb916db, 
    0xbee0f0c1, 0xbee11604, 0x3e463b7c, 0xbe7d6980, 0xbee83c6e, 0xbe667261, 0x3ded0829, 0xbca2641d, 
    0xbec365d5, 0xbcf2706f, 0x3e746069, 0xbe5c2ba2, 0x3da00685, 0x3dc5d25f, 0xbe256da5, 0x3ead5e3e, 
    0xbe1fd59c, 0xbdfda5c0, 0xbdc2a3b9, 0x3e004abf, 0x3ea0b92c, 0xbdf4013a, 0xbdc542d7, 0x3e5a6770, 
    0x3e2c2853, 0xbe57fcf6, 0xbeac3bf5, 0x3ea532b7, 0x3e4fb525, 0xbdf1dc8b, 0x3ee99936, 0xbe7bfa55, 
    0xbe2e4cf3, 0xbe66c03b, 0xbe9cbe8d, 0xbe73d15d, 0x3da08f47, 0x3e684d31, 0xbcb6b077, 0xbe6075b5, 
    0x3c06a5f6, 0xbeb37f01, 0xbe54ace7, 0xbe271901, 0xbe8e6763, 0xbe341158, 0xbe291805, 0x3e5f0d54, 
    0xbccef170, 0xbe96a961, 0x3ddea9d0, 0xbef4a0f0, 0x3e2c0679, 0x3bf6187d, 0x3d84b95c, 0x3ea7954f, 
    0xbeb92a87, 0xbea66e41, 0xbe1766c0, 0xbc337b61, 0xbde6bfb3, 0x3df28d7b, 0xbdbead4c, 0xbe44e987, 
    0x3ddc1ed4, 0xbdb42351, 0xbe0e058d, 0x3e224ad3, 0x3ce1a8ff, 0xbbd808f3, 0xbe60675d, 0xbd701d01, 
    0xbebaca7e, 0x3cbda8d3, 0xbcf8b428, 0xbc71ea82, 0xbe986d81, 0x3e7b50fc, 0x3e9c790c, 0xbdc8765c, 
    0x3e52607d, 0xbe322a17, 0x39f715c3, 0xbe5621b5, 0x3e694733, 0xbea74d00, 0x3efcc3c8, 0x3e9c1b2f, 
    0x3e2b91cd, 0xbe4bb78e, 0xbe4cf275, 0x3e990fdb, 0xbe0779e0, 0x3edb4c97, 0x3d9e87b8, 0x3d8b8899, 
    0xbc3f0d65, 0xbe9a987a, 0xbf0c3ef2, 0xbee0e3c5, 0x3df23c99, 0x3e6844e9, 0x3e7a5bd8, 0xbec4455f, 
    0x3ea65278, 0x3ea83524, 0xbe1a1d79, 0xbc49cc35, 0xbe9f47bc, 0xbeb2479d, 0xbedba9c1, 0xbf13a628, 
    0x3ef3c831, 0x3d19e8d8, 0x3e597f0c, 0x3f0966c7, 0x3e89a9d7, 0xbe6d82ca, 0x3e356ee4, 0xbe908539, 
    0xbd1f2fba, 0x3f023c1b, 0xbd45eaa6, 0x3dd1ca36, 0x3bc359c3, 0x3d9ec3c2, 0x3deab6c8, 0xbb647a9c, 
    0xbf14e3ef, 0xbf3c5c47, 0xbd048720, 0xbe7a976d, 0x3e97abb5, 0x3f0acc29, 0xbf1bcafb, 0xbed9f2dd, 
    0x3e78dfbd, 0x3dc2de00, 0xbd32a51c, 0x3f0ed9dc, 0xbf1ac18e, 0x3e5555b4, 0xbf078d75, 0x3e9f1138, 
    0x3e162a22, 0xbeaf8549, 0x3f3d51d5, 0xbeef3b04, 0x3f111d07, 0xbebecd3c, 0x3d08232c, 0x3ea4bb4d, 
    0x3ee26fe1, 0xbe332746, 0x3cc9f1b6, 0xbeef3324, 0xbd95a5e3, 0x3df2a131, 0xbec59996, 0x3e86102c, 
    0xbd8c6a0b, 0x3e5dfe1f, 0x3e7af05f, 0x3d03eb64, 0xbecde372, 0xbea284de, 0x3e87dee9, 0xbe0fbcf1, 
    0xbe228fc8, 0x3eb74edf, 0x38c2c796, 0xbbe10cdb, 0x3dd669b3, 0xbe9f04a7, 0xbdcaeb1e, 0xbeb26b3b, 
    0x3da59f43, 0xbe801b77, 0xbdb0c2a6, 0xbda0e155, 0x3e10eee8, 0xbd81a30e, 0xbe6693e7, 0xbdcb7057, 
    0x3dab41c9, 0x3f011697, 0xbc27cbea, 0x3e9eeffd, 0x3eb0b9eb, 0xbe048a0c, 0x3d0651f7, 0x3ef17f77, 
    0xbea49317, 0xbf036b85, 0xbed5c2c0, 0xbcf0d7e8, 0xbb84c1a4, 0xbe3e1e0f, 0x3dbb652b, 0x3e64ce71, 
    0xbe8194c2, 0x3e0648a6, 0x3e6ba365, 0x3e5bd14c, 0x3d642c63, 0xbd66a5b5, 0x3e376853, 0x3dea560d, 
    0x3e04f663, 0xbd5e491c, 0xbe0d54cc, 0x3c9abaeb, 0xbcbd6e57, 0xbe33c4f9, 0xbe46742b, 0xbbc1d992, 
    0xbe94f524, 0xbeba1796, 0x3e330567, 0x3e99183c, 0xbec4bf01, 0xbe0fc7ef, 0xbe22291a, 0xbc72ce02, 
    0x3dbef1a2, 0x3cbb5e45, 0x3d5c5326, 0x3db0c8d8, 0x3e8a0332, 0x3e28b1bc, 0xbe98f3a8, 0x3e3c9d45, 
    0xbd573070, 0x3daea5bc, 0xbd92cfc3, 0xbe939e77, 0x3c9880c6, 0x3ec99119, 0xbe97a17a, 0x3e14cd1f, 
    0xbc827d13, 0xbe47bbd9, 0xbcd833b2, 0xbe3072eb, 0x3db88f16, 0xbd6fb02e, 0xbe307b5f, 0x3e4381c8, 
    0xbdb0b43c, 0xbd98c718, 0xbdb03e3d, 0xbc7c7387, 0xbe6dac31, 0xbd1673ac, 0xbe6dadbe, 0x3db65626, 
    0xbd13424e, 0x3e296d57, 0x3e197982, 0x3e80d802, 0x3dbe3143, 0xbdd8768a, 0x3e5ccd65, 0xbc36821d, 
    0x3de90614, 0x3cfc2451, 0xbe33fcf3, 0xbddeefb6, 0x3cda6caf, 0x3e402046, 0xbe68756a, 0x3e1c9990, 
    0xbd8a064c, 0xbd336841, 0xbe763b75, 0xbe6da11a, 0x3ccc00a1, 0x3e26792c, 0xbdb3d98e, 0xbe0526b8, 
    0x3e0dc1c9, 0x3dac321e, 0x3e16a352, 0x3e003eb0, 0x3e32b480, 0x3e12df79, 0x3c147690, 0xbe524e7f, 
    0x3e3303df, 0x3db3e156, 0xbe36efb1, 0x3e99accf, 0xbdb96a25, 0xbdff5458, 0xbe005c87, 0xbf23baad, 
    0x3e258d53, 0xbd7c2c6a, 0xbe89db71, 0xbe4f074a, 0xbd72eef6, 0x3d9385d6, 0xbeb26d66, 0x3ead6cc2, 
    0x3e80139d, 0xbe2da9c3, 0x3e80feed, 0xbe52f68c, 0xbe702923, 0x3e3e8a25, 0xbe55b48e, 0x3ecc1084, 
    0x3d14fe11, 0x3cc233f2, 0xbe286700, 0x3ed28483, 0xbd1128a8, 0xbe644ce6, 0x3e321a26, 0xbee2e661, 
    0xbe013855, 0x3d7abddd, 0xbd9b1747, 0xb9f315b3, 0x3e54a139, 0x3e9c6c6a, 0xbd3def98, 0xbeb3c10d, 
    0x3d18bf00, 0xbe38c8a6, 0x3d47b760, 0x3d8c1cc4, 0xbe131ff1, 0xbe14f62e, 0x3e0ed03d, 0xbd37c819, 
    0x3c611554, 0xbe91ba91, 0x3e6a8c58, 0xbeb36cfc, 0x3e8c4928, 0x3e844e8a, 0x3e9e3caf, 0x3f0cb2aa, 
    0xbf023b6a, 0xbe4e1ff8, 0xbe98f51b, 0x3f10289e, 0x3ec9a331, 0xbd3d6611, 0x3eaef111, 0x3e990d68, 
    0xbdf332c8, 0xbe8f51ce, 0xbdfb4fdc, 0xbea5ab5b, 0xbc47dd6b, 0xbe78b81b, 0x3d2437b6, 0xbe1d90f2, 
    0x3d81f2a8, 0x3e5f2c00, 0x3ea8a8b9, 0x3d04071b, 0x3c82f902, 0xbbfbc842, 0x3e9bd7ac, 0xbc4f4622, 
    0xbed3fedb, 0xbed07835, 0x3ec46048, 0xbd523826, 0xbe853125, 0xbe9bcc22, 0xbc8c4f88, 0x3d88a04a, 
    0x3e23f88c, 0x3e9027df, 0x3eec9764, 0xbe85f1f7, 0x3d78606f, 0x3dafbdc7, 0x3edb2deb, 0x3da83831, 
    0xbe9bf8e8, 0xbe45df6e, 0xbe7679b5, 0xbe99db84, 0xbd8cb9e2, 0x3e54100e, 0xbe82811b, 0x3dcbf341, 
    0x3eca53e7, 0xbcd00779, 0x3e3970b9, 0xbeb6adf6, 0xbe98be09, 0x3eaee883, 0x3da251d4, 0x3f158f46, 
    0xbe6fad12, 0xbcfb0724, 0x3e90c274, 0xbd9c8b18, 0xbe0ecb6f, 0x3e5bff06, 0x3eb4d79f, 0x3ed041b1, 
    0x3e924b82, 0xbe1e6332, 0xbe52a209, 0xbe2188cd, 0xbd35f657, 0x3e790905, 0x3e86e3ef, 0x3d7c81ee, 
    0xbe16c51b, 0xbe019544, 0xbe833816, 0x3ecf3584, 0xbe1896bd, 0x3e1f29bf, 0xbec96bed, 0xbe12baaf, 
    0x3d8e1774, 0x3e5912f7, 0x3dc14a4b, 0xbe0ce644, 0xbed22b08, 0xbeb018d1, 0xbebe4950, 0xbe04551c, 
    0x3e2272c8, 0x3c61505f, 0x3e9fc1e2, 0x3de1746c, 0x3f005122, 0x3dfa6a74, 0xbe1ece40, 0x3f0beea4, 
    0x3e537bcf, 0xbd0e0be4, 0x3e82f076, 0xbec6d8a1, 0xbf1bd4f5, 0xbe0913ce, 0xbe6bf9e0, 0xbe9b9c63, 
    0x3e947d4f, 0xbe3f97c5, 0x3eeb40ac, 0xbd822486, 0xbdb3cc0d, 0x3ee709e4, 0xbe863a17, 0x3d6a9b22, 
    0x3e44de0b, 0xbd521fd3, 0x3e0af4a6, 0xbe25dddb, 0xbd7d6d08, 0x3d1d74fd, 0x3e874b5d, 0x3e8a7141, 
    0xbe56491a, 0x3e8756c4, 0x3e78a7fa, 0x3e20a08b, 0xbe9f327f, 0xbeaa4eaa, 0x3e822101, 0x3e0c08fb, 
    0x3d4e4237, 0xbe311608, 0x3e230722, 0x3e62003c, 0xbf000c5a, 0xbec305ab, 0xbe2d9638, 0xbea2a39b, 
    0x3bbc15c6, 0xbeb37266, 0x3eb8146f, 0xbe257b0b, 0x3dbaf861, 0xbea3c53a, 0x3e8684ff, 0xbf12bdc9, 
    0x3bbc6a7d, 0xbe88d075, 0x3f07671c, 0x3d6db2da, 0xbe6be18c, 0x3e36bcc1, 0x3e8fd99f, 0x3ef6587d, 
    0xbb9c43ac, 0x3eb1a372, 0x3eaaaca6, 0xbdf46614, 0xbe9ea725, 0x3e8a0534, 0xbeb3bb00, 0x3e7f1e81, 
    0x3e1008f3, 0x3ef129cd, 0x3f04c80b, 0x3d450982, 0x3da08a4c, 0xbd197b38, 0xbd44c51f, 0xbebd1af0, 
    0xbdc82f5f, 0xbe7eccfe, 0x3e5b562c, 0x3ea06a2c, 0x3d344a05, 0x3e8f63bd, 0x3e8b1dfd, 0x3e8e63c8, 
    0xbd9a7a26, 0xbec0d765, 0x3ef80db2, 0xbdd33efe, 0xbef08449, 0xbe3c9791, 0xbecbb91c, 0xbda7277b, 
    0xbe9079e8, 0xbee0f674, 0xbea2517a, 0xbdf951ab, 0xbdcf2bf0, 0x3f00d7bd, 0x3eb8d3d0, 0xbe8caf19, 
    0xbe42c4ab, 0x3ec0de22, 0x3e975ed6, 0x3d275588, 0xbed4562f, 0xbb8f1db2, 0x3ece1670, 0xbeadfc53, 
    0x3e8074b1, 0x3eac4928, 0x3e0340e3, 0xbe8193f8, 0x3eb5514f, 0x3ecaa533, 0xbe9e017e, 0x3e32656e, 
    0xbedf2906, 0x3ed6d8e9, 0xbc39f32e, 0x3ea51a64, 0x3e83e269, 0x3eacfb36, 0xbea87fac, 0x3ee87973, 
    0xbe8ab6bd, 0x3e8de7e6, 0xbe7f3158, 0x3e9bf665, 0x3c07b414, 0x3ebfc4e5, 0xbec9035a, 0xbde244e6, 
    0xbe57a8ee, 0x3e881d22, 0xbe6332e0, 0xbe6714fd, 0x3e841467, 0x3f072216, 0x3ed0afef, 0x3e0a048e, 
    0x3ee05955, 0x3defd4c1, 0xbe9e7b10, 0xbf2747d8, 0x3eb3cc5b, 0xbdffac09, 0x3ed5047d, 0xbe038e9f, 
    0xbe8d7639, 0xbc84ddf6, 0x3df6266b, 0x3eb07581, 0x3efab802, 0xbe497c0e, 0xbed7ae18, 0x3e3f1107, 
    0x3e8138c0, 0x3e6687da, 0x3d6f75dd, 0xbf07eb05, 0xbebebfb6, 0xbe6be876, 0xbee16130, 0x3ed192df, 
    0xbe6ee7c4, 0x3e5f318b, 0x3d8f8e76, 0xbcd2cce4, 0x3e883f0d, 0x3f346735, 0x3f12f11c, 0xbe7b7ffe, 
    0x3e24a2c7, 0x3aece6d4, 0xbe2dbdfa, 0xbf06b971, 0x3f0aaa3d, 0xbead90b8, 0x3f0be936, 0x3c86528e, 
    0xbef81c18, 0x3ea7271c, 0x3f6813c5, 0x3e09527e, 0xbeb211a6, 0xbcabdc5d, 0xbeab9953, 0x3e5ec38e, 
    0xbe5d2c10, 0x3d933b3e, 0x3c72eb63, 0x3e3f3708, 0x3f024302, 0x3f171486, 0xbde8d0b5, 0x3e7238f9, 
    0xbe08c881, 0xbf08de8c, 0x3daea6ef, 0x3f088e06, 0x3bb7ba92, 0xbed9f564, 0xbdc6b510, 0x3efc091d, 
    0x3e4687c3, 0xbdb2b81c, 0x3ea51052, 0x3d9dfe7f, 0x3d7ebd81, 0x3ec82f78, 0x3e7c8081, 0xbee827c0, 
    0xbdb52002, 0xbdb2db73, 0xbe83ee60, 0x3ed04bb3, 0xbe9affb5, 0x3e77bf83, 0xbe96ada2, 0x3d635b50, 
    0xbeb48dda, 0x3da3320c, 0x3ef39965, 0xbd427d31, 0xbe1789b7, 0xbeda00f4, 0xbeca5914, 0x3e7e3d25, 
    0xbf37e355, 0xbed18de9, 0xbe6f8581, 0xbd0aa0ad, 0x3f253dce, 0x3f16b407, 0x3e7cdaa4, 0x3f2f26b4, 
    0x3a023d1f, 0x3f54d59f, 0x3e5ed096, 0xbe8199e6, 0xbe51c638, 0x3e34f33c, 0xbed5227e, 0x3e506e9a, 
    0xbcd2e77a, 0x3ef00bf4, 0x3f05c9c7, 0xbeb052d9, 0xbdfaae07, 0xbee3e38b, 0xbe576917, 0x3ef5a5da, 
    0x3e7a0c07, 0x3f0ba422, 0x3e08cbf8, 0x3eca9018, 0x3eda3171, 0x3e6ba69f, 0x3e3780a4, 0x3ec7813f, 
    0x3e5f62c9, 0x3d0676a8, 0x3f0f2f41, 0x3e66a77c, 0xbf28b31f, 0xbe99494f, 0x3dc289e4, 0x3e0eb773, 
    0x3f492999, 0x3eec2e51, 0xbd8817c6, 0x3de64469, 0x3eed56c1, 0x3ef5ae3a, 0xbe61ce95, 0xbe89a9b5, 
    0xbeae2f6d, 0x3ef26c19, 0x3e018af3, 0x3e141975, 0xbe091c80, 0x3e94909d, 0x3defb6dd, 0x3d82f9cd, 
    0x3df5a980, 0x3e0fbd19, 0xbe8b8019, 0x3e7010d0, 0xbeb05f69, 0x3ea2c14c, 0xbc5c7e8f, 0xbeae6b4b, 
    0x3e83f250, 0x3ebae887, 0x3f314f14, 0xbd8221ba, 0x3ee6ed6a, 0x3ddc481a, 0xbe739348, 0xbe376955, 
    0xbea6b0f4, 0xbe43de0b, 0xbe98ab0f, 0x3ef4bb46, 0xbe9203a4, 0x3e5f9f7e, 0x3ed79e18, 0x3ea9b0d4, 
    0xbe9af55f, 0xbe9dc6b3, 0x3f357ff8, 0xbe04a7f4, 0xbdd6a5ff, 0xbf20623d, 0x3e20248e, 0x3ed6f6c1, 
    0xbdf9bd68, 0x3ef8bb64, 0x3ecc56fd, 0xbe3c7b9a, 0xbe7f6416, 0x3bfc3e9a, 0xbe895ef9, 0x3e4896c2, 
    0xbebd9027, 0xbe9d298b, 0xbeda2516, 0x3db8ccab, 0xbee4a90d, 0x3e9e4e7a, 0x3e60878b, 0x3f18b22e, 
    0x3ef8bac9, 0xbda3b8ac, 0x3eec8d34, 0x3e305367, 0x3dde24ce, 0x3eab3003, 0xbe952470, 0xbeeee5ed, 
    0x3e9fd1bf, 0x3d59ebed, 0x3e12d5a1, 0x3db3f0c0, 0x3e7f4cdb, 0xbe59c8a9, 0x3ee1a062, 0x3e985b31, 
    0xbdf2e199, 0x3cb53217, 0xbe37c943, 0x3e7ed575, 0x3eba916c, 0x3f0a582b, 0x3decb587, 0x3e421b87, 
    0xbd918226, 0x3e60aa44, 0xbe2ea50a, 0xbe002b43, 0x3ea4f2c9, 0x3e9178e2, 0x3ec7ba37, 0xbea04fc7, 
    0xbe342c45, 0xbe48e70b, 0xbedd9759, 0x3e91405a, 0xbe3db180, 0xbe3f4cc2, 0xbe9aaeb6, 0x3e01c0dd, 
    0x3bdaa854, 0xbe173441, 0x3ea03678, 0xbee2801f, 0x3e3f9f91, 0x3e7c26be, 0xbe62c7c7, 0xbe9d6a8d, 
    0x3d854a59, 0x3ea8e5c8, 0x3e82eb67, 0x3deea310, 0x3ecd27c7, 0xbea61672, 0x3e1000eb, 0x3eba0303, 
    0xbe72f1ab, 0xbdd0148b, 0x3ea69568, 0xbe26e3e2, 0xbdd92274, 0x3e50f144, 0xbdf9859a, 0x3e483e4b, 
    0xbe2bf34a, 0x3e3ec9af, 0xbe43f48f, 0xbec7bbc4, 0x3e216177, 0x3e829497, 0x3eb1b11c, 0xbebbb909, 
    0x3ec62bad, 0xbe8d0d82, 0x3e81ebbc, 0xbe9593a7, 0x3ebc5888, 0x3ecaab27, 0xbe9e9b3a, 0x3e85047d, 
    0xbee2689c, 0xbeac42c1, 0x3e035845, 0xbe3d7dea, 0xbe409ab7, 0x3dbe86dc, 0xbdd2a170, 0x3eec2133, 
    0x3e694358, 0xbc65446a, 0x3d6d7ea1, 0x3e91db05, 0xbd375758, 0x3e73718c, 0x3e8800fd, 0x3cacb188, 
    0xbc6dbaea, 0x3d7a8d5f, 0x3dfd22c2, 0x3d252819, 0x3eafc7c4, 0x3f03c968, 0xbf05c7da, 0xbcc2a8c9, 
    0x3e6c891f, 0x3e82d945, 0x3e59a5cd, 0x3e91aaa8, 0x3ea7db0c, 0xbf15dfdc, 0xbd33b50d, 0x3e6a0ce5, 
    0x3e66317c, 0xbe9f0772, 0x3e2a3bb7, 0x3e6a732e, 0xbef68f10, 0x3e5eaa34, 0x3ec05998, 0x3e5af336, 
    0xbf33a655, 0x3d8f8c48, 0x3dfc37d8, 0xbdb07dfa, 0xbdaf000b, 0xbe0dba60, 0x3ed08dea, 0x3da3373c, 
    0x3f4c5c3b, 0xbf10e4e7, 0xbe9f6c76, 0x3ebbfd28, 0x3ddeb825, 0xbe5e646c, 0xbdbd8d2f, 0x3ed26a57, 
    0xbed8ed72, 0xbe811b64, 0x3d79fa0d, 0x3eec2d3b, 0xbed5fa2f, 0x3e9c6bbf, 0x3ed68264, 0xbe818902, 
    0xbd034d98, 0xbe855654, 0xbebae276, 0x3e82c00a, 0x3eb6c045, 0xbe937730, 0xbe32d8da, 0x3ecaa6ca, 
    0x3ec36acf, 0xbe0b9d33, 0x3eaf93e5, 0x3ead6e91, 0xbe4b920e, 0xbcf89b24, 0x3eb07932, 0x3ee906c3, 
    0x3f14e1a7, 0x3f025b73, 0xbe0cd6b9, 0x3ec09b4d, 0x3f1f1902, 0x3ec4bcd8, 0x3ea32e7e, 0x3e7af77c, 
    0xbebb6d88, 0x3f034db8, 0x3e90dfd1, 0xbe7981f5, 0x3eda6d9a, 0xbdde5517, 0xbc7c191c, 0x3f000266, 
    0x3ec25bb1, 0xbe1b06b0, 0xbeb4851d, 0x3e005b7e, 0xbe50eb52, 0xbd449863, 0xbd9bb8cf, 0xbef0a975, 
    0xbdfff21d, 0xbe887c8d, 0xbe5d7591, 0x3e1576d2, 0xbdfa3bab, 0xbd54345d, 0xbe143838, 0xbe352c10, 
    0x3f499f99, 0xbed19f5f, 0x3e4d5cb9, 0x3c82674c, 0xbddc14f2, 0x3e798302, 0x3cd93e22, 0x3ead51cc, 
    0x3e45e074, 0x3ea7d76c, 0xbdc3e6bb, 0x3e3bde91, 0xbe9ae6e0, 0x3dbabe71, 0xbd90b89f, 0xbdcfad42, 
    0xbe6aa723, 0x3cd660b0, 0x3e153549, 0xbddff0f0, 0x3e8c2e57, 0x3e52cd91, 0x3bfede5d, 0x3ede9b18, 
    0xbe851955, 0x3d75d998, 0x3e975432, 0x3d2da5a1, 0xbd1c8e32, 0xbdea708f, 0xbd35eb89, 0x3ea3ba8a, 
    0xbdb8e6d3, 0xbe4dd45b, 0x3c399c5f, 0x3e1188fe, 0x3ec0e5d6, 0x3ee47594, 0xbe8eb0fe, 0xbe79fca2, 
    0xbe9e65a1, 0x3dbc66f7, 0x3df5e62b, 0xbe39b372, 0xbcbc23e6, 0x3ea1930d, 0xbcbf270e, 0x3eacb54b, 
    0xbe29fba5, 0xbe2528bf, 0xbe1a076f, 0xbe8af54c, 0x3e7cd438, 0xbdc2fa11, 0xbeaba6d6, 0x3e235dcd, 
    0x3dd1d6cb, 0x3ebc5da7, 0x3edf6441, 0x3d216a29, 0xbea13f7a, 0x3e769d54, 0x3c156ac7, 0xbe130915, 
    0xbd6709a6, 0xbe478e9b, 0x3d89a665, 0xbddea6b2, 0xbe4f2bc3, 0x3deb9e76, 0x3e1364c2, 0x3d0cecc2, 
    0xbd9d53fb, 0x3ea9920a, 0xbe9544ef, 0xbe98cf7e, 0xbe10cd63, 0x3eea1c5c, 0x3d92bc2a, 0xbe2ad6bc, 
    0xbd9fbc07, 0x3e4e343d, 0x3ea3dd64, 0x3eadcf4d, 0x3e9f1fa8, 0xbe4b922a, 0xbdc3f3fb, 0x3e1c155c, 
    0xbe043906, 0x3d85704a, 0x3f097632, 0x3e49ef85, 0xbe43d7bc, 0xbec22048, 0xbe83ca69, 0x3de26c2c, 
    0x3e9722d1, 0x3e648b06, 0x3e22ddee, 0x3ca41fb1, 0xbcf9567d, 0x3e3100e2, 0x3e812828, 0x3dfbc9b2, 
    0x3e5b6b6a, 0x3deadf4a, 0x3e7c09c1, 0xbe5ebee8, 0x3e90cde4, 0xbe4e0294, 0xbdf470cd, 0x3e776135, 
    0x3e6f8e66, 0xbd722631, 0xbea14690, 0xbebfb62a, 0xbf027e50, 0x3ddd9f09, 0x3eb7137d, 0x3eae6496, 
    0x3e07f5d6, 0x3d9f095a, 0xbe3ef577, 0x3e04cdf8, 0xbef85092, 0x3e3fe899, 0xbc66dfa9, 0x3ea3caf5, 
    0xbe97931f, 0xbe214e57, 0xbe8ae668, 0x3ea5447b, 0x3ecc0f0a, 0x3e2684d1, 0xbdd90eed, 0x3eb684d9, 
    0x3e5c5e2c, 0x3e0791d2, 0x3dc01440, 0xbe9ed8c8, 0x3e8f8f92, 0x3eb7a6e9, 0xbe1b2d8b, 0x3ea2b96e, 
    0xbe807e79, 0xbe25de6e, 0xbeb55386, 0x3e37598d, 0x3e19b2f0, 0x3e1f0c5b, 0x3e1922e0, 0xbe975e9c, 
    0xbe77cb44, 0xbe703041, 0xbe472348, 0xbf054002, 0xbee466f3, 0xbd4d26b6, 0x3e6077c7, 0xbe572223, 
    0xbe8b2385, 0xbe462aca, 0xbe983d70, 0xbe93b5fa, 0x3e9d5d1a, 0xbe43d016, 0x3e934a93, 0x3eb1761d, 
    0xbe327396, 0x3e63ac9b, 0x3e83808f, 0xbe272776, 0xbe298050, 0x3ed9792e, 0x3d79fa9d, 0xbe1f5715, 
    0x3dbb5dde, 0xbe5a3f85, 0x3e978291, 0xbd3d2c05, 0x3e63e28a, 0x3e08dc43, 0x3ecb411c, 0x3d920c4d, 
    0xbd2241bf, 0x3e8217ae, 0xbc46093c, 0xbe9ce216, 0xbc804dea, 0xbedabcfc, 0xbe549881, 0xbe214d86, 
    0x3e285c32, 0xbe8749e3, 0x3d404228, 0x3e8b99aa, 0x3e9259d0, 0x3d5568b6, 0xbe37f768, 0x3dc0ee85, 
    0x3e3441c1, 0xbe843a58, 0x3defda08, 0x3eae7479, 0xbe1b185e, 0x3e8a405a, 0xbbc2d068, 0x3da97e93, 
    0x3e64390e, 0x3ea4edb7, 0xbe1fc37f, 0xbe8110ee, 0xbea6261a, 0xbe3fb70a, 0xbda5b08d, 0xbe26b6f5, 
    0x3e89f161, 0x3e6f745b, 0xbdb8f300, 0xbe36cbcf, 0x3e2e1a40, 0xbe495cd4, 0xbea17547, 0x3d66e08f, 
    0xbcf2a4ea, 0xbe92df95, 0xbd8e56ab, 0x3e84ada4, 0xbe13b303, 0x3e6eff4c, 0xbe93fbfe, 0x3eb6e888, 
    0x3e24e925, 0xbd9e0562, 0xbe0fdf46, 0x3e0599f9, 0x3d1f99b1, 0xbe2cf928, 0x3e33e855, 0xbe83fb86, 
    0xbdf49e71, 0x3de085c6, 0xbe9edfb8, 0x3e71c1d4, 0x3be56d79, 0xbe9e20b3, 0x3df3b6a0, 0xbeac367a, 
    0x3e51cb7d, 0x3ebe02e6, 0xbed07c6f, 0xbd831dea, 0xbd212a88, 0xbe9e63ad, 0xbced0769, 0x3d5b58fb, 
    0x3e3d0ebd, 0xbe4900dd, 0xbdade461, 0x3e5b711f, 0x3e285717, 0x3de18b4e, 0x3d96c080, 0x3e9a548c, 
    0x3dd16ee8, 0xbe633fd3, 0xbda50de3, 0x3e7d4ec0, 0xbecca1b6, 0x3e8c43c8, 0xbeb415b7, 0xbe8155d8, 
    0x3eb1511a, 0xbea5e709, 0x3e7bc721, 0x3e7dc2c7, 0xbe3239d3, 0xbe3d2b4f, 0x3e12bef2, 0xbe3f198b, 
    0xbe5ccb4c, 0x3e44f1ed, 0xbdef68f1, 0xbc84b943, 0x3e0d264a, 0xbe2fb66b, 0x3e47a6f0, 0x3dfa6048, 
    0x3e2e16fd, 0x3daf49c2, 0xbc902242, 0xbe1226fd, 0x3e40e91f, 0xbcf65f05, 0xbe131a2a, 0x3f0d48a3, 
    0xbf088606, 0x3eae4171, 0x3f314458, 0xbea422c1, 0x3f17fee3, 0x3eb663d7, 0x3f158c7e, 0xbe71b81d, 
    0x3dbe029e, 0x3ea30a08, 0xbdc5b497, 0x3f100aad, 0xbf0b0fba, 0x3de3d64d, 0xbf19984e, 0x3e0e5b15, 
    0x3f24f62e, 0x3f43d8fc, 0xbf0feab8, 0x3d63e3f6, 0x3e2dba0b, 0xbee5a19d, 0xbed53da6, 0x3e96c4b7, 
    0x3eafda24, 0x3efaac4f, 0xbebef1fd, 0xbde01e53, 0x3f374984, 0xbd99fd92, 0x3eb17afe, 0x3ef130bc, 
    0xbf072808, 0x3e5d7eb4, 0x3f3cb9ae, 0x3f148481, 0xbda1bdfe, 0xbe57f039, 0xbbb6e6ea, 0xbd1fe6e3, 
    0xbeeb2321, 0xbed960d0, 0xbf0febca, 0xbebce693, 0x3eaf5713, 0xbdf6bb7e, 0x3f18c7bc, 0xbe1b42f3, 
    0xbf2caaf7, 0xbeea6a66, 0xbe2c995c, 0x3f223b41, 0xbd8b8bf3, 0x3e216fd2, 0xbeeccfd8, 0xbe1510a3, 
    0x3f027ba0, 0xbef1d2eb, 0x3e7268e0, 0x3ea004dc, 0x3ce7f25f, 0x3e2a5438, 0xbdbcc9be, 0x3e9fc10b, 
    0x3e0f739c, 0xbf096e08, 0x3e838836, 0x3f0ddbe9, 0xbe3563ee, 0x3f26b464, 0x3edcb7c8, 0x3ec57b1e, 
    0xbe0bec58, 0x3e6de92a, 0xbf1157b1, 0x3f3160e3, 0xbf0ff17d, 0xbf083948, 0xbe7bb995, 0x3e05caa1, 
    0x3ca56a90, 0x3d94f611, 0x3e4a104d, 0xbe6c9aec, 0xbef00616, 0xbf335ae1, 0xbdf7f3b8, 0xbedbc66c, 
    0x3e0ad51b, 0x3f2ba495, 0x3f15ff03, 0x3ecd9733, 0x3d75e338, 0xbecb25bb, 0xbe13d200, 0xbe0b3a61, 
    0x3e961a2c, 0x3e168089, 0x3f08813d, 0x3ed4cbe5, 0x3ebea5a6, 0x3e9fa8c2, 0xbeb2b372, 0x3e80dd12, 
    0x3cf709e2, 0xbee51449, 0xbef95227, 0x3ec8744b, 0xbe504439, 0xbebf0f20, 0x3e3a9c43, 0xbeb95295, 
    0xbeee0da4, 0x3ed27f9d, 0xbdec7a9b, 0x3f0abf65, 0xbd8fd701, 0xbe78fed6, 0x3db933fa, 0x3e1af45a, 
    0x3ec77578, 0xbe4ee06e, 0xbed84bf5, 0x3f05de56, 0x3e835b53, 0xbd19716c, 0x3edcaeb2, 0x3f0e5a2a, 
    0xbefc11c6, 0x3e1b0d59, 0x3d3780af, 0x3dbaf8a8, 0x3d975970, 0x3f15959b, 0x3ea13ee6, 0xbe587324, 
    0xbe3037c5, 0x3e01bbae, 0x3d2a16e8, 0x3da9f2aa, 0xbefff171, 0x3e9289fc, 0xbedec861, 0x3e31d24b, 
    0x3ee8f18e, 0x3ec5c9d0, 0x3e0d51c6, 0xbdcd3200, 0x3e15836e, 0xbe5b95cc, 0x3db4d5cf, 0x3e7dc4f6, 
    0xbe5cd3ed, 0x3f32529d, 0x3d928a72, 0xbdcd0bbc, 0xbea3103e, 0x3e07d55c, 0x3ec8f2c7, 0x3d181098, 
    0xbe3ec23c, 0x3ea60356, 0x3d395122, 0x3b2b56d3, 0xbe54a935, 0x3d6fb1cb, 0xbe8a5359, 0x3d995899, 
    0xbeb5a965, 0xbe6a1715, 0x3e046116, 0xbe5ce3cd, 0xbd015dbe, 0xbeb2c27d, 0x3e9edcab, 0xbea5e2c7, 
    0xbe84ee42, 0xbdbb98e7, 0x3daa9846, 0xbe81d96b, 0x3ed04184, 0xbe12a32e, 0xbdc7d8dd, 0x3ea883b3, 
    0xbd777c23, 0x3e141f0b, 0x3f0176b1, 0xbe56e372, 0x3e170956, 0x3f0ba54e, 0x3ebea4cc, 0xbe175ba2, 
    0x3eabbaed, 0x3dd03422, 0xbe13b4ef, 0xbece6159, 0x3e7d1daa, 0xbf50f280, 0xbf1be4a7, 0x3e308593, 
    0x3e868c4f, 0xbdddd412, 0x3e7d4745, 0x3e08d7d9, 0xbe2646fa, 0x3cc611df, 0xbe8a687e, 0x3ed8ad46, 
    0x3ee50eea, 0xbeb44707, 0xbd6c8307, 0xbf09da36, 0xbeb7f0f0, 0xbe4b2ea4, 0xbd9a43fe, 0x3e7fbccf, 
    0xbe9cc70e, 0xbe587a96, 0x3e993c49, 0xbf27e3df, 0x3f02d73a, 0xbda15035, 0x3ebd78df, 0x3d4421de, 
    0x3ee95fae, 0x3eb50fa5, 0x3f321055, 0x3f025258, 0xbd64ade9, 0x3d869f4b, 0xbdb602eb, 0x3db73fdd, 
    0xbe9c2525, 0xbed812d2, 0x3e88492b, 0x3dd9b9ed, 0xbeab44a5, 0x3ea3601f, 0xbee20002, 0x3db08228, 
    0xbece9fb6, 0x3f1fea42, 0xbe1d7291, 0xbf044478, 0x3f0dc2f6, 0x3c0e4cd4, 0x3edc8a4a, 0xbe9bcd5d, 
    0xbe44438b, 0x3e2da800, 0x3f0d38d2, 0xbeaadb3a, 0x3eb8587f, 0xbe346239, 0xbeaea579, 0x3eb3594e, 
    0xbd863586, 0x3e0221b6, 0xbe3269f8, 0x3e812213, 0x3ee7bfdb, 0xbf3b9163, 0x3d8229c8, 0x3de56be1, 
    0x3e331b41, 0x3ec02fe1, 0x3c3b5333, 0xbe4f952c, 0x3de37076, 0xbdf79df4, 0xbdbfd368, 0x3e767fd2, 
    0x3d9c173c, 0xbc600eb2, 0xbd1f9f5e, 0xbdeabae6, 0xbeafd54f, 0x3e10c842, 0xbee0e09d, 0xbe70054a, 
    0x3ca8c071, 0xbdf42d9a, 0x3f2142c5, 0x3db85760, 0xbd6e24a0, 0xbe846ca1, 0xbe5fb73b, 0xbc93be0c, 
    0x3e06af58, 0xbe2d0e10, 0xbe0b874b, 0x3d21b833, 0xbce11209, 0x3eabee73, 0x3ec012f3, 0x3d994dfc, 
    0xbe705a83, 0xbe070dd8, 0xbcd0c71e, 0xbeb34b3d, 0xbdb5a76b, 0x3e74f1bf, 0x3ec7b2e9, 0x3dd2cf6b, 
    0xbe674064, 0x3c34fc56, 0x3e6c538f, 0xbe12db9f, 0xbe8b45d1, 0x3e730b0b, 0x3e080831, 0x3cfffd90, 
    0x3e80f2de, 0x3d652d93, 0xbe807da7, 0xbda01c8e, 0x3e0ca665, 0xbd30f534, 0xbe935396, 0x3d409bc0, 
    0x3e132973, 0x3e6f7f34, 0x3e225c5b, 0x3e374f5c, 0xbe6024fa, 0x3e1829b8, 0xbe5332cf, 0x3e134e35, 
    0xbdc18537, 0xbed53eb3, 0xbe868811, 0xbeb02b18, 0xbebea66c, 0x3ec05828, 0x3eb47c49, 0x3e900ca7, 
    0xbe92f8eb, 0x3d5ee7e9, 0xbe69e8d3, 0xbe754610, 0xbea4e173, 0xbe2f5841, 0x3dc60969, 0x3eb5fa1f, 
    0xbeb0e111, 0xbe9c6c50, 0x3d34e4d7, 0x3e274c41, 0xbd83a115, 0xbe3305fa, 0xbea2e7af, 0xbcd3904e, 
    0xbe6dea3a, 0x3eccba93, 0x3e81679e, 0xbeb02d06, 0xbeaa2f78, 0x3c4906a3, 0x3ea3480a, 0x3dfc9bf9, 
    0x3e0c9617, 0x3e94ad49, 0x3b8d596a, 0x3e0b9ea9, 0x3e0439a0, 0x3ea059c5, 0x3e5e54bf, 0xbdcc3463, 
    0x3d9110db, 0x3e013513, 0x3d3dfa77, 0x3e852d23, 0x3d063d5d, 0xbe98f230, 0xbd90c9a5, 0x3bf60d7f, 
    0xbd918168, 0x3dbb7d44, 0xbe48493c, 0x3e3fd1b9, 0xbe6f93e9, 0x3d768a44, 0xbe189c56, 0x3eaecc1f, 
    0xbe945f6a, 0x3f221763, 0xbf0d1799, 0xbe63161c, 0x3f2eb7c0, 0x3e6188a0, 0x3e5db0ac, 0xbe6d8474, 
    0x3f0e63cf, 0xbeb6660e, 0x3e6a41bd, 0xbed1b250, 0x3db42977, 0x3e9cf0ff, 0xbe80f7fd, 0xbef6d9d8, 
    0x3e71f2c7, 0xbe1e0cf5, 0x3dbb4238, 0xbe2ab4f0, 0xbe764ec0, 0x3da49def, 0x3e3ca934, 0xbf309ba4, 
    0xbe82f5ba, 0x3d28f757, 0xbd797dab, 0xbf197441, 0xbf2a64f3, 0x3db6e999, 0x3e0c6e9c, 0x3c4df8a4, 
    0x3edca66f, 0x3f29bb81, 0xbe8fd0d8, 0x3e1244fa, 0x3f18b03a, 0xbf2eb473, 0x3f02ea2c, 0x3db94c2c, 
    0x3ede37e6, 0xbdaf46e2, 0x3f286e93, 0x3dc3e8f0, 0x3d7c7b36, 0x3f1c4660, 0xbbe90516, 0x3eab1299, 
    0x3f15814d, 0xbef01fbd, 0xbf045117, 0x3f273547, 0x3f161416, 0x3f149b14, 0x3d6d2613, 0x3e7527b0, 
    0xbe7158a6, 0xbe82ac61, 0xbf0d6287, 0xbe6df846, 0x3d828338, 0x3e6d53fe, 0x3e7f1bf8, 0xbefd0a4e, 
    0xbe86cc76, 0xbe1c150c, 0xbe2137ba, 0xbf25e3b6, 0x3f1a630f, 0x3e3ee968, 0xbef9ddc7, 0x3e9800a1, 
    0xbcaa95de, 0xbecd88ed, 0xbea5c642, 0xbf5a51f6, 0x3e8ddcd3, 0x3f081dbb, 0x3f1d4765, 0x3e69e1e3, 
    0xbed794f8, 0xbd030399, 0x3ecd3fa6, 0x3e87cfc8, 0x3e2014d8, 0xbf02a5e6, 0x3e6ffd9f, 0xbea69a31, 
    0x3f1d9bb0, 0x3d83d6f2, 0x3e1f535b, 0x3eae4f29, 0x3dae2c82, 0xbf2c5f75, 0xbed12174, 0x3f047772, 
    0x3ea0dce0, 0xbc02173d, 0x3d824a0f, 0xbe8a3830, 0x3da42d70, 0x3e8e488d, 0xbe3ef076, 0x3e949b81, 
    0xbe78a2d8, 0xbdec9b37, 0x3e5e3dc8, 0x3e616377, 0xbf0e094a, 0xbe943457, 0x3bece806, 0xbdb79af5, 
    0x3f338853, 0xbe1e00cf, 0xbe3291bf, 0xbef23000, 0x3ed7c689, 0x3d8203d7, 0x3eb63e45, 0xbf060204, 
    0x3d08e84b, 0x3ea3a93b, 0x3e663abd, 0x3e94b460, 0xbddee225, 0xbecce057, 0xbc5540bb, 0x3f032340, 
    0x3f1233bb, 0xbebf669a, 0x3e3e573f, 0x3e2f19c2, 0xbe131687, 0xbe377122, 0x3efb88dc, 0xbe6c1bdf, 
    0xbe25087c, 0xbe354fbf, 0xbe261d4b, 0xbd50113c, 0x3e437d73, 0xbf0bf092, 0xbe8514e4, 0xbed92b20, 
    0xbe8b255a, 0x3dbe9936, 0x3e49272a, 0x3e22da33, 0xbeae51a8, 0xbde4c4e4, 0x3ec4988f, 0x3ed8dab2, 
    0x3e9d5aec, 0xbe276503, 0xbe6d8dd8, 0xbd043d51, 0xbf165f0d, 0xbe806e1b, 0xbe0052f5, 0x3edfec30, 
    0xbe58718f, 0xbf090e2e, 0x3e9434dc, 0x3d9dfd93, 0xbec9f0e2, 0x3f4c6d2e, 0x3e3f235c, 0xbe89b0a6, 
    0xbe54bff8, 0xbe7857fe, 0xbeb51775, 0x3c19e6ec, 0xbe2db608, 0x3e7fa94e, 0xbecee988, 0x3e64f4d6, 
    0x3f0e175c, 0x3e81cdfa, 0xbf05f25b, 0xbe33821b, 0xbe0d59ff, 0xbeab3dc9, 0xbeb9df1a, 0xbef9d981, 
    0x3ebe4ca1, 0xbd29695d, 0xbe969946, 0x3eae9b25, 0xbe7eecf2, 0x3ee9781e, 0xbea27924, 0xbdbc8fd4, 
    0xbec2bdc5, 0xbdeec57c, 0x3efbeb74, 0xbf1988e2, 0xbea5c84d, 0xbe9fa97c, 0xbd44ccd2, 0xbef18255, 
    0x3e7489a8, 0x3e56baca, 0x3f4e7de7, 0xbf1152ac, 0x3f2b9669, 0x3eddb0da, 0x3e91e458, 0x3f285cbd, 
    0xbe969f41, 0x3eb19da4, 0xbf426d4d, 0x3f2b9d6b, 0xbdda1777, 0x3e22eb95, 0x3e94a32a, 0xbce47cac, 
    0x3ea006d1, 0xbe33a7ae, 0xbef380b8, 0xbdeec2b1, 0xbe404cff, 0x3f433444, 0x3f0bc0f6, 0xbf06d5f3, 
    0x3e406d88, 0xbda2bf3a, 0x3f054347, 0xbd282fcd, 0x3e3e3db6, 0xbf3f81c5, 0xbf5c7c88, 0x3cbcaa55, 
    0xbe88954b, 0x3e2a1f78, 0xbd0cbb48, 0xbcfd1769, 0xbed7bcaa, 0x3e9511be, 0xbf3475ee, 0xbee5917b, 
    0xbec89d34, 0x3f0be3b1, 0xbe76bd1b, 0x3e8278ba, 0xbe8f60c5, 0xbe085592, 0xbe671744, 0x3e23a577, 
    0x3e963d67, 0xbee9d46e, 0x3f00a5b0, 0x3ed2b3a4, 0x3eba0146, 0x3e0dd922, 0xbf6a8767, 0x3e38d3b1, 
    0xbee4b04c, 0xbea27fe0, 0xbe2f7ea0, 0x3ed1dad6, 0xbed66539, 0xbf43e2e9, 0x3ec964bb, 0x3f32c39f, 
    0xbeadd49a, 0x3f2034db, 0x3e808c46, 0xbec8f087, 0x3e1bfaed, 0x3ec9087c, 0x3d29e92e, 0xbf00f855, 
    0xbe973aa5, 0xbe9cebcb, 0xbf0cb74e, 0x3eb13b84, 0x3f528fc5, 0x3f800009, 0xbedb8636, 0xbe450dd4, 
    0x3f54f42e, 0x3f16b1fc, 0xbe0ff43c, 0xbe59021c, 0x3f136385, 0xbeaae500, 0x3d36f7b8, 0xbd2155fd, 
    0x3dc8dc70, 0xbedeebb6, 0x3f2ab95f, 0x3ea82320, 0xbe9ccbf2, 0x3ebb5d3d, 0xbef464c2, 0xbdf7d874, 
    0xbd806fa4, 0x3ea5c90d, 0x3c7c00ae, 0x3eb5da50, 0xbec9cfe7, 0x3ec8506e, 0x3e2946c8, 0xbcc8c841, 
    0xbeb65165, 0x3eac609e, 0x3c28110b, 0xbceaf6c9, 0x3e2126b8, 0xbebe4fe5, 0x3ec72ce5, 0x3ef52d9d, 
    0x3e88b1e3, 0x3d937c22, 0x3d59048e, 0xbde80b2f, 0xbdfe918c, 0x3e911f7d, 0xbed05315, 0x3ef12c8e, 
    0x3e21da37, 0xbebe8920, 0x3f09f9fd, 0x3e3a3c23, 0xbe9a1be0, 0xbdde1355, 0xbe3a58aa, 0x3c6f6dd6, 
    0xbe210f9d, 0xbceacb97, 0xbe966888, 0xbe76b95a, 0x3dab63da, 0x3c5706a7, 0xbeed97ec, 0x3ec20192, 
    0x3e374695, 0x3f36ba61, 0x3dd7c037, 0x3ed2df29, 0x3f0c7cef, 0x3e2a7c8e, 0xbd810059, 0xbe85b2e3, 
    0xbcde6490, 0x3ebcc7f0, 0xbe3b4c8b, 0xbdec4aa1, 0xbd853d0f, 0x3e9a2303, 0x3ee68eef, 0xbe34ebc2, 
    0xbdc55e09, 0x3ed1df79, 0x3e9b9689, 0xbea3dc41, 0xbe95a9f3, 0xbde6f35d, 0xbd98f728, 0xbda71e5e, 
    0x3e710f9e, 0x3e7f36fa, 0x3dc08cf9, 0xbee11fdb, 0xbdc5bfb5, 0x3e3b1c9d, 0x3e296f76, 0x3e1f48e1, 
    0xbe801839, 0x3d3b6492, 0x3e8b061b, 0x3e8b36be, 0xbeba7ab7, 0x3ef291c6, 0x3ed55b85, 0x3ef8a2a6, 
    0xbdd3ca4c, 0x3f352e9c, 0x3e07960f, 0xbe6700e3, 0xbd6e5958, 0x3c87b2c4, 0xbd5b237b, 0x3d1cbf8f, 
    0xbe133cb6, 0x3e045c15, 0xbd70d3d1, 0xbe92e1b9, 0xbea997a7, 0xbe9930d3, 0xbdd8ef17, 0x3e084eeb, 
    0x3d897c3f, 0xbe6febeb, 0x3e0a329b, 0xbd9bb360, 0x3e9ad61f, 0xbe1a4206, 0x3e78a21d, 0x3e206016, 
    0x3d669cb9, 0xbe0e9857, 0xbdde11a1, 0xbd281d82, 0xbead0aa1, 0x3e859164, 0xbe73f9a5, 0xbebcab74, 
    0x3df0230c, 0xbda3e5e4, 0xbd1b96c9, 0x3d8667cd, 0xbe9dedd2, 0x3ad7762d, 0x3d7fb149, 0xbd95ac7e, 
    0x3d62b28f, 0x3ddecab7, 0xbdb76f81, 0x3c407ddd, 0x3e060f00, 0x3ca74397, 0xbddff827, 0x3eccea08, 
    0xbdd20e8b, 0xbcbe6ed0, 0xbe4dc764, 0xbeb5e2f0, 0x3e8c6eaf, 0xbdcc8129, 0xbdb580c3, 0x3e93050d, 
    0xbec7a82b, 0x3d873091, 0xbe859f85, 0x3e82dcbd, 0xbe3dfed5, 0x3ed0307b, 0xbe2e6387, 0x3cf28d26, 
    0xbca128af, 0xbd22d064, 0x3cf63bf1, 0xbb813c8b, 0xbe229d3b, 0x3e99e74e, 0x3e9164d6, 0xbe9b23db, 
    0xbda57250, 0xbe9b1f6c, 0xbe860bba, 0x3e8eeebe, 0x3daba279, 0xbdf580a8, 0xbe5bdf22, 0x3edbcb66, 
    0xbe8cc3da, 0xbd8ddf70, 0x3e826413, 0x3da025d4, 0x3e153a45, 0x3e2bf4bf, 0x3e940acc, 0x3e67ba6f, 
    0xbed3a49d, 0xbcf116b9, 0x3e1734e2, 0x3dce28d5, 0x3e951a2b, 0x3e1c2781, 0xbd048b54, 0xbec9fb00, 
    0x3e2f46dd, 0xbe8f6bbb, 0xbe6ee084, 0xbb28c3bc, 0x3e249460, 0xbeb042ea, 0xbe8ba01b, 0x3ed40995, 
    0x3e9d6a43, 0x3e1d27a1, 0x3d07b0a2, 0x3def39fb, 0x3e75b082, 0x3d962e9d, 0xbe6c2640, 0x3d7d1aac, 
    0x3db4b652, 0x3abb0e6e, 0x3e30254f, 0x3ef1c543, 0xbd514464, 0xbe640b5e, 0xbd9cdb43, 0xbd8e9618, 
    0xbe197f7f, 0x3e15e2f6, 0x3e0ba536, 0x3defc06a, 0x3cfb4a99, 0xbe7bf292, 0x3c95ea66, 0x3c885c7c, 
    0x3b9c651a, 0xbe8fa7c8, 0x3f1cd540, 0x3ec50a98, 0xbe688a7b, 0xbdc6d311, 0x3e4f893e, 0x3dd4c3db, 
    0xbed569cd, 0xbe552104, 0xbe58517a, 0x3e59645c, 0x3ea26abf, 0x3ef0309b, 0xbd162738, 0xbe97a31a, 
    0xbc5d4ce7, 0x3c8525a4, 0xbe965fb7, 0x3ec8b062, 0x3c82a52d, 0xbe879d7f, 0x3cf680f5, 0xbd3b9471, 
    0xbece5ad6, 0x3d46a988, 0xbe35910d, 0xbeb809f2, 0xbe9d8a28, 0xbe6ba9c2, 0x3ee19f50, 0xbe324eef, 
    0x3e693ed2, 0xbdf22f68, 0xbde561d8, 0x3ee8d7a2, 0x3ee107d2, 0x3d39bcb6, 0xbe3e06b0, 0x3e7875ee, 
    0x3ebb6a92, 0xbec8f27c, 0x3df56660, 0x3dae92d8, 0xbd73684f, 0x3eb4c098, 0xbe7cfccc, 0xbe7d93bd, 
    0xbe9315d9, 0xbe9210f4, 0xbe87402c, 0xbd78c31c, 0xbee24138, 0x3c734bf1, 0xbdd57ff4, 0x3d68e76f, 
    0xbdc9f037, 0x3f148edb, 0xbe7fc51a, 0xbe1bca61, 0x3ec274e7, 0xbefc8377, 0x3e22181e, 0xbed0529f, 
    0x3e962c30, 0xbdedbd89, 0xbe3d0918, 0xbebd2426, 0xbea67620, 0xbefd33f9, 0xbd973492, 0x3e0fed5b, 
    0xbebb7641, 0x3e97ba65, 0xbe9cb6ff, 0xbe38cfba, 0xbd71634b, 0x3ebf408b, 0x3d2d280b, 0x3eda0341, 
    0xbe005434, 0x3e16519d, 0x3dfb5406, 0xbf0e0bf5, 0x3f083893, 0xbef1b774, 0x3d02c418, 0xbead2bd4, 
    0x3dbce3d3, 0xbe2a3938, 0x3ea3513f, 0x3f09a8d2, 0x3e29a6e2, 0x3e8149d2, 0x3eaa58cd, 0x3d80aa00, 
    0x3f03e18f, 0xbecadf98, 0xbeff6089, 0xbee3974a, 0xbeb0aa88, 0x3e3789e4, 0xbed2a884, 0xbf2d0095, 
    0xbe160432, 0x3edefc73, 0xbe6ab8ec, 0xbef61092, 0x3f3757ff, 0x3d585815, 0xbb878fbe, 0xbedc3181, 
    0x3dea5685, 0x3e839d59, 0xbe6bec3d, 0xbe491356, 0x3df6e890, 0x3ce74f8f, 0xbe85965c, 0xbef0992e, 
    0xbd81e445, 0xbe892525, 0xbea9b138, 0x3ef17a92, 0xbe15df3b, 0x3e99e595, 0xbedb9201, 0xbe433166, 
    0xbee685db, 0xbd6e5624, 0x3e17ea31, 0xbd7adb92, 0xbf14993c, 0xbe95c15a, 0x3e0118db, 0x3e78e434, 
    0xbe8da5b2, 0x3ed2aca4, 0xbe432fb5, 0x3d62024a, 0xbe6be8e4, 0xbe2b0d8d, 0xbc90f90b, 0x3e98776c, 
    0x3c1efd4a, 0xbef81e3b, 0x3e8e951a, 0xbe944d19, 0x3de60b92, 0xbf094dbb, 0x3e8503da, 0xbec71e25, 
    0xbe2363bd, 0xbe0b641e, 0xbe972b39, 0xbea7604e, 0xbea36fc1, 0xbc1ea3cd, 0xbe328c5f, 0x3e71a92a, 
    0x3f138dbb, 0xbf14b82b, 0xbefe819a, 0xbebe19df, 0xbee87943, 0x3e8ae246, 0xbe24ec39, 0xbe5eda8f, 
    0xbedc9432, 0x3dac52ce, 0x3e81f394, 0xbde9705d, 0xbe324250, 0x3ef397b9, 0xbdf2178f, 0x3e962bf7, 
    0xbe93e7bc, 0xbd6e5af7, 0x3eac79d9, 0xbee3f4fb, 0x3e79f276, 0x3e93361e, 0xbe351aa6, 0x3d31f194, 
    0xbe9e863b, 0xbca5707c, 0xbd76ae30, 0xbdd8dbca, 0xbb55d1f3, 0xbe950297, 0xbe78a3a4, 0xbea5d8be, 
    0xbe07df1b, 0x3da6f768, 0xbe268a4e, 0xbd815cdf, 0x3e0b7e52, 0x3d290868, 0xbe5b34d2, 0x3de3a582, 
    0x3e06770b, 0xbed6d5ac, 0x3da3a5ee, 0x3e31700d, 0x3e5c4bdf, 0x3f03d012, 0xbd83bbf6, 0x3e9ae4b7, 
    0xbe427ff7, 0x3db55b73, 0x3e1e5396, 0xbf075648, 0xbee54c08, 0x3e619bb0, 0xbe8c2e35, 0x3e8567e8, 
    0xbd869ae1, 0x3e07bd99, 0x3eaae34f, 0xbd03c47e, 0xbda7201a, 0x3e0a15ef, 0xbe5c0527, 0xbdb529ba, 
    0x3d929ec8, 0x3d5111e8, 0xbe84d7d7, 0x3eaeda96, 0xbe9eb6fc, 0xbe932f9c, 0x3cb50afa, 0xbea97b14, 
    0xbe3218e7, 0x3dfb83e7, 0xbe6fe3a3, 0xbc126fc9, 0x3ea901ad, 0x3d934915, 0x3e8785e1, 0xbcb3dbb8, 
    0x3af7acb1, 0xbed55bb9, 0xbeb93deb, 0xbf0840e2, 0x3e51017c, 0xbe1c3ea7, 0x3eb2e372, 0x3e13e595, 
    0xbe7c75df, 0xbc93078e, 0xbd79d44d, 0xbe5b69c8, 0xbe1eb631, 0xbdac7114, 0xbeb76c72, 0xbdf2b3c0, 
    0x3e2e61c0, 0xbe0af495, 0xbddb7cfa, 0xbecde94e, 0x3e847181, 0xbe89438a, 0xbde79e7a, 0xbe332bfe, 
    0x3e51a125, 0xbe68c534, 0xbee48255, 0xbdd9915e, 0xbed6fe4a, 0x3d408b1f, 0xbe982686, 0xbee4d981, 
    0xbeda14a7, 0x3e8961ae, 0x3d032d4d, 0x3e3aa5f2, 0x3e8f300b, 0xbeca9bc8, 0x3e684f30, 0xbec0603a, 
    0x3e1fb138, 0xbe38626f, 0xbdfef13c, 0x3e7b02e6, 0x3c9a3421, 0xbea2c6c8, 0x3dc9b57b, 0xbf1857fb, 
    0xbe82dfdf, 0xbe9e5c3e, 0x3e29d889, 0x3e8522d0, 0x3dbf9a47, 0x3e63fa68, 0xbc9e0d57, 0x3e86e4a6, 
    0x3e8de4d3, 0xbd84b55d, 0xbe969cb3, 0x3d95c3bd, 0xbe0da2b7, 0xbd58d048, 0xbea4d024, 0xbe82052d, 
    0x3ec29199, 0xbea9491b, 0xbdd8ad3f, 0xbcd84e60, 0xbeb77b0a, 0xbefb2684, 0xbe8120f7, 0x3e506204, 
    0x3f2ad0d5, 0xbe083e00, 0xbe88ba43, 0xbe844d68, 0x3e205299, 0xbd6065d9, 0xbe9db2f5, 0xbe1c052d, 
    0x3ebe32a4, 0xbd1f0364, 0x3e6292ed, 0xbd309ab3, 0xbe3101df, 0xbeea37aa, 0xbed1b7de, 0x3eaf6b62, 
    0xbe5f336c, 0xbe821bf8, 0x3e613928, 0x3ed12824, 0xbed961c9, 0x3f12cb4d, 0xbe57f929, 0xbe679341, 
    0x3ebcb2b5, 0xbeb547de, 0x3f2b0c02, 0x3ec5b975, 0x3e9d0d8c, 0xbd552954, 0x3acdaf69, 0xbec4e50f, 
    0xbe54b05b, 0xbdcbf184, 0x3eaf1eae, 0xbe51b216, 0xbd1b508d, 0xbe0e2180, 0x3d682c58, 0xbf0746c9, 
    0x3dd5327c, 0x3d5e3cac, 0x3ddd32ef, 0xbe0368c2, 0x3ec55b67, 0x3f5d8afe, 0xbeb52496, 0xbe9571e1, 
    0x3f09a5ba, 0x3e7ea6e3, 0xbe170596, 0xbf053b9e, 0x3f372d2d, 0xbe6db222, 0x3ea3a5f1, 0x3e4da721, 
    0xbed905a1, 0xbeab3d3b, 0xbd29701e, 0x3e38dfba, 0x3eafb040, 0xbf1ef98a, 0xbf388923, 0xbe621837, 
    0xbf0ccf5e, 0x3f4e3bf6, 0xbea50865, 0xbe61e588, 0x3ca7910c, 0xbd4ab24e, 0x3e85037a, 0xbe646a3c, 
    0xbf054673, 0xbd1ab5a2, 0x3e823f71, 0x3e84842d, 0x3d8b8184, 0xbe2aa574, 0x3e9fec69, 0x3f01862d, 
    0xbedf0303, 0x3f2ce76e, 0xbe804767, 0x3e470e56, 0xbe8b6bbd, 0x3d9df89c, 0xbedfe4d0, 0xbe64d5bf, 
    0xbf089068, 0x3e8498c3, 0x3f00ed3f, 0xbf2043ec, 0x3ef4c36a, 0xbef13694, 0xbf24110a, 0xbdfd1946, 
    0xbeedc576, 0x3f34b138, 0xbd954e74, 0x3eee9088, 0x3ef40093, 0x3c813a13, 0xbce81870, 0x3e9d9528, 
    0x3eb022d3, 0xbe563036, 0xbdc9d620, 0x3efa8fd8, 0x3f348eb2, 0xbd3cb372, 0x3ec05789, 0x3ec3863b, 
    0xbc5c07da, 0x3ebbddd9, 0x3f06d553, 0x3f0ad390, 0xbd7aff71, 0xbec788c8, 0x3eb1f0f0, 0xbee20159, 
    0x3ec0e8bd, 0x3ce0a13f, 0xbed2bb37, 0xbe3d5dcd, 0x3c793eaa, 0x3e2ff544, 0xbdd48505, 0x3dd7fb83, 
    0xbf1f4f62, 0x3dd0ec80, 0x3e9e328d, 0xbd406e90, 0x3f0205c3, 0x3e2b3083, 0x3eafae0e, 0xbe671036, 
    0x3efd947d, 0xbe510801, 0x3ee10f6a, 0x3da32134, 0xbdf5b549, 0x3ee49316, 0x3e8f930f, 0xbf4add2c, 
    0xbe58875f, 0xbbe5a6c5, 0x3d43a6c6, 0x3e318258, 0xbf1ec290, 0x3da6bf6d, 0xbebe6fff, 0xbed6d899, 
    0xbe81f42c, 0x3da49fe5, 0x3d6dfa63, 0xbe7e3ebc, 0x3f3513cf, 0x3ec972a1, 0xbf129da0, 0xbf10e254, 
    0x3ea565d8, 0x3e282e6c, 0x3ef06dbe, 0xbc980e18, 0x3e148596, 0x3e9473fc, 0xbeda17bd, 0x3ee2a21a, 
    0xbeaede9d, 0x3c78cd71, 0x3ec56baf, 0xbf4efffd, 0xbc5a9abe, 0xbee55bc0, 0xbc453223, 0x3eb6918a, 
    0xbe771cd0, 0x3dd133b5, 0xbcdf6b9d, 0x3e6f3762, 0xbf1aab07, 0xbf3e898d, 0xbeb315af, 0xbe596e52, 
    0xbf1b8717, 0x3e1afeaa, 0xbd2ee4e2, 0x3e82b40a, 0x3ef41806, 0xbee5f704, 0xbe49e003, 0x3e3d3e0d, 
    0xbe895b82, 0xbeb8d20b, 0xbe45b065, 0x3ecce72b, 0x3f47a0c1, 0x3eb9a5f5, 0xbf2b81d9, 0x3eba419b, 
    0x3f2b0a08, 0x3dd5c8ee, 0xbea5bdbb, 0xbed060bd, 0x3e088b36, 0x3e9c282f, 0x3e53a3ab, 0x3eeee41e, 
    0xbb319bf4, 0x3f3ab198, 0xbe2b7593, 0xbe000536, 0xbea44385, 0xbee6f9b7, 0x3db989a8, 0x3edf6cb2, 
    0x3c803a1b, 0x3d17e850, 0x3ed55967, 0x3ee7c361, 0x3e2b94b5, 0xbecbe629, 0x3e99f7ff, 0xbe1970e0, 
    0x3ed30042, 0xbdc52778, 0xbf0276f4, 0xbe0a96e2, 0xbdd5376e, 0x3e2aff50, 0xbe2e3c67, 0xbebd3355, 
    0x3e97c39a, 0xbd00a4b3, 0xbd1c1079, 0xbdff2d53, 0x3db619f5, 0x3ef403e6, 0x3e271e6a, 0xbe618b07, 
    0xbeccecc4, 0xbe9ce0d4, 0xbe8f8570, 0xbe04da08, 0xbcd58c6a, 0xbe9fd9c6, 0xbbc6d987, 0xbd6112a6, 
    0xbe5f2c6d, 0x3e4127a2, 0xbd9b5bdf, 0x3e12fbe5, 0x3e07b7cd, 0xbe96710e, 0xbe3ab074, 0x3e9a0de1, 
    0xbea8a07a, 0xbdf6d130, 0xbe3302d9, 0x3e37c903, 0xbdf903a9, 0x3f0396ee, 0xbe0656ce, 0xbe8ee1a7, 
    0x3f0d4448, 0x3ef21781, 0xbed801d5, 0x3e7efe83, 0x3e5b88f2, 0x3e61e92e, 0xb836a5b4, 0x3e2e9e3d, 
    0x3e354298, 0xbc04ef16, 0xbd603d49, 0x3ecb987b, 0xbe1a80e8, 0xbe377b98, 0x3e89bec7, 0xbe17e34d, 
    0x3e8d1d73, 0xbd56ffcc, 0x3d93580f, 0xbe622dcb, 0xb9bb330f, 0x3ca70a3b, 0xbeaeeb45, 0xbc08859a, 
    0xbe337c4a, 0xbebad1bf, 0x3e532db8, 0x3e80c343, 0xbe6e297c, 0x3e655bf9, 0x3e91aba0, 0xbe424ab1, 
    0x3f00954e, 0x3ee55498, 0x3e339b07, 0xbe628195, 0xbe0df0b6, 0x3e21dadd, 0x3e9daaa6, 0xbea3793a, 
    0x3d902352, 0xbd798690, 0x3ed69867, 0x3e9aab8b, 0xbcadeee3, 0x3effd465, 0xbddc7fcc, 0x3ed0215d, 
    0xbed5d648, 0x3eca0292, 0xbbf6ac9b, 0x3dc72b19, 0xbdf866a8, 0x3eb1f803, 0x3e0a9752, 0xbe72dc81, 
    0xbe825a73, 0xbdb2b516, 0x3d121466, 0x3ed46d78, 0x3dc29844, 0x3ed90aff, 0xbde91210, 0x3e527199, 
    0xbd7c2f44, 0xbe2de27b, 0xbd398081, 0xfffffe46, 0x00000004, 0x00000080, 0xbe246d4f, 0x3c1a5223, 
    0xbfc0dc92, 0x3f41bb92, 0xbfa0272c, 0xbea017e5, 0x3f544b4a, 0x3f66385f, 0xc005b6c4, 0xbfd520ce, 
    0xbf2725dd, 0xbe037c60, 0xbd7b75a8, 0xbf42a9e4, 0xbf4fda36, 0xbfedbe8a, 0xbf40d0b1, 0x3f32a1be, 
    0xbdade158, 0xbe238b8f, 0xbf801e0f, 0xbf96a0a2, 0x3f5d81cf, 0xc0377ac4, 0x3e287ffa, 0x3f623f07, 
    0x3f971809, 0x3ffa6eb1, 0x4059cb4e, 0x4017d2c6, 0xbf378d6a, 0x404a70cb, 0xfffffed2, 0x00000004, 
    0x00000080, 0x3f968a7f, 0x3f9bc332, 0x3ef0b942, 0x3fb40b0a, 0x3f9e61a4, 0xbde1d49f, 0x3d0603fe, 
    0xbd612c25, 0xbe27287d, 0x3e0aef66, 0xbf29356d, 0xbf6298c4, 0xbf8d9fef, 0xbf21f7ef, 0xbe56d93a, 
    0xbec9c2ee, 0xbf38e176, 0xbf85e66a, 0x3e60a974, 0xbcf32470, 0xbf7c3ecc, 0xbeabe21b, 0x3f36add9, 
    0xbf4a2232, 0x3f75af0a, 0xbf0cf917, 0x400973f7, 0x3f72b26d, 0x3f64f227, 0xbfa4b194, 0x3fe076b2, 
    0xbcb3fbfc, 0xfffff1fc, 0xfffff200, 0x0000000f, 0x52494c4d, 0x6e6f4320, 0x74726576, 0x002e6465, 
    0x00000001, 0x00000014, 0x000e0000, 0x00140018, 0x000c0010, 0x00040008, 0x0000000e, 0x00000014, 
    0x0000001c, 0x000002c8, 0x000002cc, 0x000002d0, 0x00000004, 0x6e69616d, 0x00000000, 0x0000000b, 
    0x0000028c, 0x00000230, 0x000001d0, 0x0000018c, 0x00000148, 0x00000124, 0x000000d0, 0x000000ac, 
    0x00000078, 0x00000040, 0x00000004, 0xfffffe06, 0x0000001c, 0x09000000, 0x0000001c, 0x00000020, 
    0x00000005, 0x00060000, 0x00040008, 0x00000006, 0x3f800000, 0x00000001, 0x00000019, 0x00000001, 
    0x00000018, 0xfffffe3e, 0x00000014, 0x08000000, 0x00000010, 0x00000014, 0x00000004, 0xfffff2d4, 
    0x00000001, 0x00000018, 0x00000003, 0x00000017, 0x0000000b, 0x0000000c, 0xfffffe72, 0x00000014, 
    0x1b000000, 0x00000010, 0x00000014, 0x00000003, 0xfffff308, 0x00000001, 0x00000017, 0x00000002, 
    0x00000016, 0x0000000d, 0xfffffe46, 0x00000008, 0x0000000c, 0x00000001, 0x00000016, 0x00000002, 
    0x00000015, 0x00000006, 0xfffffec2, 0x00000024, 0x05000000, 0x00000034, 0x00000038, 0x00000002, 
    0x000e0000, 0x00170018, 0x000c0010, 0x00040008, 0x0000000e, 0x00000002, 0x00000001, 0x00000002, 
    0x00000001, 0x01000000, 0x00000001, 0x00000015, 0x00000001, 0x00000014, 0xfffffeb6, 0x00000008, 
    0x0000000c, 0x00000001, 0x00000014, 0x00000002, 0x00000013, 0x00000007, 0xffffff32, 0x00000014, 
    0x01000000, 0x0000001c, 0x00000020, 0x00000001, 0xffffff80, 0x01000000, 0x00000001, 0x00000001, 
    0x00000001, 0x00000013, 0x00000003, 0x00000012, 0x00000003, 0x00000001, 0xffffff72, 0x00000014, 
    0x01000000, 0x0000001c, 0x00000020, 0x00000001, 0xffffffc0, 0x01000000, 0x00000001, 0x00000001, 
    0x00000001, 0x00000012, 0x00000003, 0x00000011, 0x00000008, 0x00000009, 0xffffffb2, 0x00000020, 
    0x01000000, 0x00000028, 0x0000002c, 0x00000001, 0x0010000c, 0x000c0000, 0x00070008, 0x0000000c, 
    0x01000000, 0x00000001, 0x00000002, 0x00000001, 0x00000011, 0x00000003, 0x00000010, 0x00000004, 
    0x00000002, 0x000e0000, 0x0014001a, 0x000c0010, 0x0004000b, 0x0000000e, 0x00000020, 0x01000000, 
    0x00000028, 0x0000002c, 0x00000001, 0x000a0000, 0x000f0010, 0x00040008, 0x0000000a, 0x00000001, 
    0x00000002, 0x01000000, 0x00000001, 0x00000010, 0x00000003, 0x0000000f, 0x0000000a, 0x00000005, 
    0x000a0000, 0x0000000c, 0x00040008, 0x0000000a, 0x00000008, 0x0000000c, 0x00000001, 0x0000000f, 
    0x00000002, 0x00000000, 0x0000000e, 0x00000001, 0x00000019, 0x00000001, 0x00000000, 0x0000001a, 
    0x00000ad0, 0x00000a7c, 0x00000a40, 0x000009f8, 0x000009b0, 0x00000974, 0x00000934, 0x000008dc, 
    0x00000894, 0x00000858, 0x00000810, 0x000007cc, 0x0000078c, 0x0000074c, 0x000006e4, 0x00000670, 
    0x000005a4, 0x00000470, 0x000003a8, 0x00000274, 0x00000208, 0x000001a0, 0x0000013c, 0x000000e0, 
    0x00000050, 0x00000004, 0xfffff5ae, 0x01000000, 0x00000010, 0x00000010, 0x0000001a, 0x00000028, 
    0xfffff598, 0x00000019, 0x74617453, 0x6c756665, 0x74726150, 0x6f697469, 0x4364656e, 0x3a6c6c61, 
    0x00000030, 0x00000002, 0x00000001, 0x00000005, 0xfffff5f6, 0x01000000, 0x00000010, 0x00000010, 
    0x00000019, 0x0000006c, 0xfffff5e0, 0x0000005c, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x616d732d, 
    0x622d6c6c, 0x6e616c61, 0x2d646563, 0x616c2f33, 0x5f726579, 0x4d2f3231, 0x754d7461, 0x6f6d3b6c, 
    0x2f6c6564, 0x766e6f63, 0x732d6431, 0x6c6c616d, 0x6c61622d, 0x65636e61, 0x2f332d64, 0x6579616c, 
    0x32315f72, 0x6169422f, 0x64644173, 0x00000000, 0x00000002, 0x00000001, 0x00000005, 0xfffff682, 
    0x01000000, 0x00000010, 0x00000010, 0x00000018, 0x00000038, 0xfffff66c, 0x0000002b, 0x65646f6d, 
    0x6f632f6c, 0x6431766e, 0x616d732d, 0x622d6c6c, 0x6e616c61, 0x2d646563, 0x616c2f33, 0x5f726579, 
    0x4d2f3131, 0x006e6165, 0x00000002, 0x00000001, 0x00000020, 0xfffff6da, 0x01000000, 0x00000010, 
    0x00000010, 0x00000017, 0x0000003c, 0xfffff6c4, 0x0000002d, 0x65646f6d, 0x6f632f6c, 0x6431766e, 
    0x616d732d, 0x622d6c6c, 0x6e616c61, 0x2d646563, 0x616c2f33, 0x5f726579, 0x71532f39, 0x7a656575, 
    0x00000065, 0x00000003, 0x00000001, 0x00000006, 0x00000020, 0xfffff73a, 0x01000000, 0x00000010, 
    0x00000010, 0x00000016, 0x0000003c, 0xfffff724, 0x0000002d, 0x65646f6d, 0x6f632f6c, 0x6431766e, 
    0x616d732d, 0x622d6c6c, 0x6e616c61, 0x2d646563, 0x616c2f33, 0x5f726579, 0x614d2f39, 0x6f6f5078, 
    0x0000006c, 0x00000004, 0x00000001, 0x00000006, 0x00000001, 0x00000020, 0xfffff79e, 0x01000000, 
    0x00000010, 0x00000010, 0x00000015, 0x00000040, 0xfffff788, 0x00000030, 0x65646f6d, 0x6f632f6c, 
    0x6431766e, 0x616d732d, 0x622d6c6c, 0x6e616c61, 0x2d646563, 0x616c2f33, 0x5f726579, 0x78452f39, 
    0x646e6170, 0x736d6944, 0x00000000, 0x00000004, 0x00000001, 0x0000000c, 0x00000001, 0x00000020, 
    0xfffff806, 0x01000000, 0x00000010, 0x00000010, 0x00000014, 0x00000108, 0xfffff7f0, 0x000000f9, 
    0x65646f6d, 0x6f632f6c, 0x6431766e, 0x616d732d, 0x622d6c6c, 0x6e616c61, 0x2d646563, 0x616c2f33, 
    0x5f726579, 0x65522f38, 0x6d3b756c, 0x6c65646f, 0x6e6f632f, 0x2d643176, 0x6c616d73, 0x61622d6c, 
    0x636e616c, 0x332d6465, 0x79616c2f, 0x375f7265, 0x7461622f, 0x6f6e6863, 0x612f6d72, 0x315f6464, 
    0x646f6d3b, 0x632f6c65, 0x31766e6f, 0x6d732d64, 0x2d6c6c61, 0x616c6162, 0x6465636e, 0x6c2f332d, 
    0x72657961, 0x432f365f, 0x31766e6f, 0x71532f44, 0x7a656575, 0x6f6d3b65, 0x2f6c6564, 0x766e6f63, 
    0x732d6431, 0x6c6c616d, 0x6c61622d, 0x65636e61, 0x2f332d64, 0x6579616c, 0x2f375f72, 0x63746162, 
    0x726f6e68, 0x756d2f6d, 0x3b315f6c, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 0x6d732d64, 0x2d6c6c61, 
    0x616c6162, 0x6465636e, 0x6c2f332d, 0x72657961, 0x432f365f, 0x31766e6f, 0x00000044, 0x00000004, 
    0x00000001, 0x00000001, 0x0000000c, 0x00000020, 0xfffff936, 0x01000000, 0x00000010, 0x00000010, 
    0x00000013, 0x0000009c, 0xfffff920, 0x0000008c, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x616d732d, 
    0x622d6c6c, 0x6e616c61, 0x2d646563, 0x616c2f33, 0x5f726579, 0x65522f35, 0x6d3b756c, 0x6c65646f, 
    0x6e6f632f, 0x2d643176, 0x6c616d73, 0x61622d6c, 0x636e616c, 0x332d6465, 0x79616c2f, 0x345f7265, 
    0x6e6f432f, 0x2f443176, 0x65757153, 0x3b657a65, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x616d732d, 
    0x622d6c6c, 0x6e616c61, 0x2d646563, 0x616c2f33, 0x5f726579, 0x6f432f34, 0x4431766e, 0x00000000, 
    0x00000004, 0x00000001, 0x00000001, 0x0000000c, 0x00000020, 0xfffff9fa, 0x01000000, 0x00000010, 
    0x00000010, 0x00000012, 0x00000108, 0xfffff9e4, 0x000000f9, 0x65646f6d, 0x6f632f6c, 0x6431766e, 
    0x616d732d, 0x622d6c6c, 0x6e616c61, 0x2d646563, 0x616c2f33, 0x5f726579, 0x65522f33, 0x6d3b756c, 
    0x6c65646f, 0x6e6f632f, 0x2d643176, 0x6c616d73, 0x61622d6c, 0x636e616c, 0x332d6465, 0x79616c2f, 
    0x325f7265, 0x7461622f, 0x6f6e6863, 0x612f6d72, 0x315f6464, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 
    0x6d732d64, 0x2d6c6c61, 0x616c6162, 0x6465636e, 0x6c2f332d, 0x72657961, 0x432f315f, 0x31766e6f, 
    0x71532f44, 0x7a656575, 0x6f6d3b65, 0x2f6c6564, 0x766e6f63, 0x732d6431, 0x6c6c616d, 0x6c61622d, 
    0x65636e61, 0x2f332d64, 0x6579616c, 0x2f325f72, 0x63746162, 0x726f6e68, 0x756d2f6d, 0x3b315f6c, 
    0x646f6d3b, 0x632f6c65, 0x31766e6f, 0x6d732d64, 0x2d6c6c61, 0x616c6162, 0x6465636e, 0x6c2f332d, 
    0x72657961, 0x432f315f, 0x31766e6f, 0x00000044, 0x00000004, 0x00000001, 0x00000001, 0x0000000c, 
    0x00000020, 0xfffffb2a, 0x01000000, 0x00000010, 0x00000010, 0x00000011, 0x000000a0, 0xfffffb14, 
    0x00000090, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x616d732d, 0x622d6c6c, 0x6e616c61, 0x2d646563, 
    0x616c2f33, 0x5f726579, 0x69422f30, 0x64417361, 0x6f6d3b64, 0x2f6c6564, 0x766e6f63, 0x732d6431, 
    0x6c6c616d, 0x6c61622d, 0x65636e61, 0x2f332d64, 0x6579616c, 0x2f305f72, 0x766e6f43, 0x532f4431, 
    0x65657571, 0x3b3b657a, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x616d732d, 0x622d6c6c, 0x6e616c61, 
    0x2d646563, 0x616c2f33, 0x5f726579, 0x6f432f30, 0x4431766e, 0x00000000, 0x00000004, 0x00000001, 
    0x00000001, 0x00000018, 0x0000000d, 0xfffffbf2, 0x01000000, 0x00000010, 0x00000010, 0x00000010, 
    0x00000048, 0xfffffbdc, 0x00000038, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x616d732d, 0x622d6c6c, 
    0x6e616c61, 0x2d646563, 0x616c2f33, 0x5f726579, 0x6f432f30, 0x4431766e, 0x7078452f, 0x44646e61, 
    0x31736d69, 0x00000000, 0x00000004, 0x00000001, 0x00000001, 0x00000032, 0x0000001e, 0xfffffde6, 
    0x01000000, 0x00000014, 0x00000014, 0x0000000f, 0x02000000, 0x00000044, 0xfffffc50, 0x00000037, 
    0x65646f6d, 0x6f632f6c, 0x6431766e, 0x616d732d, 0x622d6c6c, 0x6e616c61, 0x2d646563, 0x616c2f33, 
    0x5f726579, 0x6f432f30, 0x4431766e, 0x7078452f, 0x44646e61, 0x00736d69, 0x00000001, 0x00000004, 
    0xfffffe4a, 0x01000000, 0x00000014, 0x00000014, 0x0000000e, 0x02000000, 0x00000020, 0xfffffcb4, 
    0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 0x3231746e, 0x00000000, 0x00000000, 0xfffffd02, 
    0x01000000, 0x00000010, 0x00000010, 0x0000000d, 0x00000020, 0xfffffcec, 0x00000010, 0x74697261, 
    0x6f632e68, 0x6174736e, 0x3131746e, 0x00000000, 0x00000001, 0x00000005, 0xfffffd3e, 0x01000000, 
    0x00000010, 0x00000010, 0x0000000c, 0x00000020, 0xfffffd28, 0x00000010, 0x74697261, 0x6f632e68, 
    0x6174736e, 0x3031746e, 0x00000000, 0x00000002, 0x00000005, 0x00000020, 0xfffffd7e, 0x01000000, 
    0x00000010, 0x00000010, 0x0000000b, 0x0000001c, 0xfffffd68, 0x0000000f, 0x74697261, 0x6f632e68, 
    0x6174736e, 0x0039746e, 0x00000004, 0x0000000d, 0x00000001, 0x00000003, 0x0000001e, 0xfffffdc2, 
    0x01000000, 0x00000010, 0x00000010, 0x0000000a, 0x0000001c, 0xfffffdac, 0x0000000f, 0x74697261, 
    0x6f632e68, 0x6174736e, 0x0038746e, 0x00000001, 0x00000020, 0xfffffdfa, 0x01000000, 0x00000010, 
    0x00000010, 0x00000009, 0x0000001c, 0xfffffde4, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 
    0x0037746e, 0x00000004, 0x00000020, 0x00000001, 0x00000003, 0x00000020, 0xffffffc2, 0x01000000, 
    0x00000014, 0x00000014, 0x00000008, 0x02000000, 0x0000001c, 0xfffffe2c, 0x0000000f, 0x74697261, 
    0x6f632e68, 0x6174736e, 0x0036746e, 0x00000001, 0x00000004, 0x00160000, 0x0018001c, 0x00100017, 
    0x0008000c, 0x00000000, 0x00070000, 0x00000016, 0x01000000, 0x00000014, 0x00000014, 0x00000007, 
    0x02000000, 0x0000001c, 0xfffffe80, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0035746e, 
    0x00000001, 0x00000003, 0xfffffece, 0x01000000, 0x00000010, 0x00000010, 0x00000006, 0x0000001c, 
    0xfffffeb8, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0034746e, 0x00000001, 0x0000000d, 
    0xffffff06, 0x01000000, 0x00000010, 0x00000010, 0x00000005, 0x0000001c, 0xfffffef0, 0x0000000f, 
    0x74697261, 0x6f632e68, 0x6174736e, 0x0033746e, 0x00000004, 0x00000020, 0x00000001, 0x00000003, 
    0x0000000d, 0xffffff4a, 0x01000000, 0x00000010, 0x00000010, 0x00000004, 0x0000001c, 0xffffff34, 
    0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0032746e, 0x00000004, 0x00000020, 0x00000001, 
    0x00000003, 0x00000020, 0xffffff8e, 0x01000000, 0x00000010, 0x00000010, 0x00000003, 0x0000001c, 
    0xffffff78, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0031746e, 0x00000001, 0x00000020, 
    0xffffffc6, 0x01000000, 0x00000010, 0x00000010, 0x00000002, 0x0000001c, 0xffffffb0, 0x0000000e, 
    0x74697261, 0x6f632e68, 0x6174736e, 0x0000746e, 0x00000001, 0x00000020, 0x00160000, 0x00140018, 
    0x00100000, 0x0008000c, 0x00000000, 0x00070000, 0x00000016, 0x01000000, 0x00000014, 0x00000014, 
    0x00000001, 0x0000002c, 0x00040004, 0x00000004, 0x00000019, 0x76726573, 0x5f676e69, 0x61666564, 
    0x5f746c75, 0x6579616c, 0x3a305f72, 0x00000030, 0x00000003, 0x00000001, 0x00000032, 0x0000001e, 
    0x00000006, 0x00000060, 0x00000044, 0x00000034, 0x00000024, 0x00000014, 0x00000004, 0xffffffc4, 
    0x00000019, 0x19000000, 0xffffffd0, 0x00000009, 0x09000000, 0xffffffdc, 0x00000028, 0x28000000, 
    0xffffffe8, 0x00000011, 0x11000000, 0xfffffff4, 0x00000003, 0x03000000, 0x000c000c, 0x0000000b, 
    0x00040000, 0x0000000c, 0x00000016, 0x16000000
};

static const uint32_t _k11[] = {
    0x00000000, 0x381e87c4, 0x391e863b, 0x39b25423, 0x3a1e8019, 0x3a77a0f6, 0x3ab2449b, 0x3af29a52, 
    0x3b1e6790, 0x3b487014, 0x3b776514, 0x3b95a260, 0x3bb2068a, 0x3bd0ddef, 0x3bf2275e, 0x3c0af0c6, 
    0x3c1e058c, 0x3c325144, 0x3c47d325, 0x3c5e8a59, 0x3c767600, 0x3c87ca96, 0x3c94f373, 0x3ca2b513, 
    0x3cb10eef, 0x3cc00079, 0x3ccf891c, 0x3cdfa83e, 0x3cf05d41, 0x3d00d3bf, 0x3d09c324, 0x3d12fc79, 
    0x3d1c7f61, 0x3d264b7e, 0x3d306070, 0x3d3abdd2, 0x3d45633d, 0x3d505049, 0x3d5b8488, 0x3d66ff8d, 
    0x3d72c0e4, 0x3d7ec81a, 0x3d858a5c, 0x3d8bd322, 0x3d923e20, 0x3d98cb17, 0x3d9f79c6, 0x3da649eb, 
    0x3dad3b42, 0x3db44d87, 0x3dbb8073, 0x3dc2d3c0, 0x3dca4724, 0x3dd1da56, 0x3dd98d0a, 0x3de15ef5, 
    0x3de94fc9, 0x3df15f37, 0x3df98cef, 0x3e00ec51, 0x3e0520fd, 0x3e096453, 0x3e0db62a, 0x3e121654, 
    0x3e1684a9, 0x3e1b00fb, 0x3e1f8b1e, 0x3e2422e6, 0x3e28c824, 0x3e2d7aab, 0x3e323a4b, 0x3e3706d7, 
    0x3e3be01f, 0x3e40c5f2, 0x3e45b820, 0x3e4ab678, 0x3e4fc0c8, 0x3e54d6df, 0x3e59f88a, 0x3e5f2596, 
    0x3e645dd0, 0x3e69a105, 0x3e6eeeff, 0x3e74478b, 0x3e79aa74, 0x3e7f1784, 0x3e824743, 0x3e8507a1, 
    0x3e87ccc2, 0x3e8a968a, 0x3e8d64dd, 0x3e9037a0, 0x3e930eb6, 0x3e95ea04, 0x3e98c96d, 0x3e9bacd4, 
    0x3e9e941e, 0x3ea17f2c, 0x3ea46de3, 0x3ea76026, 0x3eaa55d6, 0x3ead4ed8, 0x3eb04b0c, 0x3eb34a56, 
    0x3eb64c99, 0x3eb951b5, 0x3ebc598e, 0x3ebf6406, 0x3ec270fd, 0x3ec58056, 0x3ec891f3, 0x3ecba5b5, 
    0x3ecebb7e, 0x3ed1d32f, 0x3ed4ecaa, 0x3ed807cf, 0x3edb2480, 0x3ede429f, 0x3ee1620c, 0x3ee482a8, 
    0x3ee7a455, 0x3eeac6f2, 0x3eedea63, 0x3ef10e86, 0x3ef4333d, 0x3ef7586a, 0x3efa7dec, 0x3efda3a4, 
    0x3f0064ba, 0x3f01f79e, 0x3f038a6f, 0x3f051d1d, 0x3f06af97, 0x3f0841d0, 0x3f09d3b7, 0x3f0b653c, 
    0x3f0cf651, 0x3f0e86e5, 0x3f1016e9, 0x3f11a64e, 0x3f133504, 0x3f14c2fc, 0x3f165025, 0x3f17dc72, 
    0x3f1967d3, 0x3f1af237, 0x3f1c7b91, 0x3f1e03d0, 0x3f1f8ae6, 0x3f2110c4, 0x3f22955a, 0x3f241899, 
    0x3f259a73, 0x3f271ad8, 0x3f2899b9, 0x3f2a1709, 0x3f2b92b7, 0x3f2d0cb6, 0x3f2e84f6, 0x3f2ffb69, 
    0x3f317001, 0x3f32e2af, 0x3f345365, 0x3f35c214, 0x3f372eaf, 0x3f389927, 0x3f3a016e, 0x3f3b6776, 
    0x3f3ccb32, 0x3f3e2c94, 0x3f3f8b8d, 0x3f40e811, 0x3f424212, 0x3f439982, 0x3f44ee55, 0x3f46407c, 
    0x3f478fec, 0x3f48dc96, 0x3f4a266f, 0x3f4b6d69, 0x3f4cb177, 0x3f4df28e, 0x3f4f30a0, 0x3f506ba2, 
    0x3f51a386, 0x3f52d842, 0x3f5409c9, 0x3f553810, 0x3f56630a, 0x3f578aac, 0x3f58aeeb, 0x3f59cfbb, 
    0x3f5aed11, 0x3f5c06e2, 0x3f5d1d24, 0x3f5e2fcb, 0x3f5f3ecc, 0x3f604a1e, 0x3f6151b6, 0x3f62558a, 
    0x3f63558f, 0x3f6451bc, 0x3f654a07, 0x3f663e67, 0x3f672ed2, 0x3f681b3e, 0x3f6903a2, 0x3f69e7f7, 
    0x3f6ac831, 0x3f6ba44a, 0x3f6c7c39, 0x3f6d4ff4, 0x3f6e1f74, 0x3f6eeab2, 0x3f6fb1a4, 0x3f707443, 
    0x3f713289, 0x3f71ec6c, 0x3f72a1e7, 0x3f7352f3, 0x3f73ff87, 0x3f74a79e, 0x3f754b32, 0x3f75ea3b, 
    0x3f7684b4, 0x3f771a97, 0x3f77abdd, 0x3f783882, 0x3f78c080, 0x3f7943d1, 0x3f79c270, 0x3f7a3c5a, 
    0x3f7ab188, 0x3f7b21f6, 0x3f7b8da1, 0x3f7bf483, 0x3f7c5699, 0x3f7cb3df, 0x3f7d0c52, 0x3f7d5fee, 
    0x3f7daeaf, 0x3f7df893, 0x3f7e3d97, 0x3f7e7db8, 0x3f7eb8f4, 0x3f7eef48, 0x3f7f20b3, 0x3f7f4d32, 
    0x3f7f74c3, 0x3f7f9766, 0x3f7fb519, 0x3f7fcdda, 0x3f7fe1a9, 0x3f7ff085, 0x3f7ffa6d, 0x3f7fff61, 
    0x3f7fff61, 0x3f7ffa6d, 0x3f7ff085, 0x3f7fe1a9, 0x3f7fcdda, 0x3f7fb519, 0x3f7f9766, 0x3f7f74c3, 
    0x3f7f4d32, 0x3f7f20b3, 0x3f7eef48, 0x3f7eb8f4, 0x3f7e7db8, 0x3f7e3d97, 0x3f7df893, 0x3f7daeaf, 
    0x3f7d5fee, 0x3f7d0c52, 0x3f7cb3df, 0x3f7c5699, 0x3f7bf483, 0x3f7b8da1, 0x3f7b21f6, 0x3f7ab188, 
    0x3f7a3c5a, 0x3f79c270, 0x3f7943d1, 0x3f78c080, 0x3f783882, 0x3f77abdd, 0x3f771a97, 0x3f7684b4, 
    0x3f75ea3b, 0x3f754b32, 0x3f74a79e, 0x3f73ff87, 0x3f7352f3, 0x3f72a1e7, 0x3f71ec6c, 0x3f713289, 
    0x3f707443, 0x3f6fb1a4, 0x3f6eeab2, 0x3f6e1f74, 0x3f6d4ff4, 0x3f6c7c39, 0x3f6ba44a, 0x3f6ac831, 
    0x3f69e7f7, 0x3f6903a2, 0x3f681b3e, 0x3f672ed2, 0x3f663e67, 0x3f654a07, 0x3f6451bc, 0x3f63558f, 
    0x3f62558a, 0x3f6151b6, 0x3f604a1e, 0x3f5f3ecc, 0x3f5e2fcb, 0x3f5d1d24, 0x3f5c06e2, 0x3f5aed11, 
    0x3f59cfbb, 0x3f58aeeb, 0x3f578aac, 0x3f56630a, 0x3f553810, 0x3f5409c9, 0x3f52d842, 0x3f51a386, 
    0x3f506ba2, 0x3f4f30a0, 0x3f4df28e, 0x3f4cb177, 0x3f4b6d69, 0x3f4a266f, 0x3f48dc96, 0x3f478fec, 
    0x3f46407c, 0x3f44ee55, 0x3f439982, 0x3f424212, 0x3f40e811, 0x3f3f8b8d, 0x3f3e2c94, 0x3f3ccb32, 
    0x3f3b6776, 0x3f3a016e, 0x3f389927, 0x3f372eaf, 0x3f35c214, 0x3f345365, 0x3f32e2af, 0x3f317001, 
    0x3f2ffb69, 0x3f2e84f6, 0x3f2d0cb6, 0x3f2b92b7, 0x3f2a1709, 0x3f2899b9, 0x3f271ad8, 0x3f259a73, 
    0x3f241899, 0x3f22955a, 0x3f2110c4, 0x3f1f8ae6, 0x3f1e03d0, 0x3f1c7b91, 0x3f1af237, 0x3f1967d3, 
    0x3f17dc72, 0x3f165025, 0x3f14c2fc, 0x3f133504, 0x3f11a64e, 0x3f1016e9, 0x3f0e86e5, 0x3f0cf651, 
    0x3f0b653c, 0x3f09d3b7, 0x3f0841d0, 0x3f06af97, 0x3f051d1d, 0x3f038a6f, 0x3f01f79e, 0x3f0064ba, 
    0x3efda3a4, 0x3efa7dec, 0x3ef7586a, 0x3ef4333d, 0x3ef10e86, 0x3eedea63, 0x3eeac6f2, 0x3ee7a455, 
    0x3ee482a8, 0x3ee1620c, 0x3ede429f, 0x3edb2480, 0x3ed807cf, 0x3ed4ecaa, 0x3ed1d32f, 0x3ecebb7e, 
    0x3ecba5b5, 0x3ec891f3, 0x3ec58056, 0x3ec270fd, 0x3ebf6406, 0x3ebc598e, 0x3eb951b5, 0x3eb64c99, 
    0x3eb34a56, 0x3eb04b0c, 0x3ead4ed8, 0x3eaa55d6, 0x3ea76026, 0x3ea46de3, 0x3ea17f2c, 0x3e9e941e, 
    0x3e9bacd4, 0x3e98c96d, 0x3e95ea04, 0x3e930eb6, 0x3e9037a0, 0x3e8d64dd, 0x3e8a968a, 0x3e87ccc2, 
    0x3e8507a1, 0x3e824743, 0x3e7f1784, 0x3e79aa74, 0x3e74478b, 0x3e6eeeff, 0x3e69a105, 0x3e645dd0, 
    0x3e5f2596, 0x3e59f88a, 0x3e54d6df, 0x3e4fc0c8, 0x3e4ab678, 0x3e45b820, 0x3e40c5f2, 0x3e3be01f, 
    0x3e3706d7, 0x3e323a4b, 0x3e2d7aab, 0x3e28c824, 0x3e2422e6, 0x3e1f8b1e, 0x3e1b00fb, 0x3e1684a9, 
    0x3e121654, 0x3e0db62a, 0x3e096453, 0x3e0520fd, 0x3e00ec51, 0x3df98cef, 0x3df15f37, 0x3de94fc9, 
    0x3de15ef5, 0x3dd98d0a, 0x3dd1da56, 0x3dca4724, 0x3dc2d3c0, 0x3dbb8073, 0x3db44d87, 0x3dad3b42, 
    0x3da649eb, 0x3d9f79c6, 0x3d98cb17, 0x3d923e20, 0x3d8bd322, 0x3d858a5c, 0x3d7ec81a, 0x3d72c0e4, 
    0x3d66ff8d, 0x3d5b8488, 0x3d505049, 0x3d45633d, 0x3d3abdd2, 0x3d306070, 0x3d264b7e, 0x3d1c7f61, 
    0x3d12fc79, 0x3d09c324, 0x3d00d3bf, 0x3cf05d41, 0x3cdfa83e, 0x3ccf891c, 0x3cc00079, 0x3cb10eef, 
    0x3ca2b513, 0x3c94f373, 0x3c87ca96, 0x3c767600, 0x3c5e8a59, 0x3c47d325, 0x3c325144, 0x3c1e058c, 
    0x3c0af0c6, 0x3bf2275e, 0x3bd0ddef, 0x3bb2068a, 0x3b95a260, 0x3b776514, 0x3b487014, 0x3b1e6790, 
    0x3af29a52, 0x3ab2449b, 0x3a77a0f6, 0x3a1e8019, 0x39b25423, 0x391e863b, 0x381e87c4, 0x00000000
};

static const uint32_t _k23[] = {
    0x00080006, 0x000d000a, 0x0012000f, 0x00180015, 0x001f001b, 0x00270023, 0x0030002b, 0x003b0035, 
    0x00470040, 0x0055004d, 0x0065005c, 0x0077006d, 0x008c0081, 0x00a40098, 0x00c000b2, 0x00e000cf
};

// Memory mapped buffers
#define _K11             ((float *)_k11)                     // f32[512] (2048 bytes)
#define _K23             ((int16_t *)_k23)                   // s16[32] (64 bytes)
#define _K7              ((uint8_t *)_k7)                    // u8[39888] (39888 bytes)
#define _K10             ((int8_t *)(_state + 0x00002110))   // s8[8] (8 bytes)
#define _K18             ((int32_t *)(_state + 0x00006120))  // s32[24] (96 bytes)
#define _K19             ((float *)(_state + 0x00006180))    // f32[258] (1032 bytes)
#define _K2              ((int8_t *)(_state + 0x00000000))   // s8[2256] (2256 bytes)
#define _K5              ((int8_t *)(_state + 0x000008d0))   // s8[6208] (6208 bytes)
#define _K6              ((uint8_t *)(_state + 0x00002120))  // u8[16384] (16384 bytes)
#define _K1              ((float *)(_buffer + 0x00000000))   // f32[512] (2048 bytes)
#define _K15             ((float *)(_buffer + 0x00000800))   // f32[512] (2048 bytes)
#define _K16             ((float *)(_buffer + 0x00001000))   // f32[257,2] (2056 bytes)
#define _K20             ((float *)(_buffer + 0x00001808))   // f32[1026] (4104 bytes)
#define _K22             ((float *)(_buffer + 0x00000000))   // f32[257] (1028 bytes)
#define _K27             ((float *)(_buffer + 0x00000404))   // f32[30] (120 bytes)
#define _K28             ((float *)(_buffer + 0x00000000))   // f32[30] (120 bytes)
#define _K3              ((float *)(_buffer + 0x00000078))   // f32[30] (120 bytes)
#define _K4              ((float *)(_buffer + 0x00000000))   // f32[50,30] (6000 bytes)

#define IPWIN_RET_SUCCESS 0
#define IPWIN_RET_NODATA -1
#define IPWIN_RET_ERROR -2
#define IPWIN_RET_STREAMEND -3

#ifdef IMAI_PROFILING
	static uint32_t region_profile_visits[IMAI_REGIONS_COUNT];
	static uint64_t region_start[IMAI_REGIONS_COUNT];
	static uint64_t region_profile_sum[IMAI_REGIONS_COUNT];
	static uint64_t region_profile_max[IMAI_REGIONS_COUNT];
	static char* region_names[] = IMAI_REGIONS_NAMES;
	static const char* region_notes[] = IMAI_REGIONS_NOTES;

	#define __HOOK_REGION(entered, region_id) hook_region(entered, region_id)
	#define __CLOSE_HOOKS() close_regions()

	int IMAI_get_ticks(uint64_t *val) { return 0; }
    int (*IMAI_get_ticks_ptr)(uint64_t* val) = &IMAI_get_ticks;

	ATTRIB_WEAK void IMAI_hook_region(bool entered, int32_t region_id) {
		uint64_t ticks = 0;
		// assign the current tick count with a BSP or custom function
		IMAI_get_ticks_ptr(&ticks);
		 if (entered) {
			 region_start[region_id] = ticks;
		}
		else {
			ticks = ticks - region_start[region_id];
			region_profile_visits[region_id]++;
			if (ticks > region_profile_max[region_id])
				region_profile_max[region_id] = ticks;
			region_profile_sum[region_id] += ticks;
		}
	}
	
	static bool region_entered[IMAI_REGIONS_COUNT];
	
	static inline void hook_region(bool entered, int32_t region_id) {
		region_entered[region_id] = entered;
		IMAI_hook_region(entered, region_id);
	}
	
	static inline void close_regions() {
		uint32_t i = 0;
		for (i = 0; i < IMAI_REGIONS_COUNT; i++)
			if (region_entered[i])
				hook_region(false, i);
	}

	void IMAI_print_region_profiling(void) {
		uint32_t i = 0;
		printf("Region profiling results:\r\n");
		for (i = 0; i < IMAI_REGIONS_COUNT; i++) {
			if (region_notes[i] != NULL && region_notes[i][0] != '\0') {
				printf("Region \"%s\"; %s\r\n",
					region_names[i],
					region_notes[i]);
			}
			else {
				printf("Region \"%s\"; visits: %lu, max cycles: %-10.2f, avg cycles: %-10.2f\r\n",
					region_names[i],
					(unsigned long)region_profile_visits[i],
					(float)region_profile_max[i],
					(float)region_profile_sum[i] / region_profile_visits[i]);
			}
		}
		printf("\r\n");
	}
#else
	#define __HOOK_REGION(entered, region_id) do { } while(0)
	#define __CLOSE_HOOKS() do { } while(0)

	void IMAI_print_region_profiling(void) {
		(void)0;
	}
#endif

// Represents a Circular Buffer
// https://en.wikipedia.org/wiki/Circular_buffer
typedef struct
{
	char *buf;
	int size;		// total bytes allocated in *buf
	int used;		// current bytes used in buffer.
	int read;
	int write;
} cbuffer_t;

#define CBUFFER_SUCCESS 0
#define CBUFFER_NOMEM -1

// Reset instance (clear buffer)
static inline void cbuffer_reset(cbuffer_t* buf) {
	buf->read = 0;
	buf->write = 0;
	buf->used = 0;
}

// Initializes a cbuffer handle with given memory and size.
static inline void cbuffer_init(cbuffer_t *dest, void *mem, int size) {
	dest->buf = mem;
	dest->size = size;
	cbuffer_reset(dest);
}

// Returns the number of free bytes in buffer.
static inline int cbuffer_get_free(cbuffer_t *buf) {
	return buf->size - buf->used;
}

// Returns the number of used bytes in buffer.
static inline int cbuffer_get_used(cbuffer_t *buf) {
	return buf->used;
}

// Writes given data to buffer.
// Returns CBUFFER_SUCCESS or CBUFFER_NOMEM if out of memory.
static inline int cbuffer_enqueue(cbuffer_t *buf, const void *data, int data_size) {
	int free = cbuffer_get_free(buf);

	// Out of memory?
	if (free < data_size)
		return CBUFFER_NOMEM;

	// Is the data split in the end?
	if (buf->write + data_size > buf->size) {
		int first_size = buf->size - buf->write;
		memcpy(buf->buf + buf->write, data, first_size);
		memcpy(buf->buf, ((char *)data) + first_size, data_size - first_size);
	}
	else {
		memcpy(buf->buf + buf->write, data, data_size);
	}
	buf->write += data_size;
	if (buf->write >= buf->size)
		buf->write -= buf->size;

	buf->used += data_size;
	return CBUFFER_SUCCESS;
}

// Advances the read pointer by given count.
// Returns CBUFFER_SUCCESS on success or CBUFFER_NOMEM if count is more than available data
static inline int cbuffer_advance(cbuffer_t *buf, int count) {
	int used = cbuffer_get_used(buf);

	if (count > used)
		return CBUFFER_NOMEM;

	buf->read += count;
	if (buf->read >= buf->size)
		buf->read -= buf->size;

	// Reset pointers to 0 if buffer is empty in order to avoid unwanted wrapps.
	if (buf->read == buf->write) {
		buf->read = 0;
		buf->write = 0;
	}

	buf->used -= count;
	return CBUFFER_SUCCESS;
}

// Returns a read pointer at given offset and  
// updates *can_read_bytes (if not NULL) with the number of bytes that can be read.
// 
// Note! Byte count written to can_read_bytes can be less than what cbuffer_get_used() returns.
// This happens when the read has to be split in two since it's a circular buffer.
static inline void* cbuffer_readptr(cbuffer_t* buf, int offset, int* can_read_bytes)
{
	int a0 = buf->read + offset;
	if (a0 >= buf->size)
		a0 -= buf->size;
	if (can_read_bytes != NULL)
	{
		int c0 = buf->used;
		if (a0 + c0 > buf->size)
			c0 = buf->size - a0;

		*can_read_bytes = c0;
	}
	return buf->buf + a0;
}

// Copies given "count" bytes to the "dst" buffer without advancing the buffer read offset.
// Returns CBUFFER_SUCCESS on success or CBUFFER_NOMEM if count is more than available data.
static inline int cbuffer_copyto(cbuffer_t *buf, void *dst, int count, int offset) {
	
	if (count > cbuffer_get_used(buf))
		return CBUFFER_NOMEM;

	int can_read_bytes;
	void* src_ptr = cbuffer_readptr(buf, offset, &can_read_bytes);

	int c0 = (count < can_read_bytes) ? count : can_read_bytes;
	memcpy(dst, src_ptr, c0);
	
	int c1 = count - c0;

	if (c1 > 0)
		memcpy(((char *)dst) + c0, buf->buf, c1);

	return CBUFFER_SUCCESS;
}

typedef struct {
	cbuffer_t data_buffer;			// Circular Buffer for features
	int input_size;					// Number of bytes in each input chunk
} fixwin_t;

#ifdef _MSC_VER
static_assert(sizeof(fixwin_t) <= 64, "Data structure 'fixwin_t' is too big");
#endif

/*
* Try to dequeue a window.
*
* @param handle Pointer to an initialized handle.
* @param dst Pointer where to write window.
* @param stride_count Number of items (of size handle->input_size) to stride window.
* @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1) is no data is available.
*/
static inline int fixwin_dequeue(void* restrict handle, void* restrict dst, int count, int stride_count)
{
	fixwin_t* fep = (fixwin_t*)handle;

	const int stride_bytes = stride_count * fep->input_size;
	const int size = count * fep->input_size;
	if (cbuffer_get_used(&fep->data_buffer) >= size) {
		if (cbuffer_copyto(&fep->data_buffer, dst, size, 0) != 0)
			return IPWIN_RET_ERROR;

		if (cbuffer_advance(&fep->data_buffer, stride_bytes) != 0)
			return IPWIN_RET_ERROR;

		return IPWIN_RET_SUCCESS;
	}
	return IPWIN_RET_NODATA;
}

// input array (any shape >= 1D)
// output array (same shape as input array)
// d0 = input.shape.step(axis)
// d1 = input.shape.size(axis)
// d2 = input.shape.slot(axis)
static inline void hannmul_f32(const float* restrict input, const float* restrict w, int d0, int d1, int d2, float* restrict output)
{
	const int d3 = d0 * d1;

	const float* ip = input;
	float* op = output;

	for (int j = 0; j < d2; j++) {
		for (int i = 0; i < d0; i++) {
			for (int k = 0; k < d1; k++) {
				op[k * d0 + i] = ip[k * d0 + i] * w[k];
			}
		}

		ip += d3;
		op += d3;
	}
}

static void makeipt(int nw, int *ip)
{
    int j, l, m, m2, p, q;
    
    ip[2] = 0;
    ip[3] = 16;
    m = 2;
    for (l = nw; l > 32; l >>= 2) {
        m2 = m << 1;
        q = m2 << 3;
        for (j = m; j < m2; j++) {
            p = ip[j] << 2;
            ip[m + j] = p;
            ip[m2 + j] = p + q;
        }
        m = m2;
    }
}

static void makewt(int nw, int *ip, float *w)
{
    void makeipt(int nw, int *ip);
    int j, nwh, nw0, nw1;
    float delta, wn4r, wk1r, wk1i, wk3r, wk3i;
    
    ip[0] = nw;
    ip[1] = 1;
    if (nw > 2) {
        nwh = nw >> 1;
        delta = atan(1.0) / nwh;
        wn4r = cos(delta * nwh);
        w[0] = 1;
        w[1] = wn4r;
        if (nwh == 4) {
            w[2] = cos(delta * 2);
            w[3] = sin(delta * 2);
        } else if (nwh > 4) {
            makeipt(nw, ip);
            w[2] = 0.5 / cos(delta * 2);
            w[3] = 0.5 / cos(delta * 6);
            for (j = 4; j < nwh; j += 4) {
                w[j] = cos(delta * j);
                w[j + 1] = sin(delta * j);
                w[j + 2] = cos(3 * delta * j);
                w[j + 3] = -sin(3 * delta * j);
            }
        }
        nw0 = 0;
        while (nwh > 2) {
            nw1 = nw0 + nwh;
            nwh >>= 1;
            w[nw1] = 1;
            w[nw1 + 1] = wn4r;
            if (nwh == 4) {
                wk1r = w[nw0 + 4];
                wk1i = w[nw0 + 5];
                w[nw1 + 2] = wk1r;
                w[nw1 + 3] = wk1i;
            } else if (nwh > 4) {
                wk1r = w[nw0 + 4];
                wk3r = w[nw0 + 6];
                w[nw1 + 2] = 0.5 / wk1r;
                w[nw1 + 3] = 0.5 / wk3r;
                for (j = 4; j < nwh; j += 4) {
                    wk1r = w[nw0 + 2 * j];
                    wk1i = w[nw0 + 2 * j + 1];
                    wk3r = w[nw0 + 2 * j + 2];
                    wk3i = w[nw0 + 2 * j + 3];
                    w[nw1 + j] = wk1r;
                    w[nw1 + j + 1] = wk1i;
                    w[nw1 + j + 2] = wk3r;
                    w[nw1 + j + 3] = wk3i;
                }
            }
            nw0 = nw1;
        }
    }
}

static void makect(int nc, int *ip, float *c)
{
    int j, nch;
    float delta;
    
    ip[1] = nc;
    if (nc > 1) {
        nch = nc >> 1;
        delta = atan(1.0) / nch;
        c[0] = cos(delta * nch);
        c[nch] = 0.5 * c[0];
        for (j = 1; j < nch; j++) {
            c[j] = 0.5 * cos(delta * j);
            c[nc - j] = 0.5 * sin(delta * j);
        }
    }
}

static void bitrv2(int n, int *ip, float *a)
{
    int j, j1, k, k1, l, m, nh, nm;
    float xr, xi, yr, yi;
    
    m = 1;
    for (l = n >> 2; l > 8; l >>= 2) {
        m <<= 1;
    }
    nh = n >> 1;
    nm = 4 * m;
    if (l == 8) {
        for (k = 0; k < m; k++) {
            for (j = 0; j < k; j++) {
                j1 = 4 * j + 2 * ip[m + k];
                k1 = 4 * k + 2 * ip[m + j];
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 -= nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nh;
                k1 += 2;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 += nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += 2;
                k1 += nh;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 -= nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nh;
                k1 -= 2;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 += nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
            }
            k1 = 4 * k + 2 * ip[m + k];
            j1 = k1 + 2;
            k1 += nh;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nm;
            k1 += 2 * nm;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nm;
            k1 -= nm;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 -= 2;
            k1 -= nh;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nh + 2;
            k1 += nh + 2;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 -= nh - nm;
            k1 += 2 * nm - 2;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
        }
    } else {
        for (k = 0; k < m; k++) {
            for (j = 0; j < k; j++) {
                j1 = 4 * j + ip[m + k];
                k1 = 4 * k + ip[m + j];
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nh;
                k1 += 2;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += 2;
                k1 += nh;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nh;
                k1 -= 2;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= nm;
                xr = a[j1];
                xi = a[j1 + 1];
                yr = a[k1];
                yi = a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
            }
            k1 = 4 * k + ip[m + k];
            j1 = k1 + 2;
            k1 += nh;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nm;
            k1 += nm;
            xr = a[j1];
            xi = a[j1 + 1];
            yr = a[k1];
            yi = a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
        }
    }
}

static void bitrv216(float *a)
{
    float x1r, x1i, x2r, x2i, x3r, x3i, x4r, x4i, 
        x5r, x5i, x7r, x7i, x8r, x8i, x10r, x10i, 
        x11r, x11i, x12r, x12i, x13r, x13i, x14r, x14i;
    
    x1r = a[2];
    x1i = a[3];
    x2r = a[4];
    x2i = a[5];
    x3r = a[6];
    x3i = a[7];
    x4r = a[8];
    x4i = a[9];
    x5r = a[10];
    x5i = a[11];
    x7r = a[14];
    x7i = a[15];
    x8r = a[16];
    x8i = a[17];
    x10r = a[20];
    x10i = a[21];
    x11r = a[22];
    x11i = a[23];
    x12r = a[24];
    x12i = a[25];
    x13r = a[26];
    x13i = a[27];
    x14r = a[28];
    x14i = a[29];
    a[2] = x8r;
    a[3] = x8i;
    a[4] = x4r;
    a[5] = x4i;
    a[6] = x12r;
    a[7] = x12i;
    a[8] = x2r;
    a[9] = x2i;
    a[10] = x10r;
    a[11] = x10i;
    a[14] = x14r;
    a[15] = x14i;
    a[16] = x1r;
    a[17] = x1i;
    a[20] = x5r;
    a[21] = x5i;
    a[22] = x13r;
    a[23] = x13i;
    a[24] = x3r;
    a[25] = x3i;
    a[26] = x11r;
    a[27] = x11i;
    a[28] = x7r;
    a[29] = x7i;
}

static void bitrv208(float *a)
{
    float x1r, x1i, x3r, x3i, x4r, x4i, x6r, x6i;
    
    x1r = a[2];
    x1i = a[3];
    x3r = a[6];
    x3i = a[7];
    x4r = a[8];
    x4i = a[9];
    x6r = a[12];
    x6i = a[13];
    a[2] = x4r;
    a[3] = x4i;
    a[6] = x6r;
    a[7] = x6i;
    a[8] = x1r;
    a[9] = x1i;
    a[12] = x3r;
    a[13] = x3i;
}

static void cftf1st(int n, float *a, float *w)
{
    int j, j0, j1, j2, j3, k, m, mh;
    float wn4r, csc1, csc3, wk1r, wk1i, wk3r, wk3i, 
        wd1r, wd1i, wd3r, wd3i;
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i;
    
    mh = n >> 3;
    m = 2 * mh;
    j1 = m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[0] + a[j2];
    x0i = a[1] + a[j2 + 1];
    x1r = a[0] - a[j2];
    x1i = a[1] - a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[0] = x0r + x2r;
    a[1] = x0i + x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i - x2i;
    a[j2] = x1r - x3i;
    a[j2 + 1] = x1i + x3r;
    a[j3] = x1r + x3i;
    a[j3 + 1] = x1i - x3r;
    wn4r = w[1];
    csc1 = w[2];
    csc3 = w[3];
    wd1r = 1;
    wd1i = 0;
    wd3r = 1;
    wd3i = 0;
    k = 0;
    for (j = 2; j < mh - 2; j += 4) {
        k += 4;
        wk1r = csc1 * (wd1r + w[k]);
        wk1i = csc1 * (wd1i + w[k + 1]);
        wk3r = csc3 * (wd3r + w[k + 2]);
        wk3i = csc3 * (wd3i + w[k + 3]);
        wd1r = w[k];
        wd1i = w[k + 1];
        wd3r = w[k + 2];
        wd3i = w[k + 3];
        j1 = j + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j] + a[j2];
        x0i = a[j + 1] + a[j2 + 1];
        x1r = a[j] - a[j2];
        x1i = a[j + 1] - a[j2 + 1];
        y0r = a[j + 2] + a[j2 + 2];
        y0i = a[j + 3] + a[j2 + 3];
        y1r = a[j + 2] - a[j2 + 2];
        y1i = a[j + 3] - a[j2 + 3];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        y2r = a[j1 + 2] + a[j3 + 2];
        y2i = a[j1 + 3] + a[j3 + 3];
        y3r = a[j1 + 2] - a[j3 + 2];
        y3i = a[j1 + 3] - a[j3 + 3];
        a[j] = x0r + x2r;
        a[j + 1] = x0i + x2i;
        a[j + 2] = y0r + y2r;
        a[j + 3] = y0i + y2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i - x2i;
        a[j1 + 2] = y0r - y2r;
        a[j1 + 3] = y0i - y2i;
        x0r = x1r - x3i;
        x0i = x1i + x3r;
        a[j2] = wk1r * x0r - wk1i * x0i;
        a[j2 + 1] = wk1r * x0i + wk1i * x0r;
        x0r = y1r - y3i;
        x0i = y1i + y3r;
        a[j2 + 2] = wd1r * x0r - wd1i * x0i;
        a[j2 + 3] = wd1r * x0i + wd1i * x0r;
        x0r = x1r + x3i;
        x0i = x1i - x3r;
        a[j3] = wk3r * x0r + wk3i * x0i;
        a[j3 + 1] = wk3r * x0i - wk3i * x0r;
        x0r = y1r + y3i;
        x0i = y1i - y3r;
        a[j3 + 2] = wd3r * x0r + wd3i * x0i;
        a[j3 + 3] = wd3r * x0i - wd3i * x0r;
        j0 = m - j;
        j1 = j0 + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j0] + a[j2];
        x0i = a[j0 + 1] + a[j2 + 1];
        x1r = a[j0] - a[j2];
        x1i = a[j0 + 1] - a[j2 + 1];
        y0r = a[j0 - 2] + a[j2 - 2];
        y0i = a[j0 - 1] + a[j2 - 1];
        y1r = a[j0 - 2] - a[j2 - 2];
        y1i = a[j0 - 1] - a[j2 - 1];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        y2r = a[j1 - 2] + a[j3 - 2];
        y2i = a[j1 - 1] + a[j3 - 1];
        y3r = a[j1 - 2] - a[j3 - 2];
        y3i = a[j1 - 1] - a[j3 - 1];
        a[j0] = x0r + x2r;
        a[j0 + 1] = x0i + x2i;
        a[j0 - 2] = y0r + y2r;
        a[j0 - 1] = y0i + y2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i - x2i;
        a[j1 - 2] = y0r - y2r;
        a[j1 - 1] = y0i - y2i;
        x0r = x1r - x3i;
        x0i = x1i + x3r;
        a[j2] = wk1i * x0r - wk1r * x0i;
        a[j2 + 1] = wk1i * x0i + wk1r * x0r;
        x0r = y1r - y3i;
        x0i = y1i + y3r;
        a[j2 - 2] = wd1i * x0r - wd1r * x0i;
        a[j2 - 1] = wd1i * x0i + wd1r * x0r;
        x0r = x1r + x3i;
        x0i = x1i - x3r;
        a[j3] = wk3i * x0r + wk3r * x0i;
        a[j3 + 1] = wk3i * x0i - wk3r * x0r;
        x0r = y1r + y3i;
        x0i = y1i - y3r;
        a[j3 - 2] = wd3i * x0r + wd3r * x0i;
        a[j3 - 1] = wd3i * x0i - wd3r * x0r;
    }
    wk1r = csc1 * (wd1r + wn4r);
    wk1i = csc1 * (wd1i + wn4r);
    wk3r = csc3 * (wd3r - wn4r);
    wk3i = csc3 * (wd3i - wn4r);
    j0 = mh;
    j1 = j0 + m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[j0 - 2] + a[j2 - 2];
    x0i = a[j0 - 1] + a[j2 - 1];
    x1r = a[j0 - 2] - a[j2 - 2];
    x1i = a[j0 - 1] - a[j2 - 1];
    x2r = a[j1 - 2] + a[j3 - 2];
    x2i = a[j1 - 1] + a[j3 - 1];
    x3r = a[j1 - 2] - a[j3 - 2];
    x3i = a[j1 - 1] - a[j3 - 1];
    a[j0 - 2] = x0r + x2r;
    a[j0 - 1] = x0i + x2i;
    a[j1 - 2] = x0r - x2r;
    a[j1 - 1] = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    a[j2 - 2] = wk1r * x0r - wk1i * x0i;
    a[j2 - 1] = wk1r * x0i + wk1i * x0r;
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    a[j3 - 2] = wk3r * x0r + wk3i * x0i;
    a[j3 - 1] = wk3r * x0i - wk3i * x0r;
    x0r = a[j0] + a[j2];
    x0i = a[j0 + 1] + a[j2 + 1];
    x1r = a[j0] - a[j2];
    x1i = a[j0 + 1] - a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[j0] = x0r + x2r;
    a[j0 + 1] = x0i + x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    a[j2] = wn4r * (x0r - x0i);
    a[j2 + 1] = wn4r * (x0i + x0r);
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    a[j3] = -wn4r * (x0r + x0i);
    a[j3 + 1] = -wn4r * (x0i - x0r);
    x0r = a[j0 + 2] + a[j2 + 2];
    x0i = a[j0 + 3] + a[j2 + 3];
    x1r = a[j0 + 2] - a[j2 + 2];
    x1i = a[j0 + 3] - a[j2 + 3];
    x2r = a[j1 + 2] + a[j3 + 2];
    x2i = a[j1 + 3] + a[j3 + 3];
    x3r = a[j1 + 2] - a[j3 + 2];
    x3i = a[j1 + 3] - a[j3 + 3];
    a[j0 + 2] = x0r + x2r;
    a[j0 + 3] = x0i + x2i;
    a[j1 + 2] = x0r - x2r;
    a[j1 + 3] = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    a[j2 + 2] = wk1i * x0r - wk1r * x0i;
    a[j2 + 3] = wk1i * x0i + wk1r * x0r;
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    a[j3 + 2] = wk3i * x0r + wk3r * x0i;
    a[j3 + 3] = wk3i * x0i - wk3r * x0r;
}

static void cftmdl1(int n, float *a, float *w)
{
    int j, j0, j1, j2, j3, k, m, mh;
    float wn4r, wk1r, wk1i, wk3r, wk3i;
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i;
    
    mh = n >> 3;
    m = 2 * mh;
    j1 = m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[0] + a[j2];
    x0i = a[1] + a[j2 + 1];
    x1r = a[0] - a[j2];
    x1i = a[1] - a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[0] = x0r + x2r;
    a[1] = x0i + x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i - x2i;
    a[j2] = x1r - x3i;
    a[j2 + 1] = x1i + x3r;
    a[j3] = x1r + x3i;
    a[j3 + 1] = x1i - x3r;
    wn4r = w[1];
    k = 0;
    for (j = 2; j < mh; j += 2) {
        k += 4;
        wk1r = w[k];
        wk1i = w[k + 1];
        wk3r = w[k + 2];
        wk3i = w[k + 3];
        j1 = j + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j] + a[j2];
        x0i = a[j + 1] + a[j2 + 1];
        x1r = a[j] - a[j2];
        x1i = a[j + 1] - a[j2 + 1];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        a[j] = x0r + x2r;
        a[j + 1] = x0i + x2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i - x2i;
        x0r = x1r - x3i;
        x0i = x1i + x3r;
        a[j2] = wk1r * x0r - wk1i * x0i;
        a[j2 + 1] = wk1r * x0i + wk1i * x0r;
        x0r = x1r + x3i;
        x0i = x1i - x3r;
        a[j3] = wk3r * x0r + wk3i * x0i;
        a[j3 + 1] = wk3r * x0i - wk3i * x0r;
        j0 = m - j;
        j1 = j0 + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j0] + a[j2];
        x0i = a[j0 + 1] + a[j2 + 1];
        x1r = a[j0] - a[j2];
        x1i = a[j0 + 1] - a[j2 + 1];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        a[j0] = x0r + x2r;
        a[j0 + 1] = x0i + x2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i - x2i;
        x0r = x1r - x3i;
        x0i = x1i + x3r;
        a[j2] = wk1i * x0r - wk1r * x0i;
        a[j2 + 1] = wk1i * x0i + wk1r * x0r;
        x0r = x1r + x3i;
        x0i = x1i - x3r;
        a[j3] = wk3i * x0r + wk3r * x0i;
        a[j3 + 1] = wk3i * x0i - wk3r * x0r;
    }
    j0 = mh;
    j1 = j0 + m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[j0] + a[j2];
    x0i = a[j0 + 1] + a[j2 + 1];
    x1r = a[j0] - a[j2];
    x1i = a[j0 + 1] - a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[j0] = x0r + x2r;
    a[j0 + 1] = x0i + x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    a[j2] = wn4r * (x0r - x0i);
    a[j2 + 1] = wn4r * (x0i + x0r);
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    a[j3] = -wn4r * (x0r + x0i);
    a[j3 + 1] = -wn4r * (x0i - x0r);
}

static void cftmdl2(int n, float *a, float *w)
{
    int j, j0, j1, j2, j3, k, kr, m, mh;
    float wn4r, wk1r, wk1i, wk3r, wk3i, wd1r, wd1i, wd3r, wd3i;
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i, y0r, y0i, y2r, y2i;
    
    mh = n >> 3;
    m = 2 * mh;
    wn4r = w[1];
    j1 = m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[0] - a[j2 + 1];
    x0i = a[1] + a[j2];
    x1r = a[0] + a[j2 + 1];
    x1i = a[1] - a[j2];
    x2r = a[j1] - a[j3 + 1];
    x2i = a[j1 + 1] + a[j3];
    x3r = a[j1] + a[j3 + 1];
    x3i = a[j1 + 1] - a[j3];
    y0r = wn4r * (x2r - x2i);
    y0i = wn4r * (x2i + x2r);
    a[0] = x0r + y0r;
    a[1] = x0i + y0i;
    a[j1] = x0r - y0r;
    a[j1 + 1] = x0i - y0i;
    y0r = wn4r * (x3r - x3i);
    y0i = wn4r * (x3i + x3r);
    a[j2] = x1r - y0i;
    a[j2 + 1] = x1i + y0r;
    a[j3] = x1r + y0i;
    a[j3 + 1] = x1i - y0r;
    k = 0;
    kr = 2 * m;
    for (j = 2; j < mh; j += 2) {
        k += 4;
        wk1r = w[k];
        wk1i = w[k + 1];
        wk3r = w[k + 2];
        wk3i = w[k + 3];
        kr -= 4;
        wd1i = w[kr];
        wd1r = w[kr + 1];
        wd3i = w[kr + 2];
        wd3r = w[kr + 3];
        j1 = j + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j] - a[j2 + 1];
        x0i = a[j + 1] + a[j2];
        x1r = a[j] + a[j2 + 1];
        x1i = a[j + 1] - a[j2];
        x2r = a[j1] - a[j3 + 1];
        x2i = a[j1 + 1] + a[j3];
        x3r = a[j1] + a[j3 + 1];
        x3i = a[j1 + 1] - a[j3];
        y0r = wk1r * x0r - wk1i * x0i;
        y0i = wk1r * x0i + wk1i * x0r;
        y2r = wd1r * x2r - wd1i * x2i;
        y2i = wd1r * x2i + wd1i * x2r;
        a[j] = y0r + y2r;
        a[j + 1] = y0i + y2i;
        a[j1] = y0r - y2r;
        a[j1 + 1] = y0i - y2i;
        y0r = wk3r * x1r + wk3i * x1i;
        y0i = wk3r * x1i - wk3i * x1r;
        y2r = wd3r * x3r + wd3i * x3i;
        y2i = wd3r * x3i - wd3i * x3r;
        a[j2] = y0r + y2r;
        a[j2 + 1] = y0i + y2i;
        a[j3] = y0r - y2r;
        a[j3 + 1] = y0i - y2i;
        j0 = m - j;
        j1 = j0 + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j0] - a[j2 + 1];
        x0i = a[j0 + 1] + a[j2];
        x1r = a[j0] + a[j2 + 1];
        x1i = a[j0 + 1] - a[j2];
        x2r = a[j1] - a[j3 + 1];
        x2i = a[j1 + 1] + a[j3];
        x3r = a[j1] + a[j3 + 1];
        x3i = a[j1 + 1] - a[j3];
        y0r = wd1i * x0r - wd1r * x0i;
        y0i = wd1i * x0i + wd1r * x0r;
        y2r = wk1i * x2r - wk1r * x2i;
        y2i = wk1i * x2i + wk1r * x2r;
        a[j0] = y0r + y2r;
        a[j0 + 1] = y0i + y2i;
        a[j1] = y0r - y2r;
        a[j1 + 1] = y0i - y2i;
        y0r = wd3i * x1r + wd3r * x1i;
        y0i = wd3i * x1i - wd3r * x1r;
        y2r = wk3i * x3r + wk3r * x3i;
        y2i = wk3i * x3i - wk3r * x3r;
        a[j2] = y0r + y2r;
        a[j2 + 1] = y0i + y2i;
        a[j3] = y0r - y2r;
        a[j3 + 1] = y0i - y2i;
    }
    wk1r = w[m];
    wk1i = w[m + 1];
    j0 = mh;
    j1 = j0 + m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[j0] - a[j2 + 1];
    x0i = a[j0 + 1] + a[j2];
    x1r = a[j0] + a[j2 + 1];
    x1i = a[j0 + 1] - a[j2];
    x2r = a[j1] - a[j3 + 1];
    x2i = a[j1 + 1] + a[j3];
    x3r = a[j1] + a[j3 + 1];
    x3i = a[j1 + 1] - a[j3];
    y0r = wk1r * x0r - wk1i * x0i;
    y0i = wk1r * x0i + wk1i * x0r;
    y2r = wk1i * x2r - wk1r * x2i;
    y2i = wk1i * x2i + wk1r * x2r;
    a[j0] = y0r + y2r;
    a[j0 + 1] = y0i + y2i;
    a[j1] = y0r - y2r;
    a[j1 + 1] = y0i - y2i;
    y0r = wk1i * x1r - wk1r * x1i;
    y0i = wk1i * x1i + wk1r * x1r;
    y2r = wk1r * x3r - wk1i * x3i;
    y2i = wk1r * x3i + wk1i * x3r;
    a[j2] = y0r - y2r;
    a[j2 + 1] = y0i - y2i;
    a[j3] = y0r + y2r;
    a[j3 + 1] = y0i + y2i;
}

static int cfttree(int n, int j, int k, float *a, int nw, float *w)
{
    void cftmdl1(int n, float *a, float *w);
    void cftmdl2(int n, float *a, float *w);
    int i, isplt, m;
    
    if ((k & 3) != 0) {
        isplt = k & 1;
        if (isplt != 0) {
            cftmdl1(n, &a[j - n], &w[nw - (n >> 1)]);
        } else {
            cftmdl2(n, &a[j - n], &w[nw - n]);
        }
    } else {
        m = n;
        for (i = k; (i & 3) == 0; i >>= 2) {
            m <<= 2;
        }
        isplt = i & 1;
        if (isplt != 0) {
            while (m > 128) {
                cftmdl1(m, &a[j - m], &w[nw - (m >> 1)]);
                m >>= 2;
            }
        } else {
            while (m > 128) {
                cftmdl2(m, &a[j - m], &w[nw - m]);
                m >>= 2;
            }
        }
    }
    return isplt;
}

static void cftf161(float *a, float *w)
{
    float wn4r, wk1r, wk1i, 
        x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i, 
        y4r, y4i, y5r, y5i, y6r, y6i, y7r, y7i, 
        y8r, y8i, y9r, y9i, y10r, y10i, y11r, y11i, 
        y12r, y12i, y13r, y13i, y14r, y14i, y15r, y15i;
    
    wn4r = w[1];
    wk1r = w[2];
    wk1i = w[3];
    x0r = a[0] + a[16];
    x0i = a[1] + a[17];
    x1r = a[0] - a[16];
    x1i = a[1] - a[17];
    x2r = a[8] + a[24];
    x2i = a[9] + a[25];
    x3r = a[8] - a[24];
    x3i = a[9] - a[25];
    y0r = x0r + x2r;
    y0i = x0i + x2i;
    y4r = x0r - x2r;
    y4i = x0i - x2i;
    y8r = x1r - x3i;
    y8i = x1i + x3r;
    y12r = x1r + x3i;
    y12i = x1i - x3r;
    x0r = a[2] + a[18];
    x0i = a[3] + a[19];
    x1r = a[2] - a[18];
    x1i = a[3] - a[19];
    x2r = a[10] + a[26];
    x2i = a[11] + a[27];
    x3r = a[10] - a[26];
    x3i = a[11] - a[27];
    y1r = x0r + x2r;
    y1i = x0i + x2i;
    y5r = x0r - x2r;
    y5i = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    y9r = wk1r * x0r - wk1i * x0i;
    y9i = wk1r * x0i + wk1i * x0r;
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    y13r = wk1i * x0r - wk1r * x0i;
    y13i = wk1i * x0i + wk1r * x0r;
    x0r = a[4] + a[20];
    x0i = a[5] + a[21];
    x1r = a[4] - a[20];
    x1i = a[5] - a[21];
    x2r = a[12] + a[28];
    x2i = a[13] + a[29];
    x3r = a[12] - a[28];
    x3i = a[13] - a[29];
    y2r = x0r + x2r;
    y2i = x0i + x2i;
    y6r = x0r - x2r;
    y6i = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    y10r = wn4r * (x0r - x0i);
    y10i = wn4r * (x0i + x0r);
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    y14r = wn4r * (x0r + x0i);
    y14i = wn4r * (x0i - x0r);
    x0r = a[6] + a[22];
    x0i = a[7] + a[23];
    x1r = a[6] - a[22];
    x1i = a[7] - a[23];
    x2r = a[14] + a[30];
    x2i = a[15] + a[31];
    x3r = a[14] - a[30];
    x3i = a[15] - a[31];
    y3r = x0r + x2r;
    y3i = x0i + x2i;
    y7r = x0r - x2r;
    y7i = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    y11r = wk1i * x0r - wk1r * x0i;
    y11i = wk1i * x0i + wk1r * x0r;
    x0r = x1r + x3i;
    x0i = x1i - x3r;
    y15r = wk1r * x0r - wk1i * x0i;
    y15i = wk1r * x0i + wk1i * x0r;
    x0r = y12r - y14r;
    x0i = y12i - y14i;
    x1r = y12r + y14r;
    x1i = y12i + y14i;
    x2r = y13r - y15r;
    x2i = y13i - y15i;
    x3r = y13r + y15r;
    x3i = y13i + y15i;
    a[24] = x0r + x2r;
    a[25] = x0i + x2i;
    a[26] = x0r - x2r;
    a[27] = x0i - x2i;
    a[28] = x1r - x3i;
    a[29] = x1i + x3r;
    a[30] = x1r + x3i;
    a[31] = x1i - x3r;
    x0r = y8r + y10r;
    x0i = y8i + y10i;
    x1r = y8r - y10r;
    x1i = y8i - y10i;
    x2r = y9r + y11r;
    x2i = y9i + y11i;
    x3r = y9r - y11r;
    x3i = y9i - y11i;
    a[16] = x0r + x2r;
    a[17] = x0i + x2i;
    a[18] = x0r - x2r;
    a[19] = x0i - x2i;
    a[20] = x1r - x3i;
    a[21] = x1i + x3r;
    a[22] = x1r + x3i;
    a[23] = x1i - x3r;
    x0r = y5r - y7i;
    x0i = y5i + y7r;
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    x0r = y5r + y7i;
    x0i = y5i - y7r;
    x3r = wn4r * (x0r - x0i);
    x3i = wn4r * (x0i + x0r);
    x0r = y4r - y6i;
    x0i = y4i + y6r;
    x1r = y4r + y6i;
    x1i = y4i - y6r;
    a[8] = x0r + x2r;
    a[9] = x0i + x2i;
    a[10] = x0r - x2r;
    a[11] = x0i - x2i;
    a[12] = x1r - x3i;
    a[13] = x1i + x3r;
    a[14] = x1r + x3i;
    a[15] = x1i - x3r;
    x0r = y0r + y2r;
    x0i = y0i + y2i;
    x1r = y0r - y2r;
    x1i = y0i - y2i;
    x2r = y1r + y3r;
    x2i = y1i + y3i;
    x3r = y1r - y3r;
    x3i = y1i - y3i;
    a[0] = x0r + x2r;
    a[1] = x0i + x2i;
    a[2] = x0r - x2r;
    a[3] = x0i - x2i;
    a[4] = x1r - x3i;
    a[5] = x1i + x3r;
    a[6] = x1r + x3i;
    a[7] = x1i - x3r;
}

static void cftf162(float *a, float *w)
{
    float wn4r, wk1r, wk1i, wk2r, wk2i, wk3r, wk3i, 
        x0r, x0i, x1r, x1i, x2r, x2i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i, 
        y4r, y4i, y5r, y5i, y6r, y6i, y7r, y7i, 
        y8r, y8i, y9r, y9i, y10r, y10i, y11r, y11i, 
        y12r, y12i, y13r, y13i, y14r, y14i, y15r, y15i;
    
    wn4r = w[1];
    wk1r = w[4];
    wk1i = w[5];
    wk3r = w[6];
    wk3i = -w[7];
    wk2r = w[8];
    wk2i = w[9];
    x1r = a[0] - a[17];
    x1i = a[1] + a[16];
    x0r = a[8] - a[25];
    x0i = a[9] + a[24];
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    y0r = x1r + x2r;
    y0i = x1i + x2i;
    y4r = x1r - x2r;
    y4i = x1i - x2i;
    x1r = a[0] + a[17];
    x1i = a[1] - a[16];
    x0r = a[8] + a[25];
    x0i = a[9] - a[24];
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    y8r = x1r - x2i;
    y8i = x1i + x2r;
    y12r = x1r + x2i;
    y12i = x1i - x2r;
    x0r = a[2] - a[19];
    x0i = a[3] + a[18];
    x1r = wk1r * x0r - wk1i * x0i;
    x1i = wk1r * x0i + wk1i * x0r;
    x0r = a[10] - a[27];
    x0i = a[11] + a[26];
    x2r = wk3i * x0r - wk3r * x0i;
    x2i = wk3i * x0i + wk3r * x0r;
    y1r = x1r + x2r;
    y1i = x1i + x2i;
    y5r = x1r - x2r;
    y5i = x1i - x2i;
    x0r = a[2] + a[19];
    x0i = a[3] - a[18];
    x1r = wk3r * x0r - wk3i * x0i;
    x1i = wk3r * x0i + wk3i * x0r;
    x0r = a[10] + a[27];
    x0i = a[11] - a[26];
    x2r = wk1r * x0r + wk1i * x0i;
    x2i = wk1r * x0i - wk1i * x0r;
    y9r = x1r - x2r;
    y9i = x1i - x2i;
    y13r = x1r + x2r;
    y13i = x1i + x2i;
    x0r = a[4] - a[21];
    x0i = a[5] + a[20];
    x1r = wk2r * x0r - wk2i * x0i;
    x1i = wk2r * x0i + wk2i * x0r;
    x0r = a[12] - a[29];
    x0i = a[13] + a[28];
    x2r = wk2i * x0r - wk2r * x0i;
    x2i = wk2i * x0i + wk2r * x0r;
    y2r = x1r + x2r;
    y2i = x1i + x2i;
    y6r = x1r - x2r;
    y6i = x1i - x2i;
    x0r = a[4] + a[21];
    x0i = a[5] - a[20];
    x1r = wk2i * x0r - wk2r * x0i;
    x1i = wk2i * x0i + wk2r * x0r;
    x0r = a[12] + a[29];
    x0i = a[13] - a[28];
    x2r = wk2r * x0r - wk2i * x0i;
    x2i = wk2r * x0i + wk2i * x0r;
    y10r = x1r - x2r;
    y10i = x1i - x2i;
    y14r = x1r + x2r;
    y14i = x1i + x2i;
    x0r = a[6] - a[23];
    x0i = a[7] + a[22];
    x1r = wk3r * x0r - wk3i * x0i;
    x1i = wk3r * x0i + wk3i * x0r;
    x0r = a[14] - a[31];
    x0i = a[15] + a[30];
    x2r = wk1i * x0r - wk1r * x0i;
    x2i = wk1i * x0i + wk1r * x0r;
    y3r = x1r + x2r;
    y3i = x1i + x2i;
    y7r = x1r - x2r;
    y7i = x1i - x2i;
    x0r = a[6] + a[23];
    x0i = a[7] - a[22];
    x1r = wk1i * x0r + wk1r * x0i;
    x1i = wk1i * x0i - wk1r * x0r;
    x0r = a[14] + a[31];
    x0i = a[15] - a[30];
    x2r = wk3i * x0r - wk3r * x0i;
    x2i = wk3i * x0i + wk3r * x0r;
    y11r = x1r + x2r;
    y11i = x1i + x2i;
    y15r = x1r - x2r;
    y15i = x1i - x2i;
    x1r = y0r + y2r;
    x1i = y0i + y2i;
    x2r = y1r + y3r;
    x2i = y1i + y3i;
    a[0] = x1r + x2r;
    a[1] = x1i + x2i;
    a[2] = x1r - x2r;
    a[3] = x1i - x2i;
    x1r = y0r - y2r;
    x1i = y0i - y2i;
    x2r = y1r - y3r;
    x2i = y1i - y3i;
    a[4] = x1r - x2i;
    a[5] = x1i + x2r;
    a[6] = x1r + x2i;
    a[7] = x1i - x2r;
    x1r = y4r - y6i;
    x1i = y4i + y6r;
    x0r = y5r - y7i;
    x0i = y5i + y7r;
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    a[8] = x1r + x2r;
    a[9] = x1i + x2i;
    a[10] = x1r - x2r;
    a[11] = x1i - x2i;
    x1r = y4r + y6i;
    x1i = y4i - y6r;
    x0r = y5r + y7i;
    x0i = y5i - y7r;
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    a[12] = x1r - x2i;
    a[13] = x1i + x2r;
    a[14] = x1r + x2i;
    a[15] = x1i - x2r;
    x1r = y8r + y10r;
    x1i = y8i + y10i;
    x2r = y9r - y11r;
    x2i = y9i - y11i;
    a[16] = x1r + x2r;
    a[17] = x1i + x2i;
    a[18] = x1r - x2r;
    a[19] = x1i - x2i;
    x1r = y8r - y10r;
    x1i = y8i - y10i;
    x2r = y9r + y11r;
    x2i = y9i + y11i;
    a[20] = x1r - x2i;
    a[21] = x1i + x2r;
    a[22] = x1r + x2i;
    a[23] = x1i - x2r;
    x1r = y12r - y14i;
    x1i = y12i + y14r;
    x0r = y13r + y15i;
    x0i = y13i - y15r;
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    a[24] = x1r + x2r;
    a[25] = x1i + x2i;
    a[26] = x1r - x2r;
    a[27] = x1i - x2i;
    x1r = y12r + y14i;
    x1i = y12i - y14r;
    x0r = y13r - y15i;
    x0i = y13i + y15r;
    x2r = wn4r * (x0r - x0i);
    x2i = wn4r * (x0i + x0r);
    a[28] = x1r - x2i;
    a[29] = x1i + x2r;
    a[30] = x1r + x2i;
    a[31] = x1i - x2r;
}

static void cftf081(float *a, float *w)
{
    float wn4r, x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i, 
        y4r, y4i, y5r, y5i, y6r, y6i, y7r, y7i;
    
    wn4r = w[1];
    x0r = a[0] + a[8];
    x0i = a[1] + a[9];
    x1r = a[0] - a[8];
    x1i = a[1] - a[9];
    x2r = a[4] + a[12];
    x2i = a[5] + a[13];
    x3r = a[4] - a[12];
    x3i = a[5] - a[13];
    y0r = x0r + x2r;
    y0i = x0i + x2i;
    y2r = x0r - x2r;
    y2i = x0i - x2i;
    y1r = x1r - x3i;
    y1i = x1i + x3r;
    y3r = x1r + x3i;
    y3i = x1i - x3r;
    x0r = a[2] + a[10];
    x0i = a[3] + a[11];
    x1r = a[2] - a[10];
    x1i = a[3] - a[11];
    x2r = a[6] + a[14];
    x2i = a[7] + a[15];
    x3r = a[6] - a[14];
    x3i = a[7] - a[15];
    y4r = x0r + x2r;
    y4i = x0i + x2i;
    y6r = x0r - x2r;
    y6i = x0i - x2i;
    x0r = x1r - x3i;
    x0i = x1i + x3r;
    x2r = x1r + x3i;
    x2i = x1i - x3r;
    y5r = wn4r * (x0r - x0i);
    y5i = wn4r * (x0r + x0i);
    y7r = wn4r * (x2r - x2i);
    y7i = wn4r * (x2r + x2i);
    a[8] = y1r + y5r;
    a[9] = y1i + y5i;
    a[10] = y1r - y5r;
    a[11] = y1i - y5i;
    a[12] = y3r - y7i;
    a[13] = y3i + y7r;
    a[14] = y3r + y7i;
    a[15] = y3i - y7r;
    a[0] = y0r + y4r;
    a[1] = y0i + y4i;
    a[2] = y0r - y4r;
    a[3] = y0i - y4i;
    a[4] = y2r - y6i;
    a[5] = y2i + y6r;
    a[6] = y2r + y6i;
    a[7] = y2i - y6r;
}

static void cftf082(float *a, float *w)
{
    float wn4r, wk1r, wk1i, x0r, x0i, x1r, x1i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i, 
        y4r, y4i, y5r, y5i, y6r, y6i, y7r, y7i;
    
    wn4r = w[1];
    wk1r = w[2];
    wk1i = w[3];
    y0r = a[0] - a[9];
    y0i = a[1] + a[8];
    y1r = a[0] + a[9];
    y1i = a[1] - a[8];
    x0r = a[4] - a[13];
    x0i = a[5] + a[12];
    y2r = wn4r * (x0r - x0i);
    y2i = wn4r * (x0i + x0r);
    x0r = a[4] + a[13];
    x0i = a[5] - a[12];
    y3r = wn4r * (x0r - x0i);
    y3i = wn4r * (x0i + x0r);
    x0r = a[2] - a[11];
    x0i = a[3] + a[10];
    y4r = wk1r * x0r - wk1i * x0i;
    y4i = wk1r * x0i + wk1i * x0r;
    x0r = a[2] + a[11];
    x0i = a[3] - a[10];
    y5r = wk1i * x0r - wk1r * x0i;
    y5i = wk1i * x0i + wk1r * x0r;
    x0r = a[6] - a[15];
    x0i = a[7] + a[14];
    y6r = wk1i * x0r - wk1r * x0i;
    y6i = wk1i * x0i + wk1r * x0r;
    x0r = a[6] + a[15];
    x0i = a[7] - a[14];
    y7r = wk1r * x0r - wk1i * x0i;
    y7i = wk1r * x0i + wk1i * x0r;
    x0r = y0r + y2r;
    x0i = y0i + y2i;
    x1r = y4r + y6r;
    x1i = y4i + y6i;
    a[0] = x0r + x1r;
    a[1] = x0i + x1i;
    a[2] = x0r - x1r;
    a[3] = x0i - x1i;
    x0r = y0r - y2r;
    x0i = y0i - y2i;
    x1r = y4r - y6r;
    x1i = y4i - y6i;
    a[4] = x0r - x1i;
    a[5] = x0i + x1r;
    a[6] = x0r + x1i;
    a[7] = x0i - x1r;
    x0r = y1r - y3i;
    x0i = y1i + y3r;
    x1r = y5r - y7r;
    x1i = y5i - y7i;
    a[8] = x0r + x1r;
    a[9] = x0i + x1i;
    a[10] = x0r - x1r;
    a[11] = x0i - x1i;
    x0r = y1r + y3i;
    x0i = y1i - y3r;
    x1r = y5r + y7r;
    x1i = y5i + y7i;
    a[12] = x0r - x1i;
    a[13] = x0i + x1r;
    a[14] = x0r + x1i;
    a[15] = x0i - x1r;
}

static void cftleaf(int n, int isplt, float *a, int nw, float *w)
{
    void cftmdl1(int n, float *a, float *w);
    void cftmdl2(int n, float *a, float *w);
    void cftf161(float *a, float *w);
    void cftf162(float *a, float *w);
    void cftf081(float *a, float *w);
    void cftf082(float *a, float *w);
    
    if (n == 512) {
        cftmdl1(128, a, &w[nw - 64]);
        cftf161(a, &w[nw - 8]);
        cftf162(&a[32], &w[nw - 32]);
        cftf161(&a[64], &w[nw - 8]);
        cftf161(&a[96], &w[nw - 8]);
        cftmdl2(128, &a[128], &w[nw - 128]);
        cftf161(&a[128], &w[nw - 8]);
        cftf162(&a[160], &w[nw - 32]);
        cftf161(&a[192], &w[nw - 8]);
        cftf162(&a[224], &w[nw - 32]);
        cftmdl1(128, &a[256], &w[nw - 64]);
        cftf161(&a[256], &w[nw - 8]);
        cftf162(&a[288], &w[nw - 32]);
        cftf161(&a[320], &w[nw - 8]);
        cftf161(&a[352], &w[nw - 8]);
        if (isplt != 0) {
            cftmdl1(128, &a[384], &w[nw - 64]);
            cftf161(&a[480], &w[nw - 8]);
        } else {
            cftmdl2(128, &a[384], &w[nw - 128]);
            cftf162(&a[480], &w[nw - 32]);
        }
        cftf161(&a[384], &w[nw - 8]);
        cftf162(&a[416], &w[nw - 32]);
        cftf161(&a[448], &w[nw - 8]);
    } else {
        cftmdl1(64, a, &w[nw - 32]);
        cftf081(a, &w[nw - 8]);
        cftf082(&a[16], &w[nw - 8]);
        cftf081(&a[32], &w[nw - 8]);
        cftf081(&a[48], &w[nw - 8]);
        cftmdl2(64, &a[64], &w[nw - 64]);
        cftf081(&a[64], &w[nw - 8]);
        cftf082(&a[80], &w[nw - 8]);
        cftf081(&a[96], &w[nw - 8]);
        cftf082(&a[112], &w[nw - 8]);
        cftmdl1(64, &a[128], &w[nw - 32]);
        cftf081(&a[128], &w[nw - 8]);
        cftf082(&a[144], &w[nw - 8]);
        cftf081(&a[160], &w[nw - 8]);
        cftf081(&a[176], &w[nw - 8]);
        if (isplt != 0) {
            cftmdl1(64, &a[192], &w[nw - 32]);
            cftf081(&a[240], &w[nw - 8]);
        } else {
            cftmdl2(64, &a[192], &w[nw - 64]);
            cftf082(&a[240], &w[nw - 8]);
        }
        cftf081(&a[192], &w[nw - 8]);
        cftf082(&a[208], &w[nw - 8]);
        cftf081(&a[224], &w[nw - 8]);
    }
}

static void cftrec4(int n, float *a, int nw, float *w)
{
    int cfttree(int n, int j, int k, float *a, int nw, float *w);
    void cftleaf(int n, int isplt, float *a, int nw, float *w);
    void cftmdl1(int n, float *a, float *w);
    int isplt, j, k, m;
    
    m = n;
    while (m > 512) {
        m >>= 2;
        cftmdl1(m, &a[n - m], &w[nw - (m >> 1)]);
    }
    cftleaf(m, 1, &a[n - m], nw, w);
    k = 0;
    for (j = n - m; j > 0; j -= m) {
        k++;
        isplt = cfttree(m, j, k, a, nw, w);
        cftleaf(m, isplt, &a[j - m], nw, w);
    }
}

static void cftfx41(int n, float *a, int nw, float *w)
{
    void cftf161(float *a, float *w);
    void cftf162(float *a, float *w);
    void cftf081(float *a, float *w);
    void cftf082(float *a, float *w);
    
    if (n == 128) {
        cftf161(a, &w[nw - 8]);
        cftf162(&a[32], &w[nw - 32]);
        cftf161(&a[64], &w[nw - 8]);
        cftf161(&a[96], &w[nw - 8]);
    } else {
        cftf081(a, &w[nw - 8]);
        cftf082(&a[16], &w[nw - 8]);
        cftf081(&a[32], &w[nw - 8]);
        cftf081(&a[48], &w[nw - 8]);
    }
}

static void cftf040(float *a)
{
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i;
    
    x0r = a[0] + a[4];
    x0i = a[1] + a[5];
    x1r = a[0] - a[4];
    x1i = a[1] - a[5];
    x2r = a[2] + a[6];
    x2i = a[3] + a[7];
    x3r = a[2] - a[6];
    x3i = a[3] - a[7];
    a[0] = x0r + x2r;
    a[1] = x0i + x2i;
    a[2] = x1r - x3i;
    a[3] = x1i + x3r;
    a[4] = x0r - x2r;
    a[5] = x0i - x2i;
    a[6] = x1r + x3i;
    a[7] = x1i - x3r;
}

static void cftx020(float *a)
{
    float x0r, x0i;
    
    x0r = a[0] - a[2];
    x0i = a[1] - a[3];
    a[0] += a[2];
    a[1] += a[3];
    a[2] = x0r;
    a[3] = x0i;
}

#ifdef USE_CDFT_THREADS
struct cdft_arg_st {
    int n0;
    int n;
    float *a;
    int nw;
    float *w;
};
typedef struct cdft_arg_st cdft_arg_t;


static void cftrec4_th(int n, float *a, int nw, float *w)
{
    void *cftrec1_th(void *p);
    void *cftrec2_th(void *p);
    int i, idiv4, m, nthread;
    cdft_thread_t th[4];
    cdft_arg_t ag[4];
    
    nthread = 2;
    idiv4 = 0;
    m = n >> 1;
    if (n > CDFT_4THREADS_BEGIN_N) {
        nthread = 4;
        idiv4 = 1;
        m >>= 1;
    }
    for (i = 0; i < nthread; i++) {
        ag[i].n0 = n;
        ag[i].n = m;
        ag[i].a = &a[i * m];
        ag[i].nw = nw;
        ag[i].w = w;
        if (i != idiv4) {
            cdft_thread_create(&th[i], cftrec1_th, &ag[i]);
        } else {
            cdft_thread_create(&th[i], cftrec2_th, &ag[i]);
        }
    }
    for (i = 0; i < nthread; i++) {
        cdft_thread_wait(th[i]);
    }
}


static void *cftrec1_th(void *p)
{
    int cfttree(int n, int j, int k, float *a, int nw, float *w);
    void cftleaf(int n, int isplt, float *a, int nw, float *w);
    void cftmdl1(int n, float *a, float *w);
    int isplt, j, k, m, n, n0, nw;
    float *a, *w;
    
    n0 = ((cdft_arg_t *) p)->n0;
    n = ((cdft_arg_t *) p)->n;
    a = ((cdft_arg_t *) p)->a;
    nw = ((cdft_arg_t *) p)->nw;
    w = ((cdft_arg_t *) p)->w;
    m = n0;
    while (m > 512) {
        m >>= 2;
        cftmdl1(m, &a[n - m], &w[nw - (m >> 1)]);
    }
    cftleaf(m, 1, &a[n - m], nw, w);
    k = 0;
    for (j = n - m; j > 0; j -= m) {
        k++;
        isplt = cfttree(m, j, k, a, nw, w);
        cftleaf(m, isplt, &a[j - m], nw, w);
    }
    return (void *) 0;
}


static void *cftrec2_th(void *p)
{
    int cfttree(int n, int j, int k, float *a, int nw, float *w);
    void cftleaf(int n, int isplt, float *a, int nw, float *w);
    void cftmdl2(int n, float *a, float *w);
    int isplt, j, k, m, n, n0, nw;
    float *a, *w;
    
    n0 = ((cdft_arg_t *) p)->n0;
    n = ((cdft_arg_t *) p)->n;
    a = ((cdft_arg_t *) p)->a;
    nw = ((cdft_arg_t *) p)->nw;
    w = ((cdft_arg_t *) p)->w;
    k = 1;
    m = n0;
    while (m > 512) {
        m >>= 2;
        k <<= 2;
        cftmdl2(m, &a[n - m], &w[nw - m]);
    }
    cftleaf(m, 0, &a[n - m], nw, w);
    k >>= 1;
    for (j = n - m; j > 0; j -= m) {
        k++;
        isplt = cfttree(m, j, k, a, nw, w);
        cftleaf(m, isplt, &a[j - m], nw, w);
    }
    return (void *) 0;
}
#endif /* USE_CDFT_THREADS */

static void cftfsub(int n, float *a, int *ip, int nw, float *w)
{
    void bitrv2(int n, int *ip, float *a);
    void bitrv216(float *a);
    void bitrv208(float *a);
    void cftf1st(int n, float *a, float *w);
    void cftrec4(int n, float *a, int nw, float *w);
    void cftleaf(int n, int isplt, float *a, int nw, float *w);
    void cftfx41(int n, float *a, int nw, float *w);
    void cftf161(float *a, float *w);
    void cftf081(float *a, float *w);
    void cftf040(float *a);
    void cftx020(float *a);
#ifdef USE_CDFT_THREADS
    void cftrec4_th(int n, float *a, int nw, float *w);
#endif /* USE_CDFT_THREADS */
    
    if (n > 8) {
        if (n > 32) {
            cftf1st(n, a, &w[nw - (n >> 2)]);
#ifdef USE_CDFT_THREADS
            if (n > CDFT_THREADS_BEGIN_N) {
                cftrec4_th(n, a, nw, w);
            } else 
#endif /* USE_CDFT_THREADS */
            if (n > 512) {
                cftrec4(n, a, nw, w);
            } else if (n > 128) {
                cftleaf(n, 1, a, nw, w);
            } else {
                cftfx41(n, a, nw, w);
            }
            bitrv2(n, ip, a);
        } else if (n == 32) {
            cftf161(a, &w[nw - 8]);
            bitrv216(a);
        } else {
            cftf081(a, w);
            bitrv208(a);
        }
    } else if (n == 8) {
        cftf040(a);
    } else if (n == 4) {
        cftx020(a);
    }
}

static void bitrv2conj(int n, int *ip, float *a)
{
    int j, j1, k, k1, l, m, nh, nm;
    float xr, xi, yr, yi;
    
    m = 1;
    for (l = n >> 2; l > 8; l >>= 2) {
        m <<= 1;
    }
    nh = n >> 1;
    nm = 4 * m;
    if (l == 8) {
        for (k = 0; k < m; k++) {
            for (j = 0; j < k; j++) {
                j1 = 4 * j + 2 * ip[m + k];
                k1 = 4 * k + 2 * ip[m + j];
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 -= nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nh;
                k1 += 2;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 += nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += 2;
                k1 += nh;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 -= nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nh;
                k1 -= 2;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 += nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= 2 * nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
            }
            k1 = 4 * k + 2 * ip[m + k];
            j1 = k1 + 2;
            k1 += nh;
            a[j1 - 1] = -a[j1 - 1];
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            a[k1 + 3] = -a[k1 + 3];
            j1 += nm;
            k1 += 2 * nm;
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nm;
            k1 -= nm;
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 -= 2;
            k1 -= nh;
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 += nh + 2;
            k1 += nh + 2;
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            j1 -= nh - nm;
            k1 += 2 * nm - 2;
            a[j1 - 1] = -a[j1 - 1];
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            a[k1 + 3] = -a[k1 + 3];
        }
    } else {
        for (k = 0; k < m; k++) {
            for (j = 0; j < k; j++) {
                j1 = 4 * j + ip[m + k];
                k1 = 4 * k + ip[m + j];
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nh;
                k1 += 2;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += 2;
                k1 += nh;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 += nm;
                k1 += nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nh;
                k1 -= 2;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
                j1 -= nm;
                k1 -= nm;
                xr = a[j1];
                xi = -a[j1 + 1];
                yr = a[k1];
                yi = -a[k1 + 1];
                a[j1] = yr;
                a[j1 + 1] = yi;
                a[k1] = xr;
                a[k1 + 1] = xi;
            }
            k1 = 4 * k + ip[m + k];
            j1 = k1 + 2;
            k1 += nh;
            a[j1 - 1] = -a[j1 - 1];
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            a[k1 + 3] = -a[k1 + 3];
            j1 += nm;
            k1 += nm;
            a[j1 - 1] = -a[j1 - 1];
            xr = a[j1];
            xi = -a[j1 + 1];
            yr = a[k1];
            yi = -a[k1 + 1];
            a[j1] = yr;
            a[j1 + 1] = yi;
            a[k1] = xr;
            a[k1 + 1] = xi;
            a[k1 + 3] = -a[k1 + 3];
        }
    }
}

static void bitrv216neg(float *a)
{
    float x1r, x1i, x2r, x2i, x3r, x3i, x4r, x4i, 
        x5r, x5i, x6r, x6i, x7r, x7i, x8r, x8i, 
        x9r, x9i, x10r, x10i, x11r, x11i, x12r, x12i, 
        x13r, x13i, x14r, x14i, x15r, x15i;
    
    x1r = a[2];
    x1i = a[3];
    x2r = a[4];
    x2i = a[5];
    x3r = a[6];
    x3i = a[7];
    x4r = a[8];
    x4i = a[9];
    x5r = a[10];
    x5i = a[11];
    x6r = a[12];
    x6i = a[13];
    x7r = a[14];
    x7i = a[15];
    x8r = a[16];
    x8i = a[17];
    x9r = a[18];
    x9i = a[19];
    x10r = a[20];
    x10i = a[21];
    x11r = a[22];
    x11i = a[23];
    x12r = a[24];
    x12i = a[25];
    x13r = a[26];
    x13i = a[27];
    x14r = a[28];
    x14i = a[29];
    x15r = a[30];
    x15i = a[31];
    a[2] = x15r;
    a[3] = x15i;
    a[4] = x7r;
    a[5] = x7i;
    a[6] = x11r;
    a[7] = x11i;
    a[8] = x3r;
    a[9] = x3i;
    a[10] = x13r;
    a[11] = x13i;
    a[12] = x5r;
    a[13] = x5i;
    a[14] = x9r;
    a[15] = x9i;
    a[16] = x1r;
    a[17] = x1i;
    a[18] = x14r;
    a[19] = x14i;
    a[20] = x6r;
    a[21] = x6i;
    a[22] = x10r;
    a[23] = x10i;
    a[24] = x2r;
    a[25] = x2i;
    a[26] = x12r;
    a[27] = x12i;
    a[28] = x4r;
    a[29] = x4i;
    a[30] = x8r;
    a[31] = x8i;
}

static void bitrv208neg(float *a)
{
    float x1r, x1i, x2r, x2i, x3r, x3i, x4r, x4i, 
        x5r, x5i, x6r, x6i, x7r, x7i;
    
    x1r = a[2];
    x1i = a[3];
    x2r = a[4];
    x2i = a[5];
    x3r = a[6];
    x3i = a[7];
    x4r = a[8];
    x4i = a[9];
    x5r = a[10];
    x5i = a[11];
    x6r = a[12];
    x6i = a[13];
    x7r = a[14];
    x7i = a[15];
    a[2] = x7r;
    a[3] = x7i;
    a[4] = x3r;
    a[5] = x3i;
    a[6] = x5r;
    a[7] = x5i;
    a[8] = x1r;
    a[9] = x1i;
    a[10] = x6r;
    a[11] = x6i;
    a[12] = x2r;
    a[13] = x2i;
    a[14] = x4r;
    a[15] = x4i;
}

static void cftb1st(int n, float *a, float *w)
{
    int j, j0, j1, j2, j3, k, m, mh;
    float wn4r, csc1, csc3, wk1r, wk1i, wk3r, wk3i, 
        wd1r, wd1i, wd3r, wd3i;
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i, 
        y0r, y0i, y1r, y1i, y2r, y2i, y3r, y3i;
    
    mh = n >> 3;
    m = 2 * mh;
    j1 = m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[0] + a[j2];
    x0i = -a[1] - a[j2 + 1];
    x1r = a[0] - a[j2];
    x1i = -a[1] + a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[0] = x0r + x2r;
    a[1] = x0i - x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i + x2i;
    a[j2] = x1r + x3i;
    a[j2 + 1] = x1i + x3r;
    a[j3] = x1r - x3i;
    a[j3 + 1] = x1i - x3r;
    wn4r = w[1];
    csc1 = w[2];
    csc3 = w[3];
    wd1r = 1;
    wd1i = 0;
    wd3r = 1;
    wd3i = 0;
    k = 0;
    for (j = 2; j < mh - 2; j += 4) {
        k += 4;
        wk1r = csc1 * (wd1r + w[k]);
        wk1i = csc1 * (wd1i + w[k + 1]);
        wk3r = csc3 * (wd3r + w[k + 2]);
        wk3i = csc3 * (wd3i + w[k + 3]);
        wd1r = w[k];
        wd1i = w[k + 1];
        wd3r = w[k + 2];
        wd3i = w[k + 3];
        j1 = j + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j] + a[j2];
        x0i = -a[j + 1] - a[j2 + 1];
        x1r = a[j] - a[j2];
        x1i = -a[j + 1] + a[j2 + 1];
        y0r = a[j + 2] + a[j2 + 2];
        y0i = -a[j + 3] - a[j2 + 3];
        y1r = a[j + 2] - a[j2 + 2];
        y1i = -a[j + 3] + a[j2 + 3];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        y2r = a[j1 + 2] + a[j3 + 2];
        y2i = a[j1 + 3] + a[j3 + 3];
        y3r = a[j1 + 2] - a[j3 + 2];
        y3i = a[j1 + 3] - a[j3 + 3];
        a[j] = x0r + x2r;
        a[j + 1] = x0i - x2i;
        a[j + 2] = y0r + y2r;
        a[j + 3] = y0i - y2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i + x2i;
        a[j1 + 2] = y0r - y2r;
        a[j1 + 3] = y0i + y2i;
        x0r = x1r + x3i;
        x0i = x1i + x3r;
        a[j2] = wk1r * x0r - wk1i * x0i;
        a[j2 + 1] = wk1r * x0i + wk1i * x0r;
        x0r = y1r + y3i;
        x0i = y1i + y3r;
        a[j2 + 2] = wd1r * x0r - wd1i * x0i;
        a[j2 + 3] = wd1r * x0i + wd1i * x0r;
        x0r = x1r - x3i;
        x0i = x1i - x3r;
        a[j3] = wk3r * x0r + wk3i * x0i;
        a[j3 + 1] = wk3r * x0i - wk3i * x0r;
        x0r = y1r - y3i;
        x0i = y1i - y3r;
        a[j3 + 2] = wd3r * x0r + wd3i * x0i;
        a[j3 + 3] = wd3r * x0i - wd3i * x0r;
        j0 = m - j;
        j1 = j0 + m;
        j2 = j1 + m;
        j3 = j2 + m;
        x0r = a[j0] + a[j2];
        x0i = -a[j0 + 1] - a[j2 + 1];
        x1r = a[j0] - a[j2];
        x1i = -a[j0 + 1] + a[j2 + 1];
        y0r = a[j0 - 2] + a[j2 - 2];
        y0i = -a[j0 - 1] - a[j2 - 1];
        y1r = a[j0 - 2] - a[j2 - 2];
        y1i = -a[j0 - 1] + a[j2 - 1];
        x2r = a[j1] + a[j3];
        x2i = a[j1 + 1] + a[j3 + 1];
        x3r = a[j1] - a[j3];
        x3i = a[j1 + 1] - a[j3 + 1];
        y2r = a[j1 - 2] + a[j3 - 2];
        y2i = a[j1 - 1] + a[j3 - 1];
        y3r = a[j1 - 2] - a[j3 - 2];
        y3i = a[j1 - 1] - a[j3 - 1];
        a[j0] = x0r + x2r;
        a[j0 + 1] = x0i - x2i;
        a[j0 - 2] = y0r + y2r;
        a[j0 - 1] = y0i - y2i;
        a[j1] = x0r - x2r;
        a[j1 + 1] = x0i + x2i;
        a[j1 - 2] = y0r - y2r;
        a[j1 - 1] = y0i + y2i;
        x0r = x1r + x3i;
        x0i = x1i + x3r;
        a[j2] = wk1i * x0r - wk1r * x0i;
        a[j2 + 1] = wk1i * x0i + wk1r * x0r;
        x0r = y1r + y3i;
        x0i = y1i + y3r;
        a[j2 - 2] = wd1i * x0r - wd1r * x0i;
        a[j2 - 1] = wd1i * x0i + wd1r * x0r;
        x0r = x1r - x3i;
        x0i = x1i - x3r;
        a[j3] = wk3i * x0r + wk3r * x0i;
        a[j3 + 1] = wk3i * x0i - wk3r * x0r;
        x0r = y1r - y3i;
        x0i = y1i - y3r;
        a[j3 - 2] = wd3i * x0r + wd3r * x0i;
        a[j3 - 1] = wd3i * x0i - wd3r * x0r;
    }
    wk1r = csc1 * (wd1r + wn4r);
    wk1i = csc1 * (wd1i + wn4r);
    wk3r = csc3 * (wd3r - wn4r);
    wk3i = csc3 * (wd3i - wn4r);
    j0 = mh;
    j1 = j0 + m;
    j2 = j1 + m;
    j3 = j2 + m;
    x0r = a[j0 - 2] + a[j2 - 2];
    x0i = -a[j0 - 1] - a[j2 - 1];
    x1r = a[j0 - 2] - a[j2 - 2];
    x1i = -a[j0 - 1] + a[j2 - 1];
    x2r = a[j1 - 2] + a[j3 - 2];
    x2i = a[j1 - 1] + a[j3 - 1];
    x3r = a[j1 - 2] - a[j3 - 2];
    x3i = a[j1 - 1] - a[j3 - 1];
    a[j0 - 2] = x0r + x2r;
    a[j0 - 1] = x0i - x2i;
    a[j1 - 2] = x0r - x2r;
    a[j1 - 1] = x0i + x2i;
    x0r = x1r + x3i;
    x0i = x1i + x3r;
    a[j2 - 2] = wk1r * x0r - wk1i * x0i;
    a[j2 - 1] = wk1r * x0i + wk1i * x0r;
    x0r = x1r - x3i;
    x0i = x1i - x3r;
    a[j3 - 2] = wk3r * x0r + wk3i * x0i;
    a[j3 - 1] = wk3r * x0i - wk3i * x0r;
    x0r = a[j0] + a[j2];
    x0i = -a[j0 + 1] - a[j2 + 1];
    x1r = a[j0] - a[j2];
    x1i = -a[j0 + 1] + a[j2 + 1];
    x2r = a[j1] + a[j3];
    x2i = a[j1 + 1] + a[j3 + 1];
    x3r = a[j1] - a[j3];
    x3i = a[j1 + 1] - a[j3 + 1];
    a[j0] = x0r + x2r;
    a[j0 + 1] = x0i - x2i;
    a[j1] = x0r - x2r;
    a[j1 + 1] = x0i + x2i;
    x0r = x1r + x3i;
    x0i = x1i + x3r;
    a[j2] = wn4r * (x0r - x0i);
    a[j2 + 1] = wn4r * (x0i + x0r);
    x0r = x1r - x3i;
    x0i = x1i - x3r;
    a[j3] = -wn4r * (x0r + x0i);
    a[j3 + 1] = -wn4r * (x0i - x0r);
    x0r = a[j0 + 2] + a[j2 + 2];
    x0i = -a[j0 + 3] - a[j2 + 3];
    x1r = a[j0 + 2] - a[j2 + 2];
    x1i = -a[j0 + 3] + a[j2 + 3];
    x2r = a[j1 + 2] + a[j3 + 2];
    x2i = a[j1 + 3] + a[j3 + 3];
    x3r = a[j1 + 2] - a[j3 + 2];
    x3i = a[j1 + 3] - a[j3 + 3];
    a[j0 + 2] = x0r + x2r;
    a[j0 + 3] = x0i - x2i;
    a[j1 + 2] = x0r - x2r;
    a[j1 + 3] = x0i + x2i;
    x0r = x1r + x3i;
    x0i = x1i + x3r;
    a[j2 + 2] = wk1i * x0r - wk1r * x0i;
    a[j2 + 3] = wk1i * x0i + wk1r * x0r;
    x0r = x1r - x3i;
    x0i = x1i - x3r;
    a[j3 + 2] = wk3i * x0r + wk3r * x0i;
    a[j3 + 3] = wk3i * x0i - wk3r * x0r;
}

static void cftb040(float *a)
{
    float x0r, x0i, x1r, x1i, x2r, x2i, x3r, x3i;
    
    x0r = a[0] + a[4];
    x0i = a[1] + a[5];
    x1r = a[0] - a[4];
    x1i = a[1] - a[5];
    x2r = a[2] + a[6];
    x2i = a[3] + a[7];
    x3r = a[2] - a[6];
    x3i = a[3] - a[7];
    a[0] = x0r + x2r;
    a[1] = x0i + x2i;
    a[2] = x1r + x3i;
    a[3] = x1i - x3r;
    a[4] = x0r - x2r;
    a[5] = x0i - x2i;
    a[6] = x1r - x3i;
    a[7] = x1i + x3r;
}

static void cftbsub(int n, float *a, int *ip, int nw, float *w)
{
    void bitrv2conj(int n, int *ip, float *a);
    void bitrv216neg(float *a);
    void bitrv208neg(float *a);
    void cftb1st(int n, float *a, float *w);
    void cftrec4(int n, float *a, int nw, float *w);
    void cftleaf(int n, int isplt, float *a, int nw, float *w);
    void cftfx41(int n, float *a, int nw, float *w);
    void cftf161(float *a, float *w);
    void cftf081(float *a, float *w);
    void cftb040(float *a);
    void cftx020(float *a);
#ifdef USE_CDFT_THREADS
    void cftrec4_th(int n, float *a, int nw, float *w);
#endif /* USE_CDFT_THREADS */
    
    if (n > 8) {
        if (n > 32) {
            cftb1st(n, a, &w[nw - (n >> 2)]);
#ifdef USE_CDFT_THREADS
            if (n > CDFT_THREADS_BEGIN_N) {
                cftrec4_th(n, a, nw, w);
            } else 
#endif /* USE_CDFT_THREADS */
            if (n > 512) {
                cftrec4(n, a, nw, w);
            } else if (n > 128) {
                cftleaf(n, 1, a, nw, w);
            } else {
                cftfx41(n, a, nw, w);
            }
            bitrv2conj(n, ip, a);
        } else if (n == 32) {
            cftf161(a, &w[nw - 8]);
            bitrv216neg(a);
        } else {
            cftf081(a, w);
            bitrv208neg(a);
        }
    } else if (n == 8) {
        cftb040(a);
    } else if (n == 4) {
        cftx020(a);
    }
}

static void rftfsub(int n, float *a, int nc, float *c)
{
    int j, k, kk, ks, m;
    float wkr, wki, xr, xi, yr, yi;
    
    m = n >> 1;
    ks = 2 * nc / m;
    kk = 0;
    for (j = 2; j < m; j += 2) {
        k = n - j;
        kk += ks;
        wkr = 0.5 - c[nc - kk];
        wki = c[kk];
        xr = a[j] - a[k];
        xi = a[j + 1] + a[k + 1];
        yr = wkr * xr - wki * xi;
        yi = wkr * xi + wki * xr;
        a[j] -= yr;
        a[j + 1] -= yi;
        a[k] += yr;
        a[k + 1] -= yi;
    }
}

static void rftbsub(int n, float *a, int nc, float *c)
{
    int j, k, kk, ks, m;
    float wkr, wki, xr, xi, yr, yi;
    
    m = n >> 1;
    ks = 2 * nc / m;
    kk = 0;
    for (j = 2; j < m; j += 2) {
        k = n - j;
        kk += ks;
        wkr = 0.5 - c[nc - kk];
        wki = c[kk];
        xr = a[j] - a[k];
        xi = a[j + 1] + a[k + 1];
        yr = wkr * xr + wki * xi;
        yi = wkr * xi - wki * xr;
        a[j] -= yr;
        a[j + 1] -= yi;
        a[k] += yr;
        a[k + 1] -= yi;
    }
}

static void rdft(int n, int isgn, float *a, int *ip, float *w)
{
    void makewt(int nw, int *ip, float *w);
    void makect(int nc, int *ip, float *c);
    void cftfsub(int n, float *a, int *ip, int nw, float *w);
    void cftbsub(int n, float *a, int *ip, int nw, float *w);
    void rftfsub(int n, float *a, int nc, float *c);
    void rftbsub(int n, float *a, int nc, float *c);
    int nw, nc;
    float xi;
    
    nw = ip[0];
    if (n > (nw << 2)) {
        nw = n >> 2;
        makewt(nw, ip, w);
    }
    nc = ip[1];
    if (n > (nc << 2)) {
        nc = n >> 2;
        makect(nc, ip, w + nw);
    }
    if (isgn >= 0) {
        if (n > 4) {
            cftfsub(n, a, ip, nw, w);
            rftfsub(n, a, nc, w + nw);
        } else if (n == 4) {
            cftfsub(n, a, ip, nw, w);
        }
        xi = a[0] - a[1];
        a[0] += a[1];
        a[1] = xi;
    } else {
        a[1] = 0.5 * (a[0] - a[1]);
        a[0] -= a[1];
        if (n > 4) {
            rftbsub(n, a, nc, w + nw);
            cftbsub(n, a, ip, nw, w);
        } else if (n == 4) {
            cftbsub(n, a, ip, nw, w);
        }
    }
}

// input array (any shape >= 1D)
// output array (shape = input.shape.replace(axis, n).insert(0,2))
// d0 = input.shape.step(axis)
// d1 = input.shape.size(axis)
// d2 = input.shape.slot(axis)
static inline void rfft_libfft_f32(
    const float* restrict input, 
    float* restrict output, 
    int d0, int d1, int d2,
    int32_t* restrict temp_ip, float* restrict temp_w, float* restrict temp_a)
{
    void rdft(int n, int isgn, float* a, int* ip, float* w);

    int d3 = d0 * d1;
    int d_out = (d1 >> 1) + 1;

    for (int k = 0; k < d2; k++)
    {
        int dk = k * d3;
        int dm = k * 2 * d_out * d0;
        for (int i = 0; i < d0; i++)
        {                	           
            for (int j = 0; j < d1; j++)
            {
                temp_a[j] = input[dk + j * d0 + i];
            }
            rdft(d1, 1, temp_a, (int *)temp_ip, temp_w);

            for (int m = 2; m < d1; m+=2)
            {
                int index = (m * d0) + 2 * i + dm;
                output[index] = temp_a[m];
                output[index + 1] = -temp_a[m + 1];
            }
            int beta = dm + 2 * i;
            output[beta] = temp_a[0];
            output[beta + 1] = 0;
            output[beta + d3] = temp_a[1];
            output[beta + d3 + 1] = 0;
        }
    }
}

static inline float __norm_sqrt_sum_f32(const float* restrict input, int count)
{
	float sum = 0;
	for (int j = 0; j < count; j++) {
		float item = *input++;
		sum += item * item;
	}
	return sqrtf(sum);
}

static inline void norm_f32(const float* restrict input, int d1, int d2, float* restrict output)
{
	for (int k = 0; k < d2; k++) {
		*output++ = __norm_sqrt_sum_f32(input, d1);
		input += d1;
	}
}

static inline float __mel_f32(const float* restrict input, const short* restrict filter_points, int filter)
{
	short n0 = filter_points[filter];
	short n1 = filter_points[filter+1];
	short n2 = filter_points[filter+2];
	short c0 = n1 - n0;
	short c1 = n2 - n1;
	float sum = 0;
	
	for (int i = 0; i <= c0; i++) {
		float rate = i / (float)c0;
		float value = input[i + n0];
		sum += value * rate;
	}

	for (int i = 1; i <= c1; i++) {
		float rate = i / (float)c1;
		float value = input[i + n1];
		sum += value * (1.0 - rate);
	}

	return sum;
}

// input array (any shape >= 1D)
// output array (same shape as input array except with 0 replaced with num_filter)
// size = input.shape.size(0)
// slot = input.shape.slot(0)
static inline void mel_f32(const float* restrict input, const short* restrict filter_points, int size, int slot, int num_filter, float* restrict output)
{	
	for (int k = 0; k < slot; k++) {
		const float *ip = input + k * size;
		for (int i = 0; i < num_filter; i++) {
			*output++ = __mel_f32(ip, filter_points, i);
		}
	}
}

static inline void clip_f32(const float* restrict input, int count, float min, float max, float* restrict output)
{	
	for (int i = 0; i < count; i++) {
		float value = input[i];
		if (value > max)
			value = max;
		if (value < min)
			value = min;

		output[i] = value;
	}
}

static inline void ln_f32(const float* restrict x, int count, float* restrict result)
{
	for (int i = 0; i < count; i++) {
		*result++ = logf(*x++);
	}
}

/**
 * Enqueue handle->input_size values from given *data pointer to internal window buffer.
 *
 * @param handle Pointer to an initialized handle.
 * @param data Data to enqueue.
 * @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_ERROR (-2) if internal buffer is out of memory.
 */
static inline int fixwin_enqueue(void* restrict handle, const void* restrict data)
{
	fixwin_t* fep = (fixwin_t*)handle;

	if (cbuffer_enqueue(&fep->data_buffer, data, fep->input_size) != 0)
		return IPWIN_RET_ERROR;

	return IPWIN_RET_SUCCESS;
}

static inline int mtb_model_raw(const void* handle,
	const void* restrict src, int src_count,
	void* restrict dst, int dst_byte_count)
{
	mtb_ml_model_t* model = *(mtb_ml_model_t**)handle;
	mtb_ml_model_run(model, (MTB_ML_DATA_T*)src);
	
	int ret_status = model->lib_error;
	if (ret_status != 0) {printf("ERROR: TensorFlow Lite model inference failed with error code: %d.\r\n", ret_status);}
	CY_ASSERT(ret_status == 0);

	memcpy(dst, model->output, dst_byte_count);

	return IPWIN_RET_SUCCESS;
}

static inline void mtb_model_free(const void* handle)
{
	mtb_ml_model_t* model = *(mtb_ml_model_t**)handle;
	mtb_ml_model_deinit(model);

#ifndef IMAI_NO_NPU
	mtb_ml_deinit();
#endif

	if (IMAI_mtb_models_count > 0)
		IMAI_mtb_models_count--;
}

/**
* Initializes a fixwin sampler handle.
*
* @param handle Pointer to a preallocated memory area of fixwin_handle_size() bytes to initialize.
*
* @param input_size Number of bytes to enqueue.
* @param count Number of items (of size input_size) in each window
*/
static inline void fixwin_init(void* restrict handle, int input_size, int count)
{
	fixwin_t* fep = (fixwin_t*)handle;
	fep->input_size = input_size;

	char* mem = ((char*)handle) + sizeof(fixwin_t);

	int data_buffer = input_size * count;
	
	cbuffer_init(&fep->data_buffer, mem, data_buffer);
}

static inline int mtb_model_soft_reset(const void* handle)
{
	mtb_ml_model_t* model = *(mtb_ml_model_t**)handle;

	cy_rslt_t result = mtb_ml_model_rnn_reset_all_parameters(model);

	if (result != MTB_ML_RESULT_SUCCESS)
		return IPWIN_RET_ERROR;

	return IPWIN_RET_SUCCESS;
}

#if defined(IMAI_PROFILING_LOG)
#define MODEL_PROFILING MTB_ML_LOG_ENABLE_MODEL_LOG
#elif defined(IMAI_PROFILING)
#define MODEL_PROFILING MTB_ML_PROFILE_ENABLE_MODEL
#endif

#define IMAI_MAX_MTB_MODELS 4
uint8_t IMAI_mtb_models_count = 0;
mtb_ml_model_t* IMAI_mtb_models[IMAI_MAX_MTB_MODELS];

void IMAI_mtb_models_print_info() {
	if (IMAI_mtb_models_count < 1)
		return;

	printf("Loaded %ld models:\r\n", (long int)IMAI_mtb_models_count);
	for (uint32_t index = 0; index < IMAI_mtb_models_count; index++) {
		printf("Model %ld:\r\n", (long int)index);
		mtb_ml_utils_print_model_info(IMAI_mtb_models[index]);
		printf("\r\n");
	}
	printf("\r\n");
}

void IMAI_mtb_models_profile_log() {
	if (IMAI_mtb_models_count < 1)
		return;

	printf("Profiling %ld models:\r\n", (long int)IMAI_mtb_models_count);
	for (uint32_t index = 0; index < IMAI_mtb_models_count; index++) {
		printf("Model %ld: %s:\r\n", (long int)index, IMAI_mtb_models[index]->name);
		mtb_ml_model_profile_log(IMAI_mtb_models[index]);
		printf("\r\n");
	}
	printf("\r\n");
}

static int mtb_init(const void* handle, uint8_t* model_bin, unsigned int model_size, uint8_t* arena_buffer, int arena_size, int npu_priority, char model_name[]) {
	mtb_ml_model_t** model_obj = (mtb_ml_model_t**)handle;

	mtb_ml_model_bin_t model = {
		.model_bin = model_bin,
		.model_size = model_size,
		.arena_size = arena_size
	};

	strncpy(model.name, model_name, MTB_ML_MODEL_NAME_LEN - 1);
	model.name[MTB_ML_MODEL_NAME_LEN - 1] = '\0';

	mtb_ml_model_buffer_t buffer = {
		.tensor_arena = arena_buffer,
		.tensor_arena_size = arena_size
	};

	if (mtb_ml_model_init(&model, &buffer, model_obj) != CY_RSLT_SUCCESS)
		return IPWIN_RET_ERROR;

#ifndef IMAI_NO_NPU
	if (mtb_ml_init(npu_priority) != CY_RSLT_SUCCESS)
		return IPWIN_RET_ERROR;
#endif

#if defined(IMAI_PROFILING) || defined(IMAI_PROFILING_LOG)
	if (mtb_ml_model_profile_config(*model_obj, MODEL_PROFILING) != CY_RSLT_SUCCESS)
		return IPWIN_RET_ERROR;

	IMAI_mtb_models[IMAI_mtb_models_count++] = *model_obj;
#endif

	return IPWIN_RET_SUCCESS;
}

#ifndef __CLOSE_HOOKS
	#define __CLOSE_HOOKS() do { } while(0)
#endif
#define __RETURN_ERROR(_exp) do { int __ret = (_exp); if(__ret < 0) { __CLOSE_HOOKS(); return __ret; } } while(0)
#define __RETURN_ALWAYS(_exp) __CLOSE_HOOKS(); return (_exp)
#define __RETURN_ERROR_BREAK_EMPTY(_exp) {  int __ret = (_exp); if(__ret == -1) break; if(__ret < 0) { __CLOSE_HOOKS(); return __ret; } }
#define __RETURN_ERROR_BREAK_EMPTY_END(_exp) {  int __ret = (_exp); if(__ret == -1 || __ret == -3) break; if(__ret < 0) { __CLOSE_HOOKS(); return __ret; } }
#define __RETURN_ERROR_CANCEL_EMPTY(_exp) {  int __ret = (_exp); if(__ret == -1) { __CLOSE_HOOKS(); return 0; } if(__ret < 0) { __CLOSE_HOOKS(); return __ret; } }
#define __BREAK_ERROR(_exp) {  int __ret = (_exp); if(__ret < 0) break; }
#define __CONTINUE_ON_EMPTY(_exp) {  int __ret = (_exp); if(__ret < -1) { __CLOSE_HOOKS(); return __ret; } }

/*
* Try read data from model.
* 
*  @param data_out Output features. Output float[5].
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*/
int IMAI_dequeue(float *restrict data_out) {    
    __HOOK_REGION(true, 0);
    while(1) {
        __RETURN_ERROR_BREAK_EMPTY(fixwin_dequeue(_K2, _K1, 256, 160));
        hannmul_f32(_K1, _K11, 1, 512, 1, _K15);
        rfft_libfft_f32(_K15, _K16, 1, 512, 1, _K18, _K19, _K20);
        norm_f32(_K16, 2, 257, _K22);
        mel_f32(_K22, _K23, 257, 1, 30, _K27);
        clip_f32(_K27, 30, 0.000316227766016, 3.40282347E+38, _K28);
        ln_f32(_K28, 30, _K3);
        __RETURN_ERROR_BREAK_EMPTY(fixwin_enqueue(_K5, _K3));
    }
    __RETURN_ERROR(fixwin_dequeue(_K5, _K4, 50, 6));
    __HOOK_REGION(false, 0);
    __HOOK_REGION(true, 1);
    __RETURN_ERROR(mtb_model_raw(_K10, _K4, 1500, data_out, 20));
    __HOOK_REGION(false, 1);
    return 0;
}

/*
* Try write data to model.
* 
*  @param data_in Input features. Input float[2].
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*/
int IMAI_enqueue(const float *restrict data_in) {    
    __HOOK_REGION(true, 0);
    __RETURN_ERROR(fixwin_enqueue(_K2, data_in));
    __HOOK_REGION(false, 0);
    return 0;
}

/*
* Closes and flushes streams, free any heap allocated memory.
* 
*/
void IMAI_finalize(void) {    
    mtb_model_free(_K10);
}

/*
* Resets windows and neural networks(i.e. RNNs) to initial state.
* 
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*/
int IMAI_soft_reset(void) {    
    fixwin_init(_K2, 8, 256);
    fixwin_init(_K5, 120, 50);
    __RETURN_ERROR(mtb_model_soft_reset(_K10));
    return 0;
}

/*
* Initializes buffers to initial state.
* 
*  @return IPWIN_RET_SUCCESS (0) or IPWIN_RET_NODATA (-1), IPWIN_RET_ERROR (-2), IPWIN_RET_STREAMEND (-3)
*/
int IMAI_init(void) {    
    fixwin_init(_K2, 8, 256);
    fixwin_init(_K5, 120, 50);
    __RETURN_ERROR(mtb_init(_K10, _K7, 39888, _K6, 16384, 3, "network_float"));
    return 0;
}

static IMAI_api_def _IMAI_api_def = {
    .api_ver = 1,
    .id = {0x68, 0x04, 0xc0, 0xa5, 0x56, 0x37, 0xfc, 0x40, 0xa4, 0xb7, 0xe9, 0x16, 0x54, 0xac, 0x78, 0xdd},
    .api_type = IMAI_API_TYPE_QUEUE,
    .prefix = "IMAI_",
    .buffer_mem = {
        .size = 10256,
        .peak_usage = 8208,
    },
    .static_mem = {
        .size = 25992,
        .peak_usage = 25984,
    },
    .readonly_mem = {
        .size = 42000,
        .peak_usage = 42000,
    },
    .func_count = 5,
    .func_list = (IMAI_func_def[]) {
        {
            .name = "IMAI_dequeue",
            .description = "Try read data from model.",
            .fn_ptr = IMAI_dequeue,
            .attrib = 3,
            .param_count = 1,
            .param_list = (IMAI_param_def[]) {
                {
                    .name = "data_out",
                    .attrib = IMAI_PARAM_OUTPUT,
                    .rank = 1,
                    .shape = (IMAI_shape_dim[]) {
                        {
                            .name = "Labels",
                            .size = 5,
                            .labels = (label_text_t[]) { "unlabeled","East","Nord","South","West" },
                        },
                    },
                    .count = 5,
                    .bytes = 20,
                    .type_id = IMAGINET_TYPES_FLOAT32,
                    .frequency = 16.666666666666668,
                    .shift = 0,
                    .scale = 0,
                    .offset = 0,
                },
            },
        },
        {
            .name = "IMAI_enqueue",
            .description = "Try write data to model.",
            .fn_ptr = IMAI_enqueue,
            .attrib = 3,
            .param_count = 1,
            .param_list = (IMAI_param_def[]) {
                {
                    .name = "data_in",
                    .attrib = IMAI_PARAM_INPUT,
                    .rank = 1,
                    .shape = (IMAI_shape_dim[]) {
                        {
                            .name = "",
                            .size = 2,
                        },
                    },
                    .count = 2,
                    .bytes = 8,
                    .type_id = IMAGINET_TYPES_FLOAT32,
                    .frequency = 16000,
                    .shift = 0,
                    .scale = 1,
                    .offset = 0,
                },
            },
        },
        {
            .name = "IMAI_finalize",
            .description = "Closes and flushes streams, free any heap allocated memory.",
            .fn_ptr = IMAI_finalize,
            .attrib = 10,
            .param_count = 0,
            .param_list = (IMAI_param_def[]) {
            },
        },
        {
            .name = "IMAI_soft_reset",
            .description = "Resets windows and neural networks(i.e. RNNs) to initial state.",
            .fn_ptr = IMAI_soft_reset,
            .attrib = 67,
            .param_count = 0,
            .param_list = (IMAI_param_def[]) {
            },
        },
        {
            .name = "IMAI_init",
            .description = "Initializes buffers to initial state.",
            .fn_ptr = IMAI_init,
            .attrib = 7,
            .param_count = 0,
            .param_list = (IMAI_param_def[]) {
            },
        },
    },
};

IMAI_api_def *IMAI_api(void) {
    return &_IMAI_api_def;
}

