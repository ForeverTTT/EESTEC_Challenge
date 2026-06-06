/*
* ImagiNet Compiler 5.12.5418.0+7793ebcc9f383586f202c2d2f6eafbd7ebe6519d
* Copyright © 2023- Imagimob AB, All Rights Reserved.
* 
* Generated at 06/06/2026 15:05:41 UTC. Any changes will be lost.
* 
* Model ID  212e298b-7862-4ecb-905c-63d72e60451c
* 
* Memory    Size                      Efficiency
* Buffers   10256 bytes (RAM)         80 %
* State     25992 bytes (RAM)         100 %
* Readonly  48012 bytes (Flash)       100 %
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
    0x0000001c, 0x00000090, 0x000000e8, 0x00009e68, 0x00009e78, 0x0000b2a8, 0x00000003, 0x00000001, 
    0x00000010, 0x000a0000, 0x000c0010, 0x00040008, 0x0000000a, 0x0000000c, 0x0000001c, 0x0000003c, 
    0x0000000f, 0x76726573, 0x5f676e69, 0x61666564, 0x00746c75, 0x00000001, 0x00000004, 0xffffff98, 
    0x00000024, 0x00000004, 0x00000008, 0x6579616c, 0x30325f72, 0x00000000, 0x00000001, 0x00000004, 
    0xffff615e, 0x00000004, 0x00000007, 0x6579616c, 0x00305f72, 0x00000002, 0x00000034, 0x00000004, 
    0xffffffdc, 0x00000027, 0x00000004, 0x00000013, 0x564e4f43, 0x49535245, 0x4d5f4e4f, 0x44415445, 
    0x00415441, 0x000c0008, 0x00040008, 0x00000008, 0x00000026, 0x00000004, 0x00000013, 0x5f6e696d, 
    0x746e7572, 0x5f656d69, 0x73726576, 0x006e6f69, 0x00000028, 0x00009d7c, 0x00009d74, 0x00009ce4, 
    0x00009c74, 0x00009c34, 0x00006c24, 0x00005114, 0x000049b4, 0x00004970, 0x00004954, 0x00004934, 
    0x00004914, 0x000048f4, 0x000024e4, 0x00002454, 0x000016c4, 0x00001654, 0x000003fc, 0x0000016c, 
    0x00000148, 0x00000134, 0x00000114, 0x0000010c, 0x00000104, 0x000000fc, 0x000000f4, 0x000000ec, 
    0x000000e4, 0x000000dc, 0x000000d4, 0x000000cc, 0x000000c4, 0x000000bc, 0x000000b4, 0x000000ac, 
    0x000000a4, 0x0000009c, 0x00000094, 0x00000074, 0x00000004, 0xffff6272, 0x00000004, 0x00000060, 
    0x00000010, 0x00000000, 0x000e0008, 0x00040008, 0x00000008, 0x00000010, 0x00000024, 0x00060000, 
    0x00040008, 0x00000006, 0x00000004, 0x00000000, 0x0018000c, 0x00100014, 0x0004000c, 0x0000000c, 
    0x556d7f89, 0xd514cb7e, 0x00000003, 0x00000002, 0x00000004, 0x00000006, 0x39312e32, 0x0000302e, 
    0xffff62de, 0x00000004, 0x00000010, 0x2e362e31, 0x00000030, 0x00000000, 0x00000000, 0xffff4f98, 
    0xffff4f9c, 0xffff4fa0, 0xffff4fa4, 0xffff4fa8, 0xffff4fac, 0xffff4fb0, 0xffff4fb4, 0xffff4fb8, 
    0xffff4fbc, 0xffff4fc0, 0xffff4fc4, 0xffff4fc8, 0xffff4fcc, 0xffff4fd0, 0xffff4fd4, 0xffff633a, 
    0x00000004, 0x00000010, 0x00000001, 0x00000001, 0x00000032, 0x0000001e, 0xffff6356, 0x00000004, 
    0x00000004, 0x00000001, 0xffff6366, 0x00000004, 0x00000014, 0xbd368873, 0x3ca2723c, 0x3c2b5a61, 
    0x3bc3541e, 0x3c64ae8c, 0xffff6386, 0x00000004, 0x00000280, 0x3d255339, 0xbd1e470f, 0x3eab3841, 
    0xbe17bf1f, 0xbe36909c, 0xbe2bfca0, 0x3dd8bcf6, 0x3e4d18aa, 0x3e954001, 0xbeb6ad6f, 0xbe8aefa8, 
    0x3e51b014, 0xbea240d7, 0xbe995a69, 0xbeaaca8a, 0xbecc67fe, 0xbedf401b, 0x3e89042b, 0x3ddfcaf0, 
    0xbbe5222a, 0xbe850447, 0x3df98896, 0x3e8f02ee, 0x3eb0430c, 0xbd16ad05, 0x3eba68c2, 0x3da678cf, 
    0xbeae7445, 0xbdd71c4a, 0xbe9b18e1, 0xbe35cab6, 0x3e03b8dc, 0x3e9d76a0, 0x3d3c31b0, 0x3c2ada28, 
    0x3eb55ccd, 0x3ed8e3db, 0xbbb18355, 0x3eb2a1ea, 0xbeb2c25e, 0xbc0fe3cb, 0xbebc01c8, 0xbeb18ee3, 
    0x3eadd91f, 0xbe60830e, 0xbe805001, 0xbd126fa2, 0xbedbfce3, 0xbe93e769, 0xbe32eea2, 0x3b8b151d, 
    0xbe660c54, 0xbd9308e1, 0x3e921349, 0xbea30dc7, 0x3e23f6af, 0x3e786b6f, 0xbdd9ab97, 0x3dfe0261, 
    0x3e5cef3f, 0x3eba6237, 0x3d84ddbb, 0x3ecbe298, 0xbe534100, 0xbe844d23, 0xbd35228b, 0x3e6e12ab, 
    0x3ec76035, 0xba5fdb4b, 0x3e8b1047, 0xbc07ba70, 0xbe5784fc, 0x3e1f7408, 0x3ea4539c, 0x3ec412d2, 
    0xbec7c436, 0x3e9ba8ad, 0x3e947266, 0xbe343e04, 0x3e54853c, 0xbeafee0f, 0xbebd6c00, 0x3e4585b4, 
    0x3e849afc, 0xbecd4321, 0x3ea26b1c, 0xbec04f63, 0xbe3b4f64, 0xbe148d42, 0xbd756e48, 0x3d46d85c, 
    0x3e682729, 0xbe8a7da9, 0x3e83ebb8, 0xbe69277f, 0x3c22d5e1, 0x3ecb4331, 0xbd216f5e, 0xbc68a5fc, 
    0xbe4133d0, 0xbeb654bc, 0x3eb6ef53, 0xbe679327, 0xbd30b03c, 0xbe9e21ab, 0xbebc13c7, 0x3ea20188, 
    0x3eaf1331, 0xbe807200, 0xbdc6d1eb, 0xbe9a9558, 0x3db5170d, 0xbda38f96, 0x3e9cf9f0, 0xbe9f1f9b, 
    0x3e8bfded, 0xbded9094, 0xbecdc603, 0x3e87f6c5, 0xbd9f9c99, 0x3e81afe1, 0x3ec4d885, 0xbe38a5ff, 
    0xbeb0f09b, 0x3e80314f, 0xbe890ce8, 0x3e0161e8, 0x3e287522, 0xbeb4ee4f, 0x3d64cb24, 0x3e7f60d8, 
    0xbe711752, 0xbe20a9bb, 0xbe5d2504, 0xbe17ed67, 0xbdc7953b, 0x3e1c3b9e, 0x3dad13c5, 0x3e07bcae, 
    0xbe991c04, 0x3e647971, 0x3e51449b, 0x3caf7844, 0xbe9d9ce8, 0xbe9c01ae, 0xbc7d9c31, 0xbdcc3e98, 
    0x3e1c5dbb, 0x3e9d9b1e, 0x3e0f12ff, 0x3dad189a, 0x3e560100, 0x3e9dd6a9, 0x3eca6fb2, 0x3e88a138, 
    0xbcbc3a83, 0xbec4c623, 0xbea7eb10, 0xbead5d55, 0x3e96233b, 0xffff6612, 0x00000004, 0x00001248, 
    0xbdb1869b, 0x3e36df3a, 0xbdf2dd03, 0x3de15a88, 0xbcf0cbcb, 0xbd36a46d, 0xbbd9c756, 0xbe362c3e, 
    0xbd5e26e3, 0xbe2d87b2, 0xbe3a113e, 0x3d93054e, 0xbd8d624e, 0xbdc762da, 0x3d95e604, 0xbcd251fc, 
    0x3e4a7c08, 0xbe41a60a, 0x3dd9c71c, 0xbe2478c3, 0x3e630e39, 0x3e1bb9f4, 0x3dfb79bb, 0x3d7beb14, 
    0xbd2e7e88, 0xbe216388, 0xbaa4dcb7, 0x3e30cfca, 0x3ce94759, 0x3d1bc164, 0x3cabb393, 0x3e3197fc, 
    0xbddc96a8, 0x3e363108, 0x3de47321, 0xbd132266, 0xbd94c610, 0xbc327bf4, 0x3e383aa5, 0x3b80a1fb, 
    0x3d3fe27f, 0xbceabb94, 0xbde50db8, 0x3da7f287, 0xbdf21bcb, 0xbddfaba7, 0x3d9ea32f, 0xbe299920, 
    0x3e2619df, 0x3e44e5b4, 0x3e5f5f98, 0x3dcbd2b8, 0x3c027d41, 0xbe129be6, 0xbb310b49, 0xbe1986fc, 
    0x3e28452b, 0x3d6c2d4d, 0xbd08b16c, 0x3e3c57c7, 0x3e1c44f4, 0xbd74f216, 0xbe355d0d, 0xbd9faf9b, 
    0xbd3aa4d4, 0x3d777af8, 0xbd285dbb, 0x3c6de80a, 0xbe1f3700, 0xbe3fd049, 0x3d9be6a3, 0x3d01fdd8, 
    0xbe1a87cf, 0x3db401a5, 0x3ad0ff5e, 0x3e3d4d27, 0x3dabe6e9, 0xbe3f994e, 0x3db20dd7, 0xbd0daf68, 
    0xbe041c10, 0x3d090099, 0xbd8f55a1, 0xbe18e3ef, 0x3e5224ec, 0xbc1e210e, 0x3d526460, 0xbd9e2c9a, 
    0x3e088496, 0x3e4242c8, 0x3de4d256, 0xbdf5e379, 0xbe5bbf40, 0xbd5f0f44, 0x3dfcab89, 0x3d05384b, 
    0xbe7b0276, 0xbe4ed2eb, 0x3e2629cf, 0x3d8ecf66, 0x3e358407, 0xbe3bbbe9, 0x3e0e2d33, 0x3b7aee14, 
    0x3d862337, 0x3e16fd56, 0xbe4dfbc2, 0xbc920115, 0xbe1cb64b, 0x3e425f2a, 0x3e055774, 0xbdc3755f, 
    0xbe01b77f, 0xbe1f617a, 0x3e1f8d7d, 0xbd0219d9, 0xbe3a474d, 0x3de5ecd5, 0xbd8e2e57, 0x3e4624f3, 
    0xbdef9441, 0xbd83dfc8, 0xbe383d1e, 0x3d84d7ae, 0xbbc47a4a, 0x3e33d29a, 0xbba44fa2, 0x3d1738c5, 
    0x3dfeddaf, 0xbe197a01, 0x3d664824, 0x3c3c3794, 0x3e289de1, 0x3df27a51, 0x3e20b5a7, 0x3e2f08e7, 
    0x3dde2b86, 0x3da2860f, 0xbdde73ce, 0x3e300733, 0xbc501abd, 0xbda782e2, 0x3d96b473, 0x3d6971e2, 
    0x3b16015d, 0xbd016040, 0xbd6192b2, 0x3e33291d, 0x3d947bd2, 0xbd754c5e, 0xbd9c6879, 0xbdbcafaf, 
    0x3d2db57c, 0x3dd2894d, 0x3dd19f02, 0x3e3df819, 0xbe75fe7a, 0xbda6d745, 0xbdeb820b, 0x3c045fd4, 
    0x3e2ae2f4, 0xbdb44a25, 0x3c23fed3, 0xbdd33130, 0x3d02174d, 0xbcdd70c2, 0x3e232f6c, 0xbe001d71, 
    0xbb5a8f0f, 0xbbe37a82, 0x3d19d5d6, 0xbd6784cb, 0x3d895782, 0xbd843088, 0xbe0a8027, 0xbdcd425c, 
    0xbd05c5f2, 0xbe68e13b, 0xbd2018f5, 0xbe35605f, 0xbd9cfb2a, 0x3c5000c7, 0x3bfba4ba, 0xbd759715, 
    0xbdbac4af, 0xbe359420, 0xbcc09076, 0xbe3f6b8d, 0xbda0599f, 0x3e0f8e09, 0x3e25ace0, 0xbd2a346a, 
    0xbd7be0c2, 0x3e3d63bb, 0x3d8cc4a6, 0xbdc55b5a, 0x3d9da363, 0xbe200e3b, 0x3dd45161, 0x3dadad81, 
    0xbe4b8a76, 0xbcbfe04d, 0x3dcc73de, 0x3ddbd891, 0x3e61377f, 0xbe16b4df, 0x3e18bf51, 0x3c1e63f8, 
    0x3e011292, 0xbdcae310, 0xbd639dc2, 0x3d55339d, 0xbdfa0a30, 0x3deed172, 0xbd5ff753, 0xbabf7722, 
    0x3e16279b, 0xbd25bf38, 0xbe4c3f1c, 0x3dd85ed9, 0xbdf6ffcf, 0xbdf31896, 0xbe0d99a3, 0x3e10328c, 
    0xbcf894f5, 0xbda6969d, 0x3d344679, 0xbd15d138, 0x3b227ec5, 0x3e0bc01c, 0x3e43261a, 0x3daeb16d, 
    0xbe1c3960, 0xbe481c11, 0x3dcd9559, 0x3dc26d41, 0xbdb55a5a, 0xbcaa753f, 0xbd8632f6, 0xbe2a2ab1, 
    0x3d27478c, 0x3d031613, 0x3dbeb364, 0xbdac18bd, 0x3e5aa143, 0x3e1c132e, 0xbe532ded, 0xbddafab3, 
    0xbe551f49, 0x3db63b2e, 0xbe4bbd81, 0x3e418058, 0xbe6a008b, 0xbd919302, 0xbe124152, 0x3e47ae9f, 
    0xbd7540e8, 0xbd9cad91, 0x3e24d024, 0x3e1c6c1c, 0xbe3c3165, 0xbcd72b0c, 0x3e6042b0, 0xbe595528, 
    0x3e3716ae, 0x3e5534d7, 0x3de85b98, 0x3dd565e4, 0x3e07fb00, 0xbd2cd07e, 0xbd10cebd, 0xbe064554, 
    0xbdd0b1eb, 0xbe2e6a87, 0xbc264f07, 0x3b9d6466, 0x39a55b1e, 0xbe295a94, 0x3e0d28c4, 0x3da93130, 
    0xbcd73c53, 0x3c034b64, 0xbe2afca9, 0x3e5ddb99, 0x3cdb8ef7, 0x3de2dc6f, 0x3ce38ae4, 0x3cd26a77, 
    0x3e3417ab, 0x3da8099d, 0x3e43643e, 0x3d5f2f81, 0x3c9c5a03, 0x3e4a07a1, 0xbd8f7621, 0xbd2f5671, 
    0xbdd46ae4, 0xbd0c8605, 0x3e3ad539, 0xbe1b853a, 0x3e49ab24, 0x3e31bad2, 0x3d805d76, 0x3e12c0aa, 
    0xbe1db543, 0xbdd1745e, 0x3db40d96, 0x3de67c56, 0xbb13b1d2, 0xbe42cfa3, 0x3d9c9004, 0xbdc2c1d1, 
    0x3d95ed15, 0x3cd72c2c, 0x3d7a3ac0, 0xbdae611a, 0xbd9a0544, 0x3bce3822, 0xbc15c0ee, 0xbe129fdf, 
    0xbe006170, 0x3d22e14a, 0x3d83073a, 0xbe34f738, 0x3c045d6e, 0xbda23279, 0x3b40cdcc, 0xbe45930a, 
    0xbdafc33d, 0xbd1d044f, 0x3ccf6129, 0xbd6be925, 0x3d37f386, 0xbe42c0b5, 0xbb351889, 0xbe53b542, 
    0xbd1874a7, 0x3e0ef6a6, 0xbddd7108, 0x3df94c81, 0x3dcb1a8d, 0x3d0c616f, 0xbdfc4111, 0x3d88ce2f, 
    0xbe2cc01b, 0x3e559b1c, 0xbdd56b9d, 0x3e37998c, 0x3d5cd9d5, 0xbe2be57b, 0x3df90215, 0x3d20b0a6, 
    0xbda107fe, 0x3ddb408d, 0x3e66a5cd, 0x3e1b7f7a, 0xbe1249f0, 0x3e35b3ff, 0xbe54c0fc, 0xbdd4ec55, 
    0x3db6c61b, 0xbdfdd247, 0x3cd95a69, 0xbe2edd0d, 0xbdb8c200, 0x3e374467, 0x3e5faec8, 0xbca16c6a, 
    0x3e4ce31b, 0xbd674315, 0xbe2b2bb7, 0xbe0728ab, 0xbdeeafee, 0xbe2570a2, 0xbd6f80fc, 0x3e51e590, 
    0xbd43b50a, 0xbd1e11b2, 0xbde0b89b, 0xbd785adb, 0x3d711830, 0xbde306db, 0xbdeae055, 0xbe382a9a, 
    0x3df03cb6, 0x3e0d6a09, 0xbdc16071, 0xbcbefc5d, 0x3da7e763, 0x3de95564, 0xbce770b8, 0xbd1661fa, 
    0x3db210da, 0xbe50d319, 0x3e3958a6, 0xbd57c9ed, 0xbc48bc8a, 0xbd00b181, 0xbe183b45, 0xbe489183, 
    0x3d8d484b, 0x3d975acc, 0x3c89e0df, 0x3e45b181, 0x3dd716c4, 0xbd304efe, 0x3e2ce738, 0x3c890381, 
    0xbb83936a, 0x3cc4ee29, 0x3e373f6c, 0x3e0cd5e4, 0x3e2de0d0, 0x3d840f1f, 0xbdc52c11, 0x3d86ee76, 
    0xbe03926e, 0x3de0f7bc, 0x3de54a54, 0x3dd24bab, 0xbc17a2fa, 0x3ddd633d, 0xbe184d1c, 0x3da78cce, 
    0xbe207d48, 0xbe112380, 0xbe2266a9, 0xbe4e1d91, 0xbd3ce672, 0x3d3aae5f, 0x3e027886, 0xbd05cd6e, 
    0x3d0be895, 0xb80d6dfd, 0xbdf77398, 0xbdce87c9, 0x3e4500cd, 0x3df3ea23, 0xbdbd0e13, 0x3d3ed606, 
    0xbd9a5c03, 0xbe3b9601, 0x3d8b02e4, 0xbe2eb7d4, 0x3d0acf9a, 0xbc98cb32, 0xbe3026d8, 0x3e54b087, 
    0xbe452502, 0xbe3ad936, 0x3dd83d56, 0xbe3ef80d, 0x3dccc948, 0x3e550c1b, 0xbdbba42f, 0xbe1a29f8, 
    0xbe117b96, 0x3e019d27, 0x3d5092a0, 0xbdb25b12, 0x3ccce3f7, 0x3e64fad4, 0xbd3ed951, 0xbd67d7b6, 
    0x3dc5e74a, 0xbd43d41e, 0xbd93f179, 0x3d60755f, 0x3d050d1a, 0xbc52ea37, 0x3e0a7223, 0xbe495f06, 
    0x3ada1d47, 0xbd9ed77c, 0xbde5876e, 0x3e16f4df, 0xbc1931f7, 0xbe427237, 0xbe40bf4e, 0x3de85dd3, 
    0x3e595f40, 0x3e238c42, 0x3e39b6ab, 0xbe410d67, 0x3af6db22, 0x3e0565d1, 0xbc1adc90, 0xbe284881, 
    0x3dce24e4, 0xbe400ed2, 0xbe350617, 0x3e5be04d, 0xbe4d6de8, 0xbe4d1dc4, 0x3dc2ef97, 0x3d7ab1b2, 
    0x3bae743e, 0xbd42718f, 0xbd90899a, 0xbe115547, 0x3e4c464b, 0xbe068025, 0x3bf62017, 0xbdbc1f6c, 
    0xbd96d2e5, 0xbcd5ad71, 0xbc90a967, 0xbd2743fd, 0xbe0c0e60, 0x3dcdd8a9, 0xbd2654b9, 0xbe4c1aa6, 
    0x3d2117cb, 0x3dbdd722, 0xbe1dc235, 0x3e681982, 0x3e10be8d, 0x3e459c84, 0x3dc2001d, 0xbd8d0649, 
    0x3e2ab816, 0x3e5ba9e1, 0xbe3ea955, 0x3e0b4cf6, 0xbdb2ad4a, 0x3e117848, 0xbd95732f, 0x3e0d36b1, 
    0xbe0686c5, 0xbe323cb8, 0xbc6163fe, 0x3ca3b675, 0xbda1aafe, 0xbd76c9cc, 0xbd0603e7, 0x3c4684a9, 
    0xbdd99af7, 0x3e0903ad, 0x3e461361, 0x3d68fe50, 0xbe3bbfe4, 0x3e296436, 0xbd53d76f, 0xbde95e10, 
    0xbe068984, 0xbd07acc9, 0x3dd2c6c4, 0xbccdc3f4, 0xbd779851, 0xbe082e63, 0x3d3608f2, 0xbd2db8e2, 
    0xbd6e07ec, 0xbdccc132, 0x3d94e194, 0x3de98d45, 0xbe52d7f3, 0xbd774682, 0xbe367f07, 0xbe26d5ac, 
    0x3e2fc5a2, 0x3d8c4d92, 0xbc9ae9fc, 0x3dd16c4d, 0xbd64a939, 0xb9c29829, 0xbd8959a9, 0x3d879d69, 
    0x3b816906, 0xbe44dbae, 0x3dfb63cd, 0xbe107b53, 0xbe0e9368, 0xbe476488, 0xbe04e40d, 0xbd812380, 
    0xbd032154, 0xbe35ff9e, 0xbe44fb4c, 0x3d7ea2aa, 0xbd6d40df, 0x3e096f89, 0x3db2b2e6, 0xbdd0f1c2, 
    0xbdd59f51, 0xbdde1dae, 0x3bffbdbd, 0x3d104739, 0x3d15bffa, 0xbe4a8412, 0x3b88d006, 0x3d6e81bf, 
    0x3dacd3a3, 0x3e31bc18, 0xbdaed3c0, 0x3ddb42ae, 0xbe325691, 0xbdc8bb1f, 0x3cafdd8f, 0x3e04b9f2, 
    0xbe34cfc8, 0x3d824a13, 0xbe3ee881, 0x3e041d35, 0x3da992d4, 0x3df50d73, 0x3dbb6a1a, 0x3e149d9e, 
    0xbcc36240, 0x3e25fe74, 0xbd36a5bb, 0xbe0f6bbe, 0x3e3411b0, 0xbe36951b, 0x3e22d5ce, 0xbe3d2f0f, 
    0x3e234228, 0xbe22f26c, 0x3c98e8eb, 0xbe0aca2e, 0xbb732772, 0xbe02a187, 0x3e50c34f, 0xbe077275, 
    0x3da2fb7f, 0x3e2e8a91, 0x3e0f642a, 0xbd0fe2d9, 0x3d8bbb15, 0xbdee0d6b, 0xbe5bd7ed, 0xbcf2725e, 
    0x3d34111f, 0x3d8d4464, 0x3d8b93eb, 0x3e439832, 0x3e1f5a1f, 0x3c05541f, 0x3e28130d, 0x3ddf8bbb, 
    0xbe4615a4, 0x3dfe0785, 0xbe171eea, 0xbd450157, 0x3da81b04, 0x3d00f15f, 0xbd87d8d7, 0xbd982d69, 
    0x3ce129d6, 0x3daf59d2, 0x3df89ee8, 0xbd4a3980, 0x3d001bac, 0x3dd6c8e9, 0x3e532d23, 0xbdbbd73f, 
    0xbd5cf24e, 0xbc962dd3, 0xbdfd7bbe, 0xbe2482ee, 0xbd86dbb8, 0xbd863b3f, 0xbe2cf484, 0x3d85d3d0, 
    0x3e38b09e, 0x3dc3bfbe, 0x3c72d87d, 0x3d81079c, 0x3d9efe50, 0x3c74a381, 0x3e0b2fcd, 0xbc40f2c1, 
    0x3c206c16, 0x3e19c363, 0xbe2437af, 0xbcb9cc4f, 0xbe1627a7, 0x3e21f74f, 0x3e3cf16a, 0xbdeeea42, 
    0x3bc65f4e, 0x3df3213b, 0x3da76e3c, 0x3d2216f9, 0x3d252d76, 0x3e45c518, 0x3e44a80d, 0xbd97f0c3, 
    0x3d2bf9c6, 0x3e26260d, 0x3d722214, 0xbdb10004, 0xbd4d5c3c, 0xbd965283, 0xbd00b540, 0x3b414cb6, 
    0x3e2c8422, 0x3da49100, 0x3e4b33f2, 0xbd85b4a3, 0xbe3133cd, 0xbe4b28bc, 0xbe534061, 0x3e4684f4, 
    0x3d9e5c50, 0x3e103ad4, 0x3e1f3dba, 0x3e2c123c, 0x3e1f6356, 0xbe40842e, 0x3e5d2783, 0xbd9a897a, 
    0xbb66f1cd, 0x3e47fd8f, 0xbc5257aa, 0x3de2ed36, 0xbe1c4152, 0xbd7c92b4, 0xbe50d8ea, 0xbcb51a96, 
    0xbe31f515, 0xbd91e630, 0xbd76674e, 0x3e067f7e, 0xbd2116dc, 0xbe32b864, 0xbd9232d8, 0xbe235b35, 
    0x3e057458, 0xbd9bcdeb, 0xbe070088, 0xbe1cb1d9, 0xbc285094, 0xbdf2d7dc, 0xbe4c5551, 0x3c71f8ce, 
    0x3e20c173, 0x3d15de89, 0x3e14645f, 0x3c98a659, 0xbe554f87, 0x3db54523, 0x3e0792e7, 0x3e11c60c, 
    0x3d4b8daa, 0x3e378fb2, 0xbd435b85, 0xbe4bfd02, 0x3c4f1281, 0xbd9d74f9, 0x3e52882f, 0x3d19f3ff, 
    0x3df712ea, 0x3dd093e7, 0x3d3e2124, 0x3e5a607a, 0xbdfa01e1, 0xbd3fb423, 0x3e5849ec, 0xbd4dae74, 
    0xbd7fe179, 0x3d2f7629, 0xbce65aaf, 0x3ca4ec9b, 0x3e245037, 0x3e22d0b7, 0xbc19a499, 0x3db415d9, 
    0xbc96f117, 0xbe01c07f, 0xbde65433, 0x3e09f737, 0xbe484126, 0xbe33ca44, 0xbdb54fb2, 0x3d6338f6, 
    0x3e5896fe, 0xbe462598, 0x3d4acec4, 0xbe07fe95, 0xbd014aaa, 0xbd9e8aec, 0x3e580448, 0x3d027f8a, 
    0xbdfb470b, 0x3dc05b29, 0xbe18ed77, 0x3de62b2f, 0x3da663c4, 0x3e40d2bf, 0xbdacaecb, 0xbcf7b117, 
    0xbd32fe16, 0x3e31bf98, 0x3e07bc21, 0x3dea79ce, 0xbd0a6dc2, 0xbe33bbd8, 0xbe208c88, 0xbdd91b3a, 
    0xbe4b2f9f, 0x3bc6a582, 0xbe1393ed, 0x3e568c9a, 0xbd70d536, 0xbe148096, 0x3e34e483, 0x3e4d9e1e, 
    0x3de02061, 0x3dd28312, 0x3e15a2a3, 0x3e0e7f35, 0x3dc1cd5b, 0x3de904a5, 0xbd5e5b7c, 0xbd8d46d6, 
    0xbe3d833a, 0x3c8d47ee, 0xbe1269bb, 0xbe0e2cb0, 0xbded0510, 0x3e4c8420, 0x3da4dcc9, 0xbd12dc31, 
    0x3e2175b5, 0xbe181495, 0x3e383127, 0xbde5ed2b, 0x3db7d0d2, 0x3c8de1c9, 0x3b84a269, 0x3ce89659, 
    0x3de2296f, 0xbe0713bb, 0xbe000541, 0x3e0af1d0, 0xbae591b0, 0x3dc003b8, 0xbd494b05, 0xbe0e9207, 
    0x3e461dde, 0xbe1cb882, 0xbd83b4bb, 0xbd0bd48b, 0x3db1627d, 0xbd818abf, 0x3df63c3c, 0x3d52c0df, 
    0xbe12dd71, 0xbd8f2d24, 0x3df0319f, 0x3dd94efd, 0x3d964a75, 0xbe2a8177, 0xbe18ce9e, 0x3c6ddd2f, 
    0x3e0681b6, 0xbe1ce0ec, 0xbe5a808a, 0x3d8ac332, 0xbda09457, 0x3e4ba8a2, 0x3dcd8be1, 0xbd162d90, 
    0xbe28b794, 0xbbf490f2, 0xbda03263, 0x3e06090d, 0xbdc6d911, 0x3e39f57d, 0x3d972037, 0x3ce9effb, 
    0xbd46e9d5, 0x3be67dfe, 0xbd869bf4, 0x3dcce320, 0xbd50c88d, 0x3d3e0309, 0x3cb70854, 0xbe43d16d, 
    0x3e2409f2, 0xbe4db8c0, 0x3d4c4e57, 0x3e4b4ec1, 0x3e2473ae, 0xbe449d90, 0xbdce6a50, 0xbd73a58b, 
    0x3dd20806, 0x3dbd6448, 0xbd759014, 0xbd30fb7f, 0xbe0cd566, 0x3dfed744, 0xbdb178b3, 0xbd110a5b, 
    0xbcd93553, 0xbd8fc54e, 0x3e385356, 0x3da2b329, 0x3e20b073, 0xbdeb9e2b, 0xbe4585a8, 0xbe01596d, 
    0x3e04aadc, 0x3e09cf7d, 0xbc9ed742, 0xbe4fe561, 0xbe435f23, 0x3d95857f, 0xbdc08e32, 0x3cce3b97, 
    0xbdeb0e63, 0x3e062fe5, 0x3e4c496e, 0x3cbfafb5, 0x3e0a2536, 0xbdd0f831, 0xbda15b07, 0x3e19eb5f, 
    0x3dd8da36, 0xbe24c06d, 0x3e519bd1, 0xbe1110d5, 0xbde15439, 0xbe0fdc95, 0xbce47878, 0xbd907377, 
    0x3dbd1b83, 0xbc0f68f3, 0xbbff65df, 0xbe43e921, 0x3e37e0a7, 0xbc7943fd, 0xbc4a97b2, 0xbe3a56a7, 
    0xbd8bdda2, 0x3e000e37, 0xbe2d582c, 0xbdd82c00, 0x3c8154d2, 0x3d1a227d, 0x3e567bd2, 0xbcf6eefa, 
    0x3e66aed0, 0xb9ac62a8, 0xbd9919fd, 0x3e40ae09, 0xbe1895aa, 0xbd1d4bd1, 0xbe1418c9, 0x3d3585f2, 
    0xbda752ea, 0xbcc0cd0f, 0x3e2de840, 0x3e442fb0, 0xbe63b079, 0x3db9e854, 0x3e35fc57, 0x3e312e80, 
    0xbe1e5bdb, 0x3e4b1034, 0x3de4c8ad, 0x3e17d7b3, 0xbe1c6a99, 0xbe49b1e6, 0xbd7f3962, 0xbdfbcc9d, 
    0x3d1fc72e, 0xbe33e9ae, 0xbda7641c, 0xbe110128, 0x3e02991a, 0x3dbadf51, 0x3e652b68, 0xbe10d5b1, 
    0xbdf531a2, 0x3e34a6d3, 0xbce63120, 0x3de51ffe, 0x3d3b121c, 0xbdabcfcf, 0xbe267bfb, 0x3dbb1d64, 
    0x3d9b12ba, 0xbe1dc5b8, 0xbd90e294, 0xbe22b2d8, 0x3cf8b522, 0xbe55e9f7, 0xbdf4698b, 0x3e4ead85, 
    0x3dd70d9b, 0xbc929e04, 0x3cd5276d, 0xbe1a261d, 0x3d9b6496, 0x3dea63e4, 0xbd68bd4b, 0x3de11e4a, 
    0x3d0c24ad, 0xbd6805eb, 0xbd91d839, 0xbe687322, 0xbb97c421, 0x3e49c22c, 0xbd037fc2, 0xbc99c4f0, 
    0x3c9789f1, 0x3e480a5e, 0x3e28de26, 0xbe52b19d, 0xbd80fb28, 0xbce54844, 0x3d5e97e6, 0xbe59f59d, 
    0xbe4e3b26, 0xbe0e6546, 0xbdee75de, 0x3dd12737, 0x3cff1e87, 0xbe1fe202, 0xbd508ce1, 0x3e047368, 
    0xbccf4d95, 0xbe0a3b70, 0xbce3f1a3, 0xbe2f806b, 0xbe37b9ed, 0xbd5797e3, 0xbda0d206, 0xbe073bb4, 
    0xbe1ecbbd, 0x3e1fce59, 0xbd72ee86, 0x3e2d1abd, 0xbe494e9f, 0xbd9dd5f6, 0xbe342c12, 0xbe49af32, 
    0xbd8df03c, 0x3e4d9cf5, 0x3dde751c, 0xbdb2f4c2, 0xbd32345b, 0x3dbc6f7b, 0xbe212fce, 0xbe353bbd, 
    0x3e1ea203, 0xbe508a40, 0x3d54192a, 0xbc895f49, 0xbd7d1a85, 0xbd9d4032, 0x3d98abca, 0x3c9c67d2, 
    0x3e3eea70, 0x3d213b3a, 0xbdd6834a, 0x3e1cde05, 0xbe332742, 0xbdde94dc, 0xbe5f3f34, 0x3e2851b2, 
    0x3bf4c929, 0xbe1863cf, 0x3d3652fc, 0xbe4db4b4, 0xbd5339d4, 0x3ca8d905, 0xbc853395, 0xbc14500d, 
    0xbd598765, 0xbd927d6f, 0xbe13f3cf, 0x3d335434, 0x3c71bd9c, 0xbd45ffd5, 0x3e1b7fba, 0x3e37c1a0, 
    0x3ddcf75b, 0xbe350376, 0x3a3feb70, 0xbe32b6f6, 0x3e4d65c2, 0x3c46cc91, 0x3d60dd2f, 0xbceb182e, 
    0xbe142043, 0xbe30394c, 0x3e6169e5, 0x3dcbadc9, 0x3d71aaf8, 0xbe01282d, 0xbcde0cdb, 0xbe4210c2, 
    0xbbf55304, 0x3e352457, 0x3e367dae, 0xbe324a37, 0xbd1bb009, 0xbe0bdddc, 0x3e5e3cf6, 0xbe44b58f, 
    0x3cb7a505, 0xbe19fcf5, 0x3e0277fb, 0xbe0293a8, 0x3deda330, 0x3d0be98c, 0x3e091a57, 0x3daaac13, 
    0x3d1653b6, 0xbe0bcf00, 0xbe0091cf, 0x3e1f80c0, 0xbe2ea93c, 0xbdeb5ba9, 0x3c1b04b0, 0x3e69aca9, 
    0x3c382e9d, 0x3d5c2bc2, 0x3d904843, 0x3e4bfbb1, 0xbdfc5b47, 0x3d8c836f, 0x3e091c40, 0xbcbad73f, 
    0x3e691aa8, 0xbcf2278d, 0xbe16c955, 0xbe0605de, 0xbc734afd, 0x3dad435d, 0xbe4f5031, 0x3db4fdc2, 
    0xbd6f992c, 0x3d0b79e2, 0xbdfbfd10, 0xbe5158d0, 0x3df0f803, 0xbdda6997, 0x3d538091, 0xbe084c71, 
    0x3d333e5d, 0x3d1abbb3, 0x3debdac9, 0xbde60b4b, 0x3e58e29b, 0x3e1a0cd1, 0x3829afec, 0xbd9f78d0, 
    0x3e23bf78, 0xbdad6e62, 0x3c2325af, 0x3d5ee2ca, 0xbd3cd00d, 0x3e4e2e7d, 0x3d86bc4e, 0xbd3d1c93, 
    0x3d37b457, 0x3d938091, 0xbdbf4ff6, 0xbd75098d, 0x3de4bef5, 0xbd8e8caa, 0x3e462aea, 0x3da3fcbb, 
    0x3e12b2eb, 0xbd4a4f5d, 0xffff7866, 0x00000004, 0x00000060, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0xffff78d2, 0x00000004, 0x00000d80, 
    0x3e1baba5, 0xbe4e3b98, 0xbdcb5840, 0x3e540f3d, 0x3c5ab43a, 0xbe15393c, 0x3e410d97, 0xbe47c648, 
    0xbe6150f7, 0xbccd6882, 0x3e3525b4, 0x3dad368f, 0xbe1dc510, 0x3bbc4f28, 0xbe57b0ff, 0xbe50eeb9, 
    0xbe4e3781, 0xb951c128, 0xbe070e7b, 0xbccbb1e9, 0x3dc8adb2, 0x3dfa31ec, 0x3e3fbda6, 0xbaa08b06, 
    0xbe294d21, 0x3e238e05, 0xbe4c2c88, 0xbdab88e9, 0x3d9c2d65, 0x3df05504, 0xbdce30bb, 0xbda12c9a, 
    0xbe1a65af, 0x3e3f614f, 0xbd8c8197, 0x3aa77842, 0x3cca1290, 0xbcd5596b, 0xbcfb5e69, 0x3d4a9cfd, 
    0xbdd07e1a, 0xbe1c295f, 0xbe399edc, 0x3e0d7804, 0xbe23b3e0, 0x3d5b181a, 0xbe47c410, 0xbe109911, 
    0xbe795b79, 0x3e557737, 0xbdffd085, 0xbd3c3154, 0xbe1ee148, 0x3d733113, 0x3e66aac8, 0x3d6b91b4, 
    0x3e575522, 0xbdcccf91, 0xbdf2f720, 0xbd553d22, 0x3e11c33e, 0x3db7eaed, 0xbcf4e643, 0x3cc2934f, 
    0xbdf902b8, 0xbe31f87e, 0x3d4c0d8c, 0xbe585cfc, 0xbd75c5d9, 0x3dec489a, 0x3e2a3c8e, 0xbe468c56, 
    0xbe022aab, 0xbdcecee0, 0xbe636a3f, 0x3e1c9ddf, 0x3dafd415, 0x3e3d02dc, 0x3e54dec9, 0x3e2790a7, 
    0xbe3a66ef, 0x3c14168c, 0xbe3a4b29, 0x3e35cbe4, 0x3e40969c, 0xbd151e30, 0x3dc73c83, 0x399894d7, 
    0xbe407337, 0x3d5ecbd1, 0xbdf1a63c, 0xbe6f75f5, 0xbe099f5c, 0xbd490e8e, 0x3e13221d, 0x3e1b89c8, 
    0xbe2cca66, 0x3e4dc05a, 0xbe339301, 0xbe09f3d3, 0x3dfed865, 0x3c13eb4b, 0xbdbb4bff, 0x3b4cba44, 
    0x3d80994e, 0xbe27270f, 0x3e59bd20, 0x3ddc776d, 0x3db92acf, 0xbe48e9da, 0xbe0925cc, 0x3e6bec01, 
    0xbd3ef499, 0x3e567060, 0xbcb48d27, 0xbcee29cd, 0xbe4a5333, 0x3d56e5df, 0xbd38f9df, 0x3d7da87b, 
    0xbe0a10e2, 0x3e269f64, 0x3e5d8d6b, 0x3e6f2d9b, 0xbe14e89d, 0xbe0ee42a, 0x3e0d797c, 0x3d99ebb7, 
    0xbe236f59, 0xbd66c15d, 0x3d7ce948, 0xbd972290, 0xbe5e33f0, 0xbe693345, 0xbe1fe3a7, 0x3e5fb1b2, 
    0xbc1886ee, 0xbcd11b4b, 0xbd8f86a3, 0xbe5a7fab, 0x3e46b8cd, 0x3e3835da, 0xbe4e2da8, 0x3e14efc9, 
    0xbcf6a45d, 0x3d9b69a2, 0x3dcc9d02, 0xbe0a7baa, 0xbe31f8ee, 0xbce6b2fc, 0x3e2e5eca, 0x3e47615f, 
    0x3ba50edb, 0x3e1639f8, 0x3e153ede, 0x3d0758c8, 0x3e530f15, 0xbe4f7504, 0xbd958a16, 0x3e495dcc, 
    0xbe79c8a4, 0x3e41e963, 0x3a733042, 0xbe671c87, 0x3deaf785, 0x3e1f0e08, 0xbbe15c47, 0xbd247b43, 
    0x3ca6ba35, 0x3e1ecf76, 0x3dba2e04, 0xbcea0ac5, 0x3e26f4c6, 0x3d1c7f56, 0xbe341b2b, 0x3cba94c8, 
    0xbe1fbd6e, 0xbd3d8270, 0xbe4b87b0, 0x3d851b1a, 0x3e2b7eea, 0xbc8b4fd8, 0xbe1bb9c2, 0xbde3484f, 
    0xbd29a4c4, 0xbdf36865, 0xbd4b5434, 0xbd7c0b76, 0x3e3d8527, 0xbc0b946a, 0x3ddfc6f5, 0x3df84cd0, 
    0x3e005eb3, 0xbdf7c0f6, 0x3e28c75f, 0x3e542084, 0xbda1c459, 0xbddca59d, 0xbcb6a8c0, 0x3e484f0f, 
    0xbe3f0e7d, 0x3db12f1d, 0x3d015d5c, 0x3dec5d6b, 0x3cf0986b, 0x3dd84642, 0xbe3d169c, 0xbd706180, 
    0xbdc9bf22, 0x3e469ccc, 0x3c8a13a5, 0xbe30faca, 0xbe1a9a48, 0xbd4f8a0e, 0x3dc0766d, 0xbd345b97, 
    0x3dc67a46, 0xbdaff4d4, 0xbe007c07, 0xbddcd04a, 0xbdea156e, 0x3d554d7d, 0x3e639c2f, 0x3e66524a, 
    0xbd8f7d4c, 0x3c27e92c, 0x3daffbb3, 0xbe17262f, 0x3c08b722, 0x3e53d364, 0xbe4fe55b, 0x3db46d3f, 
    0x3e1f92e6, 0x3d00bde8, 0x3e1f04c1, 0xbe105415, 0xbdce63ba, 0x3d7973d0, 0xbe182ef3, 0xbd96ffc2, 
    0xbdba11c1, 0x3e3903fb, 0x3d5808b7, 0xbc04489a, 0xbe4039a7, 0x3e790008, 0xbe00b591, 0x3e3ed8e0, 
    0xbe47e296, 0xbe169b62, 0xbe1d620c, 0xbcadac54, 0x3e308b6a, 0x3d87a107, 0xbe4adb25, 0xbda5068f, 
    0xbda614e8, 0x3dddc705, 0x3dca1315, 0x3e30a061, 0xbd2ff584, 0x3df08c21, 0xbd4eb244, 0xbe08f560, 
    0xbdb0e0b9, 0xbe158273, 0x3e60c0fa, 0xbca6b36b, 0x3b1cf633, 0x3ddf3693, 0x3c469766, 0xbe3db8cb, 
    0xbe721c78, 0xbd1b57c8, 0x3de9fca5, 0x3e41b3a5, 0xbdc6808a, 0xbe31f297, 0xbded5d17, 0x3e79bdc9, 
    0x3cf0ff7e, 0x3e627ee3, 0x3e8356a6, 0xbd399df0, 0x3e11b447, 0xbd9f3076, 0xbe16485f, 0xbc5e1ced, 
    0x3e3c57f5, 0xbdc0d51f, 0x3d419032, 0xbdee7ef1, 0xbe251fb0, 0xbe1caf45, 0x3dc4f55e, 0x3d17a4ee, 
    0x3d9fafc5, 0xbe36f614, 0xbda59996, 0x3e638f8f, 0x3e2a2122, 0xbdc86527, 0x3e5cda0a, 0x3e7a4798, 
    0xbda7d7a6, 0xbe23ee55, 0x3cacbef3, 0x3e561038, 0x3da2a5b7, 0xbe61d408, 0x3e5bd708, 0xbe73480e, 
    0x3e6d21a7, 0xbd11fdf1, 0xbe3777b7, 0xbe3d8ae4, 0xbd1cd7b7, 0xbe3725ff, 0x3df67571, 0x3e4dfebe, 
    0x3d83c5cf, 0xbe629049, 0xbe356f3e, 0xbcfa59e9, 0xbdd2617d, 0x3e5130f6, 0x3dd661d0, 0xbbae57fe, 
    0xbe461ce7, 0xbd18637f, 0xbe65afdf, 0x3e0d05d0, 0xbc9bf00d, 0xbcb59a60, 0xbe3b3e06, 0xbdf21fbf, 
    0x3dcae285, 0x3e4ca35c, 0xbdf96a41, 0x3e0a0880, 0xbdb1de89, 0xbdf67a42, 0xbe5a32f7, 0xbe03b6e0, 
    0x3d681f1d, 0xbc100371, 0xbdca0abb, 0x3c908f1d, 0xbe2ea5a3, 0x3e1fe8f0, 0x3cecb06b, 0x3db7c16d, 
    0x3e2b5451, 0xbd2ad052, 0x3e4e2449, 0x3e4ca243, 0xbdc06c47, 0x3dcc9b16, 0x3e415ff3, 0xbdf9c913, 
    0xbd798209, 0xbd3d5aa7, 0x3e050eed, 0xbe5ab49f, 0x3ca60bcb, 0x3c7dde58, 0x3dfd6f2e, 0xbe5b155d, 
    0xbe37aad5, 0x3e4998f0, 0xbe34d121, 0xbe0bc215, 0x3e6bcbea, 0x3c94fff4, 0x3b2d529c, 0x3ddacb0e, 
    0xbe1e22fc, 0xbe305b57, 0xbd85aa82, 0xbe58c754, 0x3db715f5, 0x3dfe5fd7, 0x3d2dc7e4, 0x3be1daf7, 
    0x3e6b4493, 0x3e6c2f6b, 0x3d791421, 0xbd5a20d3, 0x3e037fde, 0x3e2ed327, 0xbbf8900a, 0xbe2b4dd2, 
    0x3c4e3ae7, 0x3d5f9f44, 0x3d693460, 0xbe3cefcf, 0x3e48075a, 0x3df1d16a, 0x3d44bc11, 0xbd95069b, 
    0x3e44d01e, 0x3e625383, 0xbe63f97c, 0x3e4e2260, 0xbe01baeb, 0xbe475988, 0xbe61e231, 0x3da59e60, 
    0xbe36927a, 0xbdc95bbb, 0x3c91be45, 0x3d059293, 0x3e3f2d60, 0xbe6ac1e2, 0xbcb28fd4, 0xbc5d5025, 
    0x3df2381f, 0xbd32e20c, 0x3d9372be, 0x3cc712b4, 0x3dd0cda3, 0xbdf0efc6, 0x3cb241c2, 0x3e4483b0, 
    0x3d0f7938, 0x3d11b501, 0x3e697364, 0x3d40d46b, 0x3dd29142, 0x3e670174, 0x3d18d08b, 0xbe3666e2, 
    0x3d9116ff, 0xbe427577, 0x3e62ce47, 0xbc67d1c3, 0x3d018a7e, 0xbe3bc0db, 0x3e225434, 0x3c013205, 
    0x3d054cbb, 0xbdf83793, 0x3e6127f2, 0x3d0f0082, 0x3e32d412, 0x3da42522, 0x3d2f4172, 0x3d98979c, 
    0xbe204931, 0x3a69cbb0, 0x3cba6cca, 0x3ca02015, 0xbd6dfa5b, 0xbd61bac9, 0x3c8624f1, 0xbe1ed992, 
    0xbe3b0b07, 0xbdc3b992, 0x3e6d78b1, 0xbe59bdf5, 0x3e596e6d, 0xbe31bd6a, 0xbc54b0ca, 0xbde9364e, 
    0xbc999e94, 0xbda66f66, 0xbe3c3c01, 0xbdc59534, 0xbde13f0a, 0xbe1a6a4b, 0x3e0e2336, 0x3d50b460, 
    0x3e36bae7, 0x3d3224b0, 0x3b796f25, 0x3e535a74, 0x3d725548, 0xbcd77030, 0xbe2f8d94, 0x3e304ca8, 
    0xbe3e1343, 0xbe0d460a, 0x3e5b6423, 0xbc128600, 0xbdd78c43, 0xbde355d5, 0x3ddbe807, 0x3e4fc253, 
    0xbdfb9d63, 0x3e82eda1, 0xbd8115fc, 0xbd670d4f, 0xbdf853fd, 0xbe2ac190, 0x3e2a2745, 0x3e71c5f7, 
    0x3db2d1cd, 0xbdc5e819, 0x3e7b67e5, 0x3e223665, 0x3e577639, 0xbc033900, 0xbe51f782, 0x3e7090b6, 
    0xbd8a0492, 0x3d129ee0, 0x3e5ad95e, 0x3e3afb12, 0xbc8e10c4, 0xbdf412c3, 0xbe5ea0d6, 0xbe5ca160, 
    0x3d59fda1, 0xbdd1a3c6, 0xbdab60eb, 0x3cad41a2, 0x3dd2df77, 0x3e573f80, 0x3cd43381, 0x3dc28464, 
    0xbcb94316, 0xbdd563f7, 0xbdfe54b6, 0x3c24dd7d, 0xbe1522fb, 0x3e6bb3c6, 0xbbb6bb33, 0x3d82318e, 
    0xbd77f9bd, 0x3d5ebe0c, 0xbdde5097, 0xbd405cc4, 0xbd75bce9, 0xbd45ac6b, 0x3e11e191, 0xbe25a38b, 
    0x3e5cd0b1, 0x3d94060c, 0x3dfab8af, 0xbdf75e22, 0xbe251c36, 0xbaf0742e, 0x3dc99d7f, 0xbe0ec727, 
    0x3dc9dd16, 0x3e4e2f4e, 0xbd9977e5, 0x3d99e826, 0x3e33dcc2, 0x3c592fcc, 0xbd3d616c, 0xbdf31243, 
    0xbd1b02d1, 0x3e22868c, 0xbd74c469, 0xbe425a16, 0xbcdf1155, 0xbb68f023, 0xbe2e9302, 0xbde3b3ca, 
    0xbe0676f5, 0x3e6f5c13, 0x3dcc36d9, 0x3e3052d8, 0x3e310f6f, 0x3e56f222, 0x3dc661c9, 0xbe1dd599, 
    0xbe4dbecc, 0x3c8de29f, 0xbda2447e, 0xbe5def61, 0x3d13a699, 0xbe072c97, 0x3d5c7e9a, 0x3de4c304, 
    0x3c3194fb, 0xbe45396d, 0x3bd440b8, 0xbe3c2c5e, 0x3e10eb70, 0xbdfa2229, 0x3de77a8f, 0x3d12333d, 
    0x3dac4b73, 0xbc880e78, 0x3d099536, 0x3e577ec8, 0xbd9f0651, 0x3d199b88, 0xbe21d309, 0xbdbec5cb, 
    0xbd414789, 0x3cfa7a2b, 0x3e395a6d, 0xbdf5bed8, 0xbe2f7ac6, 0x3db25c5d, 0xbe24e369, 0x3e09bb88, 
    0xbdb5c404, 0x3dcd711d, 0x3e1ccb00, 0x3d9820e2, 0xbe0ce85f, 0x3e635238, 0xbe6175ed, 0xbd88ac48, 
    0xbb8f6bf3, 0x3bdd7aa8, 0xbdbbd03e, 0x3dc171d6, 0xbdfd0d51, 0x3e2130ee, 0x3c9575ac, 0xbe5e8f02, 
    0x3e45288e, 0x3e2291bd, 0xbe36ff87, 0x3e3cd23e, 0xbe543e1b, 0x3d1e8fe6, 0xbe3931e4, 0x3dcf6b90, 
    0x3e2b2d51, 0xbdc945f5, 0xbd7b2cb1, 0x3de87f06, 0x3d4cc891, 0x39602011, 0xbe727f3a, 0xbe774839, 
    0xbe2d6a51, 0x3dd8ca87, 0xbe69a687, 0xbcc0877f, 0x3e436ddf, 0xbe280a23, 0xbe3d195c, 0xbcb6d958, 
    0xbdddd62d, 0xbe57f76b, 0x3d099d89, 0x3d93bf44, 0x3c75601e, 0xbe487dce, 0xbe446d99, 0x3daaf8ad, 
    0x3e72f93e, 0x3dc67c82, 0x3e0d7d30, 0x3db12acc, 0xbdc8022e, 0xbe642252, 0x3cac2c73, 0x3e31bbda, 
    0x3e68746a, 0xbdc1453b, 0x3d97aaab, 0xbe38643d, 0x3e69e874, 0x3caa820c, 0x3b37ad15, 0x3e3a6d0e, 
    0xbd5319d8, 0x3de8dd8e, 0xbe371531, 0xbe511615, 0xbe33351a, 0x3dc922e7, 0x3e165a2c, 0xbd30778e, 
    0xbe003d54, 0xbe19081d, 0x3e48c122, 0xbe530e30, 0xbe55fa53, 0x3e01685b, 0xbe1941e7, 0x3de1700d, 
    0x3d71d03c, 0x3e4fa178, 0xbd34782a, 0xbd52f4e7, 0x3e33f281, 0x3e1f910b, 0xbe541bc8, 0x3d9a8f8b, 
    0x3c400563, 0x3e4e43f9, 0x3e054dfc, 0xbe2a5630, 0xbe24d355, 0x3e4ab403, 0x3e03404e, 0x3d1f9aab, 
    0x3e3adb4a, 0x3dccb8a7, 0x3e09892c, 0x3e10c8bb, 0xbd8a17b4, 0xbdf23e41, 0xbd289638, 0xbce43f52, 
    0xbe18aa1f, 0x3d795d1a, 0xbce14f26, 0xbdc24636, 0x3e268811, 0xbdfcae86, 0xbe6ef1f7, 0x3cf23a77, 
    0x3de4cb07, 0xbe581395, 0xbe423895, 0x3e08d39a, 0xbe672b8e, 0x3dabc691, 0xbdecd21d, 0x3e20d4a9, 
    0x3e568ba4, 0xbda1367a, 0xbe38ee5b, 0xbe0a8221, 0xbe153f26, 0xbdad7382, 0x3bf66e1a, 0xbda6be4a, 
    0x3c28bdb0, 0x3de7ac40, 0x3e25ee77, 0xbc7ba977, 0xbe5675b9, 0x3dccde67, 0x3e5f49fa, 0x3df8448d, 
    0xbe167d3e, 0x3de14a0e, 0xbe5528e4, 0x3d788bd7, 0x3dc34bcf, 0xbe62f08c, 0xbc5efe19, 0x3e4b181d, 
    0xbe6a1bdd, 0x3dc626f0, 0x3e2a1281, 0x3dadcf74, 0x3e18a9fa, 0xbde5d5fe, 0xbe4e1235, 0xbd1bc0e1, 
    0x3e07aa5c, 0xbd9da766, 0x3e3d95fa, 0xbacd55a7, 0xbe2db7e9, 0x3e10c868, 0x3e34c711, 0xbe0d21cd, 
    0x3d5d112b, 0x3d099da7, 0x3db480b9, 0xbd9a597d, 0xbd1876ea, 0x3de0281f, 0x3d9333aa, 0x3e436861, 
    0xbe34dd8c, 0x3dec5621, 0x3e135ee2, 0x3dea966d, 0x3e5736fa, 0xbd750669, 0x3e20b139, 0x3dfe8ad1, 
    0xbe69f9e2, 0x3e549cc3, 0x3da5307c, 0xbd316f97, 0xbe42626e, 0x3dd0c863, 0xbcc996a1, 0x3e10907f, 
    0x3e485e46, 0x3daa0f75, 0xbe670855, 0x3d237c05, 0xbd9ce90a, 0x3d5ad663, 0x3e29fca5, 0xbe54c280, 
    0x3d8bf31c, 0xbd9bf5ad, 0xbe130fe0, 0xbd3f8f1a, 0xbde88b56, 0xbe516729, 0x3bb95d27, 0xbddbdf51, 
    0x3e206b0c, 0xbdbc35d5, 0x3d639374, 0xbd387a42, 0xbe3da364, 0x3c2cd632, 0xbe30f3a8, 0xbdfe9209, 
    0x3dab833b, 0xbe1ae651, 0x3e10bb3b, 0x3e171c90, 0x3b8ba8a9, 0x3e5cba74, 0x3e272d97, 0x3e5e479e, 
    0xbe687954, 0x3e3a0a36, 0xbd45d5dd, 0xbd4f174b, 0x3ce43b08, 0xbdc3b4d5, 0x3daefd57, 0x3d4267ef, 
    0x3d41619b, 0x3dcc716f, 0x3d30ec82, 0x3d7353f9, 0x3d1d596c, 0x3c333d08, 0xbe508c18, 0xbdf1e84a, 
    0x3dd25162, 0xbe155c11, 0x3e24a341, 0x3dc61c0c, 0x3e112439, 0x3d05ba3e, 0xbddbd775, 0xbd0bc855, 
    0x3d802e2e, 0x3dc6b4af, 0x3e4f3a1d, 0x3cf48827, 0xbc26f31b, 0xbdcf9b8c, 0xbe3c2717, 0xbdc1716c, 
    0x3dd90a46, 0xbbd3635e, 0xbdf4f4c5, 0xbe506ec6, 0xbd6aa626, 0x3d599827, 0xbdc87964, 0xbd8fc503, 
    0xbd482b90, 0xbdd292fa, 0xbe0c508f, 0xbdde79f9, 0x3e258b4e, 0xbdedeb29, 0x3d493d8e, 0xbd2215b8, 
    0xffff865e, 0x00000004, 0x00000080, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 
    0x00000000, 0x00000000, 0x00000000, 0xffff86ea, 0x00000004, 0x00002400, 0x3e2018a2, 0x3bcb6d9c, 
    0x3e0d6ac4, 0xbdf6930a, 0xbe39cbc7, 0x3d7a87de, 0xbd2fee1a, 0x3e3fab7c, 0xbdf6b85f, 0x3c50d0d4, 
    0x3e0ef7a2, 0xbe39a434, 0x3dd05559, 0x3e2d844b, 0x3d16bed7, 0x3d21ef17, 0xbd377e1d, 0x3dc5e752, 
    0xbd3f0c43, 0xbe34e126, 0xbdd2f439, 0x3e0cf664, 0xbd4e46bc, 0xbd7de3c5, 0x3deb1684, 0xbd7a8df2, 
    0x3dd7b41c, 0xbdd03452, 0xbd35ba32, 0xbe2c8ec4, 0xbe1f61c7, 0x3e3c599c, 0x3e1e214f, 0x3c831fa0, 
    0xbd4beab5, 0x3df32fa5, 0x3e32d627, 0xbd8c2044, 0x3dfb5803, 0xbdf7ad53, 0xbc7caecb, 0xbe1e9ecc, 
    0x3d58881d, 0x3d3ccfee, 0xbdf591f1, 0x3e2f5097, 0x3d84b8ad, 0x3e1467f1, 0xbdddf0a7, 0x3cac3406, 
    0xbdd17bf9, 0xbd93fe26, 0xbd36005b, 0x3cd4f442, 0x3d6cd974, 0xbdb82fb7, 0x3e347acd, 0x3dd6ed6a, 
    0xbe4707be, 0xbc201706, 0xbe43df04, 0x3e391ac9, 0xbe1da3be, 0xbde37f8b, 0xbe2451c0, 0xbdf8305a, 
    0xbc9e4c20, 0x3d431359, 0x3d25ec7b, 0x3de6c07f, 0xbda573b8, 0xbcb91117, 0xbe14abcf, 0x3dab0a80, 
    0x3e23a9e0, 0x3d823190, 0xbe39af0b, 0xbd2a4553, 0x3e1dda54, 0xbdb5c18c, 0xbb7856a4, 0x3dfaa4c7, 
    0xbd610b01, 0xbe03ae0a, 0xbdf78334, 0xbca8ef6b, 0x3e439836, 0x3e404f24, 0x3c944383, 0x3e08ff70, 
    0xbdf81a03, 0x3e39c429, 0xbe152b9c, 0xbdc11254, 0x3cb779d4, 0x3dd045da, 0xbe3348be, 0x3c939471, 
    0xbd1e89da, 0xbd89e984, 0x3d236706, 0x3db2b653, 0xbdbd3f3f, 0x3de15c02, 0xbde074b3, 0xbe0c58c7, 
    0xbd963c9c, 0x3e28c91e, 0x3e28bbc9, 0xbdc697b7, 0x3d4add15, 0x3deea6f3, 0x3e07bffa, 0x3e0b5716, 
    0x3d1e0435, 0x3e2f415f, 0xbcca990b, 0x3cf2f9df, 0x3e3da7b9, 0xbdf6c652, 0x3e2775dd, 0xbd2eae5a, 
    0x3cffdf4e, 0xbd910957, 0x3d236d2e, 0xbd28757c, 0xbe30e639, 0x3e435f98, 0x3e3411f3, 0x3d37b2f1, 
    0x3e1f8754, 0xbcdf3423, 0x3e061407, 0xbc00c725, 0xbdc92197, 0x3e065329, 0xbe0ac09f, 0xbe3038a3, 
    0xbde84e31, 0xbd9fa26d, 0x3e19192a, 0xbe343eca, 0x3c800860, 0x3dab7d49, 0xbdf4230e, 0xbe1cba96, 
    0x3e2a8a44, 0xbd7f4484, 0xbd48ff17, 0x3d953952, 0x3d5d13b5, 0x3bcc31fc, 0xbc7bdd9d, 0x3bd35208, 
    0xbe365f76, 0x3e29c610, 0x3e01d50e, 0x3e007ec2, 0xb8ca1166, 0xbdfdac0b, 0xbd1d2abe, 0x3e48cbab, 
    0xbe0914f5, 0xbd65ef03, 0x3d363d7f, 0xbb3b8db3, 0xbd78f0e1, 0xbd216057, 0xbc0dfd70, 0x3dfde1a6, 
    0xbd3e30c3, 0xbc87d729, 0xbde89513, 0x3d2eda99, 0xbd5c1a7b, 0xbe15ff25, 0xbe2ea9ef, 0x3d7743d6, 
    0x3d1cb162, 0xbe223d2b, 0xbd2a63aa, 0x3e002fbb, 0xbde43504, 0x3cd60f88, 0x3dca852b, 0xbc56654b, 
    0x3e1dd162, 0x3e118976, 0xbd84a04a, 0x3e2aac7f, 0xbda742aa, 0xbd811747, 0x3d3a7bfd, 0x3b85b43e, 
    0xbd189c30, 0xbd99dee0, 0xbd252e76, 0xbd33e224, 0xbe36fdee, 0x3e2d9783, 0xbdb54a48, 0x3ca24382, 
    0xbd4d2593, 0xbdf0136e, 0xbe0aeee9, 0x3e313908, 0xbe12c5a8, 0xbc9df905, 0xbd375156, 0xbe260ce5, 
    0x3d9d2560, 0xbdf6b669, 0x3d6ea57c, 0x3d24ac3b, 0x3e27365f, 0x3d8e3322, 0x3e3175e6, 0x3df71d50, 
    0x3dac484e, 0xbe0dee79, 0xbe388585, 0x3ccd3c53, 0xbdfd1640, 0x3e1dddd4, 0x3e272fe7, 0xbd2353e9, 
    0xbc10cfa0, 0x3dfe10a0, 0xbd94c42a, 0x3e298b0a, 0xbd611ebc, 0x3de8220f, 0xbe2d4ae9, 0x3df3ae38, 
    0x3dc559e0, 0x3dbc2cfa, 0xbdbc8c52, 0x3e1cb4dd, 0xbd9cb4e7, 0x3d288cbf, 0xbdceef64, 0x3d80519c, 
    0x3d8b8ffe, 0x3d3ea0f2, 0x3e09240d, 0x3e076dac, 0x3bdc9eae, 0x3c8c5973, 0x3cbcada4, 0x3ca7d44a, 
    0x3d461a8d, 0xbdb8d777, 0xbdba9276, 0x3e42164b, 0xbde29407, 0xbd0b076c, 0xbe35fcea, 0x3c0df7d7, 
    0xbda9e742, 0xbe0bc9f9, 0xbdc11024, 0xbd7cda64, 0x3d403611, 0xbd3b2004, 0xbd92ea33, 0x3e19b2fd, 
    0xbe23724b, 0xbe242b02, 0xbc6eb8c9, 0x3df9bd59, 0xbcd78a03, 0xbe071639, 0xbd1a2f48, 0xbe327cf5, 
    0x3e17317d, 0x3cc21a17, 0x3d8585c1, 0x3cad1ba5, 0xba8ee421, 0xbd8cc591, 0x3daaa8e4, 0xbc53f974, 
    0x3c39872b, 0xbd3bf553, 0x3debf05c, 0x3dd1bbe0, 0x3e27d9ec, 0x3de5b220, 0xbdae42d7, 0x3e11c778, 
    0x3e2be4ec, 0xbe35eec9, 0xbdefd6b4, 0xbd51d32a, 0x3dc92c33, 0x3d2c0ef8, 0xbcfad500, 0xbe458650, 
    0x3e2f3953, 0xbd316a0b, 0x3d8558df, 0xbbfad2ef, 0x3e1c689b, 0xbd5c8e9d, 0xbca34630, 0xbc62b0db, 
    0x3d172377, 0xbd7a690d, 0xbd50aad2, 0x3d804815, 0xbcb9f104, 0x3e11ac4d, 0xbe2fd2d6, 0xbd99d730, 
    0xbcb43608, 0xbe27d740, 0x3e3c1f10, 0xbcb73f88, 0xbd5ba747, 0xbd8da8ab, 0xbce882df, 0xbdae81eb, 
    0xbdc20dc2, 0x3df74350, 0x3dd6ec78, 0x3dc02a54, 0x3d979f5b, 0x3ce5cf2d, 0xbd88f73d, 0xbda3304d, 
    0x3ccc5659, 0x3dc49a0c, 0x3c385775, 0x3e295664, 0x3df501d2, 0x3e36da10, 0x3e33a16b, 0x3e229ceb, 
    0xbe23acb5, 0xbdb035e2, 0xbd248bc0, 0xbd03466b, 0xbe199cb4, 0xbda0455a, 0x3cb41385, 0xbd97ef05, 
    0x3de88e55, 0x3e269339, 0x3ce2952b, 0x3e340feb, 0x3e14ff2b, 0x3db61bfd, 0xbb99454c, 0xbd654298, 
    0x3dc6ce77, 0x3d360538, 0x3e271345, 0xbe12999f, 0xbde0e9f6, 0x3e3e6cf5, 0x3d1279e9, 0xbdb36112, 
    0xbc6d160a, 0x3c820b92, 0x3cdbe807, 0xbdae0b8b, 0x3e3f98ba, 0x3e3cd31c, 0x3af948ed, 0xbd84dcf8, 
    0xbbbf877e, 0x3e04b7d8, 0x3e473138, 0xbe1c8cb4, 0x3da85040, 0x3e136328, 0xbc9e760b, 0xbc2ef749, 
    0xbe067c3b, 0xbdc1dd5a, 0x3ddd08d0, 0x3e04cf42, 0xbd0bee30, 0x3e29d9a2, 0xbda0d250, 0x3dece7c2, 
    0x3d04ae03, 0xbe2fe2eb, 0xbddb36ba, 0xbdc0452d, 0xbdb6c24b, 0x3e41a6e1, 0xbd30dd00, 0x3e10d56a, 
    0x3da68405, 0xbe2a3c80, 0x3dd1b389, 0x3cc7a69d, 0xbccee6cb, 0x3e1f9d8d, 0xbe1156d4, 0x3e0fa096, 
    0xbdccbac8, 0xbd12e453, 0x3d89210e, 0x3e35f110, 0x3e48b8f6, 0xbe08be4f, 0xbd97e4df, 0x3db87316, 
    0xbdf3fdcd, 0x3a6d4921, 0x3db90386, 0x3e30f0c3, 0x3d4ffe36, 0xbe0ac46f, 0x3df48858, 0xbd2d61f8, 
    0xbc2998e1, 0x3dc5993a, 0xbcc02edf, 0xbdaf2bbc, 0xbe3cb0d5, 0xbd5989d0, 0x3dbbc0ad, 0xbe3a0610, 
    0x3d0aa20d, 0xbd30fe88, 0x3ca81c87, 0x3e03d66e, 0xbc218986, 0x3de699e0, 0xbdb8a2df, 0x3c9deb28, 
    0xbd99c072, 0xbdd583f0, 0x3e20882d, 0x3e04f38b, 0x3dd8e2b5, 0xbdac1072, 0xbd99efab, 0x3dc1e85a, 
    0x3aad123f, 0xbde9e5ef, 0x3b4eea85, 0x3d329b9f, 0xbdebb3a1, 0x3d3d5a73, 0xbb907d45, 0xbd7d3ed4, 
    0xbe478adf, 0x3e04a08a, 0xbdbbef81, 0x3d294db8, 0x3e1bacd3, 0x3c1f45a3, 0xbe2ea7c9, 0xbe19736f, 
    0x3ddd3fd2, 0xbdffafe4, 0x3d3b5825, 0xbd02d0bc, 0x3e1006a6, 0xbe38c8fa, 0x3e178f84, 0x3e50b2b2, 
    0xbd84ec25, 0xbe09fa9a, 0xbe06674a, 0xbd4278c0, 0x3c190d11, 0xba8243bb, 0xbe0c4d23, 0xbd8d4e78, 
    0x3b986b6b, 0xbe0e9578, 0x3c9e15bc, 0xbe11b822, 0x3e4b15a2, 0xbdee4acd, 0xbda7c12f, 0xbcd843e7, 
    0x3da429b0, 0x3d401fad, 0x3deb063a, 0x3d7cd597, 0x3bd60475, 0x3d421690, 0x3d6fec0a, 0xbd99d92e, 
    0xbe226305, 0x3e1d33e8, 0x3e2cf8fa, 0x3dd229e3, 0x3cd2d35d, 0x3d06b45a, 0x3ddb208b, 0x3e186c45, 
    0x3df3a26f, 0x3dbbde16, 0x3bb318a8, 0xbcba81d0, 0xbdfc9437, 0xbe140e46, 0x3b1bec87, 0xbe12b3fe, 
    0xbdc86257, 0xbe0b7983, 0xbd953876, 0x3e136db4, 0x3d4f2649, 0xbdbd2328, 0xbd7bdd94, 0xbe10aaa2, 
    0xbde23a4f, 0x3e370332, 0x3de2fc8a, 0xbe0ac033, 0x3ddc3edd, 0xbddd6294, 0x3e046b94, 0x3d9d8fd9, 
    0x3e299dad, 0xbcd2e12e, 0x3e05f8c0, 0x3dd44534, 0x3dd644f8, 0x3df6b627, 0x3b9547d1, 0xbc95b219, 
    0x3dacf076, 0xbe0436e7, 0xbd408fca, 0x3dc425a1, 0x3c17467e, 0x3ca40054, 0xbe042837, 0x3e0c8845, 
    0xbe10c899, 0xbdb9775c, 0xbd412dd4, 0xbd13f2d3, 0x3e3a97ee, 0x3d9d8969, 0x3d5e6aba, 0xbd8a683e, 
    0xbe1f4b20, 0x3e334e2b, 0xbe251863, 0xbcc56a39, 0xbb009f65, 0x3d45c00a, 0xbdb285e2, 0x3d90e4a3, 
    0x3c55f54a, 0xbdb8de06, 0x3dab675f, 0xbd342434, 0x3c291424, 0x3dce7601, 0x3dd7c753, 0xbdd0f0b3, 
    0x3e3c92c7, 0xbd3b3c5c, 0x3dbd5178, 0x3d2ac8b2, 0x3e1e5449, 0x3e28feb1, 0x3e0e25cc, 0xbde9aa79, 
    0x3d3f4dd4, 0xbdae19d9, 0xbdfb153a, 0xbdc09904, 0x3e4613bc, 0x3e1ef287, 0xbe10a881, 0x3bab4076, 
    0x3e401f76, 0x3d6998a6, 0xbe169398, 0x3e0bba7c, 0x3e12c4a4, 0x3e34bc96, 0x3e3ea1a9, 0x3d2bcb80, 
    0xbdf1bfc3, 0x3de751bb, 0x3d31fb1e, 0xbd9cc052, 0xbe2b7017, 0x3df5b15f, 0xbe4e0f76, 0x3e070fac, 
    0xbda0a36d, 0xbdce4312, 0xbe37f46e, 0xbcaae249, 0x3e37c3d1, 0xbdab5fb2, 0x3ca7cecd, 0xbe2792bf, 
    0x3d09beb3, 0x3d95e6b7, 0x3c48ffef, 0xbe17930a, 0x3e108c1b, 0x3d5900ea, 0x3e32a202, 0x3e1985c9, 
    0xbde0f057, 0x3cb00fac, 0x3e401628, 0xbd90bda0, 0xbd79c019, 0xbc776581, 0x3e224e90, 0xbe1c4c22, 
    0x3e2ee10e, 0xbc67ff2d, 0x3e10fec0, 0xbc5990d3, 0xbe29ca9e, 0x3e0e7fa8, 0x3ccff900, 0xbdb55337, 
    0xbba58e44, 0xbe1f7c06, 0x3cf78e97, 0x3e3477b4, 0xbc9051e0, 0x3e39c697, 0xbddc09c0, 0xbdec8253, 
    0xbe23ddef, 0x3c4753df, 0x3e1d2151, 0xbe05dede, 0x3d87ff81, 0xbb28eabb, 0xbe386e61, 0xbda4f5e5, 
    0xbd777fbb, 0x3df3109b, 0xbd9eee21, 0x3de1b470, 0x3d9a021e, 0x3d924432, 0xbe13dccf, 0x3e129957, 
    0xbdfc2063, 0x3e4d0cd1, 0xbc173fa3, 0x3df935a1, 0xbcefdfe1, 0xbe07fcf6, 0x3e175968, 0xbe2692be, 
    0xbcba63f9, 0xbd8f0354, 0xbcce6bc5, 0xbe0c16cb, 0xbe2256d6, 0x3c457d07, 0xbd86f963, 0x3c8564ee, 
    0xbe2f95d7, 0x3ddf817f, 0x3c9ee9b5, 0xbd95a660, 0xbd71aa2e, 0x3bff0253, 0xbd921ab9, 0x3d835e21, 
    0xbd08dfda, 0x3e2bb0a4, 0xba8885eb, 0xbd85034b, 0x3e349f37, 0x3d98a0b3, 0xbd9f718b, 0xbe2e17a1, 
    0x3e3eabcc, 0xbcadf61e, 0xbc42cd0d, 0xbdde9268, 0x3dbf2bc5, 0x3e308818, 0x3e0420eb, 0xbe04d017, 
    0x3e4a0189, 0xbe067888, 0xbd2a5e49, 0x3dcfb2ac, 0xbd481208, 0x3dcc2da2, 0xbd58698a, 0x3e0615a6, 
    0xbe15afd5, 0x3cefa44e, 0xbdecee3f, 0xbdf60b67, 0xbdd39773, 0x3e228820, 0xbde8b40a, 0xbd4222c2, 
    0xbc8440f4, 0x3d2cf8af, 0xbe10508e, 0xbca9ba00, 0x3b877d34, 0x3db15346, 0xbdad44d2, 0x3e45d4de, 
    0x3dd24c30, 0xbe21cc93, 0x3df35201, 0x3b221178, 0xbd4c5b15, 0x3e36c9f0, 0xbb7bd90a, 0x3d76df35, 
    0xbe1a05f1, 0x3d5b4705, 0xbdfedf64, 0xbe214e87, 0xbe3d7841, 0x3e1a4930, 0x3cfae530, 0x3e149067, 
    0x3e2dccd3, 0xbe038918, 0x3e16d056, 0xba81dc34, 0xbe17418a, 0x3d4214aa, 0x3e4535b9, 0x3e0e2205, 
    0xbce339e5, 0xbe05d2ee, 0xbe025ed4, 0xbde92dfa, 0xbd63b01e, 0x3e38c245, 0xbd158d00, 0xbe2eeb0d, 
    0x3e328a4f, 0x3e141cf5, 0xbdbd90da, 0x3d144806, 0xbdcef999, 0xbe2eab13, 0xbdc0b7e3, 0x3e1a2249, 
    0x3b702aca, 0xbc51e974, 0x3e47cf69, 0x3d541d64, 0x3cda3ee9, 0xbd0960ec, 0xbd77f546, 0x3d498a16, 
    0x3ce88f22, 0xbdfe8cba, 0xbe12888b, 0x3d56c902, 0xbdcb980a, 0x3ce79ae8, 0xbe2cc803, 0xbd86ff74, 
    0x3e32e72c, 0x3d9239d5, 0x3de12b60, 0xbb020dc6, 0xbddc2960, 0xbcca86a8, 0xbab936f2, 0x3bf0cb17, 
    0x3d42659b, 0x3e4215aa, 0x3e430ccb, 0x3e20c1a1, 0xbe205c1a, 0xbd627279, 0x3d0450b7, 0xbdc2aabc, 
    0x3e4e876a, 0xbdc005f8, 0xbdf82d36, 0x3d1eb6aa, 0xbda57fea, 0xbc872b1f, 0xbdb5ff46, 0x3e1c991f, 
    0xbd0c506a, 0xbd06671f, 0xbd8902e5, 0xbe2b6b59, 0xbdac9a71, 0xbe2c3225, 0xbdc85aaf, 0x3c23fc61, 
    0x3dbb8481, 0x3dde7ba0, 0x3c6e55a9, 0xbda58c6f, 0xbd6eefd2, 0x3c565dd3, 0xbdb7365b, 0xbe370ac5, 
    0xbce39bf9, 0xbca22f75, 0xbd928140, 0xbdad402f, 0xbe38829d, 0x3d1f03b5, 0x3da73a06, 0xbc911c86, 
    0x3c86b60d, 0x3d142448, 0x3e32910a, 0xbe1de8b6, 0x3ddb2442, 0x3ddc03e7, 0xbe45da86, 0x3dae95b2, 
    0x3d6cbac9, 0xbe0ef522, 0xbd1f60a2, 0xbce4f390, 0xbe25b916, 0xbde3dbc2, 0x3e16198c, 0xbc0ae073, 
    0xbc409fce, 0xbb5e0061, 0xbe17d20c, 0xbd96be06, 0x3e054dcc, 0x3de4443b, 0xbd73fca5, 0x3d8bb3a5, 
    0x3cc9af37, 0x3a887280, 0x3e476fb6, 0x3d7c3bf7, 0xbd862611, 0xbca2d89e, 0x3e098894, 0x3e3c6784, 
    0xbdd25e47, 0xbc95e5ac, 0xbdba442a, 0xbe1317d8, 0xbd5044da, 0x3dcd1d22, 0x3e0b7562, 0x3d9f659d, 
    0x3e01c5cd, 0xbe31cdb9, 0xbdfce8aa, 0x3e3dcbd0, 0xbc007506, 0xbe15010b, 0x3da3cbd4, 0x3d0fc0ed, 
    0xbdcf1392, 0xbe34734a, 0x3c1dc928, 0xbcdda757, 0xbcebbf55, 0xbe24c690, 0x3d82168a, 0x3e394a86, 
    0x3df83788, 0xbe28219d, 0x3e33e3a0, 0xbe1175a2, 0xbe1a485b, 0xbdb877da, 0xbe11ce63, 0xbc4917ac, 
    0x3d3610bb, 0x3d95c8fb, 0xbe14587d, 0xbdbef557, 0x3d9ff0a4, 0xbd56f207, 0xbd78da7e, 0xbd624448, 
    0x3daba42f, 0xbdb52835, 0x3d1a6cf5, 0x3e07e0dd, 0x3c2fa789, 0xbe05f8fa, 0xbe421bdd, 0xbe4104cc, 
    0xbdae2b89, 0xbca8adc1, 0xbe222592, 0xbdb9aeef, 0x3d9eb11f, 0xbd4b4a7e, 0xbdd2d1d4, 0x3da322e2, 
    0x3cd8f38b, 0xbe19f0fd, 0xbe2e114c, 0x3e07fa99, 0xbe1bdf09, 0x3d8fbdbd, 0xbe26405c, 0xbce735a2, 
    0xbd34d0f3, 0x3cd4e5bc, 0x3df6858a, 0x3bfb1867, 0x3cd0f2d1, 0x3d8635b6, 0xbe061299, 0xbd5744fd, 
    0x3c7657d6, 0x3dbbb0dd, 0xbc17c68c, 0x3b0037ab, 0x3e08769a, 0xbe2f940b, 0xbca1b57f, 0xbdbb56aa, 
    0xbde94c3a, 0xbe143797, 0xbd7beb93, 0x3e3a9863, 0xbd7e6aa1, 0x3e2c3c89, 0x3d4f77ab, 0xbe3b122a, 
    0x3db767bf, 0xbdca50f4, 0x3dd5c7c6, 0x3dffdad8, 0x3dbb19d8, 0xbd354d0a, 0xbc93573e, 0xbdb532ae, 
    0xbcc22ff7, 0x3ddcb203, 0x3ca447a8, 0x3e11f9a1, 0x3aa1047b, 0xbe42b66a, 0xbde15e1d, 0x3c917535, 
    0xbe2a9a5f, 0x3e2da572, 0x3c5d853f, 0x3da7cdab, 0x3d079735, 0x3de64774, 0x3ddc6e40, 0x3da24200, 
    0xbd284eb1, 0x3d98ddff, 0x3d72ec58, 0x3dfada46, 0xbd121c06, 0x3daf39fc, 0x3e24624d, 0x3d6da9ee, 
    0xbe293256, 0xbe187434, 0x3d6beb5e, 0x3dcf644d, 0xbe3e4490, 0x3df7f526, 0x3e31f00f, 0xbe30e486, 
    0xbe3010c0, 0xbded6ecf, 0xbd38367a, 0xbe24b76c, 0x3c711654, 0x3dfa22b4, 0xbdd96703, 0xbe361765, 
    0xbde51e6b, 0xbe191bbb, 0x3dd450ab, 0xbc91aa38, 0xbcb45646, 0xbd597d45, 0xbdfa53e3, 0x3e11db00, 
    0xbe187054, 0xbd7098d9, 0x3defcf89, 0xbe182b6d, 0xbdcc83d0, 0x3e22abbc, 0xbc14d0a3, 0xbba9ba2f, 
    0x3e31ab15, 0xbe0c283e, 0x3d6e792c, 0x3d5bd03e, 0xbd3a2a6c, 0xbe1558ef, 0xbe1a61a8, 0xbe057b5b, 
    0xbdd91108, 0x3b541bd8, 0x3e0e51b0, 0xbcbaab78, 0xbbe13aa2, 0xbd51394c, 0x3df5938c, 0xbd880529, 
    0xbe1972a3, 0x3cfc3dc2, 0xbcf011bd, 0x3e11010d, 0xbe3af776, 0x3da2d43a, 0xbe0ca398, 0xbe1ed5b9, 
    0x3de52c00, 0xbd4396f2, 0xbdaaffa8, 0xbe1f5f49, 0x3cc77294, 0x3e32aacc, 0xbc47d27f, 0xbd0a6ae3, 
    0xbd104942, 0xbd9ddf42, 0xbda55bcf, 0xbdf2dd52, 0xbd2c6c75, 0x3e3ad599, 0x3dc29b73, 0x3c1c11a6, 
    0xbe306e95, 0x3e25b0c6, 0xbe35ee62, 0xbe3f2669, 0xbd4c090f, 0xbe24ac9f, 0xbc07384e, 0xbd77ec1c, 
    0x3dd5c466, 0x3e3609be, 0x3e0cbcac, 0xbb3fab9a, 0xbdef30d6, 0xbe2f732a, 0x3e1fd3b0, 0xbd7de083, 
    0xbdcfa7fc, 0xbe3996d9, 0x3cab9899, 0x3cdb3fc3, 0x3dec6bdc, 0x3e29efd7, 0xbab37a30, 0x3e00127d, 
    0xbe1932c5, 0xbdd17367, 0xbe05c98a, 0x3cfdd3b5, 0x3d285d85, 0xbe08d717, 0xbe2fd150, 0x3e0b368d, 
    0x3dd6cd90, 0xba8ba45f, 0xbe2a8253, 0x3ce61b29, 0xbcdeb05f, 0x3caeeb3b, 0xbd017dbc, 0xbd9ac1e8, 
    0xbe3dbe2e, 0x3e2e3125, 0xbde8e842, 0x3daecd84, 0x3e50eaf5, 0xbe005226, 0xbde1029f, 0xbe1d19af, 
    0xbe167602, 0x3d0825d3, 0xbe080fb0, 0xbe296117, 0xbcb77a68, 0xbe16a65c, 0xbe266cf7, 0x3dfbc217, 
    0xbdd2aac4, 0x3e3217bc, 0x3db695a9, 0xbe35245e, 0x3e223dc4, 0x3b301ee2, 0xbdcd0447, 0xbdd2e360, 
    0xbcf26e58, 0xbd8ed908, 0x3e1ab995, 0x3c239ee3, 0xbdb84eb2, 0x3e245262, 0x3c074407, 0xbe06b32f, 
    0xbe23b1ed, 0xbd527b2e, 0xbdecc7d6, 0xbd8b7847, 0x3e3cbc04, 0xbe249b61, 0x3e17d809, 0x3e3e47d5, 
    0x3d6becbc, 0x3d7e19be, 0xbe31240f, 0x3ce90fed, 0xbe0ea694, 0xbe1981ce, 0xbe1f64a0, 0x3d809886, 
    0xbde1311e, 0x3def9c73, 0xbd9f19c9, 0xbd93c125, 0x3da5a918, 0xbe03326c, 0xbe19250e, 0x3c7b826d, 
    0xbda6d082, 0x3d033f37, 0x3ca65a85, 0xbbdd2211, 0xbe06d2a5, 0xbe08eaa1, 0xbdcf7b17, 0xbe3fc63f, 
    0x3e3e5225, 0x3e3a9358, 0xbdd995aa, 0xbb6d4c3b, 0x3b1ad52d, 0xbe29f3b1, 0x3defe3e8, 0xbbeaea6f, 
    0xbde4b9f4, 0x3dcf13ec, 0x3d6f44ff, 0x3de35287, 0x3e00838d, 0xbdcb773a, 0xbc226312, 0xbe148fe0, 
    0x3e47412c, 0x3d568f3a, 0xbce0b757, 0x3ce17e3b, 0x3d599a20, 0xbde2d7a3, 0x3d5c6a37, 0xbd35263b, 
    0x3d07c7dd, 0xbe16c86b, 0xbbc04e5b, 0x3d383ac6, 0xbe2bc35f, 0xbdf1846b, 0xbd5b982e, 0x3d04f1de, 
    0xbe0916de, 0x3ded3cdd, 0x3c29d529, 0x3d03d25b, 0xbda1629e, 0xbdbbdfd5, 0x3d81e0eb, 0x3e1af3cc, 
    0x3de333f6, 0x3e038dab, 0xbd3581ad, 0xbe0acd27, 0xbd50d4d9, 0xbdb4940a, 0xbe245d07, 0x39366364, 
    0x3e0e794b, 0xbd8342e5, 0xbdf6b5d1, 0x3e3b5066, 0xbd3a1123, 0x3e110e33, 0x3e001a1f, 0xbd7fa4f4, 
    0x3d069d6a, 0x3df3bb8a, 0x3d363d8b, 0x3cedc9ae, 0xbe2badb1, 0xbde658c3, 0x3d677e0e, 0x3de990bc, 
    0xbe0dc885, 0x3da0f2fb, 0x3caa3488, 0xbe5317ad, 0x3de308a3, 0x3de918c7, 0x3d49070e, 0x3da4de49, 
    0x3e38a4cb, 0x3c8cd93a, 0x3e150f2d, 0x3e1405f8, 0x3e27fb64, 0x3e09fafd, 0xbdbb912a, 0x3d71662a, 
    0x3e3146d8, 0x3da516c7, 0xbd5070e3, 0xbd5dfb0c, 0xbe298451, 0xbe385118, 0x3c1fb365, 0xbd35012f, 
    0x3e030c6e, 0x3d54461b, 0xbc224d20, 0xbe0a50d5, 0x3df3240f, 0xbdf53969, 0xbe42c156, 0x3db33024, 
    0xbd891d63, 0x3d0cd246, 0x3d837b9c, 0x3d9a60c5, 0x3ddc3648, 0xbda3184e, 0xbda9a575, 0x3e0d38e9, 
    0xbd8fcdc8, 0xbe2abcd9, 0xbdee41c7, 0xbdd11b50, 0xbdb6a386, 0xbdc1a8c1, 0xbd56a09b, 0xbdbbca17, 
    0xbdc19cc4, 0xbda5146e, 0xbdbcb9b3, 0xbc8ebb64, 0x3ad668cc, 0xbdfb30f4, 0x3d852dd6, 0xbd6fe029, 
    0xbce479cd, 0x3e1e0382, 0xbe191cf1, 0xbdf2fc74, 0x3db648fa, 0x3d7dda4c, 0x3d6f980d, 0xbe12aaed, 
    0xbd0051b7, 0xbe0b0aef, 0xbe0947ba, 0xbe2fd435, 0xbe0a7ea0, 0xbcc47d0b, 0xbdab588d, 0xbd2af6ec, 
    0xbcac6d52, 0x3d4d09d2, 0xbe0d3143, 0x3db70e91, 0x3c60eeed, 0xbe22581b, 0x3df4322a, 0x3db8b9ac, 
    0x3e0436f7, 0x3e135495, 0x3e1355e3, 0x3db9f65e, 0xbe249ce2, 0xbc5ca1aa, 0xbd70b527, 0xbdcbfaf2, 
    0xbe1b1982, 0xbe211b99, 0xbe25dd1b, 0x3e091580, 0x3d74a1a6, 0xbd0a1dd8, 0xbc2286ac, 0xbcf3f54d, 
    0x3d42e986, 0x3d9bd771, 0xbc96ab6f, 0x3dbb271a, 0xbd9d123e, 0x3dc48a7f, 0x3df351cd, 0xbd90e787, 
    0x3d9c8cfe, 0xbe0ffa43, 0x3d049146, 0x3cf06b7a, 0xbd859959, 0x3db57baf, 0xbdee92ad, 0xbc812357, 
    0xbca96892, 0xbe352128, 0x3dd85440, 0x3dceccf5, 0x3dfaab3c, 0xbe2c7feb, 0xbc160cec, 0x3e0b14da, 
    0x3d64863a, 0x3e34203d, 0x3c300929, 0x3e3086dc, 0x3de3680c, 0x3ced4f6e, 0xbd4d0eda, 0xbda690cc, 
    0xbe1e2fb1, 0x3df2db23, 0x3ddeb41c, 0x3d7906d1, 0x3d970982, 0x3db65237, 0xbc38f543, 0xbe400297, 
    0xbd48fdc6, 0x3e290fa0, 0xbdca9645, 0xbe208916, 0xbdc2f227, 0x3dac84a6, 0xbe16a211, 0x3d9f1c3d, 
    0x3e20b4a9, 0xbe216b87, 0xbc57568c, 0x3e1483da, 0x3dbd7161, 0x3e247615, 0x3db0993e, 0xbe10bcc1, 
    0xbd33c453, 0xbcea3197, 0x3cc4f271, 0x3dd0bd07, 0x3dfe075a, 0xbe1cf769, 0x3d9680e0, 0x3e2bc020, 
    0xbb87858e, 0x3dd69a77, 0x3d0b143e, 0xbe3d4a64, 0xbd91bb5c, 0x3d8c3f01, 0xbd8ff349, 0x3dc97372, 
    0xbddd6b1e, 0xbe2325cf, 0xbe1c2353, 0xbd8625c1, 0xbda3bcfa, 0x3d89fc25, 0xbd3550b9, 0xbd74b1ee, 
    0x3dadd91e, 0xbe3aeda2, 0x3ccd56f9, 0xbe31e84d, 0xbd12c8cb, 0x3e2c19ed, 0x3d402054, 0x3e0040b0, 
    0x3dc67c06, 0xbd312a61, 0xbd825e18, 0x3c8f4088, 0x3c47d1c2, 0x3dffcfee, 0xbde4870e, 0x3b3a9e54, 
    0xbdfeaba6, 0x3d9579e2, 0x3dc0f2c0, 0x3e37c82d, 0xbe0bb7b8, 0x3e1ecf45, 0xbe353b2f, 0xbe3d285f, 
    0xbe335ef9, 0xbcb58140, 0x3df7724e, 0xbe3a36b9, 0xbcae4d6d, 0x3e440090, 0x3e0daaaa, 0xbe1791da, 
    0x3d90021f, 0x3d0dffe7, 0x3e0b01d8, 0xbdaaaea1, 0x3e3ef1fd, 0x3e1b9f85, 0xbc99d0b4, 0xbd2cf65a, 
    0xbd996011, 0x3dfe62f9, 0xbd1415cb, 0xbe294cdd, 0x3d189e95, 0xbde66515, 0xbe2bb578, 0x3de4791c, 
    0xbdd89613, 0xbb4a8797, 0xbcb7bccc, 0xbb55543e, 0x3e367ba7, 0xbc591eb9, 0xbdf5a2f3, 0xbcbeb02a, 
    0x3cb0bc75, 0x3d91ea6a, 0xbdd2ad25, 0x3d9b61f4, 0x3c063cac, 0xbdc76fbc, 0xbca37924, 0x3e338ca9, 
    0xbc3427e9, 0xbd9cbd31, 0xbd6f7988, 0x3e0f3db8, 0x3d9fe5b6, 0xbd5e81c9, 0xbd4e14cd, 0x3e3e189b, 
    0xbe2db50c, 0xbdcd484e, 0xbc308f22, 0xbe29c8fd, 0x3e0826cf, 0xbd914185, 0x3dad9be2, 0xbd526838, 
    0xbd600d6a, 0xbaece84c, 0x3d23ae24, 0x3d10a43b, 0xbbb7e4ab, 0x3d6ea661, 0x3dae6261, 0x3e27ae7d, 
    0x3e251834, 0x3b9dbdc7, 0xbd980232, 0xbd389b0e, 0x3d2161c1, 0x3dac2bf3, 0x3d84205d, 0xbdbe45e4, 
    0x3e51ba88, 0xbd4f8851, 0x3d8e9e05, 0xbd5c675e, 0xbad3c1b5, 0x3dd73a02, 0xbdb1913f, 0xbd3f04ed, 
    0xbdc6ef47, 0xbd98e9aa, 0x3e106523, 0x3e4275df, 0xbe3c1b74, 0xbe0aeeaa, 0xbd39ab22, 0xbe0e93ae, 
    0x3e49adfa, 0x3e3b658b, 0xbe2703be, 0x3e1428c7, 0x3e325ed7, 0x3d9c1a12, 0xbdcb29a3, 0x3dcec408, 
    0x3cb628f2, 0x3e2b36e9, 0xbd8c991e, 0xbde64655, 0x3e07dea7, 0x3ddb7146, 0xbcbf37d3, 0xbd16b57d, 
    0x3e26baac, 0xbd3cd3bf, 0x3c4b71e4, 0xbde3bce0, 0xbdb20fa1, 0xbce3deec, 0x3da72bd3, 0x3c76ee21, 
    0x3e1efb63, 0xbc215154, 0xbd77bb55, 0xbc8acc04, 0x3e18fa9a, 0xbe04d908, 0x3db885a1, 0xbe0e8f6e, 
    0x3e0a9faa, 0x3dc12d7d, 0xbe08f672, 0xbdf8dbcd, 0x3d2e45a9, 0x3e1ce1ef, 0x3dc596df, 0xbcf308bc, 
    0x3e34054b, 0x3d7bba83, 0xbe0ff57a, 0x3d8aa39b, 0x3e104b5b, 0xbe2c775e, 0xbd57e32c, 0xbe46d474, 
    0xbe2590ec, 0x3e164602, 0xbce9ca09, 0xbdf44a08, 0xbc277da5, 0xbe33d9fe, 0xbe09ae2f, 0xbdeb3223, 
    0x3c9421b1, 0xbe0932e7, 0xbe009d72, 0x3dfcccdf, 0x3e3c62c8, 0xbe1466b8, 0xbe0f9fbe, 0x3e2543a6, 
    0x3b989898, 0x3c902356, 0x3c180871, 0x3e1fcf11, 0xbd4a1d0b, 0xbc993f19, 0x3c1d98a9, 0x3dad0c9c, 
    0x3e38cff7, 0x3dec1ed2, 0x3dfdf822, 0xbcf6b29c, 0xbcb5dd5f, 0xbda5156d, 0xbe41f47b, 0x3e020291, 
    0xbd5dcbd3, 0xbe08ee09, 0x3da9c57f, 0x3deafec5, 0xbe308efb, 0xbe095fcd, 0xbd2220c0, 0x3d78d19d, 
    0xbbee21fb, 0xbd4f719d, 0xbdf74816, 0x3e0b89d9, 0xbe03ee4b, 0xbdd877c1, 0xbdda81ed, 0xbd4df44b, 
    0x3d0e1442, 0x3bf45005, 0x3e043187, 0xbdfb082b, 0x3e402657, 0x3d9d760b, 0x3d9c43fc, 0xbe016bcb, 
    0x3d56b746, 0xbe0ada05, 0xbe20bebf, 0xbd0a93cf, 0x3dd0756a, 0xbd524c55, 0x3c2b673d, 0xbd1d28ad, 
    0x3dbd59a3, 0xbe067ed6, 0x3e36a763, 0x3cefa180, 0x3d8cff53, 0xbdaaa32f, 0xbd7a49c1, 0x3db2a390, 
    0x3d314b65, 0xbac7ccfe, 0x3dc26584, 0xbbafb0a3, 0x3dbe2f38, 0x3e0dd32d, 0x3dcf7ae3, 0x3cd4d884, 
    0x3cd5fbf5, 0x3dc1740f, 0xbe21c61b, 0x3e10fce4, 0xbe129410, 0x3d2dd4b4, 0xbe13ea5d, 0x3d89a54c, 
    0x3dc09678, 0x3dc54ead, 0xbd2832e5, 0x3e1b4169, 0x3d728b16, 0x3d62de02, 0xbc07a36c, 0xbd9c72c2, 
    0x3d57df4e, 0xbd0d69f7, 0xbcc8c756, 0x3d0968cd, 0x3e3dd6d7, 0x3deaba3f, 0xbddfb830, 0x3d0d0a5c, 
    0x3e02aa65, 0x3dbab499, 0xbdbf1be1, 0xbd704084, 0xbd8f03aa, 0x3e2aed15, 0x3d8f7815, 0xbe2e4f1a, 
    0x3d442726, 0x3debda9e, 0xbe1f5a8f, 0xbe166f50, 0x3d5576ee, 0xbe2d2b04, 0xbbf63c06, 0xbd89aa6c, 
    0x3dc38ab3, 0x3e095781, 0xbe137d4a, 0xbd44b19b, 0x3d7c11c6, 0x3da6f877, 0x3e240894, 0xbdeb5de4, 
    0x3d3b63b8, 0x3d158482, 0x3ddbaa63, 0xbe27f8b9, 0x3d5360b8, 0xbd8bfbfb, 0xbd7b3cb0, 0xbd9840c2, 
    0xbcedffca, 0xbe00a0ed, 0xbda38314, 0xbc9b6329, 0x3e22440f, 0x3dc379af, 0x3e053d9a, 0x3d1310d3, 
    0x3e520509, 0x3da21ca7, 0x3e11fb8e, 0x3e1d1586, 0x3e0be338, 0xbb817fb8, 0x3d587f15, 0x3da494db, 
    0x3dd8603c, 0xbe040fb4, 0xbe0d0762, 0xbe03b2af, 0xbde8eac2, 0x3dbe17af, 0xbd92c0c5, 0x3d8d6058, 
    0x3dc138c6, 0xbe26eac6, 0x3daf0af0, 0x3e4437c6, 0xbe2b0bb2, 0xbccb1483, 0x3d50d679, 0x3d0d11d8, 
    0x3e4df398, 0xbdf87897, 0xbd85a760, 0x3d16768c, 0xbdc75ddb, 0x3d5e90c3, 0xbdbe362e, 0x3d00cf18, 
    0x3e4e3c74, 0x3e12e52a, 0xbdd9db94, 0xbdf7eb60, 0xbe1a8ee5, 0xbcab2de8, 0x3e04c53f, 0x3d3a4aea, 
    0xbe1932b4, 0xbd12ed4d, 0xbd089e24, 0xbe1f9400, 0x3c440854, 0x3e3e0f22, 0xbd4d26bd, 0x3e304886, 
    0xbd0b50f0, 0xbe1e680c, 0x3c2eeef8, 0xbe32531b, 0x3e2480ed, 0x3e3d47b4, 0xbd5212e7, 0xbc558db3, 
    0x3e222d18, 0x3b3326fc, 0xbcdef2bd, 0xbdd4eac4, 0xbda2d0b5, 0xbdfc1432, 0x3e16e502, 0x3c5da6bc, 
    0x3e21a991, 0x3e39da9b, 0x3dc1031a, 0x3cc4a754, 0xbcce8735, 0xbdf64690, 0x3da271ad, 0xbd0aeda8, 
    0xbe299c4e, 0xbcc99fd9, 0xbbb2acc8, 0xbe0e499f, 0x3e1fb095, 0xbc8fb111, 0xbe1e715e, 0x3e1f0a3d, 
    0xbdcaf165, 0xbcb42aaf, 0xbd9d5c60, 0x3d6506e0, 0xbd392fb3, 0x3c5a97ea, 0x3e4153ec, 0x3e37627c, 
    0xbdb1b744, 0x3bd6f490, 0x3de02e50, 0x3d97aa13, 0x3e0b917d, 0x3dca3433, 0xbd920b83, 0xbe124d1d, 
    0xbdd9a333, 0x3dd9266f, 0xbe18e566, 0x3d53b7ce, 0xbdc45db7, 0x399a58cb, 0x3d86d9d5, 0xbdbbcfc2, 
    0xbd442f95, 0x3d573d37, 0xbcb885bd, 0xbe1a974c, 0x3d29dd4e, 0xbe069bdf, 0xbdce2ae4, 0xbda8cbf8, 
    0xbd2f4b3b, 0xbd22aaa1, 0x3d884102, 0x3e103e58, 0x3cdd6704, 0x3d8f52a2, 0xbe1c258d, 0x3df8958c, 
    0xbdbd9337, 0xbe2d0c75, 0xbdec4ea5, 0xbe3c8289, 0xbe2c6412, 0xbddaa190, 0x3d9cb610, 0x3d7133f6, 
    0x3e14c7bf, 0x3dcea1a2, 0xbd1aa9b6, 0xbdd14074, 0x3d9920a4, 0x3e3e4b6e, 0xbd73b728, 0x3d1e2a52, 
    0x3e09413d, 0x3d5fc490, 0x3dfb902d, 0x3df41d2d, 0x3b02e494, 0x3e3967a5, 0x3c99d94f, 0x3a0d6f7c, 
    0x3dddf0d0, 0x3e3796cb, 0xbd573d07, 0xbd883a5a, 0x3d45098a, 0xbc9ed0c1, 0xbdd9217d, 0x3bdba145, 
    0xbd6bdae4, 0xbdc6c851, 0x3df675a7, 0xbdaf6aa1, 0xbd2d45db, 0x3c35759d, 0x3e0211ea, 0x3d8a5dda, 
    0xbe0c8ae6, 0xbd0245a1, 0xbd61e1b2, 0x3e1f90bc, 0xbe543f99, 0xbd493af1, 0xbb4497c0, 0x3dd5bd4e, 
    0x3dbafe74, 0x3d7be2f8, 0xbb83eb52, 0xba928d65, 0xbba7b80f, 0xbe17f6b9, 0x3dcb7b57, 0x3c908ff3, 
    0x3e078994, 0x3db0345d, 0xbe03a2a5, 0xbe24e51d, 0xbd8792c3, 0xbd91d8d2, 0x3e2a3b3f, 0xbdfb286b, 
    0x3b91c4ef, 0xbccb0088, 0x3da19d81, 0xbe271325, 0x3e2c9deb, 0xbe26124d, 0x3ddb51af, 0x3d4260ed, 
    0xbd8739f4, 0x3db9d150, 0x3d95506a, 0xbce26d90, 0xbca2200d, 0x3dd8c0b5, 0xbe1a7236, 0xbe3180a1, 
    0x3d19e604, 0xbc2c5d01, 0x3c8a068f, 0x3e2de889, 0xbd9b7c05, 0x3e198c32, 0xbb904109, 0x3e2e46c9, 
    0x3dc69702, 0x3d04c775, 0xbd73a334, 0x3db4bddf, 0x3cd22e56, 0x3dc757ad, 0xbcba7b03, 0x3d997d46, 
    0x3ddc5134, 0xbd363a00, 0xbe04408b, 0x3db34f0f, 0x3cd6bef1, 0x3e05a715, 0x3df0775b, 0xbcfd3894, 
    0x3c6bfbff, 0xbe38e72f, 0x3e30fc35, 0x3ccff1e7, 0xbdb3130c, 0x3e2bbb26, 0xbd52ebe9, 0xbe2b4a48, 
    0xbdc90489, 0x3d70b744, 0x3cae2e15, 0xbdfafa95, 0x3e510436, 0xbe05971c, 0xbcfa6441, 0x3e040442, 
    0xbe526524, 0xbdea7165, 0x3d91d241, 0xbd757502, 0xba1ebcac, 0xbde80cac, 0x3e005aa9, 0x3c456f32, 
    0x3e066fde, 0x3d58a390, 0xbe36c283, 0xbde93af3, 0xbc859708, 0xbdc59502, 0xbe00529b, 0xbd3b6ada, 
    0x3d0a5972, 0xbe10998b, 0x3e23803f, 0x3e1d6d3b, 0x3db94d58, 0xbabedf98, 0xbe188821, 0x3db2b8ed, 
    0xbdfa69fb, 0xbe017e48, 0x3db1af6c, 0xbd23e402, 0x3d10e35e, 0xbcc5b376, 0xbda57eb5, 0xbd8fc5f5, 
    0xbd8f6bb1, 0xbe2cb879, 0xbd4ce64d, 0xbdcc69fe, 0x3d093346, 0x3c0bbd70, 0x3b5d2549, 0x3dfcf554, 
    0x3da48d99, 0x3e0bfba7, 0xbb4634ea, 0xbd1da696, 0xbcc092a6, 0xbd931030, 0x3e14c1a0, 0xbe020063, 
    0xbe532422, 0x3cf9c703, 0x3dc980fb, 0x3d97233a, 0xbdae78ea, 0xbe15f9b5, 0x3e2698e3, 0xbdf08e6f, 
    0xbd75748e, 0x3d38c2df, 0x3dd8f112, 0xbe39e581, 0x3be1b274, 0x3b769421, 0xbc8ee89d, 0x3df40ab5, 
    0xbc857b32, 0xbd0233e3, 0x3e247d9d, 0x3e31e311, 0x3df5327d, 0x3cc0e276, 0x3e28988d, 0x3d21fd6f, 
    0x3d27cd83, 0xbcbfa42f, 0xbdc30c70, 0xbe2d8c1e, 0x3e024f61, 0x3e26cbf1, 0x3d4953d1, 0x3e258fae, 
    0x3e39a452, 0xbe42fda3, 0xbe0f7584, 0x3d6838d6, 0x3b5bb34d, 0xbd8379ce, 0x3d9777ff, 0x3d19c228, 
    0xbe30a192, 0xbe1b4826, 0x3de24159, 0x3e3e4485, 0xbe2fb02a, 0xbe0d9602, 0xbe2fb46a, 0xbda8b451, 
    0x3d7c812d, 0x3cd45817, 0x3dff49e3, 0xbbbfda49, 0xbe11d39b, 0x3df551a5, 0x3d9bed3a, 0xbdbe8c68, 
    0xbe2608cf, 0x3e265d80, 0x3e133250, 0xbe3400df, 0xbe0d5930, 0xbc6a97a7, 0xbe400a89, 0x3de03aed, 
    0xbe3d36e1, 0xbbb1a0fe, 0x3d9d2dba, 0xbd76a08a, 0xbdadd1aa, 0xbe46444b, 0xbde6aa85, 0xbdad8111, 
    0x3e2cce53, 0x3cc715f1, 0xbb87fc4b, 0x3dd31c2c, 0x3d3eb1f3, 0xbdc79caf, 0x3e156b57, 0x3da83fcb, 
    0xbca715ac, 0x3e20db1d, 0x3d9f0b7c, 0x3e29f6cb, 0xbdf61046, 0xbe28ba2b, 0xbe31b40b, 0xbd53de32, 
    0xbdf62fde, 0xbd6fdfcd, 0xbdcb2d05, 0xbdf36b9d, 0x3db9519d, 0xbe3a44b3, 0xbe378512, 0x3e254ae1, 
    0x3e03874d, 0x3e38e56b, 0xbe3700e5, 0xbcbc133c, 0xbd571ca6, 0xbe19d010, 0xbe27b1d9, 0xbd8b1d4d, 
    0xbe04436f, 0x3de0f2e6, 0xbc5d6edd, 0xbd43737a, 0x3dbe6590, 0xbd48ab2d, 0xbd969b73, 0xbe325645, 
    0x3d847893, 0xbe102cd4, 0xbe29e84b, 0x3da51390, 0xbe1b4e4c, 0xbdefc9eb, 0x3db5b44b, 0x3d9c2b97, 
    0xbe31eb97, 0xbe139a47, 0x3e284ccb, 0xbdf967da, 0x3cfbff09, 0xbd860bf8, 0x3dc06dac, 0xbe2b19d9, 
    0x3df15d50, 0xbda5dbff, 0xbd69a4f2, 0x3c9efb10, 0xbe0bcd39, 0xbe320aa9, 0xbd4e5fc5, 0x3b0cb8b2, 
    0xbc2109ec, 0x3d9f0e8e, 0x3a26f3fd, 0xbe1f4661, 0xbd12feaa, 0x3d83551d, 0x3e35043d, 0xbe1ab4f7, 
    0xbd8a9bc1, 0xbd924e96, 0xbe013632, 0xbc571895, 0xbd58409b, 0xbd278153, 0x3d09dd8d, 0x3cb9a234, 
    0xbd7df756, 0xbe22b6f1, 0x3dceed9a, 0xbc9dece7, 0x3e069bb7, 0x3dd33455, 0x3de1a71f, 0xbd03c48d, 
    0xbcea57fc, 0x3e29a6c5, 0x3ddb79c4, 0xbdfa843a, 0xbdb29619, 0xbe0a41eb, 0x3c43ea82, 0xbe266e39, 
    0xbd9ada4f, 0xbe1e37d2, 0x3e1851e4, 0x3dfd488e, 0xbcdee7a5, 0x3d6f5152, 0xbcd89a5b, 0x3e42a311, 
    0x3d785675, 0x3e191ed6, 0xbd54ef1b, 0x3cee7ea8, 0x3e34e248, 0x3e028c55, 0x3d593575, 0x3d901e51, 
    0x3db06f1e, 0x3e1cba97, 0xbe28d65a, 0xbd92ee06, 0xbcde9524, 0xbdf54203, 0xbe1603f6, 0x3dfa061c, 
    0x3d58b7f9, 0x3cdaf4bd, 0xbd0df03f, 0x3de6acf1, 0xbd126ea5, 0x3d420974, 0xbe2623bd, 0xbbdae05a, 
    0x3e20fc1e, 0x3df747b7, 0xbdd2d163, 0xbcdfc2c9, 0xbdf620d4, 0x3e1021a7, 0xbe339816, 0xbe28c5bb, 
    0xbd336e47, 0xbd88670e, 0x3d7f2f8d, 0x3d11e79b, 0x3d523b41, 0xbe15dbb4, 0x3d27fedf, 0xbd59b410, 
    0xbc460d7b, 0x3d8d6353, 0x3e0dfc49, 0x3e2f51a0, 0xbc2594c7, 0xbc07dbf8, 0xbdff7d1a, 0xbde90ff4, 
    0x3d420523, 0xbd5eaa63, 0xbe41c56d, 0xbdd15161, 0xbd9602ba, 0x3e2e33cf, 0xbe0124f1, 0x3d8bacd9, 
    0xbd91692a, 0xbe14eb04, 0xbdc572e5, 0xbe423b07, 0x3dcef6a1, 0x3cecfa6b, 0xbdeffc67, 0xbd4146eb, 
    0x3e017860, 0xbd6af9af, 0xbddb20b0, 0x3e0fb707, 0x3e0795d9, 0xbdb63914, 0x3e09cc60, 0xbbea20de, 
    0x3ca1eb99, 0xbb5f03e0, 0xbd6987c6, 0x3dfd2f25, 0x3d4b6d5f, 0x3cb20d14, 0x3d85d43e, 0x3e1b1d69, 
    0x3c0da0d3, 0x3de62b7a, 0x3d838ab4, 0xbd1baaa3, 0x3cded33a, 0x3d9f2c4c, 0xbe1b5651, 0x3e087409, 
    0x3e28e803, 0xbd091a3a, 0xbd9f4811, 0x3d5179ee, 0x3e3b906a, 0xbe25d500, 0x3e009b36, 0x3e1a8857, 
    0x3cadfdfc, 0x3cb0c5f2, 0x3cb23f65, 0x3e1de6e2, 0x3e124c09, 0x3e2a0661, 0xbb2ae1d2, 0x3e26919b, 
    0xbcdf863b, 0xbdab3876, 0x3e0ea4f3, 0x3dfe96d2, 0x3d5c883b, 0xbe273b58, 0x3db970dd, 0x3dc49e0c, 
    0xbe24a7d1, 0xbe0a5746, 0x3d9c3fa8, 0xbb77a775, 0x3db740ce, 0xbdc9afe7, 0x3e02a9bc, 0xbdf39bc0, 
    0xbe263059, 0xbdd7ba25, 0xbd097268, 0xbd7bec6a, 0xbe03a659, 0xbdfad660, 0x3e1b6921, 0x3dc3c9f7, 
    0xbddf37e9, 0xbade173b, 0xbcc994e4, 0x3e37656c, 0xbe1faac0, 0x3d8a7531, 0xbdc6e759, 0xbe00a660, 
    0xbd5e4f92, 0xbdb4d3f6, 0xbd8dfbae, 0x3e297b52, 0x3dd51590, 0xbd3132a1, 0x3e06a8a7, 0xbe3daa8a, 
    0xbbf800ef, 0xbdc6d492, 0xbdef268d, 0xbd9dddfd, 0x3d91208b, 0x3e094e51, 0xffffaaf6, 0x00000004, 
    0x00000010, 0x00000001, 0x0000000c, 0x00000001, 0x00000018, 0xffffab12, 0x00000004, 0x00000010, 
    0x00000001, 0x00000001, 0x00000006, 0x00000018, 0xffffab2e, 0x00000004, 0x00000010, 0x00000001, 
    0x00000006, 0x00000001, 0x00000020, 0xffffab4a, 0x00000004, 0x0000000c, 0x00000001, 0x00000003, 
    0x00000020, 0xffffab62, 0x00000004, 0x00000034, 0x3c05497f, 0x3b2975a7, 0xb755b928, 0xbc367cdd, 
    0x3bcd9c0b, 0x3b34d629, 0x3bad329a, 0xba850eb5, 0xbac03873, 0x3be6240b, 0x39dbeb4b, 0x3ac925f4, 
    0x3b6a5649, 0xffffaba2, 0x00000004, 0x00000750, 0xbe2db8f1, 0xbd7f18d9, 0x3cb737b8, 0xbda38dc8, 
    0x3e06d78b, 0xbc66e975, 0x3c8aec89, 0x3deec4a7, 0xbd5e3882, 0xbd71469c, 0x3a299fba, 0x3ac1565e, 
    0xbb1d9914, 0xbe0c3432, 0xbc1183bf, 0x3d8bd517, 0x3d539416, 0xbc40db47, 0xbd34c444, 0x3b164ec7, 
    0xbd9ca342, 0x3d57b774, 0x3a4bf26a, 0xbd5c194e, 0xbe097b13, 0x3e084a5b, 0x3df109ed, 0xbd0418db, 
    0xbdd3706a, 0x3d596378, 0xbdee2ece, 0x3de0cffb, 0xbc8f0e09, 0x3e31b507, 0x3d575d14, 0xbda4db9d, 
    0x3da95070, 0xbdb76eed, 0xbe152573, 0xbe0e7845, 0xbe8179eb, 0xbd986d12, 0x3ee364eb, 0xbebbbc9e, 
    0x3ecee8b5, 0xbecf04ce, 0xbe9e7708, 0x3d24e009, 0xbdced499, 0x3e260067, 0x3d92bcb7, 0x3e09b4b1, 
    0x3e87c58b, 0x3e9ffbb7, 0x3eac6770, 0xbd4832ec, 0x3e971748, 0x3cfeed45, 0xbe8b3954, 0x3edf95cf, 
    0xbeb93b27, 0x3e7c0473, 0xbdd2b548, 0x3eba6794, 0x3e245bee, 0x3e79dbaf, 0x3d7f4418, 0x3e9c2716, 
    0x3d35b004, 0x3d89a7b3, 0x3ec0e9c2, 0xbe4a7583, 0x3df40778, 0x3ea347e2, 0x3de3294f, 0x3da32f33, 
    0x3e68c7fb, 0x3e4dc08a, 0x3dbb0067, 0x3c9e1b72, 0xbdce26d4, 0xbddfe0e9, 0x3c985f26, 0x3e3ae28e, 
    0xbe5f042f, 0xbe8016d8, 0x3c8a0621, 0xbd28558c, 0xbea8044b, 0x3d29cd36, 0x3e9a392c, 0x3eab6d4e, 
    0x3e6333f8, 0x3dc5f0f3, 0xbd07a142, 0xbeb28462, 0x3d070a73, 0xbe1d6ced, 0xbe8d84d4, 0xbeabaa38, 
    0xbc8b4b26, 0x3ec9ff80, 0x3cd4bc93, 0x3ca1d6e6, 0xbe14e5ea, 0xbd18f9e3, 0xbd870bbe, 0x3ea2efa8, 
    0xbe179432, 0x3e32cf13, 0xbec17ce8, 0xbcf19f5f, 0xbe8e35b5, 0x3d54296f, 0x3eb20b5a, 0xbe8996a7, 
    0xbe8b2ca3, 0x3d9ee1f2, 0xbbc2fade, 0x3e4bd736, 0xbd3f2f85, 0xbd836b54, 0x3e1f6924, 0xbe311dfc, 
    0x3e39d1be, 0x3d5b911b, 0xbe53365d, 0xbe3a1be6, 0xbcc6d88f, 0x3e065e67, 0x3e001d01, 0xbe04aee4, 
    0x3d9c5f12, 0x3deafb6c, 0xbd16fbc6, 0xbcc3c2b3, 0x3dc0efbc, 0x3e63b8c1, 0xbda5c1ff, 0xbd7fbf42, 
    0x3c1e8169, 0x3daab69a, 0x3c3a0eb7, 0x3ba2e6bc, 0xbd7c0d96, 0xbdfdee49, 0xbd1ab15b, 0xbe0011f9, 
    0x3debe714, 0xbc602028, 0xbde1a322, 0xbdf7dd96, 0xbdbde204, 0x3d9f6b83, 0x3e3d31e1, 0xbd648b17, 
    0x3d2680f8, 0xbcb4170d, 0x3dae7048, 0x3e3c5c9f, 0xbe1620e8, 0x3e0b757f, 0x3d8c0385, 0xbe60642d, 
    0x3e6aaf20, 0x3e421bb5, 0x3dc73f26, 0xbe4fe2bb, 0x3e43087d, 0x3e2cec49, 0xbdff1f8a, 0xbe31df34, 
    0x3e100726, 0x3db5992d, 0x3d9284b0, 0xbe02f5e7, 0xbd997336, 0x3dbc0aeb, 0xbe6b7726, 0x3da71229, 
    0x3e04d501, 0x3cb9702f, 0xbe1a45bf, 0x3df5ff82, 0xbe2fbdf8, 0xbd8c32fe, 0xbe552579, 0xbe59188d, 
    0xbe30776c, 0x3ca516fd, 0x3e031d9b, 0x3e1fa623, 0x3e806d61, 0x3e2caa77, 0x3e378e27, 0xbe8bb1e6, 
    0xbe6d867d, 0x3ee1275b, 0xbeb98415, 0xbeb0cc54, 0x3e1deab2, 0x3e95a361, 0x3e80f272, 0xbd148d68, 
    0x3d39905b, 0xbd29ec4a, 0x3dd543b0, 0x3e7ae1a4, 0xbd8995b8, 0x3e1b6785, 0x3eaeb908, 0xbed2d35c, 
    0xbdc5bcb0, 0xbe873941, 0xbe6e44a8, 0xbece07c0, 0x3d90019e, 0x3d891865, 0x3e719ab2, 0xbe9101ae, 
    0xbd874b05, 0xbeb6ff6c, 0x3e361efe, 0xbe489d80, 0x3b48462b, 0xbeaf49ca, 0xbeabae5a, 0xbdc2ec61, 
    0xbeab1988, 0xbe3a4df5, 0xbebaecf1, 0xbdae25bb, 0xbc324e36, 0xbe1ef4c0, 0x3e0716ef, 0x3ca01219, 
    0xbe025b78, 0xbe242d43, 0xbd41b1f7, 0xbdabfb43, 0x3da65035, 0xbdc48104, 0xbc2706a6, 0xbde5a18c, 
    0x3cc9274f, 0xbe13147a, 0x3df50075, 0x3d72236e, 0xbdada6d9, 0x3d96a604, 0xbddf93f0, 0x3e119a9e, 
    0xbdeae3b0, 0x3d3a9668, 0xbd69f0c5, 0xbd26a7ae, 0x3e22a0f7, 0xbc9dd42c, 0xbe212100, 0x3cab62da, 
    0x3e330d67, 0xbd977cfa, 0xbd91cf62, 0xbd0e33c4, 0x3db60215, 0x3d92384e, 0x3e30507a, 0x3d37b120, 
    0x3e1e6e3a, 0x3d98bbe6, 0xbd17ca5b, 0xbe088394, 0x3dfc580c, 0xbd7badb6, 0xbe24f6eb, 0xbdaba95b, 
    0x3d4ce9ef, 0xbdce5ee4, 0x3db3d61d, 0x3d2e65dd, 0xbdd4cc75, 0x3e0029eb, 0x3d5f0b59, 0xbdd8f47c, 
    0xbe124e44, 0x3d9b47f6, 0x3e1a865e, 0xbc6052f1, 0x3e000ec7, 0x3de6742e, 0x3de52ba4, 0xbe04a20e, 
    0xbdd14703, 0x3d0f745e, 0x3ddb09a1, 0xbe0e0b9f, 0xbd07a1e9, 0xbe1ed47e, 0x3d1a37ab, 0x3dc24baf, 
    0x3c2fae1d, 0xbe282533, 0xbd58949a, 0xbd637b4f, 0x3c3c9133, 0xbddc31ff, 0xbda2f554, 0xbd920881, 
    0x3d0d67bc, 0x3dacfbd8, 0x3d387e88, 0x3e09ca62, 0xbe2f072d, 0x3e89780b, 0xbe5c893f, 0x3e4872c5, 
    0xbe6e1499, 0xbe1a7238, 0x3e2b39e2, 0xbe17e1cb, 0x3e1df3fa, 0x3d8edad6, 0x3e4633c9, 0x3e6df75e, 
    0xbe6856d1, 0x3c281b48, 0xbe1e2ba8, 0x3d4e2a22, 0x3e0a1342, 0xbe4a6371, 0x3e44e18e, 0xbdb4b841, 
    0x3e71eec9, 0x3d8c759c, 0x3d8e1747, 0xbe9334b3, 0xbe441708, 0x3e88674d, 0xbe9e0f67, 0x3d040cc4, 
    0xbe8af688, 0x3e6df810, 0xbde5b0e1, 0xbe08e1b7, 0xbe921b80, 0xbe3baf5f, 0x3e920c75, 0xbdfd1094, 
    0x3bff0689, 0x3e466e7a, 0x3e969c8d, 0x3e2585e2, 0xbe6a2436, 0x3ec54469, 0xbe69a900, 0x3e6c90ec, 
    0xbd7d6b3b, 0x3e9aaa8e, 0x3e32be8a, 0x3e7df8f2, 0x3da20c34, 0x3e861ba1, 0x3ea46300, 0xbee4266c, 
    0x3dd583e6, 0xbd900f50, 0x3ed8323d, 0x3ea06bfb, 0xbed2f5c3, 0xbd7bf0a7, 0x3e1737cb, 0x3eda9a3c, 
    0xbeb0c561, 0x3dbf6b8d, 0xbdcd9269, 0xbe4756d8, 0x3d5a8415, 0x3e31233d, 0x3e890e06, 0x3ced9ad6, 
    0xbd55acff, 0x3c9c8db2, 0x3ee7b30c, 0xbe96be73, 0xbe2ba806, 0xbdd103b9, 0x3e40a2a5, 0xbe2b84d6, 
    0x3ddf0c5c, 0xbe73ad86, 0x3db3456c, 0xbd00889b, 0xbbe1f59a, 0x3dfa9e9a, 0x3e58c3af, 0xbdc5044f, 
    0x3e2b49c7, 0x3d0fe7ec, 0x3d917b16, 0xbe2e05ee, 0x3c2849ab, 0x3e2889ad, 0x3de84390, 0x3d17f8c1, 
    0x3dc6633f, 0x3d21ae53, 0xbe0c0904, 0x3de07a30, 0x3e5763c7, 0xbe3729c4, 0xbe71c36a, 0x3e492bdd, 
    0xbe4d9a7f, 0x3e4f8fdd, 0xbe5f1dad, 0xbab41d0b, 0x3c7db6fe, 0xbda02b21, 0xbd3a85ef, 0xbe26e5fd, 
    0xbdb58b7a, 0x3d4e0a48, 0x3e26789e, 0x3daa1d72, 0xbdb6f1b7, 0xbb161ab3, 0xbc8f675b, 0x3d59e12c, 
    0xbdd70dde, 0xbcb0cb39, 0x3da3e11e, 0xbc3db302, 0x3dae84b1, 0xbc878412, 0xbdcaebe5, 0x3e08cd05, 
    0x3ccc2100, 0x3be3a653, 0xbdbf0627, 0x3cbfe328, 0x3df930be, 0x3d1ff743, 0xbdef6ec7, 0x3d8469fe, 
    0x3dc394c3, 0xbdd147e7, 0x3e01efad, 0x3c71213e, 0xbd54efda, 0xbdef1625, 0x3e032f8e, 0xbd88b27f, 
    0xbda91553, 0x3d48c25a, 0xbddd0014, 0x3d43c87d, 0xbd08bb7f, 0x3df3e52a, 0x3d662a2c, 0xbd00cd56, 
    0xbdf04d41, 0x3d60391a, 0x3d822dbf, 0x3d4ac721, 0x3dc8b724, 0xbe0a348d, 0x3df29be5, 0xbd891906, 
    0xffffb2fe, 0x00000004, 0x00001b00, 0xbf3e0976, 0xbe83c153, 0xbf0ae4ce, 0x3f293f23, 0x3f45ffe7, 
    0xbf1f94e4, 0x3d423524, 0xbf5603bd, 0xbc850e42, 0xbef3c148, 0x3e8ca750, 0x3f11aca7, 0x3e52dec0, 
    0x3e9d207a, 0xbf5eecbf, 0x3f2cd860, 0xbef13f3c, 0x3ecc32c6, 0x3ed4f924, 0x3f013fd0, 0x3f63b45d, 
    0xbebb864d, 0xbf3ed04c, 0xbe5c39de, 0x3eb36302, 0xbebeece8, 0xbf0ff60b, 0x3f04d28b, 0xbf32eb76, 
    0xbf5086e0, 0xbf3a53f8, 0xbeaaa2bd, 0xbe91fc20, 0xbe23f821, 0xbe9f0192, 0x3c587ace, 0xbaf0374f, 
    0x3f26cfcf, 0xbf2f97e3, 0x3f450ea1, 0xbeef20dc, 0xbe4787ed, 0xbefedb94, 0xbe83baad, 0x3e2f4574, 
    0x3ef4b7aa, 0x3f59adb1, 0xbf52e895, 0xbebb5f43, 0xbee9bd35, 0xbf17d31b, 0x3dbcb7c6, 0x3eb2a609, 
    0xbf3cff19, 0x3ee3dbba, 0xbf57b52b, 0x3e984b3a, 0x3f5aa4b2, 0xbe98a806, 0xbf05f35c, 0xbf3fe6a9, 
    0x3dd0acdc, 0xbed176dd, 0x3eb18b34, 0x3f4a043b, 0x3f0d1b06, 0xbc712dc0, 0x3dd1d720, 0x3f2e2dd6, 
    0x3e007893, 0x3ee22358, 0xbdd024e3, 0xbf3d5f83, 0xbf2550f3, 0x3f253f4c, 0xbe7ed5a9, 0x3cb6fe3d, 
    0xbc9d0a3f, 0xbee154bc, 0xbed42df0, 0xbe62c4c6, 0x3f3c8ac3, 0x3f1db62c, 0x3d5706ea, 0x3e911632, 
    0xbda5381a, 0xbd61c5f5, 0xbf1700f3, 0xbf0a5841, 0x3e1481f2, 0x3ef61473, 0x3ed27913, 0x3e8d2ae4, 
    0xbf1d10d4, 0xbbb908bf, 0xbf287cd0, 0xbe86e85d, 0x3dab0b1f, 0x3f0efa51, 0x3f05a6b0, 0xbdcb98a5, 
    0x3e2b8694, 0x3e4223f9, 0xbe7a6f96, 0xbdfe01a2, 0x3e521402, 0xbf317597, 0x3eb43dd5, 0x3ea46f98, 
    0xbe166b97, 0x3f1be9f1, 0xbf11b203, 0x3ee99c79, 0x3ebea297, 0x3d9d3205, 0x3edb4cb8, 0x3f10120d, 
    0x3e85af76, 0xbe9d9c21, 0xbea0e0e4, 0xbec5cea9, 0x3edac7ce, 0x3dff91e1, 0xbe5e0b73, 0x3e68e1e0, 
    0xbf2e5bdb, 0x3ef8b7e1, 0xbe5198cf, 0x3e3fa681, 0x3e4eb518, 0x3f1d6afc, 0xb985dbec, 0xbdf9c2ec, 
    0xbdca36a6, 0x3f081d66, 0x3d49938e, 0xbd37cbd8, 0xbef6552c, 0x3c748e27, 0xbe8aee9e, 0x3f42241c, 
    0x3ee8fd53, 0x3f1fba41, 0x3f3804ec, 0x3e8942d9, 0xbe271f6e, 0x3eb34cf8, 0xbe389cf5, 0x3dd31ad3, 
    0x3e98bf04, 0xbe971260, 0x3ed74ae2, 0x3eb86b85, 0xbee59d81, 0xbeec0969, 0xbd7a8553, 0x3ec2f538, 
    0xbe77f891, 0xbe7bca3f, 0x3efcd5c4, 0x3f03a905, 0x3e05a71f, 0x3e4450d8, 0xbe42b273, 0x3ec050d7, 
    0xbe35367b, 0xbe725fa4, 0xbe39998b, 0xbe1379c5, 0xbe9a4472, 0x3e7292bc, 0xbdfec7e6, 0xbe168718, 
    0xbbde571f, 0x3e3f5fd7, 0x3e71d708, 0x3e4cfa9f, 0xbe68132b, 0xbedc11e1, 0x3e7a3d41, 0xbed3b354, 
    0xbea49c04, 0x3e28860f, 0x3e32d526, 0x3dec0d91, 0x3d56fae1, 0xbeb14c82, 0xbeceb3a0, 0xbec79077, 
    0x3e90f227, 0xbeafaf82, 0xbdb939da, 0x3d2e0b71, 0xbc61cfa0, 0xbd40c2f3, 0xbe34d5fc, 0xbed111c6, 
    0xbe5af046, 0xbe88ad83, 0x3e344361, 0x3efe7436, 0x3e4c3555, 0xbec71a47, 0x3c29f057, 0x3d8050a1, 
    0x3ed88bf8, 0x3ed7e34d, 0xbd617f11, 0xbe244062, 0xbd140256, 0xbdc00ea6, 0x3d889d38, 0x3e7f3e37, 
    0x3e41fd81, 0xbe4d6fcd, 0xbebe606f, 0xbe8eb41a, 0x3ecf0563, 0xbee28b44, 0xbee3b1c1, 0xbe01fefc, 
    0xbe88d5e7, 0xbef7356d, 0xbe93a5d4, 0xbeff81ab, 0xbd54c4e9, 0x3ed5ba4d, 0xbe7d3e6c, 0x3ea54317, 
    0xbe661b72, 0xbeb14b3c, 0x3ea378d9, 0x3eb7751a, 0xbd39aece, 0xbee52b1c, 0x3e4a59aa, 0x3ee4f2ad, 
    0xbe8c3b8f, 0x3cbb64b1, 0x3e33f5cf, 0xbdf7ac80, 0xbee0dde0, 0xbe993a98, 0xbe6d2acf, 0xbe49516c, 
    0x3da84857, 0x3eea40dc, 0x3eebaa56, 0xbefb715b, 0xbde9d10f, 0xbcccebe5, 0x3ec342e2, 0x3e69f6ff, 
    0xbf093b7e, 0xbeee238a, 0x3df1257e, 0x3df2abcf, 0xbe90d41e, 0xbdaae0d8, 0xbddf6c66, 0xbebd03cd, 
    0x3e67e960, 0x3c82a68b, 0x3ec67aab, 0x3e10d165, 0x3e51037b, 0x3ea61b09, 0x3e3d8ee3, 0x3ea48c9d, 
    0x3ea86e28, 0x3e453c70, 0xbe14a85e, 0xbe76508b, 0xbe272660, 0x3ed49755, 0xbee01fec, 0xbececc34, 
    0x3c7ff813, 0x3d3ec3ed, 0x3de9ba07, 0x3d8c6c2a, 0xbe55e3f6, 0x3e49f0a1, 0x3e381d5f, 0x3cfbe37c, 
    0x3ec51bf0, 0x3e53f49e, 0x3e3ec0a0, 0xbf156938, 0xbea5539a, 0xbf52e658, 0xbeb297b6, 0x3f2e1b9b, 
    0x3e70861f, 0xbe918e7f, 0xbf13bfb9, 0xbe26e8dc, 0x3ed80ea7, 0x3eb18349, 0x3f338f05, 0xbf0afd6d, 
    0x3e91f1e6, 0xbf10b012, 0x3d94aa4b, 0xbf1baee6, 0xbd7c9ce9, 0xbe19b3b9, 0xbf086bd0, 0xbd230c42, 
    0x3e3d3d26, 0x3ed0d67a, 0xbf0c0648, 0x3f43be1a, 0xbe85019a, 0xbea06540, 0xbf0f5515, 0x3f1019d6, 
    0xbece12fc, 0xbd114f3a, 0x3f58d821, 0x3f10855d, 0xbf4e8df3, 0x3f4d96f4, 0xbf303f84, 0x3e950b1b, 
    0xbf38a3e6, 0x3e235dcc, 0xbea1c69c, 0xbf4fbf29, 0xbbac6f14, 0xbd2018e6, 0x3e91461e, 0x3e41691d, 
    0x3eac7d70, 0xbf1f8c36, 0xbf086372, 0x3f3f6297, 0x3ef47221, 0xbe7bcc2d, 0xbe8c5351, 0x3f0ad9c0, 
    0xbef428e0, 0x3dec6e6d, 0xbf1acb9d, 0x3dda7f4f, 0xbf11f0da, 0xbee4cfdc, 0x3dea563c, 0xbee2cbfa, 
    0xbecba37b, 0x3f09e69b, 0xbf029880, 0x3ee4d1ab, 0xbe73435b, 0xbf26142c, 0x3f05bd62, 0x3ee2f4d3, 
    0xbf4b1bd5, 0x3dbeca08, 0xbe272700, 0xbcb8d1d2, 0xbeed2986, 0x3d3e6242, 0x3ef0b26d, 0x3ebf692e, 
    0x3eb8eda7, 0xbeb198d4, 0xbe8d093d, 0x3f024c4f, 0x3eb7d6e2, 0xbf24cd26, 0xbe69374a, 0x3f0f94fe, 
    0x3e907e5e, 0x3d51d799, 0x3f10406f, 0xbee1ca42, 0xbe611dc0, 0xbefeb73c, 0xbf08808a, 0x3efe97ab, 
    0xbecac5de, 0xbe143bc9, 0xbe23529d, 0xbeab8be7, 0x3ecf067c, 0x3ec71c59, 0x3e4d4e82, 0x3f13185b, 
    0xbf17596b, 0x3f1dd8b4, 0xbebd49b2, 0x3f20f19a, 0x3ed3426c, 0x3ee31cab, 0xbdcb2912, 0x3de57788, 
    0xbf09cfc0, 0x3ec5fcf8, 0xbd8e2b77, 0x3e27ecfa, 0x3f18cb0e, 0x3eb5e5ed, 0x3dbe1830, 0x3e8aeeb0, 
    0x3ec32083, 0xbf0858cd, 0x3ec5b5fb, 0x3e58e20a, 0x3de9f802, 0xbeef55fe, 0xbf241cf1, 0xbea536d3, 
    0x3e73eb6a, 0xbe95b012, 0x3de80089, 0xbec0332f, 0xbd1c2a62, 0xbf3431c7, 0x3efc5892, 0x3f01079b, 
    0xbebc394d, 0x3d50c181, 0x3eea489e, 0xbf1f6559, 0x3f161e4a, 0x3e754cdc, 0xbe9a5ad2, 0x3e80893c, 
    0x3eff7293, 0xbee2e45f, 0xbebef3d4, 0x3ed2e410, 0x3e833e13, 0xbec6f49f, 0x3f19ee74, 0xbe9a08c8, 
    0x3f1905d2, 0xbeb33165, 0x3ef44cb7, 0xbe57c26a, 0xbf0ba4c3, 0xbee986e0, 0xbefdcc06, 0x3ebe700d, 
    0x3f0d97dc, 0xbe672640, 0xbf05ce6b, 0xbd69b4a3, 0x3e6a2cb0, 0x3ecee0bf, 0x3ef97d8c, 0x3e793184, 
    0x3de91a2f, 0xbdb4aa0c, 0xbe991fa2, 0xbea38867, 0x3db64977, 0x3edced78, 0xbc7804bf, 0xbe24ee38, 
    0xbdd33e0f, 0x3ee2375c, 0x3d5fa991, 0x3f0091ab, 0xbeaefb96, 0xbeeccb05, 0x3ece43df, 0xbf059fe6, 
    0x3f067778, 0x3d09dade, 0x3e44344d, 0xbe8cef8d, 0x3da894bc, 0x3dda0588, 0x3f0a70b7, 0xbedee795, 
    0x3e72f8d4, 0x3e9bf314, 0x3d7c0d18, 0x3ef2710e, 0xbe3fb023, 0xbefd2c9c, 0xbe6fe1db, 0x3e8dd649, 
    0xbe4bdd1d, 0xbec19e07, 0xbdf6c4ce, 0x3bfb8954, 0xbeb9c26b, 0x3caa52f9, 0x3de862ce, 0xbea8dbbc, 
    0x3e4a4044, 0x3b44be47, 0xbdeb86b2, 0x3dfcf831, 0xbc190c92, 0xbceaa69a, 0x3d140644, 0x3f09f95f, 
    0xbe633122, 0x3ebaf343, 0x3e28b9c0, 0x3f41f706, 0x3e55de34, 0x3e2f0450, 0xbf1a1f24, 0xbf375bff, 
    0x3ede5b6b, 0xbddc5f85, 0xbf5fd74e, 0xbed9b4a2, 0x3e7708f1, 0xbe8fbd10, 0x3eabd4b3, 0xbceac89d, 
    0x3eb217a5, 0x3f31db1e, 0x3f436ff0, 0xbed87d71, 0xbf4ee221, 0x3f4ecf30, 0x3d0fac60, 0x3c06552c, 
    0xbf5208e7, 0x3eac7c47, 0x3f096783, 0x3f603263, 0x3ee2019b, 0x3ef0b35d, 0xbf46d191, 0xbe2088c4, 
    0x3f152138, 0xbe6905f7, 0x3eff41a2, 0xbf297924, 0xbe9f9161, 0x3d0b00b0, 0xbefdbb0d, 0xbf3b6558, 
    0xbf4da969, 0xbece68fd, 0x3d36b79f, 0x3d842ec4, 0x3f28228c, 0xbecfb35c, 0x3e11ff12, 0xbe8aeed0, 
    0xbea5da8d, 0xbf1c426f, 0xbe867f97, 0xbeca4a31, 0x3f1f4fc9, 0xbf54385f, 0x3de5c12d, 0x3f1f2ab5, 
    0x3f6ca0e0, 0xbeb69e98, 0xbf14eab9, 0x3f0504fa, 0x3ecbff55, 0x3e9f40ed, 0x3f2133ec, 0x3eddfa8d, 
    0x3debfd44, 0xbf461594, 0x3ebc0f67, 0xbed28a7c, 0xbd91fb05, 0x3ea90187, 0x3f375d20, 0x3f213b38, 
    0xbe454a8e, 0x3ea3374b, 0x3f2867d4, 0x3ea34403, 0xbf27a7cc, 0x3ee63a0c, 0xbf002359, 0xbea475dc, 
    0x3e9ed662, 0xbdc161ec, 0xbeaabbc1, 0x3e5df1b0, 0x3e593b94, 0xbf0edbe2, 0x3e1b10fe, 0x3ef4e77d, 
    0x3f285e72, 0xbc40f8bd, 0x3e7613b8, 0xbddcfc41, 0xbcc07804, 0x3e8394fe, 0xbe96eab6, 0x3a20dfdb, 
    0xbf282592, 0xbd850f69, 0xbf06a338, 0xbf011f4b, 0xbf1eb5b2, 0xbb0612b1, 0xbf2574d7, 0xbeb37f26, 
    0x3caa9ca9, 0xbe111c73, 0xbf2977c5, 0x3ed6acf2, 0xbe6e21e3, 0xbe8bd5a4, 0xbef7ca76, 0x3ec38873, 
    0xbe88eb0b, 0x3eb7b28b, 0x3ea941d6, 0xbf052929, 0x3ef5c30e, 0x3f28196d, 0x3f364610, 0x3f0cf1cb, 
    0xbedd7a82, 0x3ee9ac92, 0xbeecb89d, 0x3e99362f, 0x3eca09ea, 0xbf0ed9b6, 0xbf02668a, 0x3ea5106b, 
    0x3e9ab5b4, 0xbf07683d, 0x3e59be4b, 0xbd7b653a, 0xbf20aecf, 0x3d77e945, 0x3e4af0da, 0xbebd446d, 
    0x3f1b5f22, 0xbed43552, 0xbea067b4, 0xbe34001f, 0xbf1fe544, 0x3e1014c9, 0x3f2b31a1, 0x3e600bdc, 
    0x3ec14953, 0xbd9c70a5, 0xbed312b1, 0x3f03ae11, 0x3e868614, 0x3ebb1f27, 0xbdae8bf0, 0x3ec2f299, 
    0x3e0f458b, 0x3f08109b, 0x3dc8e9ee, 0x3d1b2d4c, 0x3ee88b55, 0x3ed1c367, 0xbef89601, 0xbf0a5d25, 
    0xbe422bd3, 0xbeb06d5e, 0x3e1b1fe3, 0xbf05b789, 0x3c8ec19c, 0x3dbdbb8d, 0xbef1f759, 0xbe1a5f61, 
    0x3e87a42c, 0xbf007c6d, 0xbe854ba6, 0x3d8a0dbb, 0x3f02421f, 0xbea0571b, 0x3e996b51, 0xbea08a3c, 
    0x3d136534, 0x3f00aa09, 0xbea7ffe0, 0xbec30a07, 0x3cfd20fa, 0xbd012455, 0x3e85c4d4, 0xbdbafa1c, 
    0x3edefdd5, 0xbe915a13, 0xbf17991c, 0xbb436896, 0x3edb01e9, 0xbbbc1f43, 0x3ecd6495, 0xbea5a1b0, 
    0x3e09fefe, 0xbe3010d4, 0xbf018bb4, 0x3d7e0fcc, 0xbd6801ea, 0xbeda7e47, 0x3ecc8236, 0x3e6f4813, 
    0x3e90e2e6, 0x3ec25a64, 0xbeb76592, 0x3e69aecf, 0xbe808330, 0xbf11df7b, 0x3e91967c, 0x3db4771a, 
    0x3d30fe27, 0x3e626a20, 0x3e219d70, 0xbbc8cacb, 0x3edb9bea, 0x3ee47b6f, 0x3eddf285, 0xbefcb468, 
    0xbee1c6a3, 0x3f03ffde, 0x3e461b31, 0x3e0958f7, 0xbe9c65de, 0x3f19b69e, 0xbe0e47bf, 0x3f23a602, 
    0xbe960d10, 0xbf6117ee, 0xbdf4d762, 0x3e1cfad6, 0x3edf14ce, 0xbf617f64, 0x3e4e541b, 0x3f663d8f, 
    0xbeda95b6, 0xbf0a66ec, 0x3dd6d430, 0x3e921291, 0xbea612fc, 0x3eb6212b, 0xbe038429, 0xbec5cd47, 
    0xbf3fff83, 0xbf0e205a, 0xbf36b5d9, 0x3ea0c3fd, 0x3e1ff895, 0xbf54b9db, 0x3e28c6a1, 0x3f4b6408, 
    0xbeb5fc77, 0xbea08756, 0xbed54780, 0x3ebf5c06, 0xbf3e58ba, 0x3c54c0c0, 0x3f2de66f, 0x3f046951, 
    0xbe94a7de, 0xbdfb5130, 0x3e535dab, 0x3f644233, 0x3f413e0c, 0xbef6afc1, 0xbf406606, 0xbe38a3b0, 
    0x3f093301, 0xbef85037, 0xbdf3cca0, 0xbf0ca999, 0x3ef8decc, 0xbf62dd9f, 0x3f23dfdd, 0xbf63d36a, 
    0x3f06fad8, 0xbe66bca8, 0x3e3478b5, 0xbe5f0d19, 0x3f368488, 0x3e566a4a, 0xbf50bc09, 0x3f76a48f, 
    0xbedb5013, 0xbf386e4f, 0x3f4221bb, 0xbf596de3, 0xbf40055a, 0x3f5c73ae, 0xbf657809, 0xbf556eb9, 
    0x3f1eb1b5, 0x3f0ecbe9, 0x3f08318f, 0xbf108217, 0x3eccb40e, 0x3e83a590, 0xbe4297cd, 0x3eaf7468, 
    0xbed0f168, 0xbec4e353, 0xbcf15036, 0xbd8c228b, 0xbe8aa8a0, 0x3ef0aad9, 0xbed63f39, 0xbef8f683, 
    0xbf195601, 0x3e9afdfc, 0x3f086171, 0xbe6dd896, 0xbe09f07f, 0x3eb5ce18, 0xbda413ba, 0xbd8d695d, 
    0x3f0cd15c, 0x3e12ff3f, 0xbe3cb00a, 0xbe73a04a, 0x3c45fb9c, 0x3ccaa0a1, 0xbe7251aa, 0x3eef92a8, 
    0xbe21e5c6, 0x3d826498, 0xbe315de5, 0x3ea2134e, 0xbec5b898, 0x3eab63f5, 0xbec31fa8, 0xbec2cd46, 
    0xbe32e38d, 0x3e844fca, 0x3e0c4dfe, 0x3d2f0226, 0xbf09ea8d, 0x3f0fcc03, 0xbe88773e, 0x3bfcface, 
    0x3ee4fc87, 0x3e411c2c, 0x3df290c8, 0x3e85a44c, 0x3d9411a8, 0x3f0348dd, 0xbddccd77, 0x3d689779, 
    0x3e95b18d, 0xbf102a23, 0xbf06c1da, 0x3e4f18b7, 0x3f0d09e1, 0x3e12c953, 0x3de011e0, 0xbf0796ed, 
    0x3e96f424, 0xbf003e69, 0xbdcd4ff6, 0xbedbe148, 0x3e24f5b8, 0xbec6d913, 0xbd9df8f5, 0x3d290a12, 
    0xbe2c5404, 0xbee89ac8, 0xbe81838e, 0xbe7b020c, 0xbeb27e8e, 0xbe9eebec, 0x3ca05b74, 0xbf33a915, 
    0x3f20520b, 0xbf18442c, 0x3f1515f5, 0xbd58c878, 0xbdafb43e, 0x3cf829e4, 0xbf10b97e, 0x3f23a35b, 
    0x3f3a10bd, 0x3f269703, 0xbe60ac07, 0xbea7b74e, 0x3dccdbed, 0xbf2d8b27, 0xbf26355f, 0x3efcd41a, 
    0x3e32dfe0, 0xbdd4329e, 0x3e22f242, 0x3f1b7cda, 0xbf2ae6d4, 0x3d85f79d, 0xbb8d8347, 0x3f104bd4, 
    0xbea07c00, 0x3e4122a0, 0x3e80ce45, 0x3d5f6160, 0xbf32a9f6, 0xbec0d42d, 0x3e0e5ef3, 0x3f08996a, 
    0xbe708907, 0x3d679f14, 0xbf33425c, 0x3f176f01, 0xbe3197eb, 0xbedbd8e7, 0xbcfa13b7, 0xbefbcf20, 
    0xbef7d1d2, 0xbed6c8a5, 0xbec134a3, 0xbdec0b14, 0x3caeb46e, 0x3ebce5b3, 0xbdf1a17e, 0xbe83b5b4, 
    0xbbe029a8, 0x3ed225d2, 0xbe07f8b0, 0xbf1f5453, 0xbf037029, 0xbd8138c4, 0x3f2f0dac, 0x3dd20787, 
    0xbf22b54d, 0xbedc5aaf, 0x3e3dee4a, 0x3ebef3fc, 0xbec52fc3, 0x3e47289e, 0x3eb7876f, 0xbf114b32, 
    0xbe3335c1, 0x3ee4a4aa, 0xbdf0301d, 0xbf3c1dc9, 0xbf079045, 0x3f54d183, 0xbef914d6, 0xbf03a3f6, 
    0x3f1f04a4, 0xbf295b44, 0xbb45babb, 0x3e014d56, 0x3ecf331d, 0xbf1faf0a, 0x3f0fa00f, 0xbe3396e0, 
    0xbed72603, 0x3f07588c, 0xbf5e2e17, 0x3e67a62a, 0x3f22bae0, 0x3dc4c0d5, 0x3f3a3bc4, 0xbda63859, 
    0xbf174884, 0x3ed72bf5, 0x3f0aca64, 0xbf2a691d, 0xbe7f06b2, 0xbe33ef60, 0x3eb66a39, 0xbe0a49c9, 
    0x3f5d5f17, 0x3f0633b1, 0x3f2ce0cf, 0x3f215504, 0x3f54c6fe, 0x3df5de43, 0xbe4f3e6d, 0xbf37636f, 
    0x3d8e7bb2, 0xbe7f93f3, 0xbee64b6e, 0xbef7e77b, 0xbf07affb, 0xbf38085c, 0x3e1998ae, 0xbf01e7e8, 
    0x3f07f669, 0xbe94cb60, 0x3f26a408, 0xbd9e5be4, 0x3e972c79, 0x3f527953, 0x3f53aa20, 0xbf233328, 
    0x3f5944d9, 0xbeaae3ec, 0x3f2ae16b, 0xbf24ae88, 0x3ef74a4b, 0x3f67dc87, 0x3f30953b, 0x3f130d25, 
    0xbec3428a, 0x3f020b05, 0xbf406a4b, 0xbe33f0d3, 0x3f5a2fee, 0xbf486e67, 0xbe347762, 0xbd6ee5c3, 
    0xbf0407fa, 0xbf15898d, 0xbf385fa2, 0xbea82398, 0x3e593195, 0xbe605640, 0xbed129da, 0x3dbcc4a1, 
    0x3f469147, 0x3efd3ff4, 0xbf07f9f0, 0xbe751471, 0xbf1e600f, 0x3e4c9b89, 0x3dc480e9, 0xbf121db2, 
    0x3dbb804f, 0x3ee39984, 0xbed05f64, 0xbd962c51, 0x3e80e023, 0x3f0d2d63, 0xbdc8f4c7, 0xbee6e62f, 
    0xbd32cc1d, 0x3d829c95, 0x3eb6dc24, 0xbf57d7ac, 0xbe886667, 0x3d37af96, 0x3dde40b7, 0xbf0543ae, 
    0x3df954b5, 0xbf27a3ef, 0x3e858471, 0xbef17996, 0xbe2bd498, 0x3d243df1, 0xbe75760f, 0xbf31721d, 
    0xbe3666bf, 0x3f3ef440, 0xbf18ac44, 0x3ec4b394, 0x3ed46fd8, 0xbf213734, 0xbf3a5487, 0xbdc915b3, 
    0x3ebc8a35, 0xbf161a04, 0x3f3cdace, 0x3f036781, 0xbed73db7, 0xbed47d99, 0xbf44e9d2, 0xbe0c4d07, 
    0x3f009154, 0xbe0bda93, 0xbf0c3b08, 0xbe5909f5, 0x3e3ecb4a, 0xbebff7a6, 0x3c55b712, 0xbf363676, 
    0xbe8aae93, 0xbf42e2ef, 0x3f4d3cc7, 0x3ec1e4d8, 0xbf0ecbe1, 0xbe9e4184, 0xbf484ebf, 0x3f35114f, 
    0xbf1c89f3, 0xbede327e, 0xbf519937, 0xbd6c1a3d, 0x3d8edeca, 0xbec9b082, 0xbf1c391d, 0x3ed4c58b, 
    0x3ed226c0, 0x3ef36bdf, 0xbf2c154f, 0x3f14ec73, 0x3e496539, 0xbe044fb6, 0x3ec4ba0b, 0xbe927b9c, 
    0x3ed9b6cb, 0xbf0801fa, 0x3f21174e, 0xbeb0521e, 0xbe78ebeb, 0xbf1b7b72, 0x3ef44621, 0xbc937f5d, 
    0xbefb8fae, 0x3f1c3c25, 0xbbb7be16, 0x3f0d7893, 0x3df41ecd, 0x3e97e83a, 0xbf148f64, 0x3e8615ec, 
    0x3e3d8207, 0x3e5349e9, 0xbdf53881, 0x3e593d46, 0xbd0c9f3b, 0x3e973249, 0xbe63845c, 0xbe936420, 
    0xbec84bf0, 0x3d5f7b89, 0xbe3b59e9, 0x3ec83610, 0x3f173492, 0xbecb2201, 0x3e96ab7f, 0xbe28526e, 
    0xbd9b6484, 0xbe68cb8d, 0x3eceb01c, 0xbe107d61, 0x3ec0ab0e, 0xbd9d7df4, 0x3dea593f, 0xbe548de7, 
    0xbe204763, 0xbd70532d, 0x3de7c8e1, 0x3dd58795, 0x3e45bda1, 0x3e0fda55, 0xbcf782c8, 0xbf0b11ee, 
    0x3ee7cdee, 0xbefedffa, 0xbed0f99b, 0xbe95f0a3, 0x3f06e48f, 0xbdf93629, 0xbf25f88e, 0x3f33717c, 
    0xbf0fcfe0, 0x3e813936, 0xbf24ba69, 0x3f02d371, 0x3e9f9491, 0xbd214319, 0x3ea58e9f, 0x3f18f68e, 
    0xbe744050, 0x3d1321e9, 0x3dd5ffc5, 0xbef7bfdc, 0x3c028b82, 0x3e82bd58, 0x3e033abc, 0xbd75b513, 
    0xbdd84c1b, 0x3e0d83ed, 0x3c875648, 0x3eabb645, 0x3ed5cb67, 0xbee34879, 0xbefa9b32, 0xbedf0170, 
    0x3f0dc4a0, 0xbea6c8db, 0xbe3ca93e, 0xbee4a729, 0x3e901e18, 0xbe7a157c, 0x3f172ee8, 0x3dcbd5ae, 
    0xbecafaef, 0x3da92ec2, 0xbeeb34b7, 0xbea672a9, 0xbf15ba6e, 0x3eba2e80, 0x3d8426dd, 0xbdeefa59, 
    0xbe991d3d, 0x3ecda252, 0xbde79acc, 0xbc2ebd3e, 0x3e920cca, 0x3f0c794f, 0x3e97c946, 0x3dc81516, 
    0x3e870819, 0x3ecf30a9, 0x3ea2f8c1, 0x3eba4e77, 0xbdd19bbb, 0xbea36fd6, 0xbeb3d329, 0x3e8a008a, 
    0xbf1364f6, 0x3e2ea4ea, 0x3d97afb5, 0xbe55edb2, 0xbe207e7f, 0xbec26b48, 0xbdd6b89f, 0xbe914de4, 
    0x3e963444, 0xbe9e4694, 0xbe4c1abb, 0xbf1319ec, 0xbe62d1fa, 0x3db8ff5d, 0xbe1222e3, 0x3ea42b09, 
    0x3ed45e24, 0x3ebc8763, 0x3db03415, 0x3e92a4e1, 0x3e838d90, 0xbd3f9e78, 0x3e812a2b, 0x3edcb190, 
    0xbea0d111, 0xbf2005fa, 0x3ecc96d9, 0xbf0c8291, 0xbf0b6248, 0x3ecf4ecb, 0xbe526f40, 0x3f10ea8b, 
    0xbf3eba1e, 0xbf09f8d7, 0x3eb63cfc, 0x3f293966, 0x3f157f13, 0x3f23c281, 0xbc99b645, 0x3f06121b, 
    0x3d1fbcc4, 0x3d518b2f, 0x3eb99319, 0xbf2ad1b5, 0xbebbf512, 0x3e050441, 0x3f243829, 0x3eb49bca, 
    0xbe9c3e2f, 0x3ebc9c71, 0xbf34469b, 0xbf01905e, 0x3f24c385, 0x3da37e60, 0x3f0dad41, 0x3ee051cd, 
    0xbe598088, 0xbd10c14f, 0x3f08b919, 0xbe0ed849, 0x3d608259, 0x3e66e0ba, 0xbee46b5a, 0xbd2b15d2, 
    0xbee8c700, 0x3f088869, 0xbead6071, 0x3e17d0e5, 0x3f27ba26, 0xbf26ea32, 0xbf378ace, 0xbda382bd, 
    0xbd298a3a, 0x3e84e687, 0xbf11cb3b, 0x3ee53c00, 0xbee438cd, 0xbe8ff497, 0xbef667b8, 0xbf1fcffe, 
    0xbeddc52a, 0x3eb0450a, 0xbe9bca32, 0xbf23a8b3, 0xbe10a874, 0x3be32170, 0xbf237d79, 0xbe57b4b5, 
    0xbdc44611, 0xbf2010a9, 0x3f244e41, 0xbee5c8cd, 0x3eb68332, 0xbf00dfad, 0xbf05c2d5, 0xbf22a34b, 
    0xbe8f1d98, 0xbde6da21, 0xbf2c3885, 0xbf0f76d9, 0x3e1f6de8, 0x3e1fc391, 0x3c9f3c5d, 0xbea39313, 
    0xbf164365, 0x3f240c02, 0xbe8be81a, 0x3f0309bc, 0xbf38cfe5, 0x3e205ecd, 0x3ed50db1, 0xbf11c35b, 
    0x38ec61be, 0xbea54e7b, 0x3e8eee58, 0x3e5b890a, 0x3f15d6fa, 0x3f20c22e, 0x3e701931, 0x3d625e90, 
    0x3dd0db73, 0xbf1fddaa, 0xbe0f78e0, 0xbe88d9c8, 0xbf288e23, 0xbca1b94a, 0x3e16777c, 0x3f4c06a7, 
    0x3d162d44, 0xbf1ddebc, 0xbea3f8d3, 0xbebba2a8, 0x3e161587, 0xbcc6431e, 0xbf24aa87, 0x3f14ba02, 
    0x3ed5110d, 0xbf2ab12b, 0x3d9b00fc, 0x3f008c46, 0x3f108481, 0x3f08ce3d, 0x3ee26fe4, 0xbf3f4da9, 
    0xbef2957c, 0x3f1eda95, 0x3f15e139, 0x3e9903d2, 0x3f39c235, 0x3f1a9486, 0xbe7d48f3, 0xbee1ba6e, 
    0x3f0a6b61, 0xbd849b51, 0x3ee9a146, 0xbf31d0a8, 0x3f17fb82, 0xbf0e408c, 0x3eb4af1d, 0x3ef2349f, 
    0x3ea3e978, 0xbf165410, 0x3d628504, 0xbb2c5cb1, 0xbe877478, 0x3e80007c, 0xbe7c3732, 0x3e151333, 
    0x3e8dc373, 0x3eca46ad, 0x3e4a243e, 0x3e7a7c37, 0xbf25ece8, 0x3f29fceb, 0x3f3bf757, 0xbcfcef64, 
    0xbe87f2c2, 0x3dbaa967, 0x3ebc435d, 0xbdf85f38, 0x3e4414d7, 0x3ec928fb, 0x3d83460a, 0x3f0515c5, 
    0x3f437933, 0x3efa5371, 0xbf1e136a, 0x3e71c693, 0x3ee7c91d, 0x3ebfb0a5, 0x3f28ea3b, 0xbe247935, 
    0xbe0ec678, 0x3ecb7a47, 0xbf56b37b, 0x3f22f4df, 0x3eddf98f, 0x3df6cbaf, 0x3ea9a53e, 0xbe14886a, 
    0xbf015866, 0x3d60b8ea, 0x3f235cb3, 0xbf2af9be, 0xbf2df1bd, 0xbd2f49db, 0x3e3b3450, 0x3f00fdbe, 
    0x3dddb986, 0xbee2164f, 0x3e242c6a, 0x3eb143d7, 0x3f24cf95, 0xbf1c1bbc, 0xbe25d025, 0xbef6d085, 
    0xbf4a4e5e, 0xbf079400, 0xbdc415ef, 0x3dd20b77, 0xbf258290, 0xbde18b7b, 0x3f30bb76, 0x3e9be5e1, 
    0x3ef3958e, 0xbf00addd, 0xbe8824d6, 0xbee3f420, 0xbf1b2b54, 0xbeed0a70, 0xbf00b6d0, 0x3d74fa13, 
    0xbf1821bf, 0xbd8d9cf4, 0xbeb425ce, 0x3e36e726, 0xbea69667, 0x3eff643d, 0xbea2811f, 0x3e2bd205, 
    0x3e2a63e6, 0xbe3c16f6, 0xbe834c79, 0x3e86692a, 0xbe587d5f, 0x3e675f66, 0x3f01b92a, 0x3e9fbd0b, 
    0xbf0d572e, 0xbe864f37, 0xbd8b5e58, 0x3e9f35c8, 0xbefd1436, 0x3f0e672a, 0xbd909bfd, 0xbd01361b, 
    0x3b55420b, 0x3ea99b48, 0x3ef136f6, 0xbef0ed53, 0xbebf313d, 0xbe803868, 0xbed6b2b8, 0xbead48c6, 
    0x3ede8890, 0x3ea840eb, 0xbf037c9e, 0xbdafdddd, 0x3eeb555c, 0x3e8f2fa6, 0x3e06a517, 0xbf064514, 
    0xbf00d2c9, 0x3da310c3, 0xbeda2176, 0xbdb4ba4b, 0x3e70b1d9, 0xbde6c17f, 0x3ec90edf, 0x3e8b7b54, 
    0x3e833ccb, 0xbeb8dcc1, 0x3e8f764e, 0x3dbe4e67, 0xbd32ab79, 0x3e7c4849, 0x3eed6177, 0xbe2bfaf5, 
    0xbeac1cc9, 0xbefc442e, 0xbd9a3433, 0x3e54cf1c, 0x3e080c2e, 0x3e4676fc, 0x3e9d1114, 0xbeedd359, 
    0xbf078cbb, 0xbe5bcdf0, 0xbdf1c006, 0xbf03a6ba, 0xbde51f16, 0x3d1176ce, 0xbed39c04, 0x3ecedc34, 
    0x3ef6a3c1, 0x3ed2859b, 0x3ea8999a, 0xbf124d17, 0xbca8e022, 0xbec13a4e, 0xbf150182, 0xbdde77c6, 
    0xbcc45d54, 0x3da510e2, 0x3e08a595, 0x3e8135ee, 0x3ea78f4a, 0x3dd95ab3, 0xbdf6decb, 0x3f0733c3, 
    0xbedbab8b, 0xbe29c1dd, 0x3ee08549, 0xbf1665ae, 0xbee5725f, 0xbf0e2ba5, 0xbe507eb6, 0x3e4a563d, 
    0x3da3b455, 0x3f1d44cf, 0xbe0ee48c, 0xbeb65ab5, 0xbf04bd56, 0x3eace5c4, 0xbf16cf16, 0x3f09eb5d, 
    0xbd3f370a, 0xbe1a01d2, 0x3eddfb76, 0xbf1af5f1, 0xbe6280ba, 0x3eac5f8a, 0xbe9ee4fb, 0xbefa9c63, 
    0xbef35d9b, 0xbd972729, 0x3ebc1fad, 0xbf156cf0, 0x3ee371fb, 0xbed3cbbe, 0xbf0118b8, 0xbe914f75, 
    0x3f0ef4f3, 0x3d1343e0, 0xbf042473, 0xbee891d7, 0x3dd6c74c, 0xbea5811d, 0xbdf501ba, 0xbe25b518, 
    0x3e10ff27, 0xbf039b18, 0xbab1272b, 0x3e676725, 0xbe96af15, 0xbed0d8a9, 0xbe089b8a, 0xbd3a4d82, 
    0x3eb5f098, 0x3e580153, 0x3e74cdd0, 0x3ef4e10d, 0x3ce0b678, 0x3e999d3d, 0x3e5e0014, 0x3d91362d, 
    0xbd0a6053, 0x3f207d34, 0x3f0b80ee, 0x3c02f8a6, 0xbd87a8b6, 0xbea82d06, 0x3e6f8fe0, 0xbe1e33b4, 
    0x3d4cd678, 0x3c7a2461, 0xbe658eaf, 0x3ead705c, 0xbe1b2a6e, 0xbe175292, 0xbe9e8825, 0xbd99676e, 
    0x3e6b2f42, 0x3e794ff5, 0x3e9ce3d1, 0x3e9de429, 0x3e430d95, 0xbe55014d, 0x3e665685, 0x3e672b6d, 
    0x3df5584f, 0x3ec4ed9a, 0xbecaba12, 0xbd348f7d, 0x3e931cce, 0xbed2b8c6, 0xbd379cce, 0xbec7b385, 
    0xbc26000a, 0x3dbb6c10, 0xbdf21427, 0x3efb1168, 0xbe1f8523, 0xbd76ab5c, 0x3edab3d7, 0x3de9a2c8, 
    0x3d1c60fb, 0xbc2c6ee1, 0x3deaeb21, 0x3dcdcc75, 0x3d9bf051, 0xbe0551fa, 0x3e1a01e1, 0xbd7db767, 
    0xbe39e77b, 0xbeceeee6, 0x3e19caff, 0xbeb1862a, 0x3dab8641, 0xbeb9c803, 0xbe45672b, 0xbd421453, 
    0x3d789624, 0x3d48c981, 0xbe74e4fd, 0x3eb45146, 0xbeb13ef8, 0xbe44dc2c, 0xbe69f70e, 0xbe05184b, 
    0xbc7a6f0b, 0xbe3e68fe, 0xbe9a214e, 0x3eb9bc22, 0xbd96251b, 0xbdbb4b4a, 0xbe3cbdfa, 0xbdde6ba2, 
    0xbe158336, 0xbebfd2ac, 0xbebc3283, 0xbea3d3fa, 0xbe384c36, 0xbec44cda, 0x3eac808c, 0xbea717eb, 
    0xbe4aae1a, 0x3e8f097a, 0xbf05cf1a, 0xbe571764, 0x3e9814cf, 0xbed37d67, 0xbeb15ea3, 0x3e8e89d2, 
    0xbe425462, 0xbeeaf3c1, 0xbe48046f, 0xbedba411, 0x3eeea166, 0x3ef2c5e9, 0x3ed64cae, 0x3efb11cb, 
    0x3ea9fb33, 0xbedeffd3, 0xbe91d440, 0xbde5e883, 0xbd7811b6, 0xbe094bbc, 0xbe819524, 0x3ea4ad90, 
    0x3e02a430, 0xbe4ccefa, 0xbda67757, 0x3e8b1e19, 0x3ee30631, 0x3e44e5bb, 0x3e14d91f, 0x3ed2ed07, 
    0xbddc6a43, 0x3ea42368, 0xbeddf56e, 0xbeb61e9f, 0x3e9f528c, 0xbed70352, 0x3e2fb107, 0x3e2e694c, 
    0xbe929fcc, 0xbec0d55a, 0x3a5415f0, 0xbeededc4, 0x3cfba5b5, 0xbf005dd1, 0xbf04cd8c, 0x3eb9a734, 
    0x3e8fd77f, 0x3ea7d741, 0xbe901e66, 0xbd9edf13, 0x3da00c50, 0xbf00c666, 0xbf01aee0, 0xbcf88a93, 
    0x3e841c0f, 0x3c248b03, 0x3cb8dd79, 0xbdba134b, 0xbeb69b31, 0xbdbc913e, 0x3dbbe723, 0xbeb2a423, 
    0x3e3d67da, 0x3ed63185, 0x3e86524a, 0xffffce0a, 0x00000004, 0x00003000, 0x3e42d87e, 0xbddb2e4c, 
    0x3ea77f7f, 0xbed6cdc2, 0x3ee2f9c9, 0x3e16eb7c, 0xbef76629, 0x3d279ba0, 0xbd888dca, 0xbdb45e51, 
    0x3e2b3a8a, 0xbcab4483, 0xbe341e56, 0x3ea54ca4, 0xbeb9f6a6, 0x3e69c4f1, 0x3e89847a, 0xbedb2938, 
    0x3eb5da0c, 0xbeaf58fb, 0x3e80d3a0, 0xbed88aa3, 0xbea36450, 0x3f05a906, 0xbd83f34f, 0xbe2ebcb2, 
    0xbdf859dd, 0xbba3ab5d, 0x3ec9ffee, 0x3e13c8b1, 0xbe7c32fc, 0xbdde579c, 0x3dd26b0f, 0x3e01bf4b, 
    0xbef264e1, 0x3eb351bc, 0x3e31ec03, 0x3e72998d, 0xbe09898e, 0x3e26509a, 0x3dcbbdf7, 0xbedc8a21, 
    0x3e463b0a, 0x3dd6b096, 0xbe0f5670, 0x3e8b89ea, 0xbe8fdf20, 0xbebc7568, 0x3edc2f6f, 0xbec84f87, 
    0x3e7964da, 0xbeef098e, 0xbdadcfc7, 0x3eac166d, 0x3cc20833, 0x3ef560af, 0xbe848ff9, 0xbe007b7d, 
    0xbee4c34d, 0x3e89bfa1, 0x3ee24cc4, 0xbeebe0fd, 0x3e9dab36, 0x3e8d149a, 0x3df0389f, 0xbe62accd, 
    0xbeadc224, 0x3ed3d385, 0xbe40671d, 0xbe34565c, 0xbd6a3f23, 0x3ef4ab06, 0x3e80caab, 0xbebb974c, 
    0x3dcb12a5, 0x3d98175d, 0xbd990325, 0xbef4cdff, 0x3ec6cf90, 0x3d5ca93b, 0x3dcaf79a, 0xbddb7c66, 
    0xbeafc75e, 0x3e53e5e4, 0xbec8dd01, 0x3ee63bbe, 0x3e48dd48, 0x3eb68e67, 0x3e0409f0, 0xbe8bfe7d, 
    0x3e2687ad, 0x3e346315, 0xbd281b29, 0x3d596a47, 0xbed954b4, 0x3edce5c3, 0xbed46549, 0xbd5f998a, 
    0xbec89244, 0x3e82ba7b, 0xbf2f2080, 0x3d7c331e, 0x3e39186e, 0x3ee1e4c6, 0xbf12e11d, 0x3e9a659c, 
    0xbed929e4, 0xbe47102a, 0xbeb390cd, 0x3e17aa45, 0xbc836943, 0xbe4cbea6, 0x3de635a7, 0x3ea3c3e9, 
    0x3f041638, 0xbeb7d824, 0x3eb597dc, 0xbef57668, 0x3eff3dd8, 0xbf17804d, 0x3daf8e21, 0x3f07babd, 
    0x3ec25713, 0x3d1e3cc0, 0xbf17f1d1, 0x3e6edc5a, 0x3e87b331, 0xbe19a483, 0xbedbfd78, 0xbe6d6b0e, 
    0x3e7954bd, 0xbe7f8ca1, 0x3d800e61, 0xbe98d156, 0xbd6d3cbd, 0xbeaf02ea, 0xbe28b15a, 0x3ee82e95, 
    0x3beea2bd, 0xbed4203b, 0x3e39d670, 0xbea1a42b, 0xbf09dd1a, 0x3e6d21c7, 0xbf126ee4, 0xbf02657f, 
    0xbd0a7876, 0xbf0ef8e0, 0xbe68401a, 0xbdb82f4f, 0x3ea71e42, 0x3e6b62de, 0xbe2c9501, 0xbe9cbec0, 
    0xbeda2618, 0xbea7e333, 0x3d8b5778, 0x3ee3100a, 0xbd36ec3d, 0xbee61c4f, 0x3ed605ec, 0xbe29ddb4, 
    0xbeec0434, 0x3ee8556b, 0x3d8cb51b, 0xbe680c0a, 0xbe795f5d, 0x3eaf670f, 0x3e904188, 0xbe44d150, 
    0x3f0685bb, 0x3da1ee00, 0x3e6d40ed, 0x3ee10d64, 0x3f019905, 0xbe411930, 0x3f04314e, 0x3ee6b5d6, 
    0xbe8454a2, 0x3e831e14, 0xbeb95ac7, 0xbf1712f5, 0xbd5deede, 0xbd2468f1, 0xbf0592a1, 0xbe0fa1de, 
    0xbd8c42b3, 0x3bd14be3, 0x3dfdd4f3, 0xbe1f91d4, 0x3ea5e989, 0x3ec6bb86, 0x3edb75cd, 0x3eddd15d, 
    0xbeac40b0, 0x3e8a32e3, 0xbebdbc6e, 0x3e73fd28, 0x3e0dd28c, 0x3e8bc2ae, 0x3ccaba6c, 0x3dd4de33, 
    0x3e5af6e5, 0x3e3df704, 0x3ea29f9b, 0x3ede382b, 0x3eca1d60, 0x3e89afa0, 0x3dcc6262, 0xbed5d297, 
    0xbe8390d6, 0x3e209389, 0xbee1f92c, 0xbec32677, 0x3eae790d, 0xbea09638, 0xbd841b78, 0x3eaf2f1e, 
    0xbe9bf953, 0x3cf2acd1, 0x3ebb12da, 0xbe1fd673, 0xbe6b8e64, 0xbd70504a, 0x3e6070b8, 0x3e118ddf, 
    0x3e44bace, 0xbeab493d, 0xbeda6b0c, 0x3db9e154, 0xbe84f64d, 0xbecd3322, 0x3e8fda01, 0xbe1806c9, 
    0xbc2455a3, 0xbe59a173, 0xbde03821, 0x3cc90bb9, 0xbdf3aeec, 0x3e61d179, 0x3dadd44a, 0xbda7833e, 
    0xbe503567, 0x3eb63bf2, 0xbe896e41, 0x3e8d8350, 0xbd809b5b, 0x3d518692, 0xbd89550a, 0x3c3d5d9d, 
    0x3e08b1a6, 0x3e7a10f9, 0x3e50afa2, 0xbd4031de, 0x3edc1bc6, 0x3dbdabc8, 0x3eaa0c2d, 0x3eae5e33, 
    0x3ec2889b, 0xbe1aa7b0, 0x3d909afa, 0xbe15ac12, 0x3ec40b57, 0x3d7c162e, 0xbe7d4c6f, 0xbc0d52e3, 
    0x3e978441, 0xbe80846d, 0xbe008a30, 0xbe813d02, 0x3e8e215f, 0x3dcb7b09, 0xbe93f4b9, 0x3e59df18, 
    0xbe265d08, 0xbe3c6564, 0x3e76a767, 0xbc9bbf42, 0xbeafd3a2, 0x3eb19e06, 0xbe003f47, 0xbe758af6, 
    0xbde6da61, 0xbd171b53, 0x3e323287, 0x3e169b42, 0x3ec95728, 0xbe751697, 0xbdccab8d, 0x3e47b43b, 
    0xbc4535dd, 0xbe24ee50, 0xbe14506b, 0x3e31cee7, 0x3e2ba3ae, 0x3e3fb714, 0x3ea118da, 0xbe1bf1a0, 
    0xbd82bb12, 0xbceaec88, 0x3e3391a2, 0xbc153978, 0xbe0cc9e4, 0x3b828d81, 0xbe2169a7, 0xbe79d7c6, 
    0x3e0cee6f, 0x3e4b52e3, 0xbdb300d0, 0x3e8dfc13, 0x3e04cf3f, 0xbd76a89a, 0x3df30d92, 0xbd9e097e, 
    0x3d015526, 0xbdf28a60, 0x3e041643, 0xbdbe4a78, 0xbe9806bd, 0x3d42241d, 0xbde201f6, 0x3e277610, 
    0x3cfed442, 0xbe29412b, 0x3e416f64, 0xbe30b621, 0x3e6be9cf, 0x3d25778d, 0x3d88f22d, 0xbe3cbea8, 
    0x3c3afa40, 0xbe3816f2, 0xbe8fd729, 0x3e0fe0cb, 0x3e926caa, 0xbe5a781e, 0xbe841309, 0xbd1bdaba, 
    0xbe8becc1, 0x3e8ea368, 0xbe206e86, 0x3e2a9c2d, 0xbe095b8b, 0xbe88b231, 0xbe262e51, 0x3dbc0273, 
    0xbe953b7b, 0x3e8227b5, 0xbe0526a4, 0x3e83c3f7, 0xbe8436ab, 0x3d9216b4, 0xbe11c0c2, 0x3e6e93c5, 
    0x3e433a56, 0x3dc6022a, 0xbdc7c671, 0xbe3582be, 0xbc4065b5, 0xbe36e969, 0x3e49d6db, 0xbe507181, 
    0xbe150592, 0x3de448ca, 0x3e64b234, 0x3bc27eb5, 0x3e9dbdef, 0xbe8d8f31, 0xbe5b8762, 0xbdaa28ef, 
    0xbe300797, 0xbe79cb77, 0xbe5c7b98, 0x3cafc99f, 0xbe76d43b, 0x3dfe6e47, 0x3e44c0f7, 0x3e24c915, 
    0xbd738653, 0xbe116fca, 0xbe593189, 0xbe1fecb7, 0xbe8f1fb2, 0x3e79b1f5, 0x3e9ce5c4, 0x3e5444d7, 
    0xbe494a3a, 0xbec5a537, 0xbe1116c7, 0x3eb8326d, 0x3e51ca7a, 0x3d779a5a, 0xbe1ada04, 0x3e56e24c, 
    0xbedfff61, 0x3c7ef69a, 0xbec25a15, 0x3c3af277, 0xbdab88e2, 0xbee65112, 0x3ee04f67, 0xbe9e4440, 
    0x3ed45bc8, 0xbeac56e8, 0xbd44980e, 0xbdabd7ba, 0xbed250df, 0xbe94657e, 0x3e70e593, 0xbd66fcc5, 
    0xbe9b8990, 0xbee25a66, 0x3eb37736, 0xbe168b94, 0xbe269d5a, 0xbdb66624, 0x3ed846d2, 0x3e4060a6, 
    0xbe1f69b9, 0x3d393fc6, 0xbe61a3b5, 0xbe432ed0, 0xbe6a810e, 0x3e1f1555, 0xbeea9c6e, 0xbea52b31, 
    0x3e095779, 0x3e9efe36, 0x3dd9ce6b, 0x3d5c0680, 0xbe86d2f8, 0x3bba9b73, 0x3e981e54, 0x3e203aad, 
    0x3e3fd33e, 0x3dd91d12, 0x3ed00fca, 0xbee1ffd8, 0x3e7f1d46, 0x3d8cce04, 0xbe8fcf1a, 0x3d938ee5, 
    0x3d46ace1, 0x3e06298e, 0x3e790fb4, 0x3e6723ac, 0xbe849c7a, 0x3e5feb96, 0x3ebf6ef0, 0x3e99c190, 
    0x3ec54624, 0xbebe497e, 0x3cc699f9, 0xbeb34fa7, 0x3eaca607, 0x3e749deb, 0xbe2eee36, 0xbe2dfac3, 
    0xbeb0fcb1, 0x3d906593, 0xbcc9efc8, 0x3e06b03c, 0xbdd638d7, 0x3e376d56, 0x3ec60f20, 0x3e3e5aa6, 
    0xbe5880c9, 0x3dd4827f, 0xbe6ee84e, 0x3e0f22a8, 0x3ef05f72, 0xbe8d4630, 0x3e6db2e7, 0x3e8bf546, 
    0xbea5bdd1, 0xbe8b3c21, 0xbd5e9889, 0x3d8ce123, 0x3e04e689, 0x3ea77211, 0xbe71c852, 0x3bb746a5, 
    0xbef165f6, 0x3ed7bc2f, 0x3e62bf23, 0xbda8b2f4, 0xbe406ab1, 0x3ee8f61c, 0xbe891e91, 0x3efc50bc, 
    0xbedecb90, 0xbdc3a82f, 0xbe2976d0, 0x3cac00f2, 0x3dfea093, 0x3e2049fb, 0xbe43afb4, 0xbe2606ba, 
    0xbe78274e, 0xbef1df2c, 0xbeb2f177, 0x3e9f095e, 0x3de96d89, 0xbe76757d, 0x3ef91914, 0xbd95e1ca, 
    0xbe65a2b1, 0xbe6f0de9, 0x3e28f04f, 0xbe8776c2, 0x3e448bd9, 0xbeba9040, 0x3ee482cb, 0x3d24bdd4, 
    0x3ee40a6f, 0x3d5770d4, 0x3e68516a, 0x3d20c5c9, 0xbebc1a6d, 0x3f0b9c39, 0xbe318e21, 0xbef2c324, 
    0xbef2acac, 0x3e9ab903, 0xbe2e12b8, 0xbea55ad0, 0xbd1d1de5, 0x3da0f0d3, 0xbdb6ced6, 0xbed40f83, 
    0xbe1a3e1a, 0x3bd04a58, 0x3e2fd632, 0xbede6fe3, 0xbebef999, 0x3ef437c7, 0xbee356c0, 0xbe194141, 
    0xbefa1665, 0x3e8a6471, 0x3eea9406, 0x3ed74468, 0xbed7d7dc, 0xbef953c3, 0xbeac4fd5, 0xbda52acb, 
    0x3e008ced, 0x3d15b3eb, 0x3f035a23, 0x3dfec2be, 0x3e6eec20, 0xbe4815bc, 0x3ded269d, 0xbece91c4, 
    0xbf05f811, 0xbecd4af3, 0x3ed6bc42, 0xbe9a6405, 0x3e457484, 0x3ee02d79, 0xbdc9395c, 0xbc8df2d1, 
    0x3e5c0cbd, 0x3eac000d, 0xbddfbc5e, 0x3ea8030d, 0x3e53b4e3, 0x3e8aa446, 0xbeff7940, 0xbceccc6b, 
    0x3eee16cb, 0xbea3d102, 0xbeec89ec, 0x3ee51f72, 0x3ec67a1c, 0xbe10d6cb, 0xbe9e533f, 0xbe0ce16d, 
    0x3e750686, 0x3e8253c3, 0x3ecef3a2, 0xbea73832, 0xbebcbbec, 0xbe6dd7b2, 0x3e08058c, 0x3eddfa78, 
    0x3de63f76, 0x3e825a3e, 0x3e879bef, 0xbe433539, 0x3e80013b, 0xbee64963, 0x3ec2d0fa, 0x3e56539d, 
    0x3eb46ce2, 0x3d90aafc, 0x3da5692f, 0xbe8988ee, 0xbbd7ad5d, 0x3e4d970e, 0xbde7d34f, 0xbdf206c4, 
    0x3c2098b6, 0xbe3639f6, 0x3ee95b17, 0x3d2b5f80, 0xbeeacfa3, 0x3c59476c, 0x3de9237a, 0x3e9287be, 
    0xbe6bfc8b, 0x3e84596d, 0xbec42786, 0xbe425e60, 0xbd74426a, 0x3ea049d9, 0x3ea657d0, 0x3efd2a65, 
    0x3de43576, 0xbe7ada16, 0xbdccd98b, 0xbee81205, 0xbee8dec0, 0x3e86c4f4, 0x3edf355c, 0x3e0ec755, 
    0x3ea566c8, 0xbefe1ded, 0xbde556dc, 0xbdbbae93, 0x3e0cf6a1, 0x3e63dabb, 0xbe624c61, 0xbe82044c, 
    0x3dee7864, 0xbd2f0a23, 0x3daaea73, 0x3ed85792, 0xbbe9f4c8, 0x3e6023e4, 0xbe330b16, 0x3c08ecfa, 
    0x3e0aedaa, 0xbe3a3449, 0x3decb3f4, 0xbe50b7fe, 0x3eb8569c, 0xbe1f152b, 0xbec7fbf6, 0xbe5da20b, 
    0xbbffaed8, 0x3eaeee3c, 0x3c218c46, 0x3eb99043, 0x3e8980e9, 0x3ecfc299, 0xbde5fd8b, 0xbe14b6c8, 
    0xbedf7662, 0x3deac761, 0x3ecdd565, 0xbe3596a4, 0x3d082ff8, 0xbd773198, 0xbe0bdafd, 0x3de69fb5, 
    0x3d34aa04, 0xbdf31a8b, 0x3e6d05b3, 0xbe117baf, 0x3e34901e, 0xbd62155c, 0x3ea1ef30, 0x3e9f0075, 
    0x3eb4819e, 0x3cfbfd04, 0x3e985371, 0xbe17bb06, 0x3e4f4725, 0xbe70e51e, 0x3afc1d6b, 0x3dc49ac8, 
    0x3e90c0b8, 0xbeec7195, 0xbf0ca313, 0x3ec1d120, 0x3e3e39cf, 0xbe1a1451, 0xbec4f676, 0xbee20f4b, 
    0xbd4c8c77, 0xbe0bc255, 0x3e358094, 0x3e9f7ade, 0xbe00b68d, 0xbe68dcdd, 0xbeec7015, 0x3e1b9712, 
    0xbe44ea47, 0x3e986a9d, 0x3dba45dc, 0xbcb2a174, 0xbec01762, 0xbe330017, 0xbcd34018, 0x3e05410b, 
    0x3edf7852, 0xbe112cbf, 0x3ef5e90e, 0xbee1483a, 0x3eeb680f, 0x3d4149e5, 0xbe18155a, 0x3ed37c9c, 
    0x3e67dd80, 0x3e652e50, 0x3e2d83f0, 0x3eea56c9, 0x3ef14bc3, 0xbea81c89, 0xbe9b8d57, 0xbe7c8753, 
    0x3d640702, 0x3b97f361, 0x3e59deb2, 0xbdf9622c, 0xbc87981b, 0xbe4413e9, 0xbeff998c, 0x3dbf3be4, 
    0x3e8bd8c2, 0xbe99a6ed, 0xbd4e67be, 0x3ed30303, 0xbd48caa4, 0x3ed366a2, 0xbbd07a3b, 0x3d407625, 
    0xbe907e5e, 0x3c97387b, 0x3d115725, 0xbe5f551c, 0x3df564b5, 0x3ea35fb8, 0x3ea30278, 0xbe9f8561, 
    0xbe01ea18, 0xbc0b6044, 0xbec803d0, 0xbdc04a8b, 0x3eeb3f72, 0xbeed18bb, 0x3d69799f, 0xbeff3598, 
    0xbd8fcd9b, 0xbc1a60c7, 0x3e845e8d, 0x3e79ca97, 0xbf09b3fc, 0xbe345b74, 0xbdaab192, 0xbcbf5d6e, 
    0xbe9c94b3, 0xbe559713, 0x3c675f41, 0x3e852680, 0x3ec928da, 0xbd7034a0, 0xbef6542f, 0xbee9179f, 
    0xbd924afb, 0xbea5dad8, 0xbee3ab61, 0xbe2244c6, 0x3ef5dc46, 0xbe34af76, 0xbe3e0a28, 0x3dc2d922, 
    0xbec6ac06, 0x3e05aa0c, 0xbedc303b, 0xbdc835b3, 0x3ee5bb51, 0xbe4fa361, 0xbda5913a, 0x3dbcea31, 
    0x3eb7a6fc, 0xbf00e15f, 0x3eebc49c, 0xbed61655, 0x3eefc1d4, 0xbe50ec1a, 0x3c177058, 0xbde92d3f, 
    0x3f18f2b5, 0x3ea12258, 0x3ef3a6ce, 0x3ea0cdd2, 0x3eaee091, 0x3eec8fa0, 0xbd87e6a1, 0xbe63065b, 
    0x3ec62acc, 0xbefa159a, 0x3ca2f2b6, 0xbba6e42e, 0x3dba204f, 0xbe96994e, 0x3ec58ad6, 0xbe6d1742, 
    0xbecd73e4, 0xbcce1191, 0xbef45114, 0xbd9d72b8, 0xbe39f3ec, 0x3e3562a8, 0xbeb8f00c, 0xbddbe1a3, 
    0xbbcc1382, 0x3eb0cbef, 0xbdee2454, 0x3db0da96, 0x3dc25344, 0x3ee78da8, 0x3afa0520, 0xbea488fe, 
    0x3e8c14b0, 0x3d3fdac6, 0xbe3deb2f, 0xbeed0079, 0xbeb01112, 0xbeb9679b, 0x3ec7f7e1, 0xbe3ec760, 
    0xbe1433be, 0x3ebc4230, 0x3db3b673, 0x3ea7f93d, 0xbdffb10c, 0xbeb1a18c, 0x3d92aa9c, 0x3ef254b3, 
    0xbe2e071c, 0xbda17ff1, 0xbef0ef30, 0x3eb108eb, 0x3ed7e2c0, 0xbe9f3a7c, 0x3f02db88, 0xbec7498a, 
    0x3edb99bc, 0x3ea18107, 0xbdc459da, 0xbdedee39, 0x3d5539f7, 0xbec94458, 0x3e37884a, 0xbf02b318, 
    0xbedbc5c2, 0x3f0f4607, 0x3dd0da6b, 0x3efa3de3, 0xbd5ad4a6, 0xbe62797a, 0x3e70a551, 0x3cf4d980, 
    0x3d86476b, 0xbe2b39f0, 0xbe44bf14, 0xbdaf7046, 0xbe8e8d0b, 0xbe7eedc0, 0xbe24c2a4, 0x3eaa4d12, 
    0xbe1d19fe, 0x3d94f8a8, 0x3e39d672, 0x3ec9b58d, 0x3eb8015b, 0xbcd90814, 0xbe615865, 0x3ea56d8c, 
    0x3db45a22, 0xbe100ed7, 0xbe9f7d57, 0xbe88baae, 0x3cb8b91d, 0xbec3e862, 0x3dfca085, 0x3d3f714d, 
    0xbe21604c, 0x3ebc8296, 0x3eba6b94, 0x3e500a4d, 0xbd46d05f, 0x3d7d3677, 0x3eb68d0f, 0x3d1141cf, 
    0x3cbc279d, 0x3e9963a6, 0xbe6b2fe7, 0xbdb6736b, 0x3d558c30, 0x3e36ad7b, 0x3e9730ca, 0x3e4f08c4, 
    0xbeb7c26a, 0xbe7c25d7, 0xbb289da0, 0x3ec0140e, 0xbe5561d0, 0x3cd42264, 0xbd90da5a, 0xbe7e8026, 
    0x3e73c29f, 0xbe4622a2, 0xbe83d2d0, 0x3ea647f2, 0xbe35842e, 0x3e8139fd, 0xbd76c9f0, 0x3db4e3cd, 
    0xbe3c5614, 0x3e9ab1d8, 0xbe9a4926, 0x3e92b1d4, 0xbe7cee98, 0x3cf81470, 0x3e0826e1, 0x3d959564, 
    0xbe2e3812, 0x3e311189, 0xbe899843, 0x3dec11b0, 0xbd2c1f54, 0x3db83605, 0x3ec8557d, 0xbe263be9, 
    0xbe221dce, 0x3e8a38e6, 0xbebaf5a4, 0xbe882b53, 0xbd87e7f4, 0x3e3cb9a8, 0xbe9b65b3, 0xbe8ca17b, 
    0x3eb9aa3d, 0xbe9916ad, 0xbeaec97a, 0xbd241de3, 0xbe920f6d, 0xbe95e840, 0x3ea0f093, 0xbd26d35b, 
    0x3e2b1347, 0x3e9cea5f, 0x3e29c064, 0xbdf43875, 0x3e56bfc1, 0xbdb1bdf9, 0xbede57b6, 0xbe0ee910, 
    0xbe9a3e56, 0x3ed5a3d0, 0xbe404c7c, 0x3e62408e, 0x3eb0b41a, 0xbe7a2a04, 0x3e6bdea5, 0x3c61a3cc, 
    0xbec30b52, 0xbdb82128, 0x3eb4a6fc, 0xbef49429, 0xbe7629d1, 0x3cdd846c, 0xbec7dc6f, 0x3e1c14bf, 
    0xbe934fd5, 0x3d5aeae4, 0x3eec1e20, 0x3edcfba6, 0xbeba71a7, 0x3ef666a8, 0x3e5bdb5c, 0xbedca13b, 
    0x3dd1d003, 0xbe423dc0, 0xbec9b7db, 0x3cef3b42, 0x3e41b58a, 0x3e416077, 0xbd23c41f, 0xbd56ad25, 
    0x3ee90c2f, 0x3de9ac97, 0xbeddc3b1, 0x3eebf49b, 0x3ec2f6c9, 0x3edce566, 0xbed07cd0, 0x3d8af143, 
    0x3d0ceace, 0x3db2abd9, 0x3deedd41, 0xbd19f087, 0xbe95089f, 0xbda89446, 0x3d7a424b, 0x3e8630b7, 
    0x3e37602d, 0xbd524514, 0xbeacc9d7, 0x3ebe1739, 0xbcf3348c, 0x3ddebddc, 0x3e0257ef, 0xbec9c66c, 
    0xbead7df2, 0x3ec8dd3f, 0xbe0513ec, 0xbdc00b7f, 0x3eb887c6, 0xbe5b0d23, 0x3e1fd861, 0xbb0551bb, 
    0x3e1a966c, 0xbe587b15, 0xbeec0c94, 0x3ecc6c48, 0xbef15b75, 0xbd45a660, 0x3ed81d36, 0xbb71029e, 
    0xbeb1f7fa, 0x3ea446e0, 0x3baedf39, 0x3ebb5bd2, 0x3ebd0270, 0xbe1ff49a, 0x3e645b27, 0x3e0ea20a, 
    0x3e976ac0, 0x3e0a4e6c, 0xbe961135, 0xbecc4059, 0x3ebc5bea, 0x3ebaaf66, 0x3e02fdfe, 0xbec65536, 
    0x3e5e7358, 0x3ed5437f, 0x3ed27cb7, 0xbe7e96fb, 0x3ee9d489, 0x3c92c7c0, 0xbf04e7d1, 0x3ee77225, 
    0xbe11b51d, 0x3dd958d3, 0x3ecaa6a8, 0xbeead77f, 0x3c24dc50, 0x3e8447bb, 0x3cdd338a, 0x3eef5e13, 
    0x3ea807e8, 0xbe5755ce, 0xbdccc802, 0x3eae090f, 0xbe292f4f, 0xbe34540e, 0xbd6afe96, 0x3e08e1b4, 
    0xbeed63df, 0x3eda9794, 0xbd8c2e55, 0xbea3e267, 0x3dae5b9a, 0xbd926fbb, 0xbe0c92ae, 0x3ebb3618, 
    0x3deec466, 0x3e708c28, 0xbe863271, 0x3e134647, 0xbd17983b, 0x3e835eca, 0x3e90526d, 0xbebf9064, 
    0xbec9a032, 0x3e2007d8, 0x3cc33d2f, 0xbee3d732, 0x3dc42ca5, 0x3da77f89, 0xbeca421a, 0xbea733ae, 
    0x3e16d1aa, 0xbe52133e, 0x3ea0cbd5, 0x3e598713, 0x3e3d9b91, 0xbedb327e, 0x3ea90ee1, 0x3eaa44d7, 
    0xbf089ace, 0xbe0a2e60, 0x3e463946, 0xbef27e4b, 0xbee3d9b0, 0xbe2b27ff, 0xbe551283, 0xbd930d46, 
    0xbef3ec50, 0xbeb4975f, 0x3efb5d57, 0xbeb69801, 0xbebbc166, 0xbec2bcb1, 0xbce325cc, 0x3ec0666a, 
    0x3d289497, 0x3eb19911, 0x3e7443bd, 0xbd5b719d, 0x3e12a293, 0xbee4aef0, 0x3ebe4548, 0xbe572720, 
    0x3d58200a, 0x3c21a43f, 0xbb70ef43, 0xbeaa05db, 0x3e5f2fbf, 0xbee53814, 0x3c513de0, 0x3ecfa3a7, 
    0xbddd44e4, 0xbd75815e, 0xbe408d69, 0x3e8da22b, 0x3ea4c96c, 0x3dca1ac9, 0xbeeb71a3, 0x3ef5bb6e, 
    0x3c67dfde, 0x3c9a1be3, 0x3e161a2e, 0x3ec39dfc, 0x3d25a12e, 0x3ed09b43, 0xbcf6c8fe, 0xbeb68acd, 
    0x3e83db68, 0xbe9a4994, 0xbe8b85f0, 0xbe48ca60, 0x3dcb00a4, 0xbe84920e, 0x3a96af75, 0xbcef6a2a, 
    0x3e14d704, 0x3e8824e7, 0x3d80cf9f, 0x3e72f02e, 0xbe9a87d1, 0x3ec170cc, 0xbe92bfaf, 0xbd8d0b30, 
    0x3ed083b0, 0x3da166b1, 0x3ebbb196, 0x3d972dbb, 0x3e56850a, 0x3ed27077, 0x3e9f8c6c, 0xbd99cbca, 
    0xbde099f3, 0x3e103f4f, 0xbd614dd2, 0x3d7f2689, 0x3e841999, 0xbe81fcfc, 0x3d8b96a3, 0x3e0a9552, 
    0x3dc0f1cf, 0xbec781cc, 0xbecf2711, 0xbd98affa, 0xbbb6f7b6, 0xbe385d2b, 0x3c1bdc56, 0x3e23a2dd, 
    0x3d010131, 0x3d653563, 0x3e330831, 0x3e96536b, 0xbdb43921, 0x3e72ed98, 0xbdb3cef4, 0x3d9e8ba5, 
    0x3e0cdcf2, 0xbe3a7c2d, 0x3d56c3b5, 0x3c443288, 0xbeb10d40, 0xbe643da5, 0x3e5a11e3, 0xbe738b6d, 
    0xbd8697c0, 0x3dd5937e, 0x3ecc8408, 0xbc721fa0, 0xbe86c949, 0xbdd89641, 0x3dd6644c, 0x3eba5962, 
    0xbea9595d, 0xbe0a7384, 0x3e927cc0, 0x3e3c1501, 0x3ebafc31, 0x3e911a0e, 0xbec8cfe5, 0x3d90dcb3, 
    0xbd5f42cd, 0x3df3825c, 0xbe646fd1, 0xbe1fcc92, 0x3e2a48a1, 0xbdddbd22, 0xbe707301, 0xbe913c40, 
    0xbe845e93, 0x3ea8d76b, 0x3e694380, 0xbcec7190, 0xbe851ffb, 0xbe7a862f, 0x3eb9e414, 0x3e972894, 
    0xbcdfdad4, 0x3e8e3109, 0xbe14664c, 0x3e15674e, 0xbe1e463e, 0xbe5e4116, 0xbbb33114, 0xbe99bbac, 
    0xbe0ef6ce, 0xbd45a658, 0xbe28393c, 0xbe91379e, 0x3ea83d8f, 0xbd810da5, 0xbe8ac48c, 0x3d9c7242, 
    0xbd66c37c, 0xbdcb8114, 0x3ddc2da6, 0xbd947073, 0xbe192d34, 0x3d4e2928, 0xbde34ece, 0xbe30f420, 
    0xbe8904b7, 0x3e79878a, 0x3e435bc2, 0x3e3ffba2, 0xbe6d6ee0, 0xbea977be, 0x3e25a7fb, 0xbea98abe, 
    0x3e3decc2, 0x3ec47c32, 0xbe10f4e1, 0x3dbf1a1e, 0x3dfb72c0, 0x3e74f71c, 0x3d1d616d, 0xbdcf014c, 
    0xbd9a6491, 0x3eb96ac7, 0xbeb65556, 0x3dee7234, 0x3e24a073, 0xbe3b84ae, 0xbe73ce09, 0x3e81e478, 
    0xbeaa92af, 0xbe8da0fb, 0x3e95dde7, 0xbe37281b, 0x3e73a2b7, 0x3dd6e3b5, 0xbe8f287c, 0xbde6146e, 
    0xbd499830, 0xbdbff3db, 0x3d36ec0b, 0xbe287c4b, 0xbe818b3b, 0xbdd9b834, 0xbe012565, 0xbe58a1f9, 
    0xbdc0197e, 0x3dcdbdf0, 0xbea382ea, 0x3e1eed15, 0xbd0a6c90, 0xbdbf50d7, 0xbe573462, 0x3e730edf, 
    0xbc72fbd7, 0xbe48689d, 0xbea83782, 0x3da35e54, 0xbe77c10b, 0xbd01ea73, 0xbe88ab34, 0xbe629908, 
    0x3e66af65, 0x3e71d69e, 0xbe27e4a0, 0x3d3305f0, 0xbeab386f, 0xbdc7b441, 0xbe7a4950, 0x3d463e09, 
    0x3deccccf, 0x3c4571c6, 0xbe4c87f4, 0xbe705e4e, 0xbe57c8a9, 0xbdaf366d, 0x3e9eb436, 0xbeb88165, 
    0xbdf85378, 0xbdb8f23e, 0xbe8a1065, 0x3da02327, 0x3e492bae, 0x3e23581b, 0x3e5248ce, 0xbee4aa72, 
    0x3ed65c6f, 0x3e17e4f3, 0xbee4e648, 0xbccd6640, 0xbe06306f, 0xbd3d370d, 0xbea444de, 0xbe7df8a2, 
    0xbe9ed269, 0x3ebb6ec8, 0xbe9513ac, 0x3e1b81fe, 0xbed1ecf5, 0x3de93878, 0xbeabf96a, 0x3eaff85e, 
    0x3c246abc, 0xbe4eb1ea, 0x3e997b58, 0xbe79dc0b, 0xbe89d2ff, 0x3e62e35e, 0xbd87d8c4, 0xbef8233d, 
    0xbd84fe24, 0x3eec069b, 0xbdfa037d, 0xbea140f4, 0x3e2fdb9d, 0x3dff0749, 0xbd394bef, 0x3c35a547, 
    0x3a55b743, 0xbea96b72, 0x3e1934d2, 0xbedb93b6, 0xbec08934, 0x3e99ba6d, 0x3e497410, 0x3e46685f, 
    0xbe7067d2, 0xbebda9f6, 0xbe6e4bd3, 0x3e0d47f2, 0xbecd5715, 0xbe984be7, 0xbedf4ebb, 0xbe4c749d, 
    0x3e79cb0e, 0x3ea421c8, 0xbf0909f3, 0xbef6cff1, 0x3e98c28c, 0xbe8f388a, 0xbdac8d6e, 0x3e22aac8, 
    0xbe4c2ee3, 0x3e3104de, 0xbed79a78, 0x3ed26de8, 0xbe441a29, 0x3ee66d2b, 0x3e67bfbd, 0xbed166fd, 
    0xbe2669ae, 0x3d276cac, 0x3a88d803, 0x3d9c7d6e, 0xbedb6dc5, 0x3ea51926, 0xbe9ee430, 0xbebc1347, 
    0x3ecbf56d, 0xbe900402, 0xbe2892a3, 0x3e11c570, 0x3d1297e4, 0x3d7c4eb2, 0x3df0d9ca, 0x3d590675, 
    0xbe6de7c7, 0xbe4a5852, 0x3eaab57a, 0xbd68b248, 0x3e8e7502, 0x3dc8113a, 0xbea43576, 0x3da5c7f2, 
    0xbed2b188, 0xbe9a6dd5, 0x3ed37259, 0x3e9a11af, 0xbc1390f1, 0xbcb810f9, 0x3e82fc24, 0xbdd62a64, 
    0x3e1cd32e, 0xbc11d96a, 0x3f1304a6, 0x3ecb4bdf, 0xbefefeb1, 0x3e0fbc1e, 0x3ef3093c, 0xbedcb937, 
    0xbddb2233, 0x3eabc978, 0x3e0df044, 0x3f0964ac, 0x3f10d913, 0xbebc95fb, 0xbeaa87ed, 0xbe18a48c, 
    0xbe00c253, 0xbe7ed60a, 0x3e3e7506, 0xbef25c34, 0xbeba352d, 0xbe0e8e56, 0x3ee7129c, 0xbc662bb1, 
    0xbe50f985, 0xbcf558b8, 0xbf0304b6, 0x3f1a39ec, 0xbe73199f, 0xbccca0a6, 0xbed21d5c, 0x3e0f89a0, 
    0x3e3a3e60, 0x3e83bc98, 0x3d9f0b9c, 0xbd3c7e49, 0xbee91ecd, 0x3e30690d, 0x3e8b021c, 0xbf0683e0, 
    0x3e0e2797, 0xbeee79d4, 0x3eacaa76, 0x3b9a96de, 0x3ef40c2e, 0xbee6e569, 0xbe94a6b7, 0x3efc3924, 
    0x3ef84953, 0x3e349193, 0x3e428ecc, 0x3d2172c8, 0xbe1381c6, 0x3e6d23f0, 0x3e9f75c5, 0x3f1046d1, 
    0x3dc69f83, 0x3e0097d3, 0x3f106d92, 0x3e2bfcc1, 0x3eda7292, 0xbd961ed5, 0x3e323a2d, 0xbe97dd79, 
    0x3e2f2779, 0xbecb25d3, 0x3e62e098, 0x3d672c70, 0xbbedf87f, 0x3f006b08, 0x3f11bc7c, 0x3e770a52, 
    0xbe1e523b, 0xbd8752fb, 0x3e90d33d, 0xbdf2d09c, 0x3dd91ad4, 0x3eab6bb6, 0x3ce0801c, 0xbefc4297, 
    0xbe968ce3, 0x3f124e17, 0x3e6fd532, 0xbea51ed6, 0xbecb7b0f, 0x3e9a3a0e, 0x3eee0212, 0xbde38d28, 
    0x3eeb41af, 0xbe666545, 0x3ec35832, 0xbe8133d7, 0xbd81a09b, 0x3e9ad6a7, 0x3da25d41, 0xbeb094f6, 
    0x3eb9a078, 0x3e94c331, 0x3bc061bf, 0x3e632599, 0xbe621394, 0xbe5e60f3, 0xbe6d2e2d, 0xbe99145d, 
    0x3e1114d7, 0xbe72aa17, 0xbd2ce71c, 0x3c5d20ca, 0xbda3c335, 0x3e829f06, 0x3ebc0594, 0xbd20a7e4, 
    0x3ea39cda, 0xbea9709b, 0xbeb856d8, 0xbe46a7ad, 0x3ec62df4, 0xbe6c98fd, 0x3d9fc805, 0xbd5a52a1, 
    0x3da90d90, 0x3e6f223d, 0x3ea5a852, 0x3eca1372, 0x3ead1133, 0xbeb44ce8, 0x3cf809b7, 0xbe999d94, 
    0x3d5646a4, 0xbed4f5b9, 0x3e3adfd3, 0x3dcd2252, 0x3e17efcc, 0xbebc9e8f, 0x3ec6b07d, 0x3e482d45, 
    0x3e80a86e, 0x3df34cca, 0x3e04418d, 0x3e3a4341, 0xbe78f859, 0xbe1cf301, 0xbe1700c5, 0x3e39b576, 
    0xbe939613, 0x3eb62f06, 0x3e91caed, 0x3e993c0f, 0x3c5a7b1c, 0x3d95b68c, 0xbea8b95c, 0x3ec499d6, 
    0x3e0c0a98, 0xbbac2458, 0x3df77b65, 0xbe90dbf5, 0x3ecd4885, 0x3eb380df, 0xbd17bac7, 0xbead6d32, 
    0x3e56c90f, 0xbe4c8d59, 0x3e3b653b, 0xbe61bb89, 0xbeafda90, 0x3ea66ea3, 0x3ecef676, 0xbed77765, 
    0x3b8d813a, 0xbd8c057a, 0xbec94056, 0xbecb379f, 0xbe93dbe5, 0x3e5c7e8a, 0xbeca9aae, 0x3e2fda08, 
    0xbc840ca1, 0xbe53609c, 0xbeaed0a6, 0x3e859131, 0x3ee8cb2a, 0xbdbb384b, 0x3e734260, 0x3e920471, 
    0x3dcf2e93, 0xbeb3d47b, 0xbee88a88, 0x3e57ed47, 0x3ed60366, 0x3ebd2bae, 0x3ea47b79, 0xbf0e268d, 
    0x3e9f83ec, 0xbd10e482, 0xbcebfae8, 0x3d42b453, 0x3df83183, 0x3eb3226c, 0x3e07e37c, 0x3f13c093, 
    0x3f1b70e5, 0x3ecf8960, 0x3ec18c91, 0xbe60cb1b, 0x3eaa6fe7, 0x3e376268, 0xbf113231, 0x3ee182f1, 
    0xbef15d4f, 0xbf16a1a7, 0x3e87d6c1, 0xbdff994b, 0xbe8d43a5, 0x3e7c25fd, 0x3e979717, 0x3e93dc48, 
    0xbebc136e, 0xbce85747, 0x3de21baa, 0x3ebaaa50, 0x3e4ff004, 0x3e8bb80d, 0xbe2f1959, 0xbdd30810, 
    0x3edfd1df, 0xbf11a1a4, 0x3e1f8d64, 0x3d8a2142, 0xbf1160e4, 0x3d65fbbb, 0x3e6796d2, 0xbf0812ec, 
    0x3e3bd1c7, 0x3dcfcc54, 0xbeacbd70, 0x3dd74a82, 0xbe798283, 0x3ce77cc9, 0xbeffd80d, 0x3ec03035, 
    0xbdd1b48d, 0x3de411e0, 0xbe2b85d7, 0x3eed0d57, 0xbd930152, 0xbe3c09ee, 0xbf0e1479, 0x3e249941, 
    0xbe8d92f9, 0x3ed37c0d, 0xbf17c5dd, 0x3e5e6429, 0x3f02d480, 0xbe649cdf, 0xbf01d5f9, 0x3d05c9a6, 
    0x3df2e9d1, 0x3ed4efdd, 0x3e4867b5, 0x3ec0310a, 0xbe3d7a06, 0xbf10abef, 0xbeb79fca, 0xbf007cdd, 
    0xbed3adb5, 0xbd1d2b5c, 0x3e57a365, 0x3ec735ab, 0xbdb58aac, 0xbddc7bf2, 0x3efc9b33, 0xbe417ae8, 
    0xbe489acc, 0xbf0821a2, 0x3e68b95d, 0x3e11704d, 0xbe9f46d3, 0x3cf0b21a, 0xbf081267, 0xbefab655, 
    0x3e1537cc, 0x3eb4e037, 0xbec648cb, 0x3ec08ce6, 0x3e40a5b5, 0xbe91a0c1, 0xbdad7332, 0xbea0527b, 
    0x3eae7420, 0x3e4ad4cd, 0xbe26a09e, 0x3d3e61a1, 0x3ec49e2e, 0x3edfef1a, 0x3e455e2f, 0xbb01d1d1, 
    0xbede3929, 0x3de28d45, 0x3e46728f, 0xbe8393bf, 0xbd45268c, 0xbd5fdf80, 0xbdfe2fd9, 0xbbfb2582, 
    0x3ea4e046, 0xbde8780d, 0xbeb94725, 0xbe8670cf, 0x3e3d6e84, 0xbe019a61, 0x3e8b32b0, 0xbe6b2a40, 
    0x3e8845c1, 0x3eabccb2, 0xbccf2b2e, 0xbe167dd0, 0xbe77671f, 0xbe362e57, 0x3e442583, 0xbe802c67, 
    0x3d8529c1, 0xbea02f27, 0x3d4ea4d0, 0x3e59be67, 0x3dd84397, 0x3e9b6f34, 0x3e6c095c, 0xbe131547, 
    0x3df4874c, 0xbe097c14, 0xbe2fa6c2, 0x3d822c12, 0x3e80ded5, 0x3e177135, 0xbe5f883c, 0xbde89c5c, 
    0x3e6e3748, 0xbd91f838, 0x3ea856d3, 0x3db13a20, 0xbb32685e, 0xbdeebd17, 0x3d4493f1, 0x3e3c3711, 
    0x3e515670, 0x3d5d6f67, 0xbe02e9a5, 0x3e458900, 0xbe68dfcc, 0xbdb0f7a8, 0x3e0f203e, 0x3ec72456, 
    0xbe8ed35d, 0x3eac4dbe, 0xbe4acbe3, 0xbe19fbf5, 0x3afd8280, 0x3e7c3f25, 0x3d337995, 0xbec049f6, 
    0xbed44dc2, 0x3e9f595d, 0xbde2b190, 0xbe1344a3, 0x3e99c490, 0xbe5cdaea, 0x3dcd07f9, 0xbc09ab5d, 
    0x3d977e27, 0xbe1ccd36, 0x3e5b0321, 0x3d9fa49b, 0x3df7dff4, 0xbe776f4c, 0xbe788a9e, 0x3ea77938, 
    0x3ededab0, 0xbe87cf85, 0x3dd8de72, 0xbdc5dc25, 0x3d33f4ef, 0x3ea3914d, 0x3dd305f1, 0x3bc6f40a, 
    0x3db1d34f, 0x3e3e8deb, 0x3c699d86, 0xbec4fd0a, 0x3eeb1063, 0xbe6dd18a, 0xbe6241e8, 0xbeab5b3a, 
    0x3e39cb56, 0xbc3eaa82, 0xbf05b5c4, 0xbe28b478, 0xbe929a49, 0x3d284116, 0xbe1956d1, 0xbe0268be, 
    0xbeec4cde, 0xbde4cefe, 0xbe14c9d5, 0xbe44a92d, 0xbf02b4e2, 0x3ee7a775, 0x3efd0bd6, 0xbeb8da09, 
    0xbdda00de, 0x3e8fbecc, 0xbe97fe3f, 0xbe0a09c5, 0x3ede06a6, 0x3e001802, 0xbdf5795a, 0x3cd127ee, 
    0x3f0201e8, 0x3ed863f7, 0x3e98b5c3, 0x3eccf63d, 0x3c3ca042, 0x3de10e48, 0xbdb5d4fe, 0xbdfbe794, 
    0xbed79334, 0x3f02fce0, 0x3da6e58f, 0xbe5411f3, 0xbecb7cc7, 0xbe962536, 0xbf081c73, 0xbf04b59e, 
    0x3ee6e800, 0x3d88c509, 0x3cdde28e, 0x3e6cd45d, 0xbe9ecb3d, 0x3dcec6c8, 0xbecd2b59, 0xbe790b52, 
    0xbe962b4f, 0x3e8566ab, 0xbea06a77, 0x3e236a52, 0xbec20f64, 0x3ea43a6b, 0x3e868b27, 0x3ed068a2, 
    0xbe55cddb, 0x3eefcd7d, 0xbefc2ac0, 0x3e5d782e, 0xbebc3715, 0xbe810a36, 0xbe4aa89d, 0xbe352b74, 
    0xbd0d8e1d, 0xbedb6d9c, 0xbf0e14d4, 0x3ee53801, 0x3e411089, 0xbe97cd16, 0x3ede252c, 0x3eb08316, 
    0x3f1175a3, 0x3e97e384, 0xbba3e4d2, 0x3e9edb36, 0xbdfeb1ff, 0x3d7b6e41, 0x3e7ef2b1, 0x3e837f1d, 
    0x3e0fe082, 0xbe3be8e4, 0x3ee7bbc4, 0xbdc2df85, 0xbe9d3c6e, 0x3e86fd5d, 0x3cd64770, 0xbebd6c88, 
    0x3e2f8b93, 0xbee08695, 0xbef4c93b, 0x3ea8ee20, 0xbee78715, 0xbd58fe67, 0x3e4abed0, 0xbed61669, 
    0x3eb416bb, 0x3f01e2a7, 0xbdfdf85c, 0x3c99edd2, 0x3eae5912, 0xb972fc85, 0x3e1521f5, 0xbeb9e38f, 
    0xbea1a0c7, 0xbe9ad1f6, 0x3dc657ed, 0xbe5e4795, 0x3d386787, 0xbe304bb8, 0xbee0fc47, 0xbed02550, 
    0x3eb463ca, 0x3ef606bc, 0xbc02ecaa, 0x3ea63a2f, 0x3e632251, 0x3eb0994b, 0xbde3e5e9, 0xbed20d13, 
    0xbeb062d3, 0x3e8d4a00, 0xbee1674b, 0x3e67c1a7, 0x3ef1eec5, 0x3e49a192, 0xbe4da0ee, 0x3e9854b7, 
    0x3eae913d, 0x3e484689, 0x3eb9f40d, 0xbebba61c, 0xbce40750, 0x3ea8c369, 0x3b8c40e8, 0xbeb4e239, 
    0x3e69aee9, 0xbedca959, 0xbbe25d37, 0xbdf84f08, 0x3defc256, 0x3eb30ca5, 0xbdd5dc6d, 0xbdc97716, 
    0x3ee80b70, 0x3e320f76, 0x3ee1996f, 0x3c0a780b, 0x3ef96c4c, 0xbba467d5, 0xbe59c243, 0xbeebdd25, 
    0x3eb3c6bb, 0x3ca5a072, 0xbcb86cfe, 0x3c77a0cf, 0xbe849598, 0x3e4622c9, 0x3cf72902, 0xbd9743ed, 
    0x3bfff6e9, 0x3edf4270, 0xbd95d24d, 0x3e8851b7, 0x3e849ffe, 0x3c9ff63e, 0x3e1c8ecd, 0x3ed73aef, 
    0xbe541015, 0x3e5a571e, 0xbe4f11a6, 0xbe8ecb72, 0xbd204040, 0xbd9d42c8, 0x3ee970a1, 0xbe879470, 
    0xbdc8de44, 0xbd25c3a5, 0xbea4d7f6, 0x3edb05f6, 0x3e717b19, 0xbe9ba9bc, 0x3e9eafc8, 0x3e4e1205, 
    0xbe240d95, 0xbeb31b07, 0xbc2bdc61, 0xbda80d5f, 0xbda60558, 0xbdd194a4, 0x3d5c5f16, 0x3b595e2d, 
    0xbeafa494, 0x3d1201e3, 0x3ea43335, 0x3eadcc01, 0x3e5957a1, 0x3ea340ff, 0xbe4c5945, 0xbe1f8372, 
    0x3ea1c39b, 0x3e72c9b8, 0x3bf352d5, 0x3c71111d, 0xbd1dd3cb, 0x3c82eded, 0xbe9d8258, 0x3e39fe69, 
    0x3e97a682, 0xbdb546d7, 0xbe5d2857, 0xbe8be8b0, 0x3cb27582, 0x3ea09319, 0xbea61d3e, 0xbe4acdd6, 
    0xbdc65015, 0xbd432bfd, 0xbe11f52d, 0xbe91d19c, 0x3eb5c74c, 0x3eb79a3f, 0x3e832e96, 0x3da9681f, 
    0x3e9e2f5a, 0x3e77a122, 0x3cdef642, 0xbda063c5, 0xbe8e7103, 0x3ccecc0a, 0x3e960ad1, 0x3e74efa5, 
    0x3eb7e7da, 0xbd72af64, 0xbda97369, 0xbeb68d5b, 0xbd5d13d2, 0x3dfbbb2f, 0xbca8fe09, 0x3db19655, 
    0x3e963de0, 0xbe915209, 0x3de2f41d, 0xbd38bf4f, 0x3bae2929, 0xbe116f31, 0x3e9e0edc, 0x3d4739c6, 
    0xbdecd412, 0x3dee6608, 0xbe51350e, 0xbe723a6c, 0x3e651adc, 0x3e24a14f, 0x3e8cf2f1, 0xbca283f1, 
    0xbebf0c42, 0xbe181a8d, 0xbe076b31, 0x3e7c1648, 0x3e91e846, 0x3d4feaaa, 0xbdf03805, 0xbe82ec81, 
    0x3e904319, 0x3de74611, 0x3de13c7f, 0xbeb21775, 0xbe5e4fb2, 0x3ea836bc, 0x3e03f382, 0x3e7ddafd, 
    0xbcd6e54e, 0xbdf3785e, 0x3eb12b8b, 0xbcb9ce90, 0x3e7aa09b, 0x3db3cf1b, 0x3eba231e, 0xbe4dc543, 
    0x3d731837, 0xbe89f2d5, 0x3e63f66a, 0xbefe6639, 0x3ec3ec41, 0x3e7d0a59, 0xbe6e54dd, 0x3e932d47, 
    0xbe0c1eef, 0x3e8c650d, 0x3e9cc97f, 0x3d95309d, 0xbe558244, 0x3e6d4062, 0xbe445a51, 0xbede4734, 
    0xbecf99ea, 0x3d635568, 0xbe970fa2, 0x3e57c371, 0xbebad1ce, 0xbd6639ff, 0xbdc5b68c, 0xbdbb99d8, 
    0x3e33f111, 0x3d21b6ef, 0x3e4164d4, 0xbe8ff72c, 0x3edca122, 0xbe0a1718, 0x3ebdcb2b, 0x3db3a735, 
    0xbec18be5, 0xbd8d96f2, 0xbd29b8f9, 0xbdfa1081, 0x3e2e22ee, 0x3cfe8e7f, 0x3dff4aa2, 0x3ea8416b, 
    0x3ebafd0c, 0xbe6cabbd, 0x3d241904, 0x3ea19a8b, 0xbea32246, 0x3ea7263c, 0xbe6877aa, 0x3ec50455, 
    0x3e1b9b73, 0xbd3e6ad8, 0xbd8e81d4, 0x3edb3ef6, 0x3deb4810, 0x3e99ddbe, 0x3e7ccf8c, 0xbe5f2058, 
    0xbd4d9ee8, 0xbe5ef91b, 0xbec71fe1, 0xbe2afb57, 0xbe9288c3, 0xbe7166cd, 0x3dce6676, 0xbddbc9a5, 
    0xbe4244c0, 0xbea7b3bc, 0xbe2262f5, 0xbd728058, 0xbdea7e41, 0xbecf3bb1, 0x3eca606b, 0xbd8146a9, 
    0x3eb27d0a, 0xbec58aeb, 0xbdc89e2b, 0xbe9e81fd, 0xbedd3a31, 0xbe41ad3f, 0x3dae12a9, 0xbe2dd2f3, 
    0xbe5b9694, 0xbe013f0b, 0xbe12ff19, 0x3d2ee288, 0x3e361d3e, 0xbe8134ad, 0xbee98816, 0x3cf0f26e, 
    0x3dcf3ed1, 0xbe89bbbc, 0xbe86cacd, 0xbec39145, 0x3e9768a9, 0xbe601b9a, 0x3e6e8a1d, 0x3e288a86, 
    0x3ec7bda5, 0x3e05aa14, 0xbe9b9ab4, 0xbe8bbd04, 0xbe7b7032, 0x3d255f92, 0x3e930f54, 0xbe49b4c1, 
    0xbdb3a616, 0xbc593afb, 0xbe1cf93e, 0x3e50514f, 0x3e9b3b32, 0xbe7e3ebb, 0x3b12415c, 0xbda07d6f, 
    0x3ebbfc08, 0xbe23ac1f, 0xbe9c8c99, 0x3ceb5d6f, 0x3e9d1f47, 0x3e6011ba, 0x3c99f0ca, 0x3ea1d5f1, 
    0x3e1d509b, 0xbeaf698c, 0xbdad121c, 0xbe46a3e8, 0x3ed77c3a, 0xbe60ffd1, 0x3e9f565f, 0x3e1f465f, 
    0xbe6931f6, 0xbebef7ee, 0x3e910cde, 0x3e272d19, 0xbe02f0b7, 0x3e3c548a, 0x3da23a3a, 0xbea554e8, 
    0x3ddf0a77, 0xbe105b87, 0x3e7691c4, 0x3ea567d6, 0x3d9c2a20, 0xbda02b36, 0xbd60b23c, 0xbd990728, 
    0xbea181db, 0xbe42b17d, 0x3cf9b624, 0x3d816fbe, 0xbe8fc8b2, 0xbd7985e1, 0x3e8de71d, 0xbecf1dbc, 
    0xbe82af5d, 0xbd4fd941, 0xbd626705, 0x3eaeba46, 0x3ed58c1b, 0xbde12e65, 0xbd4e158a, 0x3df8e204, 
    0x3e975be4, 0xbe8770dc, 0xbe98f26a, 0xbea1502b, 0xbe7c67e7, 0x3dc09c30, 0x3e47f120, 0xbe1cc138, 
    0xbeb12277, 0x3e24d0b9, 0x3e18a50c, 0xbe8411b5, 0x3e511037, 0x3d3a9d52, 0xbdab7564, 0xbe74b4ad, 
    0x3e29f295, 0xbe862c94, 0xbecb4d19, 0x3e92f2f2, 0xbea383dd, 0xbeaa32c4, 0xbe142400, 0x3e9da5d6, 
    0x3ead5a97, 0x3ec81a45, 0xbe9ec590, 0x3e9438d5, 0x3e9fe79c, 0xbd4ce533, 0x3ceaa005, 0xbeda5958, 
    0xbec9712b, 0xbe87febc, 0xbedf2297, 0xbe25adb7, 0x3e7323cf, 0x3e6d8b9c, 0xbe9a23f2, 0x3eb9dad9, 
    0x3e4bb707, 0x3e2da5bc, 0xbe489e87, 0x3e5e32b2, 0xbd4dea66, 0xbe91740c, 0xbeac27a9, 0xbee21bff, 
    0x3ebecb53, 0xbda8eb61, 0x3c6d5b65, 0xbe762058, 0x3e89fa3b, 0xbeb3c896, 0xbdb3f621, 0x3e17928c, 
    0xbe270229, 0xbc877e45, 0x3eb5e19f, 0xbdac9d2f, 0xbdbeb335, 0xbe911629, 0xbe9ff087, 0xbeb51cfa, 
    0x3eb353e3, 0x3eb4b0e2, 0xbed60d8d, 0xbee6f7f6, 0xbf054561, 0x3e87fd6d, 0x3e03ca6f, 0x3ee93098, 
    0xbecf583a, 0x3ef5d385, 0xbd55fc99, 0x3e9a055b, 0x3e795c0d, 0xbea250a8, 0xbe02e56f, 0xbec24e09, 
    0x3e95fc35, 0xbec3263b, 0xbeebd60e, 0xbe32d6d7, 0x3d7e1d05, 0xbea2afc9, 0xbe246fe5, 0x3e9d0aab, 
    0x3eb9c751, 0xbeb5a937, 0x3dcc765d, 0xbed540d3, 0x3d4d5bdb, 0xbe1cab3e, 0xbea0318e, 0x3df32595, 
    0x3ee72c36, 0xbcc3cc39, 0xbd71f2ed, 0xb9df2e27, 0xbe8a8a2e, 0x3e1b371c, 0xbe8f574b, 0xbe5751f1, 
    0x3ea38ddf, 0x3e537626, 0x3ef62743, 0x3c8bd7b2, 0x3e6663d7, 0xbdfe54a4, 0xbe349b4f, 0x3e2dc3c6, 
    0x3ea7b9d5, 0xbf046722, 0x3dfa54f6, 0x3ad61b58, 0xbd9c749f, 0x3ece5623, 0x3e8aa336, 0x3dec4879, 
    0x3e8ad619, 0xbbbc85da, 0xbeecaa7d, 0x3ea529fc, 0xbe879dbc, 0x3ef2e03e, 0x3e5aeda8, 0x3e821f37, 
    0xbdba16f6, 0xbb48e8a5, 0xbe14dc94, 0x3e3930f7, 0xbdacf8bf, 0x3e542eef, 0x3e53e2a8, 0x3e9114fd, 
    0x3ec32f09, 0x3e493df7, 0xbe9c48d1, 0xbdbcd256, 0x3ed78ae4, 0xbed6d7a0, 0x3d5b35d0, 0x3ebb50f3, 
    0xbe836d39, 0xbe32fcb8, 0xbed9f5ab, 0x3eafb039, 0xbee49791, 0xbe93d6a7, 0x3e890502, 0xbe6d9afb, 
    0x3d4c1bae, 0x3ec62610, 0x3eaa9690, 0x3e896982, 0xbd9b7d86, 0xbebdb158, 0xbed39171, 0xbc592aa3, 
    0x3e4a6dcb, 0x3ed4b9c6, 0xbeb7204b, 0xbe905d1c, 0xbebff35a, 0xbd1023cd, 0x3e8eacb6, 0xbc10a12c, 
    0x3ea7d542, 0x3f030c99, 0xbe28304c, 0x3ecc7a20, 0x3dfe5b8f, 0xbd780085, 0xbe5eec17, 0x3d8bc76c, 
    0x3df954bc, 0x3ed15247, 0xbedd7a39, 0xbc49af34, 0x3d36a533, 0x3e8b6607, 0xbca57bd9, 0x3ed9b34e, 
    0x3ec8fbea, 0x3ed82899, 0x3ea63f55, 0xbeaa7280, 0xbec9ce4f, 0x3e8ae867, 0xbecace4d, 0xbdeaaab7, 
    0x3eafee98, 0x3e5eab38, 0xbeda3353, 0xbe5f7b1c, 0xbe928de9, 0x3ea7f5d7, 0xbe81d8ae, 0xbee2a7b6, 
    0x3d3101b7, 0x3e1125b1, 0x3e111e99, 0xbeba26b6, 0xbebd97bf, 0xbd463b4a, 0xbe109c88, 0x3edd5aa5, 
    0xbeabdb69, 0x3ed71d3a, 0xbeea4a8c, 0xbdbfb29f, 0x3d8aba34, 0xbdcab8a9, 0xbe0812ba, 0xbeb65c15, 
    0x3ed7a0b6, 0xbe0c95ee, 0x3dbc4414, 0x3e61730f, 0xbebec1f2, 0x3ee5cc95, 0xbf0990ac, 0xbf098859, 
    0xbef5499b, 0x3dc1a913, 0xbf0103ac, 0x3e5a948f, 0x3eb7cefa, 0x3edb41d1, 0xbe065553, 0x3e9b699c, 
    0x3e9e0a43, 0x3e5df26e, 0xbdd8e346, 0xbe6c0fb3, 0xbf10c04a, 0x3e25fe54, 0xbcaadceb, 0xbe998f7b, 
    0xbedb7168, 0xbe321c76, 0xbf0a5162, 0xbc51a262, 0x3e9643fc, 0x3ec8870e, 0xbe70588e, 0xbe69e08b, 
    0xbe1e9d30, 0x3f092388, 0xbdc856ed, 0xbe5ad891, 0xbed0e76c, 0x3e02961d, 0x3cecc552, 0xbe8888fe, 
    0xbe995720, 0x3e8d19c4, 0xbef88a61, 0x3e5e5632, 0xbf125371, 0x3e9d3eb0, 0xbb485888, 0xbe0f7789, 
    0xbe86ae27, 0x3f027029, 0x3f077734, 0xbebb031e, 0xbeb49879, 0x3e9213f7, 0x3d3ba7d3, 0x3e23bff8, 
    0x3e8aa4c9, 0x3e9db1e6, 0x3eddeef1, 0xbe7bb67f, 0x3e41dcef, 0xbf31e78d, 0x3e869a99, 0x3e0db48e, 
    0x3f0de141, 0xbefe2c03, 0xbe0b8048, 0xbe25138e, 0x3ed934b6, 0xbefb2de0, 0xbf160dfe, 0x3e3c3bc0, 
    0xbd5e552b, 0x3ebc4181, 0x3ea06a10, 0x3f07ce5a, 0xbdb8bb69, 0xbec80fd9, 0x3e722602, 0xbe122105, 
    0x3dd9c25b, 0x3e743a7b, 0x3f077715, 0x3ea65cfd, 0x3ef3b772, 0x3e5c80b6, 0x3f17db08, 0x3eba2fa0, 
    0x3e53e7cd, 0x3e2cc7fa, 0xbe7fa9d8, 0xbe3c46e6, 0xbec73a0b, 0xbda558f7, 0x3dd7deab, 0x3c36a50a, 
    0x3c8d68a1, 0x3a95f941, 0x3ed31d78, 0xbe9339a6, 0x3f002acd, 0x3f05d708, 0x3d8b3aee, 0xbea62818, 
    0x3d986cdc, 0x3e1232dd, 0xbedbd9cc, 0x3f026346, 0xbeb5498f, 0xbe5f9c37, 0x3ea30dbb, 0x3ee9a1bb, 
    0xbf0628da, 0x3ea034a4, 0xbed68662, 0x3e1ce8ea, 0x3efe0ec5, 0x3e0c0603, 0xbdaec483, 0x3e664970, 
    0xbefebbd0, 0xbe097125, 0xbe9b0f08, 0xbe6986d7, 0x3ee0747d, 0x3e79d911, 0xbea6a088, 0x3e362d19, 
    0xbdbe6b8a, 0xbeca5cc6, 0x3e7a7027, 0xbe51b00f, 0x3ebff28e, 0x3e58a304, 0x3d86eb08, 0xbed8d25e, 
    0x3dd2f741, 0xbd4710d1, 0x3e502c4b, 0x3ddc6c41, 0xbeabc170, 0x3d8847f6, 0x3d6f812e, 0xbeb999b7, 
    0xbe022c77, 0xbea099dc, 0xbee08e42, 0xbe333b8e, 0x3ebc4543, 0xbcec6622, 0xbdc7274b, 0xbc9f4eca, 
    0x3ee093a4, 0x3dc44659, 0xbe7ec102, 0x3e3174e4, 0x3da3faf1, 0xbed11dc6, 0x3ee4793a, 0xbe90cf4e, 
    0xbd261032, 0xbddf7118, 0x3e83398e, 0xbe992a0e, 0xbeb68cf3, 0x3e1d473d, 0xbd9eee25, 0x3e495bee, 
    0xbef5ef3e, 0x3ec8f493, 0x3df2c2d8, 0xbddb8d33, 0x3dbe1e8c, 0x3ea712d3, 0xbe7b92ad, 0x3e83a50a, 
    0xbcb979ab, 0xbe0ba78b, 0x3d751848, 0xbe8cf15b, 0xbe1a0adc, 0x3e156c92, 0x3e9d1832, 0x3c51a005, 
    0x3e1e469c, 0xbe796b86, 0xbe298ba8, 0x3e805b3c, 0xbef6cac9, 0xbeb63612, 0xbe8902bc, 0xbdcfdcc2, 
    0xbdabbd05, 0x3be91956, 0x3ee9676b, 0xbde9a242, 0x3dfeb703, 0x3ed7c1e6, 0xbe881799, 0x3ee36d9a, 
    0x3edf7444, 0xbe092ee1, 0xbe741202, 0x3e1ecd8f, 0x3dc1c804, 0x3e93794b, 0x3e87da69, 0x3e667c59, 
    0x3d704d00, 0x3e9f6cda, 0xbe3806f2, 0xbdc43abb, 0xbd73d2e1, 0xbe41d76b, 0xbeb85f4b, 0xbed157aa, 
    0xbee8df6d, 0x3e0304c6, 0xbe6a7b1e, 0x3ca0af58, 0xbdcafefe, 0xbe9a4644, 0xbdb231b9, 0x3dee52b5, 
    0xbe22dd0f, 0xbf001061, 0x3ed39b93, 0x3ee507cf, 0x3d8f8db8, 0xbebb5490, 0x3ca787a8, 0xbe8ae627, 
    0xbef03aaa, 0xbec7045b, 0x3eccd305, 0x3e8140a1, 0xbf14b14f, 0xbd0f89e0, 0xbe8e52f8, 0x3e667fae, 
    0x3e869052, 0xbde4df0a, 0x3e42fb69, 0xbe900e66, 0xbec360bc, 0x3ef137e3, 0x3e0f704f, 0x3e96a636, 
    0x3ebde176, 0xbd8120e1, 0x3ebbe6d1, 0x3f00f290, 0x3ce1624c, 0x3efd3075, 0xbd65a305, 0x3f038cd8, 
    0xbe88b5a1, 0xbe8d6568, 0x3ec55703, 0x3ed50955, 0x3dce0e11, 0xbcac7bbc, 0xbe1b374c, 0xbdb84b65, 
    0xbef1587a, 0x3d516c87, 0x3eb00582, 0x3ce124e4, 0xbeccf530, 0x3d4e3c6a, 0x3dad67df, 0x3d131878, 
    0x3e7d0ca6, 0xbcb31921, 0x3de5e476, 0x3e6ce9da, 0xbe6f9545, 0x3ea2dc7d, 0xbe92e198, 0xbec228e7, 
    0x3e895aaf, 0x3e73404d, 0x3d733ec1, 0x3deb0c0d, 0x3d93b1e3, 0x3eca1d9d, 0x3ee633cd, 0x3df1b648, 
    0x3daed84b, 0x3eaf41bf, 0xbd6c228d, 0xbddd7755, 0xbe3eeacf, 0x3e9dec2f, 0xbe52c37c, 0xbe5c474e, 
    0xbe9c22c7, 0x3e81fe06, 0x3d9e0bea, 0x3eb162f9, 0xbe53d888, 0x3ec27751, 0xbc38be72, 0xbe9711b3, 
    0x3e11f8be, 0xbe16a601, 0x3e180fb1, 0xbe599bfe, 0x3e1f62c5, 0x3e2c28b9, 0x3d6c1720, 0x3e64fdab, 
    0xbec2c438, 0xbe80dc26, 0xbe3c6b38, 0x3d3ae057, 0x3c8cf2ce, 0xbe0f4278, 0x3ea5868d, 0xbeaf6315, 
    0xbd824272, 0xbee407e4, 0x3b23c797, 0x3ee89ebc, 0x3ebd17e6, 0x3d9cd6b5, 0x3e4e4868, 0x3e9da53f, 
    0x3e5007be, 0x3ebef591, 0x3e0db8e9, 0xbe0b8511, 0xbe1962b6, 0x3eac94da, 0x3edc8dc2, 0x3e9e3f5f, 
    0xbebbc548, 0xbe887956, 0x3e94fcbd, 0x3e562a7b, 0xbe8be4a1, 0x3c98987d, 0xbd266aef, 0x3de70877, 
    0x3e5a5187, 0x3eb52e68, 0xbe31acc8, 0xbe3d4e4d, 0x3ebaaf53, 0x3e7ec085, 0xbe9e60d9, 0x3d111b48, 
    0xbdaada29, 0x3ede24b1, 0x3e47d907, 0x3e99b0c0, 0xbba7a0ca, 0x3e673836, 0x3d104b16, 0xbd607f4f, 
    0xbe81ad8f, 0x3e55879d, 0xbe7a5f0b, 0x3e71128f, 0x3ec43de4, 0xbd9ab10c, 0x3e191445, 0xbeae6134, 
    0xbec11f25, 0x3ee7fcf5, 0xbebb03f0, 0xbe1e5559, 0xbe6013d5, 0x3ddb9dd7, 0x3dd51b5e, 0xbe6ad9b5, 
    0x3e0560ec, 0xbec1986d, 0x3e7e7386, 0xbdc886a7, 0x3e861e5b, 0x3e84b101, 0x3e5d4e5a, 0xbeef6e94, 
    0x3eeff422, 0x3e33ade8, 0xbe0c22c9, 0xbee29ed5, 0xbe90287a, 0xbebe6c1d, 0xbea3f5d3, 0xbec6b0ee, 
    0xbd94583c, 0x3e30360e, 0xbeab6cf9, 0x3e822301, 0x3e86cd1c, 0x3d8eab5b, 0xbe0ae028, 0x3cf865bd, 
    0x3e8a609e, 0xbe3ca23a, 0x3e5875b9, 0xbe737235, 0x3da92357, 0xbdce4cf4, 0xbdf099f7, 0x3e856559, 
    0xbed308a4, 0xbe631237, 0x3e3ad023, 0x3ee837f4, 0xbe7598dd, 0xbce4786c, 0xbea74c7f, 0x3e0c0a14, 
    0x3e80cf92, 0x3e92132c, 0xbcf14275, 0x3d94af3e, 0x3d22450c, 0x3e5b982c, 0xbeaf9178, 0x3e4a4306, 
    0xbd90da35, 0xbe9248c0, 0xbeacdb03, 0x3eb2fe43, 0xbe51ca19, 0xbb9785b2, 0xbe06437b, 0x3d9288c9, 
    0xbb72da83, 0x3e279b76, 0x3d93cd74, 0x3e35792a, 0x3ec75554, 0xbd85caf3, 0xbe949474, 0x3e7568b0, 
    0xbe9bc338, 0xbebb2906, 0xbcda6962, 0xbe76e519, 0x3ebff38f, 0x3e8f0e4e, 0x3d8b7b75, 0x3ec3f341, 
    0xbe6a6c8f, 0x3dd3cac1, 0x3e94a88b, 0x3e7c4ec6, 0xbe80a4b5, 0xbed905e7, 0x3d437f56, 0xbdbf8887, 
    0x3c9a40bb, 0x3e4b82ad, 0x3e9f59c3, 0xbe919a6d, 0xbec8df12, 0xbe62e661, 0xbeaeecfe, 0x3ebc7536, 
    0xbe560043, 0x3dfff4b7, 0x3d9c0501, 0xbbebadae, 0x3e424a1e, 0xbe576b84, 0x3eecbf0d, 0xbe18a294, 
    0x3df211c1, 0x3d5f4ddb, 0x3e1c486a, 0xbe4e1cb2, 0x3ee272da, 0x3e0f03a5, 0x3e292e09, 0xbe9c34ff, 
    0xbe105ca5, 0xbec4dec5, 0x3eb5e658, 0xbc8cfecb, 0x3eab8de2, 0xbe748506, 0xbe042be1, 0xbeb4a599, 
    0x3e14c299, 0x3d8a37b5, 0xbeac5b4b, 0x3de62145, 0x3ad312a4, 0x3ea0c261, 0x3a9f89d3, 0x3d4c7d17, 
    0xbe68f1a8, 0xbda601fb, 0x3ec2f4db, 0x3e060aa5, 0xbeb5385b, 0x3eb3c715, 0xbeb2262f, 0xbe719d03, 
    0xbd63c6b9, 0xbe2e569f, 0xbe9b07f8, 0xbec04d7b, 0x3eb377e2, 0xbe41e833, 0xbecf0957, 0xbe8f00d4, 
    0x3eae180f, 0xbebaf5e1, 0xbe7b3310, 0xbbcf9d9a, 0x3e11cc30, 0x3eaec434, 0xbe8f655b, 0xbea40e3c, 
    0x3d5d4373, 0x3e43aee0, 0x3e663d85, 0x3e0dab0f, 0xbeacaf78, 0xbe95b3d9, 0xbe646ef2, 0xbe1058e5, 
    0x3e988518, 0x3ec40277, 0x3df01ffb, 0x3e1aea00, 0xbebc8480, 0xbdc3655b, 0xbea30ff3, 0x3e76aa85, 
    0x3eab4943, 0x3e813f7b, 0xbe2584d8, 0x3e24ea27, 0x3e036d91, 0x3b77436f, 0x3c3b1ca8, 0x3e953124, 
    0x3eb1913b, 0x3e4326bc, 0xbec1ea64, 0xbe53a8d0, 0x3d2038ff, 0xbe4bc8d0, 0xbc3fa2b0, 0xbecd9c5b, 
    0x3d8c876a, 0x3c2e003c, 0x3ea4fd5f, 0x3e13936b, 0x3b18c617, 0x3e8edcd4, 0xbd216e11, 0xbeeec08b, 
    0xbeb2d867, 0xbdbdb7da, 0x3ea47249, 0xbe1084ae, 0x3e3ea8a0, 0x3ea5b8d0, 0x3e621bb1, 0x3e058140, 
    0xbe8623b8, 0x3ec47d3f, 0x3e9f9d35, 0x3e181e64, 0x3eaa4d0f, 0x3eafaac5, 0xbe4b15b8, 0xbe4a2df2, 
    0x3e9cac34, 0x3edb20dc, 0xbb6f7f5d, 0x3e41705a, 0x3e15bef6, 0x3e8fed2e, 0xfffffe16, 0x00000004, 
    0x00000030, 0x3f122068, 0x3f8060a4, 0x3e33430c, 0x3e245336, 0x3eb394ce, 0xbe24f1a6, 0x3ed758da, 
    0x3f21eea4, 0xbd52c2df, 0x3e051006, 0xbe8275a2, 0xbf159c1d, 0xfffffe52, 0x00000004, 0x00000060, 
    0xbe2b50a9, 0xbf6d4e22, 0xbe2f6032, 0x3eed6ee2, 0x3f502559, 0xbf243565, 0xbf23227a, 0x3ed81623, 
    0xbd684552, 0xbdc9a9a8, 0x3f3d4b14, 0xbe495fd0, 0x3f839dc6, 0x3e391978, 0x3ffe38c9, 0x3ead68a5, 
    0xbe79e6ff, 0x3f8b0e1e, 0x3e4c75a9, 0xbf3bf003, 0xbd95a828, 0x3e86db74, 0x3eb1e726, 0x3ee60e3a, 
    0xfffffebe, 0x00000004, 0x00000080, 0xbfa0d8ce, 0x3f5c8107, 0x3dddbbf7, 0x3f0c2a2a, 0xbf19ed5d, 
    0x3f45177d, 0xbf4c651b, 0xbe992f10, 0x3e2ce82d, 0x3f23b213, 0xbe48d856, 0x3c2b2f34, 0x3f0bc148, 
    0x3fe8b9b9, 0x3faddda7, 0xbf886868, 0xbe26df5e, 0x3fa0e24b, 0xbf58cd7c, 0xbe3cb4df, 0x3eca35dd, 
    0xbf26ef32, 0x3f817bb9, 0x3f224582, 0x3f906cd7, 0x3f0a4d91, 0xbf04d5c2, 0x3ef830ad, 0xbf141423, 
    0xbf91b4dc, 0x3eeeb938, 0xbda236a2, 0xffffebe8, 0xffffebec, 0x0000000f, 0x52494c4d, 0x6e6f4320, 
    0x74726576, 0x002e6465, 0x00000001, 0x00000014, 0x000e0000, 0x00140018, 0x000c0010, 0x00040008, 
    0x0000000e, 0x00000014, 0x0000001c, 0x000003dc, 0x000003e0, 0x000003e4, 0x00000004, 0x6e69616d, 
    0x00000000, 0x00000010, 0x000003a0, 0x00000344, 0x000002e4, 0x000002a0, 0x0000025c, 0x00000238, 
    0x000001e4, 0x000001c0, 0x0000017c, 0x00000138, 0x00000114, 0x000000d0, 0x000000ac, 0x00000078, 
    0x00000040, 0x00000004, 0xfffffd06, 0x0000001c, 0x09000000, 0x0000001c, 0x00000020, 0x00000005, 
    0x00060000, 0x00040008, 0x00000006, 0x3f800000, 0x00000001, 0x00000024, 0x00000001, 0x00000023, 
    0xfffffd3e, 0x00000014, 0x08000000, 0x00000010, 0x00000014, 0x00000004, 0xffffecd4, 0x00000001, 
    0x00000023, 0x00000003, 0x00000022, 0x00000011, 0x00000012, 0xfffffd72, 0x00000014, 0x1b000000, 
    0x00000010, 0x00000014, 0x00000003, 0xffffed08, 0x00000001, 0x00000022, 0x00000002, 0x00000021, 
    0x00000013, 0xfffffd46, 0x00000008, 0x0000000c, 0x00000001, 0x00000021, 0x00000002, 0x00000020, 
    0x00000008, 0xfffffdc2, 0x00000014, 0x05000000, 0x00000024, 0x00000028, 0x00000002, 0xfffffefe, 
    0x00000002, 0x00000001, 0x00000002, 0x00000001, 0x01000000, 0x00000001, 0x00000020, 0x00000001, 
    0x0000001f, 0xfffffda6, 0x00000008, 0x0000000c, 0x00000001, 0x0000001f, 0x00000002, 0x0000001e, 
    0x00000009, 0xfffffe22, 0x00000014, 0x01000000, 0x0000001c, 0x00000020, 0x00000001, 0xfffffe70, 
    0x01000000, 0x00000001, 0x00000001, 0x00000001, 0x0000001e, 0x00000003, 0x0000001d, 0x00000004, 
    0x00000001, 0xfffffe62, 0x00000014, 0x01000000, 0x0000001c, 0x00000020, 0x00000001, 0xfffffeb0, 
    0x01000000, 0x00000001, 0x00000001, 0x00000001, 0x0000001d, 0x00000003, 0x0000001c, 0x0000000c, 
    0x0000000d, 0xfffffe46, 0x00000008, 0x0000000c, 0x00000001, 0x0000001c, 0x00000002, 0x0000001b, 
    0x0000000a, 0xfffffec2, 0x00000024, 0x05000000, 0x00000034, 0x00000038, 0x00000002, 0x000e0000, 
    0x00170018, 0x000c0010, 0x00040008, 0x0000000e, 0x00000002, 0x00000001, 0x00000002, 0x00000001, 
    0x01000000, 0x00000001, 0x0000001b, 0x00000001, 0x0000001a, 0xfffffeb6, 0x00000008, 0x0000000c, 
    0x00000001, 0x0000001a, 0x00000002, 0x00000019, 0x0000000b, 0xffffff32, 0x00000014, 0x01000000, 
    0x0000001c, 0x00000020, 0x00000001, 0xffffff80, 0x01000000, 0x00000001, 0x00000001, 0x00000001, 
    0x00000019, 0x00000003, 0x00000018, 0x00000005, 0x00000002, 0xffffff72, 0x00000014, 0x01000000, 
    0x0000001c, 0x00000020, 0x00000001, 0xffffffc0, 0x01000000, 0x00000001, 0x00000001, 0x00000001, 
    0x00000018, 0x00000003, 0x00000017, 0x0000000e, 0x0000000f, 0xffffffb2, 0x00000020, 0x01000000, 
    0x00000028, 0x0000002c, 0x00000001, 0x0010000c, 0x000c0000, 0x00070008, 0x0000000c, 0x01000000, 
    0x00000001, 0x00000002, 0x00000001, 0x00000017, 0x00000003, 0x00000016, 0x00000006, 0x00000003, 
    0x000e0000, 0x0014001a, 0x000c0010, 0x0004000b, 0x0000000e, 0x00000020, 0x01000000, 0x00000028, 
    0x0000002c, 0x00000001, 0x000a0000, 0x000f0010, 0x00040008, 0x0000000a, 0x00000001, 0x00000002, 
    0x01000000, 0x00000001, 0x00000016, 0x00000003, 0x00000015, 0x00000010, 0x00000007, 0x000a0000, 
    0x0000000c, 0x00040008, 0x0000000a, 0x00000008, 0x0000000c, 0x00000001, 0x00000015, 0x00000002, 
    0x00000000, 0x00000014, 0x00000001, 0x00000024, 0x00000001, 0x00000000, 0x00000025, 0x00000fd0, 
    0x00000f7c, 0x00000f40, 0x00000f04, 0x00000ebc, 0x00000e74, 0x00000e2c, 0x00000df0, 0x00000db0, 
    0x00000d58, 0x00000d18, 0x00000cd4, 0x00000c88, 0x00000c48, 0x00000bfc, 0x00000bbc, 0x00000b70, 
    0x00000b2c, 0x00000aec, 0x00000aac, 0x00000a40, 0x000009cc, 0x00000900, 0x000007c8, 0x00000700, 
    0x000005c8, 0x0000055c, 0x000004f4, 0x00000480, 0x000003b4, 0x00000278, 0x0000020c, 0x000001a4, 
    0x00000140, 0x000000e0, 0x00000050, 0x00000004, 0xfffff0da, 0x01000000, 0x00000010, 0x00000010, 
    0x00000025, 0x00000028, 0xfffff0c4, 0x00000019, 0x74617453, 0x6c756665, 0x74726150, 0x6f697469, 
    0x4364656e, 0x3a6c6c61, 0x00000030, 0x00000002, 0x00000001, 0x00000005, 0xfffff122, 0x01000000, 
    0x00000010, 0x00000010, 0x00000024, 0x0000006c, 0xfffff10c, 0x0000005e, 0x65646f6d, 0x6f632f6c, 
    0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f302d, 0x72657961, 0x2f39315f, 
    0x4d74614d, 0x6d3b6c75, 0x6c65646f, 0x6e6f632f, 0x2d643176, 0x6964656d, 0x622d6d75, 0x6e616c61, 
    0x2d646563, 0x616c2f30, 0x5f726579, 0x422f3931, 0x41736169, 0x00006464, 0x00000002, 0x00000001, 
    0x00000005, 0xfffff1ae, 0x01000000, 0x00000010, 0x00000010, 0x00000023, 0x0000003c, 0xfffff198, 
    0x0000002c, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 
    0x6c2f302d, 0x72657961, 0x2f38315f, 0x6e61654d, 0x00000000, 0x00000002, 0x00000001, 0x00000020, 
    0xfffff20a, 0x01000000, 0x00000010, 0x00000010, 0x00000022, 0x0000003c, 0xfffff1f4, 0x0000002f, 
    0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f302d, 
    0x72657961, 0x2f36315f, 0x65757153, 0x00657a65, 0x00000003, 0x00000001, 0x00000003, 0x00000020, 
    0xfffff26a, 0x01000000, 0x00000010, 0x00000010, 0x00000021, 0x0000003c, 0xfffff254, 0x0000002f, 
    0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f302d, 
    0x72657961, 0x2f36315f, 0x5078614d, 0x006c6f6f, 0x00000004, 0x00000001, 0x00000003, 0x00000001, 
    0x00000020, 0xfffff2ce, 0x01000000, 0x00000010, 0x00000010, 0x00000020, 0x00000040, 0xfffff2b8, 
    0x00000032, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 
    0x6c2f302d, 0x72657961, 0x2f36315f, 0x61707845, 0x6944646e, 0x0000736d, 0x00000004, 0x00000001, 
    0x00000006, 0x00000001, 0x00000020, 0xfffff336, 0x01000000, 0x00000010, 0x00000010, 0x0000001f, 
    0x00000110, 0xfffff320, 0x00000103, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 
    0x616c6162, 0x6465636e, 0x6c2f302d, 0x72657961, 0x2f35315f, 0x756c6552, 0x646f6d3b, 0x632f6c65, 
    0x31766e6f, 0x656d2d64, 0x6d756964, 0x6c61622d, 0x65636e61, 0x2f302d64, 0x6579616c, 0x34315f72, 
    0x7461622f, 0x6f6e6863, 0x612f6d72, 0x315f6464, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 0x656d2d64, 
    0x6d756964, 0x6c61622d, 0x65636e61, 0x2f302d64, 0x6579616c, 0x33315f72, 0x6e6f432f, 0x2f443176, 
    0x65757153, 0x3b657a65, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 
    0x6465636e, 0x6c2f302d, 0x72657961, 0x2f34315f, 0x63746162, 0x726f6e68, 0x756d2f6d, 0x3b315f6c, 
    0x646f6d3b, 0x632f6c65, 0x31766e6f, 0x656d2d64, 0x6d756964, 0x6c61622d, 0x65636e61, 0x2f302d64, 
    0x6579616c, 0x33315f72, 0x6e6f432f, 0x00443176, 0x00000004, 0x00000001, 0x00000001, 0x00000006, 
    0x00000020, 0xfffff46e, 0x01000000, 0x00000010, 0x00000010, 0x0000001e, 0x000000a0, 0xfffff458, 
    0x00000092, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 
    0x6c2f302d, 0x72657961, 0x2f32315f, 0x756c6552, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 0x656d2d64, 
    0x6d756964, 0x6c61622d, 0x65636e61, 0x2f302d64, 0x6579616c, 0x31315f72, 0x6e6f432f, 0x2f443176, 
    0x65757153, 0x3b657a65, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 
    0x6465636e, 0x6c2f302d, 0x72657961, 0x2f31315f, 0x766e6f43, 0x00004431, 0x00000004, 0x00000001, 
    0x00000001, 0x00000006, 0x00000020, 0xfffff536, 0x01000000, 0x00000010, 0x00000010, 0x0000001d, 
    0x00000048, 0xfffff520, 0x00000039, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 
    0x616c6162, 0x6465636e, 0x6c2f302d, 0x72657961, 0x2f31315f, 0x766e6f43, 0x452f4431, 0x6e617078, 
    0x6d694464, 0x00000073, 0x00000004, 0x00000001, 0x00000001, 0x00000006, 0x00000018, 0xfffff5a6, 
    0x01000000, 0x00000010, 0x00000010, 0x0000001c, 0x0000003c, 0xfffff590, 0x0000002e, 0x65646f6d, 
    0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f302d, 0x72657961, 
    0x4d2f395f, 0x6f507861, 0x00006c6f, 0x00000004, 0x00000001, 0x00000006, 0x00000001, 0x00000018, 
    0xfffff60a, 0x01000000, 0x00000010, 0x00000010, 0x0000001b, 0x00000040, 0xfffff5f4, 0x00000031, 
    0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f302d, 
    0x72657961, 0x452f395f, 0x6e617078, 0x6d694464, 0x00000073, 0x00000004, 0x00000001, 0x0000000c, 
    0x00000001, 0x00000018, 0xfffff672, 0x01000000, 0x00000010, 0x00000010, 0x0000001a, 0x0000010c, 
    0xfffff65c, 0x000000fe, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 
    0x6465636e, 0x6c2f302d, 0x72657961, 0x522f385f, 0x3b756c65, 0x65646f6d, 0x6f632f6c, 0x6431766e, 
    0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f302d, 0x72657961, 0x622f375f, 0x68637461, 
    0x6d726f6e, 0x6464612f, 0x6d3b315f, 0x6c65646f, 0x6e6f632f, 0x2d643176, 0x6964656d, 0x622d6d75, 
    0x6e616c61, 0x2d646563, 0x616c2f30, 0x5f726579, 0x6f432f36, 0x4431766e, 0x7571532f, 0x657a6565, 
    0x646f6d3b, 0x632f6c65, 0x31766e6f, 0x656d2d64, 0x6d756964, 0x6c61622d, 0x65636e61, 0x2f302d64, 
    0x6579616c, 0x2f375f72, 0x63746162, 0x726f6e68, 0x756d2f6d, 0x3b315f6c, 0x646f6d3b, 0x632f6c65, 
    0x31766e6f, 0x656d2d64, 0x6d756964, 0x6c61622d, 0x65636e61, 0x2f302d64, 0x6579616c, 0x2f365f72, 
    0x766e6f43, 0x00004431, 0x00000004, 0x00000001, 0x00000001, 0x0000000c, 0x00000018, 0xfffff7a6, 
    0x01000000, 0x00000010, 0x00000010, 0x00000019, 0x0000009c, 0xfffff790, 0x0000008f, 0x65646f6d, 
    0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f302d, 0x72657961, 
    0x522f355f, 0x3b756c65, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 
    0x6465636e, 0x6c2f302d, 0x72657961, 0x432f345f, 0x31766e6f, 0x71532f44, 0x7a656575, 0x6f6d3b65, 
    0x2f6c6564, 0x766e6f63, 0x6d2d6431, 0x75696465, 0x61622d6d, 0x636e616c, 0x302d6465, 0x79616c2f, 
    0x345f7265, 0x6e6f432f, 0x00443176, 0x00000004, 0x00000001, 0x00000001, 0x0000000c, 0x00000018, 
    0xfffff86a, 0x01000000, 0x00000010, 0x00000010, 0x00000018, 0x0000010c, 0xfffff854, 0x000000fe, 
    0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f302d, 
    0x72657961, 0x522f335f, 0x3b756c65, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 
    0x616c6162, 0x6465636e, 0x6c2f302d, 0x72657961, 0x622f325f, 0x68637461, 0x6d726f6e, 0x6464612f, 
    0x6d3b315f, 0x6c65646f, 0x6e6f632f, 0x2d643176, 0x6964656d, 0x622d6d75, 0x6e616c61, 0x2d646563, 
    0x616c2f30, 0x5f726579, 0x6f432f31, 0x4431766e, 0x7571532f, 0x657a6565, 0x646f6d3b, 0x632f6c65, 
    0x31766e6f, 0x656d2d64, 0x6d756964, 0x6c61622d, 0x65636e61, 0x2f302d64, 0x6579616c, 0x2f325f72, 
    0x63746162, 0x726f6e68, 0x756d2f6d, 0x3b315f6c, 0x646f6d3b, 0x632f6c65, 0x31766e6f, 0x656d2d64, 
    0x6d756964, 0x6c61622d, 0x65636e61, 0x2f302d64, 0x6579616c, 0x2f315f72, 0x766e6f43, 0x00004431, 
    0x00000004, 0x00000001, 0x00000001, 0x0000000c, 0x0000000c, 0xfffff99e, 0x01000000, 0x00000010, 
    0x00000010, 0x00000017, 0x000000a0, 0xfffff988, 0x00000093, 0x65646f6d, 0x6f632f6c, 0x6431766e, 
    0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f302d, 0x72657961, 0x422f305f, 0x41736169, 
    0x6d3b6464, 0x6c65646f, 0x6e6f632f, 0x2d643176, 0x6964656d, 0x622d6d75, 0x6e616c61, 0x2d646563, 
    0x616c2f30, 0x5f726579, 0x6f432f30, 0x4431766e, 0x7571532f, 0x657a6565, 0x6f6d3b3b, 0x2f6c6564, 
    0x766e6f63, 0x6d2d6431, 0x75696465, 0x61622d6d, 0x636e616c, 0x302d6465, 0x79616c2f, 0x305f7265, 
    0x6e6f432f, 0x00443176, 0x00000004, 0x00000001, 0x00000001, 0x00000018, 0x0000000d, 0xfffffa66, 
    0x01000000, 0x00000010, 0x00000010, 0x00000016, 0x00000048, 0xfffffa50, 0x00000039, 0x65646f6d, 
    0x6f632f6c, 0x6431766e, 0x64656d2d, 0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f302d, 0x72657961, 
    0x432f305f, 0x31766e6f, 0x78452f44, 0x646e6170, 0x736d6944, 0x00000031, 0x00000004, 0x00000001, 
    0x00000001, 0x00000032, 0x0000001e, 0xfffffcd6, 0x01000000, 0x00000014, 0x00000014, 0x00000015, 
    0x02000000, 0x00000048, 0xfffffac4, 0x00000038, 0x65646f6d, 0x6f632f6c, 0x6431766e, 0x64656d2d, 
    0x2d6d7569, 0x616c6162, 0x6465636e, 0x6c2f302d, 0x72657961, 0x432f305f, 0x31766e6f, 0x78452f44, 
    0x646e6170, 0x736d6944, 0x00000000, 0x00000001, 0x00000004, 0xfffffd3e, 0x01000000, 0x00000014, 
    0x00000014, 0x00000014, 0x02000000, 0x00000020, 0xfffffb2c, 0x00000010, 0x74697261, 0x6f632e68, 
    0x6174736e, 0x3831746e, 0x00000000, 0x00000000, 0xfffffb7a, 0x01000000, 0x00000010, 0x00000010, 
    0x00000013, 0x00000020, 0xfffffb64, 0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 0x3731746e, 
    0x00000000, 0x00000001, 0x00000005, 0xfffffbb6, 0x01000000, 0x00000010, 0x00000010, 0x00000012, 
    0x00000020, 0xfffffba0, 0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 0x3631746e, 0x00000000, 
    0x00000002, 0x00000005, 0x00000020, 0xfffffbf6, 0x01000000, 0x00000010, 0x00000010, 0x00000011, 
    0x00000020, 0xfffffbe0, 0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 0x3531746e, 0x00000000, 
    0x00000004, 0x0000000d, 0x00000001, 0x00000003, 0x0000001e, 0xfffffc3e, 0x01000000, 0x00000010, 
    0x00000010, 0x00000010, 0x00000020, 0xfffffc28, 0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 
    0x3431746e, 0x00000000, 0x00000001, 0x00000018, 0xfffffc7a, 0x01000000, 0x00000010, 0x00000010, 
    0x0000000f, 0x00000020, 0xfffffc64, 0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 0x3331746e, 
    0x00000000, 0x00000004, 0x00000018, 0x00000001, 0x00000003, 0x0000000c, 0xfffffcc2, 0x01000000, 
    0x00000010, 0x00000010, 0x0000000e, 0x00000020, 0xfffffcac, 0x00000010, 0x74697261, 0x6f632e68, 
    0x6174736e, 0x3231746e, 0x00000000, 0x00000001, 0x00000020, 0xfffffcfe, 0x01000000, 0x00000010, 
    0x00000010, 0x0000000d, 0x00000020, 0xfffffce8, 0x00000010, 0x74697261, 0x6f632e68, 0x6174736e, 
    0x3131746e, 0x00000000, 0x00000004, 0x00000020, 0x00000001, 0x00000003, 0x00000018, 0xffffff46, 
    0x01000000, 0x00000014, 0x00000014, 0x0000000c, 0x02000000, 0x00000020, 0xfffffd34, 0x00000010, 
    0x74697261, 0x6f632e68, 0x6174736e, 0x3031746e, 0x00000000, 0x00000001, 0x00000004, 0xffffff86, 
    0x01000000, 0x00000014, 0x00000014, 0x0000000b, 0x02000000, 0x0000001c, 0xfffffd74, 0x0000000f, 
    0x74697261, 0x6f632e68, 0x6174736e, 0x0039746e, 0x00000001, 0x00000004, 0xffffffc2, 0x01000000, 
    0x00000014, 0x00000014, 0x0000000a, 0x02000000, 0x0000001c, 0xfffffdb0, 0x0000000f, 0x74697261, 
    0x6f632e68, 0x6174736e, 0x0038746e, 0x00000001, 0x00000004, 0x00160000, 0x0018001c, 0x00100017, 
    0x0008000c, 0x00000000, 0x00070000, 0x00000016, 0x01000000, 0x00000014, 0x00000014, 0x00000009, 
    0x02000000, 0x0000001c, 0xfffffe04, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0037746e, 
    0x00000001, 0x00000003, 0xfffffe52, 0x01000000, 0x00000010, 0x00000010, 0x00000008, 0x0000001c, 
    0xfffffe3c, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0036746e, 0x00000001, 0x0000000d, 
    0xfffffe8a, 0x01000000, 0x00000010, 0x00000010, 0x00000007, 0x0000001c, 0xfffffe74, 0x0000000f, 
    0x74697261, 0x6f632e68, 0x6174736e, 0x0035746e, 0x00000004, 0x0000000c, 0x00000001, 0x00000003, 
    0x0000000d, 0xfffffece, 0x01000000, 0x00000010, 0x00000010, 0x00000006, 0x0000001c, 0xfffffeb8, 
    0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0034746e, 0x00000004, 0x00000018, 0x00000001, 
    0x00000003, 0x00000018, 0xffffff12, 0x01000000, 0x00000010, 0x00000010, 0x00000005, 0x0000001c, 
    0xfffffefc, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0033746e, 0x00000004, 0x00000020, 
    0x00000001, 0x00000003, 0x00000020, 0xffffff56, 0x01000000, 0x00000010, 0x00000010, 0x00000004, 
    0x0000001c, 0xffffff40, 0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0032746e, 0x00000001, 
    0x0000000c, 0xffffff8e, 0x01000000, 0x00000010, 0x00000010, 0x00000003, 0x0000001c, 0xffffff78, 
    0x0000000f, 0x74697261, 0x6f632e68, 0x6174736e, 0x0031746e, 0x00000001, 0x00000018, 0xffffffc6, 
    0x01000000, 0x00000010, 0x00000010, 0x00000002, 0x0000001c, 0xffffffb0, 0x0000000e, 0x74697261, 
    0x6f632e68, 0x6174736e, 0x0000746e, 0x00000001, 0x00000020, 0x00160000, 0x00140018, 0x00100000, 
    0x0008000c, 0x00000000, 0x00070000, 0x00000016, 0x01000000, 0x00000014, 0x00000014, 0x00000001, 
    0x0000002c, 0x00040004, 0x00000004, 0x00000019, 0x76726573, 0x5f676e69, 0x61666564, 0x5f746c75, 
    0x6579616c, 0x3a305f72, 0x00000030, 0x00000003, 0x00000001, 0x00000032, 0x0000001e, 0x00000006, 
    0x00000060, 0x00000044, 0x00000034, 0x00000024, 0x00000014, 0x00000004, 0xffffffc4, 0x00000019, 
    0x19000000, 0xffffffd0, 0x00000009, 0x09000000, 0xffffffdc, 0x00000028, 0x28000000, 0xffffffe8, 
    0x00000011, 0x11000000, 0xfffffff4, 0x00000003, 0x03000000, 0x000c000c, 0x0000000b, 0x00040000, 
    0x0000000c, 0x00000016, 0x16000000
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
#define _K7              ((uint8_t *)_k7)                    // u8[45900] (45900 bytes)
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
    __RETURN_ERROR(mtb_init(_K10, _K7, 45900, _K6, 16384, 3, "network_float"));
    return 0;
}

static IMAI_api_def _IMAI_api_def = {
    .api_ver = 1,
    .id = {0x8b, 0x29, 0x2e, 0x21, 0x62, 0x78, 0xcb, 0x4e, 0x90, 0x5c, 0x63, 0xd7, 0x2e, 0x60, 0x45, 0x1c},
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
        .size = 48012,
        .peak_usage = 48012,
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

