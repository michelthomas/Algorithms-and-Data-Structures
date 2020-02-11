cmake_minimum_required(VERSION 3.15)
project(deque C)

set(CMAKE_C_STANDARD 99)

add_executable(deque main.c deque.h deque.c)