cmake_minimum_required(VERSION 3.13)  # CMake version check
project(OpenGL triangle)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard


# Add executable target with source files listed in SOURCE_FILES variable
add_executable(OpenGL triangle ${SOURCE_FILES})