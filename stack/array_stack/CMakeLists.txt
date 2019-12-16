cmake_minimum_required(VERSION 3.15)
project(array_stack C)

set(CMAKE_C_STANDARD 99)

add_executable(array_stack main.c array_stack.c array_stack.h)