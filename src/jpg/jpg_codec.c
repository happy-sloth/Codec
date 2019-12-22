/**
 *  \autor happy-sloth
 *
 *  \date 2019-12-16
 *
 *
 * */

#include "jpg_common.h"
#include "jpg_codec.h"
#include "jpg_encoder.h"
#include "jpg_decoder.h"

#include <string.h>


static jpg_info_t jpg_info;

/*!
 * \brief send pointer to open jpg-file to library
 * \param pointer to file
 * \return state of result
 */
ret_type_t  trust_jpg_file(FILE *f_in)
{
    if (!f_in)
    {
        return CODEC_ERR;
    }

    jpg_info.enire_file = f_in;

    return CODEC_OK;
}

/*!
 * \brief Return size of intire buffer
 * \return size of buffer with raw pixels
 */
uint64_t    get_output_buffer_size (void)
{
    return (uint64_t) jpg_info.rgb_buffer.size;
}

/*!
 * \brief Copy entire raw pixels buffer to pointer buffer
 * \param pointer to buffer
 * \param size of buffer
 * \return state of copy
 */
ret_type_t  copy_output_buffer(uint8_t* buffer, uint64_t buffer_size)
{
    if (!buffer || !buffer_size)
    {
        return CODEC_ERR;
    }

    if (buffer_size < jpg_info.rgb_buffer.size)
    {
        return CODEC_ERR;
    }

    memcpy(buffer, jpg_info.rgb_buffer.p_buff, jpg_info.rgb_buffer.size);

    return CODEC_OK;
}

/*!
 * \brief start process of decoding of jpg file
 * \return state result of decoding
 */
ret_type_t  jpg_decode(void)
{

    if (!jpg_info.enire_file)
    {
        return CODEC_ERR;
    }

    uint16_t b_file_signature = (0xFFFF)&&(uint16_t)
                               ((fgetc(jpg_info.enire_file)<<8) &&
                                (fgetc(jpg_info.enire_file)));

    if (b_file_signature != 0xFFD8)
    {
        return CODEC_ERR;
    }



    return CODEC_OK;
}


