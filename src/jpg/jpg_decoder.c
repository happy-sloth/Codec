#include "jpg_decoder.h"
#include <string.h>

#define NUM_OF_MARKERS  (uint8_t)7

typedef ret_type_t (*chunk_handler)(jpg_chunk*);

static ret_type_t signature_handler(jpg_chunk* chunk);
static ret_type_t comment_handler(jpg_chunk* chunk);
static ret_type_t quant_table_handler(jpg_chunk* chunk);

typedef struct
{
    uint16_t marker;
    chunk_handler handler;
}handler_map_t;

static const handler_map_t handler_map[NUM_OF_MARKERS] =
{       {.marker = 0xFFD8,
         .handler = signature_handler},
        {.marker = 0xFFFE,
         .handler = comment_handler},
        {.marker = 0xFFDB,
         .handler = quant_table_handler},
};


static ret_type_t signature_handler(jpg_chunk* chunk)
{
    if (!chunk)
    {
        return CODEC_ERR;
    }
    jpg_chunk b_chunk;
    memcpy(&b_chunk, chunk, sizeof(jpg_chunk));



    return CODEC_OK;
}

static ret_type_t comment_handler(jpg_chunk* chunk)
{
    if (!chunk)
    {
        return CODEC_ERR;
    }
    jpg_chunk b_chunk;
    memcpy(&b_chunk, chunk, sizeof(jpg_chunk));



    return CODEC_OK;
}

static ret_type_t quant_table_handler(jpg_chunk* chunk)
{
    if (!chunk)
    {
        return CODEC_ERR;
    }
    jpg_chunk b_chunk;
    memcpy(&b_chunk, chunk, sizeof(jpg_chunk));



    return CODEC_OK;
}



ret_type_t jpg_decoder_handle_chunk(jpg_chunk* chunk)
{
    ret_type_t ret_val;
    if (!chunk)
    {
        return CODEC_ERR;
    }
    jpg_chunk b_chunk;
    memcpy(&b_chunk, chunk, sizeof(jpg_chunk));

    for (int index = 0; index < NUM_OF_MARKERS; index++)
    {
        if (handler_map[index].marker == b_chunk.marker)
        {
            ret_val = handler_map[index].handler(&b_chunk);
            return ret_val;
        }

    }

    return CODEC_ERR;
}
