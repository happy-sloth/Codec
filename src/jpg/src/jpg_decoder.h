#ifndef JPG_DECODER_H
#define JPG_DECODER_H

#ifdef __cplusplus
extern "C"{
#endif

#include "jpg_common.h"


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
 * \param p_data - pointer to jpg_info_t struct, which contain
 * information and data about jpg image
 * \return status of result
 */
ret_type_t jpg_decoder_handle_chunk(jpg_chunk* chunk,
                                    jpg_header_t *p_data);

#ifdef __cplusplus
}
#endif

#endif /* JPG_DECODER_H */
