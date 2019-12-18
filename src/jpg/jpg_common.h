#ifndef JPG_COMMON_H
#define JPG_COMMON_H

#ifdef __cplusplus
extern "C"{
#endif

#include "stdint.h"

typedef enum
{
    CODEC_OK = 0x00,
    CODEC_BUSY = 0x10,
    CODEC_ERR = 0xFF
}   ret_type_t;

/// This structure type is for containing quantization table
typedef struct
{
    uint8_t quant_table[64];
}jpg_header_t;

/// This structure type is for containing color of pixel in RGB format.
typedef struct
{
    uint8_t R_subpixel;
    uint8_t G_subpixel;
    uint8_t B_subpixel;
}pixel_rgb_t;

/// This structure type is for containing color of pixel in YCbCr format.
typedef struct
{
    uint8_t Y_subpixel;
    uint8_t Cb_subpixel;
    uint8_t Cr_subpixel;
}pixel_YCbCr_t;

/// This structure type is for containing raw pixels array in RGB format.
typedef struct
{
    pixel_rgb_t     *p_buff; /// Buffer pointer
    uint64_t        size;    /// Size of buffer
}pixel_rgb_buffer_t;

/// This structure type is for containing raw pixels array in YCbCr format.
typedef struct
{
    pixel_YCbCr_t   *p_buff;    /// Buffer pointer
    uint64_t        size;       /// Size of buffer
}pixel_YCbCr_buffer_t;

/// This structure type is for containing jpeg chunks
typedef struct
{
    uint16_t    marker;
    uint16_t    buffer_size;
    uint8_t*    buffer;
}jpg_chunk;

#ifdef __cplusplus
}
#endif

#endif // JPG_COMMON_H
