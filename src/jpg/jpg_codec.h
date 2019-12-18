#ifndef JPG_CODEC_H
#define JPG_CODEC_H

#ifdef __cplusplus
extern "C"{
#endif

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>



/*typedef ret_type_t  (*put_byte_t)(uint8_t b_byte);
typedef uint64_t    (*get_size_t)();
typedef ret_type_t  (*get_buff)(uint8_t* buff, uint64_t size);

typedef struct
{
    put_byte_t  p_put_byte;
    get_size_t  p_get_size;
    get_buff    p_get_buff;
}lib_interface;

extern const lib_interface jpg_codec_int;*/
/*!
 * \brief send pointer to open jpg-file to library
 * \param pointer to file
 * \return state of result
 */
ret_type_t  trust_jpg_file(FILE *f_in);
/*!
 * \brief start process of decoding of jpg file
 * \return state result of decoding
 */
ret_type_t  start_jpg_decoding(void);
/*!
 * \brief Return size of intire buffer
 * \return size of buffer with raw pixels
 */
uint64_t    get_output_buffer_size (void);
/*!
 * \brief Copy entire raw pixels buffer to pointer buffer
 * \param pointer to buffer
 * \param size of buffer
 * \return state of copy
 */
ret_type_t  copy_output_buffer(uint8_t* buffer, uint64_t buffer_size);

#ifdef __cplusplus
}
#endif

#endif /* JPG_CODEC_H */
