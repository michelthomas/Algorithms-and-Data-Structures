cmake_minimum_required(VERSION 3.15)
project(linked_list C)

set(CMAKE_C_STANDARD 99)

add_executable(linked_list main.c doubly_linked_list.c doubly_linked_list.h)