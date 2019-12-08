cmake_minimum_required(VERSION 3.5)
project(Codec LANGUAGES C)

add_executable(Codec main.c)

# Link jpg lib
add_subdirectory(jpg)
target_link_libraries(${PROJECT_NAME} JPG)


