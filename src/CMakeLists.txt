cmake_minimum_required(VERSION 3.5)

add_executable(Codec main.c)

# Link jpg lib
include_directories(jpg)
add_subdirectory(jpg)
target_link_libraries(Codec JPG_LIB)





