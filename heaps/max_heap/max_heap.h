//
// Created by MichelT on 11/02/2020.
//

#ifndef MAX_heap_MAX_heap_H
#define MAX_heap_MAX_heap_H

#define HEAP_MAX_SIZE 100

typedef struct HEAP {
    int size;
    void *data[HEAP_MAX_SIZE];
} HEAP;

HEAP *create_heap();

void enqueue(HEAP *heap, int priority, void *data);

void *dequeue(HEAP *heap);

void max_heapify(HEAP *heap, int i);

HEAP *build_max_heap(int arr_priority[], void *arr_data[]);

HEAP *build_max_heap_int(int arr[], int n);

void heapsort(HEAP *heap);

HEAP *heapsort_int(int *arr, int n);

int is_empty(HEAP *heap);

int get_parent_index(int i);

int get_left_index(int i);

int get_right_index(int i);

void swap(void **item_x, void **item_y);

void *item_of(HEAP *heap, int i);

int get_priority(HEAP *h, int index);

void free_heap(HEAP *heap);

void print_heap(HEAP *heap, void (*print_func)(void *data));

void print_heap_int(HEAP *h);


#endif //MAX_heap_MAX_heap_H
