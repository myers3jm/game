cmake_minimum_required(VERSION 3.10)
# Project name
project(game VERSION 0.0.1)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED 20)
add_compile_options(-Wall -Wextra -Werror -Wpointer-arith)
add_compile_options(-Os) # Optimize for size
add_executable(game main.cpp)
target_include_directories(game PUBLIC "${PROJECT_BINARY_DIR}")s