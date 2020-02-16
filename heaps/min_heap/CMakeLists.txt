cmake_minimum_required(VERSION 3.15)
project(min_heap C)

set(CMAKE_C_STANDARD 99)

add_executable(min_heap main.c min_heap.c min_heap.h)

enable_testing()

add_test(NAME Min_Heap_Test COMMAND Max_Heap_Test)

add_executable(Min_Heap_Test min_heap.c min_heap.h test.c)

set_target_properties(Min_Heap_Test PROPERTIES LINK_FLAGS -Wl,-lcunit)

target_link_libraries (Min_Heap_Test  CUNIT)