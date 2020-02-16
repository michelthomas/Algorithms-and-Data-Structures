cmake_minimum_required(VERSION 3.15)
project(max_heap C)

set(CMAKE_C_STANDARD 99)

add_executable(max_heap main.c max_heap.c max_heap.h)

enable_testing()

add_test(NAME Max_Heap_Test COMMAND Max_Heap_Test)

add_executable(Max_Heap_Test max_heap.c max_heap.h test.c)

set_target_properties(Max_Heap_Test PROPERTIES LINK_FLAGS -Wl,-lcunit)

target_link_libraries (Max_Heap_Test  CUNIT)