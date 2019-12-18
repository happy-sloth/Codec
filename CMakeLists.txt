cmake_minimum_required(VERSION 3.5)
project(Codec LANGUAGES C)

add_executable(Codec src/main.c)
#add_executable(decoder_test test/TestRunners/runner_test_jpg_decoder.c)

# Link jpg lib
add_subdirectory(src/jpg)
target_link_libraries(${PROJECT_NAME} JPG)

# Add Unity framework
#add_subdirectory(test/Unity)
#target_link_libraries(${PROJECT_NAME} Unity)

# Add directories
#add_subdirectory(test)




