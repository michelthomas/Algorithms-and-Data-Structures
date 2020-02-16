//
// Created by MichelT on 11/02/2020.
//

#ifndef MIN_heap_MIN_heap_H
#define MIN_heap_MIN_heap_H

#define HEAP_MAX_SIZE 100

typedef struct heap {
    int size;
    void *data[HEAP_MAX_SIZE];
} HEAP;

HEAP *create_heap();

void enqueue(HEAP *heap, int priority, void *data);

void *dequeue(HEAP *heap);

void min_heapify(HEAP *heap, int i);

HEAP *build_min_heap(int arr_priority[], void *arr_data[]);

void heapsort(HEAP *heap);

int is_empty(HEAP *heap);

int get_parent_index(int i);

int get_left_index(int i);

int get_right_index(int i);

void swap(void **item_x, void **item_y);

void *item_of(HEAP *heap, int i);

int get_priority(HEAP *h, int index);

void free_heap(HEAP *heap);

void print_heap(HEAP *heap, void (*print_func)(void *data));

#endif //MIN_heap_MIN_heap_H
