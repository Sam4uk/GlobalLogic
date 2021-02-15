
cmake_minimum_required(VERSION 3.10)

add_compile_options(
  -Wall 
  -Wextra 
  -Wpedantic 
  -Werror 
  -O3
  ) 

set(CMAKE_CXX_STANDARD 17)

project(task2)

add_executable(${PROJECT_NAME} main.cpp Fibonacci.hpp Fibonacci.cpp)
