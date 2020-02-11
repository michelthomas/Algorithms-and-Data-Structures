cmake_minimum_required(VERSION 3.15)
project(binary_tree C)

set(CMAKE_C_STANDARD 99)

add_executable(binary_tree main.c binary_tree.h binary_tree.c)