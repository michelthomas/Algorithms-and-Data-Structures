//
// Created by MichelT on 11/02/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "min_heap.h"


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
    HEAP *heap = (HEAP *) malloc(sizeof(HEAP));

    heap->size = 0;

    for (int i = 1; i < HEAP_MAX_SIZE; ++i) {
        heap->data[i] = NULL;
    }

    return heap;
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

void swap(void **item_1, void **item_2) {
    void *aux = *item_1;
    *item_1 = *item_2;
    *item_2 = aux;
}

int get_priority(HEAP *h, int index) {
    return ((_node *) h->data[index])->priority;
}

void enqueue(HEAP *heap, int priority, void *data) {
    if (heap->size >= HEAP_MAX_SIZE - 1) {
        printf("Heap overflow.\n");
    } else {
        _node *new_node = _create_node(priority, data);

        heap->data[++heap->size] = new_node;

        int key_index = heap->size;

        int parent_index = get_parent_index(key_index);

        while (parent_index >= 1 && get_priority(heap, key_index) < get_priority(heap, parent_index)) {
            swap(&heap->data[parent_index], &heap->data[key_index]);

            key_index = parent_index;

            parent_index = get_parent_index(key_index);
        }
    }
}

void min_heapify(HEAP *heap, int i) {
    int smallest;
    int left_index = get_left_index(i);
    int right_index = get_right_index(i);

    _node *t = heap->data[i];
    _node *t_l = heap->data[left_index];
    _node *t_r = heap->data[right_index];

    if (left_index <= heap->size && t_l->priority < t->priority) {
        smallest = left_index;
    } else {
        smallest = i;
    }

    _node *t_s = heap->data[smallest];

    if (right_index <= heap->size && t_r->priority < t_s->priority) {
        smallest = right_index;
        t_s = heap->data[smallest];
    }

    if (t != t_s) {
        swap(&heap->data[i], &heap->data[smallest]);
        min_heapify(heap, smallest);
    }
}

void *dequeue(HEAP *heap) {
    if (!(heap->size)) {
        printf("Heap underflow.\n");
        return NULL;
    } else {
        _node *item = (_node *) heap->data[1];

        heap->data[1] = heap->data[heap->size];

        heap->data[heap->size] = NULL;

        heap->size -= 1;

        min_heapify(heap, 1);

        return item->data;
    }
}

HEAP *build_min_heap(int arr_priority[], void *arr_data[]) {
    HEAP *h = create_heap();

    for (int i = 0; arr_priority[i] != -1 || arr_data[i] != NULL; ++i) {
        enqueue(h, arr_priority[i], arr_data[i]);
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