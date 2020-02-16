//
// Created by MichelT on 11/02/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "max_heap.h"

/** Nó auxiliar **/
typedef struct _node {
    int priority;
    void *data;
} _node;

_node *_create_node(int priority, void *data) {

    _node *new_node = (_node *) malloc(sizeof(_node));

    new_node->priority = priority;
    new_node->data = data;

    return new_node;
}

HEAP *create_heap() {
    HEAP *new_heap = (HEAP *) malloc(sizeof(HEAP));
    new_heap->size = 0;
    for (int i = 1; i <= HEAP_MAX_SIZE; ++i) {
        new_heap->data[i] = NULL;
    }
    return new_heap;
}

int get_parent_index(int i) {
    return (i / 2);
}

int get_left_index(int i) {
    return (2 * i);
}

int get_right_index(int i) {
    return (2 * i + 1);
}

void *item_of(HEAP *heap, int i) {
    return ((_node *) heap->data[i])->data;
}

void swap(void **item_x, void **item_y) {
    void *aux = *item_x;
    *item_x = *item_y;
    *item_y = aux;
}

int get_priority(HEAP *h, int index) {
    return ((_node *) h->data[index])->priority;
}

void enqueue(HEAP *heap, int priority, void *data) {
    if (heap->size >= HEAP_MAX_SIZE) {
        printf("HEAP overflow");
    } else {

        _node *new_node = _create_node(priority, data);

        heap->data[++heap->size] = new_node;

        int key_index = heap->size;
        int parent_index = get_parent_index(heap->size);

        while (parent_index >= 1 && get_priority(heap, key_index) > get_priority(heap, parent_index)) {
            swap(&heap->data[key_index], &heap->data[parent_index]);
            key_index = parent_index;
            parent_index = get_parent_index(key_index);
        }
    }
}

int is_empty(HEAP *heap) {
    return !(heap->size);
}

void *dequeue(HEAP *heap) {
    if (is_empty(heap)) {
        printf("HEAP underflow!\n");
        return NULL;
    } else {
        _node *item = (_node *) heap->data[1];

        heap->data[1] = heap->data[heap->size];

        heap->data[heap->size] = NULL;

        heap->size--;

        max_heapify(heap, 1);

        return item->data;
    }
}

void max_heapify(HEAP *heap, int i) {

    int largest;
    int left_index = get_left_index(i);
    int right_index = get_right_index(i);

    _node *item = heap->data[i];
    _node *item_left = heap->data[left_index];
    _node *item_right = heap->data[right_index];

    if (left_index <= heap->size && item_left->priority > item->priority) {
        largest = left_index;
    } else {
        largest = i;
    }

    _node *item_largest = heap->data[largest];

    if (right_index <= heap->size && item_right->priority > item_largest->priority) {
        largest = right_index;
        item_largest = heap->data[largest];
    }

    if (item != item_largest) {
        swap(&heap->data[i], &heap->data[largest]);
        max_heapify(heap, largest);
    }
}

void heapsort(HEAP *heap) {
    int i;
    for (i = heap->size; i >= 2; i--) {
        swap(&heap->data[1], &heap->data[i]);
        heap->size--;
        max_heapify(heap, 1);
    }
}

HEAP *heapsort_int(int *arr, int n) {
    HEAP *h = build_max_heap_int(arr, n);

    for (int i = h->size; i >= 2; i--) {
        swap(&h->data[1], &h->data[i]);
        h->size--;
        max_heapify(h, 1);
    }

    return h;
}

HEAP *build_max_heap(int arr_priority[], void *arr_data[]) {
    HEAP *h = create_heap();

    for (int i = 0; arr_priority[i] != -1 || arr_data[i] != NULL; ++i) {
        enqueue(h, arr_priority[i], arr_data[i]);
    }

    return h;
}

HEAP *build_max_heap_int(int arr[], int n) {
    HEAP *h = create_heap();


    for (int i = 0; i < n; ++i) {
        enqueue(h, arr[i], NULL);
    }

    return h;
}

void free_heap(HEAP *heap) {
    for (int i = 1; i <= heap->size; ++i) {
        free((_node *) heap->data[i]);
    }

    free(heap);
}

void print_heap(HEAP *heap, void (*print_func)(void *data)) {
    for (int i = 1; i <= heap->size; ++i) {
        print_func(((_node *) heap->data[i])->data);
        printf(" ");
    }
}

void print_heap_int(HEAP *h) {
    for (int i = 1; h->data[i] != NULL; ++i) {
        printf("%d ", ((_node *) h->data[i])->priority);
    }
}
