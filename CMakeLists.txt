cmake_minimum_required(VERSION 3.5)
project(Codec LANGUAGES C)

add_executable(Codec src/main.c)

# Add directories
add_subdirectory(test)

# Link jpg lib
add_subdirectory(src/jpg)
target_link_libraries(${PROJECT_NAME} JPG)

