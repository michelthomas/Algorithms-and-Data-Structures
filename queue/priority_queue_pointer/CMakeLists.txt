cmake_minimum_required(VERSION 3.15)
project(priority_queue_pointer C)

set(CMAKE_C_STANDARD 99)

add_executable(priority_queue_pointer main.c priority_queue_pointer.h priority_queue_pointer.c)