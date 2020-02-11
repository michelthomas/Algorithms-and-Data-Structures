cmake_minimum_required(VERSION 3.15)
project(array_queue C)

set(CMAKE_C_STANDARD 99)

add_executable(array_queue main.c queue.h queue.c priority_queue_pointer.h priority_queue_pointer.c)