cmake_minimum_required(VERSION 3.5)
project(Codec_test LANGUAGES C)

add_executable(decoder_test_runner TestRunners/runner_test_jpg_decoder.c)

#add_library(decoder_test test_jpg_decoder.c)
