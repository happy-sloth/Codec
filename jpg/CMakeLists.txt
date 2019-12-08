cmake_minimum_required(VERSION 3.5)

project(JPG_LIB LANGUAGES C)

set(SOURCES jpg_encoder.c jpg_decoder.c jpg_codec.c)
set(HEADERS jpg_encoder.h jpg_decoder.h jpg_codec.h)
add_library(JPG ${SOURCES}
                ${HEADERS}
                )
target_include_directories(JPG PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})




