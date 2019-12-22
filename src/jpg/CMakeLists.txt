cmake_minimum_required(VERSION 3.5)

project(JPG_LIB LANGUAGES C)



add_library(Unity STATIC D:/Tools/Unity/src/unity.c)
target_include_directories(Unity PUBLIC
    D:/Tools/Unity/src
)

set(SOURCES src/jpg_encoder.c src/jpg_decoder.c src/jpg_codec.c)
set(HEADERS src/jpg_encoder.h src/jpg_decoder.h src/jpg_codec.h src/jpg_common.h)
set(TEST_SOURCES test/test_jpg_decoder.c )#test/test_jpg_runner.c)
add_library(JPG_LIB ${SOURCES}
                ${HEADERS}
                )
target_link_libraries(JPG_LIB)

add_executable(JPG_LIB_TEST ${TEST_SOURCES})
target_link_libraries( JPG_LIB_TEST Unity)
target_link_libraries( JPG_LIB_TEST JPG_LIB)


