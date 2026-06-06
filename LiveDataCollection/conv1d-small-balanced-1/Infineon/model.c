/*
* ImagiNet Compiler 5.12.5418.0+7793ebcc9f383586f202c2d2f6eafbd7ebe6519d
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 06/06/2026 16:59:33 UTC. Any changes will be lost.
* 
* Model ID  8bcdd86b-d186-4904-9fbc-bc57925ba314
* 
* Memory    Size                      Efficiency
* Buffers   10256 bytes (RAM)         80 %
* State     25992 bytes (RAM)         100 %
* Readonly  20560 bytes (Flash)       100 %
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
    0x0000001c, 0x00000090, 0x000000e8, 0x00003940, 0x00003950, 0x0000476c, 0x00000003, 0x00000001, 
    0x00000010, 0x000a0000, 0x000c0010, 0x00040008, 0x0000000a, 0x0000000c, 0x0000001c, 0x0000003c, 
    0x0000000f, 0x76726573, 0x5f676e69, 0x61666564, 0x00746c75, 0x00000001, 0x00000004, 0xffffff98, 
    0x00000019, 0x00000004, 0x00000008, 0x6579616c, 0x33315f72, 0x00000000, 0x00000001, 0x00000004, 
    0xffffc69a, 0x00000004, 0x00000007, 0x6579616c, 0x00305f72, 0x00000002, 0x00000034, 0x00000004, 
    0xffffffdc, 0x0000001c, 0x00000004, 0x00000013, 0x564e4f43, 0x49535245, 0x4d5f4e4f, 0x44415445, 
    0x00415441, 0x000c0008, 0x00040008, 0x00000008, 0x0000001b, 0x00000004, 0x00000013, 0x5f6e696d, 
    0x746e7572, 0x5f656d69, 0x73726576, 0x006e6f69, 0x0000001d, 0x00003854, 0x0000384c, 0x000037fc, 
    0x000037ac, 0x00002b9c, 0x000021cc, 0x00002188, 0x0000216c, 0x0000214c, 0x0000153c, 0x000014ec, 
    0x00000294, 0x00000144, 0x00000120, 0x0000010c, 0x000000ec, 0x000000e4, 0x000000dc, 0x000000d4, 
    0x000000cc, 0x000000c4, 0x000000bc, 0x000000b4, 0x000000ac, 0x000000a4, 0x0000009c, 0x00000094, 
    0x00000074, 0x00000004, 0xffffc782, 0x00000004, 0x00000060, 0x00000010, 0x00000000, 0x000e0008, 
    0x00040008, 0x00000008, 0x00000010, 0x00000024, 0x00060000, 0x00040008, 0x00000006, 0x00000004, 
    0x00000000, 0x0018000c, 0x00100014, 0x0004000c, 0x0000000c, 0xf79b1a1f, 0xe2e711a2, 0x00000003, 
    0x00000002, 0x00000004, 0x00000006, 0x39312e32, 0x0000302e, 0xffffc7ee, 0x00000004, 0x00000010, 
    0x2e362e31, 0x00000030, 0x00000000, 0x00000000, 0xffffbaa8, 0xffffbaac, 0xffffbab0, 0xffffbab4, 
    0xffffbab8, 0xffffbabc, 0xffffbac0, 0xffffbac4, 0xffffbac8, 0xffffbacc, 0xffffbad0, 0xffffc836, 
    0x00000004, 0x00000010, 0x00000001, 0x00000001, 0x00000032, 0x0000001e, 0xffffc852, 0x00000004, 
    0x00000004, 0x00000001, 0xffffc862, 0x00000004, 0x00000014, 0x3c695e35, 0xbd25bba8, 0xbc8282fb, 
    0x3d800488, 0xbcae8996, 0xffffc882, 0x00000004, 0x00000140, 0xbda49bc8, 0xbcf60ba6, 0xbec596ba, 
    0xbe9f58a2, 0x3f02e3ff, 0xbf1bceea, 0x3dab0ff8, 0xbe89204c, 0x3eb89352, 0xbf14808b, 0x3f28b4f2, 
    0x3ed1d07f, 0x3e0adff9, 0x3e907ae1, 0x3dda4164, 0x3e9d4fb2, 0xbec25013, 0x3e694a0a, 0x3e253922, 
    0xbd96f227, 0x3e99da86, 0x3e5c81b0, 0x3e23d72a, 0xbf1cff7a, 0x3f1f28f8, 0x3e76aca8, 0xbe2e55d5, 
    0x3f1d4431, 0x3e91fa1a, 0xbef64f6e, 0xbdb42117, 0x3db1216a, 0x3ed582cb, 0xbe321fa2, 0x3e9d7dc8, 
    0x3f14b2b0, 0xbefd7771, 0x3e97a097, 0xbe8f9a8b, 0x3ec3c608, 0x3b1d4147, 0x3dca8a5d, 0xbf164a76, 
    0xbe5f4198, 0x3dbe1764, 0xbdbe63b0, 0xbf34efec, 0x3edee4d9, 0xbedbb957, 0x3ea6bd42, 0x3d6a07dc, 
    0x3e0ca448, 0xbe983ced, 0x3e86c772, 0xbee1cb5e, 0xbd71f6cb, 0xbe757624, 0xbee271e4, 0x3b91b2de, 
    0xbe6812e6, 0xbe4c37f4, 0x3f1e1d3f, 0x3ed62217, 0x3e7a0b94, 0x3e735a7f, 0xbdcdb5e9, 0xbe18dc8b, 
    0xbeaf2916, 0x3e7e6cfd, 0xbf1734f0, 0x3f08d223, 0x3f0fbb3c, 0x3d594f51, 0x3ece6549, 0xbe6abd8d, 
    0xbf172262, 0x3ebd070f, 0xbef53d24, 0x3f04ed90, 0xbf2238f5, 0xffffc9ce, 0x00000004, 0x00001248, 
    0x3d74c9a1, 0x3e1f4964, 0x3e5316a1, 0x3e29eaa8, 0xbe311500, 0x3e1523c2, 0x3e1cc2d3, 0x3ddd5c95, 
    0xbccc6f87, 0xbe327369, 0xbe03ec04, 0xbd931314, 0x3e508caf, 0x3e42d3f3, 0xba177ed6, 0xbe31c1dc, 
    0x3e2763b0, 0x3d9a128a, 0x3d3de958, 0x3dc76f8a, 0x3e44eb1b, 0xbd32ddc3, 0xbe8509b5, 0xbe5efdce, 
    0x3d152dea, 0x3c6c2aa2, 0xbe8b0c3d, 0x3dcc69ad, 0xbe186685, 0x3e2acfcd, 0xbca1089b, 0x3d5923e7, 
    0x3d80dc6b, 0x3d2fda95, 0xbe50d0d7, 0x3df638a0, 0xbe30a46b, 0xbb05e65e, 0xbe2bd291, 0x3e3e6379, 
    0x3e15afdc, 0x3e4d97d5, 0x3e07dbcd, 0xbc265b34, 0xbb1b087b, 0xbe079e33, 0x3c0d7a14, 0xbddb0963, 
    0x3e2ad4df, 0xbe3251b3, 0xbd7c1ffb, 0x3da3f164, 0x3e24ad12, 0x3c9a964c, 0xbdb9ff24, 0xbda5a9f4, 
    0xbe4d7da2, 0x3e103d6c, 0xbe2a32d2, 0xbe249f33, 0x3e55957a, 0xbdcd3a92, 0x3d5581d3, 0x3e378857, 
    0xbe50885f, 0x3df5f04c, 0xbc48f2d7, 0x3d110edb, 0xbe0a87be, 0x3d38efa1, 0x3d6bdfdc, 0xbd6de412, 
    0x3e53b9dc, 0xbe3d488e, 0x3da6d67e, 0xbcdf4f5b, 0x3d5f47f1, 0x3d9620de, 0xbe46140e, 0x3e17ec16, 
    0x3e336866, 0xbdaa2f0e, 0xbe1f6f6f, 0xbe184407, 0x3c3dc05d, 0xbe7190b4, 0xbb04142b, 0x3e395971, 
    0x3be40d3f, 0xbe104607, 0x3dad384c, 0x3e27fea2, 0xbc4bf1ef, 0x3ca2487a, 0xbe085437, 0x3ca938e7, 
    0x3c874dac, 0x3e2e938e, 0xbdaba137, 0x3e27a76e, 0xbe21785d, 0x3e041e2b, 0x3db84467, 0x3bf3e795, 
    0x3dd3b13d, 0x3e122a0a, 0x3e425c09, 0x3e02e9fb, 0xbdf80487, 0xbdda5274, 0xbe48e5f6, 0xbd30e2a9, 
    0x3df7822c, 0x3e3ee97d, 0xbde32ce5, 0xbda03b7f, 0xbd967b07, 0xbe7019fc, 0xbe4a907a, 0xbd164bf2, 
    0x3cfe30d9, 0x3c3458a3, 0x3d5d1a00, 0x3dfd55a2, 0xbe0bb611, 0xbd4a8e73, 0x3e17a9ad, 0x3e243dbd, 
    0xbd860093, 0x3c833182, 0x3dbef81f, 0xbce2f075, 0x3e2f35c0, 0xbd64aedb, 0x3dec5555, 0x3e10b685, 
    0x3e24945d, 0x3e2054dd, 0xbe349bf0, 0x3ce531a0, 0x3e281a64, 0xbdb8ac58, 0x3e84df2b, 0xbcd0fb8b, 
    0xbc8a7e87, 0xbcd9de81, 0x3e3a0179, 0x3e32bb0a, 0x3cf4d9bb, 0xbe831eed, 0xbdc0a442, 0x3db5cd63, 
    0x3d8dc247, 0xbe7b33da, 0x3dfb6b7a, 0x3d5c3e30, 0xbcb5c44b, 0x3e434d2e, 0xbe15c161, 0xbdd99d7c, 
    0x3e317d76, 0x3e296ff2, 0xbd81d939, 0x3d99cd37, 0x3e2a3ae4, 0x3de8a3ca, 0xbd038a9c, 0x3d8fdee6, 
    0xbdc50dcb, 0xbe4b39fa, 0xbe3d08b5, 0xbe13d7ba, 0x3db05915, 0x3df811e9, 0x3dd09493, 0x3dfa12c0, 
    0xbdb9c1af, 0xbc7a03ff, 0xbde75141, 0xbe88ee1d, 0xbd87dfbf, 0x3b8176da, 0x3e0affd6, 0x3e593f5e, 
    0x3d53b525, 0x3dba1492, 0x3dc0322a, 0xbda87a49, 0x3cbe25cc, 0x3de5a5a8, 0xbdd3946c, 0xbd2f3ef8, 
    0xbd408c58, 0x3e61e6bf, 0xbcef3ac8, 0xbe2a225c, 0x3d7cc72b, 0x3de9ca70, 0xbb8e3139, 0x3dcec6b4, 
    0xbca0d8dd, 0xbe339514, 0xbe5395b0, 0x3de62e09, 0xbda35060, 0xbe508b53, 0x3ddcf4e8, 0xbe037749, 
    0xbe806401, 0x3defdab3, 0x3da45126, 0xbda315c1, 0xbdf4ac12, 0xbda1d7f4, 0xbcdf6c0c, 0x3de75225, 
    0xbd91f4cd, 0x3e29f102, 0xbdc910e1, 0xbe0d6eaa, 0x3d99aa23, 0x3d6d9bd9, 0x3de9596f, 0x3d34b2f6, 
    0x3d9d494a, 0x3e145e1e, 0xbd087ef1, 0xbe516544, 0x3d875eae, 0xbb9ca3c4, 0x3e84d7e4, 0xbd817069, 
    0xbe2332a9, 0x3dd60c62, 0x3be66bda, 0xbdbe4f54, 0xbdff7c3f, 0x3ca21987, 0xbe87c823, 0x3d8efe75, 
    0x3dc1eb1c, 0xbdfec7e0, 0xbd05e3b9, 0xbd923cf8, 0x3e462190, 0xbde0fb74, 0xbdfb9e08, 0xbdfbd276, 
    0xbc77f855, 0x3d0515dc, 0x3ccaeff8, 0x3e4036b8, 0xbc531a0d, 0x3e1622b9, 0x3e319580, 0x3d141dc6, 
    0x3dfb0c8a, 0x3e0cbb3a, 0x3cf71563, 0xbbd42774, 0x3e751dd6, 0x3e3a8155, 0xbe22c276, 0xbe155ca4, 
    0x3dc1d5eb, 0xbe55b6a8, 0x3e2a08eb, 0xbdd363fb, 0xbd0f5fee, 0xbd2a542e, 0xbe37d406, 0x3e408de9, 
    0x3df90f23, 0x3d000f21, 0xbde6f2fb, 0x3e00016e, 0xbe5712e8, 0xbe05d3eb, 0xbdd21bd9, 0xbd4dacc0, 
    0x3d1b00b9, 0xbdf3b126, 0x3e114be1, 0xbdee2807, 0xbe78e5bf, 0xbdd672ed, 0xbddf42e8, 0xbe203b4c, 
    0xbd88369b, 0x3e3806f2, 0xbe4530d1, 0xbdf6d338, 0x3ddd1411, 0x3e1801a6, 0xbd8d0353, 0xbdbf4c95, 
    0xbc9a9466, 0x3e026253, 0x3da5242f, 0x3c8b8130, 0xbe294259, 0x3dac65be, 0x3d171a3c, 0xbddd5c21, 
    0xbc60de0b, 0xbe22b18f, 0x3d164cf8, 0x3d4b0ec9, 0x3e1ef13f, 0xbe6299de, 0x3d87a8a5, 0x3e1a6659, 
    0xbdcba9e2, 0x3dd4a6d0, 0xbd4411c4, 0xbcc39e16, 0x3da326b5, 0xbc241122, 0x3e49d698, 0x3dd97dba, 
    0x3e4ee6bd, 0x3d9f9ae1, 0x3cfe7da8, 0x3e4806c5, 0xbdc21053, 0xbdb81c68, 0xbe211bb2, 0xbca9ef84, 
    0x3ce356fa, 0xbe1173f0, 0x3e4b1369, 0x3b7f5287, 0x3e30cf48, 0x3cb2ea76, 0x3dd4cb03, 0x3e274365, 
    0x3e405d07, 0x3d854f6a, 0xbdc54f53, 0xbd870b67, 0xbceb3189, 0x3df8c2a9, 0xbe0a686c, 0x3dd2d8af, 
    0x3e08f935, 0xbe3db44c, 0xbdfc36ea, 0xbddff489, 0x3e340484, 0x3d83263b, 0xbe3b3c92, 0x3e4c11d7, 
    0x3e4dbe97, 0xbb8fa086, 0xbda29bd1, 0xbdcb43ee, 0xbd2c000d, 0xbd7e9556, 0xbc96273d, 0x3e7e35aa, 
    0x3dbfa488, 0x3da3bf96, 0x3e2bfb81, 0xbc9add44, 0xbd3ea229, 0xbe5052cc, 0xbe3280b5, 0xbd9270d5, 
    0xbd2f9d2f, 0x3ddf85d5, 0xbda3dceb, 0xbdff2441, 0xbdf7f391, 0xbe265975, 0xbe519c44, 0xbd8909cc, 
    0x3dedd5b1, 0xbe1e119a, 0x3c8984d6, 0x3e32e003, 0x3e38265b, 0xbc941e17, 0xbe2468df, 0xbdfe6e60, 
    0x3e196973, 0xbe2ed142, 0xbc214bb0, 0x3daef15f, 0xbda16f2a, 0x3e0212ab, 0xbe66fad1, 0x3e0c721f, 
    0xbdbf0021, 0x3cd7039a, 0xbe4e1004, 0xbc8478ad, 0x3d5422e0, 0xbd0f62b1, 0xbde05ba8, 0x3d627b2a, 
    0x3e16a334, 0x3e2c69df, 0x3dc9d2c9, 0xbe3e1409, 0xbdcd1b44, 0xbdbc5f4e, 0x3df8023c, 0x3db04546, 
    0x3c477b24, 0xbe534159, 0xbe3c7f5d, 0xbd6e4dd5, 0xbe04fec4, 0x3d671af9, 0x3dd724d1, 0xbd8852a1, 
    0x3e643bc9, 0x3dccde51, 0xbd82e0fd, 0x3e2a74ec, 0xbca1e2e7, 0x3d961ed5, 0x3ceda943, 0x3e19af40, 
    0xbe315051, 0xbdb72927, 0xbdc4abe5, 0xbcd5cd62, 0xbb27d4fb, 0x3e0edfd8, 0xbd702ad7, 0xbab335c3, 
    0x3dd2e574, 0xbe0677a2, 0xbd6de769, 0xbdaa6089, 0x3e2e9629, 0xbdf0678e, 0x3d72b01e, 0x3e5cef94, 
    0x3e228d2d, 0x3d0857fe, 0x3db2ac06, 0xbe353d85, 0x3d9536cc, 0x3e2906ce, 0x3e382acb, 0x3e0dfa4f, 
    0xbe207388, 0xbdb21b8f, 0xbddad73c, 0xbe07c589, 0x3d8551ab, 0xbe3a7673, 0x3e2a942f, 0xbe2a2ecd, 
    0x3dd6aa52, 0xbe3fd094, 0xbca96264, 0xbe088ca3, 0xbdfdc9be, 0xbdbb939d, 0x3ceb71a0, 0x3e323ca6, 
    0x3e1a99d1, 0x3dda3ea9, 0x3e1b44e6, 0x3e33fbd1, 0xbdcc6287, 0x3e2c0256, 0x3e0f2411, 0xbd98f049, 
    0xbc901501, 0xbe1daa01, 0x3d8547fb, 0x3e122037, 0xbd88958a, 0x3dce94a1, 0x3e6035ff, 0x3abb44b2, 
    0xbde39690, 0xbd3f51e8, 0x3ddefd9e, 0xbdb9b909, 0x3e72a75c, 0xbde6331a, 0x3d739833, 0x3d40c28e, 
    0x3e49a8a2, 0xbe2298c8, 0x3e457a2b, 0xbb66ec3d, 0xbe11d18a, 0x3d5aa1ee, 0xbe6aa8be, 0x3cee24cc, 
    0x3e1d2655, 0x3e29c5ac, 0xbe774a2f, 0xbd49c17e, 0xbe4bdc1b, 0xbe3e406a, 0x3d627938, 0xbdb2e748, 
    0x3e2b533d, 0x3d59f880, 0xbe315b2d, 0xbdc89de2, 0x3e64af49, 0x3e4276ec, 0xbe3f88c0, 0xbe1f2830, 
    0x3c4a4b31, 0xbdc3775d, 0xbd8760da, 0xbdf65c9f, 0xbd84e129, 0x3b39fba5, 0x3d2f940f, 0x3e12be8c, 
    0xbe635d30, 0x3e473d38, 0x3d9bd9e3, 0x3e14b2d2, 0xbe560015, 0xbe56e992, 0xbe1edffa, 0x3da35332, 
    0x3e16aca2, 0xbb90e583, 0x3e220a98, 0x3de92f92, 0x3d5c843e, 0x3e12fd4b, 0xbd00de78, 0xbde7b7f0, 
    0xbe0d15de, 0x3d8bbb07, 0x3c82f5e0, 0xbd72d612, 0xbe4ea3e7, 0xbe2ee211, 0x3d54dc4f, 0x3e149dfb, 
    0x3da7300f, 0x3d031fc1, 0x3e18a59a, 0xbc650ace, 0xbddfc7f7, 0xbc4e8fd8, 0x3d8a5b4a, 0xbe306150, 
    0xbe1933b4, 0xbdd0bd4a, 0x3cecef24, 0x3cb9d4b9, 0xbe1409b1, 0x3d97fd20, 0x3e23c851, 0x3d239344, 
    0xbc9f7832, 0x3d3ab561, 0xbe2b6f28, 0x3d77aa66, 0xbd958579, 0x3e260ca2, 0xbd9474cf, 0x3caa5e02, 
    0xbd9b39a5, 0xbdfb94a3, 0x3e00ef75, 0x3e19ad6d, 0x3daa0567, 0xbc0029f6, 0xbdf4742a, 0x3e267e9b, 
    0x3d0549a7, 0x3e052368, 0xbe3922be, 0x3e16f1dc, 0xbe47272a, 0x3d1d19dd, 0x3d23be2a, 0x3d147610, 
    0xbcca8e05, 0x3d2cfebe, 0xbdec527a, 0xbccd1f18, 0x3e1544ae, 0x3d0ccfb3, 0x3da4ce4c, 0x3e56b5f5, 
    0xbc04968e, 0xbd9ade59, 0xbe763c65, 0xbd94394b, 0x3bc6c501, 0xbde2e2ab, 0xbe3b872c, 0x3da3c8aa, 
    0x3d372390, 0xbc921615, 0xbe0a36d8, 0xbbecfe7c, 0x3dd2b1c1, 0x3e1d5e01, 0x3e431de5, 0xbe44cf4e, 
    0x3e33efb1, 0xbe2cb067, 0x3e58d29e, 0x3e452e5d, 0x3da25e9e, 0x3e51d2fc, 0xbd94d9cd, 0xbdb1d8fe, 
    0x3e42f7df, 0xbd892044, 0x3e2b10bb, 0x3decc052, 0xbd87570b, 0x3e5b17f9, 0x3e1e191d, 0xbe107c51, 
    0xbe7b56b0, 0xbd5834fc, 0x3c86fe44, 0x3dea7fe6, 0xbe3ed9b2, 0x3bb41332, 0xbced2fc8, 0xbe0b0799, 
    0x3ddb9bd5, 0xbd136cb3, 0xbe0ed44b, 0xbdfa8b87, 0x3d69f934, 0xbe228677, 0x3df173dc, 0x3d411010, 
    0x3d061f74, 0xba37cd32, 0xbdb4d693, 0x3e6213fe, 0x3a6c6205, 0x3d2ca9ec, 0x3d6fb5e9, 0x3d7d2bf5, 
    0xbe48c046, 0xbd675b25, 0x3e03a38f, 0x3bff77be, 0x3d23f955, 0x3dae386a, 0xbe7e00fe, 0x3e2372cb, 
    0xbdf37794, 0x3da069f6, 0xbe5b19b8, 0xbe765946, 0xbe19cf93, 0x3e2546a2, 0x3dc0b54c, 0xbe809e00, 
    0x3dd579be, 0xbe2a7c31, 0xbe7dd565, 0xbdf16742, 0x3dbae2ab, 0x3e4667a9, 0xbe3616aa, 0x3dcca52f, 
    0x3da41f76, 0xbcbf36f1, 0x3e0b2505, 0xbc7fccc1, 0xbde02cf1, 0x3e57d464, 0xbd5ec18d, 0xbd0c6d7e, 
    0x3d593dd3, 0xbdde5d8a, 0xbd6b73b1, 0xbe262e8c, 0x3dfb24e7, 0xbd7ea881, 0x3e0847e1, 0x3ddf62ea, 
    0x3b92712a, 0xbe6f33df, 0xbd7c4c1e, 0x3ddbf014, 0xbc81ab0b, 0x3dbe76b8, 0xbe86d95e, 0xbdf30560, 
    0x3de21659, 0xbe3c5a27, 0x3db13c87, 0xbdad4947, 0xbd4ad291, 0x3dd746ab, 0xbdb03bc0, 0xbd4b264b, 
    0xbe20fc60, 0xbe3c0333, 0xbe0fd04b, 0xbda8b2d9, 0x3e32cab8, 0xbd2b2d25, 0x3e0c9fa2, 0x3e4b58cc, 
    0xbe437374, 0x3c70fd40, 0xbba4683a, 0x3e14f1c0, 0x3ce76dcd, 0x3e206551, 0xbd1eec32, 0x3d8bc433, 
    0x3aee1e2e, 0x3e28b5ec, 0x3df5ae29, 0xbd32cce0, 0x3c2193ad, 0xbddbcd98, 0x3e371c34, 0x3e2a04da, 
    0xbdea40d0, 0x3e808696, 0xbe1f5581, 0xbb68eed9, 0x3e369709, 0xbe59c66d, 0xbd18b299, 0x3d83e42b, 
    0xbda22dda, 0x3e6b71ee, 0xbba24dab, 0x3da2b0d7, 0x3de562da, 0xbb27e4b3, 0xbd026bb1, 0x3d7e57e1, 
    0xbddd5036, 0x3cb98468, 0xbe4179ab, 0xbe4208e1, 0x3d41f3ff, 0x3df95600, 0x3e3e2a50, 0x3d8278a7, 
    0x3dcf0eb7, 0x3dd5e5d6, 0x3e1218d0, 0xbdd3f554, 0x3dee3969, 0xbd6aa13c, 0xbd94a9fe, 0x3e35b075, 
    0x3e688ea8, 0xbe0d7385, 0xbe49ada6, 0xbe266424, 0x3d1c3a13, 0xbd5ea749, 0x3e263732, 0xbd55fc14, 
    0x3cf9c8e7, 0x3e1356ce, 0xbe09f978, 0xbe0f7aae, 0xbda7a2b5, 0xbde10eed, 0x3db58a58, 0xbe040986, 
    0xbd7bb2e9, 0xbe4fd721, 0xbda6dfba, 0x3e2cf4bf, 0x3d5d8b87, 0xbdc93499, 0xbbc84e46, 0x3d4817b9, 
    0xbe1faeb1, 0x3e05af03, 0xbe17dd9c, 0xbe2ef27d, 0x3cf64f9a, 0xbd1306b1, 0xbc872567, 0x3e2d44d4, 
    0xbdc84702, 0xbe4b4624, 0xbe0ab5e5, 0x3a7a66ee, 0x3e39de31, 0x3bf3394f, 0xbd034259, 0x3e06c396, 
    0xbb71225b, 0x3db0ba84, 0xbe10c5ef, 0xbccabf61, 0x3d55726d, 0xbdcb8677, 0xbc3829bb, 0x3dcdceb0, 
    0xbdbd1e7c, 0xbe6169f8, 0x3d8bdb82, 0xbe02e957, 0x3e622363, 0x3a89e43a, 0x3d7d68ff, 0xbe119e67, 
    0x3e4fb10b, 0xbe3f44e2, 0x3e38bce9, 0x3ca5217f, 0x3e400b2b, 0x3e1b1a28, 0xbd5f8e05, 0x3cec6e91, 
    0xbe46b000, 0xb9978c82, 0xbded0211, 0xbe4d17eb, 0x3ddea59f, 0xbddded48, 0x3afc5d3c, 0xbe47123b, 
    0x3e233151, 0x3da27923, 0xbe4a725b, 0xbdf9579c, 0xbe186f14, 0xbe3cf386, 0x3d9f061e, 0x3e5b8121, 
    0xbc9c1482, 0x3e0ffe1e, 0x3e5311b8, 0xbc70c126, 0xbda9a003, 0xbe078be3, 0x3c495d2c, 0xbd9a0fc8, 
    0x3ca47e07, 0xbbc5343e, 0xbe3f9675, 0x3e2b5429, 0xbdc80776, 0x3e09be96, 0xbdb46506, 0x3da27e53, 
    0xbd1d12ea, 0x3e1cda4b, 0xbe3093a3, 0xbde36580, 0x3e32f093, 0xbe59763f, 0x3dfa5ff6, 0xbd37773a, 
    0x3e4a2fe4, 0xbe03bf10, 0xbc7cd1bd, 0xbe344220, 0xbc15de3b, 0x3e4d3375, 0xbd216ec3, 0xbd521a4c, 
    0xbd08da93, 0x3bda86c1, 0x3e04cf1e, 0xbcc2074b, 0x3df8a179, 0x3e257a0f, 0x3cb8f0ee, 0xbbcfb8ee, 
    0xbe1c83d3, 0xbbc0c141, 0x3c6343d2, 0xbdbc3d07, 0xbdf00e10, 0xbe266893, 0xbe1e03b0, 0x3dde7a04, 
    0xbe422dd2, 0x3c21eeb8, 0x3de9667a, 0x3d2bdf09, 0x3e1d9511, 0x3e09a23b, 0xbd1b4bef, 0x3de17e2b, 
    0xbd23a6b7, 0x3d8e175a, 0xbe807f75, 0xbd0c4973, 0x3cd8c0ff, 0x3ca3e4f8, 0xbcebd415, 0xbe2dcec3, 
    0xbe4eb2db, 0xbb2bc7ee, 0xbd736a6a, 0x3d80a343, 0xbda8b14b, 0xbca8ca9b, 0x3e68c37e, 0xbe3fdd96, 
    0x3d0f9679, 0xbe040297, 0x3d8fcb19, 0xbd054090, 0xbd5108ff, 0x3deb880a, 0x3e4c7114, 0x3c22e57a, 
    0x3d999897, 0x3df4487f, 0xbe1e0c8d, 0xbdd476ea, 0x3d2f00f3, 0x3e25aca3, 0x3e2fc88f, 0x3dac0497, 
    0x3db5d4a6, 0x3dc76b4d, 0xbe0021ed, 0xbe4395ad, 0xbdad6738, 0xbe342bdf, 0xbb82e6a4, 0xbd8be8d2, 
    0xbd685bf2, 0xbca6ff80, 0xbdfebffb, 0x3da07bce, 0x3e318d13, 0xbdb6ec11, 0x3d5ac3b2, 0xbdb5901e, 
    0xbd0b0d25, 0x3d46ec26, 0xbdcb7c36, 0xbcfd7e4c, 0x3de1068c, 0x3e46d789, 0x3ddc2ca8, 0x3e17be27, 
    0xbe04ab44, 0xbe1e90ee, 0x3e13eb6b, 0x3e305d74, 0xbdf5d528, 0x3e168dc3, 0xbda37074, 0x3b9f529e, 
    0x3d422709, 0x3d890ee4, 0xbbfc8556, 0x3badc684, 0x3e0f5060, 0xbce0a58b, 0x3e3d8fd7, 0x3c8ea279, 
    0x3e2fdb6d, 0xbd8ab32c, 0x3dcf484f, 0x3d924cd4, 0x3e0cab33, 0xbcb83bfe, 0xbd05f511, 0xbca408cc, 
    0x3df459ab, 0x3dc22845, 0xbd8c1b3c, 0xbc6d1656, 0x3cdbb235, 0x3e5ddda2, 0xbe063d2e, 0x3d9ec389, 
    0x3e083556, 0x3e285b80, 0xbe53e445, 0xbe251c15, 0xbd8bbd93, 0xbe285769, 0xbda33618, 0xbe2ede36, 
    0x3cf52902, 0x3dc5e9f7, 0xbda6c596, 0x3de85706, 0xbde2b3e5, 0x3e199bda, 0x3c36236c, 0x3e1b7eeb, 
    0xbd9b52d1, 0xbdda4c47, 0x3e02312d, 0x3c8778c2, 0xbd4f769b, 0x3df65d45, 0xbdaed754, 0xbc99f71a, 
    0xbce20796, 0x3d70015b, 0xbe6663fa, 0xbd915e51, 0xbe3d0e56, 0xbde98107, 0x3c5e87e0, 0x3d3914eb, 
    0x3ddc214f, 0xbd09c763, 0xbe3ae9f1, 0xbe8f8b28, 0x3d743f93, 0xbe029266, 0x3e140dc7, 0x3d8b7dfb, 
    0xbb963ed7, 0x3d99a862, 0xbd94b65a, 0xbbb58ac1, 0x3e2c5053, 0x3d98f97a, 0xbe10f91a, 0x3d2d657b, 
    0xbba5ac47, 0xbe25a445, 0x3e68a0c0, 0xbcce757d, 0x3e57a98d, 0x3e3035ac, 0x3e125294, 0x3bc504bd, 
    0xbe3e2ca0, 0x3c9fe7c2, 0xbd97ae7d, 0xbe378766, 0xbddc1ad1, 0xbdce80bd, 0x3e26c3c6, 0xbe634a74, 
    0x3e01c19c, 0x3cdbcbf7, 0x3e1562a5, 0x3dc8f3b8, 0xbe8ad7c5, 0xbe1ffcaf, 0x3d49c8a5, 0x3d89381e, 
    0xbd896037, 0xbd668078, 0x3a6a3421, 0x3dfe0800, 0x3da2d978, 0xbc2d8954, 0x3e1f18f1, 0xbde8510c, 
    0xbe0b43ee, 0xbe290e91, 0xbdcebda0, 0x3e0d1b59, 0x3c24ae92, 0xbe2a7b77, 0x3d81bb20, 0xbe32969f, 
    0x3e04edf6, 0x3e3a846d, 0x3d906c95, 0xbd687c7e, 0xbe3fc8e1, 0xbe3be181, 0xbd310951, 0x3e0b5ce3, 
    0xbcc525b0, 0x3d3abaff, 0xbda501a1, 0xbc5ac542, 0xbdfac926, 0xbe442fe0, 0x3e4da04a, 0x3e004506, 
    0x3e0ac734, 0x3dd88789, 0x3ceb53d5, 0xbe18e65c, 0xbe1be72a, 0x3e12a48b, 0xbd802a05, 0x3e803426, 
    0x3d68e21e, 0xbd633a92, 0xbe5a6d94, 0x3e08da57, 0x3df84016, 0xbe5c9dce, 0x3df63d7a, 0x3e1e9ee9, 
    0xbd27836b, 0xbe233a41, 0xbe189ea8, 0xbd0a3f40, 0xbdb0dc03, 0xbdb381e3, 0xbdd092a9, 0xbd914675, 
    0x3ddf4876, 0xbdfe9f22, 0x3d1528f0, 0xbe20c1e0, 0xbd15f592, 0xbdaa6a1a, 0x3da28068, 0xbe607611, 
    0xbd60bf44, 0xbd71f322, 0xbdb79981, 0x3e130a3e, 0xbe03d0bd, 0x3da546a6, 0x3cf55f39, 0x3d287985, 
    0x3e0a57b3, 0x3df3bce0, 0x3e234836, 0x3e1bf606, 0xbe2418df, 0x3ca34618, 0xbdcf96ce, 0x3dd08898, 
    0x3de08381, 0x3ddfc16d, 0xbe40d5ec, 0xbd9ae968, 0xbdc5cb57, 0xbca639c1, 0xbe1ee942, 0xbdb2c323, 
    0xbd4b2151, 0x3e14b223, 0xbd73eaf8, 0xbd19fd67, 0xbc6ab28d, 0xbe505127, 0xbcde7666, 0x3b03fbc6, 
    0x3e03ae96, 0xbdbbf295, 0x3cf523df, 0xbd354e76, 0xbe34b286, 0xbde9767e, 0x3d59c8d6, 0x3d7edd8b, 
    0x3e803638, 0x3e3cdb82, 0x3df17390, 0x3db27b27, 0xbd2c38ab, 0xbe53953b, 0xbd986761, 0x3da262c2, 
    0x3dd8f90a, 0x3e13c55b, 0xffffdc22, 0x00000004, 0x00000040, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xffffdc6e, 0x00000004, 0x00000c00, 
    0xbc781da1, 0xbe9743a5, 0x3de88b65, 0x3d762c94, 0xbe504ac7, 0x3db85170, 0xbd8c6a68, 0xbe85562c, 
    0xbd6897ac, 0xbe256bb8, 0xbd9d1825, 0xbe104624, 0x3d8d4a37, 0xbcee41f6, 0x3d261005, 0x3e15caa9, 
    0x3e15f930, 0xbd8b7742, 0x3e39774e, 0x3d864ab1, 0xbe0eafb2, 0x3d08f12d, 0xbe353487, 0x3db785e5, 
    0xbce455d7, 0x3c8280c9, 0xbe1e235c, 0xbe5e19fe, 0x3d1a995a, 0x3e408451, 0x3c8aa91d, 0xbde77726, 
    0x3e179f56, 0xbd3ec77d, 0xbcf4f531, 0xbd9b4fe7, 0x3e28e098, 0xbdb15439, 0x3dd2f7a6, 0xbd9fb3c7, 
    0xbe8b4e05, 0xbe214d9c, 0xbe16c536, 0xbe265278, 0xbe315e67, 0x3e1b6ef8, 0xbe01960f, 0x3d80ab8d, 
    0x3d3d6467, 0xbe3f648a, 0x3e294ddd, 0xbda41897, 0xbe75f571, 0xbe147df9, 0xbe5fe060, 0x3e52b813, 
    0x3dff1ab4, 0x3de25e89, 0xbe66cf62, 0xbd33af2e, 0x3dceb7de, 0x3e267404, 0xbdac729a, 0xbe2e72e4, 
    0xbe3bc705, 0x3e3aa8b8, 0x3cd0bf0f, 0x3e55be4b, 0xbd96591e, 0xbd67f081, 0x3d92595b, 0xbe3a0ef4, 
    0x3e83fc66, 0x3e4a662d, 0xbe31d8be, 0xbdc7d0eb, 0xbda1dde8, 0x3c0dcb38, 0x3cebdf05, 0x3e87f155, 
    0xbe0f4273, 0xbe555b00, 0xbe5502da, 0x3d9979af, 0x3df3c0fb, 0x3e33bd13, 0xbba1d434, 0xbd0c2567, 
    0x3e1a4e9c, 0xbe4f79f4, 0xbe4f76bf, 0xbe4e2cc4, 0x3e46d2de, 0x3e5fe8e3, 0x3e7d7b26, 0xbc8ca00b, 
    0xbcdb625d, 0xbd9a7112, 0xbe1a47bb, 0xbe08aa0d, 0x3e03db33, 0x3d922113, 0xbd2306f3, 0x3e4fbbc6, 
    0x3a8f5d4a, 0x3bd74d34, 0xbbe01ba1, 0xbd398320, 0xbe8067d5, 0x3cbf0f89, 0xbde59caa, 0xbdbee89e, 
    0xbe32ac85, 0x3de487d6, 0x3e2983e4, 0xbe308dab, 0x3e55ea5b, 0xbe02a776, 0xbe253a5e, 0xbe238a44, 
    0xbe383c99, 0xbe4c9b80, 0xbd4943f6, 0x3e0dd456, 0xbe02140d, 0x3e44e6fb, 0xbd2438fd, 0xbe73c17d, 
    0xbe50c7ac, 0xbd77046c, 0x3d3b6fc2, 0xbe0dca3c, 0xbe851a3a, 0xbe13ae02, 0x3d9bc386, 0x3d204fee, 
    0xbdffe775, 0xbd661e25, 0xbcfc4b6d, 0xbcbd090a, 0xbe57da03, 0x3e59eb1a, 0xbe595688, 0xbe695525, 
    0x3c6e1a6f, 0x3e69f63e, 0xbdcc5cc8, 0x3ea233e1, 0xbde7d4b4, 0x3e68b623, 0x3d1ef34e, 0xbdea8ad3, 
    0x3d51c11c, 0x3d2125bd, 0xbc802629, 0xbe8ef096, 0x3d90df20, 0x3e2b09f1, 0xbe1b43ed, 0xbd15123f, 
    0xbe266ecd, 0xbd5bc757, 0xbdd85c25, 0xbd3c834a, 0x3e6a1d67, 0xbcf2e41e, 0x3e2072d0, 0x3e9f9244, 
    0x3d6b77a7, 0xbde25040, 0x3de0f56c, 0xbe40f71c, 0xbe1c6c45, 0x3e084083, 0xbe097c6d, 0xbaa3a75f, 
    0x3ddf7828, 0xbe166a05, 0xbe2a2316, 0x3c044939, 0xbe71df4c, 0x3e25aa2c, 0x3d94558e, 0xbc01388a, 
    0xbe481082, 0xbdb7ca51, 0xbd38ad0f, 0x3d04789e, 0x3e115490, 0x3e02557d, 0xbe98bcc8, 0xbe631874, 
    0xbc9369b0, 0xbe3399be, 0x3c664301, 0x3e4fd081, 0xbe18b8e4, 0x3d3cef37, 0x3e085cdb, 0x3a34dda8, 
    0xbe27ee2c, 0xbab730fb, 0xbe0ae4c8, 0xbd6aef9c, 0x3de02a16, 0xbd0aeb85, 0xbe0ed0f8, 0xbc3a12d1, 
    0x3ccdf22a, 0xbe3262f7, 0xbe9852e7, 0x3e232d10, 0x3e0377af, 0xbaf9fba6, 0xbe92e7ae, 0xbe105e0b, 
    0x3de63d68, 0xbe3ff0b0, 0x3e75cde4, 0xbca8ffee, 0x3d345e6d, 0x3e767906, 0x3d7f5794, 0x3bcb8b90, 
    0xbd8721a9, 0xbdeb9606, 0x3d1fada1, 0x3e55c671, 0x3de35a93, 0xbdb6408e, 0xbd67a49d, 0xb8fd3a73, 
    0xbd131ac9, 0xbe09ea66, 0x3d1f92d7, 0xbe98ff87, 0x3e194deb, 0xbcaad053, 0xbd8ba58e, 0xbe20e4bf, 
    0xbd626038, 0x3d8adb8d, 0x3de11e80, 0xbe84d363, 0xbde45f0b, 0x3e54745c, 0xbe5c9e69, 0x3dfe5c3d, 
    0x3dc591de, 0xbd4e62a8, 0x3d118d8d, 0x3e210591, 0xbe64c046, 0x3e31ed55, 0x3dc74c06, 0x3cbec1f3, 
    0x3e6bd9d2, 0xbe0e187a, 0xbda6c7bd, 0xbe08d05f, 0xbe823551, 0xbda2d4d9, 0xbe2b6fed, 0x3d97349c, 
    0xbe5db018, 0x3e0597c1, 0x3d57fbd6, 0x3db9f8b8, 0x3e22424c, 0xbc3ae87d, 0xbc3c9f5f, 0xbd815cfb, 
    0xbcd10909, 0x3e7dfb98, 0x3dc82ba3, 0x3e5aa502, 0xbe4f523c, 0x3e05e596, 0xbda69785, 0x3daa2195, 
    0x3e527976, 0x3dc59c3e, 0x3e6d44b7, 0x3e03e9cb, 0x3e0a334c, 0xbe07e2b9, 0xbcb6c056, 0xbe3ced23, 
    0x3c60dbdf, 0xbdd9f9d3, 0xbe422fda, 0x3e090591, 0x3e676979, 0x3d330b55, 0xbe35257f, 0xbe146e8c, 
    0xbe41c79f, 0xbde0aa24, 0xbe39ebca, 0xbe16067e, 0x3e81dd5e, 0x3e2f9312, 0xbcc8c2b6, 0x3e57e49a, 
    0x3e783116, 0x3e5063d5, 0x3e494420, 0xbd8e3066, 0xbe38af71, 0x3daa380d, 0xbd8891fe, 0x3dc16456, 
    0xbe8b3d4b, 0x3dd808b8, 0x3e4d5cc0, 0xbe401138, 0xbb774a8b, 0x3e3ab4ab, 0x3e4f4124, 0xbd37b0c3, 
    0x3de8165a, 0xbe4faec5, 0x3e0c8135, 0x3d2c1b97, 0xbdeea415, 0x3dcaaed0, 0xbd80b283, 0x3e1c4875, 
    0xbe3e6453, 0x3e48313b, 0x3e236844, 0x3e457266, 0x3cc17318, 0x3d60a537, 0x3defde02, 0xbe33557c, 
    0xbb1d0e84, 0x3e83c1be, 0x3e71bd5e, 0xbe160ba0, 0x3dc5fed0, 0x3e5173ca, 0xbe4a2755, 0x3c998879, 
    0xbe2a9033, 0xbe14fa6b, 0x3cfcb763, 0xbda3ce1a, 0xbe1db234, 0x3e341e98, 0x3dd593b9, 0x3e511ccb, 
    0xbe2b4e4e, 0xbde28a73, 0x3e742131, 0xbca750e6, 0xbe147b3c, 0x3e1a0177, 0xbe531280, 0xbe0bb2bb, 
    0xbdc380fe, 0x3b76f2d2, 0x39f8ebad, 0xbde3e95b, 0x3e2ee2e1, 0xbe679347, 0x3e237ddf, 0x3b558637, 
    0xbe8f2eaa, 0x3c9fb1b4, 0x3e11977f, 0xbe4627a7, 0x3e670969, 0xbe58cc8d, 0x3dfabfd0, 0xbe09b382, 
    0x3b36f32d, 0xbe31c24a, 0x3e52eaaa, 0xbe50fad7, 0x3dc9486a, 0x3dd04bc5, 0x3db1b9cc, 0x3d04d451, 
    0xbd4f2d19, 0xbd87e6f6, 0x3dd85866, 0x3e4185de, 0xbe0341fd, 0xbe8af78f, 0xbccb9b68, 0x3d0e82cc, 
    0x3e1250de, 0xbe6bbff9, 0x3d837a77, 0x3e6f250e, 0xbd78a170, 0xbe5e63ce, 0x3e1261f5, 0xbd441e39, 
    0x3cbf716c, 0xbe068448, 0x39ac66ef, 0x3df05f89, 0x3e2a91ec, 0xbe12b01d, 0x3d707c80, 0x3e066527, 
    0x3d964a5f, 0x3d09ec09, 0xbe67a1b6, 0x3e76c414, 0xbdf1d8ec, 0xbe5b32a3, 0x3e003d35, 0x3a89ea74, 
    0xbe7beafc, 0x3dbdd6db, 0xbe17787b, 0x3c831e1f, 0xbe043aea, 0xbe6c8aa7, 0xbd19fafb, 0xbda9a854, 
    0xbde4302d, 0x3e34562e, 0xbe25dde4, 0x3db20bdd, 0x3e5e6f71, 0x3e80f237, 0x3e24e13a, 0x3e2dca5c, 
    0xbdd02176, 0xbd89443d, 0x3e444bd6, 0xbdf3305e, 0xbd551748, 0x3dec2e7d, 0xbe8ccea6, 0xbe2a608f, 
    0xbc05d3b6, 0xbe152ba5, 0xbdb65ee8, 0x3e723b0d, 0x3d706523, 0xbe0b2ae4, 0x3d9aa41f, 0x3da9874a, 
    0xbaf1d029, 0xbddd5a26, 0x3d2d9154, 0xbdfbb4d6, 0x3e488464, 0xbd8a1826, 0x3e8073a2, 0x3cf18960, 
    0xbdf67c3f, 0x3e210996, 0xbce3015e, 0x3e780e21, 0xbd2fb7c4, 0xbac15c36, 0xbe3be7a8, 0x3d4e27d4, 
    0x3e4d2d94, 0x3df24519, 0xbe159d5b, 0x3d46f30e, 0x3d660d6e, 0x3de7525a, 0x3d6a5d56, 0xbc52163a, 
    0xbe69bb7c, 0xbe02867a, 0x3ca58596, 0x3dd314ff, 0xbbe2b074, 0xbe41254d, 0x3e3ce022, 0x3e6de213, 
    0xbd4105bc, 0x3e4a82c7, 0xbdb0ca25, 0xbcd59a36, 0xbe574cad, 0x3c9349cc, 0xbdad2ca5, 0x3d43824f, 
    0x3dc81f70, 0x3e2c8e51, 0xbd7aa92d, 0xbe408604, 0x3e6c24c9, 0xbcc84bc4, 0xbd0849b5, 0xbd5d6db5, 
    0xbdbbe525, 0x3e8a5c8f, 0xbe19496f, 0x3e2610f5, 0xbbc5e9fc, 0xbe05b302, 0x3dc20044, 0xbe0d0822, 
    0x3e519d31, 0x3d81412d, 0x3e2de1d5, 0x3c74854c, 0xbe0c1887, 0x3d4f1be4, 0xbd3cd191, 0xbd8edd2d, 
    0x3de5bdf9, 0x3e8c4317, 0x3e74c017, 0x3e135d46, 0x3bfaa2a8, 0x3dc85ae5, 0x3d91f607, 0xbd47e821, 
    0xbded922c, 0xbe053e20, 0x3ce71b00, 0x3d1ac2c0, 0x3d07c117, 0xbe1fae28, 0x3d1512f5, 0x3e077b1c, 
    0xbde9b328, 0x3c1c5b73, 0x3bb8b9d6, 0xbc3508a4, 0xbd69c7f6, 0x3e50fb47, 0x3d930f3c, 0x3e1edc3b, 
    0xbd927e92, 0x3dbeff9f, 0x3cb9b65e, 0xbca95afa, 0xbd9a98d7, 0x3be53d77, 0xbe48ae89, 0x3e3e9e43, 
    0x3db5d279, 0xbd8eb2e8, 0xbe293bb0, 0xbd5b1b82, 0x3e7fa53f, 0x3d846111, 0x3e8f6741, 0x3e266d38, 
    0xbdf5edf3, 0x3d1fbe40, 0xbe5d282a, 0x3e44a43e, 0x3e8e5c71, 0x3e36c5c0, 0x3e28c42d, 0x3df5e0f4, 
    0xbe0f0d39, 0x3e5d815b, 0xbe4b8b14, 0xbdc6d599, 0xbd13cace, 0x3e11c1c2, 0x3cf1ced3, 0xbced844e, 
    0x3df8c24e, 0x3de828d8, 0x3e827cd4, 0xbe0b144c, 0x3e4db23e, 0x3d3f7840, 0xbd3e1bfa, 0x3e70867c, 
    0xbe491a58, 0x3e41a40e, 0x3d7d49dc, 0xbd4508e4, 0xbe37e111, 0xbde47b53, 0x3e30d37e, 0x3ba9c124, 
    0x3e00c1b2, 0xbe871daf, 0x3db1122d, 0xbe39cee5, 0x3dbd9d13, 0xbd20175d, 0x3deeae8c, 0xbd3b595b, 
    0xbe81bb87, 0x3d8ba9af, 0xbe8d9dba, 0x3d2b3d3a, 0xbd930e35, 0xbd7ef28e, 0xbe1371e6, 0xbd05eee0, 
    0xbe1cd378, 0xbe463de5, 0x3dae698b, 0x3d0e37c7, 0x3c4bad15, 0x3cdd9bb7, 0x3e3cf632, 0x3e4dd1b2, 
    0xbe061a11, 0x3e40f466, 0x3e4214d5, 0x3da61e14, 0x3d724e13, 0xbe6038e2, 0xbd33082d, 0x3e8a0bfe, 
    0x3ab7d636, 0xbe446507, 0x3d547d00, 0x3e015690, 0x3deaaed4, 0x3e5e582e, 0xbd967ac2, 0x3dcfcf31, 
    0xbd920d2a, 0x3e8295d2, 0xbe377411, 0x3b99ecd2, 0x3dfb938a, 0x3e42c470, 0x3e729cfc, 0x3e73bd4e, 
    0xbd742acb, 0x3e2c328c, 0xbd8ab12d, 0xbe437463, 0xbd2a889e, 0xbe5b1cb0, 0x3e6760bc, 0x3dbd1a81, 
    0x3e7ae21a, 0xbe197c5f, 0xbe7cecc2, 0x3d6266e5, 0xbe7607b5, 0x3e8bed71, 0x3d5cbb8a, 0x3c65e159, 
    0x3de333c5, 0x3d4ff58f, 0x3b30402b, 0x3c9920ac, 0xbe10e750, 0xbdd47df4, 0x3e709314, 0x3e626375, 
    0x3e287b09, 0xbe179504, 0x3d52809d, 0x3e2c6401, 0x3e615e59, 0xbe4c5637, 0x3e4dd0ff, 0x3da7c53f, 
    0x3e0945a2, 0xbd67c12e, 0xbe86da5f, 0x3e01f84f, 0x3e304add, 0xbe7be10e, 0x3e6e490a, 0x3e1dbce2, 
    0x3e3ae0b1, 0xbe449cdf, 0xbe263d57, 0xbe945e89, 0xbe0e03f1, 0x3e5d4b5a, 0xbe2748db, 0x3e14b616, 
    0x3d597d44, 0xbe04dda1, 0x3d5449bd, 0xbc8620d4, 0xbe80eed0, 0xbe251d5a, 0x3d846c18, 0x3dacaa06, 
    0xbe2aa960, 0xbd4f0acf, 0xbd1eff2c, 0xbe8a150c, 0x3e77ad30, 0xbe41295f, 0x3d7f9bec, 0x3c991a45, 
    0xbdc35a43, 0xbd366a1b, 0x3ceec2f8, 0xbdfa44ba, 0x3db660bf, 0x3e1a42ef, 0xbe75aced, 0x3e1fcf45, 
    0x3db48d1c, 0xbe459e95, 0x3d926702, 0xbe2652b4, 0xbe0f872c, 0x3d8b9139, 0x3d26be81, 0x3db88374, 
    0xbe21ae67, 0x3c3b3280, 0xbe323aa6, 0x3d8ae61d, 0xbd0f5f96, 0x3e3c238e, 0xbe2f7030, 0x3e9024e2, 
    0xbdaa00c1, 0x3e910bf7, 0x3e2436c0, 0xbe5323a8, 0xbe6e49a1, 0xbcabb3a6, 0x3e665b57, 0x3d83d9b4, 
    0xbd2bb516, 0xbdd52aa1, 0xbca4a5eb, 0xbcafd461, 0x3e579aac, 0x3e1a2874, 0x3d78795f, 0x3e68dcae, 
    0xbc921238, 0x3af26c64, 0xbd3ecdcf, 0xbe872a09, 0x3e32bd8c, 0x3e74cab0, 0x3de03752, 0xbc483b7e, 
    0x3de141c5, 0x3d95659a, 0xbe3e47df, 0xbc801949, 0xbe08933c, 0xbd9d04f7, 0xbb02b3e1, 0x3d0a8451, 
    0xbde832cf, 0xbdaabe32, 0xbd3e93bb, 0xbe46983e, 0xbdac6ae3, 0x3e51dacc, 0x3de26db1, 0xbca25f83, 
    0x3e59e7ca, 0x3e25b1f3, 0xbd81f4db, 0x3d959483, 0x3e6816a8, 0xbdc1430c, 0x3dc0054f, 0x3e381504, 
    0xffffe87a, 0x00000004, 0x00000010, 0x00000001, 0x0000000c, 0x00000001, 0x00000010, 0xffffe896, 
    0x00000004, 0x0000000c, 0x00000001, 0x00000006, 0x00000010, 0xffffe8ae, 0x00000004, 0x00000034, 
    0x3d140f57, 0x3d255e69, 0x3d4199b3, 0xbd878882, 0x3a50cbb5, 0x3d2d1048, 0x3ca4cfc0, 0x3d489e19, 
    0x3cc38cc6, 0x3c330f80, 0xbd589890, 0xbd359fe4, 0x3cdb62a1, 0xffffe8ee, 0x00000004, 0x000009c0, 
    0xbd3ade00, 0x3e625f47, 0x3d8341e0, 0xbe409516, 0xbdedb551, 0xbd53553c, 0xbe6470b7, 0x3dc4ad61, 
    0x3dc2f966, 0x3e32389e, 0x3e81edcb, 0x3dcd5603, 0xbe021939, 0xbdb69590, 0x3e2493ac, 0xbc53da12, 
    0x3e24aea9, 0xbd7b3da0, 0x3dc96808, 0x3e23fdab, 0xbe12dc79, 0x3cf922d3, 0xbcc7b408, 0xbdb0b1c0, 
    0x3d77c9d7, 0x3e42dda7, 0x3c7788d2, 0x3e97f8d2, 0x3e5bb068, 0xbdb9d4a1, 0x3d5c8b91, 0xbe3e68ff, 
    0x3e817d3b, 0x3d9c3568, 0xbe1472a9, 0xbd7a643a, 0xbe5bbf52, 0x3d32a456, 0xbe1f7d65, 0x3e102854, 
    0xbec9fa6d, 0xbe281875, 0xbd27b2ad, 0x3ed88fc6, 0xbec2676e, 0x3eb8077c, 0xbe9fb6cd, 0xbe8fce9b, 
    0x3e7ad5f4, 0xbe2a864d, 0xbe7dbb7a, 0x3ea85812, 0x3e8f83af, 0xbd942faa, 0x3e0dca63, 0x3e1d3c16, 
    0xbdf5a2e4, 0xbec73386, 0xbe23de67, 0x3d421dd9, 0x3c5939c2, 0x3ed583b5, 0x3eab45af, 0x3d984223, 
    0x3e5d76b1, 0x3d50f165, 0x3dd6bb42, 0x3ef48786, 0xbe88bd8c, 0x3e2fb05b, 0x3e9f5a0c, 0x3e7f27f7, 
    0x3ea36453, 0x3e66c736, 0x3b03aad5, 0xbe7ef54c, 0xbe1ad33b, 0x3eb9ee78, 0x3b967606, 0x3d7c172e, 
    0xbd9c27b0, 0x3da23617, 0x3b3fb04b, 0xbb3b0c42, 0x3cf993d4, 0xbb9d295a, 0x3d5e0752, 0x3dc70e3b, 
    0x3de84b5c, 0xbd771877, 0x3dfb5dc2, 0x3df5bb98, 0x3db7b116, 0x3e17e07d, 0x3d693b93, 0x3e0ed399, 
    0x3d09d93e, 0x3d39b2eb, 0xbdb4f9f3, 0x3d50387a, 0x3ce90fbc, 0x3e1acdc0, 0xbdaeb875, 0x3d3cc9d9, 
    0xbd341962, 0xbc81fb82, 0x3db6d3f5, 0x3dfe11ba, 0xbdf8d528, 0xbc949b15, 0x3e3c1a02, 0xbd271784, 
    0xbdd33f8a, 0x3dd67f5c, 0xbd91389c, 0x3c16a389, 0x3dae27a9, 0xbdd6fabe, 0x3c81f29a, 0xbde6f52b, 
    0xbd9ceeb9, 0x3e1980c2, 0x3e4e0aab, 0x3dd1e030, 0x3a414826, 0xbeafb389, 0xbe87bba1, 0xbe83f6c6, 
    0x3e6c31bb, 0x3e2a7f11, 0x3da31bb4, 0x3d92d49a, 0xbe4a84ca, 0xbe187d3e, 0x3dd0046c, 0xbe32ac32, 
    0xbe42d388, 0x3defd358, 0x3dc79d98, 0x3c8ec6a8, 0xbd1c2063, 0x3e03ecbb, 0xbe52a8db, 0xbe0f72c2, 
    0x3e183dde, 0x3e417b75, 0xbe6138b5, 0xbc3e9c97, 0x3e29d357, 0xbc504d5f, 0xbc2315ce, 0x3d6b0a36, 
    0xbe4c5b1b, 0xbe5e1222, 0xbe28f2a5, 0x3eaed139, 0xbeaccf8e, 0xbddb659f, 0xbead5406, 0xbbb43034, 
    0x3ebaa231, 0x3e2833e6, 0x3ddccbdc, 0xbec0a82a, 0xbd6c6d84, 0xbe964941, 0x3ea14522, 0xbd6adec3, 
    0x3de64cf8, 0x3eb39d6d, 0xbe44cafd, 0xbe9b6f0d, 0x3e8d30d8, 0xbea067de, 0xbe2efa4a, 0xbe80de7d, 
    0x3de59e3d, 0x3e25b87f, 0x3dc6ce9f, 0xbdf4cf3e, 0xbe84dabb, 0x3df63c8a, 0xbe92d58d, 0x3ea9ddbd, 
    0x3e8c36d5, 0x3e0c88a4, 0x3e5eaf9b, 0xbebea0d4, 0xbe512a3f, 0x3e1d5510, 0xbe2b4153, 0xbead4065, 
    0x3dab73a1, 0x3ea01cce, 0xbd88fa37, 0xbe77b5e4, 0x3eb6e07b, 0x3ed8e3d5, 0xbe391500, 0x3e50d0c4, 
    0x3e97ff14, 0x3e13e5ec, 0x3cbf1e31, 0x3ea6058c, 0x3e9461d6, 0xbe1dc21f, 0xbea1877c, 0x3de37fbb, 
    0xbbb44dcb, 0x3dc6beaf, 0x3e4896ab, 0xbe67b730, 0xbe8670c5, 0x3e64b05b, 0xbe8fd791, 0x3e306220, 
    0xb99b678a, 0xbd3f632d, 0xbdac14d4, 0xbe0c7d9b, 0x3d30c911, 0x3eb824a4, 0xbc8b5563, 0x3e80f8f9, 
    0xbd8ccd6b, 0x3dae5b1a, 0xbc845f39, 0x3e1bb321, 0xbe60015a, 0x3cecbe0a, 0x3e6b06e2, 0xbd7f08a4, 
    0x3c245eb3, 0x3eb02b1b, 0xbe019b45, 0xbe9125b0, 0xbdbd4abc, 0x3e556b27, 0x3c7266c0, 0x3daa084c, 
    0x3dfaab2d, 0xbd8d676c, 0xbd2c967f, 0x3c2114fa, 0x3d9d7217, 0xbdb84589, 0x3e3f7b75, 0x3cff47ca, 
    0xbe583179, 0x3e9b826a, 0x3e1bf398, 0xbe8b64e0, 0x3e77e98a, 0xbe549111, 0xbe5bc352, 0xbda01d18, 
    0xbda48282, 0xbe133632, 0xbe210e78, 0xbe6f35bf, 0x3e25158d, 0x3dd0c0b3, 0xbd918a12, 0x3de319a7, 
    0x3e053961, 0x3e2033b6, 0xbb8cda3e, 0xbec297c9, 0x3e8cac30, 0xbe3387c0, 0xbd533da2, 0x3e1d54b8, 
    0xbce08abb, 0x3e96b7fd, 0xbda10e91, 0xbe06b36d, 0xbd65c40c, 0x3e8cf85b, 0xbdf83409, 0xbe811296, 
    0xbd84092b, 0xbc29a1fd, 0xbda34c78, 0x3e3568cc, 0x3e6b2ebd, 0x3d9f2f37, 0x3e6a334c, 0xbe18853d, 
    0x3e5716bb, 0xbc7cedc1, 0x3ce86c23, 0x3cc58a88, 0x3debd1d7, 0x3d8278dc, 0x3e67ad6b, 0xbd9b56e8, 
    0x3e88b72d, 0x3d9c4efc, 0x3cec4877, 0x3e283e6a, 0xbd9185d6, 0x3d46a534, 0x3e23883d, 0x3de9d780, 
    0xbd6d9c05, 0xbe10db48, 0x3e0605ea, 0x3d7d3af5, 0xbcfab6ed, 0xbd850e15, 0xbe834d70, 0xbe17fd5a, 
    0xbe44c062, 0xbe2d138d, 0xbdfa3f27, 0x3d9bb8b6, 0xbe23cb45, 0x3e86f75d, 0x3de24225, 0x3db3567e, 
    0x3bb857c5, 0xbe011323, 0xbe219d1d, 0x3ed48714, 0x3e119f3f, 0xbd0ebf9c, 0x3eb0c8d3, 0x3d93b400, 
    0xbe4dfaf9, 0x3d62a805, 0xbe70381b, 0xbd5f4feb, 0x3e2acbf5, 0x3eed5428, 0xbe363d39, 0x3e8f91a2, 
    0x3d1a7134, 0xbe6772cd, 0xbc06ca9c, 0xbdb6bb48, 0xbd17d79a, 0x3e0ce2bf, 0xbe343916, 0x3e3661b4, 
    0xbe6914f7, 0xbe8fc398, 0x3e185587, 0x3e7d2ce1, 0xbe38e4ca, 0xbe2a6590, 0xbe187dda, 0x3eb44fbc, 
    0x3defc398, 0xbe97d6c4, 0x3e2f48b5, 0x3ea4b5d5, 0xbda5cd29, 0xbe59c780, 0x3e6c567c, 0xbe8ecae3, 
    0xbe9a2d99, 0xbd850df9, 0x3e4204c8, 0xbe5a6ffc, 0xbddea710, 0x3d903c3d, 0xbc9f6fd7, 0x3e021c62, 
    0xbdd7d01d, 0xbd85899c, 0x3da174c6, 0xbdca2e16, 0x3dc661c0, 0xbe903787, 0xbe919f27, 0xbe63f013, 
    0x3ea0c0b7, 0xbe7477cc, 0x3ea32546, 0x3e58444c, 0xbcf426ca, 0xbedbed9e, 0x3e2f9d8c, 0xbca89581, 
    0x3d959fdb, 0x3e3220af, 0xbe5d8422, 0xbe77fb96, 0xbe0a25f7, 0x3ea4b315, 0x3e6aeb8d, 0xbdb29482, 
    0x3c434991, 0xbe551ce5, 0xbe20e4b8, 0xbe060f9d, 0xbe54c02b, 0xbbaa8918, 0x3d8f3c08, 0xbe336db8, 
    0xbcf04c88, 0xbe646cf4, 0x3e6d2705, 0x3dad33b8, 0xbc57d204, 0x3e14ddbc, 0xbcf519a2, 0xbe306746, 
    0x3e6aaf20, 0x3d6a0d03, 0xbd94d12f, 0xbce205ee, 0x3e1e02a8, 0xbccb7e34, 0xbe0ee197, 0xbe2f1a0d, 
    0x3e1553c2, 0x3d6970bd, 0x3e3d5991, 0xbcae6a5d, 0x3d120e35, 0x3e217bf8, 0xbd5d3d31, 0xbdb9cf2b, 
    0xbddc3118, 0x3dee458d, 0x3d892200, 0xbe70b81f, 0x3e4f4d67, 0xbe6e1009, 0xbe7e648a, 0x3e0a6754, 
    0x3ea12817, 0x3e4d926e, 0x3d979029, 0xbe8b204e, 0xbd2cef1e, 0xbe44a0fe, 0xbe0e5129, 0xbe17f2b4, 
    0x3d4c15be, 0xbc05dfcc, 0x3e556251, 0xbd9a152d, 0xbe25eca7, 0x3e45df4a, 0xbcda2163, 0xbdf0d092, 
    0x3e5f669c, 0xbdce45ae, 0x3e2bd187, 0xbd766a57, 0x3df057f3, 0xbe8f68a5, 0x3e04e61d, 0xbe553131, 
    0xbe3b672a, 0x3e1b92fc, 0x3ea8ab22, 0x3e2c6f19, 0x3e6b7200, 0xbe3a473a, 0x3d5e9294, 0x3e460cd9, 
    0xbe704fc1, 0xbe0df2d3, 0x3cf12f48, 0xbe9e55d9, 0x3e85051b, 0x3dcb7a3b, 0x3cd48a6d, 0x3e85ac70, 
    0x3d60fb0c, 0x3e9713f4, 0xbead21c4, 0xbe7ecec6, 0x3e3023b1, 0xbdd8e709, 0xbeb80f3d, 0x3edc2304, 
    0xbe69cc73, 0xbe480e2e, 0xbeda37ba, 0x3e9186a0, 0xbe071527, 0x3e3d2c9c, 0x3eab3431, 0xbda55593, 
    0xbd2e96fd, 0x3c1e0d01, 0xbdc0ce7c, 0x3e988656, 0xbe83748f, 0x3e76a707, 0x3ea13535, 0xbd7029b2, 
    0xbdcbe2d1, 0xbc2cb071, 0xbe3a13c7, 0x3eb03d82, 0xbec3a5a0, 0xbd4f270d, 0x3e8cb9db, 0xbe5043a2, 
    0x3eab9f63, 0xbe3ed8cf, 0xbedfb9a8, 0x3e26ad01, 0xbe4dbd74, 0x3e3a82f7, 0xbd9fb99b, 0xbe986c51, 
    0xbdc1c068, 0x3e30acbe, 0xbde0caff, 0x3e0f01e0, 0xbe11c291, 0x3e4030d4, 0x3e369cf4, 0x3e30d8d9, 
    0xbe8cf30f, 0xbe432609, 0xbe0e00ad, 0x3e1097a3, 0xbdff17ec, 0xbe4c73b6, 0xbe3cd45a, 0xbdf8beb0, 
    0xbe622129, 0xbd89a313, 0xbd70fbf1, 0x3d855a27, 0x3e55b0a4, 0xbe07206e, 0xbe194310, 0x3dc5485b, 
    0x3d4cff6b, 0x3d50379f, 0xbe30bc5a, 0x3c832833, 0xbe97d9ef, 0x3df3bb72, 0x3e3e6e35, 0x3e29f2bf, 
    0xbdda16a5, 0xbc853b19, 0xbe2d3daf, 0xbe737dab, 0xbd42641b, 0xbea941e9, 0x3e755349, 0x3d38d4ef, 
    0xbd3bc98c, 0x3dd89d4d, 0x3d9ee685, 0xbe9fd681, 0xbd9ff086, 0xbeaf3b9f, 0xbe272dbd, 0x3e8cedef, 
    0xbd4fcc06, 0x3d025ea1, 0xbdeb7901, 0x3e8cb099, 0xbd16e77d, 0x3e1eedf1, 0xbea507b6, 0x3d68c59e, 
    0x3e102e3a, 0xbe73a6b6, 0x3ead6b48, 0x3ea0f4ab, 0xbe86cc35, 0xbdeb4f25, 0xbe6c59fd, 0x3eb75363, 
    0x3ebdbd23, 0x3ede1685, 0x3ead59d6, 0xbea36a14, 0xbe528e51, 0x3d2708af, 0xbdb29735, 0xbea52161, 
    0xbebccb0c, 0xbe77a146, 0xbe62714a, 0xba8faa17, 0xbe45aac1, 0xbe84c857, 0xbe382818, 0xbdd91ec8, 
    0xbdef8472, 0xbd47d0a9, 0xbe02ff0b, 0xbe45ffb7, 0x3cebedfd, 0xbeb323b5, 0x3e14cf58, 0x3e2108c4, 
    0x3d13cd0a, 0x3eab44a5, 0xbe08da62, 0xbe9bc9c2, 0xbe415c36, 0xbebb6c24, 0xbea809b6, 0x3e584f36, 
    0x3d2c6f54, 0xbd9bdf5e, 0x3ca95eac, 0xbe4fa06f, 0x3e2ddef2, 0xbea7758a, 0x3e06d1b1, 0x3ea411fb, 
    0x3e7c9c33, 0xbd522b28, 0xbdf6d2bc, 0xbe02120d, 0x3e97fa4e, 0x3dec4d4c, 0xbe22167f, 0x3e9fdb72, 
    0xfffff2ba, 0x00000004, 0x00000c00, 0x3e7f1a3d, 0x3f2333f6, 0xbf323919, 0xbf0c8043, 0xbed1ecff, 
    0xbf0d69d9, 0x3d8bddf7, 0x3f37cc6d, 0x3f289b69, 0x3e80a276, 0xbf051bcf, 0xbf216fc0, 0xbe1291f2, 
    0x3cf5dcf1, 0x3f311ca7, 0xbf385c1d, 0x3e2bfe44, 0xbf0d209a, 0xbe93bbfe, 0x3e48183c, 0xbea6cfbf, 
    0x3d07f5f3, 0x3e0c2f09, 0x3e58544d, 0x3f46badf, 0x3e06ac03, 0xbd76e537, 0xbe5bd5de, 0xbee96add, 
    0xbf157193, 0x3f62fa16, 0x3f1aabce, 0x3f0b4ff6, 0xbee5087e, 0xbefd274c, 0xbe901970, 0xbdeb0e15, 
    0x3caba81d, 0xbf1aa026, 0xbd24f6dd, 0x3edcfbe1, 0xbeb7db4e, 0x3c531a4e, 0xbf251d2c, 0xbdbebc49, 
    0x3e3622b0, 0x3eb3a71d, 0xbe414095, 0xbdbec555, 0xbed08345, 0x3dc30967, 0xbe5d887a, 0x3f256e5e, 
    0x3f5f09ad, 0xbe964c4a, 0xbe14280a, 0xbe4d6633, 0xbedf9dce, 0xbd995945, 0x3f3c50b2, 0x3ed03512, 
    0xbf08db21, 0xbe95c1ef, 0xbf0a79c6, 0x3de460fa, 0xbda406d5, 0xbeb2c445, 0x3f807bc4, 0x3e1ff638, 
    0xbe9df600, 0xbde4c111, 0x3f1f898f, 0xbe2b8c6a, 0xbe70c2a0, 0xbea85b33, 0x3f12facd, 0x3e212be6, 
    0x3dbbf931, 0xbf15bf84, 0x3b6b0f8b, 0x3ea01a97, 0xbef3051f, 0x3ec41841, 0x3f52cce3, 0x3f3f7632, 
    0xbd2b44ae, 0x3e4c3790, 0xbdab2b8f, 0xbea78746, 0xbcf7eeb3, 0x3f276aa3, 0x3e828fb3, 0xbeda1d47, 
    0x3ee47dcb, 0x3e8bf9f7, 0xbe70f6d1, 0x3e99e0bd, 0xbd684b81, 0xbe0776f7, 0x3cfeb426, 0x3dbc91a3, 
    0x3e4158e5, 0x3ed5b005, 0x3dd4ff74, 0x3d9770a3, 0x3dbbbd28, 0x3e1226fa, 0xbeeafa9f, 0xbe99dd38, 
    0x3e54cc0a, 0x3ee70095, 0xbbf4ffe1, 0x3d16ffa6, 0xbebd7b72, 0x3e85a54c, 0xbe19c39a, 0xbec33c76, 
    0x3e9e6329, 0xbe0ae276, 0x3e23a125, 0x3d684db2, 0x3e284880, 0x3ea4c1ea, 0xbda8bf1d, 0xbd1d2281, 
    0xbef9903a, 0xbdd0b16b, 0x3ea03e1e, 0xbe8b3756, 0xbda9125b, 0x3d9b0e0d, 0x3e9dfafb, 0xbf26c3df, 
    0x3e502b0a, 0x3ea74cc4, 0x3f151a66, 0xbea6fb16, 0xbe8eb3f7, 0xbe5a7e16, 0xbe1fc2bb, 0x3de72b54, 
    0x3c10ed41, 0x3e584393, 0xbf02d879, 0xbe5cc996, 0xbee3439d, 0xbe8561a8, 0x3e33f540, 0xbede9977, 
    0x3e353122, 0xbe0950f4, 0xbde673a8, 0x3dea0ee2, 0x3e97a77b, 0xbee8f3f7, 0xbf0a4a3c, 0xbe913300, 
    0x3da098ee, 0xbd3a9d2d, 0xbecef86c, 0xbd839b7b, 0xbef56044, 0xbe869614, 0xbebc91f8, 0x3ea34214, 
    0xbd8065f0, 0xbce70e60, 0xbd465407, 0x3e0f09ad, 0x3e10fe91, 0x3e078ca5, 0xbeee31fe, 0xbe278235, 
    0xbec37e9d, 0xbe962fc4, 0x3de7f59e, 0xbdee6de1, 0xbec0232a, 0x3e80e365, 0x3ea608d6, 0x3d5590aa, 
    0x3e4dbd07, 0x3c59f097, 0xbe35942f, 0x3da2068e, 0x3eb8b530, 0x3c4dadf0, 0xbea97322, 0xbe8d9705, 
    0xbeb372db, 0x3c50d701, 0xbd7a02f0, 0xbf05a9e4, 0x3f1d0c88, 0xbe2a81db, 0xbf314b7a, 0xbef75f3a, 
    0x3f11c541, 0xbdc74ea9, 0x3f075b53, 0xbc023744, 0xbee87c0c, 0xbf16af2e, 0xbd915944, 0xbf0b2e7e, 
    0x3f1504f1, 0x3f0cca40, 0xbe32e242, 0xbf1c0d15, 0xbf316f87, 0x3e0d33fb, 0xbefdefe5, 0x3ef3b570, 
    0x3f3326e7, 0x3e2fa3aa, 0xbeb2603a, 0x3ec64154, 0x3def84c7, 0xbf21d984, 0x3f46f726, 0x3f29fd2e, 
    0xbe2a9e3d, 0xbf130acc, 0x3f087664, 0x3e3c84f0, 0x3f3bf38c, 0x3e927a2d, 0x3f2f197e, 0xbf47b5ba, 
    0xbf133057, 0xbed7a08e, 0xbe829442, 0x3f0a27bd, 0xbf3167fb, 0xbe121828, 0xbf00822e, 0xbe0eb648, 
    0x3ddda070, 0x3f1c17fc, 0x3eddbf05, 0x3e57e19f, 0xbee901f7, 0x3eef60ce, 0x3e2b1346, 0x3ebbcf74, 
    0xbe05f70c, 0xbef29d4e, 0x3f09de00, 0xbd01a6a6, 0xbeacf774, 0x3e8a6121, 0x3e21f10a, 0xbe12f1df, 
    0xbe89d480, 0xbe9fde8c, 0xbee083a9, 0xbc8a5493, 0xbed092af, 0x3ebc0590, 0x3e8df8cc, 0x3f0eb29c, 
    0xbe8a1767, 0x3e6023cb, 0x3dbf55c4, 0xbe36c223, 0xbe7e0852, 0x3e023a68, 0xbedf5f45, 0x3ddbe5df, 
    0xbec7b5df, 0x3ead4036, 0xbe538225, 0xbe51e99a, 0x3e65909b, 0xbf06e216, 0xbecf8d1c, 0x3eba3b98, 
    0xbcefc137, 0x3ee2f5b0, 0xbe952c3a, 0xbf214246, 0x3d7d1dcd, 0xbe57e658, 0x3e2e98c5, 0x3e58e0ed, 
    0xbd19c123, 0xbd8e941b, 0x3e9dcec6, 0xbef72ab3, 0x3f033f92, 0x3e070cbc, 0x3e85b696, 0xbe42d5e1, 
    0xbe90956f, 0x3df88474, 0xbeae9729, 0x3e88fde4, 0x3f3be615, 0xbf08308f, 0x3e1bd4df, 0xbb8688f9, 
    0x3b5975ac, 0xb9b84132, 0x3f07dc75, 0xbeec77ab, 0xbf0630ee, 0x3ea9a4ce, 0xbf112d34, 0x3e9c89cd, 
    0x3ea681af, 0xbeb1c333, 0xbdfc4a33, 0x3eae8d88, 0x3f2169bb, 0xbe9ff69a, 0xbe1babdf, 0x3f210347, 
    0x3e8d2d52, 0xbf31280b, 0x3ea057b9, 0xbf07d250, 0x3e37e652, 0xbbe1d713, 0xbe9a3b29, 0x3de28b44, 
    0x3e88cdf7, 0x3da8dff7, 0x3ee81802, 0xbf293a70, 0xbf0be352, 0x3f12d674, 0xbef8b7db, 0x3ea56d7c, 
    0x3de52c6a, 0x3f014d14, 0x3e44b253, 0x3f300423, 0xbb0ab94e, 0xbf18b1b0, 0x3e93516e, 0xbe1fc11e, 
    0x3df1c730, 0xbd99569d, 0xbe9975eb, 0x3eef7225, 0x3f24edd4, 0xbedf4517, 0x3f012546, 0x3c7bddc3, 
    0xbf065b1e, 0x3efa3eb9, 0x3d81db1a, 0x3eb49b7e, 0xbe500867, 0xbf15586c, 0xbf056029, 0x3e9d9ead, 
    0xbf03d998, 0xbe87beee, 0x3e47b51f, 0x3ec1103c, 0x3cb315d0, 0xbe9519ff, 0xbf1d48a0, 0xbe3a9908, 
    0x3e4fbfa8, 0x3ea63df9, 0xbe025e78, 0x3eae336e, 0xbefe2250, 0x3eda95a6, 0xbeb55f98, 0x3e666f7c, 
    0xbf023e99, 0xbebed973, 0x3e8f1520, 0x3f18e3d3, 0x3dd036b2, 0xbbd009ba, 0x3ec798cd, 0xbd9d6b53, 
    0xbe6b9304, 0xbdbcb287, 0xbf0156c0, 0xbf00dc00, 0xbe1d6a1b, 0xbf221489, 0xbf65e02e, 0x3ef198c9, 
    0xbe8bdc13, 0xbdf827d4, 0x3e67a00f, 0x3dd8c3fe, 0xbdf1acc1, 0x3f7b285e, 0x3e8c256d, 0xbdf2aabd, 
    0xbf3a4807, 0x3f05dc07, 0x3ee016bf, 0x3ec77092, 0xbdc0bf95, 0x3f77a028, 0xbf0c047e, 0x3f1bb1bc, 
    0xbf031090, 0xbef2f928, 0xbee6f1de, 0x3da22014, 0xbe0a7410, 0x3f7768a0, 0xbb655eed, 0xbd18ec89, 
    0xbe457875, 0xbf068367, 0x3f0a59e0, 0x3eff71ae, 0xbf12953f, 0x3f35aba6, 0x3ed58ad1, 0x3df5a19d, 
    0x3e93939d, 0xbe738316, 0x3f3c77c3, 0xbf18aab3, 0x3ebfb2bc, 0xbe240548, 0x3c54a71d, 0x3d04be18, 
    0x3e5a53d0, 0x3f18573b, 0x3e743ef2, 0xbec3b3ed, 0xbf0bba7c, 0xbe8357ea, 0xbd1afcd6, 0xbf15c4f8, 
    0xbeb25183, 0xbd7e5d9a, 0xbee12ca9, 0xbe7cb341, 0xbf03c79a, 0x3efb6a41, 0xbefd9880, 0x3d772db0, 
    0xbf166797, 0x3eceacef, 0x3ee35d7b, 0xbf35cf2b, 0xbdd4d7e8, 0xbe8172d1, 0xbf11c7bb, 0xbe881806, 
    0xbf25595f, 0xbe6018ff, 0x3e8fa4b2, 0xbef76acf, 0x3f1d60f5, 0xbe7d9b37, 0x3e8e7277, 0x3e9de36d, 
    0x3eaa0dea, 0xbeca4c5f, 0x3e146fa1, 0xbe6c5a7d, 0x3ec87534, 0x3f4dd639, 0xbef56d63, 0x3e73e304, 
    0xbe8562ba, 0xbea6c88d, 0x3f29e910, 0x3e6c138a, 0xbe5420eb, 0xbe00471f, 0x3ef1c4c5, 0x3e89adb7, 
    0xbef7a126, 0x3f1e9c6c, 0x3d14a76c, 0xbf0016ac, 0x3e51c49c, 0x3f137cc1, 0x3f3d54cd, 0x3f4bebc1, 
    0xbf05cca0, 0xbcdf372a, 0xbea4d9c5, 0x3eb9d7ab, 0x3ea29cc4, 0xbee888ad, 0xbf6ecdf1, 0xbf1f46ad, 
    0x3ec22122, 0xbef49ba5, 0x3f05e1f9, 0x3f257641, 0x3dddced7, 0xbf3d6000, 0x3f75eaba, 0x3c92553a, 
    0x3f8c7789, 0xbecda985, 0x3eaa5613, 0x3f31a759, 0xbf3a9b70, 0x3a9db4e0, 0x3f287f6a, 0xbf178fda, 
    0xbe87b60b, 0xbf706f68, 0x3f4eb44f, 0x3e6edbea, 0xbe3db03b, 0xbe2cc1fb, 0xbed7bca9, 0xbe21f27e, 
    0xbf438ee6, 0x3f3b4ebe, 0xbe45d1b2, 0xbeddcfc6, 0x3e217bd5, 0x3f41f48a, 0xbecc6f84, 0x3e46035d, 
    0x3f59c41a, 0x3e926fe6, 0x3e07ab0a, 0xbf132874, 0xbf2acfa8, 0xbe93ec9f, 0xbce0fa75, 0x3e131b22, 
    0xbedef689, 0xbf154a5a, 0x3e39b777, 0xbf0dd45b, 0xbdf42a53, 0x3f2a5e0c, 0x3f18b4fc, 0x3eb7e195, 
    0xbd1c5e35, 0xbecaad46, 0xbf16f81e, 0x3e39d8ab, 0x3f29b400, 0x3e3fa3d3, 0x3e291408, 0xbeedd6e4, 
    0x3f1d8b16, 0xbf28f330, 0x3ef4a3b4, 0x3ea30157, 0xbf70ebd0, 0x3cb12fae, 0xbde0f977, 0xbeba72f3, 
    0x3ec3ec4b, 0xbf0fa93f, 0x3f02ee50, 0xbf12ddc7, 0xbf2b381a, 0x3ea27278, 0x3e8fe9aa, 0xbec10553, 
    0x3f437fdd, 0xbf034212, 0x3f2abd20, 0xbf2b4997, 0x3d0cc833, 0xbe9a1107, 0xbf04f5fb, 0xbe66be6b, 
    0xbe20b850, 0xbee55166, 0x3f3c7802, 0xbea32ee7, 0x3da8f350, 0xbe6ce05c, 0x3dde576f, 0x3edd5ef1, 
    0xbec1db7e, 0xbec0bc17, 0x3ed35b5b, 0xbee5a8ff, 0xbeb57078, 0xbe9cd484, 0x3e1b0f7d, 0x3f61c396, 
    0x3eedce5a, 0xbdc80390, 0x3da3c952, 0x3ea4bde7, 0x3ed9ed81, 0x3f23e70c, 0x3c321ed4, 0xbece9b8b, 
    0xbecbf3fb, 0x3f06b562, 0x3ea14dbf, 0xbf10bf88, 0x3ec38d4d, 0xbec8234f, 0xbee7d010, 0x3f5367db, 
    0x3f1ca5aa, 0xbeb7ec26, 0x3ef1ac6a, 0xbecbe9b0, 0x3ede7115, 0x3f0059d3, 0xbe0e03d9, 0xbf0384a1, 
    0xbea44b13, 0x3d403eae, 0x3f3e033c, 0xbe2d77b9, 0x3dac9585, 0x3ebd064a, 0xbd29f992, 0xbdace2cf, 
    0xbd35c0b8, 0xbea871be, 0xbe0453df, 0xbf7cb893, 0x3f12d836, 0xbeee7696, 0x3e6d7191, 0x3f46f021, 
    0x3f38d732, 0x3f9f66cf, 0xbdfe6ed5, 0xbe323d0b, 0x3e4c4653, 0x3ecd3207, 0xbc20da86, 0x3ed94890, 
    0x3e3a3097, 0x3e73b181, 0xbe9cca8e, 0xbf253f90, 0x3f15f622, 0x3ecaf7e2, 0x3f0507ff, 0x3d97ad0d, 
    0x3ef60199, 0xbe84a49d, 0xbf1b04d9, 0xbe1aebf1, 0xbe8bb55a, 0xbe20aaf8, 0x3e3f5411, 0xbefa6c22, 
    0xbf1b52f1, 0xbdc86268, 0xbf5f1c45, 0xbf8b7915, 0xbf7a267c, 0xbf102b19, 0x3f172229, 0x3eb9026f, 
    0xbe90a9ae, 0x3f4241c3, 0xbe94aaa2, 0x3c727457, 0x3e0c7b08, 0xbf1baec0, 0x3f30d632, 0xbc9dcb74, 
    0x3f5bb602, 0xbe2b0262, 0xbf19f89f, 0xbf0c86cf, 0xbf307a5e, 0x3f1cad23, 0x3ed25142, 0x3f745974, 
    0x3d9349ca, 0xbd5321bb, 0xbd03d10c, 0xbea4ac75, 0xbe4bfd9c, 0xbf16faad, 0x3f320d92, 0x3ca61caf, 
    0xbefd6dcd, 0xbf30c7bf, 0xbda2219f, 0x3d9410c0, 0x3e622053, 0xbeb94d10, 0xbea6e8b6, 0x3df296f4, 
    0xbf002f6a, 0x3f0749d8, 0xbe035fde, 0xbe323eff, 0xbe7134d8, 0x3ed01dd9, 0x3f2dead6, 0xbc45903e, 
    0xbd631590, 0xbd2946ee, 0xbec1c662, 0x3eec192c, 0x3f01d0a6, 0x3f364166, 0x3f40eb62, 0x3d9003f4, 
    0xbe095efd, 0xbcd325ee, 0xbf562cd6, 0x3f2af6ff, 0x3c36e4a5, 0xbef74f86, 0x3f319338, 0x3e710d9d, 
    0x3e075544, 0xbec33326, 0x3eeff195, 0x3ef16e18, 0x3e252152, 0x3f1979c4, 0x3e5a96d9, 0x3f128432, 
    0x3e7ecaad, 0xbee2a2ce, 0x3e9f7ae7, 0x3ef7daa5, 0xbd85a014, 0xbed29247, 0x3f004ff2, 0xbf0a7f4c, 
    0xbf3636a3, 0x3f28dd74, 0xbe552cd7, 0x3e97988a, 0xbf359d01, 0x3f0685b7, 0x3e7e7baf, 0xbf32766f, 
    0x3d8b3682, 0x3ee4c5d8, 0x3f0c0999, 0x3e07af7b, 0xbe3936ba, 0xbd6ffcaf, 0xbf5eaa33, 0xbf0c31b2, 
    0xbe12ed67, 0xbe32fc7a, 0xbf13c327, 0x3e916ac7, 0xbe752903, 0xbf2d433f, 0xbd3537a6, 0xbeac1bb2, 
    0x3e4d8655, 0xbeb0b49a, 0xbeae2135, 0x3dfff230, 0xbe819964, 0xbd5faf4a, 0x3e8ead56, 0xbf212f53, 
    0x3f1f0909, 0x3f1aa503, 0xbe89f935, 0xfffffec6, 0x00000004, 0x00000040, 0x3ff44768, 0xbfa7d913, 
    0x3f4801e9, 0xbcf0c956, 0xbebba77c, 0x3f8e3bf3, 0x3f83e488, 0xbe3203ee, 0x3ebbdf68, 0x4019b312, 
    0x3f7b95f7, 0xbf2d9beb, 0x3e7f6980, 0xbf5d38e7, 0xbe82ef82, 0xbd99af40, 0xffffff12, 0x00000004, 
    0x00000040, 0x3fc32098, 0xbf2057ec, 0x3e486c57, 0x400c7074, 0xbef270e5, 0x3fb3e939, 0xbf34bbe0, 
    0x3f6c364c, 0xbead0044, 0x3f4fbd3c, 0xbf8e07ea, 0x3f13d708, 0xbf803a29, 0xbf00e4f6, 0xbf3d4d29, 
    0x3fc955fe, 0xfffff1fc, 0xfffff200, 0x0000000f, 0x52494c4d, 0x6e6f4320, 0x74726576, 0x002e6465, 
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
    0x622d6c6c, 0x6e616c61, 0x2d646563, 0x616c2f31, 0x5f726579, 0x4d2f3231, 0x754d7461, 0x6f6d3b6c, 
    0x2f6c6564, 0x766e6f63, 0x732d6431, 0x6c6c616d, 0x6c61622d, 0x65636e61, 0x2f312d64, 0x6579616c, 
    0x32315f72, 0x6169422f, 0x64644173, 0x00000000, 0x00000002, 0x00000001, 0x00000005, 0xfffff682, 
    0x01000000, 0x00000010, 0x00000010, 0x00000018, 0x00000038, 0xfffff66c, 0x0000002b, 0x65646f6d, 
    0x6f632f6c, 0x6431766e, 0x616d732d, 0x622d6c6c, 0x6e616c61, 0x2d646563, 0x616c2f31, 0x5f726579, 
    0x4d2f3131, 0x006e6165, 0x00000002, 0x00000001, 0x00000010, 0xfffff6da, 0x01000000, 0x00000010, 
    0x00000010, 0x00000017, 0x0000003c, 0xfffff6c4, 0x0000002d, 0x65646f6d, 0x6f632f6c, 0x6431766e, 
    0x616d732d, 0x622d6c6c, 0x6e616c61, 0x2d646563, 0x616c2f31, 0x5f726579, 0x71532f39, 0x7a656575, 
    0x00000065, 0x00000003, 0x00000001, 0x00000006, 0x00000010, 0xfffff73a, 0x01000000, 0x00000010, 
    0x00000010, 0x00000016, 0x0000003c, 0xfffff724, 0x0000002d, 0x65646f6d, 0x6f632f6c, 0x6431766e, 
    0x616d732d, 0x622d6c6c, 0x6e616c61, 0x2d646563, 0x616c2f31, 0x5f726579, 0x614d2f39, 0x6f6f5078, 
    0x0000006c, 0x00000004, 0x00000001, 0x00000006, 0x00000001, 0x00000010, 0xfffff79e, 0x01000000, 
    0x00000010, 0x00000010, 0x00000015, 0x00000040, 0xfffff788, 0x00000030, 0x65646f6d, 0x6f632f6c, 
    0x6431766e, 0x616d732d, 0x622d6c6c, 0x6e616c61, 0x2d646563, 0x616c2f31, 0x5f726579, 0x78452f39, 
    0x646e6170, 0x736d6944, 0x00000000, 0x00000004, 0x00000001, 0x0000000c, 0x00000001, 0x00000010, 
    0xfffff806, 0x01000000, 0x00000010, 0x00000010, 0x00000014, 0x00000108, 0xfffff7f0, 0x000000f9, 
    0x65646f6d, 0x6f632f6c, 0x6431766e, 0x616d732d, 0x622d6c6c, 0x6e616c61, 0x2d646563, 0x616c2f31, 
    0x5f726579, 0x65522f38, 0x6d3b756c, 0x6c65646f, 0x6e6f632f, 0x2d643176, 0x6c616d73, 0x61622d6c, 
    0x636e616c, 0x312d6465, 0x79616c2f, 0x375f7265, 0x7461622f, 0x6f6e6863, 0x612f6d72, 0x315f6464, 
    0x646f6d3b, 0x632f6c65, 0x31766e6f, 0x6d732d64, 0x2d6c6c61, 0x616c6162, 0x6465636e, 0x6c2f312d, 
    0x72657961, 0x432f365f, 0x31766e6f, 0x71532f44, 0x7a656575, 0x6f6d3b65, 0x2f6c6564, 0x766e6f63, 
    0x732d6431, 0x6c6c616d, 0x6c61622d, 0x65636e61, 0x2f312d64, 0x6579616c, 0x2f375f72, 0x63746162, 
    0x726f6e68, 0x756d2f6d, 0x3b315f6c, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 0x6d732d64, 0x2d6c6c61, 
    0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 0x432f365f, 0x31766e6f, 0x00000044, 0x00000004, 
    0x00000001, 0x00000001, 0x0000000c, 0x00000010, 0xfffff936, 0x01000000, 0x00000010, 0x00000010, 
    0x00000013, 0x0000009c, 0xfffff920, 0x0000008c, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x616d732d, 
    0x622d6c6c, 0x6e616c61, 0x2d646563, 0x616c2f31, 0x5f726579, 0x65522f35, 0x6d3b756c, 0x6c65646f, 
    0x6e6f632f, 0x2d643176, 0x6c616d73, 0x61622d6c, 0x636e616c, 0x312d6465, 0x79616c2f, 0x345f7265, 
    0x6e6f432f, 0x2f443176, 0x65757153, 0x3b657a65, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x616d732d, 
    0x622d6c6c, 0x6e616c61, 0x2d646563, 0x616c2f31, 0x5f726579, 0x6f432f34, 0x4431766e, 0x00000000, 
    0x00000004, 0x00000001, 0x00000001, 0x0000000c, 0x00000010, 0xfffff9fa, 0x01000000, 0x00000010, 
    0x00000010, 0x00000012, 0x00000108, 0xfffff9e4, 0x000000f9, 0x65646f6d, 0x6f632f6c, 0x6431766e, 
    0x616d732d, 0x622d6c6c, 0x6e616c61, 0x2d646563, 0x616c2f31, 0x5f726579, 0x65522f33, 0x6d3b756c, 
    0x6c65646f, 0x6e6f632f, 0x2d643176, 0x6c616d73, 0x61622d6c, 0x636e616c, 0x312d6465, 0x79616c2f, 
    0x325f7265, 0x7461622f, 0x6f6e6863, 0x612f6d72, 0x315f6464, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 
    0x6d732d64, 0x2d6c6c61, 0x616c6162, 0x6465636e, 0x6c2f312d, 0x72657961, 0x432f315f, 0x31766e6f, 
    0x71532f44, 0x7a656575, 0x6f6d3b65, 0x2f6c6564, 0x766e6f63, 0x732d6431, 0x6c6c616d, 0x6c61622d, 
    0x65636e61, 0x2f312d64, 0x6579616c, 0x2f325f72, 0x63746162, 0x726f6e68, 0x756d2f6d, 0x3b315f6c, 
    0x646f6d3b, 0x632f6c65, 0x31766e6f, 0x6d732d64, 0x2d6c6c61, 0x616c6162, 0x6465636e, 0x6c2f312d, 
    0x72657961, 0x432f315f, 0x31766e6f, 0x00000044, 0x00000004, 0x00000001, 0x00000001, 0x0000000c, 
    0x00000010, 0xfffffb2a, 0x01000000, 0x00000010, 0x00000010, 0x00000011, 0x000000a0, 0xfffffb14, 
    0x00000090, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x616d732d, 0x622d6c6c, 0x6e616c61, 0x2d646563, 
    0x616c2f31, 0x5f726579, 0x69422f30, 0x64417361, 0x6f6d3b64, 0x2f6c6564, 0x766e6f63, 0x732d6431, 
    0x6c6c616d, 0x6c61622d, 0x65636e61, 0x2f312d64, 0x6579616c, 0x2f305f72, 0x766e6f43, 0x532f4431, 
    0x65657571, 0x3b3b657a, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x616d732d, 0x622d6c6c, 0x6e616c61, 
    0x2d646563, 0x616c2f31, 0x5f726579, 0x6f432f30, 0x4431766e, 0x00000000, 0x00000004, 0x00000001, 
    0x00000001, 0x00000018, 0x0000000d, 0xfffffbf2, 0x01000000, 0x00000010, 0x00000010, 0x00000010, 
    0x00000048, 0xfffffbdc, 0x00000038, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x616d732d, 0x622d6c6c, 
    0x6e616c61, 0x2d646563, 0x616c2f31, 0x5f726579, 0x6f432f30, 0x4431766e, 0x7078452f, 0x44646e61, 
    0x31736d69, 0x00000000, 0x00000004, 0x00000001, 0x00000001, 0x00000032, 0x0000001e, 0xfffffde6, 
    0x01000000, 0x00000014, 0x00000014, 0x0000000f, 0x02000000, 0x00000044, 0xfffffc50, 0x00000037, 
    0x65646f6d, 0x6f632f6c, 0x6431766e, 0x616d732d, 0x622d6c6c, 0x6e616c61, 0x2d646563, 0x616c2f31, 
    0x5f726579, 0x6f432f30, 0x4431766e, 0x7078452f, 0x44646e61, 0x00736d69, 0x00000001, 0x00000004, 
    0xfffffe4a, 0x01000000, 0x00000014, 0x00000014, 0x0000000e, 0x02000000, 0x00000020, 0xfffffcb4, 
    0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 0x3231746e, 0x00000000, 0x00000000, 0xfffffd02, 
    0x01000000, 0x00000010, 0x00000010, 0x0000000d, 0x00000020, 0xfffffcec, 0x00000010, 0x74697261, 
    0x6f632e68, 0x6174736e, 0x3131746e, 0x00000000, 0x00000001, 0x00000005, 0xfffffd3e, 0x01000000, 
    0x00000010, 0x00000010, 0x0000000c, 0x00000020, 0xfffffd28, 0x00000010, 0x74697261, 0x6f632e68, 
    0x6174736e, 0x3031746e, 0x00000000, 0x00000002, 0x00000005, 0x00000010, 0xfffffd7e, 0x01000000, 
    0x00000010, 0x00000010, 0x0000000b, 0x0000001c, 0xfffffd68, 0x0000000f, 0x74697261, 0x6f632e68, 
    0x6174736e, 0x0039746e, 0x00000004, 0x0000000d, 0x00000001, 0x00000003, 0x0000001e, 0xfffffdc2, 
    0x01000000, 0x00000010, 0x00000010, 0x0000000a, 0x0000001c, 0xfffffdac, 0x0000000f, 0x74697261, 
    0x6f632e68, 0x6174736e, 0x0038746e, 0x00000001, 0x00000010, 0xfffffdfa, 0x01000000, 0x00000010, 
    0x00000010, 0x00000009, 0x0000001c, 0xfffffde4, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 
    0x0037746e, 0x00000004, 0x00000010, 0x00000001, 0x00000003, 0x00000010, 0xffffffc2, 0x01000000, 
    0x00000014, 0x00000014, 0x00000008, 0x02000000, 0x0000001c, 0xfffffe2c, 0x0000000f, 0x74697261, 
    0x6f632e68, 0x6174736e, 0x0036746e, 0x00000001, 0x00000004, 0x00160000, 0x0018001c, 0x00100017, 
    0x0008000c, 0x00000000, 0x00070000, 0x00000016, 0x01000000, 0x00000014, 0x00000014, 0x00000007, 
    0x02000000, 0x0000001c, 0xfffffe80, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0035746e, 
    0x00000001, 0x00000003, 0xfffffece, 0x01000000, 0x00000010, 0x00000010, 0x00000006, 0x0000001c, 
    0xfffffeb8, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0034746e, 0x00000001, 0x0000000d, 
    0xffffff06, 0x01000000, 0x00000010, 0x00000010, 0x00000005, 0x0000001c, 0xfffffef0, 0x0000000f, 
    0x74697261, 0x6f632e68, 0x6174736e, 0x0033746e, 0x00000004, 0x00000010, 0x00000001, 0x00000003, 
    0x0000000d, 0xffffff4a, 0x01000000, 0x00000010, 0x00000010, 0x00000004, 0x0000001c, 0xffffff34, 
    0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0032746e, 0x00000004, 0x00000010, 0x00000001, 
    0x00000003, 0x00000010, 0xffffff8e, 0x01000000, 0x00000010, 0x00000010, 0x00000003, 0x0000001c, 
    0xffffff78, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0031746e, 0x00000001, 0x00000010, 
    0xffffffc6, 0x01000000, 0x00000010, 0x00000010, 0x00000002, 0x0000001c, 0xffffffb0, 0x0000000e, 
    0x74697261, 0x6f632e68, 0x6174736e, 0x0000746e, 0x00000001, 0x00000010, 0x00160000, 0x00140018, 
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
#define _K7              ((uint8_t *)_k7)                    // u8[18448] (18448 bytes)
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
    __RETURN_ERROR(mtb_init(_K10, _K7, 18448, _K6, 16384, 3, "network_float"));
    return 0;
}

static IMAI_api_def _IMAI_api_def = {
    .api_ver = 1,
    .id = {0x6b, 0xd8, 0xcd, 0x8b, 0x86, 0xd1, 0x04, 0x49, 0x9f, 0xbc, 0xbc, 0x57, 0x92, 0x5b, 0xa3, 0x14},
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
        .size = 20560,
        .peak_usage = 20560,
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

