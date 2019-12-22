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

#define GET_BYTE(byte)          {int b_byte_from_file = 0;\
                                if ((b_byte_from_file = fgetc(jpg_info.enire_file)) == EOF)\
                                {\
                                   break;\
                                }\
                                byte = (uint8_t)b_byte_from_file;\
                                }

#define GET_WORD(byte)          {int b_byte_from_file = 0;\
                                if ((b_byte_from_file = fgetc(jpg_info.enire_file)) == EOF)\
                                {\
                                   break;\
                                }\
                                byte = (uint16_t)((int8_t)b_byte_from_file<<8);\
                                if ((b_byte_from_file = fgetc(jpg_info.enire_file)) == EOF)\
                                {\
                                    break;\
                                }\
                                byte |= b_byte_from_file;\
                                }

void close_file(void);

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

    uint16_t b_file_signature =(uint16_t)(
                              ((int8_t)fgetc(jpg_info.enire_file)<<8) |
                               (int8_t)fgetc(jpg_info.enire_file));

    if (b_file_signature != 0xFFD8)
    {
        close_file();
        return CODEC_ERR;
    }

    jpg_chunk b_chunk = {0};
    while (1)
    {
        //memset(&b_chunk, 0, sizeof(b_chunk));
        GET_WORD(b_chunk.marker)
        GET_WORD(b_chunk.buffer_size)
        b_chunk.buffer_size -= 2;
        b_chunk.buffer = malloc(b_chunk.buffer_size);

        if (!b_chunk.buffer)
        {
            close_file();
            return CODEC_ERR;
        }

        int i;
        for (i = 0; i < b_chunk.buffer_size; i++)
        {
            GET_BYTE(b_chunk.buffer[i])

        }

        jpg_decoder_handle_chunk(&b_chunk,
                                 &jpg_info.header);
        free(b_chunk.buffer);
        if (b_chunk.marker == 0xFFDA)
        {

            uint8_t b_byte1, b_byte2 = 0;
            GET_BYTE(b_byte1)
            /*while ()*/break;
        }

    }

    close_file();

    if (b_chunk.marker == 0xFFD9)
    {
        return CODEC_OK;
    }

    return CODEC_ERR;
}

void close_file(void)
{
    fclose(jpg_info.enire_file);
}

