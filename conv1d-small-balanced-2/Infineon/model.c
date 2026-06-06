/*
* ImagiNet Compiler 5.12.5418.0+7793ebcc9f383586f202c2d2f6eafbd7ebe6519d
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 06/06/2026 16:58:53 UTC. Any changes will be lost.
* 
* Model ID  814221dc-7c4b-4d16-adec-7b23bede2593
* 
* Memory    Size                      Efficiency
* Buffers   10256 bytes (RAM)         80 %
* State     25992 bytes (RAM)         100 %
* Readonly  33296 bytes (Flash)       100 %
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
    0x0000001c, 0x00000090, 0x000000e8, 0x00006b00, 0x00006b10, 0x0000792c, 0x00000003, 0x00000001, 
    0x00000010, 0x000a0000, 0x000c0010, 0x00040008, 0x0000000a, 0x0000000c, 0x0000001c, 0x0000003c, 
    0x0000000f, 0x76726573, 0x5f676e69, 0x61666564, 0x00746c75, 0x00000001, 0x00000004, 0xffffff98, 
    0x00000019, 0x00000004, 0x00000008, 0x6579616c, 0x33315f72, 0x00000000, 0x00000001, 0x00000004, 
    0xffff94da, 0x00000004, 0x00000007, 0x6579616c, 0x00305f72, 0x00000002, 0x00000034, 0x00000004, 
    0xffffffdc, 0x0000001c, 0x00000004, 0x00000013, 0x564e4f43, 0x49535245, 0x4d5f4e4f, 0x44415445, 
    0x00415441, 0x000c0008, 0x00040008, 0x00000008, 0x0000001b, 0x00000004, 0x00000013, 0x5f6e696d, 
    0x746e7572, 0x5f656d69, 0x73726576, 0x006e6f69, 0x0000001d, 0x00006a14, 0x00006a0c, 0x0000697c, 
    0x0000692c, 0x0000391c, 0x00002f4c, 0x00002f08, 0x00002eec, 0x00002ecc, 0x000016bc, 0x0000162c, 
    0x000003d4, 0x00000144, 0x00000120, 0x0000010c, 0x000000ec, 0x000000e4, 0x000000dc, 0x000000d4, 
    0x000000cc, 0x000000c4, 0x000000bc, 0x000000b4, 0x000000ac, 0x000000a4, 0x0000009c, 0x00000094, 
    0x00000074, 0x00000004, 0xffff95c2, 0x00000004, 0x00000060, 0x00000010, 0x00000000, 0x000e0008, 
    0x00040008, 0x00000008, 0x00000010, 0x00000024, 0x00060000, 0x00040008, 0x00000006, 0x00000004, 
    0x00000000, 0x0018000c, 0x00100014, 0x0004000c, 0x0000000c, 0x314ea63f, 0x66dedbd9, 0x00000003, 
    0x00000002, 0x00000004, 0x00000006, 0x39312e32, 0x0000302e, 0xffff962e, 0x00000004, 0x00000010, 
    0x2e362e31, 0x00000030, 0x00000000, 0x00000000, 0xffff88e8, 0xffff88ec, 0xffff88f0, 0xffff88f4, 
    0xffff88f8, 0xffff88fc, 0xffff8900, 0xffff8904, 0xffff8908, 0xffff890c, 0xffff8910, 0xffff9676, 
    0x00000004, 0x00000010, 0x00000001, 0x00000001, 0x00000032, 0x0000001e, 0xffff9692, 0x00000004, 
    0x00000004, 0x00000001, 0xffff96a2, 0x00000004, 0x00000014, 0xbb32fe00, 0x3d17e457, 0x3c8d27f7, 
    0xbcb0435c, 0xbd0a074c, 0xffff96c2, 0x00000004, 0x00000280, 0x3dd44a68, 0x3e090dc7, 0xbea93073, 
    0xbea66ade, 0x3d1ae4b3, 0x3e9b2d4f, 0xbd7861a4, 0x3de38ac6, 0xbe989537, 0xbea702a4, 0x3eaef436, 
    0x3e3007c5, 0x3e704df7, 0xbe3a4d56, 0xbea12389, 0x3e4850ad, 0xbe63ddb7, 0x3dcdcf2e, 0xbe546d9c, 
    0x3ea9a2d3, 0x3eab841b, 0xbde36f1c, 0xbe107d31, 0xbe96c50f, 0xbdb6cac0, 0xbd6c6035, 0x3ec3563f, 
    0x3e688dd5, 0xbe9f2acb, 0x3e7fa72d, 0x3e9240e6, 0xbe9dc955, 0x3e5e6267, 0x3eb8249f, 0x3ecff7ca, 
    0x3edfd9b9, 0xbe6c250e, 0xbe89b3c1, 0xbd86fd60, 0x3ed52f04, 0xbeaa1aef, 0xbe9b7d62, 0xbecaded3, 
    0xbb3b13c8, 0xbec8a1b8, 0xbeb47e17, 0xbecbaf23, 0xbcd5355f, 0x3e23333c, 0xbe3e1533, 0xbda18acc, 
    0xbd8779fd, 0xbe9c8804, 0x3e450bbb, 0xbdd1f05e, 0x3ca2e7e0, 0x3eb9eea8, 0x3e9dcfbd, 0x3dc11256, 
    0x3e5b3882, 0x3d5e1fb8, 0xbeb07e5d, 0xbe7ebca6, 0x3ec3f066, 0x3e1c515a, 0xbec8158a, 0xbea4bedf, 
    0xbe5bf36f, 0x3ec73104, 0x3d9d3e96, 0xbe83fc68, 0x3c9c9a50, 0xbd5acff4, 0xbebdd613, 0xbee6ca1e, 
    0xbdd5c86d, 0xbeac456c, 0xbed6c627, 0x3d56061f, 0x3e281687, 0x3e7d5576, 0x3ea2c893, 0x3c8d367c, 
    0x3e637980, 0x3d2f23d4, 0x3e70cb7b, 0x3ec36d07, 0xbe4bea33, 0x3dccafba, 0x3d0368b4, 0x3dfd10cf, 
    0xbeeba8bd, 0x3ebc1cbe, 0x3e6ddc11, 0xbed4479e, 0x3ead00d4, 0xbe834dd3, 0xbe7a2bb0, 0x3e1e35ad, 
    0xbe9f2bce, 0x3eaf8d14, 0x3c6977bc, 0x3ebce695, 0xbe087471, 0x3e811216, 0xbe8b228c, 0xbe7b5137, 
    0xbebc0819, 0x3e82b865, 0xbe36e21b, 0xbe82a2cb, 0xbb86e9da, 0xbe4a6474, 0x3da05ad0, 0x3ec73893, 
    0xbeb4d36c, 0xbdd786ae, 0x3ec4f4ac, 0xbe3c05a6, 0xbdd28ca4, 0x3e76519f, 0x3e322831, 0x3eb21e04, 
    0xbe76535e, 0xbe712d6a, 0x3db0a848, 0x3e931618, 0xbd3485dc, 0x3ec61075, 0xbed4e301, 0x3e21b2cc, 
    0x3b8cb298, 0x3e561347, 0xbe7cb9fa, 0xbea4829b, 0x3ca2f15d, 0xbeb4f184, 0x3e059bd1, 0x3df60f54, 
    0x3ea06a20, 0xbec211e6, 0x3d6cfb7e, 0x3e9da92d, 0xbeb7415a, 0xbee2a21c, 0xbed66c65, 0x3dc32720, 
    0xbde722cd, 0x3eac4b69, 0xbe5044a0, 0x3eb0799d, 0x3eb9f410, 0x3eaca357, 0xbeb1b459, 0x3b418907, 
    0x3dee227b, 0x3dc0d27d, 0xbe84a8bc, 0xbea6c25f, 0xbef4fe92, 0xffff994e, 0x00000004, 0x00001248, 
    0x3cf9950f, 0x3e1fdb59, 0x3d9aa3ea, 0x3d83459f, 0x3e11fdf7, 0xbe501186, 0x3d3750de, 0x3e4fb713, 
    0xbe07ed92, 0xbe2352f0, 0xbe41abd9, 0xbcc05c9b, 0xbe157fa0, 0x3de6ed01, 0xbd911c6a, 0xbdfc329d, 
    0xbe1e6eaa, 0x3dcc4096, 0xbe0a7b98, 0x3e3eb59e, 0xbe068969, 0x3da4a6a5, 0xbd6d2b93, 0x3e5e4718, 
    0xbc3ed961, 0xbd0051ec, 0x3d35e604, 0x3d96c4ab, 0xbd9ef2d0, 0xbd15cad5, 0xbe38718a, 0xbe2745d2, 
    0x3cec7d41, 0x3e294822, 0xbd9b8cf5, 0xbe335c71, 0x3dc3f7b8, 0xbdf0228c, 0x3dba2925, 0x3d853f13, 
    0x3e254f44, 0x3d90b1dd, 0xbdc4e8b1, 0x3d713f74, 0xbe2e5063, 0xbe0e8d63, 0x3dfe92fa, 0x3dceacc4, 
    0x3d4d5588, 0xbcf15fbd, 0x3e00b3bb, 0x3cc18d03, 0xbddc09c4, 0x3db7339e, 0xbe45170b, 0xbe3a24fd, 
    0x3c368774, 0xbe3b4b73, 0xbd2c5e3d, 0x3e88cb30, 0xbe1a98d4, 0x3e090b39, 0xbd9b8bad, 0x3df206f8, 
    0xbd9a0b68, 0x3d273d76, 0xbd857961, 0xbe364d0e, 0x3dc85737, 0x3e16b230, 0xbdb713ca, 0xbe1edac5, 
    0xbe4e3f89, 0xbe31e262, 0xbdd8757f, 0xbe523302, 0xbd3d133f, 0xbe400005, 0x3d87e4a2, 0xbdc28486, 
    0x3db7ceac, 0xbafa20e6, 0xbca61ce7, 0xbd9de340, 0xbc874268, 0x3cce736a, 0x3d8a2a9e, 0xbc91d0ae, 
    0x3db78a8a, 0x3e30e54b, 0x3d761af1, 0xbe132f46, 0xbdb46e4f, 0x3dbcfb57, 0x3d6bdbd7, 0x3da9e0a3, 
    0x3e2eb332, 0x3e1015ab, 0x3d872273, 0x3ce4048d, 0x3e517066, 0xbbb16b31, 0xbe58c9e2, 0x3bd1abe6, 
    0x3e556b92, 0x3e437932, 0xbd4cb451, 0x3e4207bd, 0xbdd79e8f, 0x3c846fa9, 0xbdb07da3, 0x3da18641, 
    0xbd7e2fa6, 0x3e0bd2e1, 0x3e305c64, 0x3de9d4f6, 0x3e39cf2e, 0xbc9a2712, 0xbe776b1c, 0xbe6ddf1b, 
    0x3dad8fc8, 0x3dc90899, 0x3de6ad6a, 0x3dbf6ca2, 0xbd451767, 0xbe35f1e9, 0x3d116984, 0xbe09d558, 
    0x3d431d02, 0xbe445b3c, 0xbe32f56e, 0xbe0c1d41, 0x3daa2b7f, 0x3e741c6a, 0x3dcc9e67, 0x3e223dd4, 
    0x3e095bfa, 0x3db49cc9, 0x3d687539, 0x3e144af4, 0xbe38a94d, 0xbe07f69d, 0xbddf3a67, 0x3e25dfd6, 
    0xbe58fc6f, 0x3e20ea96, 0xbe042994, 0xbe0e9712, 0xbd24f4d1, 0xbe62508c, 0x3d763859, 0xbe351a92, 
    0x3e422766, 0xbe49e0ce, 0xbe627d67, 0xbe29d3a8, 0xbe525b94, 0x3e40b88b, 0xbd873d0b, 0xbe325c3d, 
    0xbc42bbd1, 0xbde91824, 0xbd6943ac, 0x3dd50ca1, 0xbd306e9b, 0x3e214f32, 0x3da4c643, 0xbc9bd37f, 
    0xbe308a21, 0xbd391abc, 0xbd850e31, 0x3e3ccf93, 0x3e1ad298, 0x3e3fbffb, 0x3db93f0d, 0xbd663bad, 
    0x3d239562, 0xbe027d9e, 0xbcd33240, 0xbdf0be5a, 0x3e294d40, 0x3d45ed83, 0xbe014d7e, 0xbdf8edc5, 
    0xbe3544e0, 0x3dd65c9d, 0x3e6e0b96, 0xbce0a782, 0x3e768ca7, 0x3e3c1afe, 0xbe06e3be, 0xbe1d3f6e, 
    0x3e3742b3, 0x3e220787, 0xbe204329, 0x3e1c5860, 0x3e080942, 0xbdea9369, 0x3dea33b1, 0xbda7512b, 
    0x3dd0edbe, 0x3d77ea40, 0xbe169c50, 0xbe09b6bc, 0xbd92c050, 0xbe427e4b, 0xbd1549d7, 0xbbda904a, 
    0x3da091ba, 0x3dcdc851, 0xbe7c3553, 0x3d141e51, 0x3d0ae875, 0x3c0de1e7, 0xbe61c60f, 0xbdebf5ff, 
    0xbde557be, 0x3d5d3aa2, 0xbcae4fb1, 0x3c17784a, 0xbdfc10c5, 0xbe011fe3, 0x3db31131, 0xbe3381cb, 
    0xbe18d3cf, 0xbcf2688c, 0x3dea25a2, 0xbe560939, 0x3d371395, 0x3dc8f41c, 0x3e550707, 0x3e5aafb2, 
    0x3e51a4f4, 0x3e548d6a, 0x3e0df774, 0x3c3b1850, 0x3e250a2e, 0xbe30ce6d, 0xbe876be4, 0x3e199192, 
    0x3db67a6f, 0xbd00f322, 0xbe03b63a, 0xbcfdc6a8, 0xbe680aae, 0x3d1b72fd, 0x3b917ce2, 0xbdc6f14a, 
    0xbd7a78ef, 0xbe0b9820, 0xbe2a3e68, 0x3def77a9, 0xbe1e5bce, 0x3bd25cec, 0xbc788349, 0xbe210203, 
    0x3d818d03, 0xbe4906ff, 0x3e3e4404, 0xbccce7f1, 0xbde7f8ea, 0x3e52ae8e, 0xbd43d0b3, 0x3cee8ff4, 
    0xbd8e9ef7, 0x3e1e03fb, 0x3e424d6c, 0x3de27ff9, 0xbe2e29fe, 0x3d893993, 0x3d1c8243, 0xbe180749, 
    0xbd2f630a, 0xbe3ce536, 0xbd3046e9, 0xbda1fd8d, 0xbd9cee76, 0xbcc84cef, 0x3e15cafa, 0xbe05c85a, 
    0xbe121ff2, 0xbdb22845, 0xbde450dc, 0xbe27c642, 0x3df0a2b0, 0x3e45a7b4, 0x3e170e3a, 0xbe0196f2, 
    0x3d142116, 0x3e256430, 0xbb5035df, 0xbe25fe76, 0x3e1ae577, 0x3d38a6fb, 0x3e231e35, 0x3c96231c, 
    0xbd208646, 0x3e208cf9, 0x3de3eb1a, 0xbdfba9c3, 0x3dea62a7, 0xbe30ff33, 0x3d861665, 0x3e59570c, 
    0xbdb4c20b, 0x3e41cb28, 0xbe2ce559, 0xbd85ca62, 0xbd2d64e2, 0xbd30d01c, 0xbe6042b3, 0x3d42433d, 
    0x3db401f6, 0xbe5b951b, 0x3ce464b2, 0x3d4f12de, 0xbc9101e1, 0xbe1a3a63, 0xbd806d9f, 0x3d2cbe06, 
    0x3c3fb96d, 0xbe699c60, 0x3e2bf809, 0xbd7535a2, 0x3c4beeca, 0x3d9b77e0, 0xbda389ef, 0x3e5f3fb7, 
    0x3e80ec8e, 0xbd8b90d7, 0x3e3da5b2, 0x3d955bba, 0x3dc11537, 0xbd200c4b, 0x3e2b7c19, 0xbc3ca1de, 
    0x3c5db69f, 0xbde889e4, 0x3b80aa34, 0xbe76dc2b, 0x3cce9b82, 0xbcef78de, 0xbdea20da, 0x3d0b33df, 
    0x3e170975, 0x3df86d7e, 0xbc97b920, 0x3db10a7f, 0x3b81cf08, 0xbe52a498, 0x3e4a317a, 0x3e1ce7f4, 
    0xbdd46e60, 0x3dc4f685, 0xbe0eab59, 0xbe1e5473, 0x3e5febb7, 0xbd470c28, 0x3e709a52, 0xbc7126ea, 
    0xbacabb5e, 0x3e4a3f38, 0xbdbcfb47, 0x3e18942e, 0x3c728c9c, 0xbe3b8135, 0x3ce3f93d, 0xbe11c7c7, 
    0xbbc8e7ee, 0xbd175915, 0xbe1df02a, 0x3e233afe, 0xbe410429, 0xbd860aee, 0xbe178f17, 0xbe0b616d, 
    0x3e16be7a, 0xbe4cd7ee, 0xbd97c6b4, 0xbcf80cba, 0xbcbbae33, 0xbe36c406, 0x3e416691, 0xbe209191, 
    0x3e14ffeb, 0x3d6c1bfd, 0xbe03f71e, 0xbe2b2ded, 0xbe10fef5, 0xbd02bb11, 0x3d4bf41f, 0xbce9b915, 
    0x3d664708, 0x3b170312, 0x3c5af43a, 0x3d0bac47, 0xbe16b8fa, 0xbe3f5408, 0xbd2a49ea, 0x3d0b9f67, 
    0xbd0ba8f6, 0xbe2c9fdc, 0xbdde96b2, 0x3dd98a58, 0xbdccd846, 0xbdc49811, 0x3d8f026c, 0x3e160345, 
    0xbde32d3d, 0xbc8ec708, 0x3da4050e, 0xbab2af72, 0x3e53a0b7, 0xbe39094e, 0x3dc65f0b, 0xbe0f46b0, 
    0x3b34ef26, 0xbcb85a83, 0xbcad8c1b, 0xbdd259ae, 0xbdec4054, 0xbe1b3ac9, 0x3da6adbf, 0xbdf73a71, 
    0x3e528957, 0xbd8a821d, 0x3de22633, 0xbd7850ba, 0x3d0426df, 0x3e009833, 0x3ddcfb67, 0x3de31908, 
    0xbe3c3eb0, 0xbca442e9, 0x3df6a4d8, 0xbde4deed, 0xbe05ab9d, 0x3d632f11, 0x3e635317, 0xbd6cf6bb, 
    0x3d84c3ca, 0xbe10c51c, 0x3e3d1a2e, 0x3bb3eb2c, 0xbde11e65, 0x3df76c0a, 0x3e25ff29, 0x3c565d03, 
    0x3b989734, 0x3dbd4fa7, 0x3dd03c0c, 0xbe1a6038, 0xbcdf701f, 0xbd2440c0, 0x3dae0242, 0x3e3d94fd, 
    0x3e593d9a, 0x3d56be32, 0xbd863d43, 0x3dd69d08, 0xbe250a2e, 0x3cf8f699, 0x3e3b1693, 0xbe140c41, 
    0xbe3a961a, 0xbe4c502f, 0xbd0b12c2, 0xbe177db3, 0x3dbe9bfb, 0xbc8048ed, 0xb9cc11a1, 0xbd939c46, 
    0x3e0a6a67, 0x3c87c6e2, 0x3e44dd54, 0x3e33c658, 0x3dddca7f, 0x3e1fec3f, 0x3dd62762, 0xbcb66f31, 
    0x3dcfed9a, 0x3e1369b3, 0x3da0c33b, 0x3d206d56, 0xbe3eaf27, 0x3e07a9ca, 0xbdf57b67, 0xbd8c5136, 
    0xbe3ea553, 0x3b644204, 0xbe3a1496, 0xbdc448b7, 0xbd77ad46, 0x3d546e8c, 0xbcbd9dbd, 0x3e116937, 
    0x3dc6abd7, 0xbdb5d66c, 0xbd96b41a, 0xbba6a954, 0x3e5ce16d, 0xbe15af54, 0xbe26b0e9, 0x3d9e5792, 
    0x3e3637d3, 0xbd84251d, 0xbbdf37e7, 0xbe4a697e, 0xbe281be3, 0x3e0f5705, 0xbddbc800, 0x3e1a8104, 
    0x3e42eaaa, 0x3e408ef7, 0xbc0df036, 0x3e0e4f16, 0x3d48704e, 0xbc8c38fb, 0xbd8f2be5, 0xbde1b364, 
    0x3e234fe0, 0x3d6bfb0a, 0x3df5b0da, 0xbdc22212, 0x3e096f36, 0xbe17b858, 0x3cf1f53c, 0x3c541bf9, 
    0x3e0cac97, 0xbd8ea5f1, 0xbd7a9ce6, 0x3e30e5f1, 0xbca8a7ce, 0x3d5570fa, 0x3e1d722d, 0x3df87332, 
    0x3e02f886, 0xbe0f0ac8, 0x3e0ef4b6, 0x3e35b4bf, 0x3d4c4804, 0x3d4e0ce3, 0x3e129611, 0x3db702ba, 
    0x3dba0cfa, 0x3e06f818, 0xbdf79c5c, 0xbe3d158c, 0x3de08de3, 0xbe3f5fc8, 0x3d1eafd0, 0xbe389d26, 
    0x3b605acc, 0x3e18e1dc, 0x3dca1d7c, 0xbe194605, 0x3db2f6c8, 0xbdf174c3, 0x3cba75bc, 0x3d63a7c8, 
    0x3e50f025, 0x3d8615d9, 0xbe730918, 0xbd15a6af, 0x3d112a04, 0x3e19340b, 0x3d295bb1, 0x3e2a3c9f, 
    0xbdfda93d, 0x3d855dcb, 0x3dec7e2a, 0xbe35a847, 0x3d5c6c5e, 0x3e3654a3, 0x3db74c0b, 0xbce6b826, 
    0x3e345a11, 0xbe431fa4, 0xb9d59dfa, 0x3e152b99, 0xbe4cd6a5, 0xbdbea65e, 0xbd715a9d, 0x3e06d328, 
    0x3d3da6f9, 0xbe300fff, 0xbdb9416b, 0x3e074ba9, 0x3d9343fb, 0xbe2927ed, 0xbe1bdd55, 0x3d51027d, 
    0xbe1550c7, 0xbde0d7a5, 0x3e3aedad, 0x3e4a9b94, 0xbdd12213, 0xba6c7f84, 0x3d2416da, 0xbe1a2973, 
    0x3e1e290d, 0x3c10c47f, 0xbdfd1332, 0x3e0a4a3d, 0xbe1f9d06, 0xbd2b71c1, 0xbcb2cbd9, 0x3e1218ae, 
    0x3c6b456d, 0x3defe820, 0xbe1feaaa, 0x3df6332a, 0x3e153be8, 0x3dbd8a90, 0x3de19e47, 0xbd993182, 
    0x3dbffc52, 0xbe04e515, 0xbd823c14, 0xbc14bfc3, 0xbe0b3047, 0xbd83b417, 0x3e017196, 0x3a7c5f03, 
    0x3e05ca64, 0x3dab6030, 0xbe40811e, 0x3e4589b7, 0x3e1b7b03, 0x3e1ee248, 0x3e5c907e, 0x3dd39d27, 
    0x3e470ed1, 0xbd9aa884, 0x3dbd190d, 0xbe02be7b, 0x3dc00091, 0x3dff51be, 0x3c2c4266, 0xbdba0427, 
    0x3e4c97e7, 0xbe1cf1f9, 0x3d68bd8c, 0x3e519534, 0x3e8652c0, 0x3e35290a, 0xbe02e507, 0x3e0acc45, 
    0xbe21ea82, 0xbdb159a5, 0xbda08da7, 0xbdbe4214, 0xbbcdfb8d, 0x3d646df5, 0x3df9ee33, 0x3dbd59dd, 
    0xbe4c5604, 0x3e50a366, 0x3e28e535, 0x3d0d3646, 0xbd3ea720, 0x3cd0d494, 0x3e364fa9, 0xbe18c376, 
    0x3d357eff, 0x3ceca3e3, 0x3c0c6cb8, 0x3e02fa55, 0x3e0e699c, 0x3e5d4dbb, 0x3b2ac075, 0xbd623d05, 
    0x3d8cde48, 0x3e386b01, 0xbe1caeb7, 0xbdbe7e9c, 0xbe39b86f, 0xbd46d2b2, 0x3e055fdd, 0xbe521b43, 
    0x3e703395, 0x3d9f67fc, 0x3e7bd33f, 0xbbb6bcc0, 0xbe45a2b6, 0x3de0dd8e, 0x3d883654, 0xbdf0b218, 
    0xbe827068, 0xbe133fad, 0xbe1def11, 0xbc043afe, 0xbe3f7f20, 0x3e46b29e, 0x3e01dfc5, 0xbe36089c, 
    0xbd1da4e6, 0x3d171c94, 0xbdabba47, 0xbe002cba, 0xbd8179b3, 0xbe22f901, 0x3e288fd7, 0xbd2b0acc, 
    0xbdf25a37, 0xbe35ac5b, 0x3db2340c, 0xbc851615, 0x3e2c239f, 0xbe3abf4a, 0x3e546bc6, 0x3e3a4552, 
    0x3d6b67a0, 0x3e2386d9, 0xbe23e730, 0xbdd9a22c, 0xbe21a54b, 0xbd1676b9, 0xbe501707, 0xbdfb1505, 
    0xbbce7067, 0xbd76a205, 0xbdd40006, 0x3dc0524e, 0x3dbc064b, 0xbe3de8b3, 0xbe25222c, 0x3c2f8f38, 
    0x3d67e17d, 0x3dbdd97c, 0x3cc90157, 0xbdaef76e, 0xbdd35620, 0xbe046194, 0xbd896076, 0xbd69a02a, 
    0xbd92cd76, 0x3e2872ad, 0x3de8618d, 0x3dc68875, 0x3da95489, 0x3dbecd03, 0xbddd4d6d, 0x3d19d140, 
    0xbd8fc3f3, 0xbe677e2c, 0xbe1dde0d, 0x3e579bc5, 0xbe0a3fd4, 0xbd399ab9, 0xbd9ea8a8, 0x3e004ba3, 
    0x3e0dced7, 0x3d86e405, 0xbdb40bdf, 0xbd9411db, 0xbe43a85c, 0x3d9a16d7, 0xbe4d7729, 0x3deace44, 
    0xbd915b99, 0x3e3a9d60, 0xbdffc985, 0x3ccc63a7, 0xbe1236e3, 0xbde07445, 0xbdc049dc, 0x3d36d9a2, 
    0x3e03024c, 0xbe00c39b, 0x3e6884dc, 0x3e3efde4, 0x3dec7fe3, 0xbe0e01ba, 0xbd3755b1, 0xbe16086e, 
    0x3d6a8891, 0xbe20e3ce, 0x3cfbcf9a, 0xbc89f14e, 0xbe3820f2, 0x3e035674, 0x3d9968bf, 0x3e2ebb35, 
    0xbdee3754, 0x3e0725f3, 0xbe2333ff, 0xbae6c956, 0x3e3f49a9, 0x3e28d141, 0xbdf023f8, 0x3e2b69ed, 
    0x3e352f0f, 0x3e47ce58, 0xbd9e30fd, 0xbd287bdc, 0xbdd926d8, 0x3e2ae03c, 0xbdcf5868, 0xbe18d554, 
    0x3bfc6688, 0x3e44872f, 0xbe2bdc35, 0x3dd30056, 0x3bc54bfc, 0xbe1017f6, 0x3d04ca32, 0x3df5ee2d, 
    0x3e4093c1, 0xbe22ecbf, 0xbdc6587d, 0x3e024cff, 0x3e493dc9, 0x3d51bec2, 0xbdfe35ca, 0x3e186470, 
    0x3cf136b0, 0xbddaa022, 0x3dca008f, 0xbdd57406, 0xbd2a8346, 0xbdf2f42e, 0xbdf1295b, 0xb8613db8, 
    0x3c2a3479, 0x3e2dd3ee, 0xbdbb8eb8, 0x3ba22edb, 0xbe0be398, 0xbe1afc11, 0x3d7d229c, 0xbdf6bbe5, 
    0x3d731180, 0xbe06f879, 0x3d3181e1, 0x3dd1bfcc, 0x3dc0924d, 0x3e210b23, 0xbe86ef04, 0x3e609418, 
    0x3e334e74, 0xbdb99e52, 0x3db49b8d, 0x3e1c0eba, 0xbe4d38ac, 0xbe1920f6, 0xbe257fb8, 0x3e39de9b, 
    0xbda40252, 0x3dc34bbb, 0x3c154874, 0x3e57cd67, 0x3e11f669, 0x3e2be2b7, 0xbe0d48a5, 0x3e5b3922, 
    0xbd74a750, 0xbb65f7ab, 0x3db70b17, 0xbd9bbf23, 0xbe0d211f, 0xbda0baf5, 0x3e423a81, 0xbdbde1f5, 
    0xbdecab4f, 0x3d7c326d, 0xbd023eda, 0x3c878a8c, 0xbc72be5d, 0x3e49a78d, 0xbdc2543a, 0xbd4947d0, 
    0x3de9bfde, 0x3e336d56, 0x3e45c0a3, 0x3e2f0bd9, 0xbd860ac1, 0xbc9f2011, 0xbd8f79fc, 0x3da6da6a, 
    0xbdee0d7b, 0xbabd4552, 0x3da106af, 0xbe0990c3, 0xbd9ddf37, 0x3e49be0c, 0xbe67eef4, 0x3c710ed6, 
    0x3c5f7726, 0x3e5ae355, 0x3dd02c9e, 0x3dff7243, 0x3d072410, 0xbda59852, 0xbe44580d, 0x3e42177f, 
    0x3e2719e3, 0x3e436311, 0xbd9be7c7, 0xbe1212b0, 0xbdc9f2b4, 0xbe2e372f, 0x3e122557, 0xbdd80d3e, 
    0x3e2c7575, 0xbe597b1e, 0xbe01b572, 0x3e47ea54, 0x3decdf2c, 0x3d01c809, 0x3cc3aba5, 0xbda434fc, 
    0x3cd38fe9, 0xbd5c97ac, 0x3da6f50c, 0xbdbee993, 0x3d92794a, 0xbd80f4f4, 0xbd3af1f0, 0x3d05f667, 
    0x3e185e67, 0xbe3d90e0, 0xbe66014e, 0x3cf00548, 0x3d93b76e, 0x3e256d06, 0xbe2d83af, 0x3bbbebb4, 
    0xbd4b291e, 0x3de218e3, 0xbd80d2ab, 0xbce5f457, 0x3a6cc4a5, 0xbe418f77, 0xbdd3711a, 0xbded98c6, 
    0x3cc78f03, 0xbd47769a, 0xbe1a4027, 0x3daa7083, 0x3e045aba, 0xbdcdfbfe, 0x3e0fb966, 0x3d73dac3, 
    0x3e017221, 0xbe46d556, 0xbe32827f, 0x3e009421, 0x3e1cbb51, 0xbe57cb89, 0x3d8ba1ca, 0x3e2e8d6b, 
    0xbd1e7e8f, 0x3e1ee6db, 0x3db310dd, 0xbdc4af28, 0xbe494458, 0x3e256e60, 0xbe3250a9, 0x3e135e0b, 
    0x3e59320c, 0xbdb6eb28, 0x3e304296, 0xbd9ff9ba, 0x3e3dade3, 0x3cc909b7, 0x3e464e38, 0xbd116e3e, 
    0x3d8888f5, 0x3dba0b2b, 0xbdc63487, 0xbdc3dcdf, 0x3dd0627b, 0xbd13f671, 0x3db87540, 0x3c96952e, 
    0x3d0fc81c, 0x3e04132d, 0xbd9a8e87, 0xbe5eddf6, 0x3e0f000d, 0xbd59e4f9, 0x3de3a887, 0xbddb1a95, 
    0x3db5a1a7, 0xbda7b615, 0x3e4c2e57, 0x3cbc7c39, 0xbdfd5972, 0x3cf7ec16, 0x3c120844, 0x3e20a9d1, 
    0xbe1db046, 0x3e46c810, 0xbdf52cb0, 0x3de11c11, 0x3d8a5039, 0x3d3930a5, 0x3d11aaa0, 0x3e18cb1b, 
    0x3e308020, 0x3e44eda2, 0xbde8b101, 0xbd6da7aa, 0xbc1a28e1, 0xbe19f753, 0x3e1f94f0, 0xbcadd3ae, 
    0x3dc6e41f, 0x3cd4a324, 0x3e0bf675, 0xbdc910de, 0xbe391155, 0xbdc6dcef, 0x3dce0213, 0xbc222448, 
    0xbe1308a8, 0xbd9fe084, 0xbe84ff1b, 0xbde62edc, 0xbe084714, 0xbe1cbc93, 0xbd3d2d43, 0x3d21912c, 
    0x3d8b5617, 0xbe06b4cc, 0xbcba85e1, 0xbdc91f4f, 0xbe1e36f1, 0x3cccb825, 0xbe4ec507, 0xbe4ee426, 
    0xbe20892b, 0x3de2f841, 0x3e2bbc2e, 0x3ca5dc4c, 0xbdec087c, 0x3d2458a7, 0xbe12a43d, 0x3e05289a, 
    0x3cbc5cab, 0xbc9440fb, 0xbe17a847, 0xbc111a28, 0x3d9c736d, 0xbdfcf4e7, 0x3d947bab, 0x3d746d17, 
    0xbe7129fd, 0x3dbce9b8, 0x3dbfc016, 0x3e0bc5f5, 0xbd9b4847, 0xbd7bf03b, 0xbe6241ea, 0xbd4ef3bc, 
    0x3deca524, 0x3a07c7ef, 0x3dced014, 0xbd2910ac, 0x3c322cbf, 0x3e5b2715, 0x3c57188c, 0xbcbd5dc4, 
    0xbd593d92, 0x3dc1ee47, 0x3daaad33, 0x3d9d01fa, 0x3e2e0a77, 0xbe3ca6c3, 0x3e107e61, 0x3d576ce2, 
    0xbe5fd2ff, 0xbe64bec4, 0xbd4a4363, 0xbe0e02e8, 0xbe2e721e, 0xbe04f81a, 0x3bc6f932, 0x3c6b7f13, 
    0x3e3d5ffb, 0x3da187db, 0x3e2a374c, 0xbdf2ff34, 0xbcc8746d, 0x3d999337, 0x3d893839, 0xbdf62ef0, 
    0xbdbbb8c7, 0xbe08ab61, 0xbe02a7f0, 0x3e0cee60, 0xbe00b7b1, 0x3d99c561, 0x3d3982d4, 0x3e032745, 
    0x3dbaed1c, 0x3e3df23b, 0xbe362e1a, 0xbd451a53, 0x3e1223b4, 0xbdddc7b5, 0xbddac5d7, 0xbe2afd16, 
    0xbd2b6084, 0x3d3d8b27, 0x3e062a46, 0x3d74367b, 0x3e4d10f1, 0xbdbc878b, 0x3dcdeb20, 0xbd8d9470, 
    0x3c91f176, 0xbe442981, 0xbd9fcae8, 0x3e2b5ccc, 0xbd5e5109, 0x3e5b3617, 0x3dd7f851, 0x3e5615b5, 
    0xbe42e37e, 0x3e17273c, 0xbe5e371e, 0x3daf99f1, 0xbe314751, 0xbd68fce0, 0xbd972bc5, 0x3cf665a1, 
    0x3df468bf, 0xbe4b650e, 0xbdd1c83d, 0xbda2d6a2, 0xbbe26445, 0x3e2559e4, 0xbe4ad504, 0xbd548867, 
    0xbcd67895, 0xbdded1aa, 0x3dff4522, 0xbe62b741, 0xbe511772, 0x3e231d8a, 0x3e058e65, 0x3c811569, 
    0xbd947691, 0xbe2fde29, 0x3dd87c1e, 0xbd8c9a5f, 0xbe242cc8, 0x3e62775e, 0x3df294af, 0xbe0f9215, 
    0xbd24e76b, 0xbdecbe69, 0xbd59970d, 0x3d6f535e, 0x3e5618d8, 0x3d9afbbb, 0x3e5f4ab8, 0xbdf88aa8, 
    0xbe182113, 0x3d1be213, 0x3e28294f, 0x3d7f94af, 0xbe2841ee, 0x3e2a4f4d, 0x3dea172f, 0x3e52b5e3, 
    0xbbdb7ea5, 0xbc57cb2d, 0xffffaba2, 0x00000004, 0x00000080, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xffffac2e, 0x00000004, 0x00001800, 
    0x3db24262, 0xbe397296, 0xbd733d03, 0x3e26a0ad, 0xbe2f8b4c, 0xbe42d202, 0xbb1317af, 0xbe1726b8, 
    0xbe0133f3, 0x3dd30bb9, 0xbd7dc5a2, 0xbdd1c4b7, 0x3e03a549, 0x3b36af97, 0xbd8f5953, 0xbdc202fd, 
    0x3e0b5b57, 0xbde1fee1, 0x3dfd01b3, 0x3e24e81b, 0xbe3c2579, 0xbdd276de, 0x3df909ea, 0xbdcad32f, 
    0xbd432c41, 0xbe1e6389, 0x3db558fc, 0x3d29881a, 0x3dc4fafd, 0x3e3f69b3, 0x3d0c4d02, 0x3d4a3615, 
    0x3db4a909, 0xbd5c5e3e, 0xbe0d9899, 0xbd88262a, 0xbde1978f, 0xbe25b740, 0xbe40b33c, 0x3ded3aae, 
    0x3e100bee, 0x3e4dafdc, 0xbd3a451a, 0x3cee5481, 0xbe060578, 0xbe09339f, 0xbe1c0cf0, 0xbcbd33dd, 
    0x3d7a40df, 0x3d85ec8c, 0xbe2f7207, 0xbd6bf815, 0xbd87dc06, 0xbc453b78, 0x3ce4878e, 0x3e5cae5f, 
    0xbe459f2a, 0x3d80f7c1, 0xbdd8dacd, 0xbe43411f, 0x3e0966e9, 0xbe166eb0, 0x3cfd265b, 0x3dd57274, 
    0xbd9f08cf, 0x3d7c5dfd, 0x3dd6b344, 0xbdcb0969, 0x3ca3d231, 0xbe23ebc9, 0xbe15ccde, 0xbd8b95c1, 
    0x3d868695, 0xbdbfabb8, 0xbd2508d9, 0x3e52c7f8, 0x3d7f9664, 0xbe18fb3d, 0x3de8d561, 0x3c926453, 
    0xbd8bc112, 0xbd9dcab2, 0xbe23f6f1, 0xbba25d18, 0x3e575c8f, 0x3e07ecb6, 0xbdaf241b, 0xbcfc8a5f, 
    0x3b2b3a7d, 0x3e23852a, 0x3e2a68e2, 0x3dfbde03, 0xbce17209, 0xbd855e60, 0xbe533204, 0xbe01a35f, 
    0xbdb68698, 0x3e1c2d5e, 0xbcbd7930, 0xbe2408ad, 0x3d99a08a, 0xbdf130b4, 0xbe3b58d4, 0xbe265cff, 
    0x3e49c34b, 0x3e480b66, 0x3d3f3922, 0xbd0fc5b6, 0xbdb0d71a, 0xbb761c88, 0xbe097d2a, 0x3e1aaf31, 
    0xbd165296, 0x3d8e8b03, 0xbdb0f61c, 0x3d0c3ef4, 0xbd7f5f72, 0x3e3dd8e4, 0xbdf5a9dd, 0xbe2346ba, 
    0x3de528a1, 0xbdb535ec, 0x3c6a1900, 0xbd93e100, 0x3e02537a, 0xbe353e90, 0x3e58ac21, 0xbd0f8588, 
    0x3db8c177, 0x3dbf6f01, 0x3e0120f9, 0xbe1bd1d5, 0xbe5c421d, 0x3c33bd63, 0x3da16bff, 0x3ccd7050, 
    0xbcc13689, 0xbc300e9e, 0x3dd8838c, 0x3d6ca39c, 0x3e4cacf7, 0x3d4f4b46, 0x3cf576e1, 0xbce2f302, 
    0xbd5dd817, 0x3e0c4a9a, 0x3e0747b1, 0x3b8a20cb, 0xbdad9903, 0x3dd66c68, 0xbe5b62eb, 0xbe040510, 
    0xbdd49d34, 0xbd81dc09, 0xbc3c29fd, 0x3c0ca27e, 0xbda0349f, 0xbe51cf6b, 0x3db23394, 0xbe0d6285, 
    0x3d8da123, 0x3d4435fe, 0x3e4a0df5, 0x3dbe633d, 0xbdd41520, 0xbe4e33ee, 0xbdc11f8f, 0xbe2a245e, 
    0x3e41e76d, 0xbb8dc105, 0x3e275cb0, 0xbd398cd9, 0xbe5e9899, 0x3b9bcbc6, 0xbce276bf, 0x3e10002a, 
    0xbe3030b5, 0xbde4e2f7, 0x3e48327d, 0x3d55c4f0, 0x3e1d3687, 0xbc5c1626, 0xbd069b0b, 0xbe1fcb9c, 
    0x3e16709b, 0x3d7a65d0, 0x3df17b3a, 0xbd1ac4b7, 0xbda3d13a, 0xbb7b85af, 0xbda2da01, 0x3c85f195, 
    0x3dec0488, 0x3e157e3a, 0x3e024a9f, 0xbdc3bb50, 0x3da23350, 0xbe01b450, 0xbc9811ba, 0x3e338d7a, 
    0xbd85d5fe, 0x3e415331, 0xbd9f895a, 0x3de81548, 0x3e1012e4, 0x3e0e986b, 0x3e0180b7, 0xbe3c1109, 
    0xbd856adf, 0xbc83da51, 0x3dd784ad, 0xbe22036f, 0x3c96fb18, 0x3d486ebb, 0x3e1d3339, 0x3d1d2083, 
    0xbe0e08b6, 0x3e089f5a, 0x3ddc9f33, 0x3d75ee9f, 0x3d85ae51, 0xbd8923c3, 0x3d711c38, 0xbbd4bcc2, 
    0x3e2ab2ec, 0x3cd63b75, 0x3d3751b8, 0x3d3f58b9, 0xbe4e682b, 0x3d534d40, 0x3d064931, 0xbbfe0a04, 
    0x3dd824b1, 0x3c906ff5, 0xbb94891f, 0x3dda8a1a, 0x3d774abe, 0x3e31f39a, 0xbdc3fdb6, 0x3de99215, 
    0x3df20aca, 0xbdbe8811, 0x3ddf87cc, 0xbe3136fe, 0xbd25745e, 0x3e3f6d3d, 0x3cfb0a3f, 0x3d542aaf, 
    0x3c8369c5, 0xbdabe091, 0x3d65be31, 0xbdfea0d9, 0xbdb1656c, 0xbe111a53, 0x3de75cd1, 0xbe42419d, 
    0xbe243b4d, 0xbd283a22, 0x3e0798f3, 0xbe012745, 0x3cf4a19d, 0xbdab23df, 0x3db7d82e, 0xbd4808c0, 
    0x3e33ab62, 0xbdd3641c, 0xbdfc62ab, 0xbde0f2f5, 0x3e39962a, 0x3da88b52, 0x3d9984f2, 0x3b9ad44d, 
    0xbe3e09f9, 0xbdbc953b, 0xbe296a31, 0x3d6e549d, 0xbd6ad485, 0x3e11841e, 0x3e432b66, 0xbd31f954, 
    0x3da40bec, 0x3ae4c08a, 0x3dc96b79, 0xbd2b393d, 0x3db55edf, 0xbdb28778, 0x3e3455a6, 0x3c10712b, 
    0xbe1a840f, 0x3d499658, 0xbdd51672, 0x3d9ac637, 0x3e009faf, 0xbbf16b5e, 0x3dd47241, 0x3e1374fb, 
    0xbbaf2fef, 0xbdaa6a16, 0xbe3982fa, 0x3dfab1c0, 0x3dd9094b, 0x3cf877f2, 0x3e384dfb, 0x3dd4cbae, 
    0x3dc60dbf, 0x3e2527f0, 0x3e1be3dc, 0xbddf02d9, 0xbe3b0a64, 0x3df5f3a8, 0x3e19cf80, 0xbd1272f7, 
    0xbc9c8f2c, 0xbe6fc540, 0xbdf2e904, 0x3e284fae, 0x3d4a90fd, 0x3e08782d, 0x3e114278, 0x3d98df3e, 
    0x3e0e4bb6, 0x3dffae48, 0xbe2e768f, 0x3de43ef2, 0x3c34edfc, 0x3d151948, 0x3e1e4493, 0x3e21539b, 
    0x3e028af5, 0x3d7c7f48, 0x3c4350d2, 0x3e0b4f29, 0x3e29c792, 0xbe4b6845, 0xbe592072, 0xbcdddbf7, 
    0x3dcfd295, 0x3e0e8c5e, 0x3e15e0cb, 0x3c9555cd, 0xbc6902e4, 0xbe4e1b2e, 0x3c1ba991, 0xbe1b8fe9, 
    0x3c018c3f, 0xbe141d29, 0xbe266e9a, 0xbdc99f87, 0xbe144218, 0x3ce304a9, 0x3d050074, 0xbe180629, 
    0xbe018b79, 0xbcd7f665, 0x3dec55de, 0xbd7029b2, 0x3e4e9acf, 0xbd0842fe, 0x3deabeef, 0x3d65a5c2, 
    0x3d131a12, 0xbe23c80a, 0xbdc931fb, 0xbdfaa86d, 0xbd1d8d56, 0xbdc3f1ff, 0x3dce14b6, 0x3e08d97d, 
    0xbdedc872, 0x3d2a1d23, 0xbddc2449, 0x3dbdc9f4, 0xbd780533, 0xbe4946f2, 0xbd2bf886, 0xbe447fe4, 
    0xbda08d07, 0x3e0e9906, 0x3d446578, 0xbd2b8959, 0xbd695dab, 0x3e33a8e6, 0x3dd353e1, 0xbda3648c, 
    0x3e2a9fd2, 0xbdd7f3da, 0xbdd90db2, 0x3d991631, 0xbe480f0b, 0x3d95d523, 0x3e0986fd, 0x3d1f137a, 
    0x3e08af63, 0xbe0c1bb2, 0xbdf435ad, 0xbe25e76b, 0x3e2f0d3b, 0x3dde616b, 0x3d88b2c9, 0x3d92510e, 
    0xbc75a2da, 0xbd9fbfd2, 0xbca87e67, 0x3bcf6a0a, 0x3cf5dfe6, 0x3dddfff5, 0xbe281160, 0x3cb71f65, 
    0x3e4feb76, 0xbd4d99bc, 0x3d906c7f, 0xbe0c49a8, 0xbc2bf1de, 0x3ba9dd62, 0xbdb43694, 0xbe04f7aa, 
    0x3e4c5797, 0x3e4e7cea, 0xbcff0ce9, 0x3dd6ea4c, 0x3e32e8c1, 0xbdfca53f, 0xbde3e728, 0x3df262e5, 
    0x3df0600b, 0x3d13894c, 0xbd92a0e3, 0xbd833be1, 0x3a69219c, 0xbd82410f, 0xbe2bc2fb, 0xbe081e23, 
    0x3d457f96, 0xbdce130f, 0xbd5b82d7, 0x3ccf56d5, 0x3e45ce2f, 0x3d8983ac, 0x3e321bb7, 0xbd1f9f84, 
    0x3ccd93fa, 0x3e59f184, 0xbd490124, 0xbc044dae, 0xbd228e48, 0x3d7e5ca4, 0x3e04d056, 0x3d258e8e, 
    0xbbf74701, 0x3e031c5a, 0xbe1141d5, 0x3da82d90, 0x3df052ec, 0xbc78bc77, 0xbc69f041, 0xbb3057a8, 
    0xbe2e1ee1, 0x3e2461ef, 0xbca3c852, 0xbdc40672, 0xbbfc746b, 0x3d42c53f, 0xbe710449, 0xbd3971d6, 
    0x3dc0db62, 0xbcb38b17, 0xbd0ba9b0, 0xbe451189, 0x3d293464, 0xbe303c9d, 0xbde14894, 0xbe4e731b, 
    0xbdf39754, 0xbe0b08d2, 0xbcd55269, 0xbe278d57, 0x3a2a8a1b, 0xbdb9ecf1, 0xbdb829ce, 0x3e004276, 
    0xbe1aa8b8, 0x3d262c81, 0xbd33b431, 0xbd9683ac, 0x3e1d2be0, 0x3dc378c9, 0x3dd21c2f, 0x3e1d2c24, 
    0x3dcf214a, 0x3dae7b2f, 0x3d6d981d, 0x3da38b95, 0xbe1a35fd, 0xbdb12486, 0xbdb05168, 0xbe1bef02, 
    0x3e0c79dc, 0x3dc5a4a3, 0x3e2fba52, 0x3d369adc, 0x3e0c77e0, 0xbe555b73, 0xbe01cb15, 0x3d6fe933, 
    0x3e396660, 0x3dfe622d, 0x3e32ca1a, 0x3e32c7ba, 0xbe4495cb, 0xbcf22b34, 0x3e4460ed, 0x3e13e9cd, 
    0x3c8bfd2d, 0x3df22eff, 0x3d18e7e2, 0xbe0aa8cf, 0x3db43f97, 0xbd4527c5, 0xbe2cf6a7, 0x3cffbeff, 
    0x3d3f7c68, 0xbe50823d, 0x3e292fe6, 0xbe02f78c, 0xbe2ee73a, 0x3d7e06ad, 0xbe3fefa2, 0xbdb2d29e, 
    0xbc1bd482, 0x3da1051a, 0x3e46e789, 0xbe2e855c, 0x3da52b9c, 0x3de46642, 0x3d81057b, 0xbda16fe1, 
    0x3d8b93f5, 0xbdb42418, 0xbde908a3, 0x3d92d458, 0x3dfc903f, 0xbe4c84c7, 0x3d1343c5, 0x3dd1997d, 
    0x3cf73343, 0x3e068a88, 0x3e0dda28, 0x3e23fe02, 0x3e1ffc0a, 0x3e18f34f, 0xbcafe4ea, 0xbd3b3e6c, 
    0xbd9765a8, 0x3e262035, 0x3c8f1f15, 0xbd1a94a9, 0x3c90f841, 0xbd23aa3e, 0x3cc16c23, 0xbdd58612, 
    0xbd98ef79, 0x3e21a8ef, 0x3d38b157, 0xbdd573df, 0xbdb62a7a, 0xbe011cec, 0x3beab547, 0x3df396f5, 
    0xbda6a011, 0x3df6dba8, 0xbd515411, 0x3dfb8369, 0x3dbcd498, 0xbe431755, 0xbdb1ad85, 0xbe08aa4d, 
    0xbe0fa700, 0x3dc67df2, 0xbdaf5365, 0x3defc916, 0xbdabe69c, 0xbe1c9f76, 0x3e2fdeab, 0xbde37b6c, 
    0x3e29e93f, 0x3cd406b6, 0xbe2aaebf, 0x3e12ec30, 0xbd4e8470, 0x3deed13e, 0x3e3eecc7, 0xbd70be16, 
    0x3dde2312, 0x3e2e9b20, 0xbd77fa71, 0xbc129e60, 0x3d389e42, 0x3dd97dcc, 0xbd1d8508, 0xbd746745, 
    0x3c9efb7f, 0x3dd4593e, 0xbdd1969c, 0xbe335df6, 0x3cc0c200, 0x3ca2fd6a, 0xbde17d50, 0x3e3c0e90, 
    0x3e1d67be, 0x3d27ca21, 0xbe23e375, 0xbc8f074b, 0xbe2220d3, 0x3df84626, 0x3e2775e8, 0x3e1bd4ba, 
    0x3e3366bf, 0x3e1ec75b, 0x3e356378, 0x3b8408f4, 0xbe5499cb, 0x3e071bab, 0xbe1f0e0c, 0x3d629608, 
    0xbe1cbed0, 0xbe673a02, 0x3e006b57, 0x3d67d77e, 0x3e208c8a, 0x3c91f9a4, 0x3ddbc86b, 0xbe27b607, 
    0xbc8ca073, 0x3e185853, 0xbdcdc720, 0xbe0f4cc0, 0x3da6cba2, 0xbdd858e0, 0x3dead954, 0xbe0f318b, 
    0x3d719218, 0xbd234d11, 0x3d6cd69f, 0xbe211478, 0xbe2286df, 0x3d432866, 0xbdfb1420, 0xbd8936f1, 
    0xbe2ed495, 0x3c826c3f, 0xbd1e9a33, 0xbe35c7b8, 0xbcc8622f, 0x3d9496be, 0x3e3fc98a, 0x3c55af4e, 
    0xbe2a4b83, 0xbe1a8134, 0x3d94e124, 0x3d9b339a, 0x3cf2e080, 0xbdc9d8ec, 0x3e1ee355, 0x3d0059b5, 
    0x3e4e13f9, 0xbdecc81e, 0x3e077ddc, 0x3c71aedd, 0x3d70b28e, 0xbb4140d5, 0x3e3658dd, 0x3caf0752, 
    0xbdc69048, 0x3e170270, 0x3d8b5f38, 0x3b2eed85, 0x3e065ce4, 0xbe32ee48, 0x3d391d61, 0xbda22ef0, 
    0xbca26c83, 0xbe66096a, 0xbd9fcac0, 0xbd9a8460, 0xbe1d78bd, 0x3d51d739, 0x3b6161c5, 0xbd6375e9, 
    0x3e02e53c, 0x3dcda23a, 0xbd7c9793, 0x3dcf1b82, 0x3da90d3f, 0x3dbfafd0, 0xbda6bd0d, 0xbe2e7585, 
    0xbc4238a0, 0x3de4fa00, 0xbe11683e, 0xbe70a022, 0x3e212e09, 0x3dc7779a, 0x3e2bb059, 0x3e3ae32a, 
    0x3cfa4c23, 0x3e170001, 0xbd9b203f, 0xbe278ece, 0xbd9ec5ab, 0x3d991998, 0x3e54f056, 0x3dc3b01d, 
    0xbe1f69ba, 0xbde1452e, 0x3db41470, 0xbe812dea, 0x3e0d6158, 0x3cdf3d37, 0x3e03d429, 0x3e2fee02, 
    0xbe1dd605, 0xbe20f642, 0xbe4275f7, 0x3debf441, 0xbc99eaa4, 0xbe5725a2, 0x3e4aaebf, 0xbe31af70, 
    0x3db1224a, 0x3e1f8af4, 0xbe062417, 0xbdc5814d, 0x3d888e7e, 0xbd445472, 0x3e3c7f76, 0xbd87b26e, 
    0xbd04633e, 0x3cbf2efb, 0x3d55a3c1, 0x3e1bc087, 0x3e5591a8, 0x3d3792a3, 0xbd82273a, 0xbdc5f126, 
    0xbd95352d, 0xbdcf7095, 0x3d6f3178, 0xbdd00fbe, 0x3e4d41da, 0xbdc79bba, 0xbd83674b, 0xbe0d5440, 
    0x3e1febca, 0xbd7dc591, 0xbc87b578, 0xbba7cf4c, 0x3e121556, 0xbd5f2adf, 0xbe13eff7, 0x3d8a4e20, 
    0x3cca149c, 0xbe17125d, 0xbe28400d, 0xbd80a267, 0x3d8bfb0a, 0x3e1cbf1f, 0x3e46937b, 0xbdb353bb, 
    0xbd5be4e3, 0x3e40b035, 0x3cbb2ced, 0xbd856343, 0x3d8ba4eb, 0xbc8f15bc, 0xbd0b1ad3, 0x3dab67ee, 
    0x3d003329, 0x3c4a7c2e, 0xbe1a6530, 0xbe434a86, 0xbdc66224, 0x3c12e9c1, 0x3e22f290, 0x3e1391c4, 
    0xba5578d5, 0x3d631992, 0x3e450664, 0xbdf940fe, 0x3dc471e3, 0xbe29203d, 0xbe1b15df, 0xbd0bf81b, 
    0xbd5ee2f1, 0xbe3a88a1, 0x3dc56fd0, 0x3e3850c2, 0x3de855da, 0xbe1f51cf, 0xbe115b7a, 0x3df4f4ff, 
    0x3dc734fe, 0x3e55c9bf, 0x3d4cafe7, 0xbe07f441, 0x3d1defa3, 0x3e1881e7, 0xbe0b100c, 0x3e3c2ed7, 
    0xbd920ed9, 0xbd4e4549, 0x3e1e1efc, 0xbe0c7c66, 0xbe46a5b9, 0x3e1ffebc, 0xbe16b09f, 0xbe3be1ca, 
    0x3dddffcd, 0x3c106c6d, 0xbd4fd9e6, 0x3e31c2a4, 0x3e2c2607, 0xbe38d0f9, 0xbca8a3f3, 0x3dcf70be, 
    0xbd37630a, 0xbd7bf058, 0x3d83fe15, 0x3e171b5d, 0xbdaea8a6, 0xbe57ca91, 0xbd9fcda1, 0xbe1ab275, 
    0xbe2cf029, 0x3da00103, 0x3df32551, 0xbde5b49c, 0xbd48c50c, 0x3dae852a, 0xbe14255c, 0x3c14d68e, 
    0xbe463f5d, 0x3da3a5b0, 0x3e09dc7b, 0x3d9617e9, 0x3ca2e114, 0xbe32430c, 0x3caf8226, 0x3c7467f1, 
    0x3dfd4fdd, 0x3d929b45, 0xbd17b1e0, 0x3e14a861, 0x3e5b5791, 0x3dbca22a, 0xbd5ea9ef, 0x3e29b736, 
    0xbe4fdc16, 0x3c2cb3e8, 0x3d182ab6, 0x3e30b5c7, 0xbca7c267, 0xbda1896c, 0xbd966872, 0xbd14bacf, 
    0xbd9a42be, 0x3e1f1f0d, 0x3d7695ca, 0x3e55413d, 0xbe277bc7, 0x3de078b8, 0xbe1c3ed0, 0xbd867200, 
    0xbd5ef363, 0x3dc512fb, 0xbe10404c, 0xbdff75e8, 0x3e0a5846, 0xbbce1ad4, 0xbd247c90, 0xbe0b1846, 
    0xbe2fd55c, 0x3c5f2d58, 0x3e253ed3, 0x3e47a275, 0x3e093731, 0xbe45191c, 0xbded3897, 0xbd90e7d8, 
    0xbd96bedf, 0x3e1a7ef9, 0xbe28bb3a, 0xbdf5c0ae, 0xbcb7540a, 0x3decd421, 0x3e000052, 0x3d843304, 
    0x3d8e1200, 0xbe0bd12e, 0x3e1da2db, 0xbe17a3ad, 0x3e1781df, 0xbe64ee42, 0xbd188aef, 0x3d702040, 
    0xbdbadf72, 0x3db94424, 0x3dc71a2e, 0x3e01480a, 0x3ca6133d, 0x3e085bff, 0x3ded3e97, 0x3dfe80c6, 
    0x3b2c5984, 0x3d417931, 0x3d88ac83, 0x3e19fab5, 0xbe21c4b1, 0x3dda5c9a, 0x3d41f244, 0xbdacb96d, 
    0x3da8727b, 0x3e3fd123, 0x3dceac93, 0x3d5d414c, 0xbd92b083, 0x3d8fac1e, 0xbdea4e76, 0xbc58ee1a, 
    0xbd212d1e, 0x3d960247, 0xbe043700, 0xbde91777, 0x3d4e03d6, 0xbe07d831, 0x3e44dda5, 0xbd5e9ccd, 
    0x3e28fbc9, 0xbe32b307, 0xbdd44522, 0x3e1b67e9, 0xbe2344ed, 0x3def4a3f, 0xbd1c00cc, 0x3db8eac4, 
    0x3c5eab8c, 0xbe2b8ee3, 0x3e2f9846, 0x3da73ef3, 0x3d9bb76b, 0xbbc0e282, 0x3dba762e, 0x3db13ceb, 
    0x3e5da255, 0x3dddb4db, 0x3e503bb7, 0x3e1946a8, 0x3d5c05ee, 0x3e4b2840, 0xbe04f5a7, 0x3e3db9b6, 
    0xbd37dff7, 0xbe3340cd, 0xbde41705, 0x3cd069d8, 0x3dbdfb74, 0xbd82e171, 0xbda22543, 0x3db0f573, 
    0x3d8fd1a6, 0x3e02b78f, 0x3de98c2d, 0x3d00ba1b, 0xbba46b95, 0x3e3e385f, 0x3e485696, 0xbe0a2b42, 
    0xbc03e3e2, 0x3d781958, 0x3dcb5cc2, 0xbe306a93, 0x3dad616b, 0x3d15dc78, 0x3dafca09, 0xbe26c07d, 
    0xbd1f36bb, 0xbe11f7fe, 0xbd8a5da9, 0xbd98809c, 0x3d05494b, 0x3de0d958, 0xbd6d0d1d, 0xbd28ae3e, 
    0xbe23ca0a, 0xbd1ee911, 0xbe4bc744, 0x3d828684, 0x3d1d01c0, 0xbd52169d, 0x3dd96da3, 0xbda5f894, 
    0xbe2b8868, 0x3e510beb, 0x3d9e0958, 0xbd3fc88e, 0xbd6d44c2, 0x3c73581e, 0x3e26faf1, 0xbe0c5f97, 
    0xbd5fa83e, 0xbe579fc0, 0x3dad74e9, 0xbd90d86a, 0xbdc1d52b, 0xbd972ebe, 0xbc82ff4d, 0xbe1b8934, 
    0xbcc97712, 0x3e2fdf62, 0xbd80afb7, 0xbdff629f, 0xbe687ade, 0x3d181b82, 0x3e5119f5, 0xbd66f6cc, 
    0x3e548898, 0xbce662b9, 0x3d305ff5, 0xbe5dd4c9, 0xbdb4f4ef, 0x3e38cad0, 0xbdf069b4, 0xbccbcb19, 
    0xbce40149, 0xbe24fb27, 0x3d798091, 0x3e3077b7, 0xbe03c8c6, 0xbe489514, 0x3e4dc350, 0x3c9c8ee1, 
    0x3e59c10b, 0xbe4af167, 0x3dcdc066, 0xbd88e7d8, 0xbe268248, 0xbda23f5b, 0xbc6ab383, 0x3caf9ab0, 
    0xbd067eab, 0x3db91749, 0xbd75af30, 0x3ca506e7, 0x3cf7046e, 0x3dcde2a3, 0x3e3e3df1, 0x3e2c43a5, 
    0x3e24eabb, 0xbda01f4c, 0xbe33e33d, 0xbce39f7b, 0x3ce7b01b, 0x3e03c5e6, 0x3e30feca, 0xbd1da4ce, 
    0xbda63d64, 0xbca7b34a, 0xbe3c70d0, 0xbe26f378, 0xbe132a35, 0xbc413cd6, 0x3da825d4, 0xbcb84d85, 
    0x3e34de4f, 0xbda67b79, 0x3e5f3360, 0x3daedb94, 0x3e621748, 0x3df739a2, 0xbbdbaefb, 0xbe1c1526, 
    0x3e0e33cb, 0xbd67de0d, 0x3e4050a3, 0xbe55e824, 0xbd1c0abd, 0x3dea8651, 0xbd8ce941, 0xbc65c4ea, 
    0x3d768a43, 0x3dc67ecf, 0xbe172c01, 0xbd550253, 0xbd1d5862, 0x3de73b01, 0xbe03f4c3, 0xbd3fad80, 
    0x3e3c2aa8, 0xbd84002e, 0xbdb0e1dc, 0x3deeb5b2, 0xbe2ad728, 0xbe522f57, 0x3e284435, 0x3ca35e9e, 
    0x3d620a18, 0x3e085d62, 0x3cec67f0, 0x3ddfee3b, 0xbceeedaa, 0xbc8ae6b7, 0x3e300033, 0xbde10840, 
    0x3cb41567, 0x3da7d111, 0x3e101530, 0x3ce26183, 0x3bfc7de4, 0x3e45418f, 0xbe418a0e, 0x3d7d9e0f, 
    0x3defb607, 0xbe096f45, 0xbd9b0b0c, 0x3d618d60, 0x3e0edf1b, 0xbdbf011d, 0x3c363db9, 0x3d191720, 
    0xbe3933ae, 0x3e351b0c, 0xbd154efd, 0x3e3c1423, 0x3d4c265c, 0x3df73d13, 0x3e2cdf28, 0x3e175749, 
    0xbe3ea1b0, 0xbde8e2f6, 0x3db92cc8, 0x3df14cfe, 0xbdbadde9, 0x3e17b6bd, 0x3e1d9908, 0x3db143b8, 
    0xbde51201, 0xbe0ade86, 0x3ba493dd, 0xbcbb1a3a, 0xbe4311cb, 0xbc37bc0f, 0xbe36d12e, 0xbddaa462, 
    0x3e2d78df, 0x3e3a2e98, 0xbd00ea7f, 0xbdc169cb, 0x3e3e870a, 0x3da16b54, 0x3e115d06, 0xbe501d95, 
    0x3e1afc8c, 0xbc954679, 0xbdc85d62, 0x3da84d4d, 0x3e081e7f, 0x3daeeb4c, 0xbe20cdeb, 0xbe70c722, 
    0xbe08c04a, 0xbc90f224, 0x3d971ca3, 0xbd81b851, 0xb9865d14, 0x3dd944dd, 0xba45226f, 0x3d872b7a, 
    0xbe4fd2eb, 0x3d083b6b, 0x3dc9297d, 0xbe068aec, 0x3e3a090f, 0x3cbd0460, 0x3e3485c5, 0xbe1a0851, 
    0x3e1ab31b, 0xbe439688, 0xbe22d271, 0x3db449f6, 0x3dd1360a, 0xbe2d6251, 0xbd78ed43, 0xbdf446cb, 
    0xbe1f1edb, 0xbe58332e, 0xbd8a09e9, 0xbe2b9251, 0x3d83e1b6, 0x3c3424f6, 0xbd32979f, 0xbde531c4, 
    0xbe1370ff, 0xbdcda72a, 0x3c54f529, 0x3e103156, 0xbdb43796, 0xbe00eaab, 0x3d895eee, 0xbdca23f0, 
    0x3de3cf09, 0x3e2766dc, 0xbe331579, 0x3bbe9222, 0xb9a2d671, 0x3dc199ef, 0x3badcac7, 0xbe05f8bc, 
    0xbc0ac693, 0xbdb0d63c, 0x3de5cce6, 0xbd15aa2f, 0x3cc167ab, 0xbdcade3a, 0xbb3589e9, 0x3dfdb416, 
    0x3e0c4958, 0x3e3049ca, 0x3d66d32f, 0xbdaa0e8c, 0xbdcd4897, 0x3df9e98e, 0xbd63f80b, 0xbda1b7d8, 
    0xbe038f97, 0x3e28dc84, 0xbdd7e680, 0xbe42e89b, 0x3ced9e89, 0x3e222ae8, 0x3d75a0a0, 0xbe5b3f64, 
    0x3da6e74e, 0xbc8ffcf0, 0xbe419cce, 0x3bdf3627, 0x3e02f411, 0xbd469e9c, 0x3ca601fb, 0xbd767fd9, 
    0xbd8938cf, 0xbd4eedc1, 0x3e6a52c6, 0x3e3c3cf4, 0x3e1e91a2, 0xbe087d44, 0x3e574fa3, 0x3ce9dee9, 
    0x3e2bedc0, 0x3dfff479, 0x3dcf60a9, 0xbe2da9b6, 0xbe219ba8, 0x3d7b2947, 0xbe1c16de, 0x3e23aaf1, 
    0xbdcd95f9, 0xbde9e6b6, 0x3e037a47, 0xbdeb33d9, 0x3da36302, 0x3e370e5e, 0xbcacb386, 0x3dbbde69, 
    0x3e4b6045, 0xbd8ec964, 0x3d7b5bcd, 0xbe256dcd, 0xbe3887d2, 0xbdc73b71, 0x3d5323a5, 0x3de73394, 
    0x3c96a741, 0x3df09f3c, 0xbdb50abb, 0x3e08caa9, 0xbde426cd, 0xbe28c383, 0xbbaf39d6, 0xbe1a51f3, 
    0xbe02593f, 0x3d903046, 0xbc6921ce, 0xbe0e51a4, 0x3e3d7776, 0x3d29cc80, 0xbde46f87, 0xbce28ee3, 
    0xbd2c9683, 0xbdfe1162, 0xbd894900, 0x3daa558d, 0x3e05a9b3, 0xbdec0247, 0xbd672a0c, 0xbd3343ca, 
    0xbd1335dc, 0x3e3dad4b, 0x3ce4e38b, 0x3dd8bb7b, 0x3d0db287, 0x3e586cdf, 0xbd19f5b8, 0x3d8bd4fe, 
    0x3d8bfd79, 0x3dfd21a6, 0xbe18d749, 0xbd293406, 0xbdd658d1, 0x3e0f2f54, 0x3d8cd574, 0xbd6ea498, 
    0x3de7e34c, 0x3e167a2a, 0x3ca8f19c, 0xbbf53502, 0x3d8f4cc2, 0xbe06922a, 0x3dba6411, 0x3e1eb615, 
    0x3dfddeb2, 0xbe189783, 0xbda320a5, 0x3d28ef37, 0xbd69c8ba, 0xbd87e818, 0xbe331675, 0xbe1ce289, 
    0x3cb623d6, 0x3dcc0cbe, 0xbcf1987b, 0x3dfd3e10, 0xbdd4c65b, 0x3e53b7c4, 0xbd846a19, 0xbe2128c5, 
    0xbdd2ce2f, 0x3df7c45a, 0xbd1e7cb7, 0xbda6ab90, 0x3e0d4767, 0x3e0b167b, 0xba1d90b9, 0x3e194b49, 
    0x3d945636, 0xbdc8a348, 0xbd71a29f, 0x3d2a766a, 0xbd845d6d, 0x3e06e479, 0x3e2639ad, 0xbccb6e47, 
    0xbe2fcbe3, 0x3df46375, 0xbe0967e1, 0xbe2681b5, 0x3dea0b3e, 0x3e20d72b, 0xbdfac0d2, 0x3dc89892, 
    0x3b89073e, 0x3e80cb49, 0xbe01088e, 0x3cb10d7b, 0xbdf611cf, 0x3d822468, 0xbd215999, 0x3c2692cd, 
    0xbd426131, 0x3e2c8479, 0xbd378151, 0xbe13d0e2, 0x3e424de0, 0x3dc9b398, 0xbc7d376a, 0xbd036502, 
    0x3d86c98d, 0x3e1735ac, 0xbdc36750, 0x3e3b7929, 0xbe1fc9aa, 0xbdee5145, 0xbe1b7703, 0xbd91e92d, 
    0x3e3e7352, 0x3bbe9680, 0x3e21c117, 0xbe1aff90, 0xbdc184f6, 0x3e4d4699, 0x3d16c363, 0xbdef4163, 
    0xbde618cc, 0xbdf7e0d1, 0xbd97480a, 0xbd39c4da, 0xbe464ad8, 0x3e0a5766, 0xbd889da3, 0x3e0cd650, 
    0x3d789a0c, 0x3dba634e, 0xbda9c2b0, 0x3d4562cb, 0xbd225baa, 0xbdb3a98a, 0xbdd39491, 0x3e2d7437, 
    0xbdf5576b, 0x3d28f409, 0x3bca9b4d, 0x3e438f90, 0xbbd9af90, 0xbdd94f08, 0x3c3d5715, 0x3db0e5c0, 
    0xbe1af856, 0xbe328385, 0x3e51daa8, 0xbdc6c029, 0xbdacc091, 0x36948d39, 0x3e120b86, 0xbd1f310f, 
    0x3ddcdc1b, 0x3e23d448, 0xbe10307e, 0xbdcbecef, 0x3da7ecf6, 0x3d85bf3e, 0x3e4a7480, 0xbc71d2b7, 
    0xbe2dd4e9, 0x3d974212, 0x3e0d3266, 0x3e3ce096, 0x3d65ba66, 0xbe12b0e5, 0xbd89675b, 0xbe51cd30, 
    0xbe5fc989, 0xbd9702dc, 0xbc47404e, 0x3dfe2077, 0xbda76728, 0xbe491da7, 0xbd38dc3e, 0x3e048793, 
    0xbe45532b, 0xbc834e50, 0xbd794921, 0x3e05fb6f, 0xbe2a4c2c, 0x3e1d9730, 0xbe5cbf50, 0xbc63ed6b, 
    0x3d115574, 0x3d6b9f81, 0xbd170de2, 0x3cca0b0d, 0x3df0ca17, 0x3de2d184, 0xbe603ce0, 0xbe0f5105, 
    0x3dc06f25, 0xbb59ff10, 0xbcfd75f3, 0x3dd2fa40, 0x3d8c6632, 0x3d323990, 0x3dfd797c, 0x3c3d1955, 
    0xbd638b7f, 0xbd448d7b, 0xbd43a699, 0x3d84de01, 0x3db084dc, 0x3d8ea724, 0x3de10556, 0x3db0693f, 
    0xbdbb7feb, 0xbe3404c5, 0x3e07c235, 0x3de9e6e5, 0x3d7ee7f7, 0xbe3bd604, 0x3b980415, 0xbdebb6db, 
    0x3ca23d2a, 0xbd2e0501, 0x3db04b72, 0x3dfadf8b, 0xbe34a6ab, 0xbe005b28, 0xbde5767c, 0xbd68b6eb, 
    0x3df84e25, 0x3cf012f0, 0x3e2e659a, 0xbdd0506d, 0xbdee26f5, 0x3d45ebff, 0xbe06ea82, 0x3d4e1ef3, 
    0x3d8bd6d1, 0xbe5b0248, 0x3cdaad50, 0xbde661cb, 0x3d9bb9dd, 0x3d405848, 0x3e643866, 0x3dc2efbd, 
    0xbda73307, 0xbdb83984, 0x3e17201a, 0x3dbcb4d2, 0xbdae8e13, 0x3d922e40, 0x3e39cc32, 0xbd31f678, 
    0x3cb75e45, 0xbc98bd04, 0x3d17bf76, 0x3e06ae4e, 0x3dc1ece2, 0x3e1d8ad7, 0x3c85397b, 0xbdb1a636, 
    0xffffc43a, 0x00000004, 0x00000010, 0x00000001, 0x0000000c, 0x00000001, 0x00000020, 0xffffc456, 
    0x00000004, 0x0000000c, 0x00000001, 0x00000006, 0x00000020, 0xffffc46e, 0x00000004, 0x00000034, 
    0xbcd85645, 0x3d688cf0, 0xbba1b6db, 0xb81f137c, 0xbc3bb02b, 0xbb5b0204, 0x3c93a56b, 0x3d10eb0e, 
    0x3ca960ab, 0xbd4d59ea, 0xbd188a37, 0x3d92c4fd, 0x3d02c7b7, 0xffffc4ae, 0x00000004, 0x000009c0, 
    0x3e808409, 0x3e15c4b2, 0x3c3efbd8, 0xbeaba751, 0x3e0cbf94, 0x3e96f295, 0xbdd634ba, 0x3e9d5116, 
    0xbc3950ea, 0xbe4a7384, 0xbdcdd4bf, 0x3dd25c2e, 0xbdadc949, 0x3d1fb1e7, 0xbe1926d8, 0xbb816ec9, 
    0xbe773cc5, 0x3cdace61, 0xbe9f4095, 0xbe837685, 0x3e8d5dbc, 0xbe0ebfba, 0x3ea8c963, 0x3e018084, 
    0x3d7d912f, 0x3e6dd59c, 0x3e69a62c, 0x3e900559, 0xbe0e56bc, 0x3e018220, 0xbe3c8ec5, 0x3d485114, 
    0x3e269d40, 0xbe0cf275, 0x3d5cd520, 0x3e8130d1, 0xbd017f10, 0x3cdcd9e9, 0x3cdfa2bb, 0x3e1f3951, 
    0x3dfda2fc, 0xbe7f3327, 0x3e1f5f5d, 0xbe2134a0, 0xbd0249f4, 0xbdb24283, 0xbd29272b, 0x3e73dca6, 
    0xbe39374a, 0xbe0ffd52, 0x3d88a61c, 0x3e4f378f, 0x3e151685, 0xbe7cd3f5, 0xbdd74ba4, 0xbe4bd619, 
    0xbe6ac828, 0x3e6d3c0e, 0xbd03644c, 0x3da7d247, 0x3d064ba3, 0x3dbe0d6f, 0x3aa175e2, 0x3e0d434a, 
    0x3dc524ef, 0x3ba71394, 0xbdc0f4d1, 0x3cb944b7, 0xbe8795ea, 0xbd43279e, 0x3dd1a9fb, 0xbe37a060, 
    0x3d0c0c94, 0x3e89bfd2, 0xbe560db3, 0xbc9e7bee, 0xbdfe3ec3, 0x3d522c9d, 0x3dfc786e, 0x3dedfda2, 
    0x3e6c4270, 0xbe38eac0, 0xbd6555ea, 0x3da9834a, 0xbd43cd05, 0x3adfa3f0, 0x3d4889ef, 0x3d7c4255, 
    0xbde761bf, 0xbb51fa23, 0x3e41a8f4, 0xbe72f900, 0xbe4c5d32, 0x3e81791a, 0x3cd07449, 0xbe4f7a32, 
    0xbe8af463, 0x3dde61bc, 0x3dffccea, 0xbe015de2, 0x3d8d44e7, 0xbd830586, 0x3e917989, 0x3d701e8d, 
    0xbe825d85, 0xbe29bd89, 0x3e86d1e9, 0x3d918a58, 0xbc048b55, 0xbe41bdf7, 0x3e456416, 0xbd26de05, 
    0xbcc1e5fd, 0x3e9ccaa5, 0x3e5b0ced, 0x3e6376bd, 0xbe95264e, 0x3d20f9fc, 0x3ddc9315, 0x3de39df9, 
    0xbda89d35, 0x3cac0fee, 0x3db16589, 0x3df12560, 0xbd3de570, 0x3d3e2171, 0xbdedf18e, 0xbe028e71, 
    0x3d5a99cd, 0x3cec5f3c, 0xbdc0d502, 0xbdee49c2, 0xbdf416e3, 0x3bbfed1d, 0x3e003528, 0x3b41e526, 
    0xbd08f3b5, 0xbd911c76, 0xbd2f18d2, 0xbe08eeb9, 0xbb99a44a, 0x3e1ebe44, 0xbc993f90, 0x3d5d122b, 
    0x3c9d6509, 0xbdd6dc93, 0xbe070303, 0xbd4e3448, 0xbde90006, 0x3c8c1182, 0xbc514f12, 0xbd185be9, 
    0x3cd0144b, 0xbe0445c5, 0x3b690217, 0x3b858764, 0x3e9bffde, 0xbc1dccba, 0x3da05634, 0x3e677106, 
    0xbdd43bdd, 0x3e390d2b, 0xbe751f26, 0x3e522e09, 0xbe8a73f3, 0xbe2e142d, 0x3e838702, 0x3ce701cc, 
    0xbe8f402a, 0x3e5c6958, 0xbe78433e, 0xbda26b00, 0x3e937d50, 0xbe9617e6, 0x3b3d1cd8, 0x3ea8d1ee, 
    0xbdf1d66c, 0xbd73cadc, 0x3e05e46b, 0x3cfe6aff, 0x3daf7fcb, 0xbeab7f85, 0xbe56adf8, 0xbe2e9067, 
    0xbdad3601, 0x3e905220, 0xbdb7d755, 0xbe6806c6, 0xbe8fe5f5, 0x3dbf25e1, 0xbdc6abda, 0x3d4adb06, 
    0x3e6da2dd, 0xbe25ada5, 0xba99877c, 0xbe7b2ca8, 0xbe5dd19c, 0x3e648e92, 0x3d995556, 0x3e496db4, 
    0xbc6cea82, 0x3e45c20b, 0xbe401326, 0x3e4a7fc8, 0x3da84093, 0xbe11bb1a, 0x3e34aaae, 0xbe59c2b2, 
    0xbe3476a9, 0x3dc4ac0d, 0x3de5640f, 0x3e1e4b27, 0x3d9b587c, 0x3ddf4b46, 0xbd906603, 0xbe34c910, 
    0xbd796b30, 0xbd937096, 0xbe13eb52, 0x3def3d29, 0xbe14b118, 0xbd1803fe, 0x3e3e4455, 0x3db50095, 
    0xbe26c398, 0xbd8e27a6, 0xbe328bb4, 0x3e80aa24, 0x3df498cd, 0x3e3bebb4, 0xbda854c6, 0xbe05f07a, 
    0xbc81347d, 0xbd2750aa, 0x3c4fe6a3, 0xbcc0637d, 0x3d9b62c1, 0x3e01c06d, 0xbe86cc1b, 0x3eac47cf, 
    0xbb89b155, 0x3d6d2b39, 0x3ea70a84, 0xbd11aff0, 0x3eb2a33d, 0x3e7fe9e7, 0xbd925101, 0x3d5ab442, 
    0x3e693d5f, 0xbe219187, 0xbcc753f9, 0xbea29493, 0xbdfe6ffe, 0x3eab0af0, 0xbeaaa48b, 0x3e81a4a2, 
    0xbea57eef, 0x3e90cdd9, 0x3dae6f4c, 0xbe2985a2, 0xbe9d6882, 0x3eadf7d0, 0xbdc4203b, 0x3e8c7a77, 
    0xbc9ddb90, 0xbe08a101, 0x3e1024b6, 0x3c59ba0e, 0x3ccc9a39, 0xbe96f46c, 0xbe983d87, 0x3e4b8488, 
    0x3e887df2, 0x3e1a4223, 0xbe52af4a, 0xbe18334b, 0xbd08c6c9, 0x3e1cf34b, 0x3e62216e, 0xbd450aa7, 
    0xbe412438, 0x3da28d19, 0xbd792173, 0x3be5489a, 0xbe0cd88b, 0x3d9a6f42, 0x3dc8e337, 0x3e20cdf9, 
    0xbc6260c4, 0xbe18d0a3, 0x3d357f3c, 0xbe6fd451, 0xbd012d19, 0x3e5d3506, 0x3d3c7882, 0xbe192615, 
    0xbdecf0df, 0x3db82c83, 0xbda7ea4a, 0xbe51df17, 0x3e6d53f0, 0x3c9fa1fc, 0x3e5ca546, 0x3e814177, 
    0xbe0edc4f, 0xbd2453f4, 0xbca858ea, 0xbdfb2572, 0xbd60a85e, 0x3e54c444, 0xbe34d240, 0x3dd6ebfb, 
    0xbed1ab9e, 0x3eba7ced, 0x3daf7467, 0x3bd0ccf7, 0xbe7456fc, 0x3d7f6332, 0xbeb0acbb, 0x3dc44032, 
    0x3e087552, 0x3e87b7d6, 0xbe19786b, 0x3e02fc42, 0xbec5b89b, 0x3de4ed0c, 0x3dd65703, 0xbd2c3fc6, 
    0xbd1642d4, 0xbe6bf480, 0xbdbe6bbc, 0xbe4ca5a3, 0xbe1fd7ab, 0x3df4ba97, 0xbdae6b54, 0x3d9ae5ab, 
    0xbc303350, 0xbc87ac60, 0x3cb30ecb, 0xbdc13161, 0xbe04fa5f, 0xbed79f68, 0x3e2fedc9, 0xbec010fc, 
    0x3e384f77, 0x3e34364a, 0xbe1985dc, 0x3e255bc7, 0xbe53f3da, 0xbdc6f7d7, 0xbe9fd6c6, 0x3c8685f4, 
    0x3ca5f149, 0x3e3fe47e, 0xbe1449ad, 0x3d6718c9, 0x3e0a21c2, 0x3e353084, 0x3c206e40, 0xbca40fbc, 
    0x3d125159, 0xbd3f9f20, 0xbe0302e4, 0x3e4b260f, 0x3d8ef6ca, 0xbe7b3031, 0xbe413092, 0x3e5166c5, 
    0x3dc871f6, 0xbddc6872, 0x3e07e230, 0xbe169c7a, 0x3d6ebf29, 0xbcd16bd9, 0xbe48dd43, 0xbe83d20a, 
    0xbd2be98f, 0x3e17fea4, 0xbdd230ee, 0x3d134b8d, 0xbd8a7294, 0x3dd49279, 0xbe213f10, 0xbe14f7a6, 
    0xbe836a94, 0x3c19b4e9, 0xbdf20c00, 0xbd1ad8d1, 0xbd95993f, 0x3cf30734, 0xbe33c1fb, 0xbd83fdf8, 
    0x3e56afd7, 0xbe30cff2, 0xbdd16ef0, 0x3e39ad7e, 0xbc0b621a, 0x3da78f6f, 0xbd1244ab, 0x3d8195be, 
    0xbd13a6f7, 0x3caa2612, 0xbe7b4207, 0x3e228b3b, 0xbd107685, 0x3a9d5780, 0x3cd40de0, 0x3e10251b, 
    0xbe1f55b3, 0xbe18a1d9, 0xbc3bb362, 0xbe26db01, 0x3e374a93, 0xbd9b0975, 0xbcacd40b, 0x3d485661, 
    0xbe2b0a99, 0x3de9dbd5, 0xbd4440b8, 0x3ce3d1d1, 0x3da96b3b, 0x3e1e2c85, 0x3e198259, 0x3e713245, 
    0xbe3171d1, 0x3dcf2562, 0x3c909625, 0x3e2a1d0a, 0xbe257bdf, 0x3d6659fe, 0x3e45a878, 0x3daf9ba3, 
    0xbe2c28b3, 0xbe30519b, 0xbd02fe56, 0xbe17c55e, 0xbe3a5c3f, 0x3df5d886, 0x3d2b31ef, 0xbdd32220, 
    0xbe65b712, 0xbe8cab6d, 0x3d1e5b9b, 0x3e375a15, 0x3deec2d5, 0x3d016b24, 0x3d6e3297, 0xbaeb38a0, 
    0x3e1c84bd, 0x3b480382, 0xbd2e3224, 0x3da69fb1, 0x3e0f7c8a, 0xbdff599e, 0xbdc1d9f4, 0xbe4c79cb, 
    0xbe523800, 0xbdc969a7, 0xbe131ff0, 0x3d385c12, 0x3def4229, 0x3e089ecc, 0xbe2c88a1, 0x3e7ee921, 
    0x3dde0f26, 0xbdb1780b, 0x3da524dd, 0x3e0446a9, 0x3d41caa4, 0xbdcb5074, 0xbce29eb6, 0xbcf16be7, 
    0xbdb9255c, 0xbd227f43, 0xbdadc068, 0xbd5a2be9, 0x3d37fe06, 0x3d91b8e8, 0xbcc0fc84, 0x3d288a7b, 
    0x3dd5e28d, 0x3e0517c3, 0x3dc2eb3e, 0xbdc5eb03, 0x3d5f675f, 0xbdd3d01b, 0x3d863b8e, 0xbd16da25, 
    0x3dade228, 0xbd41c736, 0xbe004ec2, 0x3bddf67b, 0x3cc3cf05, 0x3ce189b4, 0xbd04ab5f, 0x3ca7dea0, 
    0x3b82390d, 0xbdafd756, 0x3d8547a5, 0xbe0a0148, 0xbe08b75c, 0xbde3446c, 0xbdba00f9, 0xbddac462, 
    0xbe087ca7, 0x3cc6f0a8, 0xbde89c92, 0xbe5d2328, 0xbd87d952, 0xbcaf2cf1, 0xbe0b1858, 0xbdb14f31, 
    0x3e18da7c, 0x3d8ff9f1, 0x3e82197e, 0x3e6d5135, 0xbe5790c8, 0xbd8bef5a, 0xbe8f1b97, 0xbe305bcc, 
    0x3e54bf28, 0x3ea5cede, 0xbe201ef4, 0xbb7042d7, 0xbe491236, 0xbe2d563a, 0x3c5976eb, 0xbe091c88, 
    0xbe8ffed0, 0xbe290347, 0xbdbf65b9, 0x3e7885e7, 0x3d6042a0, 0xbe129bbc, 0x3e4edb9c, 0xbe00a696, 
    0x3d9fbf9f, 0xbd994766, 0xbe7a8441, 0xbe14a103, 0xbdd5408a, 0x3e0676a1, 0xbd372a56, 0xbe64e6c7, 
    0x3d095fcd, 0x3e0dc456, 0xbe41c9f9, 0xbdb2ca1a, 0xbe07b008, 0x3da9aa36, 0x3d8a05e1, 0xbd80d7aa, 
    0xbe2eecec, 0x3e595436, 0xbcc6933e, 0xbe312702, 0x3d3198cc, 0xbd5fc3af, 0x3d30177a, 0xbe595a9b, 
    0x3e80b302, 0x3e5f1a00, 0xbdd42c0d, 0xbe1d09e5, 0xbdafc4d4, 0x3e47639d, 0x3d7ba2bb, 0xbc1f3ca1, 
    0xbdaaa6dd, 0x3de21608, 0xbabd33be, 0x3e498772, 0xbd5fc282, 0x3e0c849e, 0xbdd4ec32, 0xbde22dfd, 
    0x3d5605cf, 0xbe22083c, 0x3e3bdafc, 0x3e223ac1, 0x3d08cfbd, 0x3d111d3b, 0x3db3dca8, 0x3d366938, 
    0x3db08006, 0xbe9c6f18, 0xbe420fce, 0xbe925214, 0xbe9d5836, 0xbd3fd2b9, 0x3e2e1a4b, 0x3d2f513e, 
    0x3ebc8469, 0x3ea0792e, 0x3e1f8e03, 0xbb761e7e, 0x3ea62d94, 0xbe97023e, 0xbc9461c1, 0x3e3c748e, 
    0x3e94c53e, 0x3e3034ee, 0x3e0c7433, 0xbdb150b3, 0x3d98e822, 0xbe51e921, 0x3e716cc1, 0xbda30c34, 
    0x3dca6bbb, 0x3e81689e, 0x3e77c15b, 0x3df41266, 0x3c00fb24, 0xbe52bb28, 0x3e96380b, 0x3e553292, 
    0x3e14531e, 0x3ea89013, 0xbe9a2c4f, 0xbe0c0265, 0x3e21801e, 0xbcdfd55c, 0xbe14f189, 0x3dda22b1, 
    0xffffce7a, 0x00000004, 0x00003000, 0xbe2ea43a, 0x3da44fae, 0x3f2ba334, 0xbef5f8dc, 0xbd1b6c39, 
    0xbef64fcb, 0x3bbe3f24, 0xbe7d04c6, 0x3e55b5d9, 0x3ba9e2e8, 0xbe81da02, 0x3e295d7c, 0xbcba896f, 
    0xbd33f3c3, 0x3dd58eb8, 0xbeeaceb6, 0x3f045d98, 0xbed3df96, 0xbe9cda15, 0xbda0bc47, 0x3e5f1453, 
    0x3efc247d, 0x3e5fe93a, 0x3e891248, 0x3e5d7188, 0x3daeeb21, 0xbd788147, 0x3f164b86, 0x3f248a07, 
    0xbed2e252, 0x3ccc703f, 0xbf1b6ec0, 0x3de76fee, 0xbf14d7fb, 0x3e91a519, 0x3ddb5831, 0xbe8b33d2, 
    0xbf32adf1, 0xbf043cc7, 0xbe7b161d, 0x3ef8bac0, 0x3e96c22c, 0xbefb8191, 0x3f1ea91e, 0xbf072e15, 
    0x3e558ca5, 0xbea30a1b, 0xbf0abce1, 0x3e7c77a8, 0x3eef6b11, 0x3e3327d9, 0x3e6a76ad, 0xbe4082de, 
    0x3ed974db, 0x3eafe179, 0xbe08055e, 0x3ead54ad, 0x3ea611ad, 0xbeb9a801, 0xbed9fbb4, 0xbeda08fd, 
    0x3dd6c417, 0x3ef8d7ce, 0xbf108a2e, 0x3eeacbe7, 0x3f31e072, 0x3f0e4039, 0x3e069dfc, 0xbf0b6099, 
    0x3d89165e, 0x3f0651d7, 0xbe51e7c2, 0xbe51f8ba, 0x3f023e3b, 0xbe619ef7, 0x3f237482, 0xbe53176a, 
    0x3cb08d1f, 0x3e5fee44, 0x3cef90e4, 0xbcd0602e, 0x3df1b318, 0x3e5ad885, 0x3dba4df3, 0xbe492ec0, 
    0xbe64d701, 0xbec06f0e, 0xbe9822d7, 0xbdad41aa, 0xbe6618fe, 0x3e88dd03, 0xbea3966d, 0xbde0d3e0, 
    0xbf2438e4, 0x3f103b91, 0xbd012b18, 0x3d35e3c9, 0xbe99db7b, 0xbeb68ce5, 0x3f7001eb, 0xbe609192, 
    0xbea7bcd5, 0x3d9fbc3c, 0x3f086d0b, 0xbecf9dfc, 0x3ed2897f, 0xbf01f4cf, 0xbeb0f503, 0x3ef1ae03, 
    0x3be1667a, 0x3f8d534f, 0xbd1a46d2, 0xbecd62cd, 0xbe23dd48, 0xbf2544d5, 0xbee20f20, 0x3ee93801, 
    0xbf43ceae, 0x3f1f4e05, 0x3dc656eb, 0xbe85b290, 0xbe21b3f6, 0xbe25b1d1, 0xbebce665, 0xbed05796, 
    0x3f63a487, 0x3f175dfc, 0xbea4cf37, 0xbf3de8db, 0x3f2b5994, 0x3f477bf9, 0x3f1221be, 0xbe2521c1, 
    0x3e421fbd, 0x3edb9aa5, 0x3e84062a, 0x3f2711a5, 0x3df3d7b9, 0xbd872a61, 0x3f1bbda6, 0x3f02022c, 
    0x3b9ad164, 0xbe8cd708, 0xbed09f19, 0xbcb6f2f7, 0xbdd12a28, 0xbef5d50e, 0x3d950b90, 0x3f09d29c, 
    0xbe8b19c4, 0x3eddf5cc, 0x3e33e199, 0x3f38a67c, 0xbb942d97, 0xbebb0e72, 0xbf04b885, 0xbe95c028, 
    0x3f27aa26, 0x3ea8a538, 0xbf2fc5d9, 0x3dbdb077, 0x3e947474, 0xbebd565d, 0x3f4bc480, 0x3d1438ee, 
    0xbf4875ed, 0xbe287436, 0xbe8fa120, 0xbf5bc544, 0x3e4e3df3, 0x3f3b79c0, 0xbe293240, 0x3f1b171d, 
    0xbe4632da, 0x3ee73dbc, 0x3ed8eb14, 0x3f761f55, 0x3ee49ef3, 0xbecc2a2a, 0xbea1eb74, 0x3f060f16, 
    0xbe5fb6f4, 0x3e74c452, 0xbf0f7815, 0x3e21ab68, 0xbe38d966, 0x3f27c5d6, 0xbf13b217, 0xbf28da51, 
    0x3d29da04, 0x3eff4351, 0xbe91844d, 0x3f1ecd43, 0xbe675e95, 0xbf36f4be, 0x3edd09d5, 0xbf1d1c82, 
    0xbf07d9f0, 0x3e2410fc, 0x3f243ef9, 0xbe262723, 0xbcc3336a, 0xbd1d3cb9, 0x3f0035d0, 0xbe12ad1a, 
    0xbf28d66a, 0x3f1f4108, 0xbcf7608e, 0x3f17aa16, 0xbeadbbd5, 0xbe65dd27, 0x3e5955f3, 0xbf3a80c8, 
    0xbe01e5be, 0x3f22d00d, 0xbea8929a, 0xbe8817a8, 0x3c09c84e, 0x3f0dd943, 0x3dbb67e8, 0x3eba33d1, 
    0xbe61ec08, 0xbdcfbf56, 0x3ef0f69c, 0xbeb03f84, 0x3eb5d60b, 0xbebe5179, 0xbe8a7f27, 0xbeb590c5, 
    0x3efda230, 0x3c26f9e1, 0x3ef5efe0, 0xbdd60c8f, 0xbcc3f894, 0xbeb82021, 0x3ec232ad, 0xbdc7b045, 
    0xbd809468, 0x3eca0b61, 0xbe73d108, 0xbf0cb47a, 0x3f280698, 0xbcb3a383, 0x3f109324, 0x3f22e995, 
    0xbf11da56, 0x3e14fd3e, 0x3e012d79, 0x3f2e7a43, 0x3e17048b, 0xbc3a9e85, 0xbe8ede71, 0xbe0679d1, 
    0xbf1cc017, 0xbdc9c1ce, 0xbda5e1d2, 0xbe6841de, 0xbf307b2c, 0xbea8e6d8, 0xbeed0fa1, 0x3d976c0f, 
    0xbe02fa3e, 0x3a64216f, 0x3f02bf42, 0xbf0769f3, 0xbef240e7, 0x3ebd4e7d, 0x3e8898d2, 0xbe48f36f, 
    0x3ee05035, 0x3ec69798, 0xbe5c6c80, 0xbecdb484, 0x3ecd83c0, 0x3d6ee99f, 0x3cb34d28, 0x3e760e34, 
    0x3d91f6f8, 0x3f3c478a, 0x3f025a36, 0x3e69455a, 0xbf3fe661, 0xbe82239d, 0x3e76d359, 0xbd002303, 
    0xbe3f8daa, 0x3ef1cfb0, 0xbdb14080, 0xbf085081, 0x3e1fd5f5, 0xbf1811a0, 0x3f527d0d, 0xbf196648, 
    0xbf39b56a, 0xbee90adf, 0xbf200c2f, 0x3dcdff77, 0x3ecfc7a4, 0xbeb95c99, 0xbe47c6e3, 0x3eff5c8c, 
    0x3d75c12f, 0x3d83746c, 0xbf4fbf11, 0x3df81393, 0x3f20b55e, 0x3f1c9422, 0x3ec6b9b8, 0xbe37ba03, 
    0xbbf3fd86, 0xbe5dbb80, 0x39a7c1b4, 0x3f0d6554, 0x3ec20331, 0x3f3c5dbf, 0x3e00b918, 0xbe54a884, 
    0x3da2bbd5, 0x3efc40a3, 0x3f2310f4, 0xbdfa8fec, 0x3e98588a, 0x3f146f20, 0x3f3543e5, 0xbf1588d1, 
    0x3d08bd0a, 0x3f129811, 0x3ef38465, 0xbe91896c, 0x3f091006, 0xbe49ef73, 0x3eadb4fe, 0x3d2e7892, 
    0xbe86cd48, 0xbe6dbbf8, 0x3ea4277f, 0xbdb771c6, 0x3f1da4c6, 0x3c08ef81, 0xbdaab16a, 0x3e7432c4, 
    0xbe09ebc4, 0xbf15503f, 0xbf04ffb4, 0xbc70ab69, 0xbeb9c139, 0x3f0d4604, 0xbe552587, 0xbe77ea7a, 
    0xbebe390d, 0x3f02780b, 0x3e711616, 0xbf0859d2, 0xbeda170b, 0xbe08e6a5, 0xbe112e60, 0x3e08bd0a, 
    0xbe7cbb65, 0xbf3cda0c, 0xbdc1fd46, 0xbe7b27c6, 0xbeab1d40, 0xbe2432c9, 0xbe996130, 0x3da56986, 
    0xbeda59b0, 0x3eb9cdbc, 0x3de21978, 0xbeaee700, 0x3e7332b9, 0xbe09982d, 0x3eba601a, 0x3ea54e12, 
    0x3e721bc2, 0xbf090eba, 0x3d956b42, 0x3eb6c9d5, 0xbe34251c, 0x3f165c97, 0x3f0ef9d7, 0x3ec651ef, 
    0xbe096efc, 0xbebc2d8e, 0x3ef4a2bf, 0x3e4b7686, 0xbd32acd3, 0xbde45bd8, 0xbd1ffe68, 0xbdb9bdab, 
    0x3e81473e, 0xbcbe055b, 0x3e528a85, 0x3e9798bf, 0x3ed009e6, 0xbdf7fd47, 0xbe6119c1, 0xbbed056c, 
    0x3eea50e6, 0xbde29619, 0xbdcaea75, 0xbecb301d, 0xbf01a779, 0x3e5c6966, 0x3e8017c0, 0x3eb6caeb, 
    0xbe7ed905, 0x3ea1d2c6, 0xbefe9333, 0x3e6382eb, 0xbe078c60, 0xbe0aa00b, 0x3edf3895, 0x3ceee853, 
    0x3f1b33a8, 0x3e57b2df, 0x3e40e69b, 0xbeb91639, 0xbe8834dd, 0x3f090f2f, 0x3e8b7306, 0xbf0b5aef, 
    0xbe73342a, 0xbe26f666, 0xbea7ab06, 0x3eef06f9, 0x3e76a7c3, 0x3dc562c8, 0xbd808e98, 0x3eaa8145, 
    0x3f03e4ea, 0xbf40f9c5, 0x3df8d88e, 0xbf1aeae2, 0x3eb8fb94, 0x3d4b1fa8, 0xbdab2b07, 0x3de6efae, 
    0x3e0f43d8, 0xbeb778d1, 0x3ed6c672, 0x3d7dbbba, 0x3bd7fcfb, 0xbbe31aa5, 0xbf133159, 0xbe938d9d, 
    0xbe26c707, 0xbe8292b9, 0x3ddb77bc, 0x3e59c1f9, 0x3ed7d58a, 0xbe5a0b69, 0x3e86ab6a, 0x3e85780b, 
    0xbc117137, 0x3ec8c416, 0x3e328353, 0xbf1ca408, 0xbe1802ab, 0x3e7e70b4, 0xbce563c3, 0xbe87f432, 
    0x3e883d91, 0x3c1686d7, 0x3db1d503, 0xbf0baefb, 0xbee8b985, 0xbdb42468, 0xbd7a24ef, 0x3ebf4e8d, 
    0x3f03ca12, 0x3e946079, 0x3dae727d, 0x3eb4e1f0, 0x3f0a66c7, 0xbf1e4417, 0xbe6ac1fd, 0xbeccfb3b, 
    0xbecdb84f, 0xbdfb9cbe, 0xbec363b3, 0xbdfc6b6a, 0x3f1a2e5d, 0xbe5f27af, 0xbf05a5aa, 0x3c0e2014, 
    0xbeac2f84, 0x3f19c807, 0xbe5d5fcf, 0xbe1f3692, 0xbeca4ef7, 0x3efcae89, 0x3ec1b064, 0x3e5acf89, 
    0xbf06519c, 0x3f06bd54, 0xbdbd7d18, 0x3ebc0e4d, 0xbf03aeda, 0x3e5d0224, 0xbe9b2c82, 0x3e91907b, 
    0x3f13516a, 0x3e9c9655, 0x3dcbb394, 0x3eb39c1f, 0xbe4a5e07, 0x3e1ec7fb, 0xbf130346, 0x3ced3169, 
    0x3af5d04b, 0x3efdaae4, 0xbf093d53, 0x3f0851e2, 0xbea79b4f, 0xbf00b221, 0x3ead431d, 0x3f121f09, 
    0x3eb2be3b, 0x3e89e321, 0xbeea6c9f, 0xbee03067, 0xbebd7fe6, 0xbbb6b3c8, 0x3ecae6fb, 0xbe94881f, 
    0x3eb4892a, 0xbe3cf33e, 0xbec6f00a, 0xbe68d262, 0xbda2afb8, 0xbe0db0b3, 0xbda612bb, 0x3f1b0eb7, 
    0xbe5aff87, 0x3d261dbe, 0x3f096a2d, 0xbf280a8a, 0x3f42aee6, 0x3e258f0a, 0x3f1a9a5c, 0xbee53ce7, 
    0x3e8ecedb, 0xbe6caefa, 0xbd929d7a, 0xbf0d90d0, 0x3f4b8b64, 0x3f002200, 0x3eb29de7, 0xbf03e774, 
    0x3f1a2155, 0xbe8711bf, 0x3f07e0bc, 0x3f090e9e, 0x3d4d9f78, 0x3e9b7af8, 0xbe1fc066, 0x3eefe1c3, 
    0x3d72b08e, 0xbcef38fe, 0xbdaea66b, 0x3d129121, 0xbed8090d, 0xbdef1189, 0x3de04189, 0x3e8cff21, 
    0x3eff80bc, 0xbee052c1, 0xbe1047d9, 0xbf0b17e3, 0x3ec08630, 0xbb60174f, 0xbdf3cbf1, 0xbe2e3281, 
    0x3f250f22, 0x3f06f5c7, 0xbe06d2c6, 0x3e69f0e8, 0xbf1ede9c, 0xbf0b7a80, 0xbe7616c8, 0xbf288cfc, 
    0xbce19ff5, 0x3ed9c469, 0xbeb85c57, 0x3d9e2d0e, 0x3f08d779, 0xbe951cf7, 0xbeefcf1d, 0xbedc0bda, 
    0xbf0320f8, 0xbe320580, 0xbeddeac2, 0x3e156081, 0xbf08511f, 0x3ec14fad, 0x3ee6a8a7, 0x3f0dc0dc, 
    0xbeb17eb2, 0x3ee2e411, 0x3eb08f21, 0xbe6c9898, 0xbebdef8b, 0x3ee3e816, 0xbf34270f, 0xbe7e12ab, 
    0xbe1d13f2, 0x3d944c69, 0x3ea5fae4, 0x3e754373, 0xbefb600d, 0xbf2c078c, 0xbcf6ba6a, 0x3cf71916, 
    0x3e60f3cb, 0x3eb9d8b0, 0x3f58ed77, 0x3c646268, 0x3ef99be0, 0x3e88f22d, 0x3e40e6e2, 0xbe9a52e0, 
    0xbde89329, 0x3f16bd4e, 0xbc89a0ac, 0xbeb0d1ab, 0xbec7e215, 0x3f14b62c, 0x3f366ba1, 0x3ed87216, 
    0x3f029adc, 0x3e80c595, 0xbe449613, 0xbdca8461, 0x3f31d66d, 0x3f0bf169, 0xbf1fede4, 0x3e7766a7, 
    0xbecf13a6, 0x3ee939de, 0x3ea540cc, 0xbf03cbb2, 0xbeff99e7, 0x3ebfdfa0, 0x3eb4a6af, 0xbe4612a5, 
    0xbcc63078, 0xbd82b906, 0x3f1f8ca7, 0xbf37a455, 0xbed17bd1, 0xbf00e328, 0x3f1be47a, 0x3f11910e, 
    0xbe876794, 0xbd2f5d32, 0x3f02f53d, 0x3d315c73, 0x3f0ea38e, 0x3d6487d7, 0xbf2245fe, 0x3ece9e65, 
    0xbe85fd8f, 0x3f319723, 0x3e8b9a6f, 0xbe82aa06, 0xbccc1d45, 0x3e8f3e73, 0x3dc6a022, 0xbe9cfc59, 
    0x3e967217, 0xbdae68b3, 0xbedda3da, 0xbe99edc7, 0x3f010ffc, 0xbec2697e, 0x3e22505d, 0xbe21af02, 
    0xbf19d436, 0x3e5785a9, 0xbee61e27, 0xbf062146, 0xbe8687ae, 0x3e9eceb3, 0xbde0dfa3, 0x3e8e9345, 
    0xbea3ac35, 0x3e3dbdca, 0x3ec28f9f, 0x3e0cdb0b, 0x3ebdf308, 0x3efc7e6c, 0xbe4a641b, 0x3e9c2410, 
    0xbf1e19c2, 0x3ee543dd, 0xbc12c756, 0xbdb2e64c, 0xbf16f3f6, 0x3e4df49c, 0xbefce2bd, 0x3e1c1cf9, 
    0xbebbcc37, 0xbe91339c, 0x3f0003d4, 0x3e7e905e, 0xbceaca7c, 0x3f119bb7, 0xbed65c59, 0xbe66d7b6, 
    0xbd3a920b, 0xbf0dde75, 0x3eb06b38, 0xbea3b549, 0xbf19131c, 0xbdc211f8, 0x3e9955d9, 0x3f147e12, 
    0x3e856a86, 0xbe373aae, 0xbf46c765, 0xbee43de6, 0x3f4c7353, 0x3eefa769, 0x3e85d6c4, 0xbe15390d, 
    0x3cf8b789, 0xbf2819bf, 0xbe9acd12, 0xbebb76b8, 0xbe13b7e9, 0x3f504dff, 0xbf185bce, 0xbf291ec1, 
    0xbe5dfa4b, 0xbe8f1002, 0xbdee59c3, 0xbd80c73e, 0xbeb1b43b, 0x3f059724, 0x3f34f803, 0x3eb673c1, 
    0x3c566f62, 0xbe35c844, 0x3d29e79e, 0xbe2e0586, 0xbda63b26, 0x3e3e3815, 0xbe6e4b64, 0xbe3ad2cc, 
    0x3e06f49f, 0x3e650f0d, 0xbdafc0b8, 0xbea651f7, 0x3f504da6, 0x3dc406be, 0x3f0b0a11, 0x3de56050, 
    0x3e2b8a89, 0xbd93e302, 0x3e160a20, 0x3f18e308, 0x3df67a69, 0xbd424494, 0xbe51e3ce, 0x3da41902, 
    0x3e80b82e, 0x3f399821, 0xbf08ccc2, 0x3cf3811e, 0xbe8d2563, 0xbe354000, 0xbf1b6261, 0x3f03896a, 
    0x3f04acb6, 0xbcf765f0, 0x3e809b1a, 0x3f020bf8, 0xbf102f4a, 0xbda5f5d7, 0x3ddf129c, 0x3eb83e21, 
    0x3f086d73, 0xbeae6824, 0xbec4b637, 0xbeaf6c12, 0x3e798a02, 0xbe584924, 0x3e710338, 0x3df7dd49, 
    0x3df1fe3f, 0x3ea28399, 0x3c6e420c, 0x3e218b3f, 0xbdd849fa, 0xbeec3f69, 0x3c002388, 0x3dd6464a, 
    0x3f027583, 0xbf131a1b, 0x3ec14de7, 0xbe11ea7f, 0xbe602e85, 0xbf283230, 0x3e88c757, 0xbd3d1dca, 
    0xbebfdddb, 0xbecc1806, 0x3f101f37, 0xbe7c4650, 0xbf189a6a, 0x3d5adcc1, 0xbea765ea, 0xbdda7b8b, 
    0xbe985949, 0xbde839e8, 0x3e3b13bb, 0xbe9e18a9, 0xbee45ac5, 0x3eedb56c, 0x3eaabdc6, 0x3f12fd8b, 
    0x3de7abb9, 0x3d99f0fa, 0xbebd613c, 0x3ee6067f, 0x3e45a5b1, 0x3e78fb7c, 0x3e0921b3, 0xbea07c34, 
    0xbd8c5798, 0x3eaa8107, 0x3d40fae9, 0xbedc2ca9, 0xbe82a118, 0xbd1498ce, 0xbef14d96, 0xbdea0605, 
    0x3f0d655f, 0xbea37c8d, 0x3d1815d9, 0x3e812d22, 0x3ea707ab, 0xbe59195c, 0x3df0046a, 0x3eaa938e, 
    0x3f1955da, 0x3dc7165a, 0xbe097af4, 0x392bb5f1, 0xbe8b0d19, 0x3ef3b1bb, 0xbc9417bd, 0xbe976657, 
    0x3e70c4a2, 0xbd91a3bc, 0xbec4a0cb, 0xbe07501f, 0xbee5e9b5, 0xbec8bf94, 0xbe96d834, 0x3eb4860b, 
    0xbeceaab0, 0x3c2ccf8c, 0x3c3ba4c2, 0xbeaf8606, 0xbe392f9b, 0x3e02479f, 0x3dd3b98d, 0xbcd5dd5f, 
    0xbec67a86, 0xbeda80df, 0x3bb9a293, 0x3e8d8154, 0xbdb80745, 0xbd9942a5, 0x3e2198ae, 0xbf03b6d3, 
    0x3e0aa370, 0xbe896bba, 0xbe3f6cf8, 0x3e2ccaca, 0xbbf58323, 0x3e3e0cc4, 0xbe371794, 0x3e01233e, 
    0xbd69e341, 0x3eb51907, 0xbe9a3340, 0x3f0df5c7, 0xbe60faea, 0xbdca3916, 0x3f03fadc, 0x3f0b33a7, 
    0xbd101448, 0xbef705a4, 0x3e57847d, 0xbe214af6, 0xbe3ded49, 0xbee50f19, 0x3e861fad, 0xbe03c82d, 
    0x3deff828, 0x3eacbba9, 0x3e326110, 0xbebbe963, 0x3f3ed232, 0xbf02cd78, 0x3a94bfc7, 0x3d8fb105, 
    0x3e419f34, 0xbf0690a4, 0xbe47c26a, 0x3e88c7d2, 0x3ee8c91c, 0x3e726f63, 0xbebce47a, 0x3e94f092, 
    0x3e5bab20, 0x3d796239, 0x3eca3f6e, 0xbe1999ee, 0xbeb2a2b5, 0xbe0d969f, 0x3e86a8fb, 0x3d30dacf, 
    0x3e0aa84c, 0xbe2b157f, 0xbe99a85a, 0xbf2a2e3c, 0x3e7d1989, 0xbeebaaa1, 0xbec86f25, 0xbe7da2f9, 
    0xbf0635be, 0x3ea60b21, 0xbe11e701, 0xbf1b133b, 0xbc270b77, 0x3c099ae2, 0xbe935211, 0xbdbe4b2f, 
    0x3ed7147d, 0x3e7f68a0, 0x3d15beea, 0xbd9e1c0d, 0xbea28c81, 0x3d3d2644, 0xbca7608c, 0x3e74a429, 
    0xbec0f74c, 0xbda6c631, 0x3e41ac72, 0xbeac4276, 0x3e8d49cd, 0xbeffd355, 0x3e2e3414, 0x3dbdb6b9, 
    0xbec18c4c, 0xbe196c07, 0x3e8fe3f1, 0xbe9b2b57, 0x3ee86499, 0x3ebbbebf, 0x3db854ec, 0x3e15ef1e, 
    0xbc33aa84, 0xbf1316ce, 0xbe101a19, 0x3c6eba54, 0xbd2abf7c, 0xbee2679f, 0xbe85f9dd, 0x3df9a2dc, 
    0xbec92dd3, 0x3f0477f8, 0xbd72e38d, 0xbd1d80f2, 0xbee79973, 0x3f26203b, 0x3ec9a990, 0x3ebc638b, 
    0xbd4ff6fe, 0x3e5234d2, 0xbef0eae5, 0x3edbf8fa, 0x3f2a09e5, 0xbf109545, 0xbe1a4ab3, 0x3f16719e, 
    0xbefde47f, 0x3e1c9304, 0x3d92c026, 0xbe9f5fc8, 0xbe97656e, 0xbebaf5d8, 0xbed8624e, 0x3e32ecc2, 
    0xbbb62b2e, 0xbef678c2, 0xbe6c0fe4, 0x3eb0c70c, 0x3f22eab7, 0x3e0de144, 0x3eb9ca34, 0x3f075903, 
    0xbd1e98a4, 0x3edab516, 0xbe8c414a, 0x3e4fbfe2, 0x3eb29147, 0xbd0a1fbd, 0xbd41e0bf, 0xbdffebf2, 
    0x3e0b6a83, 0xbef08016, 0x3e81548d, 0x3ef8fba7, 0xbd9dee70, 0xbd8727ad, 0xbf00b14c, 0x3ef86ed7, 
    0x3efcb0d1, 0xbf20b489, 0x3ea8aec1, 0xbf35109b, 0x3f22b50b, 0x3ef00c20, 0xbe875c64, 0xbee866d8, 
    0x3eaf1c14, 0x3d8a937e, 0xbd9ae297, 0xbf0c7402, 0x3f283c88, 0xbef61e91, 0x3ec77c6b, 0xbdf027fb, 
    0xbf006f29, 0xbee374a5, 0xbc595105, 0xbee5cb23, 0x3f2ca340, 0x3f1beda7, 0x3e224e35, 0x3dbc9efe, 
    0xbdffcfa9, 0x3ec9ba19, 0x3f086dca, 0x3e9cba20, 0x3ed86f6a, 0x3d85eac1, 0x3f068f0c, 0x3e7ac519, 
    0x3dddc8b8, 0x3f1d22c0, 0x3ed627ac, 0x3eb32d5f, 0x3e9e9ec9, 0x3ec0698a, 0x3e98dfe6, 0x3e662787, 
    0xbea33b4a, 0xbec87c11, 0xbe1bd155, 0xbbec51c0, 0x3ea036bd, 0xbea5ad11, 0xbe98fd92, 0xbe3b0d90, 
    0x3b66b1e6, 0xbe70e299, 0x3ed4686f, 0x3d2f9a3a, 0x3c85d1b2, 0xbd826b78, 0xbede81f7, 0x3e88d404, 
    0xbe472987, 0xbc4b4b21, 0x3e906508, 0x3e19e335, 0x3e0330fb, 0xbd206713, 0x3ea51088, 0x3ebf9d7f, 
    0x3e79f30e, 0xbeb2ac67, 0x3e404a25, 0xbe9f47b3, 0xbe8bfb67, 0xbe080d7f, 0xbe2ba53c, 0x3ea2187f, 
    0xbdd968cb, 0xbe9d511e, 0xbe6816e5, 0x3cb648c7, 0x3f241241, 0xbe0ef415, 0x3e5381f7, 0x3ef1d85c, 
    0x3dcded56, 0xbc428aca, 0xbec5e768, 0xbe10bbf3, 0x3eb68f38, 0xbeac5783, 0xbe946b72, 0xbe4f652d, 
    0xbe93a112, 0xbd95c4ce, 0x3ee13542, 0x3cd8816a, 0xbe7a8605, 0x3e528dc3, 0xbe9270c9, 0x3f1773f8, 
    0xbe8661d8, 0xbe57a010, 0x3e96be2d, 0xbe9375d3, 0x3edd819e, 0x3effbe73, 0x3de78667, 0xbe98b4db, 
    0xbecfbb19, 0xbed15879, 0x3e88716c, 0xbe234fd4, 0x3f27c8fb, 0xbebf610c, 0xbe3c0504, 0x3ebf17e5, 
    0xbdf044d6, 0xbcca12e1, 0x3df89abc, 0x3d9c3e71, 0x3ed6307c, 0xbe44ecc1, 0x3e3ac894, 0x3ee11153, 
    0x3d9560d5, 0xbe5a8ef8, 0x3ec46750, 0xbe49a991, 0x3e41cf9c, 0x3e2eac68, 0x3d004128, 0xbd87cc10, 
    0xbe6c3bd9, 0xbd23a9cc, 0xbe80438b, 0xbd99c542, 0x3ee9ad19, 0x3eb25bae, 0x3ebe202c, 0x3e9fe9f1, 
    0x3f29f553, 0x3c31b3da, 0xbe593901, 0x3ef29d5d, 0x3ebcb518, 0x3ebe56db, 0xbe8a5353, 0x3c2128fe, 
    0xbebe0a36, 0x3b9cccad, 0x3e8dd8cd, 0xbdcb207f, 0x3d6f01c4, 0xbdc19e31, 0x3e645866, 0x3e89c57f, 
    0x3d470b79, 0x3d2e5574, 0x3e9cc431, 0x3ef58215, 0x3df4e8f7, 0x3f0bf99e, 0xbece55a5, 0xbecb53b4, 
    0x3e53a72c, 0x3ef7047f, 0xbce62455, 0xbe9c31ce, 0xbeae52c5, 0x3e93576e, 0xbf27433d, 0xbd6fa266, 
    0xbe9e32cb, 0x3ec367e4, 0xbe8eb9c1, 0x3e099639, 0x3f291054, 0xbe99cd68, 0x3ee5c66c, 0x3d616b58, 
    0x3ebab8b1, 0xbe9cf118, 0x3ef8c08e, 0xbd2e4eeb, 0xbe69e544, 0xbe9a88ff, 0x3e273bca, 0x3f2ba92a, 
    0x3e96d8b2, 0x3ccbcb59, 0x3e1f8a38, 0x3ea4c971, 0xbe5e7854, 0x3f079d49, 0xbf011a34, 0x3f2bacbf, 
    0xbec650d7, 0xbf1081b4, 0x3f059ed6, 0x3e4c7073, 0xbe1f6dd0, 0xbde00177, 0xbef5c6e0, 0xbe879ebc, 
    0x3efff318, 0xbeb31f43, 0xbebe0159, 0xbed9c9a3, 0xbdd8718c, 0xbd94b61b, 0xbf031977, 0xbdc55f25, 
    0x3f2670d1, 0x3e354bd0, 0x3f216282, 0xbe9779d9, 0xbe91e4d9, 0x3f3b01d2, 0xbe76cde9, 0x3bcadf8d, 
    0xbe6412c2, 0xbe732fe2, 0x3e85875d, 0x3ebb1548, 0xbe7ac868, 0xbd920633, 0xbc2abd9c, 0x3e8616b6, 
    0x3f1999b7, 0xbef54543, 0xbcd0ea38, 0x3f0a5ed4, 0x3e6fccbb, 0xbeb404c3, 0x3eeff9cc, 0x3eaf82be, 
    0xbe5a8469, 0xbec6d09f, 0x3edd6a48, 0xbf273e07, 0xbe943522, 0xbf21eb14, 0xbece2ec8, 0x3ed4cf33, 
    0x3f35f573, 0xbf1fc841, 0x3f5001e6, 0xbde11e36, 0xbe7b587e, 0x3e6a7f3a, 0x3f28ddb1, 0xbef55c99, 
    0xbf3f963c, 0x3e4ef933, 0x3f2fd0da, 0x3f32e3ca, 0x3f486d66, 0xbe57e357, 0x3d6f614c, 0xbd5ceb83, 
    0x3f034c35, 0x3d7db2d2, 0x3e31ba14, 0xbf26125a, 0x3f18a171, 0x3ce76635, 0xbf413e11, 0x3e82c737, 
    0x3f13818b, 0x3dcd2af4, 0xbdec3124, 0xbea4710d, 0x3ee94d14, 0x3cb2a93a, 0x3f7b5622, 0xbd798510, 
    0x3cce33d1, 0xbf0fd203, 0x3e5fd246, 0xbe2a3e5b, 0x3e7e892d, 0x3db7c78d, 0xbeee9c42, 0x3ec60512, 
    0xbeb23ad9, 0xbc93c1f2, 0xbc0cc834, 0x3f37982c, 0xbf06dde8, 0xbf299951, 0x3e2eeabd, 0x3e7a7531, 
    0xbe9d7e2f, 0xbe9b542c, 0x3eb27dce, 0x3e18a313, 0x3f3e7870, 0x3cf2e759, 0xbe6bc498, 0x3ea269bd, 
    0xbe467e94, 0x3e4d000f, 0x3e18aadd, 0xbe42f159, 0x3ecd7aa5, 0x3e80846e, 0xbe50b92f, 0x3c7995fd, 
    0xbf0b012c, 0xbe2d1765, 0xbd34360d, 0xbe106f5b, 0x3f1ad965, 0xbf158649, 0xbeb717ee, 0xbe10832f, 
    0xbef08d5f, 0x3f23be67, 0x3d3a414b, 0x3dbcf296, 0xbe428b87, 0x3ca8612e, 0xbea4cf0d, 0xbe62b6a8, 
    0xbea9d4de, 0x3f4440fe, 0xbe2c038a, 0x3e3daf81, 0x3ebe1369, 0x3e80aa48, 0x3e1d9d63, 0xbf091ca1, 
    0x3eb5b148, 0xbda50e91, 0x3eabd72f, 0x3e757404, 0xbdb8ff62, 0x3e7c047f, 0xbdcd2510, 0xbea4f9de, 
    0x3cf51cdd, 0x3e5fff8a, 0xbea49112, 0x3b189b45, 0xbee1b5e9, 0x3c2000f1, 0xbdf0521c, 0x3e1e2926, 
    0xbe412e13, 0xbed5a1e5, 0x3e55e709, 0x3ea2e03e, 0x3eabee73, 0xbdc9458d, 0xbefe18e9, 0x3d881115, 
    0x3ef48155, 0x3dd9d668, 0x3e03d7e0, 0xbbd2c748, 0x3ed40202, 0x3eb8d88e, 0x3e366700, 0xbeeb70cd, 
    0x3e215c5e, 0x3a235b09, 0x3d82f45b, 0xbf07fc6f, 0x3f232d51, 0xbeee1648, 0xbe3392bf, 0x3df8bcca, 
    0x3f020f9d, 0xbee072dc, 0xbeb24f18, 0xbf2b66df, 0x3ec8a17e, 0xbe7a75c8, 0xbf12c5c9, 0x3eebe3c4, 
    0x3ea1c22c, 0x3d76091f, 0x3d020045, 0x3f0168db, 0xbea530f7, 0xbe0b707a, 0x3f0d7691, 0x3dac48d2, 
    0xbe90e5b7, 0x3eaeb050, 0xbf1607dc, 0x3ec907a7, 0x3efcad24, 0xbe5ad33b, 0x3eb790ae, 0xbeeac4be, 
    0x3ecc9a72, 0x3f04c5c5, 0x3ea09c21, 0x3ec120a8, 0x3e8ae51b, 0xbeceffe9, 0x3f0ada0d, 0xbefecc63, 
    0xbe180943, 0xbeb81031, 0xbe8d8170, 0xbe14aec6, 0x3ec6ad65, 0x3ea79684, 0x3ee26eaa, 0xbdae4b0a, 
    0xbe46470b, 0xbeaf5763, 0xbe1dc758, 0x3eaa5c44, 0x3d834937, 0xbf3eb533, 0x3efd9262, 0x3eff8cae, 
    0xbdb5f754, 0xbe2860b4, 0x3c195532, 0xbf05f9af, 0x3f1edad5, 0x3f187aab, 0x3f58ba04, 0x3f4e20c8, 
    0xbe95bbc3, 0x3f1d841d, 0xbeec84a4, 0x3f45ce66, 0xbd5b7e20, 0x3f1ba089, 0xbd256b6d, 0xbf19df96, 
    0xbea27114, 0x3f6587e4, 0x3daf8336, 0x3edc9466, 0xbe7bf4f2, 0xbf49fe54, 0x3f463363, 0xbdaa328b, 
    0x3d0a95b1, 0xbef4f48e, 0xbe835ab0, 0xbf0dea8e, 0x3daac4d3, 0xbdd13d13, 0xbeaf482e, 0xbf1d44a7, 
    0x3ed2e363, 0xbee290d9, 0xbf2f66a1, 0x3ec41c82, 0x3f1244d1, 0x3f21279f, 0x3f618393, 0xbeae8e29, 
    0x3ed10b46, 0xbe2cbefb, 0xbf331e40, 0x3d7796c5, 0x3f87b3c0, 0xbeabd272, 0xbf551c64, 0xbf4aaf60, 
    0xb98cce26, 0xbf0c7371, 0xbe9b228d, 0x3e516264, 0xbd69dcaf, 0x3ecaa8f3, 0xbe2cd078, 0xbd9f5141, 
    0x3d21fcd0, 0x3f17df45, 0x3ee42dfb, 0xbf54aa02, 0x3f6f53b3, 0xbeb4ee4d, 0x3f27a0f9, 0x3db60f4c, 
    0x3f5d6be3, 0x3e8c92d1, 0xbde1d2c1, 0xbdb7cf4b, 0x3f676057, 0x3d1d9a95, 0xbe88d37f, 0x3f160aa2, 
    0x3f21650a, 0x3d1d94bb, 0x3f4678aa, 0xbecf7c86, 0xbf074fd9, 0xbd889cfa, 0xbf4df089, 0x3e9a7987, 
    0xbf429f94, 0x3df0d95e, 0xbf08b082, 0x3f35bf86, 0x3d29d70a, 0x3e5b6f1b, 0x3f27ff5d, 0x3f1a38fd, 
    0x3e052971, 0xbc35333a, 0x3e0a2604, 0x3f4531e1, 0xbf0dc19a, 0xbe8ab204, 0xbed0fe6b, 0x3e206658, 
    0xbf178168, 0xbf5fe8df, 0xbf172987, 0x3c6a3aaf, 0xbeeddb72, 0x3d8ae9ca, 0xbc4d328e, 0x3e0f3bea, 
    0xbef96074, 0xbdd1de6d, 0xbec61aaa, 0xbdc2ea47, 0xbec8fbc9, 0x3f283345, 0xbe348eba, 0x3eb69844, 
    0x3e6ffad8, 0x3ef9a74b, 0xbe2e0902, 0x3f07ee18, 0xbf135e3f, 0xbe9f5ee4, 0x3f020d6e, 0xbf47b26e, 
    0xbd7bfeb2, 0x3db54eea, 0xbef68096, 0xbe74a28c, 0xbf2aa935, 0xbe6f98bb, 0xbf3191d1, 0xbe834ffb, 
    0x3f0ee987, 0x3eefc227, 0xbe81dcc6, 0xbd923749, 0xbf62824a, 0x3ea62b0b, 0x3e060f98, 0xbedb9634, 
    0x3dc32536, 0x3ee727cf, 0x3daf7f67, 0xbd7adf82, 0xbed38d2a, 0xbe9e03cc, 0xbeae8168, 0x3e0817a1, 
    0x3e927106, 0x3e5de08b, 0xbf0c1caf, 0xbe23cfd4, 0x3eb3bf41, 0x3dc585cd, 0xbeb6f41b, 0x3da60a15, 
    0x3e5e0178, 0x3ebbba8b, 0xbe344307, 0xbec6aaf8, 0xbd474251, 0xbed89b60, 0xbddb74b5, 0xbeb9b20e, 
    0xbe188efb, 0xbf312860, 0xbf318a85, 0xbeb6f22c, 0xbf3a0bab, 0xbcfa43d2, 0xbe14a60d, 0x3f043440, 
    0x3f0711d9, 0xbf138679, 0x3f0365d8, 0x3ec29644, 0xbdc821b3, 0x3ec05553, 0x3f233059, 0x3d63975a, 
    0xbf15ea4a, 0xbf22d18f, 0xbe7c9323, 0x3ec2552e, 0xbe8b43a4, 0x3e5e71ef, 0xbe9b2cc7, 0xbef3dfae, 
    0x3d95ead8, 0x3ef51aba, 0xbf1dab97, 0x3e510c08, 0x3e83d1cc, 0xbea94450, 0xbe25c790, 0x3e99981c, 
    0xbe3693ea, 0x3ea34e80, 0x3f177bcf, 0x3e47686a, 0x3e6d3371, 0x3f079e4a, 0xbf1cae92, 0xbe876981, 
    0x3ddbfd69, 0xbed6f0a4, 0xbf082aa3, 0x3eb7dbcb, 0x3e474686, 0xbee1a73f, 0x3cac6251, 0x3f08216a, 
    0x3f17d96d, 0x3e485c9a, 0xbf206205, 0x3e6b8a13, 0xbd9eff24, 0x3f164145, 0x3f196446, 0x3e24ffae, 
    0x3f2d3f3e, 0xbe9fcc95, 0xbdb58326, 0xbf1928cf, 0x3efe7f60, 0xbd9eba8e, 0x3ecfbe27, 0xbe6639c4, 
    0x3cd87fd1, 0xbf0bd1b5, 0x3ea20cac, 0x3e69d68d, 0x3e596fe4, 0x3ee99ea5, 0x3d9dad35, 0xbf09a17f, 
    0xbe9fa0d1, 0xbe801277, 0x3f14362f, 0x3d704b84, 0x3e6b5c25, 0x3eda9707, 0xbe53b910, 0xbe667687, 
    0xbe9df742, 0xbec7ae04, 0x3e5c0fd1, 0xbf027b28, 0xbd280619, 0x3dd5b51c, 0x3f1d66bc, 0x3ee5e166, 
    0x3e61807e, 0xbdb6e9cb, 0xbe9b15e7, 0xbe638201, 0xbf0b8515, 0xbf4d04a3, 0xbec791ce, 0x3e0b7bd6, 
    0xbf1da899, 0x3d7d7aab, 0x3efb8f9d, 0x3af02928, 0x3e82d624, 0x3f114811, 0x3cdeeedf, 0x3ef3efeb, 
    0x3ec5fac4, 0xbe95cf78, 0xbece0d4a, 0x3e93ab57, 0x3e4dfc53, 0xbefda4e6, 0xbccca7a8, 0x3e42ffb0, 
    0x3ddf5ac9, 0x3db2ee47, 0x3e9a42c0, 0x3ef89357, 0xbf010ef9, 0x3ebe5c25, 0xbed25f05, 0xbec7d522, 
    0x3df49583, 0x3edc986f, 0x3d43e361, 0xbf194084, 0xbd23d6a1, 0xbe207826, 0x3e8b1a3a, 0xbe39c79b, 
    0x3cd862b3, 0xbf06a288, 0x3eae23a1, 0x3e06b199, 0xbf19ab3c, 0x3cc72d13, 0xbf162720, 0x3eb799c5, 
    0x3f0f3ab4, 0xbe87256c, 0x3f03b58d, 0xbdeb25d1, 0xbf098a0d, 0xbee1161f, 0xbe1dbe2f, 0x3dfcccca, 
    0xbee4a8d6, 0xbe5fdd1d, 0xbda71190, 0x38239fc0, 0x3e60d06d, 0xbdc7ca25, 0x3ee38565, 0x3d8e2b89, 
    0x3e524085, 0x3e3f3f17, 0xbeb083bf, 0xbeb18d27, 0xbd946f42, 0xbdb7d905, 0x3e106feb, 0xbe50a08f, 
    0x3ef69e1a, 0xbed4953f, 0x3efb249b, 0x3efd0cec, 0xbed28d4c, 0xbf258971, 0xbebd7e02, 0xbe8d0ca6, 
    0x3eb3b369, 0xbe64ecf8, 0xbe5794ae, 0x3ccf59ba, 0x3cc79bcb, 0xbe81635a, 0xbec4159f, 0x3efe9f86, 
    0x3eaac31f, 0xbef1a250, 0x3d712476, 0xbea9ea96, 0x3e5baf55, 0x3e093122, 0x3e2dd3ab, 0x3ed146cc, 
    0x3e8e4ede, 0xbd9f87e1, 0xbe9326ee, 0xbe4726bd, 0xbdcf63e0, 0xbeab0312, 0x3ee314e1, 0xbdbd9ca7, 
    0xbe48f7ed, 0x3e43fcce, 0x3e8267d7, 0x3f073415, 0xbd54a206, 0xbe3dff02, 0x3e8f421a, 0x3da68846, 
    0x3e7e9a5b, 0xbddd2309, 0xbd132d1b, 0xbd1e3043, 0x3e9ae413, 0xbf072823, 0x3f05b370, 0x3bd41cd6, 
    0xbe75a7c1, 0xbec56330, 0x3e82672f, 0xbe30a052, 0x3dd428e7, 0xbd6cc331, 0x3e6e60cd, 0x3ecf184b, 
    0xbd44fde0, 0x3edd0c90, 0xbedf16fe, 0xbe834424, 0x3e97529e, 0x3ec5d2a7, 0xbf1b430b, 0x3e7f1ad4, 
    0x3f042cf5, 0x3e31f159, 0xbe80d557, 0x3e8ff425, 0x3f8a761e, 0x3dce3d37, 0x3f06aa23, 0xbf414064, 
    0xbf2472c4, 0xbdc0eb28, 0xbf254a09, 0xbcf90476, 0x3eff918a, 0x3e1b57d3, 0xbed59b8a, 0x3f04bae1, 
    0x3def7f9c, 0x3dc6b6fc, 0xbf2ed682, 0xbeba87af, 0x3d731abf, 0xbcf38a01, 0x3ea1f9db, 0x3eb2d3a1, 
    0x3f32cca3, 0x3f01cc04, 0x3f06a37c, 0x3eddefdc, 0x3f4bf727, 0xbe7ab53d, 0xbf220a2d, 0xbe009862, 
    0xbe5493a7, 0x3f1d0da6, 0x3f38e91d, 0xbde0923d, 0x3dce24e4, 0x3f0f9879, 0x3f42e746, 0x3ed2f137, 
    0xbf0779d2, 0x3ed52ac5, 0xbeea7b72, 0x3e38bee9, 0xbe0e11fc, 0xbebe57b9, 0xbe3e9d64, 0x3f1ea259, 
    0xbf1f6f29, 0x3efac5f4, 0xbf3477cd, 0xbe4d0f65, 0x3de08cf2, 0xbd9152b4, 0xbf26a4ea, 0xbf247b75, 
    0x3f11ddd2, 0x3e4453f1, 0xbca2d3c3, 0x3e354cb9, 0xbf035be3, 0x3caa5ebc, 0x3f335ccf, 0x3f4e7331, 
    0xbe95fcf0, 0xbf1c4d0f, 0xbac73d0a, 0x3f10c0dc, 0x3e3f05a4, 0xbe808312, 0x3ea7a096, 0x3e72231e, 
    0x3ecfa9ca, 0x3ef4fdfa, 0x3ce82c6c, 0xbf0d2950, 0x3efb1453, 0x3e02c9c9, 0x3d28da12, 0x3f155f8b, 
    0x3eb4b459, 0xbe8c4345, 0x3ef41141, 0x3f13e509, 0xbe215977, 0xbe234edd, 0x3ed5063f, 0x3e77a9a6, 
    0x3dfb62c2, 0xbf3822b2, 0xbf0095ce, 0xbd23c1d0, 0x3f392106, 0x3ea643c0, 0xbe9ae832, 0x3d917115, 
    0x3d8fb76a, 0xbeca064f, 0x3e3864e4, 0x3f0fe627, 0x3f2aa7c8, 0x3f1a0175, 0xbd668dd8, 0x3e413015, 
    0xbf0c6f13, 0xbf2d2076, 0x3f22f5f2, 0xbe5a4b4b, 0x3f28b977, 0xbf0a5362, 0x3f045a6b, 0x3eab786f, 
    0x3ea1099f, 0x3e87825d, 0xbe843b31, 0xbeac902f, 0x3efa4143, 0x3c880d05, 0x3e3844e6, 0x3ec09e99, 
    0x3c8d7fb5, 0xbe9759af, 0xbe8bd344, 0x3eb61b42, 0xbe142591, 0xbf2f707a, 0x3f321038, 0x3f57069d, 
    0xbefe85af, 0x3e4cb75a, 0x3dbad5b8, 0x3ee2a4a1, 0x3e75f5a8, 0x3e0a3b8e, 0xbcf9cae6, 0x3f2729e6, 
    0xbe88b6b1, 0xbf1484e0, 0x3f0071d6, 0x3da810af, 0xbea20f01, 0xbea5fb88, 0xbf016e96, 0x3e88bc0b, 
    0x3d5b5336, 0xbeda038c, 0xbf1671e1, 0xbe06a459, 0x3f251c02, 0xbece93e1, 0x3e26eac9, 0x3bb53696, 
    0x3ec281e5, 0x3e1bfaa1, 0x3eda0405, 0xbefc36d8, 0x3eb49efa, 0x3eed480b, 0x3e2565ad, 0x3f07a8db, 
    0x3f1b0bc5, 0xbef94d87, 0x3df46040, 0xbf0dae37, 0xbef54b2e, 0x3de70fe3, 0x3db576b4, 0xbebb3ccb, 
    0x3e6b7621, 0x3e17a7ab, 0x3e54ec67, 0x3e429222, 0x3ba60f63, 0xbf0941b4, 0x3efc2475, 0x3eae9392, 
    0xbd89014a, 0x3ec48abe, 0x3da60b99, 0x3ee458d7, 0x3c5a530a, 0x3f0d160c, 0x3e9e1843, 0xbe97c842, 
    0x3d22d1df, 0x3f0157c3, 0x3eac36fc, 0x3e930806, 0x3ecca98b, 0x3e9c6b7a, 0xbd05197f, 0x3e6d3dee, 
    0xbc0358bc, 0xbf0dc69b, 0xbd814ccf, 0x3c2ebda3, 0x3ca4ff49, 0x3e8e7f1c, 0xbd668bb1, 0xbe0e3cc0, 
    0xbdda9b48, 0xbeb5a7b9, 0xbe1dca0b, 0xbea220b2, 0xbdce0ae5, 0xbec55dca, 0x3ea0b194, 0x3eb24528, 
    0x3f05b10e, 0x3e8fb3b9, 0xbe5f0857, 0xbe9fc721, 0xbe2d4cfa, 0xbeb793d7, 0x3eb6315a, 0x3ec43d89, 
    0xbe51799b, 0x3e0e6d7e, 0xbe9bb90f, 0xbd190445, 0x3dbd5430, 0x3e917d5e, 0x3e4dd486, 0xbef31680, 
    0x3eb207b8, 0xbeeee944, 0x3e6b2312, 0x3db4d9fd, 0xbf0633a1, 0xbd7915f0, 0xbd1174cf, 0xbdc83d57, 
    0xbea7e84b, 0x3ecb23d4, 0x3d92ad2d, 0x3eaef5e8, 0xbeb11af7, 0x3ea7654a, 0xbe06ae91, 0xbecbf024, 
    0xbd1f8602, 0xbe9b0825, 0xbebb28ca, 0x3ea8aec0, 0x3e61fb1b, 0xbe5dff18, 0x3dc4ec67, 0xbe85ed1d, 
    0x3ec3133e, 0x3e86bae5, 0xbeb38d41, 0xbe50db5c, 0x3e158723, 0x3ea8d3bc, 0xbef3bba6, 0x3dcd3aed, 
    0xbe445af7, 0x3e08e0bb, 0xbd03ffee, 0x3e3c3c18, 0x3e6d0aab, 0xbdfd7871, 0x3ec68d30, 0xbec3598f, 
    0x3e7b46dc, 0x3e6186b6, 0x3efff0ae, 0xbed0e073, 0x3d8bdaae, 0x3e4944a5, 0xbe0f53ff, 0x3d75c56f, 
    0x3ebd9c59, 0xbe8626d8, 0xbe94cfff, 0x3e96bf10, 0xbcd4b654, 0xbe8ae4d5, 0xbe5ffa0f, 0x3c9952f9, 
    0xbe23b45c, 0x3d9894b1, 0x3eb148d1, 0x3e9c5f69, 0xbb3b2092, 0x3eb4f0d5, 0x3e2ab154, 0x3d86362f, 
    0x3e5ac019, 0x3c6c8bef, 0xbe4f3a30, 0x3eb4a0fc, 0x3eaa40f5, 0xbe7f9b49, 0x3e321ee3, 0x3d94162c, 
    0x3e796f35, 0xbeaca403, 0xbedac8ef, 0xbce54d69, 0xbe99abb1, 0x3e96594b, 0xbd9358ff, 0xbe8f442c, 
    0xbe85996c, 0xbdf5f063, 0x3ecddfa4, 0x3e50adcb, 0xbddd1a0c, 0xbcde543d, 0xbeb1abb0, 0x3d1142cc, 
    0xbdacb4fe, 0xbecddb76, 0xbeca511f, 0xbef3bfa5, 0x3e5881ee, 0xbec111d8, 0x3cbecb10, 0xbcd7f1b6, 
    0xbd1fa9de, 0xbdfdfd1b, 0xbba74662, 0x3cde4cb8, 0xbe55ac28, 0x3e2e7c27, 0xbe04e77a, 0x3e42235a, 
    0xbda70650, 0xbe1e40d9, 0xbf080eb5, 0x3e0be3b2, 0xbdff03a9, 0xbeee0e4a, 0xbda3c39f, 0xbea46241, 
    0xbeadd11c, 0x3e15e84d, 0x3e181810, 0xbf10d232, 0xbdb734cc, 0x3e83c121, 0xbdb8c96b, 0x3e810cad, 
    0x3e63d49d, 0x3eba46fc, 0x3e976320, 0xbd818200, 0x3d03e210, 0xbac18b13, 0x3e7d184c, 0x3ef0af32, 
    0xbeb8feb9, 0xbc25031d, 0xbcd10a3b, 0xbde364c0, 0x3e9fa202, 0xbec812cd, 0xbe8ee532, 0xbedb1485, 
    0xbee18461, 0xbe6aaae2, 0x3e3690c6, 0xbe9b7894, 0x3ed6d761, 0xbe2d2387, 0x3e9f89a8, 0xbe4829ca, 
    0xbddd700c, 0xbde44026, 0x3e82889d, 0xbe5aa18e, 0xbecec300, 0xbedfaaea, 0xbdd2eb0c, 0xbeac4562, 
    0xbe3d2d64, 0x3e8af3ef, 0xbca26a3f, 0x3de46707, 0xbed0a686, 0x3d6a21af, 0x3cf40837, 0xbc48eb6c, 
    0x3eb8e1ee, 0x3d517f19, 0xbdd1d74b, 0xbdad9d1c, 0x3e55a3fc, 0xbeb04a85, 0x3d926a2f, 0x3d47c232, 
    0xbd8038ba, 0xbed58cd0, 0xbea12aa1, 0x3c7d6772, 0x3e0043b1, 0x3e93c867, 0x3ec5fb22, 0x3e70b40a, 
    0x3d903259, 0xbe01133b, 0xbe0913ba, 0x3ead09a3, 0x3d4816c6, 0x3e5ccae8, 0xbe39a993, 0x3ec9516d, 
    0xbb69e33a, 0xbe15e986, 0xbec45e4f, 0x3ea12c9b, 0x3da8f3c8, 0xbecba028, 0xbe40057b, 0x3e6189c1, 
    0x38567d43, 0x3e0931cf, 0xbe8be41e, 0xbea89fd9, 0x3be2d5ba, 0xbeb0475d, 0x3ea35470, 0x3c96b1c3, 
    0xbeb34b55, 0x3e6cd231, 0x3ea04aa7, 0xbe3f8c28, 0xbe31f348, 0x3e89c3db, 0xbdff881d, 0x3d3e219e, 
    0xbe81176d, 0xbd885e87, 0x3d0b6ec1, 0xbe92c07d, 0x3ee08eee, 0xbeb8cef8, 0xbebdd024, 0xbe8db717, 
    0xbeab59ce, 0x3dcdacce, 0x3d6542ec, 0x3da3a9c1, 0xbe17a8b4, 0xbdde923a, 0xbe82ec26, 0x3ed0b0a0, 
    0xbe3b2fda, 0x3e8114a9, 0xbdfa5b74, 0xbdeee43e, 0x3db11b8d, 0x3db67968, 0xbeb1d2a8, 0xbcad2ece, 
    0x3e0cfa87, 0x3e343e3a, 0xbc6e3d38, 0x3e2af09c, 0x3d4d5bcf, 0x3e8f5c62, 0x3da8b79f, 0x3c893fc6, 
    0x3c258cd0, 0xbe19e4c1, 0x3eb44ac1, 0x3e0da756, 0x3edec653, 0xbde3fe13, 0x3d8a168d, 0x3e2559d6, 
    0x3d9efd76, 0xbea9b0d9, 0xbdad6b5d, 0x3dfd9e8e, 0x3e8f4e8d, 0x3dc3dfbc, 0xbd1914ed, 0xbd83223b, 
    0xbe948c8a, 0x3e5a96bf, 0x3bc9797b, 0x3f0133be, 0x3eba50f8, 0x3e96f801, 0xbdcebe86, 0xbe7b24df, 
    0xbeadff1e, 0xbe63c5ad, 0xbda6974c, 0x3cd0a344, 0xbe84dc0a, 0xbe494c93, 0x3ea259fe, 0x3eacbe92, 
    0x3e9be0ba, 0x3c9f28b6, 0xbe3c824b, 0xbe341325, 0xbe8ca971, 0x3d77b93b, 0xbe3e8aa6, 0x3e940f9d, 
    0xbe4355da, 0x3ebcbc60, 0xbdc76e7e, 0x3ebd0dcf, 0x3d399b13, 0xbdf54e03, 0xbec12f87, 0x3ce34d0f, 
    0x3ec7bdde, 0xbe58b484, 0xbf04ea37, 0x3e6ee1bd, 0xbda01052, 0x3e765de0, 0xbe65da7b, 0xbed60e80, 
    0xbe9f742f, 0x3dcc2606, 0x3ee23397, 0xbd2418fc, 0x3e0ebc22, 0x3d41f983, 0x3e6d3466, 0xbdbb7899, 
    0xbedfe458, 0x3ebfb429, 0xbee59c68, 0xbe105007, 0xbecdfc3e, 0xbe9335f2, 0xbd8c1309, 0x3ee948e5, 
    0x3ec154ca, 0x3e872095, 0xbdb1fa85, 0x3f06e605, 0x3d0a8aef, 0x3ecb1404, 0x3dab3c65, 0xbe608918, 
    0x3d47ce03, 0x3cfe1b6a, 0xbdb030d2, 0x3e541876, 0x3dc11c0e, 0xbe6d3107, 0x3ec3c9bb, 0x3e3b28c4, 
    0xbe440678, 0x3ded1e81, 0xbe1cb806, 0x3eb88caa, 0xbf1b7ae1, 0xbf11cda0, 0x3e43b69c, 0x3ebb025a, 
    0xbec66fbc, 0xbe803baa, 0x3e4adad8, 0xbec5e312, 0x3ebd3ad1, 0x3e9774d5, 0xbe47b462, 0xbf0b3c84, 
    0x3edeba01, 0x3edd0683, 0x3e1a82be, 0x3e73c2bb, 0xbe1c1f54, 0x3e09240c, 0x3e0c1ea4, 0xbe6e9ecc, 
    0xbeae486e, 0xbee44a74, 0xbf1ef1fe, 0x3e9fa63b, 0xbf064da7, 0xbebc1419, 0xbe0aa501, 0xbe4aa37b, 
    0xbdc14f38, 0x3f1d2b1d, 0xbe237e5c, 0x3dc87a94, 0xbead4a9e, 0xbdefb62c, 0x3e077309, 0xbdeb7ba4, 
    0x3d79639c, 0xbee0cac2, 0x3c9653af, 0x3f1e89b4, 0xbede285e, 0xbee2274c, 0xbf4b2978, 0x3ebda74b, 
    0xbebe57e9, 0x3e32d4d9, 0x3e421552, 0xbeffda3a, 0x3ea76954, 0xbcac91db, 0xbf3a5050, 0xbdb11565, 
    0xbf14918a, 0xbe07e1de, 0x3e93b096, 0x3da00f61, 0xbdbc65cf, 0xbec296a4, 0x3e90caf8, 0x3ed2f5e9, 
    0x3ebb1ca7, 0x3ed804c3, 0x3f06c361, 0x3e7e9b51, 0xbbd2d075, 0xbec6e42f, 0x3ecb56c0, 0xbf0cf0ce, 
    0x3e7edd98, 0x3ec1970d, 0xbf335952, 0x3d30c228, 0xbf1dc110, 0xbcea8427, 0xbddd6329, 0x3e92a062, 
    0x3f0b1c62, 0x3e602d52, 0x3c96a283, 0xbf1448d2, 0xbe47c084, 0xbe7f7bd0, 0xbf0afa88, 0x3dc0eba1, 
    0xbe0c2363, 0x3e63e82b, 0xbf0d1e06, 0xbf016aa6, 0xbf15610a, 0xbe07357e, 0xbf19884a, 0xbefad656, 
    0xbe541f88, 0xbee9775f, 0x3f28f09e, 0x3f01cb10, 0xbd8488df, 0x3f0180aa, 0xbecbda5d, 0xbe233f5b, 
    0x3db38fcb, 0x3f4bf941, 0x3eede57b, 0x3db94075, 0xbf2a48ce, 0xbeffaaf4, 0x3e9d7b57, 0xbdd11c3c, 
    0xbd90673c, 0xbdafdb48, 0x3e92a6a9, 0x3f18b034, 0x3ec3c9fd, 0x3dba1fcb, 0xbf338dcb, 0xbebab9d8, 
    0x3ebd86dd, 0x3e80f66e, 0xbee55417, 0x3e223c5c, 0x3ea9a512, 0x3c66d1f5, 0xbefbbfc4, 0xbdfe8ad9, 
    0x3ef1c7f7, 0x3e9df4fa, 0x3e36a2bc, 0x3ee299be, 0xbe36b52e, 0x3eb5c191, 0x3f12a30c, 0x3ef7345a, 
    0x3eaa04f8, 0xbddeed4a, 0x3e8de073, 0xbee5e235, 0xbcce87bb, 0xbf011552, 0xbeb92778, 0x3e81db0c, 
    0xbec06f3d, 0xbe85d455, 0xbddad45f, 0xbe09158e, 0xbd3c1c2b, 0xbda32aff, 0xbf04994d, 0xbdf3e7b4, 
    0x3f04f19e, 0x3e0af01f, 0xbe323240, 0xbedbffd7, 0xbd86f178, 0x3d9ca173, 0xbe64dfb6, 0xbeb32a57, 
    0xbdb07d28, 0x3eaeff81, 0xbda55da3, 0xbe89975e, 0x3eeee5ac, 0x3ebb5779, 0xbe1ba1a9, 0x3ee5f42d, 
    0x3e8e0c9f, 0x3d95a76e, 0xbeff43c2, 0xbefba78b, 0x3eef63b7, 0xbe6eff1d, 0x3eebc698, 0xbeeac530, 
    0x3ead9e48, 0xbf02e2b1, 0x3f1ee40e, 0x3e965333, 0x3ea138ad, 0x3f209589, 0x3eab8dfb, 0x3eff035f, 
    0x3f04c311, 0xbed3113f, 0x3d880507, 0xbd43925b, 0x3ee3ce90, 0x3e7a9513, 0x3dbfe108, 0xbe8da750, 
    0x3eb7c7e8, 0x3e925df5, 0x3e3b243d, 0xbda7d112, 0xbc20b946, 0xbf02c109, 0x3d8f4223, 0x3e1e072a, 
    0xbe4b7c51, 0x3dbd3705, 0xbe9639dd, 0x3c1b403c, 0xbee0fa01, 0xbe839f1b, 0x3ef77476, 0xbe31a955, 
    0xbe0e06cc, 0xbdea6d63, 0x3d8a3a35, 0xbd10dcf8, 0x3e66c8d0, 0xbe3590c9, 0xbed753e6, 0xbe043708, 
    0xbee1fd8d, 0xbe6ec463, 0xbeb8ef82, 0x3e919b66, 0x3f176036, 0x3e68d25b, 0xbeb291fb, 0x3f073f15, 
    0xbe1e3bb4, 0x3f0c0f17, 0xbeab8da7, 0xbc4c1458, 0x3f086abe, 0xbefe8b67, 0xbeb464aa, 0xbe16df6d, 
    0xbf0fb719, 0xbde98236, 0xbd1999a9, 0x3f2af837, 0x3cf16ef3, 0x3f0dd867, 0x3e450096, 0xbe0c212d, 
    0xbf313255, 0xbd9ce7bb, 0x3df45cff, 0xbee37070, 0x3f18a2ce, 0x3f2d7dd3, 0xbe715861, 0x3f204e0d, 
    0x3f229106, 0x3eef04bd, 0xbe408d22, 0x3e6af744, 0xbf4522f4, 0xbd39d5b7, 0x3f04a4ac, 0xbf0c6dd2, 
    0x3df63cff, 0x3e8d73cc, 0xbea8f5d9, 0xbee2f92a, 0x3f441ccb, 0x3df55589, 0xbcc432c1, 0x3d2c4709, 
    0x3ec58754, 0x3f4c0080, 0xbd252003, 0x3e5323dd, 0x3f055411, 0xbe795b54, 0xbf0811a6, 0xbdbc931a, 
    0xbeb628f4, 0xbf0a980d, 0xbea3a3ac, 0x3c29300e, 0xbeabf290, 0x3f3288d3, 0xbf159e12, 0x3dc22e45, 
    0xbf1cf2df, 0xbedef0eb, 0x3e81e004, 0x3e97da94, 0xbec55c9d, 0x3ecb1541, 0x3eba7b28, 0xbf0e6362, 
    0xbec1a4ee, 0xbeec2434, 0xbf05004d, 0x3eba2d86, 0x3f5518ee, 0x3f0b2db4, 0x3f0bdfc2, 0xbcdd36d4, 
    0xbe052500, 0x3f2004ee, 0xbeaaff0a, 0x3f56a2ec, 0xbe07d487, 0xbef26c46, 0x3efa13e5, 0x3e7bcb5b, 
    0x3de589d5, 0x3e90983e, 0xbec79ed8, 0xbf02301a, 0x3f28a9eb, 0xbe8ff061, 0x3d72d0a1, 0xbefc8584, 
    0x3ed7d153, 0x3ead4d9e, 0xbe7ab9d5, 0x3e96976d, 0xbe755726, 0xbe7c53e0, 0x3e8f95fe, 0xbe2d3d81, 
    0xbe9df60f, 0xbea01e5a, 0xbd6d5c4d, 0xbed0f9d0, 0xbdeecd94, 0xbe99b943, 0x3e2ab0dc, 0xbe47ddda, 
    0xbe2f6e49, 0xbdeff929, 0xbdd8eb00, 0x3e447218, 0xbe44032a, 0xbecb18a6, 0xbe067a3d, 0x3e4fdf3a, 
    0x3ed03c28, 0xbecd3178, 0x3e623d29, 0xbe38dc45, 0x3e9ebd13, 0xbed1af3d, 0xbecc93cb, 0xbe84c027, 
    0xbe8994b5, 0xbddf5d9e, 0x3e9c3469, 0xbcd98fe0, 0xbdc293d9, 0xbe8dc95b, 0x3e87729d, 0x3e8dd6f6, 
    0xbdfb3fc0, 0xbe367ef4, 0xbee8d2ea, 0xbe8b3975, 0xbeb1d928, 0xbe88add1, 0xbefc02fd, 0xbeb9232f, 
    0xbe07ba26, 0x3d803c66, 0xbd9191d8, 0x3d9fcac5, 0xbb84d267, 0xbdac9436, 0x3a0be318, 0xbda374cd, 
    0x3ea2cae9, 0xbed65b97, 0x3d818145, 0xbdd4ec3a, 0x3dee07d1, 0x3e17c2b6, 0x3ce522c8, 0x3e2173e9, 
    0x3e2a7ae6, 0x3e9e26ab, 0xbe96682e, 0x3e6a1912, 0xbf033619, 0xbe21881e, 0xbe2d79c6, 0x3e62735e, 
    0x3e959b32, 0x3e5b940f, 0x3dc6a25b, 0xbebaee57, 0x3d87d252, 0xbeca4b71, 0x3d424ba2, 0xbd70db31, 
    0xbe5bca71, 0x3e513d99, 0xbe9b353c, 0xbeba3a46, 0x3ec9283b, 0x3d975e86, 0x3e92f559, 0xbeda9753, 
    0x3ebe5b33, 0x3eb8bb57, 0xbe405c77, 0x3d7b0005, 0x3dba377d, 0x3e1c3e56, 0xbea34850, 0xbdee05cd, 
    0x3d9add27, 0x3e436213, 0x3e7a6143, 0x3ea933a4, 0xbed9184b, 0xbdb19eff, 0xbe1847fc, 0x3e80a854, 
    0xbebafd13, 0xbe16ea62, 0xbf5ec43b, 0xbed70498, 0xbedf5a7b, 0x3e51b864, 0x3f0cb101, 0x3de61bfa, 
    0xbcc1c360, 0x3e200f89, 0xbe8e5f7a, 0xbf32b623, 0xbf408898, 0x3f106a07, 0x3eca3929, 0xbf4a0948, 
    0x3ee04596, 0x3d788441, 0x3f0d1215, 0xbf5e43a8, 0x3f606527, 0xbe00205b, 0x3e33f71c, 0x3c3281cc, 
    0xbe77a397, 0xbf836200, 0x3ec218eb, 0xbf14c706, 0xbdd6fd4b, 0xbf0a5373, 0xbeb296df, 0xbf14573c, 
    0xbea7f87d, 0xbeb54366, 0x3f1043df, 0x3d951949, 0x3eddc9bc, 0x3d848c8c, 0xbf49abec, 0x3f52964a, 
    0xbe51e815, 0xbe9e84e9, 0xbf074750, 0x3e8c4f10, 0xbe777e7b, 0x3ec4de1e, 0xbe501478, 0xbe5e1016, 
    0x3f88e61f, 0xbf2e41a9, 0xbf2fe519, 0xbde087d2, 0x3ec2e837, 0xbe32cd74, 0x3d902216, 0x3db6164c, 
    0xbe860f15, 0xbcc29d5b, 0x3f21977a, 0xbdf25d60, 0x3cb97bb9, 0xbedbe82e, 0xbe0c762f, 0xbeaf8c19, 
    0x3e973909, 0x3f9b59e5, 0xbf06dbd1, 0x3f3d9435, 0xbf145f88, 0xbded31f8, 0xbf833fba, 0xbf0ce1d7, 
    0xbd8f2a05, 0xbf59c160, 0x3f383989, 0x3ecb9d5f, 0x3e82a581, 0x3cc4e988, 0xbe57fe01, 0x3f0b72d7, 
    0x3efaa9af, 0xbeceb808, 0xbf09c4e0, 0xbf4d6c16, 0x3d994ad7, 0x3e3be605, 0xbd2f95bf, 0x3f40b1d6, 
    0x3f448bc3, 0xbe936ebe, 0x3ea1a5b1, 0xbf511c2b, 0x3f22fd14, 0x3f2a9dfa, 0xbed9adff, 0xbf2d0ae5, 
    0xbe184bd6, 0xbd930e1e, 0x3ea21617, 0x3f6ad1f1, 0xbeeab067, 0xbebdf37c, 0xbeb637bf, 0xbf0f1dd7, 
    0xbdc66dd7, 0x3f196c40, 0x3ee8fb5e, 0xbf2a0057, 0xbec5dfbe, 0x3f720e3d, 0xbe0c478c, 0xbf04942e, 
    0xbc9de61f, 0xbecd2214, 0x3e09dc15, 0xbe8dfd17, 0xbee07ad8, 0x3f645a0e, 0xbf408316, 0x3f800ac1, 
    0x3df3cee8, 0xbef3c6ce, 0xbed07136, 0xbf2b2f26, 0xbf340a44, 0xbf49a6d5, 0x3f0e8cba, 0xbd2b6ac0, 
    0x3e99b27f, 0x3eef60ae, 0x3f309f0b, 0x3e7a861b, 0xbe499c88, 0xbcdfd373, 0xbe6f6bb6, 0x3dfdaffc, 
    0xbf2c53c3, 0x3f00f08a, 0x3f3abbdb, 0x3f0bacd8, 0xbf344a5a, 0xbeaad22f, 0x3f0a7052, 0xbbffa2a7, 
    0xbf22b23b, 0xbf17a9f3, 0x3ebc747a, 0xbd986ebd, 0xbd89c255, 0x3e7b3904, 0xbef3bb96, 0xbe173a2f, 
    0xbdc5ac19, 0xbf0cfce7, 0x3f193c0f, 0xbef4efe7, 0x3ddc823e, 0xbe4dfff3, 0x3d9c962b, 0x3f1e71e8, 
    0x3ebe85ee, 0xbdbd6110, 0xbf0e7504, 0xbf24302f, 0xbe86679f, 0x3ef6aaea, 0xbd208683, 0xbce33e89, 
    0x3f0eb3e9, 0xbf2b1d78, 0x3f3b5489, 0x3e8cd7b2, 0x3e7b507b, 0xbe5a4955, 0x3f4ed68d, 0x3f5c5e51, 
    0xbead0b65, 0xbf0f3e43, 0x3ea0339d, 0xbef7f9d9, 0x3f3b95dc, 0xbe89eefd, 0x3d436657, 0xbf11b227, 
    0x3e08253a, 0x3f39b7d1, 0xbefb706c, 0xbe4064ed, 0xbe072a22, 0x3f101de6, 0x3ee78038, 0x3da8a709, 
    0x3e83e462, 0xbeb8e783, 0x3ee291ae, 0xbe848fff, 0x3e972f04, 0xbe8d2199, 0xbe9b89a3, 0x3dd36129, 
    0xbeafa054, 0x3ed0270c, 0x3ecb2f5e, 0x3e3b58d5, 0x3e043c59, 0x3e90027c, 0x3ef0d9ba, 0x3ca6d5fa, 
    0x3e9fd5fe, 0x3e8e3d82, 0xbf2563f9, 0xbf01190d, 0xbf07f67f, 0xbf0befe9, 0xbeb49e85, 0xbe834268, 
    0xbf2555e2, 0xbf00b24c, 0x3ec72dcb, 0x3eaa189e, 0x3dddae73, 0xbe8e02f6, 0x3ec1534b, 0xbe0f1e60, 
    0x3ec6a561, 0x3eaddda5, 0xbdffbe5f, 0x3efc6bde, 0xbe94c79b, 0x3f04450a, 0xbe853c3f, 0xbe26da07, 
    0x3e228b17, 0xbeb25869, 0xbf01d00d, 0xbe0ebad8, 0x3e3e648c, 0xbcc28569, 0xbeea2761, 0xbf189e3d, 
    0xbe9d7b52, 0xbe9335ea, 0x3d353f5a, 0x3ef7c985, 0xbea931d2, 0x3efbfd2a, 0xbe795bb5, 0xbdbc4f08, 
    0xbec1d2a1, 0xbe265552, 0x3ebad90f, 0xbd542806, 0x3e5fe527, 0xbead9474, 0x3ef5567c, 0x3e46390b, 
    0x3ea58ac8, 0xbac7d61d, 0xbf1fb493, 0x3eb20b3d, 0xbe345b3b, 0xbeb6bac4, 0x3e94308f, 0xbedb08f5, 
    0xbe018400, 0xbf008cdd, 0xbecb627a, 0xbebc9216, 0x3f119bf0, 0x3ec64677, 0x3ec5497f, 0x3dd35a56, 
    0xbef25ee7, 0x3eaa9481, 0x3e8f100a, 0x3ec43c40, 0x3e404777, 0xbe84a406, 0xbe9a9d23, 0xbf00d5f7, 
    0xbe8bfde2, 0x3d53fdc3, 0xbdb34c56, 0xfffffe86, 0x00000004, 0x00000040, 0xbe9ead6e, 0x3df85c7c, 
    0xbf8be276, 0xbf1796c4, 0xbf449446, 0xbec19b1f, 0x3fc88f8a, 0xbf0d7379, 0xbec3adef, 0xbf26fe15, 
    0x3cd10754, 0x3eb51e26, 0xbf24746b, 0x3f6ab951, 0x3f84baa1, 0x3fb23e9e, 0xfffffed2, 0x00000004, 
    0x00000080, 0x3f5a2485, 0x3db68db0, 0xbe843001, 0xbdb5f3af, 0x3df7f034, 0xbf97a46c, 0xbed392c3, 
    0xbebaecd7, 0xbd2a0471, 0x3f83e32f, 0xbf76daa5, 0x3ed3e5cc, 0xbf848eca, 0xbe0e5d73, 0x3f43d1e7, 
    0xbf936650, 0x3f454f23, 0xbece2f42, 0x3e06dd22, 0xbfffd53c, 0xbfd24145, 0x3e20d60b, 0x3febd91e, 
    0x3e4d42ee, 0x3f18bfd6, 0x3fc210cf, 0xbf712bb0, 0xbe8e1340, 0x3f972f99, 0x3eeb5d27, 0xbee58034, 
    0x3dccc5f1, 0xfffff1fc, 0xfffff200, 0x0000000f, 0x52494c4d, 0x6e6f4320, 0x74726576, 0x002e6465, 
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
    0x622d6c6c, 0x6e616c61, 0x2d646563, 0x616c2f32, 0x5f726579, 0x4d2f3231, 0x754d7461, 0x6f6d3b6c, 
    0x2f6c6564, 0x766e6f63, 0x732d6431, 0x6c6c616d, 0x6c61622d, 0x65636e61, 0x2f322d64, 0x6579616c, 
    0x32315f72, 0x6169422f, 0x64644173, 0x00000000, 0x00000002, 0x00000001, 0x00000005, 0xfffff682, 
    0x01000000, 0x00000010, 0x00000010, 0x00000018, 0x00000038, 0xfffff66c, 0x0000002b, 0x65646f6d, 
    0x6f632f6c, 0x6431766e, 0x616d732d, 0x622d6c6c, 0x6e616c61, 0x2d646563, 0x616c2f32, 0x5f726579, 
    0x4d2f3131, 0x006e6165, 0x00000002, 0x00000001, 0x00000020, 0xfffff6da, 0x01000000, 0x00000010, 
    0x00000010, 0x00000017, 0x0000003c, 0xfffff6c4, 0x0000002d, 0x65646f6d, 0x6f632f6c, 0x6431766e, 
    0x616d732d, 0x622d6c6c, 0x6e616c61, 0x2d646563, 0x616c2f32, 0x5f726579, 0x71532f39, 0x7a656575, 
    0x00000065, 0x00000003, 0x00000001, 0x00000006, 0x00000020, 0xfffff73a, 0x01000000, 0x00000010, 
    0x00000010, 0x00000016, 0x0000003c, 0xfffff724, 0x0000002d, 0x65646f6d, 0x6f632f6c, 0x6431766e, 
    0x616d732d, 0x622d6c6c, 0x6e616c61, 0x2d646563, 0x616c2f32, 0x5f726579, 0x614d2f39, 0x6f6f5078, 
    0x0000006c, 0x00000004, 0x00000001, 0x00000006, 0x00000001, 0x00000020, 0xfffff79e, 0x01000000, 
    0x00000010, 0x00000010, 0x00000015, 0x00000040, 0xfffff788, 0x00000030, 0x65646f6d, 0x6f632f6c, 
    0x6431766e, 0x616d732d, 0x622d6c6c, 0x6e616c61, 0x2d646563, 0x616c2f32, 0x5f726579, 0x78452f39, 
    0x646e6170, 0x736d6944, 0x00000000, 0x00000004, 0x00000001, 0x0000000c, 0x00000001, 0x00000020, 
    0xfffff806, 0x01000000, 0x00000010, 0x00000010, 0x00000014, 0x00000108, 0xfffff7f0, 0x000000f9, 
    0x65646f6d, 0x6f632f6c, 0x6431766e, 0x616d732d, 0x622d6c6c, 0x6e616c61, 0x2d646563, 0x616c2f32, 
    0x5f726579, 0x65522f38, 0x6d3b756c, 0x6c65646f, 0x6e6f632f, 0x2d643176, 0x6c616d73, 0x61622d6c, 
    0x636e616c, 0x322d6465, 0x79616c2f, 0x375f7265, 0x7461622f, 0x6f6e6863, 0x612f6d72, 0x315f6464, 
    0x646f6d3b, 0x632f6c65, 0x31766e6f, 0x6d732d64, 0x2d6c6c61, 0x616c6162, 0x6465636e, 0x6c2f322d, 
    0x72657961, 0x432f365f, 0x31766e6f, 0x71532f44, 0x7a656575, 0x6f6d3b65, 0x2f6c6564, 0x766e6f63, 
    0x732d6431, 0x6c6c616d, 0x6c61622d, 0x65636e61, 0x2f322d64, 0x6579616c, 0x2f375f72, 0x63746162, 
    0x726f6e68, 0x756d2f6d, 0x3b315f6c, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 0x6d732d64, 0x2d6c6c61, 
    0x616c6162, 0x6465636e, 0x6c2f322d, 0x72657961, 0x432f365f, 0x31766e6f, 0x00000044, 0x00000004, 
    0x00000001, 0x00000001, 0x0000000c, 0x00000020, 0xfffff936, 0x01000000, 0x00000010, 0x00000010, 
    0x00000013, 0x0000009c, 0xfffff920, 0x0000008c, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x616d732d, 
    0x622d6c6c, 0x6e616c61, 0x2d646563, 0x616c2f32, 0x5f726579, 0x65522f35, 0x6d3b756c, 0x6c65646f, 
    0x6e6f632f, 0x2d643176, 0x6c616d73, 0x61622d6c, 0x636e616c, 0x322d6465, 0x79616c2f, 0x345f7265, 
    0x6e6f432f, 0x2f443176, 0x65757153, 0x3b657a65, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x616d732d, 
    0x622d6c6c, 0x6e616c61, 0x2d646563, 0x616c2f32, 0x5f726579, 0x6f432f34, 0x4431766e, 0x00000000, 
    0x00000004, 0x00000001, 0x00000001, 0x0000000c, 0x00000020, 0xfffff9fa, 0x01000000, 0x00000010, 
    0x00000010, 0x00000012, 0x00000108, 0xfffff9e4, 0x000000f9, 0x65646f6d, 0x6f632f6c, 0x6431766e, 
    0x616d732d, 0x622d6c6c, 0x6e616c61, 0x2d646563, 0x616c2f32, 0x5f726579, 0x65522f33, 0x6d3b756c, 
    0x6c65646f, 0x6e6f632f, 0x2d643176, 0x6c616d73, 0x61622d6c, 0x636e616c, 0x322d6465, 0x79616c2f, 
    0x325f7265, 0x7461622f, 0x6f6e6863, 0x612f6d72, 0x315f6464, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 
    0x6d732d64, 0x2d6c6c61, 0x616c6162, 0x6465636e, 0x6c2f322d, 0x72657961, 0x432f315f, 0x31766e6f, 
    0x71532f44, 0x7a656575, 0x6f6d3b65, 0x2f6c6564, 0x766e6f63, 0x732d6431, 0x6c6c616d, 0x6c61622d, 
    0x65636e61, 0x2f322d64, 0x6579616c, 0x2f325f72, 0x63746162, 0x726f6e68, 0x756d2f6d, 0x3b315f6c, 
    0x646f6d3b, 0x632f6c65, 0x31766e6f, 0x6d732d64, 0x2d6c6c61, 0x616c6162, 0x6465636e, 0x6c2f322d, 
    0x72657961, 0x432f315f, 0x31766e6f, 0x00000044, 0x00000004, 0x00000001, 0x00000001, 0x0000000c, 
    0x00000010, 0xfffffb2a, 0x01000000, 0x00000010, 0x00000010, 0x00000011, 0x000000a0, 0xfffffb14, 
    0x00000090, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x616d732d, 0x622d6c6c, 0x6e616c61, 0x2d646563, 
    0x616c2f32, 0x5f726579, 0x69422f30, 0x64417361, 0x6f6d3b64, 0x2f6c6564, 0x766e6f63, 0x732d6431, 
    0x6c6c616d, 0x6c61622d, 0x65636e61, 0x2f322d64, 0x6579616c, 0x2f305f72, 0x766e6f43, 0x532f4431, 
    0x65657571, 0x3b3b657a, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x616d732d, 0x622d6c6c, 0x6e616c61, 
    0x2d646563, 0x616c2f32, 0x5f726579, 0x6f432f30, 0x4431766e, 0x00000000, 0x00000004, 0x00000001, 
    0x00000001, 0x00000018, 0x0000000d, 0xfffffbf2, 0x01000000, 0x00000010, 0x00000010, 0x00000010, 
    0x00000048, 0xfffffbdc, 0x00000038, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x616d732d, 0x622d6c6c, 
    0x6e616c61, 0x2d646563, 0x616c2f32, 0x5f726579, 0x6f432f30, 0x4431766e, 0x7078452f, 0x44646e61, 
    0x31736d69, 0x00000000, 0x00000004, 0x00000001, 0x00000001, 0x00000032, 0x0000001e, 0xfffffde6, 
    0x01000000, 0x00000014, 0x00000014, 0x0000000f, 0x02000000, 0x00000044, 0xfffffc50, 0x00000037, 
    0x65646f6d, 0x6f632f6c, 0x6431766e, 0x616d732d, 0x622d6c6c, 0x6e616c61, 0x2d646563, 0x616c2f32, 
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
    0x0037746e, 0x00000004, 0x00000020, 0x00000001, 0x00000003, 0x00000010, 0xffffffc2, 0x01000000, 
    0x00000014, 0x00000014, 0x00000008, 0x02000000, 0x0000001c, 0xfffffe2c, 0x0000000f, 0x74697261, 
    0x6f632e68, 0x6174736e, 0x0036746e, 0x00000001, 0x00000004, 0x00160000, 0x0018001c, 0x00100017, 
    0x0008000c, 0x00000000, 0x00070000, 0x00000016, 0x01000000, 0x00000014, 0x00000014, 0x00000007, 
    0x02000000, 0x0000001c, 0xfffffe80, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0035746e, 
    0x00000001, 0x00000003, 0xfffffece, 0x01000000, 0x00000010, 0x00000010, 0x00000006, 0x0000001c, 
    0xfffffeb8, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0034746e, 0x00000001, 0x0000000d, 
    0xffffff06, 0x01000000, 0x00000010, 0x00000010, 0x00000005, 0x0000001c, 0xfffffef0, 0x0000000f, 
    0x74697261, 0x6f632e68, 0x6174736e, 0x0033746e, 0x00000004, 0x00000010, 0x00000001, 0x00000003, 
    0x0000000d, 0xffffff4a, 0x01000000, 0x00000010, 0x00000010, 0x00000004, 0x0000001c, 0xffffff34, 
    0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0032746e, 0x00000004, 0x00000020, 0x00000001, 
    0x00000003, 0x00000020, 0xffffff8e, 0x01000000, 0x00000010, 0x00000010, 0x00000003, 0x0000001c, 
    0xffffff78, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0031746e, 0x00000001, 0x00000010, 
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
#define _K7              ((uint8_t *)_k7)                    // u8[31184] (31184 bytes)
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
    __RETURN_ERROR(mtb_init(_K10, _K7, 31184, _K6, 16384, 3, "network_float"));
    return 0;
}

static IMAI_api_def _IMAI_api_def = {
    .api_ver = 1,
    .id = {0xdc, 0x21, 0x42, 0x81, 0x4b, 0x7c, 0x16, 0x4d, 0xad, 0xec, 0x7b, 0x23, 0xbe, 0xde, 0x25, 0x93},
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
        .size = 33296,
        .peak_usage = 33296,
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

