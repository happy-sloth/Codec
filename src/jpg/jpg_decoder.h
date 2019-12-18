#ifndef JPG_DECODER_H
#define JPG_DECODER_H

#ifdef __cplusplus
extern "C"{
#endif

#include "jpg_common.h"
#include <stdio.h>

/*!
 * \brief Get chunk from file from current marker FF__ to next
 * \param entry_file - entry jpg_file with cursor position on current chunk
 * \param chunk - structure to contain parsed chunk
 * \return status of result
 */
ret_type_t get_chunk (FILE* /*TODO: add cursor position*/ entry_file, jpg_chunk chunk);

/*!
 * \brief Find handler of chunk
 * \param chunk - chunk which must by processed
 * \return status of result
 */
ret_type_t jpg_decoder_handle_chunk(jpg_chunk* chunk);

#ifdef __cplusplus
}
#endif

#endif /* JPG_DECODER_H */
