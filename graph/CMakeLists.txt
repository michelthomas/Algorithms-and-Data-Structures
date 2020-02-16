cmake_minimum_required(VERSION 3.15)
project(graph C)

set(CMAKE_C_STANDARD 99)

add_executable(graph main.c graph.c graph.h list.c list.h queue.c queue.h)