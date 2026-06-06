/*
* ImagiNet Compiler 5.12.5418.0+7793ebcc9f383586f202c2d2f6eafbd7ebe6519d
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 06/06/2026 18:20:13 UTC. Any changes will be lost.
* 
* Model ID  e01cc319-6353-4838-9bc9-3b3baaa2d775
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
    0x00000004, 0x00000001, 0xffff74a2, 0x00000004, 0x00000014, 0xbd527a29, 0xbc0f7949, 0x3c286cf2, 
    0x3d84fa35, 0xbc740617, 0xffff74c2, 0x00000004, 0x00000280, 0xbe02fd81, 0xbebf35ef, 0x3eb9bbb0, 
    0xbeba700c, 0x3ea9e5c1, 0xbe4fcd64, 0xbe81eb11, 0x3e72c66a, 0xbd8d17fd, 0xbe43c2ec, 0xbe740a95, 
    0xbe52d965, 0x3de37fd6, 0x3e7cc491, 0xbe7688b6, 0x3ea87286, 0x3c94347f, 0x3e72fce2, 0xbe007364, 
    0xbd28330f, 0x3c3ee7bb, 0x3c12b27f, 0xbe3b2d49, 0xbe98293a, 0x3e16219e, 0x3e9b173e, 0xbebdb879, 
    0x3e1f3609, 0x3e796493, 0x3ec3745a, 0x3e4aedfe, 0x3e98825a, 0x3ea2f7cf, 0x3ea6fe6d, 0xbdff13b2, 
    0xbc5df656, 0xbeb8ba35, 0x3ea8839a, 0x3c54b405, 0x3e88bbd8, 0x3c57b697, 0x3e9c2fa9, 0xbe54305b, 
    0x3e8f8f1f, 0xbec880e6, 0xbec3b876, 0x3d6d9e2a, 0x3dc2b268, 0xbe8aa159, 0x3e5a353d, 0xbe469799, 
    0x3ec4e2cc, 0x3e16e44a, 0x3e649ee5, 0x3dae1a50, 0x3de326c3, 0xba36b8fd, 0x3d8b2c5c, 0xbe772300, 
    0xbe0d7706, 0xbeb84e22, 0x3e9917f3, 0xbd96e190, 0xbe1ffba6, 0xbde523d9, 0x3e2a7afa, 0xbe19f8f1, 
    0x3ebeedce, 0xbe0ce9c8, 0x3dac5cd3, 0xbe92703f, 0xbe0d0087, 0xbe7d5a0d, 0x3e015189, 0x3e5ac170, 
    0x3dbd6f77, 0x3eb16d58, 0xbec04244, 0xbed088d9, 0x3ec22a9f, 0x3e5bf3d3, 0xbd16af48, 0x3e2c66d3, 
    0x3e0e2905, 0x3eb829b5, 0xbebbeee9, 0x3dc548f0, 0xbe99e4d1, 0xbdcce05c, 0x3e5987d1, 0xbeb76bd5, 
    0xbc4ef521, 0xbc50e43a, 0xbd524f31, 0xbe555d5a, 0xbe5210b5, 0xbea61ff7, 0xbe930e26, 0x3ed3f225, 
    0xbe253ff7, 0xbe14a0ec, 0xbdfd15c5, 0xbdda71a4, 0xbcefc192, 0x3e7a218c, 0x3eba1ce4, 0xbe0a5ee2, 
    0xbe0b30ab, 0x3e503632, 0x3c0dd510, 0x3d9c011c, 0xbe962d14, 0x3ee003d6, 0x3ed3a82b, 0xbe164236, 
    0xbe96d9b0, 0xbe48aaab, 0x3e9f5f2e, 0x3e8d0f7e, 0x3db8361c, 0xbe174a1d, 0x3d78a368, 0xbeb87f1b, 
    0x3de6f66a, 0xbe7ae835, 0xbe483657, 0xbe32a758, 0xbd21f376, 0xbdfe4958, 0xbece2525, 0x3e05b315, 
    0xbe2924a1, 0x3d9c9dd2, 0x3e7d34a0, 0x3d8a45c8, 0x3e7e05c9, 0x3babb5cf, 0xbdc53a9d, 0xbe96f04e, 
    0xbeb169b1, 0x3d6ae918, 0xbed32141, 0x3e4e374e, 0xbe16f742, 0xbe4d1d17, 0x3ecad6da, 0xbde3a2d3, 
    0x3ed54523, 0x3dec3cbb, 0x3e730d31, 0xbdab2f09, 0xbe3c0eed, 0x3eb108e0, 0x3e3fd597, 0xbd788d5c, 
    0x3eb1dd03, 0xbe3fad74, 0xbd8efd73, 0x3e933abb, 0xbed59f3d, 0xffff774e, 0x00000004, 0x00001248, 
    0xbe364216, 0x3dc252ab, 0xbce808a3, 0xbe4fe3ee, 0x3db91a54, 0x3e3a4a9f, 0xbd94e764, 0x3e145f22, 
    0xbdeb804a, 0xbd5044f4, 0xbd069fa9, 0x3e23cedf, 0x3e5c98e9, 0xbdce7971, 0xbd00ccb0, 0x3e3dfcfe, 
    0xbb4d90cf, 0x3e031661, 0xbd5b10a3, 0xbcb8def1, 0x3e215603, 0xbe2783fd, 0xbe2ccfe6, 0xbdce00b0, 
    0x3e069dce, 0xbe3a1e39, 0x3c84c6b5, 0x3dea0b79, 0x3d8126e7, 0xbc5f0d73, 0xbe361dde, 0xbd21b7dc, 
    0xbc98d442, 0xbe2a75f2, 0xbe450910, 0x3db996b3, 0x3d77781a, 0xbe511491, 0x3d832eea, 0xbe1935b1, 
    0x3e1aca9c, 0xbdad6712, 0xbe0838c6, 0xbe3ef86f, 0xbe547a1f, 0x3dba119e, 0x3d2a24f0, 0x3e166328, 
    0xbe05e717, 0x3c5aca80, 0x3cf6a57e, 0x3c859326, 0x3ce2befa, 0x3d5ee872, 0x3d353b13, 0xbe44d70e, 
    0xbe54d75c, 0x3e0062b2, 0x3e41e250, 0x3e02f838, 0x3b8a815f, 0xbd16bae5, 0x3dc81359, 0xbd8b0069, 
    0x3dc13409, 0xbe0c076a, 0xbd777edb, 0xbe4d29e0, 0x3d2371a9, 0x3d024068, 0xbd55ff46, 0xbdeac181, 
    0x3e1d6208, 0x3c972dd7, 0x3d7ed790, 0xbd0a8181, 0xbd871381, 0xbe379812, 0x3defbfb9, 0x3e45f1db, 
    0x3cee23c3, 0x3d9ec217, 0xbe5bd662, 0xbe01d552, 0xbcfcb6d3, 0xbcc825b2, 0xbe2f3c23, 0x3e2cf009, 
    0xbca81720, 0x3dea3512, 0x3e1d9046, 0xbe298d62, 0x3da453a4, 0xbe0b8848, 0x3e2bd447, 0x3e15bc9f, 
    0xbdf3fe78, 0x3d86fdeb, 0x3d9da79a, 0xbe266091, 0xbe2df7cb, 0x3d61ef6e, 0xbdff7da2, 0x3d4de763, 
    0x3e3f3a24, 0xbd1597a6, 0x3e1afc40, 0xbd97ff7c, 0xbda070b6, 0x3e47a2a1, 0xbd0dd22d, 0xbe5ceb36, 
    0x3d470667, 0xbd12e7de, 0x3e17211b, 0x3e226f05, 0xbdda70df, 0xbe15213c, 0xbe238db9, 0x3e380a3e, 
    0x3cdd3ded, 0x3d79e576, 0xbc5ab79f, 0x3cb8f7cb, 0x3d9e914a, 0x3e268426, 0x3ddecfb6, 0xbe15836a, 
    0x3bd7a833, 0x3d4e529f, 0xbd886587, 0xbdc00ae0, 0x3e044b25, 0x3dcac783, 0x3e26593a, 0xbc3e58bc, 
    0x3c9c5815, 0x3e3957a2, 0x3dfa7059, 0x3e4af7c6, 0xbe133a10, 0x3da23586, 0xbd902e66, 0x3db1174f, 
    0x3e09571d, 0x3dae5aec, 0xbcd0431c, 0xbc9a766c, 0x3d1514c8, 0x3e4ec631, 0x3da3a5b5, 0xbe35563d, 
    0xbded5d96, 0x3c483bb8, 0x3e283bfb, 0xbe0974f6, 0x3e2c2a9f, 0x3e4c3857, 0xbe54a0b7, 0x3e3ba2bc, 
    0xbe49242a, 0xbd213ff8, 0x3e402f06, 0xbd8fa0a4, 0x3de4db7b, 0x3e265340, 0x3dc0a88d, 0x3cdd3b42, 
    0xbe4c398c, 0x3e1ab172, 0x3e0b7dbd, 0x3e25aff7, 0x3d10dd28, 0xbdf44ff9, 0xbe4829df, 0xbd457ee9, 
    0x3e06a058, 0xbe3899c2, 0xbdc887cf, 0x3e527aea, 0x3d0715d9, 0x3e012d16, 0x3d91076f, 0x3c1249aa, 
    0x3e2c4b63, 0xbe09f2fa, 0x3e23ef09, 0x3da06d66, 0xbdd8595f, 0x3e5c994e, 0x3ce8c98c, 0xbd55eb8f, 
    0x3dd24304, 0x3e11a4bd, 0x3e4a5e4b, 0xbd912357, 0x3c0d69a1, 0x3b5a6374, 0xbe4697c7, 0xbe0b846e, 
    0x3d4a6c0b, 0x3da5f977, 0x3e24d7fc, 0xbe0afc5a, 0x3e5021cc, 0x3cfb3b09, 0x3de644f9, 0x3d53359c, 
    0xbccbbe2c, 0xbe7aae00, 0xbd70adc1, 0x3d168730, 0xbe29548e, 0xbe505a45, 0xbe594aca, 0xbd09aad4, 
    0x3d804ff9, 0x3d82100d, 0xbc1e9ba7, 0xbe3655a9, 0xbe155640, 0x3dd45e6d, 0xbdae7be1, 0x3e1d3c38, 
    0xbcd052b5, 0xbb99af18, 0x3c319b79, 0x3db262c2, 0xbca609be, 0x3d47e988, 0xbdce48b7, 0x3e146256, 
    0xbdbed869, 0xbd612fe9, 0x3b616808, 0xbdb96b20, 0xbe46eb1e, 0xbe053d1d, 0x3ade2853, 0xbe56bd16, 
    0xbe4b2549, 0xbdd293d9, 0x3e01bdf4, 0xbe1917fc, 0x3df52108, 0x3e2fbfda, 0xbcf49109, 0xbe3398d1, 
    0xbd841337, 0xbaa2bc6e, 0xbd218547, 0xbcce7df0, 0x3e48700b, 0x3c46f4d1, 0x3e338d90, 0xbdd35fe1, 
    0xbe269e4a, 0xbd8f7ba8, 0xbe0dd619, 0xbc6af976, 0xbdb4060f, 0x3dd4fa3e, 0xbc964157, 0x3c0b1132, 
    0xb8c3b771, 0xbe2c71e0, 0x3de8882e, 0x3db52567, 0xbd91c7d6, 0xbe1a2001, 0xbdce46bd, 0xbcd70d00, 
    0xbe39db23, 0xbd263398, 0xbd30ed1e, 0xbc5344da, 0xbe4da4a0, 0x3d72f3b6, 0xbe362402, 0x3d8e38dd, 
    0xbdfcde73, 0x3dc13401, 0x3e1bef20, 0xbd0c67af, 0xbe417120, 0x3e3111d3, 0xbdcb86e3, 0xbe04ff6b, 
    0x3d65e63d, 0x3d92eef3, 0x3e35fefe, 0x3d47f83e, 0xbcfcb094, 0xbd8427ca, 0x3dea4abd, 0x3e1a14f4, 
    0x3dc71685, 0xbdfdb035, 0x3e19b301, 0xbd960aee, 0xbe4a7be1, 0xbe37d678, 0x3e469698, 0xbd99d82e, 
    0xbdb8d42b, 0x3e44b39c, 0xbe074947, 0x3dc90698, 0xbd8393fb, 0xbe5df3af, 0xbdcea40c, 0x3d357ef3, 
    0x3e0b9361, 0xbe59ee91, 0xbdad5a83, 0x3e227597, 0xbd882658, 0xbda89ca7, 0xbe261c29, 0xbd21690a, 
    0x3bfd1b49, 0xbe25374c, 0x3e3f7c3c, 0x3c550cf4, 0xbde56fc7, 0xbe047b59, 0xbde0265a, 0xbe33cd19, 
    0xbe29a2b4, 0x3e567f79, 0xbe3eeeb1, 0x3d156f20, 0xbde664bd, 0xbe4fc334, 0x3e2857ab, 0xbdcce3e7, 
    0xbe47aab3, 0x3e297676, 0xbd7cb977, 0x3d8892dc, 0x3de0455a, 0x3d352295, 0x3d42e404, 0xbe163ea7, 
    0xbdcc42e5, 0x3dcb6d79, 0x3e336aab, 0xbdb25331, 0x3dc0c567, 0xbe31f01e, 0x3dec60fe, 0xbdd506b1, 
    0x3e5e0c3a, 0x3dd0bbf2, 0x3d553f97, 0xbca0cdbc, 0x3e6cdf47, 0x3bcf88b7, 0xbd5253e5, 0xbe4c6826, 
    0x3c58ec68, 0x3d94dcc5, 0xbe49f3f4, 0x3d0a04ce, 0xbe351040, 0x3dd5001f, 0xbdd299d3, 0xbd87e682, 
    0x3e642901, 0x3dae4c4c, 0xbcf48569, 0x3e313b4b, 0xbe12f58b, 0x3e0148bc, 0xbe304471, 0x3e556006, 
    0x3e50a983, 0x3e1ff973, 0x3e528a92, 0xbe3efb4a, 0x3e3272b5, 0xbe384ae0, 0x3e509ba9, 0xbe0ad574, 
    0xbe420470, 0xbe4eb2c1, 0x3cba42c3, 0x3d1939da, 0xbdb837d0, 0x3e21edeb, 0xbd3bfa00, 0x3dda1b74, 
    0xbe5ee685, 0xbd5f6b73, 0xbe48c71e, 0x3e16c2c7, 0xbdf83496, 0xbd6e3663, 0xbd812ba4, 0x3d408975, 
    0x3cec98b8, 0xbc81173b, 0xbd7880b7, 0xbe421fee, 0x3e63bd6d, 0x3c81aff4, 0xbbff1cb6, 0xbe4e12e6, 
    0xbe061917, 0x3cdef0c2, 0x3d96f3f9, 0xbe3dd4f2, 0x3d61070b, 0x3d223d9d, 0x3d349124, 0xbd89c011, 
    0x3e03b388, 0x3e4f66fc, 0xbd28b0a4, 0xbe75a24a, 0x3e46085a, 0xbe3ea96f, 0x3da05e21, 0xbc9264ad, 
    0xbd128713, 0x3e24897b, 0x3d4a08c8, 0x3d841c0c, 0x3e27f46d, 0xbdf60df8, 0xba5eda72, 0x3e37755a, 
    0x3df84694, 0x3e5987b1, 0xbd40d180, 0x3e04f309, 0x3e4fa6f7, 0x3d75f515, 0x3c100229, 0x3b66096c, 
    0x3dc72c36, 0x3e13347e, 0x3de50036, 0x3ca1ed35, 0xbdd3c87a, 0x3d4d8d5b, 0x3ddc12bd, 0x3dc20997, 
    0xbda67d82, 0xbe35ac04, 0x3e1986b6, 0x3da3cc5c, 0x3d35a85e, 0xbe0edff6, 0x3dca8ace, 0x3e079e26, 
    0xbe034dfa, 0x3db55224, 0x3e006b92, 0x3dd6ec93, 0xbe4a5abf, 0x3d02c3f9, 0xbddb804f, 0x3e2b434b, 
    0x3e2b5f66, 0xbcdc3b39, 0xbd310f49, 0x3df83edc, 0xbe136b2d, 0xbe05d50b, 0x3d4be115, 0xbc38a441, 
    0xbe4ca202, 0xbdcdc0a6, 0xbe2a3f5e, 0x3d93bebf, 0xbe50c897, 0x3e4c010f, 0xbe321726, 0x3e573f8d, 
    0xbe4101ec, 0x3bb802cd, 0xbe0dad49, 0xbda8c439, 0x3d34ca63, 0x3d35793a, 0x3e29013e, 0xbd0876da, 
    0x3db2cbf9, 0xbe46decc, 0xbd9cc403, 0xbcbb613c, 0xbccbd5e2, 0xbce00306, 0xbdcd374c, 0x3dd15524, 
    0x3d25b1a1, 0x3e41bfc8, 0xbcf65cb5, 0xbdd69b45, 0xbdc4dbbe, 0xbe61232d, 0xbdaf8781, 0xbce622a1, 
    0xbe0a28a5, 0xbd0d1b78, 0xbe2aafc1, 0xbe2365c2, 0x3e29065f, 0xbe3c183d, 0xbe001009, 0x3b951aba, 
    0xbe0b8e88, 0xbdc7bb72, 0x3dce9c57, 0xbd522c0f, 0x3c7d6586, 0xbdb665db, 0xbe43d7e9, 0xbe157381, 
    0xbb7bd664, 0x3e0e463d, 0xbe100ada, 0xba56bea4, 0x3e30b930, 0x3dcffc2e, 0x3dad904b, 0x3c4764ff, 
    0xbe37525f, 0xbd69ea0f, 0xbdea006d, 0x3a9466c3, 0xb9f338ce, 0xbc4aa86f, 0xbd3bc748, 0x3d9cd010, 
    0x3e2b7cda, 0xbd6c70c0, 0x3db16c6a, 0x3d9f3a20, 0xbd38b75c, 0x3ce24c17, 0x3d5df160, 0x3e346c70, 
    0xbe1def65, 0xbdb3d5a5, 0xbe621fd1, 0x3e36d323, 0xbe330099, 0xbde904f1, 0x3e488d57, 0xbdd78e6c, 
    0xbc72cfc0, 0xbd1daef1, 0x3e22e87b, 0xbdabc90d, 0xbd4da993, 0xbd0d0298, 0xbd6d907f, 0xbe5420c6, 
    0x3e306e10, 0x3e02a0b7, 0xbde230bc, 0xbe491206, 0xbe3a28c7, 0x3e195fc9, 0xbde36fa8, 0xbdd4660e, 
    0x3d266f89, 0x3d2955bb, 0x3dbbc4e7, 0x3d0fb09d, 0xbd7b8000, 0xbe1a970c, 0xbd92b860, 0xbd52bc42, 
    0x3e46c1fa, 0x3e03174f, 0xbd559205, 0x3e5c250f, 0x3e1aad0c, 0xbe2666af, 0x3deed6ff, 0xbcff304d, 
    0x3e14cd72, 0xbd905dc4, 0xbd67a6d2, 0x3dd0a9d3, 0x3a50d2fe, 0x3dc91b19, 0x3d5cd82c, 0x3d883d21, 
    0x3d8cd45d, 0x3dd7345a, 0x3c178784, 0xbe137c7a, 0x3e1eb574, 0x3e08a32b, 0xbe4eab89, 0xbe0b2aee, 
    0xbe21fdbb, 0xbc1b0e7b, 0xbe2790f6, 0x3d9239f7, 0xbd9b9a33, 0x3e34d0a2, 0x3d04ab08, 0xbbdfa5a0, 
    0xbda769c2, 0x3e3b85ec, 0x3e007035, 0x3de711e1, 0x3e1d1323, 0xbe0cd29a, 0x3d4c8239, 0x3d82e65e, 
    0xbb5c4661, 0x3e36769c, 0x3e2efb6b, 0x3e26d3b1, 0x3dc9ebc7, 0x3e56408d, 0xbd8be7d4, 0xbe0d355a, 
    0xbdfc70bf, 0xbe2027d8, 0xbdc59fab, 0xbe24b264, 0xbe08e1f7, 0xbdc85ca9, 0x3d5319b7, 0x3b5a7578, 
    0x3e177c8c, 0xbdd08823, 0x3dd45839, 0x3e12b054, 0x3d09ffa9, 0xbe28b2b0, 0x3e5108f9, 0xbdd5930b, 
    0x3d22b7bc, 0xbda48089, 0xbd48fb99, 0xbe2e4649, 0x3d8394ed, 0x3ddbe68f, 0x3e5d1cb5, 0x3e02a5b7, 
    0xbd0c6b98, 0x3c6bcbbc, 0xbdd99657, 0xbd94a63a, 0xbe3c94d9, 0xbcc76bf3, 0xbd2fee24, 0xbc4d3f60, 
    0x3dbda8d1, 0x3e2abab7, 0x3ddf833e, 0xbe1395a1, 0xbd9bd7a9, 0xbe05c3db, 0xbe1e5ef0, 0xbc995d43, 
    0x3dc9673e, 0x3e129723, 0xbd217902, 0xbdc365ba, 0x3d711e20, 0xbe026455, 0x3e2f1d54, 0xbdeb41a4, 
    0x3d2551ec, 0x3dace8d0, 0x3db2765a, 0x3dcbcc49, 0x3ddfe5e3, 0x3d26acf8, 0x3e0cc119, 0xbde267de, 
    0x3d1273b7, 0xbd2193bd, 0xbded9e0e, 0xbdf17764, 0x3df2c32a, 0x3cabb554, 0xbe03d1a8, 0x3bef75bb, 
    0x3d90b423, 0xbdb80474, 0x3de7f0a4, 0xbcc31fe5, 0xbe165279, 0xbe2f8ab7, 0x3cb739bf, 0xbd4fddd1, 
    0xbd14ff95, 0xbe06c45a, 0xbe390f82, 0x3e02864f, 0x3e2f47d9, 0xbe0b6ef6, 0xbe3abb9a, 0x3e176947, 
    0xbe011524, 0xbdbef796, 0x3e14b0e3, 0xbddbbe26, 0x3e4f0931, 0x3e06010d, 0x3db83b94, 0xbda0ebdb, 
    0x3dd7c8ba, 0x3df6218e, 0x3dfe5ae1, 0x3dd0dcd9, 0xbde32ec5, 0xbde7296a, 0xbd739106, 0xbdb7bfa0, 
    0xbd901337, 0x3dcdeed3, 0xbe18a4b0, 0xbdebe3a9, 0xbc2403d7, 0xbe2eb9df, 0xbe398e93, 0x3e01f326, 
    0xbe55b583, 0x3dd1c568, 0x3e05d271, 0xbe3ffee8, 0x3d9f0a80, 0x3d000d70, 0xbda63b6a, 0xbb1bca93, 
    0xbe080d23, 0x3e6db3ed, 0xbc295184, 0xbe7533f6, 0xbe1d3cf6, 0x3d7a6541, 0x3e13b91c, 0x3da2a65a, 
    0xbe0189dd, 0xbe3c3f83, 0x3e01dc70, 0x3e112e9b, 0x3be11a23, 0x3e04199b, 0xbb23c3ee, 0x3e3fb219, 
    0x3cffb679, 0x3e455fef, 0xbcefa32d, 0x3ca5eb2a, 0x3d88ccd7, 0xbe2c6ba5, 0xbc81f3b8, 0x3dbcaa20, 
    0x3e08a1da, 0x3dc57337, 0xbd6f7713, 0xbac71db0, 0xbe03cc05, 0xbb16b7cd, 0x3e113b18, 0x3c38a1d2, 
    0x3c9126e2, 0x3ca258ee, 0xbdd314ff, 0x3e37f2e0, 0xbe314acc, 0xbdafec1f, 0x3d3efb48, 0xbde7e564, 
    0x3d8c74a3, 0xbdc3a39c, 0xbdb012b9, 0xbdefb1cb, 0x3d96114e, 0x3dd4c956, 0xbdf805a0, 0x3e317f82, 
    0x3dfa6959, 0xbcc30612, 0xbdf0a98b, 0xbdcfe5f5, 0x3d1b4818, 0xbda252db, 0xbdd43de4, 0xbd61ed97, 
    0x3d699829, 0xbe100c62, 0xbe04c29a, 0xbe5ed8c7, 0xbe551049, 0xbcf79cb1, 0xbcb2442d, 0xbd398dba, 
    0xbe45d4b9, 0x3ca45d5a, 0x3df1e348, 0xbb31d8de, 0xbe41f3f9, 0x3d17b37a, 0x3dffc6d9, 0x3da1c64a, 
    0x3c9fe28b, 0x3e0b6e03, 0xbc98b93d, 0xbd1ca635, 0x3e302c00, 0x3d44c1de, 0x3dbf8101, 0x3e1f31b9, 
    0x3e2b75ab, 0x3df4e006, 0xbda39c16, 0x3d815cc2, 0xbe4b8ff0, 0x3e21d7de, 0x3de5e527, 0x3d422187, 
    0xbd9537b5, 0xbe5bc13f, 0x3d519fe6, 0xbcce9b94, 0x3e47e423, 0x3dcca0b8, 0xbe3b5834, 0x3c98d25e, 
    0x3cf34d7a, 0x3ce56b35, 0xbe1034bd, 0x3dbb887b, 0xbe51e446, 0x3ddc25d3, 0x3b44f257, 0xbae093a1, 
    0x3b766032, 0xbe37d49b, 0xbd3bdf43, 0x3ce67afa, 0x3dc12702, 0xbd69cc85, 0xbd27dd21, 0x3dd32b92, 
    0x3dd04065, 0x3c2d1813, 0x3b489778, 0x3e474cb5, 0xbd6cf8f7, 0x3d953dd9, 0x3e220162, 0x3e347ae3, 
    0xbd4df431, 0x3e17d746, 0xbe2a7ea7, 0x3e178fc6, 0x3e1b4b2f, 0x3d262cb1, 0xbe5fe26a, 0xbcb6b453, 
    0x3e0326ca, 0x3dfb06bd, 0x3d4df180, 0x3e2077db, 0xbe2c5381, 0x3daa7f28, 0xbbb85808, 0xbe418620, 
    0x3e22d60d, 0xbe11f37d, 0x3c5742d2, 0xbdc6ddca, 0x3da7330d, 0x3dead7fe, 0x3cf6a014, 0x3dbfaca6, 
    0xbd8989a9, 0xbd42d69d, 0xbda3db00, 0xbd73cc28, 0x3e3903e1, 0xbd0b1d56, 0x3d966b74, 0x3c0b094b, 
    0xbcff54d6, 0xbc807fd4, 0x3ce81035, 0xbde8fa95, 0xbd210619, 0xbc8eaf50, 0xbde81754, 0x3de6fd14, 
    0xbe3cfb39, 0x3d15b64f, 0xbe338574, 0xbe60dee6, 0xbe3b56b0, 0xbd9cc73f, 0x3e0e3602, 0xbd8b76a3, 
    0x3e32e4a9, 0x3d1beccc, 0x3e0fdc10, 0x3d491405, 0x3d848515, 0x3d0d8354, 0x3d389162, 0x3e334c56, 
    0x3d0dffc6, 0x3e5934e4, 0x3e4b1281, 0xbd7e1e9d, 0x3d8deccb, 0xbdb9e3c7, 0x3defd3cf, 0x3d83cda7, 
    0x3dd17268, 0xbe4ee2a0, 0xbe1b79b7, 0xbe37126a, 0xbdcebc99, 0xbd369637, 0xbe058ff6, 0xbe258979, 
    0xbcd53beb, 0xbe7badf8, 0xbc9f0925, 0x3e06d850, 0xbe02170e, 0xbd88c764, 0xbd0e87e9, 0x3db6a4b8, 
    0xbb83da05, 0x3df34ded, 0x3ce2f7eb, 0xbcf62f34, 0x3d9cdcab, 0x3e253f0b, 0x3c23a6a4, 0x3d007e96, 
    0x3e3956a0, 0x3db3fda2, 0x3e5bd90d, 0x3dd88997, 0xbd5baf6b, 0xbe17735a, 0xbe012f2d, 0xbccf38fc, 
    0xbe01841d, 0xbdbc53c1, 0x3e55d1ac, 0xbe1e14ec, 0x3e32e13e, 0xbe26ec7c, 0xbe0ad01c, 0xbca952a5, 
    0x3d0e3fda, 0xbb7d10ad, 0xbe61354b, 0xbd78d259, 0x3d12c208, 0xbe43940d, 0x3da87d26, 0xbdc42560, 
    0xbd54c13b, 0x3d1a1a69, 0x3bc0f374, 0x3ccb2c38, 0xbba0fdb0, 0x3cc12764, 0x3e45a907, 0xbe188431, 
    0x38bf4b08, 0xbdc96338, 0x3df75285, 0x3d82c88e, 0x3de8610b, 0xbe17bdc5, 0xbe70f16c, 0xbe46760d, 
    0xbd08302f, 0xbdc9dcde, 0x3d14af25, 0x3d4eb9e8, 0x3e2df580, 0xbe81624c, 0x3e3fa044, 0x3e47bf0c, 
    0xbca54b57, 0x3c0536bf, 0x3e1641ca, 0xbdb64156, 0xbe6364cf, 0xbca8aafa, 0x3e163bef, 0xbd3b88f5, 
    0xbd72f772, 0x3e2000f4, 0x3d74c52b, 0xbdff614b, 0x3cf70715, 0xbd600026, 0xbbf5f527, 0xbe2f191f, 
    0xbce696f1, 0x3c2bbdef, 0x3be2fa3b, 0x3d20d0c2, 0xbdc01a9a, 0x3e5c8983, 0x3e51d09e, 0xbe05a35f, 
    0xbcf4ccb5, 0xbe2d4e77, 0xbe6f1fd7, 0xbdd54aee, 0xbe4f6761, 0x3d8bb333, 0x3dd36559, 0xbd3522e2, 
    0x3e3c3477, 0xbe5d39df, 0x3e331118, 0xbdb4c758, 0xbe2f427d, 0xbdceedc7, 0x3cbe1b15, 0x3d3a2ee5, 
    0x3d12f538, 0x3d7fa09d, 0x3da14d71, 0x3acf042d, 0xbc5ffa74, 0x3c5b723f, 0xbdddb48d, 0xbdd5d113, 
    0xbd9452c7, 0xbe3cff9d, 0x3e229735, 0x3e38d96f, 0xbe49b14f, 0x3db4748f, 0xbe20bdb1, 0xbe3e9008, 
    0xbe815669, 0xbdde5781, 0x3d9987ed, 0x3e1d422d, 0xbddb9afb, 0xbd0b23a0, 0xbe15c402, 0x3dc9867c, 
    0x3dc73a38, 0xbc8fa4af, 0x3d8eb5b3, 0xbbba7b33, 0xbe2ab67d, 0xbdb1ad18, 0x3df3e269, 0xbe419e8a, 
    0xbdd4e11d, 0xbe320232, 0x3e5b4d95, 0x3d8984de, 0x3dfa7a01, 0x3df4d12d, 0xbe30304e, 0x3e01ad5a, 
    0x3c80069a, 0x3da936aa, 0x3e23e009, 0xbe439f55, 0xbd1ebf67, 0x3e0bf12f, 0x3d19599e, 0xbd6cb45a, 
    0x3cac01ee, 0x3e0f450d, 0xbd2f3d28, 0x3d811848, 0x3d11f0df, 0xbd41c431, 0x3d6dd90d, 0x3ddab9f1, 
    0x3dbbdb9f, 0x3dd5cc82, 0x3d7f86d9, 0x3e24b2ca, 0xbe1538c0, 0xbde3c9da, 0x3e21a37d, 0xbd417990, 
    0xbca479a7, 0x3da5be6f, 0xbe0f87df, 0x3e283e7f, 0xbd389e3d, 0xbe397fbf, 0x3e1a6af7, 0xbe4762a8, 
    0xbe04b5db, 0x3d22b0d1, 0xbdc6a1d3, 0x3e112d85, 0x3e1d5d92, 0x3da951ac, 0xbc3cd0ee, 0x3d07eb14, 
    0x3e3bda9d, 0xbe64605b, 0x3d13772b, 0x3d9bff32, 0xbc8e513c, 0x3d0e69a3, 0x3db36475, 0xbd4fd537, 
    0x3d235c03, 0xbe3c51dc, 0xbc3bc734, 0x3e4a43b9, 0x3dc0ca9b, 0x3c26844c, 0xbd0469d8, 0x3e12330b, 
    0xbe02cbfd, 0xbe1540db, 0x3d5405cb, 0xbe020796, 0x3df0ae61, 0xbd853a41, 0x3ddf8045, 0xbd2943bc, 
    0x3e13abfc, 0xbe396985, 0x3deefeff, 0xbd833728, 0xbe3905d7, 0x3c54bcc8, 0xbdbca76f, 0x3be4541c, 
    0x3e1b2fbb, 0xb7c0f9c8, 0x3d50df0a, 0x3d386b30, 0x3e2633c6, 0xbe2ccbb8, 0x3e26e5d6, 0x3ce758fa, 
    0xbd9a81ec, 0x3e66217e, 0x3d56390c, 0x3e61b719, 0x3e1bafbf, 0x3e26d78c, 0x3d9774e7, 0xbe1ba84f, 
    0xbd1aa101, 0xbe2fc987, 0xbceb4dbb, 0xbe372ef7, 0xbe252f87, 0xbdd7e661, 0x3df6d219, 0xbcaede2c, 
    0xbc8b490c, 0xbd9f6fcf, 0xffff89a2, 0x00000004, 0x00000080, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xffff8a2e, 0x00000004, 0x00003000, 
    0xbe3bbf41, 0xbdc39f05, 0xbdc43bfa, 0xbcf1cd95, 0xbddd507a, 0x3e0c6a63, 0xbcf5175a, 0x3d344759, 
    0x3b0f3d6c, 0x3e28f88c, 0xbc44602c, 0x3db8c855, 0x3d19e739, 0xbe1a61b8, 0xbdb538b2, 0x3e24b05b, 
    0xbd9e8634, 0x3e12b981, 0xbd3a89f1, 0x3dde74f9, 0x3df0c0b0, 0xbde8e054, 0x3ba73004, 0x3de83638, 
    0x3dd5aaf3, 0x3c6e936c, 0xbe01255a, 0xbd81a194, 0xbc8c0dfe, 0x3db91ed7, 0xbe1bd931, 0xbbf2e1d7, 
    0xbe00ed25, 0x3da76cf7, 0x3dd9776b, 0x3c99324c, 0x3e06a3bd, 0x3d8f662f, 0xbe03304c, 0xbe19c878, 
    0x3df973ea, 0x3e107917, 0x3e197d66, 0x3d79cf27, 0xbd07ece1, 0x3d633f70, 0x3e0fe930, 0x3d6b1fa8, 
    0xbe3598c9, 0xbe1fe6e0, 0x3d32cfdb, 0xbd05365b, 0xbbdc7513, 0xbdaa7d1f, 0xbdf0914a, 0xbe1f5dee, 
    0x3e03e690, 0xbd6fd96e, 0xbc3196ab, 0x3bb0eda9, 0xbe0d4a5a, 0xbcc796db, 0xbe04b735, 0xbdade334, 
    0x3d3e5539, 0x3d992364, 0xbda1c985, 0xbdd903c2, 0xbdaa3c64, 0xbd938462, 0x3d744212, 0xbe16b846, 
    0x3b62beef, 0xbd1c6ba7, 0x3d153b81, 0xbe1c9cdf, 0x3dce63fa, 0xbe26de29, 0xbe3a37be, 0xbe112602, 
    0x3e0e903a, 0x3d8dd748, 0x3d94a3a8, 0xbcff27aa, 0xbb24eaf3, 0xbe3305cd, 0xbe113258, 0x3e03296d, 
    0xbda1c277, 0xbdebfeb2, 0xbe17af7f, 0x3d9fbee8, 0xbe325b91, 0x3db75228, 0xbdef1641, 0xbd8367f5, 
    0x3bf94c71, 0xbd79882f, 0x3dede25b, 0x3ce717fb, 0x3d5db2d8, 0xbddfd583, 0xbcecaf45, 0x3dd75308, 
    0xbcba0f1a, 0x3d22df64, 0x3cc9e3ad, 0xbab5746b, 0xbe2105a5, 0xbda47ca6, 0x3e296ef0, 0x3df3178a, 
    0xbddc73df, 0xbd7773af, 0xbdebf373, 0x3b96640c, 0x3d33568a, 0x3dd02d6b, 0x3de99407, 0x3d9baa63, 
    0x3e36bd30, 0xbd6a4f55, 0x3ca9df42, 0x3d746c94, 0xbd760381, 0xbe360663, 0x3deb7d85, 0xbe1e1b26, 
    0xbcd037d1, 0x3d907f1b, 0x3cd08967, 0xbe1be3e8, 0xbe34eb10, 0x3cece9eb, 0x3beecb16, 0x3dc1db08, 
    0x3d0781da, 0x3dfdc395, 0x3e49dba4, 0xbe02f6c0, 0xbdffd2cc, 0x3d9cab0e, 0x3dcdabcf, 0x3d6aaa45, 
    0x3e0480fc, 0x3d6dbac5, 0xbdfc3497, 0x3cb08e3d, 0x3dffdd27, 0xbd398892, 0xbcb6f950, 0x3e48db53, 
    0x3dacc2f4, 0x3d95a184, 0xbe192f14, 0xbb6a425e, 0x3cddbb36, 0xbdacb6f0, 0xbe0e7b56, 0xbd5ed784, 
    0xbd2a1671, 0x3b28016c, 0x3dcc8916, 0xbd2d7ee6, 0x3c915762, 0x3dafeea4, 0xbcbc68ba, 0xbd8c437d, 
    0xbe258ef4, 0x3e1910d5, 0x3e2f1506, 0x3d3313ca, 0xbdcff5bd, 0xbd57e834, 0x3e1e5443, 0xbdf591ea, 
    0x3d4a65f3, 0x39bc223e, 0x3d93db2b, 0xbd83cf30, 0x3e03bdd2, 0xbd84ec51, 0x3d17b09d, 0x3d1afe8a, 
    0xbdc96c81, 0x3e1f930c, 0x3daf032e, 0xbd9149ee, 0xbc5db267, 0x3ca220b0, 0x3d58c989, 0x3ceade31, 
    0x3d04d293, 0x3c804fd9, 0xbe00b732, 0x3be21164, 0x3e12ae93, 0xbe22744d, 0xbe0419c3, 0x3d98bc53, 
    0xbde83299, 0xbe268415, 0xbcd4e526, 0xbe16985f, 0x3e0bd93e, 0x3dc23e21, 0x3e00c4b8, 0xbd5b96ea, 
    0xbd2e6c5d, 0xbcfae64d, 0xbdad356c, 0xbe024008, 0x3ceb9eb2, 0x3e0c4252, 0x3d921c33, 0xbdb56776, 
    0x3c1f99f6, 0x3e140b08, 0x3dbe1072, 0xbd549e9a, 0x3dba8a4f, 0x3a530cef, 0xbdbbe974, 0x3d70410d, 
    0x3c863f3b, 0x3e08d2ed, 0xbc537b57, 0xbd5a8e85, 0x3e194555, 0x3df5e0fe, 0x3d0872a9, 0x3dfda5b0, 
    0xbc6e0fe5, 0x3df4c93c, 0xbe022674, 0x3dbbf88a, 0xbe316667, 0x3d95810e, 0x3dc46fe0, 0x3caaedcc, 
    0x3df196e7, 0x3ce69aaf, 0xbe2f0c3a, 0xbd5aa7bd, 0x3d7ff5de, 0x3d13dc0b, 0x3e2f7600, 0xbdf8eb91, 
    0xbdd04318, 0x3e0a5185, 0x3da980ab, 0xbe01c81d, 0xbd297131, 0x3e170787, 0xbbbbe9dd, 0x3d36e21c, 
    0xbd3e89db, 0x3d80471b, 0x3d77577a, 0xbe1f7c72, 0x3ddd4c2f, 0xbd98e49c, 0xbda0db83, 0xbe18c07a, 
    0xbe25b6c4, 0x3e235786, 0xbe07ab4b, 0xbe0873eb, 0xbe357ae1, 0x3ba72c3b, 0xbd2b8433, 0xbd855ccf, 
    0x3d7ba6a9, 0xbd7b2b07, 0xbdba6cf6, 0x3d1ec152, 0xbe0badba, 0xbde1c5d4, 0x3e26f7c6, 0x3d42eea6, 
    0xbe2854b7, 0x3d94c7c8, 0xbe057040, 0xbb3402aa, 0xbd29f5cf, 0xbcf0d895, 0x3de08b59, 0xbddbed44, 
    0xbde328d2, 0xbdd28182, 0xbd0798fe, 0xbd31c4ee, 0xbd2dd2d9, 0x3d67ace2, 0x3bba5b21, 0x3d9ae06a, 
    0xbe0b0e42, 0xbe266484, 0x3dcb4005, 0x3e50be5d, 0x3cca5cef, 0x3cb35dac, 0x3e2bd667, 0x3dd1d312, 
    0xbdba8d73, 0xbcdc47f3, 0xbe236932, 0x3da3e5de, 0xbcb5f87e, 0x3dddfbac, 0x3dba54c0, 0xbdc5b175, 
    0x3df33086, 0xbd9d60fd, 0x3d1f1c6c, 0xbe15a044, 0xbd9de62a, 0xbe0eaae8, 0xbd7e062f, 0xbdd5f12c, 
    0x3dca0425, 0xbd99f5a2, 0x3cbf3745, 0x3d07d277, 0x3dbb3368, 0xbd8e26d2, 0xbbd93037, 0xbde05e68, 
    0x3e1da493, 0xbd58c9b7, 0xbdbd3ea4, 0x3e31ee3c, 0x3d853039, 0xbe06fa30, 0x3e1fb545, 0x3a635271, 
    0x3dc7d6b1, 0x3dc2c58d, 0x3cf1d650, 0x3deaaa08, 0x3c843a47, 0x3d52293d, 0x3dee25c1, 0xbd854ae0, 
    0xbd0ae200, 0xbdf592b5, 0x3da198da, 0xbda52cd0, 0x3db6a835, 0xbe1678e8, 0x3e0171a3, 0xbe186f5e, 
    0x3c488920, 0x3e31808f, 0x3e434be6, 0xbdb0d708, 0x3d86c4fa, 0xbdb66cef, 0x3d9269d7, 0xbc81b1d8, 
    0xbde34939, 0xbd4f05d9, 0xbcc784b6, 0xbc1046b8, 0x3dfe67a7, 0x3e052dc6, 0xbe0d148c, 0x3e29d8aa, 
    0x3d6c9b99, 0xbdf42fef, 0xbd4e712e, 0xbdfdcdd1, 0xbd9186e8, 0xbbd38162, 0x3df92d03, 0xbe2f62e5, 
    0xbe0098f9, 0x3da7f9a9, 0xbc91d38c, 0x3de30172, 0x3dd2f2b0, 0xbdc62125, 0xbdc7fe34, 0x3cb8b644, 
    0xbe204986, 0xbe0c4da7, 0x3d350cad, 0xbd5565a9, 0x3e1b58cc, 0x3de625db, 0xbcedfb54, 0xbe322d25, 
    0x3d6055df, 0x3dd6af17, 0x3e0249ac, 0x3d8089ee, 0xbd9f8869, 0xbd9241fa, 0x3c4df86c, 0xbe1d74ea, 
    0xbda527dd, 0x3cd7aec7, 0x3db8c7d2, 0xbd173750, 0xbe37c300, 0xbd5cbd42, 0x3e1a19be, 0xbe0bffa9, 
    0x3e10541b, 0xbd214c6a, 0x3e1cd5b1, 0x3d9a101a, 0x3cd2df13, 0xbd2de221, 0xbd1c5b15, 0xbd5f34b8, 
    0xbdc41d33, 0xbe010313, 0x3cb2437d, 0x3e05e728, 0xbca7bf75, 0x3d7fb2a8, 0xbd097d12, 0x3e0ee9d6, 
    0x3ddff441, 0x3bdfb130, 0x3db83081, 0x3d3b69c8, 0xbd8cb03e, 0xbc847f44, 0x3e2223e4, 0xbcbf88d8, 
    0x3dbcd0c2, 0x3d3ba784, 0xbe1d609d, 0x3dd91015, 0x3d46a4da, 0x3e3ced1d, 0xbcfc8f08, 0xbd2a5a48, 
    0x3dd1c597, 0xbdd97e20, 0x3e10296d, 0x3d5b28c6, 0x3e099e8e, 0xbae8ed88, 0x3964a451, 0x3d589315, 
    0xbda07b14, 0xbd9cc57b, 0xbd8c9fd9, 0x3d56e995, 0x3e04312c, 0xbcfa56b9, 0xbc8cdcbc, 0xbc3ebd45, 
    0x3dc26bb5, 0x3e35ba75, 0xbdde3f61, 0xbdc8fca8, 0x3de8ea50, 0x3d4bc89d, 0xbd0c7f4a, 0xbe097b36, 
    0x3df0180b, 0xbe24005a, 0x3da7e176, 0xbe1f43af, 0xbcb2e08f, 0xbe004fbe, 0xbdd31330, 0x3b3eefb6, 
    0x3d69863f, 0x3e01843e, 0xbdd9b9e9, 0x3d7af258, 0xbe036284, 0xbe045825, 0xbd855e4c, 0xbcb92d71, 
    0x3db2f29e, 0x3d9e5308, 0x3baa9ba6, 0xbc690d69, 0xbd54d813, 0xbc243b68, 0xbd9c607f, 0x3ddeb7d0, 
    0x3ddb696b, 0xbe06de0d, 0xbd65d4a4, 0x3cbf3d9c, 0x3dbef787, 0x3dfb2cce, 0xbd30ecc8, 0xbdaa8e92, 
    0x3e4c81a7, 0xbca2ed4a, 0x3c50aa16, 0x3dd56cc9, 0xbdec0a16, 0x3db9dafb, 0xbda32046, 0xbcebdcc1, 
    0xbe13eb35, 0x3e26a7b6, 0x3d930969, 0xbdca512b, 0xbdd6b7c6, 0x3e3b4fdf, 0xbe054d64, 0xbd962846, 
    0x3e09458e, 0x3ddd845e, 0x3d3b7c78, 0xbe164325, 0x3d02228b, 0x3df48390, 0x3e092f13, 0x3dd56f7a, 
    0x3d8c9c7a, 0xbe09b05c, 0xbe2a9a4d, 0x3dddd62b, 0x3e2311cb, 0xbe0092a6, 0xbe23c35d, 0x3e2aab09, 
    0xbdbcddc2, 0xbc817a11, 0xbd36daf2, 0xbd38d38c, 0xbdc0cb1b, 0x3dfd86b2, 0xbdd8ca32, 0xbdb95685, 
    0xbd8fca3a, 0x3ddae400, 0x3e05348d, 0xbc1b5985, 0x3e173ba7, 0x3dfe6d45, 0x3d9fdad8, 0x3da69d49, 
    0xbc83ab9f, 0x3e14528b, 0xbe159cf3, 0x3d941d01, 0x3d5a437d, 0xbd35b0c0, 0xbe1ca008, 0xbdf80563, 
    0x3e270fd9, 0xbdbe6396, 0xbe19cf66, 0x3e3511af, 0xbdc2ecd2, 0xbde8118d, 0xbd8a8a9e, 0xbd4f6e93, 
    0x3e35d2df, 0xbb85b140, 0xbe36a0f0, 0xbd58071f, 0x3b631a53, 0xbe2501ed, 0x3d7895f2, 0x3e2a2b8a, 
    0x3dc629d4, 0xbdecdf24, 0x3de0edf4, 0xbdef833f, 0x3e22b1c8, 0x3d8abda9, 0x3d69888b, 0xbd9573cb, 
    0x3e04776f, 0x3d83bf77, 0x3c3c6ac3, 0x3e00f69c, 0xbdb53de7, 0x3e0371e0, 0x3d71d6bb, 0xbc9d8fc8, 
    0xbc91c039, 0xbe1bdb90, 0x3e18514c, 0x3e25cd85, 0xbc1fd5ef, 0x3e1a738f, 0x3e134be8, 0x3db211b4, 
    0xbe320c2d, 0x3dafed85, 0x3e2a6f34, 0x3e1a4d66, 0xbdd0b46d, 0x3d9ebce6, 0xbddd6ee1, 0xbd95d8ec, 
    0xbe3c6a7d, 0x3e043cdf, 0xbdc64b62, 0xbcc60065, 0xbdcf0787, 0x3d5867c8, 0xbdaa3c7d, 0xbe097b4a, 
    0xbe1e0cdf, 0x3c33293b, 0xbe0c0bd1, 0x3e124894, 0x3be8925c, 0xbe0476b7, 0x3e360b6d, 0xbd028d04, 
    0xbc66b906, 0x3dd20db0, 0x3ccfcd03, 0xbe2cdd67, 0xbd9438b6, 0xbd4c0a94, 0x3db17aaf, 0x3c86057e, 
    0x3d0671c0, 0xbd5c0cb2, 0xbe34b93f, 0xbe12cb74, 0x3e07d408, 0x3dacebe5, 0x3d8248f6, 0x3c4b6af3, 
    0x3e01d189, 0x3e082cdf, 0x3d33fa9b, 0x3d94f913, 0x3e0eddc7, 0x3ba64305, 0xbcc665d1, 0x3d63b9af, 
    0x3c7d4653, 0xbcd16b68, 0xbe1ac923, 0x3d3e012b, 0x3d9fd6a7, 0xbe1456c4, 0x3d98a106, 0x3c45ec1c, 
    0x3b2d28ac, 0x3d2593c1, 0xbe081a65, 0xbdf65e33, 0x3d8a5e56, 0xbd7747bc, 0xbd07696b, 0x3d9df9a8, 
    0x3d6f5fdc, 0xbe3a05d2, 0xbd087437, 0xbdc24d42, 0xbdad51a2, 0xbe296a3f, 0x3da6ed67, 0x3c6ba12f, 
    0xbe0791b8, 0x3d00ea26, 0xbd9c066b, 0xbde98179, 0x3d03f535, 0x3d074c67, 0x3e0c2685, 0x3e273e51, 
    0x3cc45ad8, 0xbdb279d2, 0xbdc37427, 0xbd6abdef, 0x3d61101f, 0x3e088f0a, 0x3e049e2e, 0xbd3d08cd, 
    0x3dba64cb, 0x3e204e55, 0x3e238cea, 0xbdb614d3, 0x3e0238fa, 0x3dcc93db, 0xbd4ec7ed, 0xbd2b32c2, 
    0xbe119443, 0x3c9a1163, 0x3d3d8e12, 0x3dcc3524, 0x3c82ab8b, 0xbe04e30f, 0x3e0206ac, 0xbe19e942, 
    0x3e19168f, 0xbd812215, 0xbda97962, 0xbe00b260, 0x3dd2690a, 0x3dcefbf8, 0xbdad70a3, 0x3d181e88, 
    0xbb920e4d, 0xbe323184, 0x3d8c2372, 0x3e3513a6, 0xbc7c34d1, 0xbd1f4c89, 0x3de0bc17, 0xbd89c4ca, 
    0x3de030d5, 0xbdd585f1, 0x3dc53c96, 0x3e01d9e6, 0x3dc31d2e, 0xbe077b1e, 0xbe00c45b, 0xbaab8fe9, 
    0x3cfff2f9, 0x3cacb51b, 0x3d777863, 0x3c49a6d9, 0xbe3946ea, 0x3b4b0dce, 0xbde064e2, 0xbd43d3bf, 
    0xbe11e127, 0x3d5c8f35, 0xbdd78455, 0xbe369b96, 0xbc812333, 0x3e1083f5, 0x3c51f388, 0xbe36bb9c, 
    0x3e095d38, 0xbc3e43c2, 0x3e0aa125, 0x3d8190cc, 0x3d99508f, 0xbd28270b, 0xbd109408, 0xbdbf0eff, 
    0xbe025d71, 0x3d912405, 0x3c3e3e5d, 0xbe170868, 0x3db68492, 0xbdf5ed6f, 0x3e28f7ad, 0x3dcbd70f, 
    0xbd38a14a, 0xbdcc3cc3, 0xbe1cf6c6, 0xbe17bd1d, 0xbe2c0837, 0xbdcbe214, 0x3c98efb8, 0x3dcae150, 
    0x3d85f97a, 0x3df56831, 0xbe3769b4, 0xbe2f6f8b, 0xbe08e60f, 0xbd5effef, 0x3cd12741, 0x3e167257, 
    0xbdae8e4e, 0x3d294113, 0x3de70ab2, 0x3dead3bf, 0xbd625d78, 0xbd7ad837, 0xbd5cea5b, 0x3d4bbd03, 
    0xbc4ceb81, 0x3e19e8bb, 0x3d79ff17, 0x3d935c08, 0x3e003cf9, 0xbe2323d2, 0xbd85590c, 0x3d6dec97, 
    0x3d9152e5, 0xbc59158c, 0x3dd5918e, 0xbdef9c8b, 0x3d9f8396, 0x3d5a0c75, 0x3dcdcf68, 0xbc2ebe90, 
    0xbdda552b, 0x3dd82ef7, 0xbca6acc2, 0xbd3d8ea0, 0x3baaa7df, 0xbda4bd7c, 0xbe0c9f21, 0x3d12a939, 
    0x3e1139d8, 0x3d294b1d, 0xbb5997ef, 0x3ddb23ed, 0x3dfbdab2, 0xbd9fccce, 0xbd06581a, 0x3e1af6ad, 
    0xbe0825f5, 0xbe4a104c, 0xbdedffd5, 0x3c456077, 0xbc1462e1, 0xbe0c911f, 0x3d475806, 0xbe0f01dc, 
    0x3ce53121, 0xbdfee2d4, 0xbdaa0349, 0xbde18612, 0xbe149f5d, 0xbe3908bb, 0x3dc48581, 0x3dd7b8f2, 
    0x3dbe1e08, 0x3e14b328, 0x3e1fbfc6, 0xbd817a59, 0xbdd29d61, 0xbc9104a2, 0xbda7d8a0, 0xbcb7357d, 
    0x3d1a4e50, 0xbe3ae1b5, 0xbd87c370, 0x3db53c69, 0x3de210e4, 0xbe2f2b0f, 0xbdcb0b17, 0xbd0dd947, 
    0xbdbba851, 0xbd6b7bb7, 0xbe1bd414, 0xbb23f43c, 0xbd9b088c, 0x3e0e79de, 0x3e1f99a1, 0xbdc3e9e4, 
    0xbdc4ed27, 0x3e14d9df, 0x3e073100, 0x3ca56aae, 0x3d2b074a, 0xbdbe6cd7, 0x3d78120e, 0xbdadc79e, 
    0xbd4a6fa7, 0x3e023d06, 0xbcf21cbb, 0x3cd41963, 0xbe1edc5f, 0x3c8cf05a, 0x3e12e0b6, 0x3d7d18ce, 
    0x3aa79227, 0x3dec41ab, 0xbdf4631c, 0x3d00d0a1, 0xbd39f69d, 0xbdc14674, 0x3d24cbd0, 0xbe0e164b, 
    0xbdc75930, 0xbdc0bad1, 0x3e0fd912, 0x392786e3, 0x3d9990f9, 0xbc1cf113, 0x3db8aebf, 0x3e13fa5a, 
    0x3e08ce53, 0x3e071183, 0xbe0d6f45, 0x3caac346, 0x3e150a32, 0xbd8abc83, 0x3d750fc6, 0x3e1d130b, 
    0xbd842294, 0x3dad97df, 0x3d88ff6e, 0x3c0e887a, 0x3d8e8a86, 0xbd9d6e2b, 0x3da1017d, 0xbd9ab393, 
    0x3d33b2a1, 0x3de00066, 0x3d4aaa69, 0xbe360ec1, 0xbe1e8871, 0xbd4c84ab, 0x3d88e50d, 0x3d60f60d, 
    0x3dcacf4e, 0x3e131ba0, 0x3e08d967, 0x3d8ce1fd, 0xbe23c00e, 0xbd970774, 0x3e07571f, 0xbd1a3854, 
    0x3e272a14, 0xbd5b71d5, 0xbc9c4cc9, 0xbdb730a1, 0x3e3da5f2, 0x3e0d06c6, 0xbba6f78c, 0xbe1a7069, 
    0x3bbe9c38, 0x3cad0344, 0xbd072303, 0x3d903271, 0xbe2a16af, 0xbd7eea3e, 0x3a25da8f, 0x3dd8b86b, 
    0xbdf78f75, 0xbe1cc9fc, 0xbe389b70, 0xbe2f6f66, 0xbdd07175, 0xbd1d3493, 0xbd67adc9, 0x3e06b414, 
    0x3df87201, 0xbe25f4dd, 0x3da5b7a3, 0xbd39aa33, 0x3c1e377d, 0xbd34a3ce, 0xbde1268d, 0x3cff6fbe, 
    0xbd60268d, 0x3e00db95, 0x3d773de9, 0x3e21714b, 0x3d24beaa, 0xbd400d56, 0x3e1969c3, 0x3c2e8422, 
    0xbd18906b, 0x3e229698, 0xbd93e0cb, 0xbdf0d83e, 0xbc831a1e, 0x3e0f6602, 0xbdd06668, 0xbd6c9cd6, 
    0xbd5e2d9a, 0x3d041772, 0x3dfdda04, 0x3db4ff29, 0xbe2d42e3, 0xbd553e3a, 0xbe22cab7, 0xbe17dd71, 
    0x3d413a18, 0xbe10ff61, 0xbd0f7e09, 0xbca0a689, 0xbe3d32e0, 0x3e294392, 0x3e1ee526, 0xbc629d3c, 
    0xbddbffa4, 0xbc36280a, 0xbe11f18d, 0x3ccc063f, 0x3e21bb95, 0x3de90c4d, 0x3de48ded, 0x3c5b422a, 
    0xbe00331e, 0xbd837e22, 0x3e136ef7, 0xbde35bec, 0xbd05ef03, 0x3dd901ba, 0x3dfe9e56, 0x3d902c61, 
    0x3caed452, 0x3c9a34c2, 0x3d0111a3, 0x3e0265c4, 0x3e1c3799, 0xbe3a0a1b, 0xbe121ea5, 0xbdbdf491, 
    0x3c8a82f6, 0x3e086123, 0xbd403aa5, 0x3de1514e, 0xbdebb228, 0xbe59424c, 0x3d9b5cd9, 0x3e080b38, 
    0xbe08c055, 0x3e21b032, 0xbe0b788b, 0xbdb7b59b, 0x3e141bf2, 0x3d985ea7, 0x3cc15302, 0xbe0fc938, 
    0x3d7df515, 0xbe07df1f, 0x3c940ea4, 0x3d287304, 0xbdf212dd, 0x3dfb4313, 0x3c647e06, 0x3e10ab2c, 
    0xbe303baa, 0x3d37adb0, 0xbdb4a220, 0x3df57111, 0xbe2b5a5b, 0xbda31f6d, 0xbe3d5a2c, 0xbe065d3f, 
    0x3e03d6c4, 0x3c243643, 0x3d350dbd, 0xbd5770e3, 0x3e0efeb8, 0xbd26110c, 0x3de05e1e, 0x3d099dfe, 
    0x3d58a240, 0xbd9cceac, 0x3d206ef4, 0xbe0ecbe0, 0x3c75bfe9, 0x3d14b952, 0x3e2ff661, 0x3e17fc02, 
    0xbe18b093, 0xbc363a18, 0x3d5df019, 0x3c8bebf9, 0x3cad9520, 0xbdfce957, 0x3e1c64f0, 0xbe1f2ad3, 
    0x3d3ad593, 0x3e1a38b9, 0xbc0926a8, 0x3dbb90ed, 0xbc9062bf, 0xbdb3fed8, 0xbdd2f3b8, 0x3ca8a659, 
    0x3e0b9eb3, 0xbe04dbb2, 0x3dbf96b5, 0x3b225115, 0xbe1bbfc7, 0x3beed080, 0xbd5979e1, 0xbe24a742, 
    0x3dc01070, 0x3c1f4abf, 0xbd85aba2, 0x3db37e3a, 0xbd9a13da, 0xbdce37c6, 0x3da8e6fe, 0x3e277293, 
    0xbd76ad1e, 0xbd93fa12, 0xbdd9d099, 0x3e1d13bf, 0xbe1be5f9, 0xbd935332, 0xbbc8d846, 0xbd911a2e, 
    0x3d6a782e, 0xbdd598c5, 0xbe3b25b6, 0xbd8d140c, 0xbdc26093, 0x3e28ac9c, 0x3dff66cb, 0x3e2c582c, 
    0x3e078a51, 0x3cf511ad, 0x3e035f1a, 0xbcf9e416, 0x3dc14d2f, 0xbdaf114f, 0x3d9563c4, 0xbde0cd96, 
    0x3c425317, 0xbd6363b4, 0xbe212d79, 0xbd0a63c5, 0xbe2440f6, 0xbc8e9432, 0xbdb529dd, 0x3d25fba9, 
    0xbcb52832, 0x3d72e13d, 0xbd9d0485, 0x3d4419a3, 0x3e066e21, 0x3e19d0a3, 0xbe00a4b0, 0x3dc3abc9, 
    0x3d9a6664, 0x3db2df43, 0x3c86df6f, 0xbdb97961, 0xbdc4174e, 0xbe2b9a5b, 0x3e26df3a, 0xbe1cb791, 
    0x3d8f7883, 0xbd85093c, 0xbbaae1c8, 0x3e1c0d33, 0x3daeb8e6, 0xbcb93245, 0xbdb7633d, 0xbdbed33f, 
    0x3e1af54e, 0x3dfd157f, 0xbe2c48fa, 0xbe2e0a26, 0x3d7fde38, 0x3e0e2f71, 0x3d702587, 0x3d056a28, 
    0x3d5617af, 0x3e0ca3e4, 0x3dea7d91, 0x3e071278, 0xbb4053e1, 0xbd3964ee, 0xbc33f090, 0xbe1b6300, 
    0x3d8ead28, 0xbde96c17, 0x3d9659fa, 0xbe05f574, 0xbda41219, 0x3df8a2cf, 0x3e12f4d8, 0x3c00d75c, 
    0x3bc54169, 0xbd1a8ce2, 0x3e05b8c9, 0xbcc30a77, 0x3e3588ab, 0x3e3482aa, 0x3d8e2ce8, 0x3d8929f8, 
    0x3e024c34, 0xbd5690be, 0x3e1d0c80, 0xbe2d51b4, 0x3bb8c2ad, 0xbe01c0a2, 0xbe260576, 0x3dad75d3, 
    0xbde06a15, 0xbe150b6e, 0x3e131cee, 0xbe1fc810, 0x3c8b8edf, 0x3dd4d34c, 0xbca08dd5, 0xbe43016d, 
    0x3c915596, 0xbe013027, 0x3d8cf22d, 0xba035726, 0xbd85dbb3, 0xbde5e9b1, 0xbdd0da37, 0xbd728881, 
    0xbdfc9dc2, 0xbe2781d2, 0x3cb175e3, 0xbd897a85, 0xbe17037b, 0x3e4c3121, 0x3da791d4, 0xbe193589, 
    0xbdd7a945, 0x3d5b1fc5, 0x3e192a20, 0x3e213cb1, 0x3e133ed2, 0x3d5fb338, 0xbdb6beed, 0x3dca48c5, 
    0x3c90066a, 0x3d6e7da8, 0x3da056a5, 0xbd05ab82, 0xbdcfd1f6, 0x3e0a021c, 0x3e456ba6, 0xbd8ebb02, 
    0xbc91fe45, 0x3e0a3947, 0xbda0061b, 0xbdeff489, 0x3d1d5f04, 0xbd8e5a24, 0x3dfd2806, 0x3dee5ef3, 
    0xbd9e0618, 0xbd3489a0, 0x3d779e1f, 0x3e2bc08f, 0xbdd1e225, 0x3d5a48c0, 0xbe0fb6e0, 0xbcb84a72, 
    0x3d871ff0, 0xbe0b7fc5, 0xbd028ea9, 0x3dbfe7c6, 0x3de772ce, 0x3e231eee, 0x3e1d5dbf, 0x3c099cc9, 
    0xbe1aab01, 0xbe05b249, 0xbd174004, 0xbdafdd0d, 0x3ccaed39, 0xbe082d68, 0xbcf11e0b, 0x3dc06114, 
    0x3d4b1cb2, 0x3df592cb, 0xbd783bd9, 0xbdf56860, 0x3d9005b5, 0x3c2f83fd, 0x3dcb632c, 0xbe18d15f, 
    0xbdf61c78, 0xbe253c5c, 0x3d39add0, 0x3d83026e, 0x396a4347, 0x3da5f681, 0xbdcb3655, 0xbdebb2fc, 
    0xbd95b93e, 0x3de3fb34, 0x3e1baff7, 0xbd23c368, 0x3e250bba, 0x3cd2760f, 0xbd377d55, 0xbc0d0ff3, 
    0xbd4ad450, 0xbdabc470, 0xbd7cae72, 0xbdda1a1f, 0xbe169c31, 0x3e002974, 0x3c4d253f, 0x3d15d3c9, 
    0x3c0353bc, 0xbd159ca5, 0x3ba914fd, 0xbdf8eeac, 0xbdb32499, 0x3e04d719, 0x3dc17f4d, 0xbd8b52ab, 
    0x3d358838, 0xbda9dec1, 0x3dd811c7, 0x3dc5bb18, 0xbdbe0472, 0x3e21022b, 0x3ce38405, 0xbe07c263, 
    0x3de2fb8f, 0xbd2c8009, 0x3dff7c9d, 0xbdfa7c8d, 0xbe003071, 0x3c2f3d9c, 0x3d054dec, 0xbe2a0016, 
    0x3e18b19a, 0x3d074e1c, 0x3dde594f, 0xbd480bec, 0x3c849987, 0xbde0f880, 0xbd99e0bb, 0x3d277e01, 
    0xbd17ae13, 0x3e2b1d3d, 0x3e01f9dc, 0x3dd1bdff, 0xbc5c7782, 0x3d945353, 0xbc8b29ac, 0x3ce07be1, 
    0xbd99c965, 0xbdb4a900, 0xbc08bbcf, 0x3e1658a3, 0x3dbc5f2a, 0xbd1a5e6f, 0xbe0c9f27, 0x3d814a0c, 
    0x3de26038, 0x3dc592c8, 0xbcddf101, 0xbd592a67, 0x3dc0fd23, 0x3d561ae0, 0x3d90f8f0, 0x3dff4bc3, 
    0xbdc849f3, 0xbcc5967b, 0x3dd99267, 0xbde9893d, 0x3cf47288, 0x3b8ed54d, 0xbd0dfe2c, 0x3b773d2c, 
    0xbda76c4a, 0xbd36ac5f, 0x3de741e0, 0x3d22c6dd, 0x3cfbf345, 0xbd99e5cc, 0x3dd6cd9f, 0xbdd0274c, 
    0x3dbe3462, 0xbdc512fd, 0x3e069035, 0xbdb0f0ab, 0x3c8bf3c7, 0xbe17b5d8, 0x3d81a597, 0x3e172555, 
    0xbe2f5293, 0x3e0c82ae, 0x3cfdb56d, 0x3d61c17f, 0x3de0ba02, 0x3e2d9427, 0x3c2ce94a, 0x3cc28c9c, 
    0x3d04abba, 0xbc72c68f, 0xbd6c02e8, 0xbcb9c695, 0x3e2b8ca1, 0xbe218255, 0x3ce31f11, 0xbe187046, 
    0x3e192af7, 0x3e0e517f, 0x3db7ee25, 0xbd92e480, 0x3d7ce559, 0xbde1d1b0, 0xbd85346d, 0x3dc78cfd, 
    0xbdea8757, 0x3e19a6da, 0xbe120007, 0x3e26b5ea, 0xbdeb8ab3, 0xbdc29511, 0xbe073065, 0xbe3329a1, 
    0xbde5cd10, 0xbd5ec0b1, 0xbd536864, 0x3daaa572, 0xbd87f132, 0x3e188c9e, 0x3d7adccb, 0x3e40774f, 
    0x3cedd4e2, 0x3e0f8114, 0xbd96eeed, 0x3dcc569c, 0x3dc7e212, 0xbe3b02f3, 0x3e293b32, 0x3dc2e0b5, 
    0xbd37dac5, 0x3dcd7fea, 0xbe2ac257, 0x3e15b2a6, 0x3dece932, 0xbc322a8b, 0xbb60ad7c, 0x3e0920ce, 
    0x3e1fbdb3, 0xbd86f60e, 0xbcc76954, 0x3da6e3e4, 0xbb5e6ecb, 0xbdd2d6f9, 0xbd992374, 0x3ceb4fb4, 
    0xbe4046eb, 0xbe060567, 0x3e24cd7f, 0xbd972c13, 0x3d723ef4, 0x3e14d36b, 0x3c8e3716, 0x3dd06990, 
    0xbc4e0fae, 0xbdd7cf44, 0x3ccce322, 0xbd9c9dca, 0xbd215ebb, 0xbd81def7, 0xbd7d2337, 0xbcb0a8cd, 
    0xbc1237b0, 0xbdd4387c, 0xbc940c55, 0xbe26d351, 0xbdd69143, 0x3e1fb0e8, 0xbd9ad505, 0xbc479c8d, 
    0xbd8fb679, 0xbe117cca, 0x3e3047a7, 0xbd08c457, 0x3ca31036, 0xbe054553, 0x3cf52680, 0xbe080561, 
    0x3d650692, 0xbe39da90, 0x3e0479cb, 0xbe1b6961, 0x3e1ce57d, 0x3debd3ac, 0x3db187c1, 0xbe2a574a, 
    0xbdedd4ce, 0x3dc2f115, 0xbd18f5fc, 0xbdbcc47d, 0x3d8b1a3b, 0x3cb07ea5, 0xbdbe41b8, 0x3dd2669d, 
    0x3db6a90f, 0x3d6302f2, 0x3d17dad3, 0x3d8a7cdf, 0xbd98960e, 0xbd3e9712, 0xbe0a9e7d, 0xbdfcb88d, 
    0x3e18d111, 0xbd5277e1, 0xbde4e364, 0xbcb96f79, 0xbdb72c08, 0x3dd9337b, 0x3d91bff1, 0x3c16d019, 
    0xbdb4120f, 0xbe028b43, 0x3e322c9a, 0xbd46f64a, 0xbd436ae6, 0xbe0ec14d, 0x3d7cde78, 0xbd151fa3, 
    0x3d140b0b, 0xbd41c15b, 0x3d9061b8, 0x3cb31bd3, 0xbd9162d1, 0x3d4bdc5b, 0xbdd17acb, 0x3e07956b, 
    0x3c70a968, 0xbe21ebea, 0x3dbc0a3a, 0xbe12eb47, 0xbdc77e9f, 0x3d89862a, 0x3c37842b, 0xbd7f8ef7, 
    0x3d7deeae, 0xbe2190c2, 0xbe22ad07, 0xbd45574a, 0x3cc47826, 0xbc587b18, 0xbe1b6886, 0xbe1f0aef, 
    0xbd9b2009, 0xbe08a3f8, 0x3d4cdc84, 0xbc9604d6, 0x3dbc1143, 0xbe2bdb2e, 0xbdec2405, 0xbe0dfb7a, 
    0x3e003b7b, 0x3d82d0f9, 0xbe027758, 0x3ba6aad4, 0xbd0ec601, 0xbe3f40d3, 0x3c41921c, 0x3dcdf10c, 
    0x3cc500fc, 0x3d1c21f1, 0x3c97b0be, 0xbd0d800e, 0xbd8388e9, 0xbdd4fca8, 0xbdbc8765, 0xbd985cd2, 
    0x3e1e5d1c, 0x3c926e3f, 0x3bb3d2d9, 0x3e0b1cac, 0xbc9dba12, 0xbe17e727, 0xbe114ca5, 0x3d061397, 
    0x3cc44506, 0x3e23c02f, 0x3dc6c418, 0xbcc0c25c, 0x3d30d348, 0x3e15ff31, 0x3e16ab20, 0xbdae7636, 
    0xbd31991c, 0x3ce5f8ce, 0xbe30aa5c, 0x3c886a70, 0xbe26ae90, 0x3e008ebb, 0xbdecfdfd, 0xbca3cf05, 
    0x3d67b7f3, 0x3db5bee3, 0x3dcd52d4, 0xbe0fade1, 0xbe2ffebe, 0xbe2d4947, 0x3ddec354, 0xbda20666, 
    0xbc9925a0, 0x3de5587f, 0x3d6fc037, 0xbe3db327, 0x3d4a175a, 0x3d3fdec0, 0x3e116178, 0x3dfd1cd5, 
    0xbd101d6c, 0x3df88ef6, 0x3decf258, 0x3db6113d, 0xbdd05932, 0xbd6cefab, 0xbe0a2598, 0xbe022c3a, 
    0x3cb59354, 0x3dfbfe5c, 0x3e292d5c, 0x393b3dd8, 0x3dfff728, 0xbd6b706e, 0xbcf29e9f, 0x3db6488f, 
    0x3dcca6be, 0x3d944935, 0x3e076dca, 0xbe0d33d8, 0xbdcd296c, 0xbdbdb625, 0x3c407115, 0x3dd94605, 
    0xbe257d5a, 0xbe0e6d06, 0xbd7608d3, 0xbe2bccec, 0xbd101b75, 0xbd256837, 0xbe0d389e, 0x3da78a4c, 
    0x3d8ded99, 0x3cb0d150, 0xbe238a4c, 0xbda5f779, 0x3dd1ed89, 0xbdfcac40, 0xbd94cbc7, 0xbe028741, 
    0x3dee7335, 0x3df1f904, 0xbd4d4d4e, 0xbcf7d572, 0xbb8cac7c, 0xbd8dc202, 0x3e1c29c7, 0x3d9e3826, 
    0xbd7de85b, 0xbb48cce9, 0xbd009bc6, 0xbd207b0e, 0xbc1c4bf8, 0x3d89ba4e, 0x3de02e37, 0x3c348154, 
    0x3de5cdd2, 0x3db103ef, 0xbe11ff00, 0x3d42732b, 0x3da01d8e, 0x3c32a5b3, 0x3df250e7, 0xbd9c4998, 
    0x3c923fb7, 0xbe1f56ce, 0x3e017b17, 0xbe0ffa47, 0x3db8c302, 0x3d8c70a3, 0x3d9dcff5, 0x3da36208, 
    0x3e0400b7, 0xbd935977, 0xbda613eb, 0xbd3a7073, 0xbde5e56b, 0xbe416865, 0x3dee5f8b, 0x3c15c54b, 
    0xbe1bac71, 0xbde6951c, 0xbe20b6f6, 0x3e07e95e, 0xbdf59af2, 0x3e2cc9bd, 0x3e2559bd, 0xbe31183d, 
    0x3d18059c, 0x3ca6a8a8, 0xbd192547, 0xbdf85138, 0xbe162530, 0x3d6cfa1a, 0xbe28a9a6, 0x3de7b131, 
    0xbd04889e, 0x3e0ab6fd, 0xbe385537, 0xbcb9004f, 0xbdbf7ce3, 0x3d5724df, 0x3e1c64a3, 0xbd4c5795, 
    0x3d9c73dd, 0x3cbe4a8e, 0xbcd39c53, 0x3dbc1c86, 0x3d9ba483, 0x3d8610ba, 0x3d0f6c75, 0x3df9e0fd, 
    0xbe1334ae, 0x3e2bf906, 0x3dd659b2, 0xbdad078e, 0x3e1af29f, 0x3d0193d1, 0x3c5c518c, 0xbd641265, 
    0x3d4830cf, 0x3cc6e5e2, 0x3df8aa56, 0xbc91fbef, 0x3db283ad, 0x3d2c9f14, 0xbe07a030, 0xbc97eb66, 
    0xbc9037c9, 0x3cbfea76, 0xbb97518c, 0xbdd0c6f9, 0x3e3ae2e7, 0x3d7f1917, 0x3e13e518, 0x3d5558ac, 
    0xbc6c304d, 0xbe01c0c0, 0xbdbddfaa, 0xbd37c164, 0xbd64dae4, 0xbe2d66ef, 0xbe10fca6, 0xbdf918e1, 
    0xbdbea969, 0x3df52199, 0x3e0ee7d9, 0xbe13093e, 0x3ca4655b, 0xbc5d99bc, 0x3db8c2d7, 0xbe07cfa9, 
    0xbe166e29, 0x3dbcbce7, 0x3e1eee62, 0x3de65b0d, 0xbde09066, 0xbe1921cc, 0x3e30c425, 0x3dad3e79, 
    0x3e100cdc, 0xbde5c520, 0x3c76ede0, 0xbe154e55, 0x3dc79f3f, 0xbbbead37, 0x3df914b5, 0xbccf2fc2, 
    0x3ba69015, 0x3ddc1932, 0x3d8a774d, 0xbd23d8fa, 0x3c178fe4, 0xbc81ef1a, 0xbd9c1f9c, 0x3df3dbd0, 
    0x3e2e6fc9, 0x3e384c1e, 0xbdacc5fa, 0x3d859e16, 0x3dc60d85, 0xbd28a337, 0xbd3729bb, 0xbd860b59, 
    0xbd2d5398, 0xbc600ada, 0xbdce0995, 0xbd419386, 0xbd125731, 0x3e28f286, 0x3994c514, 0x3e1b9524, 
    0x3d77bc6f, 0xbd447906, 0x3c8ab987, 0xbd0dfaa9, 0x3ce6becc, 0xbde42a80, 0xbe5d0b39, 0xbe30c55b, 
    0x3dcb13db, 0x3d823724, 0xbd6098cf, 0xbc518a4f, 0xbcf83f21, 0xbe16d2a3, 0x3e05e291, 0xbc5a3e10, 
    0xbd395aaf, 0x3d5057d1, 0x3e19fca0, 0x3e0e1d6f, 0x3dcec07a, 0x3dd1d551, 0xbde050ee, 0x3bc4bec4, 
    0xbd97f960, 0x3e2a6747, 0xbdd1b47c, 0x3d7d3b16, 0x3d558fff, 0x3e1784bd, 0x3e08c5a2, 0xbdf4295f, 
    0x3c28d08a, 0x3d873640, 0xbdfb0555, 0xbc9205a5, 0x3d3207c4, 0x3bb7a0e0, 0xbe5669ed, 0x3de6341d, 
    0x3dfaa2c2, 0x3c91694a, 0xbd385433, 0x3d34f207, 0x3d2d8c74, 0xbde299cb, 0x3d78620c, 0x3de698fa, 
    0xbde4ea80, 0x3ce2ad66, 0x3d997ed0, 0x3d40f366, 0xbd224967, 0x3e1334ce, 0xbdca1ea4, 0xbcb58e58, 
    0xbe2a9369, 0x3dd58577, 0xbd84fb23, 0xbda3ca8a, 0x3d0a7afe, 0xbd8f5f0f, 0x3e2470be, 0xbdabd99c, 
    0x3dd6a4dd, 0xbd1114ab, 0xbd344ecb, 0xbd952647, 0x3d87f5b3, 0xbe252c71, 0xbe2477e2, 0xbd47ea12, 
    0xbe4183fb, 0x3e0999de, 0x3d164abc, 0x3c98dfdd, 0xbd507bfa, 0xbdb4a725, 0x3d80c918, 0x3dc2696e, 
    0x3d126e2d, 0xbb990b99, 0x3e20ffa9, 0xbdebeed5, 0xbdec0239, 0xbd9714be, 0x3d84fda7, 0xbcb070bb, 
    0x3df5c22d, 0xbb70ffeb, 0x3db29003, 0x3d86ede0, 0x3e1b396a, 0xbce30861, 0x3cf852e4, 0xbd75d40b, 
    0xbe3ac1fa, 0x3cd2ee63, 0xbd89da2f, 0x3d38e262, 0xbe407a93, 0xbde06de7, 0x3db2eded, 0xbe3cd806, 
    0x3e0a6827, 0x3de9e4fc, 0x3dd79c7e, 0xbe105f6e, 0xbe210c54, 0x3d137701, 0xbe47ecf4, 0xbd336eaf, 
    0x3e16aa5d, 0x3db4e87f, 0x3c6781f3, 0x3d9236f8, 0x3db82330, 0x3d51cdd3, 0x3d47643b, 0x3e012e23, 
    0xbe30ba04, 0x3d8a9188, 0x3df157e4, 0xbe092fbd, 0x3e142daf, 0x3e07c8df, 0x3d9f589f, 0xbdbf94ea, 
    0x3dbd4e40, 0x3b96f1df, 0xbe2e0e9d, 0xbcfad522, 0x3cca2839, 0x3e169755, 0x3d2d90a4, 0x3dc44e5e, 
    0xbe2a3d23, 0xbe24b760, 0xbe0fd7b3, 0x3e09cde6, 0x3e20fe2e, 0xbe18a0bb, 0xbe45c80f, 0xbd38c0ef, 
    0xbdb85a79, 0x3dc8a9c9, 0x3de1d2ee, 0x3c1e4280, 0x3d3e3c7e, 0x3bbfc955, 0xbc640101, 0xbdb98945, 
    0x3dc18c9a, 0x3dc2f09b, 0x3d954e71, 0xbe348dd6, 0xbd7b2278, 0xbc00ee27, 0x3ba52527, 0x3c00024d, 
    0x3dd7bacd, 0xbd17cacc, 0xbde44dc1, 0xbd3534a1, 0xbb336e05, 0x3df106e2, 0x3e33dfe3, 0xbdc67923, 
    0xbd78a909, 0x3dfeef7e, 0x3c49b5f2, 0x3e405565, 0x3c924acf, 0x3d1c7727, 0x3da3caf7, 0xbe2c24e5, 
    0x3dbcbd65, 0xbc5f84b1, 0xbe293c2c, 0xbc2a3f2d, 0xbd4311f5, 0xbb55e988, 0xbdd026d6, 0xbd11df58, 
    0x3dd77e1e, 0xbd20f8de, 0x3e0bbd12, 0x3da4fab9, 0x3a282819, 0xbd753f5a, 0x3db8e7d7, 0xbd904957, 
    0xbdc9a481, 0xbd94fa8f, 0xbe210914, 0x3e43ac51, 0xbe28d845, 0x3e01b8ab, 0xbde48ed8, 0xbd99b46c, 
    0x3dfd215b, 0xbceb2ca4, 0xbe032deb, 0x3b7063eb, 0x3cf298c6, 0x3e04a959, 0x3ba2f35a, 0xbd8ec761, 
    0x3d52909b, 0xbe1902e1, 0xbe31714b, 0xbdf63051, 0xbdac54f4, 0x3d0f42f1, 0x3c97b2a1, 0xbdaeb2b6, 
    0x3e253f0a, 0xbe01ea0a, 0x3dc530b1, 0x3e1ccc14, 0xbc92b202, 0xbd5fb0f7, 0x3de343a5, 0xbdd0f1cf, 
    0x3e20077f, 0x3e3680e2, 0x3dd1db43, 0xbe1026d6, 0x3e1fa915, 0xbddf41cd, 0x3e1cc97e, 0xbe040c5d, 
    0xbdf5581e, 0x3e03f151, 0x3dda9530, 0xbe178785, 0x3d470d60, 0x3dfd3aba, 0x3dd8a6cb, 0xbe234ce0, 
    0xbd403cd9, 0x3e11b848, 0x3e234eb5, 0x3d69f555, 0xbc430b48, 0xbdb2bd75, 0xbd5a09ef, 0x3d1f66eb, 
    0xbcfe47c5, 0x3dba3193, 0x3e28552a, 0x3e0b4744, 0x3c90874e, 0x3c8560fa, 0xbdf3ff34, 0xbd8f3306, 
    0x3e10a32d, 0x3e073fc9, 0xbe14d2fa, 0xbe115f5c, 0x3e0fc01b, 0x3c99d165, 0x3e09dd20, 0xbd0813f6, 
    0xbc12600b, 0x3d37cf90, 0x3e0470fc, 0x3d7593b5, 0x3e16453b, 0x3d9f4bf6, 0x3c6a7e34, 0xbd0ec376, 
    0x3cc7109f, 0xbdbed600, 0x3e0312dc, 0x3e03bb81, 0x3e05dc11, 0x3d61dce0, 0xbd00de88, 0xbd9770d5, 
    0xbdbca87c, 0xbd6b5bab, 0x3e2ae623, 0x3cf6a2c0, 0xbe2ecba7, 0x3dffa871, 0xbd5d932c, 0xbe2a2c18, 
    0xbe0462e9, 0xbd969e48, 0x3dbb0f33, 0xbd7df5c9, 0xbe3bf11f, 0x3e2d1cd8, 0xbd999d7d, 0x3a9aff47, 
    0x3dc55b42, 0x3e0f62ad, 0x3cc7b9f7, 0x3d3074ad, 0xbd620467, 0x3da10e8e, 0xbdf72d4c, 0xbe1ae0ff, 
    0x3df14f30, 0x3d68efa0, 0x3dbf916d, 0x3dd869fe, 0x3da17149, 0xbe3e4b89, 0xbd83fe40, 0x3dd977ab, 
    0x3e295878, 0xbbe5a540, 0x3e29fc8e, 0x3e04ec08, 0x3df7eafb, 0x3deadd91, 0x3e37fb3a, 0x3d48a32f, 
    0xbd01f437, 0x3c3323a4, 0xbd0b627d, 0x3dd4d71e, 0xbe3575b7, 0x3dc0a6d0, 0xbdcc3156, 0x3deb850c, 
    0xbce6094f, 0x3e177649, 0x3e1d485c, 0xbdfa9a28, 0x3ddb2e84, 0x3d6940dd, 0x3e2637b2, 0x3d86fb90, 
    0x3d02ea16, 0x3cb19134, 0xbe076c17, 0xbe33de2f, 0xbd909fc5, 0xbdb5b483, 0xbdb97c31, 0x3da221b0, 
    0x3d01437e, 0xbe18be38, 0xbd11bb7e, 0xbe063da6, 0x3cc1cc72, 0x3def8447, 0x3df5a0e0, 0x3d407edc, 
    0x3e3cffc5, 0x3d9b1c1b, 0x3c0cf860, 0x3da53aa6, 0x3e44f8ed, 0xbc31ecbd, 0xbdab6435, 0xbe237a31, 
    0xbe15eb9d, 0x3db652c5, 0x3dc6da38, 0xbd02a48e, 0xbdf78bad, 0x3b57b18a, 0x3d38d1ea, 0x3e01c588, 
    0xbd3d9bc4, 0x3d5c9d09, 0x3e4e449e, 0x3ddb8bdc, 0x3e0e8095, 0x3e2530a8, 0xbce8c1d6, 0xbbf63295, 
    0x3cdd9bc9, 0x3dfb8f8b, 0x3d7ed309, 0x3d505adf, 0x3e21673d, 0xbc280da0, 0x3ce5421d, 0xbe06497f, 
    0xbdd99611, 0xbe2669f4, 0x3c2ffef8, 0x3dc0d3b6, 0xbc7c0058, 0xbd090234, 0x3ba9f5c4, 0x3da515b5, 
    0x3e06637f, 0xbd305b80, 0x3cbce7cd, 0x3cab8eaf, 0x3c19fdc9, 0x3dd3e287, 0xbdb56bdf, 0x3da783a1, 
    0xbdd752bf, 0x3e2addae, 0x3e2872b3, 0x3c0cb0c9, 0x3d5ef00f, 0x3e1419bb, 0xbdf1b95b, 0x3d50ef52, 
    0xbcd58d68, 0x3b26ee2a, 0x3dbf51e8, 0x3d1bbc01, 0x3c3a12d0, 0xbda8c06b, 0x3d0f5fb8, 0x3e211382, 
    0x3d8c1dc1, 0xbd8c6d35, 0x3ceda0b7, 0xbd03ca1c, 0x3dd70925, 0x3d7a5384, 0x3dce5c3d, 0xbdcb6724, 
    0xbd975fe7, 0xbddf9652, 0xbda5e78e, 0x3e3a73ca, 0x3dca22ca, 0xbd21fd5d, 0xbdb3d7bc, 0xbe1963b3, 
    0x3cd58ce4, 0xbdff6e34, 0xbdcface3, 0xbe274522, 0xbe08d39c, 0x3de4a309, 0x3e17fabf, 0xbdfaa1fc, 
    0x3dd9acd6, 0xbd31033f, 0x3cea6d8c, 0xbe074183, 0x3e01ca83, 0xbe036a06, 0x3d3d67fa, 0x3c64fc44, 
    0x3cb80b5e, 0xbe216d2d, 0xbc26a460, 0x3e10dd55, 0x3e22c423, 0x3e0a1412, 0xbe0b6f5f, 0xbcba867c, 
    0xbe1e838d, 0x3dfab910, 0xbddd66c0, 0x3d80a3fb, 0x3e235536, 0x3c51891c, 0x3d0c847c, 0xbdc1bd81, 
    0x3dc1f223, 0xbcc36b2b, 0xbca0bf5e, 0xbe358e2e, 0xbbdfa956, 0xbc742cf1, 0xbe0809c9, 0xbe03a58f, 
    0x3e0874aa, 0x3d8f63d0, 0xbd90ddb9, 0xbdd9fa43, 0xbc54dfcc, 0x3db0aea4, 0x3e129a25, 0x3c327272, 
    0xbc74b50a, 0xbd95abcd, 0x3da4c6a0, 0xbdd9c6f9, 0x3e182991, 0x3e32801e, 0xbe050352, 0x3c478478, 
    0xbe36e663, 0xbe2822a5, 0xbcc67dec, 0x3e1a6fcd, 0xbd5db915, 0xbdbfdce1, 0xbddada81, 0xbdc3445b, 
    0xbda5a337, 0xbc5f6d00, 0xbdab87cc, 0x3c0a15c3, 0x3e121353, 0x3dfb3844, 0xbe013d57, 0xba3e98b6, 
    0x3e2dc6a8, 0x3d4706ce, 0x3e2c5756, 0xbceff997, 0xbd4dec3a, 0xbd74bb22, 0x3ddc95a7, 0xbd812a7d, 
    0x3d8db9ef, 0x3dd5558f, 0x3dd01f8e, 0xbb005280, 0x3e579540, 0xbe2214cb, 0xbcef9c65, 0xbd29ee20, 
    0x3c67464a, 0xbd5630c1, 0xbe38c264, 0x3d9c02cb, 0xbc93b623, 0x3c900cf9, 0x3e051e05, 0x3e1b1e44, 
    0x3da35545, 0x3da1520d, 0x3dfe20fd, 0xbdaa0640, 0xbcbb6990, 0x3e008386, 0x3e19d7a8, 0x3d422ccb, 
    0x3d3a9dbb, 0x3ceefb7e, 0x3b1ca70c, 0x3d48e97a, 0x3e002500, 0xb99fd3a7, 0x3df5a864, 0xbdd1b76e, 
    0x3e09cdd4, 0x3d15e8c9, 0xbe01f645, 0xbd6bc1bf, 0xbdcdc14d, 0xbe313d87, 0x3e20c6d8, 0xbc7a286e, 
    0x3d9af45a, 0xbda519a7, 0x3d80e416, 0x3d45f975, 0x3c8090d9, 0x3e02a750, 0x3cbf8001, 0x3df31320, 
    0xbe0bd8fc, 0xbdd10f0e, 0xbdca10b3, 0x3e1dd05d, 0x3dfdfc35, 0x3da6c949, 0xbe1e4073, 0x3d8051fa, 
    0xbaba27c4, 0x3d88a651, 0x3dc86bcf, 0xbe036ef8, 0x3d165c93, 0x3e1bb4a0, 0x3db9fac9, 0xbcc4d925, 
    0xbe10ccda, 0x3d87dfc4, 0xbde00d77, 0x3df1fa41, 0xbb729688, 0xbe075d9d, 0x3e2534fa, 0xbd144c7b, 
    0x3db9797b, 0x3c8a5caa, 0xbd9039ca, 0x39881863, 0x3da91a08, 0xbd593ec6, 0x3e0db2c6, 0xbe07b25e, 
    0xbd37c990, 0x3e01a89b, 0x3de2f112, 0x3e382119, 0xbd76df4b, 0xbd22a15a, 0x3e10cc3f, 0x3dc35e71, 
    0x3e157d2f, 0xbe0fbfd6, 0xbd061056, 0x3d9d14a2, 0xbdd4379e, 0x3d98c253, 0xbe2cb644, 0x3daa33e5, 
    0xbd393cdf, 0x3de505fe, 0x3d540815, 0xbe253953, 0x3cd0f7d3, 0x3dc380a2, 0x3e241a3c, 0xbc78e25c, 
    0xbc881635, 0xbc43ec8b, 0xbce07339, 0x3ddc11cc, 0xbcc83b26, 0x3db08ad8, 0x3df28475, 0xbd25cc52, 
    0xbe3e9c64, 0xbcb364cf, 0x3dca9b4e, 0xbe360ee2, 0xba4a39c5, 0xbe2047be, 0xbe0299c7, 0x3e1c243c, 
    0x3b266f7c, 0xbe12da14, 0xbca04a43, 0x3e40b972, 0xbde816fe, 0xbdd65239, 0xbd927dc3, 0x3d40850b, 
    0xbd775f23, 0x3e22db16, 0x3d70a7fb, 0xbde0983d, 0x3e29ed91, 0x3d8e6c6a, 0xbd9c6e97, 0xbdbead68, 
    0x3c9d2195, 0x3d0742ca, 0x3dab4c82, 0x3dfb6753, 0x3e385f62, 0xbd09d933, 0x3dfac341, 0xbd27ee6e, 
    0xbe449d62, 0xbc6609eb, 0xbd44164f, 0x3dd4f32f, 0x3e0cd8bd, 0x3e0a164a, 0x3e30cedb, 0xbdb056ae, 
    0x3d8c2c55, 0x3deb8c10, 0x3e22a9e6, 0xbdc26dfb, 0xbd95f5a7, 0x3d4d8e55, 0x3d81c30a, 0xbd846ef8, 
    0xbde43200, 0x3e2fa653, 0xbd43c3cf, 0x3cee79f5, 0xbacc3553, 0x3c550395, 0x3e1eaa77, 0x3d30d0ee, 
    0xba95fddb, 0xbd32fbc7, 0x3db967d2, 0xbdcdc267, 0xbc01e77c, 0xbd77f505, 0xbd873804, 0xbb612a04, 
    0x3da30164, 0x3dde6a99, 0x3de6d2d1, 0xbda8d976, 0xbe277006, 0x3db38dfb, 0xbe0ac599, 0x3dad325c, 
    0xbc8b2cff, 0x3df40fcb, 0xbdb1f6ba, 0x3e01b3c3, 0x3da075d4, 0xbe0c9247, 0xba89f053, 0xbe0e6c1f, 
    0x3c4c86d9, 0xbc63b92f, 0xbe095f5a, 0x3de6b97c, 0x3e447dc3, 0xbc46398a, 0xbda4ca16, 0xbd080245, 
    0x3da47fc5, 0x3daf2846, 0x3c95f43e, 0x3d0aa196, 0x3d83a213, 0xbdb8147c, 0x3d5bb491, 0xbde56a12, 
    0x3d9f1242, 0xbd9332f0, 0x3c26120a, 0x3d2f7a45, 0xbe325951, 0xbd57e20c, 0xbd96301b, 0x3e008713, 
    0xbe1106d8, 0xbd6bb918, 0xbdad09bc, 0x3e1c272e, 0xbd1107f0, 0x3cbe86a3, 0xbe12aee7, 0x3d95ef35, 
    0x3e221ee7, 0x3dc79095, 0xbd902957, 0xbd76b611, 0x3e0ae747, 0x3df8d0ac, 0xbe1299c8, 0xbde95214, 
    0x3de9f5d2, 0xbdcd989e, 0xbd48ef62, 0x3dd0d23b, 0x3de59676, 0xbd81f222, 0x3e047f7b, 0x3c843f3b, 
    0x3dfdcbc9, 0xbe071aab, 0x3dad0462, 0xbd9bab10, 0x3e0c54b8, 0xbd9c171c, 0x3e1ec03b, 0xbd824f55, 
    0xbd84b58b, 0x3d9cc895, 0x3da0c10f, 0x3e250408, 0xbd289c90, 0xbdcb32cd, 0x3e22f23e, 0x3d94878a, 
    0x3d9559b2, 0xbcd5a280, 0x3cd65b54, 0x3e17a4b6, 0x3e3e447f, 0xbe282402, 0x3df489bb, 0xbb77d59c, 
    0xbdd0461c, 0xbd2555da, 0x3e21064d, 0xbe1442c3, 0xbd604bde, 0xbd9d5257, 0x3de3813a, 0xbdae164e, 
    0x3d17b04d, 0x3dd7367a, 0x3b613493, 0xbdb7f264, 0x3d813edb, 0x3dbf137d, 0xbe22b85e, 0x3e02d3c5, 
    0x3d55f210, 0x3ca9f863, 0xbce16436, 0xbd045b3c, 0x3db03b47, 0x3ddfa52b, 0xbcdb5a4c, 0xbcf70c6a, 
    0x3d29f0fb, 0xbd77abe7, 0x3db7d3cd, 0x3db92eec, 0xbdec778d, 0x3dea28bc, 0xbd887086, 0x3d11bd02, 
    0xbd319576, 0xbd740375, 0x3d8ef284, 0xbdbf2877, 0xbc69e75e, 0x3de2e88b, 0xbcdc9cc1, 0xbe2051ec, 
    0x3ce73051, 0xbde5ced7, 0xbdc4bb21, 0x3e0d706c, 0xbdfe5449, 0x3d78eb55, 0x3cba66f5, 0x3d367d3c, 
    0x3c08f2cf, 0x3d9e01c8, 0x3e163f12, 0xbdcf49e2, 0xb9a3ae1e, 0x3d3c2380, 0xbe19aeb6, 0xbd1e483c, 
    0x3d94f6b0, 0xbdd2782c, 0xbdb5b9a5, 0xbe0d5569, 0x3e3e7c19, 0xbdad8f93, 0xbe4151c8, 0x3e03c568, 
    0x3da3f395, 0x3e11c516, 0x3d8f93a5, 0xbd149548, 0x3db9794e, 0xbe30017d, 0x3e12df94, 0xbd388fc6, 
    0xbe136cb7, 0xbdcb8e81, 0xbc9bf3a6, 0x3e0d7dd4, 0x3e01b707, 0x3de07286, 0x3dc60b38, 0x3e160535, 
    0x3d9ef954, 0x3bdb2e4a, 0x3d27a7ac, 0x3e1f0c33, 0x3c25d8b8, 0xbe017e93, 0xbc738f11, 0x3e2b959c, 
    0x3d7de323, 0xbc6b86fa, 0xbc3173f6, 0xbe133cce, 0x3e325504, 0xbbb1fc94, 0xbd24859b, 0xbd83be41, 
    0x3d96682b, 0x3dd8a719, 0xbe1e3308, 0x3e13546a, 0x3e12fba6, 0xbe3b6d28, 0xbe367ae0, 0xbd87e00b, 
    0xbd7ca0b1, 0x3e1667ae, 0xbdafb5b4, 0xbde5cdde, 0xbd6ec1d8, 0xbda2fd9c, 0xbdb0950d, 0x3982389a, 
    0xbd59bba5, 0xbcbdb46b, 0xbe1912a2, 0xbd727a76, 0x3e2283e6, 0x3d7a0910, 0xbd254b84, 0xbdd76a6b, 
    0xbdf6c92a, 0x3e0319f6, 0xbcc89b5e, 0xbda4e419, 0x3d8d471e, 0x3e2b5acd, 0xbc905438, 0x3e14ecbe, 
    0x3d9deb91, 0xbcfbb08d, 0x3d089cf1, 0x3c6948f1, 0x3dcef74a, 0xbe229235, 0x3da72211, 0x3e0a3052, 
    0x3e149474, 0x3e21e5d4, 0xbe25806f, 0x3e2d389a, 0xbde897a7, 0x3dd29b0b, 0xbc6adead, 0xbce281a4, 
    0x3d1adc37, 0xbdacba5f, 0xbbaa6dfe, 0xbd5f5145, 0xbe0a9d91, 0x3d9c35d7, 0xbdf7b707, 0x3df4fc25, 
    0x3a9c4719, 0xbe0abee0, 0x3e227a6c, 0x3d8d1c2d, 0x3e2ea209, 0xbe422673, 0x3de83bb9, 0x3c7add27, 
    0x3d15bee6, 0x3ddceb4c, 0xbbc2e059, 0x3cd7f626, 0xbd9a6024, 0x3dc144ca, 0xbd1a93a0, 0xbc40c030, 
    0xbd5dcc45, 0xbe0c8d5d, 0xbdb954d2, 0xbd10da15, 0xbd15b597, 0x3e0acfdd, 0x3c1cf6f2, 0xbda6f885, 
    0x3e3f6995, 0x3d1ac856, 0xbdf2ca42, 0x3d320784, 0xbd7f4f58, 0x3d50fb37, 0xbe037b73, 0xbe1c8429, 
    0x3d9db3b7, 0x3e3a9bc0, 0x3dc3b0d8, 0x3db6d624, 0x3e326543, 0xbe26bddd, 0x3e32b086, 0xbbb46c05, 
    0x3dcdca7a, 0xbdeea1f0, 0x3e12d1f2, 0x3e0916e8, 0xbdca5329, 0xbdcab600, 0xbe0de1ca, 0xbdd8744d, 
    0xbdcafd8f, 0xbded1982, 0xbd2eceb1, 0x3e2095be, 0x3da3f5a1, 0x3d242e0f, 0x3d715953, 0x3d84b134, 
    0xbe105513, 0xbb666eac, 0x3e0cfe11, 0x3d9d8298, 0x3dcdf912, 0x3e0a4d29, 0x3e02bf9f, 0xbe0dba8e, 
    0x3e29c7ec, 0xbd6ff6ba, 0x3da503e3, 0x3d774c55, 0xbd46924d, 0xbdda173b, 0x3e139369, 0x3dcc25b5, 
    0xbc539f64, 0xbe044a65, 0xbd30d104, 0x3e1441c9, 0xbd1fac95, 0x3d41e7b6, 0x3de38d5a, 0x3e183732, 
    0x3e0c103a, 0x3c0f02cd, 0xbddda77b, 0x3e1f07c2, 0x3e0b0834, 0x3d249470, 0xbd1255db, 0xbe2bb959, 
    0x3e05008c, 0xbdefe814, 0xbdbf9255, 0x3d07b4f0, 0x3db954cb, 0x3ca8a2ac, 0x3da7230c, 0xbceb3889, 
    0xbcf9c7f8, 0xbe2ba7b1, 0xbe32bdc2, 0xbdc4af92, 0xbcaaa089, 0x39e6df99, 0xbe0419d7, 0xbe30da16, 
    0x3bde2c70, 0x3dbd06dc, 0xbdcf1eff, 0xbdb91a40, 0x3e338dc1, 0xbd3cb6f9, 0x3db2d9c3, 0xbd1c47b5, 
    0xbe19850e, 0x3d22c461, 0xbe0e501e, 0xbe0b564e, 0xbdde762a, 0x3d1776ab, 0x3dc09df1, 0xbe1ee4bc, 
    0xbda99269, 0xbe0a9669, 0x3d652d89, 0xbd484392, 0x3e124ad9, 0xbd2e2a2d, 0x3d1508b8, 0x3d6b9f6f, 
    0xbe2b5cd4, 0xbe2d2e38, 0x3e0003b0, 0x3bb90d05, 0x3dc00b2b, 0xbc51789a, 0x3e2c372c, 0x3dc6f817, 
    0xbd6b7981, 0xbe213c2a, 0x3daae4e0, 0xbc9a67ef, 0x3c81b321, 0xbdb55bb9, 0x3de70268, 0x3b24879e, 
    0xbdffcd33, 0xbdd23f13, 0xbe208d59, 0x3dba34d6, 0x3aac517e, 0xbe0b4d92, 0xbd91074b, 0x3dfd2538, 
    0x3e229bc2, 0xbe19d7a1, 0x3cd9c089, 0x3d9254a6, 0x3d2c8ca0, 0x3e1e9c7b, 0xbdaa0d97, 0xbdd9fe0d, 
    0xbc01d650, 0x3c25e5ef, 0xbcb1d138, 0xbd327b99, 0xbd644d2b, 0xbd9763a9, 0xbd6f8599, 0xbd7ffda1, 
    0xbdfbd944, 0xbd8d6788, 0x3d66e358, 0xbddfeec9, 0xbdf37cdc, 0x3cf2e3e7, 0x3c0bd321, 0xbde31e0d, 
    0x3dbf5be0, 0x3d41773d, 0x3cd0b6cc, 0xbe5bf73b, 0x3e1be228, 0x3e134237, 0x3d209f4a, 0xbd333821, 
    0xbe013e51, 0x3bd1e90c, 0x3dea4ab1, 0x3de9feee, 0xbe022e6c, 0xbe2cc9bc, 0xbcc6e1f8, 0xbd2e28d4, 
    0x3def1b18, 0x3e011d7c, 0xbd829af7, 0x3d4aec40, 0xbd1c6906, 0x3cda7ea9, 0xbd83e348, 0xbdda1256, 
    0x3e0546b9, 0x3d35e78b, 0xbdc92277, 0xbdfacb12, 0x3dac902b, 0xbdeca9b2, 0xbb0f8c83, 0x3dab28c7, 
    0xbe2e46b6, 0xbe1aefe0, 0x3e2556f4, 0xbd3f705e, 0x3de68486, 0xbca243e4, 0xbbb42acb, 0xbd834304, 
    0xbc053d36, 0xbd3ae672, 0xbdc25cdd, 0xbcaba16b, 0x3d564a17, 0xbdb2e889, 0xbe15678b, 0xbe11445e, 
    0xbe043671, 0x3dffe14b, 0x3d5fce19, 0x3e15577d, 0x3d099d0e, 0x3e1b8e6d, 0xbe227889, 0x3de38402, 
    0xbe0ff897, 0x3d3b845a, 0x3c962296, 0x3e143a32, 0x3e02e529, 0x3dc5886b, 0x3e10fb7e, 0xbe1f71de, 
    0xbe2f93bb, 0x3d0c0f8c, 0x3e241134, 0xbc76e6e4, 0xbe27edf7, 0x3df05976, 0xbca6a732, 0x3c44c7cf, 
    0xbdd11986, 0x3d6ff321, 0xbc789ca0, 0xbd80de0c, 0x3dffd272, 0x3e32fc27, 0xbe217e2e, 0xbe1bf2f4, 
    0xbdea7ceb, 0xbd05d6ed, 0x3d9d256e, 0x3def51e2, 0x3d13c9ff, 0xbe341ecb, 0x3cc870ef, 0xbe22a32f, 
    0xbe17448f, 0xbe0e8f53, 0x3e00125f, 0x3dde7681, 0xbd59eabf, 0x3df084ec, 0xbe08ef84, 0x3e18f297, 
    0x3e318fd1, 0x3e0ddcc5, 0xbe4800c8, 0x3e3a8627, 0xbe094e36, 0xbe2c931c, 0xbe2339d2, 0xbc5f3184, 
    0xbd3a2548, 0x3e2c73fa, 0x3e473ee8, 0x3df116ea, 0xbe3c7e69, 0xbdc8598d, 0xbc21358c, 0xbdd42090, 
    0xbd5e4d3f, 0x3e1488f6, 0x3e04e61d, 0xbddf3d14, 0x3dd7c82d, 0x3d803b77, 0x3e086207, 0x3ae2b11c, 
    0xbe2c3878, 0xbc9f8d94, 0xbcdc4641, 0xbcf7d5c8, 0xbcd0813c, 0xbd503641, 0xbe0ef057, 0x3d1cfc2e, 
    0xbe341df0, 0xbc89772c, 0xbd2dfe33, 0xbd877eb6, 0xbe096aa7, 0xbd48dc65, 0x3e1f1ed7, 0x3a939258, 
    0xbe346599, 0x3e214033, 0xbafbc009, 0x3e0f53a1, 0x3cb7ae00, 0x3d51dea2, 0x3d6df3c2, 0xbe150e9c, 
    0xbba8f15b, 0x3d89e340, 0x3d994415, 0xbd31071d, 0xbe24204f, 0x3e180ec6, 0x3e12389f, 0x3ca54cbd, 
    0xbe232ee6, 0x3d85678e, 0x3cd3b72e, 0xbd5696be, 0xbe1392b6, 0x3deac427, 0xbd139319, 0xbe17c9c1, 
    0x3db72fd2, 0xbe28ef6c, 0xbe13eac1, 0x3e0a22a7, 0x3d8913b5, 0x3e12d5f2, 0x3d9685dd, 0xbd5318ce, 
    0xbe09a9e3, 0xbd8a2f9d, 0xbe05835d, 0x3b0e7fea, 0xbdeee64c, 0x3c8fcbc1, 0xbc95c81e, 0xbd9f9554, 
    0xbdbcdc90, 0x3de9802c, 0xbe0ed6cd, 0xbe04cd19, 0xbcd447dd, 0x3e19509b, 0xbdb04bdd, 0xbe0f8b61, 
    0xbe269785, 0xbd5e0050, 0x3cbd90be, 0xbd0b4b04, 0x3ca5ee42, 0x3c2c71ef, 0x3e3a8a27, 0x3da3cc41, 
    0xffffba3a, 0x00000004, 0x00000010, 0x00000001, 0x0000000c, 0x00000001, 0x00000020, 0xffffba56, 
    0x00000004, 0x0000000c, 0x00000001, 0x00000006, 0x00000020, 0xffffba6e, 0x00000004, 0x00000034, 
    0x3c8456ca, 0xbcc04843, 0xbc0fd83f, 0x3cc8aef6, 0x3c4e3875, 0x3cea2c11, 0xbc8058b7, 0x3b42a105, 
    0xbb323e71, 0x3d163b2e, 0x3a6024b5, 0x3c87c5c5, 0x3b4001f3, 0xffffbaae, 0x00000004, 0x00001380, 
    0x3d8106ee, 0xbdb6605c, 0x3e877ead, 0x3ddc8500, 0xbd5007cd, 0xbc61c171, 0xba024e16, 0x3dcc14d4, 
    0x3e225089, 0xbd20c5b2, 0x3e509775, 0x3e3af19a, 0x3c3b3139, 0xbe12fa37, 0x3e915987, 0x39092759, 
    0x3e224524, 0x3e49fc48, 0xbd15a8ad, 0x3d0dbba1, 0x3cff373c, 0xbb981494, 0xbd31c46a, 0xbc32c3cd, 
    0x3dd6db11, 0x3d9699f4, 0x3d0a8689, 0xbc2d447f, 0x3d07ddbc, 0x3df81a67, 0xbd5e55c7, 0xbc25daf4, 
    0xbe736158, 0x3d6e3afc, 0x3e15fbeb, 0xbc70fe0b, 0x3ced2deb, 0xbe7e0b96, 0x3e76f1cf, 0xbd42ce6c, 
    0xbe63dbff, 0xbe6e7589, 0xbd2dd106, 0xbcc7eb1a, 0x3e835849, 0x3e8a1090, 0x3d899f97, 0x3dbdc419, 
    0xbdfa85fa, 0x3e57b201, 0x3d5a1451, 0x3e68d107, 0x3ce5a114, 0x3e9798ec, 0xbe925ed6, 0x3e6b04a1, 
    0xbdc0a926, 0xbe8f06c4, 0x3e78336c, 0xbc95bde2, 0x3e837c13, 0x3cebbdef, 0xbd575664, 0xbc3e57e7, 
    0x3dbf39c2, 0x3e85c183, 0x3e20adb2, 0xbd440a14, 0xbe1dabc8, 0xbe56ccde, 0x3e23618b, 0xbd864567, 
    0xbe83629b, 0x3e6ce7c7, 0x3e379a8e, 0xbcc1489a, 0x3e5233e2, 0x3d93d12b, 0x3e423452, 0xbe1ff9c0, 
    0x3e0ef3a9, 0xbe4743ee, 0xbe2512a9, 0x3e86bd32, 0x3e8d8ae7, 0x3e8d1993, 0xbecdfacf, 0xbe8f004a, 
    0xbe56872f, 0x3ea43de7, 0x3e01d7b2, 0x3ebe3200, 0x3eb8e2cf, 0xbdcc9d6d, 0xbe6abf33, 0xbe955e3a, 
    0x3ebddc56, 0xb908993d, 0x3e4547d0, 0xbe94da6e, 0x3ec1b994, 0x3dfcd46b, 0x3ecc870b, 0x3d84fc33, 
    0xbd36dc69, 0xbcdb5bcd, 0xbe723c10, 0xbe503661, 0x3cad0681, 0xbe055668, 0xbe3f4ca6, 0xbe965fee, 
    0xbe64ab1b, 0xbe4e9ead, 0xbe0354f3, 0xbd818d93, 0xbe96d4b4, 0xbd98e028, 0x3e4c9af6, 0x3e7f4d6c, 
    0xbe0a7b5b, 0x3e5ae938, 0x3ddfbe7b, 0x3cea7009, 0x3b08ff1c, 0xbdde5cc8, 0xbdd65a9d, 0x3e41626e, 
    0x3e42a4c7, 0xbbf22d31, 0x3dda9c40, 0xbcb94353, 0x3e25b2f7, 0xbd1aa8ec, 0xbd8b3628, 0xbbbbd142, 
    0xbbfa38a1, 0x3e2ef888, 0xbca36c42, 0x3df358f2, 0xbdc2ed3b, 0xbe4107d3, 0x3e24e2e0, 0xbe28f4fd, 
    0xbd92b135, 0x3d789fc9, 0xbd84fffb, 0xbda37184, 0xbe1ec1f3, 0x3e35db63, 0xbdbd51f2, 0x3acf49c1, 
    0xbdc3ee73, 0x3e3f9e83, 0xbdf9767d, 0xbd1d44c0, 0xbd8d639d, 0xbe217092, 0xbe8671df, 0xbd9d9a31, 
    0x3e953b71, 0xbca4cfee, 0xbe419929, 0x3ea1322b, 0x3daceb4a, 0x3e05c692, 0xbe4f8f84, 0x3e159fb4, 
    0xbe9fe52d, 0xbde1a143, 0xbe4c364e, 0x3e9e0be0, 0x3e91f60f, 0x3dd5ff3f, 0xbe95b6d0, 0x3dc2c65a, 
    0x3ea97e98, 0x3d858655, 0xbe6fdaa6, 0xbcf4199c, 0x3eb46de1, 0x3e6943fb, 0xbd578562, 0x3e2c6213, 
    0x3e10b63d, 0xbe4f9ee3, 0xbe4df092, 0x3de13a41, 0xbe31258d, 0xbe3898db, 0xbe4def55, 0xbcd50839, 
    0x3e83de75, 0xbda4cd7b, 0x3d80e70a, 0xbda4ab06, 0xbd8589ff, 0xbe594529, 0xbb8f61e8, 0xbd3cc6da, 
    0xbe82ab4f, 0x3ccbe98d, 0xbd2708df, 0xbe392ab0, 0xbe1781fa, 0xbd91dd5d, 0x3e2e0161, 0xbe4782f7, 
    0xbc597510, 0xbe223d54, 0xbe318282, 0x3e1e6a96, 0xbe88d62f, 0x3e0821fe, 0xbe36287e, 0x3ded66a1, 
    0x3e34ef60, 0x3e2d44ea, 0xbc7d4391, 0xbe53c983, 0xbd82d766, 0x3e56da0a, 0xbaec30d3, 0xbe348bb0, 
    0xbe113b2b, 0xbe182959, 0xbc543a1a, 0xbe8ae60a, 0x3e7f77cb, 0xbe2a6acd, 0xbdb2547b, 0x3e7344ae, 
    0x3d3c2fb8, 0xbdc2fd17, 0xbda38fdb, 0xbdf0684e, 0xbdcf35d5, 0xbe17d340, 0xbde8994e, 0xbc5f439f, 
    0x3db8a4de, 0x3dcceaa2, 0x3e054ab6, 0xbe097290, 0x3d987021, 0x3d88ff63, 0xbcaf52e6, 0xbdd9c10b, 
    0xbdf789e7, 0xbdc602f8, 0xbcdacd65, 0x3e0ade22, 0x3b8da57f, 0x3cd99f4a, 0xbe106033, 0xbe28e905, 
    0xbde9c6cf, 0x3c643487, 0x3d08d04b, 0x3d5b6b0e, 0xbe0fe30e, 0x3ddd5396, 0x3d008e8c, 0xbe2bb42f, 
    0xbc9ea66c, 0xbb5dd861, 0x3c5b2a5e, 0x3df313a1, 0xbe06b162, 0xbabedbc8, 0xbd8aa631, 0xbdeea793, 
    0x3e281721, 0x3da02513, 0x3de2fcce, 0xbd901516, 0xbd8ca38a, 0x3e1e76d5, 0x3e509591, 0x3cfc8c39, 
    0x3c00259f, 0xbe517fda, 0xbe34a474, 0x3e31bcb7, 0x3ca2cdb3, 0xbe8f1aa5, 0xbe5b7fa7, 0x3d7fade2, 
    0xbcb266fa, 0xbcf6d8f4, 0xbe7a828b, 0xbd287075, 0x3d20c79c, 0xbd1d0ef3, 0x3de45c97, 0xbe515734, 
    0xbe43398a, 0xbe280f9e, 0xbe8bbb63, 0xbe23a87d, 0xbe79e619, 0x3e65d23e, 0xbe41c33a, 0xbe8a3ff9, 
    0x3cfd7cbb, 0xbe18afc1, 0x3dd70a02, 0xbea2c739, 0x3e831648, 0x3e98364c, 0x3e0351a5, 0xbe9037ba, 
    0xbd9ecf30, 0xbd0e681f, 0xbe176bc9, 0xbe284378, 0xbbda4e29, 0xbbb22493, 0x3cbfb255, 0x3dffd686, 
    0x3dcf48ab, 0x3e4552ee, 0x3b67d005, 0x3dfafb05, 0xbd7748a6, 0x3d9af83a, 0xbd801d69, 0xbe2413a9, 
    0x3e30775e, 0xbc6784e1, 0x3e183a59, 0xbd7e31c2, 0x3d332914, 0x3dbe09c1, 0xbd1b2a24, 0x3e28ccf2, 
    0xbdfff854, 0x3e43fc2e, 0xbe4357ed, 0x3e395293, 0x3e2d0b0a, 0x3e3e75c0, 0xbde9d7ce, 0x3e3c77fb, 
    0x3d0d34f3, 0xbe16a4bf, 0x3d9f9704, 0xbdc75cd6, 0xbca7de52, 0xbd9c4648, 0x3e59c78a, 0x3e30a76b, 
    0xbe407d32, 0xbdc5be66, 0x3e39e631, 0xbe01e909, 0x3e17dffb, 0x3d0913b9, 0x3dcf0058, 0x3d62b8f7, 
    0xbe2b6aab, 0x3dd23d98, 0x3e08a6a9, 0xbe05330f, 0xbe1e27f6, 0x3e348eed, 0xbe2544fc, 0xbda2c6c7, 
    0x3e090c6c, 0xbdb5a6a4, 0x3da0d80c, 0xbcbde250, 0xbce08ef0, 0x3de88b3d, 0x3dea05dc, 0x3c047b83, 
    0xbb1d00cc, 0x3d826245, 0xbe003b76, 0x3e170209, 0x3c687478, 0xbe2eb5c6, 0xbd978140, 0xbd1db2c5, 
    0xbdcfa9ea, 0xbda148fa, 0x3e2fe586, 0x3d728a86, 0x3c14c960, 0xbddf8a53, 0x3d8defe1, 0x3e0c872e, 
    0xbdcd6a93, 0xbdb70429, 0x3d5ae632, 0x3bb20c31, 0xbdbec022, 0x3ddf07df, 0xbd275355, 0x3e04dbbf, 
    0x3d0500a8, 0xbd2202b6, 0x3d323971, 0x3e03f45e, 0x3de7d991, 0x3ccbce81, 0x3d1c962a, 0xbd87d3ee, 
    0x3d40142e, 0x3cbb3935, 0xbc77b40d, 0xbd33a659, 0x3b5688e1, 0x3d3f54af, 0x3d62ae10, 0x3d67748b, 
    0x3d166f57, 0xbd27fe1f, 0x3e171127, 0x3cbb5814, 0xbaef759e, 0xbcd80d62, 0xbdf282ec, 0x3e09b1a9, 
    0xbdd33326, 0x3d34db24, 0xbc81f8ea, 0xbcb87fd4, 0x3e088e4c, 0x3e9574de, 0xbe89e1f5, 0xbb1c72ca, 
    0xbe2f103a, 0xbe087272, 0x3e2fc5dc, 0x3e5afce0, 0xbd887a55, 0xbe7f2a4b, 0xbe37390a, 0xbe51d170, 
    0x3e68a5ba, 0xbe624fdc, 0x3e55b36c, 0x3e1df9b3, 0xbe8b45e7, 0xbd6bb099, 0x3d132bc4, 0xbd9f5230, 
    0xbb7581b9, 0xbe8c21b6, 0x3e81b08a, 0x3e8e1370, 0xbe1ac6e5, 0xbe7e4fe7, 0xbd416fba, 0xbe052659, 
    0xbdc884bf, 0xbce0db2c, 0xbe1f5c58, 0x3e16ebcc, 0x3dff5f0a, 0x3e40dd5e, 0x3e0f5440, 0xbe16da16, 
    0x3e4d6709, 0xbd8fe49b, 0xbdff272d, 0x3d86e2e0, 0xbe1639c8, 0xbd7ed4bc, 0x3dd6d3c0, 0xbd2a343a, 
    0xbd8a16e0, 0x3dc90d0a, 0xbd5c27e9, 0x3e1fd256, 0x3e866fec, 0xbe9f87c3, 0x3e36b4cc, 0xbe8c6a46, 
    0x3e17e49b, 0xbe03f828, 0x3e6cc80c, 0x3eb208d6, 0x3e45fd64, 0x3dfa2d77, 0xbe0f68e2, 0xbda54f7b, 
    0x3ea12b21, 0x3e635943, 0x3e520dc5, 0xbdb67751, 0xbdbcc035, 0xbe1313d0, 0x3e843670, 0x3e070817, 
    0x3b253b1b, 0x3e3ca444, 0xbdbef749, 0x3e13cfe6, 0x3e89c093, 0x3e87a273, 0x3e870fe6, 0x3dcad186, 
    0xbda23425, 0xbe8dd591, 0x3dd7ac66, 0xbe6231be, 0x3e8a6076, 0x3e2c0019, 0xbe8491f7, 0x3d396046, 
    0x3d0f0b01, 0x3e1f123a, 0x3e7cbf33, 0xbe1600e4, 0x3d8bd96b, 0x3e841843, 0xbe13c89a, 0xbcea46cb, 
    0x3e7892a0, 0xbe85b4c6, 0x3e5dffc9, 0xbe41fedd, 0xbd916d74, 0xbcf10801, 0x3e8b3b00, 0x3e8de4c0, 
    0x3cdffdcd, 0xbe06d073, 0x3e251a3f, 0xbe332dd3, 0xbe27b3da, 0x3e291aa5, 0x3d93a248, 0x3e4d21c6, 
    0x3daebb8e, 0x3da56ef7, 0xbe306cc9, 0xbe5e7e7b, 0xbb1c7f57, 0x3e8b8249, 0xbe840543, 0x3e59b046, 
    0xbdcfce5c, 0xbe77aa9a, 0xbe9694ab, 0xbe016c71, 0x3dc937a9, 0xbd730b84, 0xbe709b8f, 0xbe36cfd8, 
    0xbdec982c, 0x3e7bb543, 0xbea06ca2, 0x3e7c69a8, 0xbe4c7793, 0xbe60d446, 0xbea40399, 0x3dea9d01, 
    0x3e883602, 0xbecb3fc7, 0xbd417a5c, 0xbe7eb8f0, 0xbd01bcc1, 0xbe22d721, 0xbe8784e4, 0x3e8d9d23, 
    0x3dac9677, 0x3e075773, 0x3e9d080f, 0x3e856777, 0x3ac8e6a1, 0xbe3a8a67, 0xbe085584, 0x3eb8b0e1, 
    0xbd9afc2d, 0x3d8279e5, 0xbe700d1f, 0x3da969e7, 0xbe2b73b8, 0x3c89164f, 0x3ea63403, 0x3d247585, 
    0xbe85935b, 0x3e0029d8, 0xbe5b1f16, 0xbe0ef538, 0xbe555a3b, 0x3e50354b, 0x3c6f6d59, 0x3e94b8d4, 
    0x3e4a3ad1, 0x3d9fd15a, 0xbda9c016, 0xbe0e98f3, 0xbe303fa8, 0xbe3f3243, 0x3e37bd81, 0xbe00a27f, 
    0x3e5e25a1, 0x3dc89689, 0xbd07a900, 0x3bdaef19, 0xbe401ae7, 0xbeb5cf51, 0x3d148d65, 0xbe960e4e, 
    0x3db4cc93, 0xbe68dc11, 0x3e53b525, 0x3e8576be, 0xbde96fcb, 0xbe9f7613, 0xbd456143, 0xbe9e130d, 
    0xbde60e9a, 0xbe9c19e0, 0x3e5d930c, 0xbe080c26, 0x3eb0df75, 0xbd83df79, 0xbe01a86a, 0xbeab7ac7, 
    0x3e25f48e, 0x3e25667d, 0xbe8ee48c, 0xbe82cb3e, 0xbe61b878, 0xbde47c95, 0x3e6aab59, 0x3df5e233, 
    0x3ebc2d67, 0x3e91d385, 0xbe358643, 0xbd68d44d, 0xbd41bb89, 0xbdc2aa1d, 0x3bcc81fd, 0x3dc8712b, 
    0xbe039fc9, 0x3d8c36da, 0x3b0f4b5d, 0x3d798d9a, 0x3da7efb2, 0x3db26734, 0xbe0411ce, 0xbe52e42f, 
    0xbcc0366b, 0x3cbf9921, 0x3e3b6d50, 0xbdc1f4a0, 0xbdc5ec7f, 0xbe15d2a7, 0xbebd911f, 0x3d7db3f8, 
    0xbc29de4e, 0x3e04c33f, 0x3e3db3f6, 0xbd900fe6, 0xbe13ed0e, 0x3c802951, 0x3d16e46c, 0xbda664a6, 
    0x3d396caf, 0x3e22cfdc, 0x3e27abd9, 0xbcd6d667, 0x3e79e3b9, 0x3dfe64ae, 0xbda82a09, 0xbc841642, 
    0xbe670ee0, 0xbe3e0189, 0x3dc82668, 0x3be0207d, 0xbdd7f1e1, 0x3dea6c42, 0x3e3c0d42, 0x3e3e9ed5, 
    0x3dd54496, 0xbc000108, 0xbd6d9697, 0xbb4dad52, 0xbd8f1b19, 0xbe2f2366, 0xbdd8c3da, 0xbdccbd2f, 
    0x3e5fbe13, 0x3e1a4ac4, 0x3e45416e, 0x3db179d3, 0x3da6722a, 0xbe435b41, 0xbe8634da, 0x3e12e88c, 
    0xbe8d6916, 0xbe8a402a, 0x3e516123, 0xbc4cf8ca, 0xbd718dfa, 0xbe53586a, 0xbe0a68aa, 0xbd4621f6, 
    0xbda874e7, 0xbd5d07b6, 0x3d949388, 0x3dd324e0, 0xbe1cab91, 0x3e2bcc4f, 0xbe757df0, 0xbe00b6d5, 
    0xbdd47350, 0xbe395ee1, 0xbe163ec9, 0xbe08efff, 0xbe4394b0, 0xbd427294, 0x3e0531e6, 0xbe34a903, 
    0x3cba2e45, 0xbe34a891, 0x3e59dc7d, 0x3dbef5aa, 0xbe5da2be, 0xbdbfcc08, 0xbd857d29, 0x3e07d1fe, 
    0xbdbfe6df, 0x3d81f60e, 0xbe8372db, 0x3e6ffa70, 0xbdc30d85, 0x3e22ba9a, 0xbddfd6ad, 0xbd89d736, 
    0x3c99cf1a, 0x3da6e2e0, 0xbe8b0760, 0xbc8f5239, 0x3df11c00, 0xbd57c59a, 0x3de6ffa6, 0xbc9ee3d2, 
    0xbda3437b, 0x3de6117b, 0x3e220bd6, 0xbd8261da, 0xbbd91d48, 0x3df9580d, 0x3d1bdb56, 0x3dea683b, 
    0xbbcc38d7, 0x3d1e0c0e, 0xbda7fb40, 0xbd13d28a, 0x3e1dab50, 0x3de8b601, 0xbdf0d0a4, 0x3c531ef1, 
    0xbda71983, 0xbe23c9f7, 0x3dc9bfed, 0x3c45ec98, 0xbe0adfd0, 0x3d2965ac, 0xbe0e038e, 0xbdc95d33, 
    0x3bb87e31, 0x3e04fb2f, 0xbe10de3d, 0x3d748813, 0x3da8bf26, 0xbe08d743, 0x3de3d0a7, 0x3d92a8b7, 
    0x3e1e500a, 0xbe2eeefe, 0x3df52e7d, 0x3bb77882, 0x3e63ec91, 0x3e0486ac, 0xbe79b07e, 0x3e5ed023, 
    0xbddac7b7, 0x3e72516b, 0xbdb42783, 0xbe755efd, 0xbdc14fa4, 0x3e46e769, 0xbe1bdb74, 0xbe76a463, 
    0x3d830d91, 0x3dfd6a89, 0x3daf9185, 0xbe16ac8d, 0xbe5b8436, 0xbe439f69, 0xbe2ca051, 0xbe016153, 
    0x3e2223e7, 0x3dd6e176, 0xbc1fb32d, 0xbdc6f6b8, 0x3c84e479, 0xbe3017a9, 0xbe5e86b9, 0xbd65d6b0, 
    0xbc3c03c5, 0xba34dc4a, 0xbd427ce2, 0xbd9dc5f3, 0xbcf40fe0, 0x3c8d80f9, 0x3e59644c, 0xbe3bade0, 
    0xbdad814b, 0xbe5aedd6, 0xbe335e1c, 0xbdde3109, 0x3d8d69c0, 0xbd1eee50, 0xbdadc8f1, 0xbd06c59c, 
    0xbe5a3982, 0xbe0a1676, 0xbda8d0cb, 0x3dab6189, 0xbad57a46, 0x3e536846, 0xbccc8199, 0xbd00cc80, 
    0x3e88377f, 0xbd493763, 0xbdc12da3, 0xbdd111fc, 0xbe28109e, 0xbe15a203, 0x3e5dd704, 0x3d070578, 
    0xbe3da3a0, 0x3e01c838, 0xbe15e638, 0x3dbca5c2, 0x3d16890f, 0x3d8bafdd, 0xbcfa3e8b, 0x3cbc03e9, 
    0x3d7c364f, 0x3d76629e, 0xbdad950a, 0xbe36e668, 0xbe6bcfa1, 0x39276712, 0x3d005db0, 0x3e39ce6b, 
    0x3e3373d5, 0xbb8f44ff, 0xbe0f0cdc, 0x3daa0a35, 0x3d70976e, 0x3cf4b000, 0x3d21bc0b, 0xbdb631b3, 
    0x3deee45e, 0x3dc72e7d, 0x3d180a5a, 0xbd793aea, 0xbd8bb520, 0x3da03b0d, 0x3e02c096, 0xbdf06219, 
    0x3d0e3d03, 0xbdd6699f, 0xbd3b9e12, 0x3b9236a6, 0xbc9721ca, 0x3de86ce0, 0x3dc9fe80, 0x3d1a4160, 
    0x3dd353e6, 0xbc67642e, 0x3d01c416, 0xbda7a62d, 0x3d72577e, 0xbd8c6c5b, 0xbd959227, 0x3d67a471, 
    0xbd2cb2fd, 0xbde56906, 0x3de5e486, 0x3d733755, 0xbda3d042, 0xbda26a87, 0x3d49f21e, 0x3cd000f0, 
    0xbc2ce0ad, 0xbdb3ac10, 0x3e18298f, 0xbd7acccd, 0x3e985e0e, 0x3e14fd7e, 0xbe6c7768, 0xbed86a53, 
    0x3eb7e225, 0x3ece7e49, 0xbe020967, 0x3e9bbbe6, 0x3e45257f, 0x3eb1c877, 0x3f108de1, 0x3e434ca2, 
    0xbe42ad56, 0xbe384422, 0xbe37eac6, 0xbef06961, 0x3ec1d515, 0x3e2a35ce, 0xbecac6e3, 0xbefe579d, 
    0x3efda041, 0xbdc1cb27, 0x39872199, 0x3ebbcb6b, 0x3e5f0cfc, 0x3ee87d3a, 0xbd811395, 0x3e2d50cc, 
    0xbe845e2e, 0xbe09a1ff, 0xbe18f953, 0x3d3057ab, 0xbe2fe0f4, 0xbdde50cd, 0x3edf1a31, 0x3de73ae3, 
    0x3d115c1d, 0x3ec11d7e, 0x3dc2d7e9, 0xbe804723, 0xbe93ae07, 0x3ed28a7b, 0x3e3fb24e, 0xbe64ddfc, 
    0x3e38583e, 0xbe99b03a, 0xbe9d85d5, 0x3e9c267e, 0x3ec3f9f5, 0x3ea50976, 0xbe6232d6, 0xbe7d4b0d, 
    0xbe0477de, 0x3e5bad2a, 0x3e88629a, 0xbda3a74f, 0x3e8a32ce, 0xbecd8cec, 0x3ebc8aec, 0xbcc3ba4e, 
    0x3bc1ecc0, 0x3e385433, 0xbd156602, 0xbc82409d, 0x3dc016fd, 0x3e0babac, 0x3e95099a, 0xbde09527, 
    0xbe56449c, 0xbd96e8d2, 0xbe6aeb8f, 0x3e8fc9d2, 0x3e5b6aea, 0x3e7a4b82, 0xbe95c055, 0xbc2b3996, 
    0xbd7c0a56, 0xbd18b592, 0x3e30cccf, 0xbdb04191, 0xbe71d524, 0x3dc602bb, 0x3cd476bc, 0x3cf6f29a, 
    0x3d358520, 0xbe0f0227, 0xbc8513ad, 0xbe513992, 0xbdcb96d8, 0x3e3c79eb, 0xbd9d58e2, 0xbe2d351a, 
    0x3e1db0d5, 0x3d3d254e, 0x3cf9dabb, 0x3e38e5fd, 0x3e0c6e26, 0x3e3b15c5, 0xbe36546b, 0x3e340b94, 
    0xbd515a8e, 0xbe36dfa3, 0xbe4523c3, 0x3d54418b, 0xbd5acb89, 0x3d81f47e, 0x3bdba34e, 0x3e1e6209, 
    0xbe5403f9, 0x3e03712f, 0xbe3b3314, 0x3cdd2f8f, 0x3e3e531c, 0xbd8d5fb2, 0xbe550397, 0xbe4cfd10, 
    0xbd9fe5f4, 0x3dba2f37, 0xbdef9f32, 0x3d917909, 0xbd924bfa, 0xb97eaada, 0xbc1e1061, 0x3ccebcd1, 
    0x3e6a36c4, 0xbe069eed, 0xbe1f76e3, 0x3ba66c2f, 0xbc60cb90, 0xbe2ad5cb, 0xbe034e15, 0xbe5be5fb, 
    0xbe077c5c, 0xbe1bb143, 0xbbfa67b3, 0x3dea24e7, 0xbdb1c1ff, 0xbdab389a, 0xbccae501, 0xbde1809a, 
    0x3cea87d1, 0x3d5fa24d, 0xbc714329, 0x3e2dbe94, 0xbdc96949, 0xbdba7b93, 0x3ddeb2b5, 0x3d9caf87, 
    0xbd24e2cf, 0x3dca67fe, 0x3e672613, 0x3e564e23, 0xbc12e506, 0x3dc892d4, 0x3e238ea5, 0xbd83955e, 
    0x3d72524d, 0x3e07ebba, 0x3d9c0887, 0xbe1f9b57, 0x3ba29086, 0xbd4fc5a5, 0x3cdaece2, 0x3e02e042, 
    0x3d55c35f, 0xbcff28c3, 0x3cdae6ca, 0xbe0ecd62, 0x3e58d089, 0xbddce278, 0x3db742fa, 0xbd54f21c, 
    0xbe0639da, 0xbd6b7116, 0x3e3ad9d5, 0xbb8a552c, 0x3ddfc869, 0x3d7df0db, 0x3e3e1c72, 0xbe5ff4c1, 
    0xbd11d988, 0x3df81b9c, 0xbe0f18ab, 0xbd95a418, 0xbe03a7d7, 0xbe5c6218, 0xbd0c5d1f, 0x3e426a7f, 
    0xbdb61dc0, 0x3cd4fb11, 0x3c4dd842, 0xbe10f43e, 0x3cee60df, 0x3d863077, 0x3d1c3e49, 0x3d25cf4c, 
    0xbe1290ba, 0xbdcf279c, 0x3e0a7d9a, 0x3db0908e, 0xbdeb5a36, 0x3bdd1e92, 0x3c6efa88, 0xbba56ae1, 
    0x3d877e82, 0x3c92df39, 0x3cf2c691, 0x3c997f51, 0xbcc37db9, 0xbdb0e3be, 0xbe0c0a47, 0xbd410589, 
    0xbd96a5ad, 0xbe2b4a38, 0x3dc4ce95, 0xbd70e88f, 0xbd1a1e3e, 0xbd64ff5c, 0xbd89d5b7, 0xbc30bd2e, 
    0xbd11244e, 0x3d11632c, 0xbe058933, 0x3cfcec92, 0x39c70d8e, 0x3cf4bbc4, 0xbe000890, 0xbca2aa53, 
    0x3d80ef61, 0x3df66393, 0xbd87c752, 0x3d9c0d29, 0xbe55478e, 0xbda29aef, 0x3b9be0d1, 0x3decd259, 
    0xbdf324aa, 0x3d0cf7df, 0xbdeb38a6, 0xbdd728a7, 0x3e5b1ef1, 0xbdc97d31, 0x3e10c151, 0x3d011358, 
    0xbe0b7e4f, 0x3dcfac8f, 0x3e048b8a, 0xbd41e7e2, 0x3cb11b63, 0xbe285831, 0x3d092af5, 0xbd7fd733, 
    0x3e5f76c8, 0x3d5bb130, 0xbda548cc, 0xbd50b7e0, 0x3dffd801, 0xbe4d015c, 0xbd945c4d, 0x3e25183a, 
    0x3cf8d0f1, 0x3d83a1ec, 0xbd1af07d, 0x3e0ff69d, 0x3d50f496, 0xbda21f39, 0x3de0a94a, 0x3d7923eb, 
    0x3e45da9c, 0xb8fb7aa2, 0x3d98a5a2, 0x3df2f7e1, 0x3d919890, 0xbdb97be0, 0x3e04586a, 0xbe048fd6, 
    0x3de80f7f, 0xbd7184dc, 0x3e29e252, 0x3dfd7167, 0x3bf5b340, 0xbddf5a59, 0xbdabcbda, 0xbd096f63, 
    0x3e076283, 0x3e025ffc, 0xbe0adb74, 0xbdbac87a, 0x3c521eef, 0x3ba263c7, 0xbd96b546, 0xbdb6a915, 
    0xbe02011f, 0x3e2910e9, 0x3e2b6344, 0x3c9ef4c7, 0x3dbb51e8, 0xbda13ee7, 0x3df4558b, 0xbe0ded62, 
    0x3e2fa674, 0xbe2096f3, 0x3bf2bf14, 0xbd72dfda, 0x3d5b4f43, 0xbdd1f96e, 0xbdbf1a6e, 0x3de391ce, 
    0xbd76c431, 0xbdab2f4f, 0x3dec2922, 0xbc8c793c, 0x3d0bbc05, 0xbdd41adb, 0xbd86cc92, 0xbe0b5658, 
    0xbc51876f, 0x3da91b4a, 0x3df49f2b, 0x3d7950c4, 0xbdb5b63e, 0xbd93a95e, 0xbc9f8bdf, 0xbdf85e2a, 
    0x3d91979c, 0xbdb13d8f, 0xbd335e18, 0x3d9bd194, 0xbb0570ce, 0xba9b1028, 0x3d77c790, 0xbcee912e, 
    0x3c9f968c, 0x3d27ac5e, 0x3d73926c, 0xbde4e617, 0x3d95cd25, 0xbe009f32, 0xbdc77940, 0x3e0524ee, 
    0xbde2aa4a, 0xbdfb29bb, 0x3def0aaf, 0xbdd2247e, 0x3cd9dcef, 0xbc55cd7d, 0xbcfcefd5, 0x3dbf2c12, 
    0xffffce3a, 0x00000004, 0x00003000, 0xbecac587, 0xbe299df3, 0x3e2c5d04, 0xbe4498d6, 0x3d062b5e, 
    0x3d060d8f, 0x3e4f9100, 0x3da3811a, 0x3c8b1e4c, 0x3e385345, 0x3e89738e, 0xbe64d3c0, 0xbed86e83, 
    0x3e867d50, 0xbe96ad13, 0x3e22f139, 0x3ed622da, 0xbe987f79, 0x3ee2fea3, 0xbe8e306d, 0xbdc4a1bd, 
    0x3e8e7042, 0x3e26a4f6, 0xbedb0d0e, 0xbebc1cc1, 0x3ec45edf, 0x3ea7c94a, 0x3dbe4d98, 0xbec0630a, 
    0xbeb5401f, 0x3e1f5183, 0xbeb002aa, 0xbe61a4cc, 0x3ee22b14, 0x3eba2206, 0xbe69c4e2, 0x3c4b260b, 
    0x3cb47a35, 0xbef481c9, 0x3a10ccf1, 0xbdce4ae1, 0x3e0a3123, 0x3ee81cee, 0xbeaddd8d, 0x3e2b7b20, 
    0xbe4499ae, 0x3ea83725, 0xbe446f17, 0xbd8d6cb9, 0xbecc7435, 0x3e32ac65, 0x3ed1141d, 0x3e7e743c, 
    0xbea81a0a, 0xbe659129, 0x3e886233, 0xbe647adf, 0x3e0374ee, 0xbf024f77, 0xbe1f2e0a, 0xbe802eb6, 
    0xbb94ef47, 0x3d0d006f, 0x3de2d1e7, 0xbecf0045, 0x3e360995, 0x3e84392f, 0x3e9ea92d, 0x3eaf48e0, 
    0xbebf09ef, 0x3eb31b3b, 0xbe253d35, 0xbc14310a, 0x3ed0a6f2, 0x3e80b6fd, 0xbe43fa3a, 0x3e8ecfd1, 
    0xbe5fa2f7, 0xbe5d1b05, 0xbd837909, 0xbbbb1ba6, 0x3dcf1061, 0xbeb42d07, 0x3e7a9eff, 0x3d0a15b6, 
    0x3e5cdfa2, 0x3e87f6b0, 0xbf0651ac, 0x3e58eeea, 0x3ec3455e, 0x3e82da57, 0xbce48337, 0xbca6fe92, 
    0x3eceafb9, 0x3e49b5b0, 0x3ec1ab73, 0xbe97c73c, 0xbc9cf5e6, 0x3ba56d80, 0x3edb9a19, 0x3ea15d3f, 
    0xbe2ed981, 0x3e44c819, 0xbe2b2ee1, 0xbebc84de, 0xbd8d3280, 0x3ea31c05, 0xbceb47a9, 0xbe983cbd, 
    0xbe49e8dd, 0x3e060d9b, 0xbde12e52, 0xbeb4b90e, 0x3e492a81, 0xbc89bf20, 0xbea325a4, 0xbe955c09, 
    0xbb978d93, 0xbea3057f, 0x3c064572, 0xbe49ed70, 0x3e1fa1b7, 0x3d94bb1b, 0xbe57e098, 0x3e766684, 
    0xbed739c5, 0xbe46e706, 0xbe13982c, 0xbd39b0cd, 0xbecf7373, 0x3b604b63, 0x3e1911e8, 0xbecbe95b, 
    0xbea470e3, 0xbe1f49ef, 0xbece7111, 0xbc0d4077, 0xbe59593b, 0x3e88ba14, 0x3e84fde2, 0x3e279686, 
    0xbb05fbd3, 0xbe284660, 0x3e0488de, 0x3e270418, 0xbe6e7ef2, 0xbea746fb, 0x3ed0548b, 0x3eec1b73, 
    0xbc0517e3, 0xbdf61b70, 0xbe171e52, 0xbe6e6158, 0x3eca4592, 0x3eac624c, 0xbed8e69c, 0xbdfd71ce, 
    0x3ea98cbc, 0xbe348cc9, 0xbe5fd014, 0x3d4010d7, 0x3e48c994, 0x3d27dce3, 0xbcd33fdc, 0x3ddc9103, 
    0xbdfdfbcd, 0xbe42e097, 0x3d04045d, 0x3e86e8a4, 0x3c892165, 0x3ed44037, 0xbe82c6ef, 0xbcfedee2, 
    0x3e21c593, 0x3db99b85, 0xbeb39693, 0xbdf5c007, 0xbe885296, 0xbe01be88, 0xbde5445e, 0x3eb6f9f6, 
    0x3ea3f188, 0x3e39436c, 0xbeb0f402, 0xbe8418c6, 0x3f1339bb, 0x3e256ded, 0xbf00b25c, 0xbe981939, 
    0x3dcd544f, 0xbe6ff736, 0xbde140bb, 0x3d210b22, 0x3dd40a48, 0x3d122888, 0xbe914197, 0x3db132fa, 
    0xbcf9d1b1, 0xbe9552d4, 0xbdc2e97e, 0xbde63878, 0x3d2100a2, 0xbbf1cb14, 0x3ddf56ca, 0x3dc23fad, 
    0x3e2663cc, 0xbd9927c1, 0x3df890d3, 0x3d4a2506, 0xbd0aa273, 0x3e1308ba, 0x3e03d36d, 0xbdb0d0eb, 
    0xbe1b2b6e, 0x3e166c09, 0x3b059485, 0x3c692e9a, 0xbe2450d6, 0xbd0d4a4e, 0x3ba17078, 0x3dd4f413, 
    0xbe483833, 0xbe2fa1ef, 0xbe70921f, 0x3aad8304, 0x3df50f49, 0xbe5ae5ac, 0x3e584edd, 0xbe805d18, 
    0x3e298a8e, 0xbda8f517, 0x3d0b35e6, 0xbe041a7e, 0xbe0b69d4, 0xbe31fcb4, 0x3e88e388, 0xbe8b48b7, 
    0x3dc80c17, 0xbe23ecc1, 0xbd9b2b1e, 0x3e9b086f, 0x3e512c26, 0x3ccc3813, 0x3e15e716, 0x3e6cc0c1, 
    0xbe3f9ff7, 0xbcc51603, 0xbdd7990c, 0x3e63cbfe, 0xbc48cde0, 0x3e396138, 0x3e720008, 0x3d27574c, 
    0xbd6f2f50, 0x3e61061b, 0xbe8b2763, 0x3e9a39e3, 0xbe1c9317, 0xbe20b8c8, 0x3e951921, 0xbe7e11f7, 
    0xbd0a7934, 0xbe1fe3c6, 0x3e764572, 0xbe8b7695, 0x3ddb8352, 0xbc1f2315, 0x3e55ae8a, 0xbe0ab1a7, 
    0xbd98f7e3, 0x3c2f46cc, 0xbbc1f29b, 0xbe0ddb7b, 0xbce4e9e2, 0x3da248b7, 0x3e4a696c, 0x3e2cd7c0, 
    0xbe648ce0, 0x3db1de98, 0x3e376c92, 0x3e4c9016, 0xbd6de8c8, 0x3e49b6a3, 0x3cb7a429, 0x3e976fcf, 
    0x3e850f9d, 0x3e0636ca, 0xbe04443e, 0x3e925c96, 0x3e7b9cc4, 0x3ec84760, 0x3dbecd77, 0xbee71ff6, 
    0xbed0e64e, 0x3ed0a53a, 0xbe12cfab, 0xbea9be27, 0x3e92bab0, 0x3dbd260b, 0xbe23bc02, 0x3ea80f95, 
    0xbe23d470, 0x3e09fe3b, 0xbea9b28d, 0xbe4c1a33, 0x3ec3c0d9, 0xbe4ebd01, 0x3ea3ad50, 0x3e5a2f4c, 
    0x3cb0920b, 0xbdb1d743, 0x3dbd54dc, 0x3cf24c51, 0x3de61eae, 0x3e010076, 0xbe619bc9, 0xbe94c249, 
    0xbed67e7b, 0xbe665f14, 0x3f136d66, 0x3e2f0967, 0xbed6abc9, 0xbe97d64e, 0xbe8049b2, 0xbdf3061c, 
    0x3e13dd68, 0x3e9d6ca2, 0xbdbb52e0, 0xbe9826bc, 0x3d84ba84, 0xbe7b9c5c, 0x3d64d8a3, 0xbe548165, 
    0x3e0a4ab8, 0x3e06f67a, 0x3c9a94b3, 0xbea00c97, 0x3e7e06c8, 0xbe93de4b, 0xbea3d027, 0x3eab8286, 
    0x3e3f9b8b, 0x3e544b9d, 0xbddbf272, 0xbe5695ea, 0xbe75996a, 0xbe115e5c, 0xbee483a4, 0x3dc63462, 
    0x3e80a2c3, 0xbe5490b1, 0x3d61e8b7, 0x3d90c6d9, 0xbed24c39, 0xbe92e935, 0x3e894703, 0x3ca8687f, 
    0x3e3543db, 0x3ea5634b, 0xbeb0e1d1, 0x3d976c2d, 0x3e83efd0, 0x3dc20b96, 0xbf050e7c, 0xbe7ef145, 
    0x3e4ce82a, 0x3e457603, 0xbe311a20, 0x3eccaaf9, 0xbe831dc5, 0x3d4eeb8c, 0x3e96b756, 0x3e8281a3, 
    0xbc31f40c, 0x3d0af967, 0xbecbc915, 0xbe665761, 0xbe203519, 0xbed06183, 0xbed3fb0e, 0x3ec9a9db, 
    0x3e8e1eab, 0x3de47b4e, 0x3e400012, 0xbcc8658e, 0x3e13d493, 0xbee4979a, 0x3ed1bc50, 0xbe82fb0d, 
    0x3e457686, 0x3ebf2e94, 0xb9a23a51, 0x3dad0ad7, 0x3d455035, 0x3e373c11, 0xbdbd535c, 0xbe33566f, 
    0xbebe10d1, 0xbeaaaf03, 0x3e815b0d, 0x3dffaafe, 0xbe797f55, 0xbea8e389, 0x3dd97ae8, 0xbe3d6f50, 
    0xbeb6239c, 0x3e14a108, 0x3ed152e1, 0x3dbae321, 0xbeb212e9, 0x3c1e0726, 0x3eb56237, 0x3cd4676e, 
    0xbe72d8dc, 0x3da819d1, 0xbe7ec598, 0xbe8f5568, 0x3e9eacec, 0xbe62c752, 0xbe4cd2fd, 0xbe906dc9, 
    0x3e15e15d, 0xbe6a103f, 0xbecd8d13, 0x3e404507, 0x3d0609ac, 0x3e3721a4, 0x3e122ee6, 0x3e6d0ba7, 
    0x3ed5e4dc, 0xbe3711e9, 0x3d770795, 0x3ec57b67, 0x3e90d20f, 0x3db82fa8, 0x3d18cfa4, 0x3c7e3678, 
    0x3e8d5a00, 0xbe15d4f5, 0x3d8ad9d4, 0x3d69c58f, 0xbe0510c0, 0xbd9ea02e, 0xbea28191, 0xbd60fbb4, 
    0xbe369127, 0xbde15577, 0xbe9ee436, 0xbe6249f7, 0x3e3522c4, 0x3dfc4695, 0xbe336378, 0xbe47321d, 
    0xbca52b5c, 0xbeab5784, 0x3eabe7f9, 0x3d4796b8, 0xbe986e6b, 0x3d485358, 0xbea48265, 0x3e076eae, 
    0x3d74e0f6, 0x3e8bd841, 0xbbc19828, 0x3e882bae, 0xbd3cbbe8, 0x3ea9b983, 0xbd2fc444, 0xbea1ee36, 
    0xbd38c465, 0x3d821e59, 0x3e9f4a3f, 0xbeb5c176, 0x3ea05774, 0xbe58dca3, 0x3d691ca1, 0x3eecd797, 
    0x3e887ec8, 0xbe4db8cb, 0xbe2fa551, 0xbe99af3f, 0xbe54cff0, 0xbde29f94, 0xbe6ded11, 0xbe6ae6d5, 
    0xbc97aee8, 0xbee0c0f8, 0xbed9433b, 0xbec6bdab, 0x3eaf398a, 0xbe0cddf1, 0xbf025f52, 0xbe872b75, 
    0xbdcd7965, 0xbe442db5, 0xbedad214, 0x3cf13002, 0x3cbf3cc2, 0x3e89cd4d, 0xbecc883a, 0xbde26152, 
    0x3dd95513, 0x3eb1f60a, 0xbecbe2de, 0x3e97a5af, 0xbe88d4ce, 0xbe11c0eb, 0x3ec8d97c, 0x3e8d243c, 
    0xbd95b676, 0xbdff3eaa, 0x3e6a8347, 0x3ea68ab5, 0x3e1e8ed6, 0xbe83c627, 0x3e3b1faa, 0xbe5b9178, 
    0xbe45090d, 0xbdbd8e82, 0x3e2d80c0, 0xbdaff22e, 0x3e057963, 0xbe98e561, 0x3eb50d57, 0xbe54f671, 
    0x3ee05ee8, 0xbd490cb7, 0xbe3b063a, 0x3dac00a9, 0x3ea456cb, 0x3d2d3bc2, 0xbe1d853e, 0xbe1dc06a, 
    0xbee08d90, 0xbc1df0e7, 0x3ec29fae, 0xbdc5e0ec, 0x3ee3d3ee, 0xbe96df23, 0x3d12d334, 0xbed32811, 
    0xbed9a042, 0x3ed45548, 0x3eb778be, 0xbe4dbfa0, 0x3e398739, 0x3e87ef4d, 0x3d4d8e97, 0x3e53da5c, 
    0x3e239ae4, 0x3e98dc63, 0x3dfbe10e, 0x3d01a570, 0x3e828888, 0x3e88214a, 0x3ea16ef9, 0x3e5a0a34, 
    0xbe786808, 0x3e8ad182, 0xbe14d09e, 0xbe13bdc3, 0xbeb3ab0e, 0x3e9b9f54, 0x3dd612a9, 0xbd84810a, 
    0xbebb6ee0, 0xbe87bf65, 0x3d6a78aa, 0xbe7621f3, 0x3eb8e113, 0xbea9ac2f, 0x3ee0f356, 0xbe932119, 
    0x3e93538c, 0x3e01887e, 0xbea15f6e, 0xbe75e9cd, 0xbd3cae9e, 0x3ebdb310, 0x3e9a2912, 0xbd28ade5, 
    0xbe7cc230, 0xbed1627c, 0x3dde808f, 0xbe930e64, 0x3ef2ea9d, 0x3e87632b, 0xbe4cc572, 0x3ead789a, 
    0x39d0664b, 0xbef8cb28, 0xbebcacc8, 0x3e46381e, 0xbd91f03b, 0xbe4a0d50, 0x3e6b7ab5, 0xbd215422, 
    0x3e2406d9, 0x3e869e03, 0x3e90fe3c, 0xbefa4f36, 0x3ede8bfe, 0xbc159e1a, 0x3e9dd20c, 0xbdf6ab67, 
    0xbe8e7e57, 0xbeba5903, 0x3dc3815d, 0xbecf7225, 0x3d3eacbe, 0x3e8698f7, 0xbdb60de9, 0x3e202760, 
    0xbea87998, 0x3e288cf0, 0x3e36836a, 0xbe9919c9, 0x3eb0ada6, 0x3d23e347, 0x3e35ce9d, 0x3ed36bcf, 
    0xbec9804f, 0x3eaa8b30, 0x3ed67241, 0xbca59039, 0xbd64d2a1, 0xbdb78a9f, 0x3e850dcf, 0xbe82830b, 
    0x3e70e6d4, 0xbdb1463f, 0xbd9f80fd, 0x3ebf098e, 0x3ec96b14, 0x3e146b4f, 0x3cae0b57, 0x3e3b00de, 
    0xbe9db502, 0x3e62e7d9, 0xbdca90a8, 0x3d817946, 0x3e2a7c5a, 0xbe30cba9, 0xbdbdcbe5, 0x3e7a3865, 
    0x3da317fc, 0xbc9650bc, 0xbd1122b4, 0x3eb4caf6, 0x3ed8332f, 0x3ec357c7, 0xbe8fd6a6, 0x3e155847, 
    0xbc5c6cb1, 0xbed05bb2, 0xbdf7ea7e, 0x3ebd3ba0, 0x3e9cd883, 0x3eb250f8, 0xbdd29f30, 0xbd5025a7, 
    0xbd6a4733, 0xbec540e0, 0x3eceb801, 0xbeacd65d, 0xbdda8701, 0xbe446678, 0xbe4b8d36, 0xbe3fd76b, 
    0xbec0a3a9, 0xbe330414, 0xbed8bca1, 0xbea0b7e8, 0x3e1d8c72, 0xbec749f4, 0x3eb192ae, 0xbdcdf085, 
    0x3e9af9dd, 0x3e92cf6a, 0xbeb70e56, 0xbf0164a9, 0xbe8acd27, 0xbeb4126c, 0xbd1aecc1, 0xbe11d86a, 
    0xbd30a28a, 0x3e9868fc, 0x3edb2a05, 0x3eee93d8, 0x3ed0854a, 0x3ef48c57, 0xbe696d44, 0x3ea263ac, 
    0xbf06357e, 0x3e642a24, 0xbe50ddff, 0x3e837622, 0x3e9ca788, 0xbeace17d, 0x3ea0e390, 0xbeffc54c, 
    0x3d3fc6a9, 0xbec6e8b1, 0x3e964641, 0xbd32688e, 0x3e74eac8, 0xbe09c22e, 0xbdf65040, 0x3e3111c7, 
    0xbde15c5c, 0x3d290a64, 0xbe8f4a78, 0xbf0d9832, 0x3dcecd50, 0xbd97f525, 0xbea1772d, 0xbe3b0a0d, 
    0xbcf169f7, 0x3e8623d6, 0xbe965678, 0xbdbad17f, 0xbe2efab0, 0x3efd7596, 0xbed70ee2, 0x3eb45fb9, 
    0xbeab0c39, 0xbe98df00, 0xbdab9202, 0x3e91cfd8, 0x3e0fbbc3, 0xbe287e37, 0xbddeaa06, 0x3e8adc47, 
    0x3dc88837, 0xbcd92f6d, 0x3ebc824b, 0x3bc19fbc, 0x3ea3203c, 0x3e3ee6f7, 0xbd42a0fa, 0x3ebb457f, 
    0xbec82c64, 0x3e3f9de7, 0xbeb9ed44, 0x3ec95ff9, 0x3e358db0, 0xbeef5bc5, 0x3e1fdd74, 0x3ce364ac, 
    0x3d64448e, 0xbe6e6008, 0x3ec0c212, 0xbe60255d, 0xbe16611f, 0x3d92dd95, 0x3c11695f, 0x3e9e41c3, 
    0x3e3ac2bf, 0x3d1da6ea, 0xbe03c1e4, 0xbe33bf54, 0x3e749aa9, 0x3e8c0622, 0x3ee89bdb, 0xbdf959d6, 
    0x3dbb46b5, 0xbe82fb8e, 0xbc7aa633, 0x3eb5ac21, 0x3e6d3526, 0x3ed476c8, 0xbedc5189, 0x3f1a4802, 
    0x3e8abd1d, 0xbf013e13, 0x3e0fea06, 0x3ebf77a2, 0x3d082f62, 0xbeab3676, 0x3e8c991e, 0x3ed99547, 
    0x3c8621b6, 0x3eeff650, 0x3e549847, 0xbe8a4bb4, 0xbe9fba40, 0xbebba4bb, 0x3ed7c57b, 0x3e9fabc3, 
    0xbe0c1483, 0xbf034e0a, 0x3d6af5f7, 0x3d2adb39, 0xbef7ff6a, 0x3ec2fdb8, 0x3e0e8193, 0x3d990d34, 
    0xbe7de477, 0xbed23525, 0x3e8da7c3, 0x3e467891, 0xbd830d50, 0xbe7a86fb, 0xbe1671d9, 0x3eaff048, 
    0xbf008d0b, 0xbe2b5979, 0xbd056c26, 0xbf0cb062, 0x3e973178, 0x3e16343f, 0xbe7d35c1, 0x3dace5d6, 
    0xbe7f1e9e, 0xbdda55d8, 0x3f08198c, 0x3ece58f9, 0xbee515e4, 0xbec57603, 0x3e70e435, 0xbec992ce, 
    0x3da50617, 0xbeb45979, 0xbe9541cc, 0x3e02c335, 0xbe82f72b, 0x3dda0566, 0xbc97e419, 0x3e9fd0d2, 
    0x3e1f9094, 0xbe90c9e0, 0x3e2551c8, 0x3e403ba8, 0x3ef1e57b, 0x3ed203b8, 0x3e1ffa32, 0x3e8b9fa1, 
    0xbe70c541, 0xbf0afb43, 0x3e7dd6e5, 0xbee93c86, 0x3de5748b, 0xbe599f03, 0xbef75e2f, 0x3eecb1f9, 
    0xbe90bf0f, 0xbef460c4, 0x3ea5aa8b, 0xbdd03676, 0xbede20d9, 0x3e0c39c4, 0x3b5ddc01, 0xbf1fb610, 
    0x3ee03f44, 0xbe4ea2f1, 0xbd85c069, 0x3e668683, 0x3dace05e, 0xbea09198, 0xbeaf4ac4, 0xbeabdc8a, 
    0xbe98999e, 0xbd305f62, 0xbe8d9ad7, 0xbe213e95, 0x3e6fc688, 0x3ed67ff9, 0xbc7a1547, 0xbcd89638, 
    0xbe22f1f0, 0xbef7eb3f, 0x3eadc177, 0xbec38905, 0xbe97b26b, 0x3eee110b, 0x3d97aab6, 0x3e5113c4, 
    0x3ed92be2, 0x3e0cf09c, 0x3c072fa7, 0x3e7025b5, 0xbeebd810, 0xbe20ed81, 0x3dd08966, 0xbda96f0a, 
    0x3e961d9f, 0xbe512be6, 0x3ecb844e, 0xbec4428c, 0xbe9db667, 0xbd41090d, 0x3c939272, 0x3e95cca1, 
    0x3ccdfbbe, 0x3eaf74e6, 0x3ec31d44, 0xbe3dab31, 0xbd0aefb5, 0x3e886c55, 0xbea71e71, 0xbd909538, 
    0x3de1ad62, 0xbe826faa, 0x3e7e02d4, 0x3ea62c66, 0x3e302aa3, 0xbeb49442, 0xbe189384, 0x3e8d659b, 
    0x3e459854, 0x3cab2bd9, 0xbd9a9a69, 0x3e1b1f30, 0xbe8f4881, 0x3c304dcd, 0x3ea9cba4, 0xbe94cfb4, 
    0x3ddd3430, 0xbeea96eb, 0xbd02a12d, 0xbed7af29, 0xbecbb63d, 0xbeb50937, 0xbea6816a, 0xbeb34b87, 
    0x3ec40484, 0x3e7f370c, 0xbbbc622c, 0x3eb3cc10, 0x3c2d640f, 0x3ebff392, 0xbe521ed5, 0xbea3bf7e, 
    0xbe367759, 0x3ed31816, 0x3edd70cc, 0xbe669d5e, 0xbe33bf69, 0x3f0f84d8, 0x3ec4ae7f, 0x3d8cc684, 
    0xbef65ffe, 0xbea531b1, 0xbe98d60a, 0xbdc80daa, 0x3e35fef3, 0x3e8de6cd, 0xbe43c3ec, 0xbeb29f87, 
    0x3eaa94dc, 0x3e8797a5, 0xbe50c690, 0x3e587286, 0xbdfdaf66, 0x3df4cd06, 0x3ef6b655, 0xbefc06a4, 
    0xbeaf582f, 0xbdce7484, 0xbdf15752, 0xbe7d7ea0, 0xbcbeea50, 0x3d80ef7c, 0xbea06046, 0x3d6f59d1, 
    0xbbbd299d, 0x3edf9910, 0x3e7dcdaf, 0x3c078771, 0xbe386c8d, 0x3e6f1a12, 0xbd83f1ab, 0xbd44c554, 
    0xbe9248eb, 0x3dd2bfc3, 0x3e9fbc51, 0xbeaac6fa, 0xbcc88af8, 0xbe98c77f, 0x3e402f59, 0x3e882c2d, 
    0xbd0d611c, 0xbebc920f, 0xbeaf7b4b, 0x3eb012a7, 0xbe56d97b, 0xbe3dda7c, 0xbec6dcf6, 0x3eb5d572, 
    0x3d2a06ba, 0x3d24b35b, 0x3ebac009, 0xbe60bc3f, 0x3e80886a, 0x3ed08fe1, 0xbeab08c3, 0xbe05ef05, 
    0x3dd004ca, 0xbc020235, 0x3d9841bd, 0x3ce4af17, 0x3e479648, 0x3eb148ba, 0xbebe683f, 0x3e64ed02, 
    0xbc7ebe69, 0x3d424739, 0x3e20c83b, 0x3cdd36b3, 0xbe6a0a8e, 0xbdd05935, 0x3e1b1abb, 0xbe73c4d5, 
    0x3e30b4cf, 0xbe14849c, 0x3ea8ccb0, 0xbe7fba63, 0xbed00556, 0xbe1316b8, 0xbebd4b73, 0x3e892efa, 
    0xbe7b5fde, 0xbe85d31b, 0xbe4deb35, 0x3c4265fa, 0xbdee8907, 0xbe7b6b05, 0x3e575bca, 0xbd52d443, 
    0x3e8f1aa1, 0x3dfc9006, 0xbda11543, 0x3d3e7473, 0xbeb9a11c, 0xbc06cf6c, 0xbec7994e, 0x3dd93ce2, 
    0xbe3438a9, 0xbe7b2988, 0x3eaab17f, 0x3eaeca8d, 0x3dd98ffd, 0xbcc3ec4c, 0xbe647366, 0x3e80111e, 
    0xbc2a61eb, 0x3e1efef1, 0x3e217cb3, 0x3e28c802, 0x3e3b7c3a, 0xbea3bba2, 0x3ddf4319, 0x3e16f75c, 
    0x3e726ab0, 0x3eafae2b, 0x3eb25fb1, 0xbefafe61, 0xbe67ad78, 0x3f049be9, 0x3f013323, 0xbd62fa60, 
    0x3ea4c28a, 0xbef76ff3, 0xbe812658, 0x3ece0116, 0x3da8fc85, 0xbe8c28fc, 0x3ebb9e0e, 0xbf0ce35f, 
    0x3e243173, 0x3e7c102c, 0xbef5318b, 0x3e0b263e, 0x3e41958c, 0x3ee95802, 0xbd762c95, 0xbd942b86, 
    0x3edafa01, 0xbf0b8fb0, 0x3ee573f1, 0x3e77505b, 0xbee17d1d, 0x3ea3a000, 0xbdb64f31, 0xbf1689a5, 
    0xbf073b63, 0xbe730d93, 0x3e8e6a90, 0xbcbd8e9f, 0x3f09e4f7, 0xbe99f230, 0x3d04145c, 0x3de04c20, 
    0xbd16ba60, 0x3e520b59, 0x3d9ce22e, 0x3deecc74, 0xbeea0f04, 0xbeb2fded, 0xbebc86a7, 0xbe220530, 
    0x3e31f83c, 0xbe94f9ae, 0xbdda77b0, 0x3eba55af, 0x3e814142, 0xbee21360, 0x3f0f80aa, 0x3ee39607, 
    0xbdf11d26, 0x3e8a8d48, 0x3ee244fe, 0xbdc39bba, 0x3e9c7244, 0xbe6bd444, 0xbed54cfc, 0xbf146157, 
    0x3e9a7276, 0x3e87ff25, 0x3e317b38, 0xbd4e93ac, 0xbee0b95a, 0xbee479f2, 0xbd023f67, 0xbecf9d4c, 
    0xbc5716dd, 0xbccac84f, 0xbe86b873, 0xbefede44, 0x3d84c2a7, 0xbeb658f7, 0x3f050b23, 0x3d72e523, 
    0xbe247eea, 0xbe57f789, 0x3ed541e1, 0xbdefe824, 0xbe7d210d, 0x3e7fdd15, 0x3d9d2704, 0xbeabf8a7, 
    0xbee40c96, 0xbe9c932c, 0xbe7253d1, 0x3e902a98, 0x3f060dc2, 0xbeb7a6f8, 0xbf07dcd6, 0x3e214309, 
    0xbebfd205, 0x3ef708d7, 0x3e91c6e6, 0x3dd7673e, 0xbf04743c, 0x3bad5100, 0xbe903ae5, 0x3e7327bd, 
    0xbe1d1827, 0xbe865ad7, 0xbdad5b8a, 0xbeb9fe7f, 0xbe6172d0, 0xbd2318ad, 0x3e47a379, 0xbe367ec8, 
    0x3d387a1b, 0xbed43ec5, 0xbd469a5d, 0x3dbbe669, 0xbe025fbc, 0xbd898a86, 0x3e8771cc, 0x3e945a58, 
    0xbd65291b, 0xbd8344c0, 0x3e9580da, 0x3e110d54, 0x3e4f5b91, 0x3db4d290, 0x3ec15a7b, 0xbc45f7f4, 
    0x3c864fec, 0xbea61fb6, 0xbe2aae85, 0xbec659ef, 0xbe58133b, 0x3e3b6bcf, 0xbf041306, 0x3e25ddc2, 
    0xbe06f93a, 0xbe9070f7, 0xbc3ba2ab, 0x3d9c189f, 0x3d515560, 0x3de47572, 0x3ec3201e, 0x3ea529ba, 
    0x3e9c0528, 0xbec7857c, 0x3ea4032f, 0x3eb86976, 0x3e0ba6e9, 0x3e4e3cb5, 0x3e905593, 0x3e442a25, 
    0xbe0b9c5f, 0x3dc0d8c5, 0x3e9ef5bc, 0xbe67448a, 0x3d68c90f, 0xbe063720, 0xbe8d9bba, 0x3d67e2cd, 
    0x3e4b3695, 0x3dc95587, 0xbccd908b, 0x3eb443db, 0xbebf63c3, 0xbe5d2daa, 0x3ebc1c09, 0xbed1b17b, 
    0xbe841f8d, 0x3e6e69c7, 0x3db0fb8c, 0x3ed39a77, 0x3ddcfc8c, 0xbead6b8b, 0x3d9bba1f, 0xbecf6ed5, 
    0xbe988b24, 0xbe87ff42, 0xbeb60b7d, 0xbe8808c6, 0xbedd2605, 0xbdd73baa, 0x3ea1c865, 0x3e04d02a, 
    0xbea75494, 0xbeb136fa, 0xbead9125, 0xbdfa2855, 0x3c7e03b8, 0xbeda4c37, 0xbe575cf8, 0x3ecac400, 
    0x3d3c155a, 0xbe946e7b, 0x3ee1cc9d, 0xbe878afa, 0x3ea4062f, 0xbec390c7, 0xbe9f843d, 0x3eadb6f7, 
    0xbecda87d, 0x3d1a617e, 0xbe19f574, 0x3e18b63e, 0xbe495b7b, 0xbdf7cc20, 0x3cb23267, 0x3ba45e7b, 
    0xbe7a2dae, 0x3e8f6dad, 0xbcfd26a9, 0xbedc968e, 0xbe77701a, 0xbe079c75, 0xbed1176a, 0x3e9cf430, 
    0xbe91c01d, 0xbe87728e, 0xbed9c634, 0xbe6f9a21, 0xbdd474fa, 0x3dc2c96d, 0x3e3acbbc, 0x3e7d3e58, 
    0xbe067264, 0x3d02eb46, 0x3d15b072, 0x3ee7c640, 0xbd3101cf, 0xbde71c82, 0x3e827014, 0xbb9c2dc5, 
    0xbec53539, 0x3e078799, 0x3ea7d626, 0xbe075a23, 0x3e4ee40f, 0x3e96a8c2, 0x3eccb98c, 0xbe936131, 
    0xbe41367c, 0xbe21123b, 0xbe82242e, 0xbebfe8f4, 0xbecc6dea, 0x3eb791e7, 0x3ec822c0, 0x3e81cf6e, 
    0x3e5dc1bd, 0x3d64d474, 0xbe926ce8, 0x3e9a9dc9, 0xbd90e7d0, 0xbdff85f4, 0xbda7d132, 0xbec5eb86, 
    0xbe1adb2b, 0xbd206702, 0xbec3d54b, 0xbe9622c9, 0xbdff28f9, 0x3d77bdb1, 0xbe049d34, 0x3ed6f085, 
    0x3eae0970, 0x3e974272, 0x3d019a3c, 0x3e0b4c7e, 0xbef0934a, 0x3e64f0cd, 0xbe8d8c3d, 0xbe9cb5c3, 
    0x3dfbf3f1, 0x3ed6715f, 0xbe87cc9c, 0xbe89de9f, 0x3b7e7b18, 0x3ec05fe7, 0x3e82bed3, 0x3e7d6100, 
    0xbe75e3b1, 0x3d8cd6c4, 0x3e82507f, 0x3d4cfc18, 0xbd81adb9, 0xbeb33a63, 0xbdb9abf6, 0x3edc5eb8, 
    0x3d56fe68, 0x3d2650e7, 0xbe6d5add, 0xbef16d54, 0x3e64e262, 0x3e7ba0fb, 0xbe085a63, 0x3eb082ec, 
    0xbe3a8ba3, 0xbe83a8b1, 0x3e98958c, 0x3de70203, 0xbe90720c, 0x3e05ff92, 0xbe951bf9, 0xbe2191ec, 
    0x3e92ff11, 0xbe2da77c, 0x3ed5ed55, 0xbd12cfdd, 0x3ec5ff02, 0x3ccb3b29, 0xbe4923ba, 0xbcb76baa, 
    0xbcbfcde9, 0xbe4d69c6, 0xbe21fb64, 0xbd49b8a9, 0x3eb3b849, 0xbecf2440, 0x3eceff9d, 0xbe4e45fc, 
    0x3f0f11e2, 0xbdaeaeb0, 0xbdbd075c, 0x3e7c0b4c, 0xbded0612, 0x3e024d25, 0x3e1fc7e0, 0xbea53183, 
    0x3e39baf5, 0x3e186563, 0x3e95b1b9, 0xbe21dd4a, 0x3ec2255c, 0xbe219f7b, 0xba8c19a7, 0xbe9078cc, 
    0x3eb44c54, 0xbe452d79, 0xbe020fc3, 0x3ea5d5de, 0x3da8c123, 0x3e6187bf, 0xbe932771, 0x3e8962f8, 
    0xbef2d401, 0x3ebfb496, 0x3ec69998, 0x3eb4893a, 0x3e7325b4, 0x3e9b4bfc, 0xbe1f31e8, 0xbe37479c, 
    0xbe872ab9, 0xbede60a8, 0x3dc6b828, 0x3e765328, 0x3f091dd8, 0xbd2d5a7b, 0x3e81fa26, 0x3eb9b1cc, 
    0xbe817fab, 0x3e5bbcf3, 0xbe39fa83, 0x3e822006, 0xbec433f0, 0x3d0eef1c, 0xbed9e9d9, 0x3da42cfe, 
    0x3e1d3841, 0x3ec193d8, 0x3dfe3722, 0x3ce65f22, 0x3e437ad0, 0xbe9bfbdc, 0xbe99113e, 0xbeafbbd2, 
    0xbed3d8d0, 0x3ae591e0, 0x3ead38d4, 0x3ed14d82, 0x3eb4aeac, 0xbdfc6d71, 0x3ef27596, 0xbdf80ed0, 
    0x3e01539e, 0xbe033e1c, 0xbd1c75cb, 0xbe269586, 0xbeab65b4, 0xbc2df7fb, 0x3e91b71a, 0x3d16f9b7, 
    0x3ed27f60, 0xbd60da8b, 0x3e2187da, 0x3e818bf9, 0x3e2c49a1, 0xbd53c9d7, 0xbc23f868, 0x3ebb9335, 
    0xbe032fad, 0xbe39b078, 0x3e8a2688, 0x3eec0073, 0x3ed87188, 0xbefabd70, 0xbed6bcc2, 0x3e91dafe, 
    0x3c6ac1e6, 0x3ec3dcac, 0x3e81671c, 0x3f069a6a, 0x3e274e68, 0xbda29cbe, 0xbe1971d0, 0xbed30273, 
    0x3edf0751, 0xbe41bfed, 0x3ee4a6b7, 0x3db511f4, 0x3ed8c45e, 0x3ec3e540, 0xbda00941, 0x3e55373f, 
    0x3e74f441, 0xbe8b5bb0, 0xbeeaeccd, 0x3ed368b4, 0xbf0f48a8, 0xbdbff7be, 0x3f170783, 0x3e072289, 
    0x3e661f01, 0xbe3b5817, 0xbd6d27ef, 0xbd030c1e, 0x3ec1d2aa, 0x3ec4c5e3, 0x3ef8632f, 0x3e5dfb98, 
    0xbda7b6f0, 0xbecd250c, 0xbe7f4f9b, 0x3e7dade3, 0xbdb5283e, 0xbeeddc49, 0x3e510b37, 0xbe88ee6f, 
    0x3ed5424c, 0x3f04d9b5, 0x3eff813e, 0x3ee28673, 0xbf19b4f4, 0xbeeba9d3, 0x3e49560b, 0x3e86b77f, 
    0x3e987756, 0x3d5df09c, 0xbed402c1, 0xbe2ae945, 0x3ee46097, 0xbed3d1b1, 0x3de65703, 0xbf14b726, 
    0xbedc3cf0, 0x3edd5571, 0xbd957432, 0x3ebbf9eb, 0xbea3d163, 0x3dad14df, 0x3ec247e8, 0x3efdf6ce, 
    0xbea7079f, 0xbd5c6ecf, 0x3ec30015, 0x3d349e09, 0x3edd1092, 0xbec42d52, 0x3eaf91e7, 0x3e4d60a1, 
    0xbed8aa1b, 0xbea86b6e, 0x3e1f7187, 0xbea2a06b, 0x3eb31898, 0x3ec30efe, 0x3d5d3b38, 0x3db250ca, 
    0xbeef7ca0, 0x3e5757de, 0x3ee81fd8, 0xbd0478d5, 0x3ea6ca35, 0xbeec90d1, 0x3ed1af71, 0x3e697dbe, 
    0xbe82073c, 0xbda147ff, 0xbe5fba19, 0x3e9cb2a9, 0x3dd357d9, 0xbe42ddba, 0x3ea83cac, 0xbed63a37, 
    0x3e1f6ad8, 0xbe6547b3, 0x3e938626, 0x3ea73937, 0x3e1e4c0b, 0x3e31aff9, 0xbeca1991, 0xbe00b568, 
    0x3e55a8c7, 0x3e1f3888, 0x3eab9ed7, 0x3cad7898, 0xbe052ca2, 0x3dc43e92, 0xbe6028ac, 0xbecf90c1, 
    0x3e3a634b, 0x3eaf3ad2, 0xbdf894a0, 0x3e913324, 0xbedc3f3c, 0x3e081b12, 0x3d084fef, 0xbdd06471, 
    0x3e155961, 0x3e705909, 0xbd1217fc, 0xbeb3cbe7, 0x3e8691e3, 0xbe79ced2, 0x3c933568, 0xbc1469cc, 
    0xbe190712, 0xbeb4cad9, 0x3e8fcd82, 0x3e5b3a6c, 0xbea554c5, 0x3e90f81d, 0x3e7ddcaa, 0xbdb4f25f, 
    0xbeaf4dd1, 0xbecedf56, 0xbe00ca6a, 0xbe2a87b4, 0xbeda2b55, 0xbead748b, 0xbebbb05f, 0x3dbe64a1, 
    0xbeb9edbe, 0x3e869c7e, 0x3edc19ba, 0x3e9a1165, 0xbe3c39f4, 0x3e8f77fe, 0xbea145e0, 0x3ea71c43, 
    0xbddcad7b, 0xbd7cf19d, 0x3da5e4f8, 0xbd956fc4, 0xbe9f5582, 0x3eafeb91, 0x3e1dcc34, 0xbede6c9f, 
    0x3d57dae4, 0x3e819fb8, 0xbe653aa4, 0x3e719472, 0xbe7cb5da, 0xbe00e9ff, 0x3e83cf63, 0xbda18d50, 
    0x3dc21cba, 0xbe8cd58c, 0x3ceebb4a, 0xbebefd74, 0xbe84c4d9, 0xbe8347e5, 0xbe7b2c3c, 0x3e5caeb4, 
    0x3d5ff6b4, 0xbe51d8c6, 0xbedeaaac, 0xbd329bd5, 0x3e88a744, 0x3ea4970a, 0x3e8f89c8, 0x3e87ddba, 
    0xbd62582d, 0x3ee70752, 0xbd9006f4, 0xbe987837, 0xbd30678e, 0x3ec59ddd, 0xbea42e52, 0xbe8d208f, 
    0xbdf15404, 0xbebf2b40, 0x3e5db101, 0x3eb44402, 0x3e4cc0b4, 0x3d26de18, 0x3eb92c09, 0x3e28115f, 
    0xbe6f60c0, 0x3dedc1ba, 0x3e758be0, 0x3e9e2afc, 0x3e2f6d31, 0xbe84ca1d, 0x3ef9f836, 0xbe10ab42, 
    0x3e8db5be, 0xbead9e03, 0xbe975bc7, 0xbe5e3ea4, 0xbe185322, 0xbe9cdcc9, 0xbea04170, 0xbe282eb4, 
    0x3e0718dd, 0xbebc11db, 0xbeb42841, 0x3e5c96f8, 0xbe2507e5, 0x3e511820, 0x3c45cfd8, 0x3e050119, 
    0xbe674194, 0xbeb3bbbd, 0x3ec4e030, 0x3ea3fac4, 0x3ea22bcd, 0x3e91da41, 0x3b30ceb4, 0x3ecb008e, 
    0xbe5cd706, 0x3d004d4f, 0x3db9e0eb, 0x3d270ad6, 0x3e49fd58, 0xbefc2578, 0xbe88e73c, 0x3ea7a663, 
    0x3bb804b1, 0x3e0e5567, 0xbea2197b, 0xbe34f5f5, 0x3ee6132c, 0xbe80391d, 0xbecde5b3, 0x3c8f64fd, 
    0xbecfe882, 0x3ec29590, 0x3d22fe0a, 0x3d77df9f, 0x3ee8b63c, 0xbe6bd54f, 0x3e475f4d, 0xbead7e47, 
    0x3e2b1634, 0xbedc5b1b, 0x3e8def82, 0xbea9cdb5, 0x3e9f54ec, 0xbe132307, 0x3f0784ee, 0xbd293043, 
    0x3ec64b67, 0xbea4b3ba, 0xbbb767f7, 0x3e5f09a0, 0xbe48ec5a, 0x3eb3094e, 0xbe2e8b48, 0x3e9a8a67, 
    0x3c73494a, 0x3ed889a0, 0xbec1126b, 0x3ec7ad4a, 0x3e997af5, 0x3ea4f7fd, 0x3ea6b8ab, 0x3ddcccfd, 
    0xbe36c97a, 0xbc9db60e, 0x3d8aef92, 0x3e93348a, 0x3e6b6b79, 0xbe9f2247, 0xbecd5f3d, 0x3daadeb7, 
    0xbe63ec1d, 0x3eaa7ed1, 0x3c33779b, 0xbe297153, 0xbea420b6, 0xbec6fab1, 0xbd9e2809, 0x3d85c902, 
    0xbea2ff06, 0xbeb82fdf, 0x3e83eb06, 0x3dc78472, 0x3b49d3ec, 0xbe8dcd7e, 0xbe036768, 0xbe86fe09, 
    0xbe343eca, 0x3f012773, 0x3eaabaad, 0x3e20674f, 0xbe9202cc, 0xbe6c732e, 0xbc6e2bc0, 0xbe1c3b1d, 
    0x3eb850f3, 0xbdd67757, 0x3e4c15b2, 0x3eb3736f, 0xbe07ab9b, 0xbeda0217, 0x3e88f4df, 0xbe94f686, 
    0xbbe9e672, 0xbe98d6a1, 0x3eb70db0, 0x3e09c652, 0xbed5e7cf, 0xbe9ed87b, 0x3dd5fc97, 0x3ea2e30b, 
    0xbe20ee1a, 0xbcdf8fee, 0x3e9c5074, 0xbd90a8d5, 0xbc431bce, 0xbe76d7ee, 0xbdbd6245, 0x3e1e85a1, 
    0x3e776c24, 0xbe1038aa, 0x3e68c7a1, 0xbe9cbe72, 0x3ea670a6, 0x3ec24e6c, 0x3caba3c8, 0xbeca3c1a, 
    0xbe97f306, 0xbed3d7a9, 0x3eb73f3f, 0x3e36e879, 0xbde42441, 0x3e97ff7a, 0x3dda4579, 0x3e4dc3d5, 
    0xbce7fcf7, 0x3de8fae0, 0x3ebbf584, 0x3ee835a9, 0xbbea4444, 0xbed734c7, 0xbf0d4969, 0xbe0d222a, 
    0x3e5893a3, 0x3e498b60, 0x3e80a124, 0x3e30010f, 0xbed026c6, 0x3d16d7ea, 0x3da04c2c, 0x3ed4f66a, 
    0x3e941e0f, 0x3e05067a, 0xbde6ae3f, 0x3ef6a453, 0x3e63fb40, 0xbd2c70f3, 0x3eebd13e, 0xbc66c7b2, 
    0xbee07179, 0x3e256a5b, 0xbd260807, 0xbed330a5, 0x3ef506db, 0xbece6617, 0xbd89ae81, 0xbe35d978, 
    0xbf1413bd, 0x3ed066dd, 0x3e4d978f, 0x3e544f50, 0x3e6487dc, 0x3ec74d15, 0x3ef448b3, 0x3e14e8d2, 
    0xbdb88434, 0xbc1a755d, 0x3b980f01, 0x3d81aa0e, 0x3ee8b20e, 0x3ea16573, 0x3ee4a7da, 0x3e8f2839, 
    0xbede329e, 0xbf0af531, 0xbe4adbc6, 0xbdff4cd6, 0x3e1a91da, 0x3e937445, 0xbe83d43b, 0xbee9807e, 
    0x3ed10823, 0xbeeaf9e8, 0xbecddb09, 0x3ee90f6d, 0x3d1ae55e, 0x3ad7eb5a, 0x3ef9e29a, 0xbe54f2d4, 
    0x3eaa6d5b, 0xbe985c23, 0xbd107ab4, 0xbef1609a, 0x3f08128d, 0x3d90f694, 0xbdd1a17d, 0xbe84650f, 
    0xbe0d332c, 0x3eedf96a, 0x3e62534b, 0x3ee2ffce, 0xbeaa2e44, 0x3ed8e1da, 0xbe684193, 0xbe91d51f, 
    0xbe2bbc95, 0xbda6ab37, 0xbe1f1153, 0x3e2bc3fd, 0xbca773c7, 0x3ef0f826, 0xbecfc233, 0xbe561fe8, 
    0xbe9bad93, 0x3e6c3441, 0xbef89cdf, 0xbe30b78e, 0x3ee0352a, 0x3e71233c, 0xbf0d5dc1, 0x3e9bd03b, 
    0xbe8803b7, 0xbb1865b1, 0xbda008b8, 0xbeadffdb, 0x3e97709f, 0xbe93cc8b, 0x3eb6d595, 0x3e7ad94f, 
    0xbf141a28, 0x3dd316b3, 0x3eef96c7, 0xbe34f54b, 0xbc1c3400, 0xbe852617, 0x3e12d1da, 0xbdf328d1, 
    0xbe035304, 0xbe3041a8, 0xbe8a5476, 0xbe9152b4, 0x3edffc33, 0xbe9e60c2, 0x3ea570dc, 0xbe9053d5, 
    0xbe2c58c0, 0xbe03bcba, 0xbe37b633, 0xbdb10443, 0x3aef7c1b, 0xbebe9084, 0x3e436469, 0x3eb1230a, 
    0xbebbce2c, 0xbe6c29e1, 0xbecc0aa1, 0xbd12f205, 0x3dce043e, 0x3e0d1910, 0x3eaa6501, 0xbe85e617, 
    0xbdb02212, 0x3ecd45c4, 0x3e56e14c, 0xbe873232, 0x3d808974, 0xbd840cd7, 0xbe3408c7, 0xbda63e05, 
    0x3e3ae87c, 0xbe817b43, 0xbdde848b, 0x3ee5f39e, 0xbdf59ed4, 0x3e231ff8, 0x3e581a93, 0x3ea03600, 
    0x3eb7e1d0, 0x3dc6cafe, 0x3dcab576, 0xbb78cf1f, 0xbe752d78, 0xbe77646e, 0xbdd2b244, 0xbdaa1b7b, 
    0x3e947741, 0x3d485567, 0x3ede7b5e, 0x3e2566f1, 0xbdcedbe7, 0x3e988b3d, 0x3eb9a855, 0xbcd6692e, 
    0x3e66b232, 0xbe97bdba, 0x3e299e23, 0xbe9a1757, 0xbedf74e9, 0x3ee4dec8, 0x3e5c75b2, 0x3c53cb37, 
    0x3e53bc97, 0xbe7eb8ab, 0xbeb2c304, 0x3def0292, 0x3eb107cb, 0xbe344564, 0x3ea103fe, 0x3b36ef94, 
    0x3c3809f2, 0xbd3dd4fb, 0xbebbcf47, 0x3dc76069, 0x3cc85c68, 0xbea09d76, 0xbeac3fe9, 0x3efa06f8, 
    0x3de4d364, 0xbd98bd57, 0xbe133b41, 0xbed8396b, 0x3e4c110f, 0x3dfe7854, 0x3e20a731, 0x3e6300db, 
    0x3e439468, 0x3daa7d37, 0x3e9c1e84, 0x3edd7892, 0xbeb1efba, 0x3e1046b8, 0xbe1e2408, 0xbee3e561, 
    0x3dd3aaa8, 0x3d433d7a, 0xbeb0d08e, 0xbe8591ea, 0xbf0001c6, 0xbe0236f9, 0x3e6b3ddb, 0x3ef51a29, 
    0xbf0b64e9, 0xbe8b99b6, 0xbed5d1c8, 0x3e4ecc1b, 0xbe68496a, 0xbebbcb12, 0x3e33e56b, 0x3d856aa1, 
    0x3e0822c0, 0x3d2cf06a, 0xbde1e538, 0xbe92b88a, 0x3ce35cfe, 0xbd9ea356, 0x3ec1c2c1, 0xbea478f7, 
    0x3e67f426, 0x3e9ed840, 0x3e341ad9, 0x3f195e7a, 0x3e94dd2e, 0xbf074513, 0xbe4dedb8, 0xbf058d03, 
    0x3e6ea8dd, 0xbe28419b, 0xbf04ce8d, 0x3e42137b, 0x3d8f7309, 0xbed46924, 0x3d1732e4, 0x3f0de3ab, 
    0x3edd954d, 0x3ec6b485, 0x3e65941c, 0xbe8ffff2, 0x3ef4eed6, 0xbde59ef4, 0x3e90d071, 0xbefca07c, 
    0x3f0a2dc1, 0xbc45c1bf, 0xbe8b66df, 0xbe72620d, 0xbe259bd3, 0x3ef4beb1, 0x3f213127, 0xbedbdcbd, 
    0x3dcbe5f2, 0xbe9f1d54, 0x3eb93cee, 0x3ea63079, 0x3eb426d3, 0xbe913d67, 0x3e866ebc, 0xbe4864bf, 
    0xbd010a21, 0xbeb0f6e6, 0x3eb2f069, 0xbe652e9b, 0x3f062506, 0xbe68fa1a, 0xbdf2671b, 0x3ee10c57, 
    0xbea1f3f8, 0x3de39228, 0xbef9ca20, 0xbd5cb22d, 0x3e3e9e6f, 0xbeeff7fa, 0xbe1be41f, 0xbd9d04e9, 
    0x3ee02e30, 0x3ea82731, 0x3e22316a, 0xbe4e57a1, 0x3e1ae584, 0x3d68cbe7, 0x3eb1a834, 0xbe1c186f, 
    0xbdd5139e, 0x3ecfc855, 0xbebbdbb0, 0xbeaf1f94, 0xbe4dce14, 0x3c199e72, 0x3e473760, 0xbe3e03c2, 
    0xbe8a582d, 0xbd9ba074, 0xbe237430, 0xbc93af87, 0xbb5905f7, 0xbdfe9b8b, 0x3e21a99e, 0x3eeab305, 
    0xbe902bef, 0x3e910dfa, 0x3eb24c72, 0x3dbae7ae, 0xbe7212bc, 0xbe88e287, 0xbe695a66, 0xbe117ea5, 
    0x3dabfac0, 0xbd9e16aa, 0xbe315573, 0xbdd6c990, 0xbec37615, 0xbe80c32f, 0xbe6cf5de, 0xbccb7508, 
    0xbde05eed, 0xbe92a9cc, 0xbd2f7c14, 0xbeb16d24, 0x3dd023df, 0xbe91bc18, 0xbea5d6f5, 0x3e125ddf, 
    0x3cc3d641, 0xbe7bee47, 0x3dc6adcd, 0x3e35452e, 0x3e902f2b, 0x3e0993c9, 0xbe03371e, 0x3d2be983, 
    0x3e33005b, 0xbe376cb9, 0x3e53475a, 0xbe151561, 0xbd56ca91, 0x3e8dcfbf, 0x3e08c718, 0xbdf650ec, 
    0x3e8d7f28, 0xbea3bf08, 0xbd975a57, 0x3d97c3d5, 0xbead6acb, 0x3d9f4dce, 0x3ead2b8a, 0xbc0a7c66, 
    0x3dbd9d02, 0xbd7b02a9, 0x3e590935, 0x3e3f6664, 0x3e908774, 0xbd64e8c8, 0x3e9fe42c, 0x3d009d1c, 
    0x3e97cd9e, 0xbd8520f7, 0x3e5ce922, 0xbe85f2d7, 0xbe009433, 0xbe9335aa, 0xbd6b8b2e, 0x3c47e7de, 
    0xbeaafa47, 0x3e390983, 0x3ecbc130, 0x3d54d546, 0x3ca96236, 0xbdbee0be, 0x3e1376c8, 0xbd6d90b9, 
    0x3ca478ec, 0xbebfb2d5, 0xbce27836, 0x3eba5174, 0xbe5edf78, 0xbe904462, 0x3d1f305e, 0xbe853345, 
    0xbe00d7af, 0xbc8176b7, 0xbdfa4739, 0x3e145b27, 0x3f18c899, 0x3f0286cc, 0x3e9eeac3, 0x3e5f2f3b, 
    0xbeebf7c2, 0xbefde45d, 0xbd9b3745, 0x3ec5b281, 0x3b729cff, 0xbe1a7411, 0x3bb24825, 0x3f0cf8af, 
    0xbd902582, 0x3f1483ef, 0xbebcab33, 0x3e972fea, 0xbe9a1de3, 0x3efac235, 0xbe5d527f, 0xbd95bcf3, 
    0xbe737965, 0xbdcc50a7, 0xbf135238, 0x3f080b1c, 0xbe492aa8, 0xbe2bad1d, 0x3e45fe99, 0x3ebc9b00, 
    0xbe2722f2, 0x3cd9e05b, 0x3e49f7e9, 0xbed3ea76, 0x3dfe4f4a, 0xbe8b59fb, 0xbeed4e99, 0xbd490984, 
    0xbe7deacf, 0xbef1ca93, 0xbd4fb793, 0xbe8fef41, 0xbec22ed7, 0x3f1cdffa, 0x3eed437f, 0x3ed60f68, 
    0x3ec2456c, 0x3e825a69, 0x3e99b159, 0xbeb70b01, 0x3ebc844d, 0xbf034c13, 0xbe82e07b, 0xbe965d6c, 
    0x3f13f4d4, 0x3ee7ee02, 0x3d88c1fb, 0xbef7ee9b, 0x3e3aa4c3, 0xbecaeffc, 0xbebdb175, 0xbf0ca724, 
    0x3f0c8870, 0xbedf92cc, 0x3caf9a0a, 0x3de41beb, 0xbe02b13f, 0xbdedcdaa, 0x3ecb95ce, 0xbecfdb95, 
    0x3ef8e3da, 0xbea8fdbc, 0xbe6f11c2, 0xbba9f511, 0x3e8ce624, 0xbea10e89, 0x3e556ef5, 0xbea55a1e, 
    0xbe42de1e, 0xbeee886c, 0x3efdb422, 0xbed1d717, 0xbdad4d98, 0x3ee5cfd6, 0x3e9b5546, 0x3e27da30, 
    0x3d4ca4bc, 0xbf0daba2, 0xbebcce9e, 0xbdba2b47, 0xbe833607, 0x3ec1e687, 0x3e365085, 0xbe720a97, 
    0xbeb0c47b, 0xbd956cee, 0xbeda0011, 0xbe6bf528, 0x3e896fe5, 0xbda73aa1, 0x3e865012, 0xbeaeb4fd, 
    0x3e9848df, 0xbe8dee0b, 0x3e0dbf5c, 0x3dbba2f6, 0xbe79cd4b, 0x3d8e075c, 0x3e5cb9fb, 0x3db4fb1b, 
    0xbd932cc9, 0x3d5f9e9d, 0x3e5f4587, 0x3e8c2fe3, 0x3e1b0798, 0x3ea50864, 0xbce867d8, 0x3e991a01, 
    0x3c285fdd, 0x3e4683d3, 0xbe1e1738, 0xbebde1ee, 0xbe5cdf19, 0x3e308fb5, 0x3d8f77e3, 0x3dbb9272, 
    0xbe0d1f3f, 0xbc750a98, 0xbda3a36c, 0x3d4850f1, 0x3e51846e, 0x3dafdb15, 0xbd2f5423, 0xbebb7b84, 
    0xbe53c4b1, 0x3e7587cd, 0x3e72d710, 0xbe3d5618, 0x3e8d2143, 0xbe0f00bf, 0xbe1efb66, 0x3e686013, 
    0x3e898d0b, 0xbcfcdaec, 0xbe418724, 0xbe82b8f4, 0x3e675654, 0x3e9afd83, 0x3e0e0c65, 0x3e58454e, 
    0xbea5de0e, 0xbe37b9de, 0x3e1b8ddd, 0x3e602fa8, 0xbe1d4410, 0xbc338a11, 0xbe3b60a4, 0x3de21e7b, 
    0xbe0bf1fa, 0x3cc2bf00, 0xbdf5254b, 0x3e34aa4f, 0x3e276e63, 0xbea31ecd, 0x3e9f5656, 0xbea6a1d0, 
    0xbc21cc74, 0x3dafe9f6, 0xbe91194b, 0xbdbaf73d, 0x3eab1377, 0xbd04e425, 0x3e68cf6f, 0x3d92bdcf, 
    0xbd7bb893, 0xbe8f9dad, 0x3e07bbd7, 0xbe125608, 0xbdf52f7b, 0x3eb41150, 0xbe88eb69, 0x3e63881e, 
    0xbdedb61d, 0x3e32278e, 0xbdfdb782, 0xbe2af80c, 0xbe40c5db, 0x3de1734f, 0xbe20b062, 0xbd8b9df1, 
    0x3da75591, 0x3dc31fce, 0xbde455f6, 0x3dac30e0, 0x3d9e9d57, 0xbe198d29, 0xbe1937a1, 0x3e29ed6b, 
    0xbe405c9a, 0xbd5bbe28, 0x3e83010a, 0x3e4399cb, 0x3e173178, 0xbe10a704, 0x3d8c1976, 0xbe829f46, 
    0x3e28ab3f, 0x3e437836, 0xbe1059f2, 0xbe7bbc41, 0xbe99807c, 0x3e5fb60f, 0xbe317518, 0x3dac7b30, 
    0x3e32d752, 0x3dbcce03, 0xbe7a6dc1, 0xbe24accc, 0xbd42473f, 0x3e5fd1d5, 0xbe661496, 0x3e0cd65c, 
    0xbe8e7cde, 0x3d98bfe9, 0x3e44fadd, 0xbe6f501f, 0xbd8558f9, 0xbdd7aa4f, 0x3ea09abe, 0x3e3899b4, 
    0xbe7681a2, 0xbdbd4651, 0xbe52a99f, 0x3dc5d09b, 0x3e565a40, 0x3e83fb13, 0x3e998ad5, 0x3e3ff806, 
    0xbe000076, 0x3d57da17, 0x3e8f4ad9, 0x3dc09444, 0xbdc8a22d, 0x3e4e8ec5, 0x3e2a31a2, 0xbd026644, 
    0xbe174ad4, 0x3d2e9112, 0xbe2e0c3e, 0x3e823e79, 0xbe41cedf, 0xbdeb30e8, 0xbe9361d1, 0x3e5f8782, 
    0x3e6fb10c, 0x3e864309, 0xbdfdfa56, 0x3da45d40, 0xbdd00c4a, 0x3da3c74d, 0x3e7001f2, 0x3d3af5ec, 
    0x3e34fdec, 0xbe9c928d, 0xbea4c906, 0xbe2766fa, 0xbe41b844, 0xbdcf19ed, 0xbe85abe2, 0x3e84fe21, 
    0xbe4a32ad, 0xbea2cef7, 0x3e413637, 0xbe60d09f, 0xbd36ed51, 0xbe001498, 0x3e515a55, 0xbe1fd001, 
    0x3e183dac, 0x3e982a2d, 0x3e7b73f0, 0x3e81d0b0, 0x3e007c1d, 0x3dff6039, 0x3e19172f, 0x3eacc5c8, 
    0xbcd7b97d, 0xbe583d96, 0x3c2ac916, 0x3e3f363c, 0x3cd47b62, 0xbe8ea2e0, 0x3cb63466, 0x3e84aced, 
    0x3e8226f6, 0xbe85365b, 0xbe3b99a9, 0xbbd0a277, 0x3e9b32af, 0x3e049a96, 0x3e764cee, 0x3e8c74a7, 
    0x3e86c091, 0xbdb9bdeb, 0x3e0015d0, 0xbc419190, 0xbe5312be, 0xbe7c9518, 0xbe9cd2d2, 0x3e930813, 
    0xbda45a78, 0xbe27f2ff, 0xbddf33af, 0xbd299843, 0xbe8a6d54, 0x3e966350, 0x3e47ab40, 0x3e3eb5a6, 
    0xbd2335d2, 0xbe7f8a4d, 0xbd88b458, 0x3e43d334, 0xbe2b43ee, 0xbe84c6a0, 0x3e36f3ca, 0x3e8ea0d8, 
    0x3da62f7b, 0x3c8b76fd, 0xbc096c74, 0x3e609f30, 0xbdf5f248, 0x3c4894e3, 0x3e52e8e1, 0x3d5d7b3a, 
    0x3e797312, 0x3e89ac68, 0x3d4884ed, 0xbe9c3d28, 0x3cab4c32, 0x3dcbae68, 0x3e85ebb4, 0xbe5dc393, 
    0xbe711d73, 0x3e78882e, 0xbcc7f783, 0xbe924097, 0x3ec2deae, 0xbcd6671c, 0x3dd2d9bc, 0xbe93ef81, 
    0xbe701143, 0xbe6c61d9, 0xbdd349b9, 0xbea017fd, 0xbbb17151, 0xbc79ce1f, 0x3e1e7a3e, 0xbb9740ca, 
    0xbe1ea226, 0x3cdd001b, 0xbe2e43e3, 0x3e944217, 0x3e975d76, 0x3e5abf00, 0xbeae8855, 0xbe4a85fa, 
    0x3c43b0ad, 0xbd590155, 0x3e3fcd55, 0xbe31d50e, 0x3e1f9e4f, 0x3e2522ae, 0xbe8e648a, 0xbe1a02a9, 
    0xbe5918d7, 0x3e99089a, 0xbdac3407, 0xbcddedc0, 0x3e4fecb2, 0xbe65fef0, 0x3e9fc85a, 0x3ea0b1cc, 
    0xbeae1467, 0xbe566e11, 0xbe4a5438, 0xbe9be31b, 0x3ee43169, 0x3dd954cc, 0xbc463451, 0xbe7556e9, 
    0xbe974ff2, 0x3e88a490, 0xbecb5671, 0xbea42db9, 0xbda5a330, 0x3e244761, 0x3e0bf461, 0x3ef9dbca, 
    0x3c7b806c, 0x3ecfdd60, 0xbe250cc2, 0xbe6d9b68, 0xbd99836e, 0xbd85d76d, 0x3e3e8906, 0xbea90fca, 
    0x3cfc423d, 0x3e25e680, 0x3f00bf4b, 0xbe0c1c70, 0xbe8e94e6, 0xbeab45d8, 0x3e5e8938, 0x3be4a314, 
    0x3ea639e3, 0xbd8ca1c4, 0x3cd9e4d2, 0x3ec52deb, 0xbe4d6460, 0xbdff944b, 0x3e4f2d62, 0xbea6729d, 
    0xbeb928d5, 0x3d7a0bd5, 0xbd87bd40, 0x3e7e2b7d, 0xbd87dfc2, 0x3da57900, 0x3e43235d, 0xbd20e5c4, 
    0xbdf26f85, 0xbcef58de, 0x3ec29d29, 0xbd84efdc, 0xbec0c215, 0x3ea3ce20, 0xbec00c76, 0x3e955050, 
    0xbee58064, 0x3bcf3e83, 0x3e6f353c, 0x3dc1baf4, 0xbde3dec7, 0x3e8b865f, 0xbdb266d3, 0xbe0e43f1, 
    0x3e8e6cf6, 0xbda122b5, 0xbeca62ff, 0x3e5a0faf, 0x3e38f89e, 0x3daed118, 0x3e58e723, 0x3e8f5f5f, 
    0x3dc463f1, 0x3cafe61c, 0xbe7a7d6d, 0x3ea323a8, 0xbe99ca69, 0xbd337b2e, 0xbd21b7cb, 0xbd90247e, 
    0x3e63b9ac, 0xbe918825, 0xbe98c950, 0xbe06a15f, 0x3d3e6930, 0x3cbd68ee, 0xbe595e26, 0xbeb0ba7a, 
    0x3e0f9dba, 0xbdb3e3e9, 0x3e96a8ca, 0x3e0cbb7e, 0xbdc361f2, 0x3f01ae7f, 0x3d88ff7d, 0x3ea705dd, 
    0xbd847616, 0xbc835214, 0xbed76f28, 0xbea36dda, 0xbe17ea04, 0xbe664a13, 0xbc9710aa, 0x3e267ea6, 
    0x3ee507c2, 0xbeba3753, 0xbeabf524, 0xbe6c4041, 0x3eb50ce4, 0x3e84f926, 0xbedfac42, 0xbec621fd, 
    0xbee431dd, 0x3ed4c2eb, 0xbee5863a, 0x3e39bbe5, 0xbd8c6b42, 0x3ef922d5, 0xbe888605, 0xbe5bb081, 
    0x3ee7d4ae, 0xbf0150ce, 0x3ef0efec, 0xbdbd027d, 0xbe973693, 0xbe898a8b, 0xbeea4f44, 0x3eb0cf30, 
    0xbe242f2e, 0x3dbd1790, 0xbeff8602, 0x3e87c78d, 0xbe683569, 0x3e506f9c, 0x3e9ee96a, 0xbdbf6357, 
    0x3cc263c3, 0x3e99c5ce, 0xbe99ce70, 0x3e76b7a4, 0xbce04626, 0xbee31d84, 0xbed19f42, 0xbea2fed0, 
    0xbe9109b1, 0x3dbb9333, 0xbed24565, 0xbef45cf0, 0x3ec5a7d1, 0xbe5d8fa5, 0x3ee9525e, 0xbd2685c2, 
    0x3e37ab5e, 0xbe9a1036, 0x3f0cfd39, 0x3e64c1ff, 0xbe9a1f4f, 0x3edc8c0c, 0xbc8ae8a0, 0x3e6f3123, 
    0xbf11c58e, 0x3e8fc0a2, 0xbeecb84d, 0xbeafe703, 0xbf138278, 0xbcb5c7c9, 0x3efa1a80, 0xbee0b056, 
    0xbed7c591, 0x3e3b003f, 0xbe814f47, 0x3b68165f, 0x3d3a795d, 0x3e72c9e2, 0x3e06df40, 0xbdd0214f, 
    0xbeb09eff, 0xbc3649fc, 0xbdc904f1, 0x3e086c22, 0xbee7277c, 0x3e30f563, 0x3e8a85b7, 0x3dac0b6b, 
    0x3e376bd5, 0x3e0409c6, 0x3db07f3a, 0xbe484af5, 0xbdbab8d7, 0xbeaaa06a, 0xbe91a0d0, 0xbe590edb, 
    0x3e8caa7b, 0xbe77db62, 0x3efe6952, 0xbe83d624, 0xbd3096f4, 0xbeb9dd4c, 0xbe04a657, 0xbe9b2061, 
    0xbc81e59b, 0x3ea0e6a9, 0xbed99516, 0x3e2e774e, 0xbde9ce6d, 0xbeb4c3ab, 0x3e0ba264, 0xbea582dc, 
    0x3e9dc65e, 0xbe7ade49, 0x3e088ad6, 0xbe62b2b4, 0xbe74ced0, 0x3ed1a777, 0xbe0564bf, 0xbe8c4c4b, 
    0xbe9393d6, 0x3e9721c5, 0x3e1c00b5, 0x3e9d47cb, 0xbe0748b3, 0x3e5e6b00, 0x3e6532d2, 0xbdcfd6b9, 
    0x3e67b583, 0xbdf24cf4, 0x3e0b4402, 0x3eb37764, 0x3e99a4a7, 0x3dea7d73, 0x3ea5f793, 0x3e8a9c53, 
    0xbea34f48, 0xbc7f6e70, 0xbe2d33b9, 0xbd986f75, 0xbe685b47, 0xbe97e965, 0x3e8529ef, 0xbbe57828, 
    0xbcbf6ad1, 0xbe5e8b4b, 0xbead6013, 0x3e37d378, 0xbe516375, 0xbd6017e9, 0xbda7df06, 0xbe3f64bb, 
    0x3e29c432, 0x3e889bee, 0xbe7059c5, 0x3eb9cb05, 0xbe9b6629, 0x3d1b233a, 0x3e431f3c, 0xbe72a811, 
    0x3e3dc933, 0x3ec34194, 0x3e83fc5a, 0x3e9f9e8a, 0x3e8a15e8, 0xbe43649a, 0x3c929307, 0x3d3da59f, 
    0x3dc817b3, 0xbe4e2cb0, 0x3e784e06, 0x3e9580d9, 0xbeb70f45, 0xbe5f9982, 0x3e6df000, 0xbe3f75d0, 
    0x3da90250, 0x3d84b69d, 0x3dda6ec5, 0x3e3030b4, 0x3e583ece, 0x3dcf4b74, 0x3ebfd661, 0x3e64ff17, 
    0xbe19d76b, 0x3e34d8cf, 0xbdbc96c3, 0xbde678ea, 0xbdda00e3, 0xbdcb7fce, 0xbebee2e2, 0x3e11a179, 
    0xbe86a74d, 0x3e8532a7, 0x3dc4ff0e, 0x3e0bfe04, 0x3dca0eee, 0x3e54c64f, 0x3db84a2a, 0xbc4195d4, 
    0x3e72a0da, 0xbd7266dd, 0x3e124bfa, 0x3e68458f, 0x3e928e1b, 0x3e119cf9, 0x3e768874, 0xbdcb8f31, 
    0xbdcfc943, 0xbe596a8d, 0x3e4fb115, 0x3e336cf6, 0x3e6107e7, 0x3e704dec, 0xbe04663e, 0xbd9ddfe1, 
    0x3e3b8bf3, 0x3e140435, 0x3e5402e4, 0xbde4bad1, 0xbd572dcf, 0xbe00f53a, 0x3e3cdd15, 0x3de18dbb, 
    0xbbfebeb6, 0x3db4a297, 0x3e05d8c8, 0x3dd86c1c, 0xbe531d34, 0xbda8101e, 0x3e8e9949, 0xbcc71d74, 
    0xbd861d24, 0x3dca4a07, 0xbe8ecdd0, 0xbded13be, 0x3e875451, 0x3dd294ee, 0xbe862c58, 0x3e3ae0ce, 
    0xbd8462e1, 0xbe84fddb, 0x3d62126a, 0xbe0f0d43, 0x3dbd5035, 0x3dbf7ddf, 0xbe17e027, 0x3e4c5927, 
    0xbe5f533c, 0x3dcaa9d9, 0xbdedf8f7, 0x3e40172d, 0x3df3f1fb, 0xbd4e4d05, 0x3d210797, 0x3e1fb0fe, 
    0xbe402304, 0x3cbd96c0, 0xbea1545e, 0xbe2635bf, 0xbda8c752, 0xbe91bba5, 0x3deecb88, 0x3d081d46, 
    0xbe16b0c8, 0x3d097acf, 0xbe8ce488, 0xbe605849, 0x3e9b9cf5, 0x3d9c66b3, 0xbe03a81d, 0x3e8b5122, 
    0x3e151cbf, 0xbe5daaa3, 0x3e8409fc, 0xbde38e98, 0x3e0bbcf0, 0xbe194a6c, 0xbd9d3c59, 0xbe4e1d05, 
    0xbda6efae, 0x3e8bf09a, 0x3e16eb62, 0x3df20dd0, 0xbd6de31e, 0x3de2f285, 0xbe04bf8b, 0x3e0ce622, 
    0xbd52065e, 0x3e697547, 0xbe7b668f, 0x3eefef37, 0xbea5de47, 0xbc9e3f26, 0xbded2535, 0x3ec8ba48, 
    0xbe3c7e8c, 0x3d79b17d, 0xbe28147f, 0xbe0b5c6a, 0xbed21a6f, 0xbd646552, 0x3e7ad8dc, 0x3e85f52a, 
    0xbe974597, 0xbd38826e, 0x3e48403b, 0x3e8aba6b, 0x3ebb48f1, 0xbdd140a6, 0x3da7145a, 0xbe3d3241, 
    0xbcd98f83, 0x3ed1e623, 0x3daeebf2, 0xbba8e590, 0x3de8a675, 0x3d2e89e9, 0xbe465167, 0x3d4f7c18, 
    0x3e31dff1, 0xbe905b8d, 0x3dcb3d37, 0xbe356d8f, 0x3e3809ec, 0xbd9c18c1, 0xbe878371, 0x3e9a1759, 
    0x3ecbb5f9, 0x3d9688d1, 0xbeb80fe0, 0xbe6c56de, 0xbf00e98b, 0xbe858f81, 0xbcfe6922, 0x3ebde768, 
    0xbeade7a9, 0xbe1e45f6, 0x3da96e24, 0x3e206a6e, 0x3df4f07e, 0xbea910c9, 0xbe33a5cf, 0x3e5fff5a, 
    0xbd821ba1, 0x3d8875e4, 0xbee72877, 0xbe74d520, 0x3cebe091, 0xbeec8d33, 0x3ea31ce9, 0xbe14d24c, 
    0x3e819c33, 0x3ef5e692, 0x3e882507, 0xbe9f82c2, 0xbe8d6664, 0xbe9ba5a0, 0xbe8fd18b, 0x3f00ba28, 
    0xbe700569, 0xbe8745aa, 0x3e974673, 0xbe45ea28, 0xbe6aa67c, 0x3ed04afd, 0xbd56fb2c, 0xbeef043d, 
    0x3ebc7a64, 0x3e0230f9, 0xbe1e5200, 0xbdd9add6, 0x3e313ddf, 0xbe219615, 0xbe7fd479, 0x3d4d0842, 
    0x3bb89d22, 0xbe117acb, 0xbe50d376, 0x3de3d41b, 0x3e3cd859, 0xbe0527f8, 0x3ec573db, 0x3ec957e9, 
    0xbe40eb54, 0xbe4aa8ed, 0xbe28bc51, 0xfffffe46, 0x00000004, 0x00000080, 0xbd61d008, 0xbebfe750, 
    0x3fa29576, 0x3f0f7285, 0x3ecc1dbd, 0xbf1f0c04, 0x3ec8321a, 0xbf591c9f, 0xbe142762, 0xbf2c9914, 
    0x3f95e7af, 0x3e4471a3, 0xbe41e602, 0xbeab836d, 0xbe886bd6, 0xbf95ee72, 0x3e2e5016, 0xbea2fb12, 
    0xbe8e1bab, 0x3dc38467, 0xbed96ca4, 0x3e862719, 0x3f09a417, 0x3f49c4b7, 0x3fd9331f, 0xbe159f87, 
    0xbf898933, 0xbdb2def6, 0x3e824c2d, 0x3f10546c, 0x3ec1a4fb, 0x3f186915, 0xfffffed2, 0x00000004, 
    0x00000080, 0xbf09573d, 0x3f920372, 0xbed8578e, 0x3ee0f86e, 0xbe441bce, 0x3f12e00d, 0xbf20fe06, 
    0xbea98f5e, 0x3f927e0c, 0x3f15b66f, 0x3d859106, 0x3f89d6c6, 0x3fcc7ab3, 0x3ea05aad, 0xbec8b9e6, 
    0xbf5d9b12, 0x3afaa700, 0xbee62aec, 0x3e0f25f1, 0xbcf53426, 0xbd758c72, 0xbe2a0e6a, 0x3f5de9fa, 
    0x3e85ecb4, 0xbe874959, 0xbf7953a4, 0xbdbd998e, 0xbd4589c6, 0x3eea8ecd, 0xbe8f3fd0, 0xbf6f2846, 
    0x3f221dc0, 0xfffff1fc, 0xfffff200, 0x0000000f, 0x52494c4d, 0x6e6f4320, 0x74726576, 0x002e6465, 
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
    __RETURN_ERROR(fixwin_dequeue(_K5, _K4, 50, 50));
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
    .id = {0x19, 0xc3, 0x1c, 0xe0, 0x53, 0x63, 0x38, 0x48, 0x9b, 0xc9, 0x3b, 0x3b, 0xaa, 0xa2, 0xd7, 0x75},
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
                    .frequency = 2,
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

