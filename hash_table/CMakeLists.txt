cmake_minimum_required(VERSION 3.15)
project(hash_table C)

set(CMAKE_C_STANDARD 99)

add_executable(hash_table main.c hash_table.h hash_table.c linked_list.h linked_list.c)