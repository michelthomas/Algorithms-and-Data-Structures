//
// Created by MichelT on 14/02/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


queue *create_queue() {
    queue *new_queue = (queue *) malloc(sizeof(queue));
    new_queue->end = NULL;
    new_queue->begin = NULL;
    return new_queue;
}

int is_empty_queue(queue *new_queue) {
    return (new_queue->end == NULL);
}

void enqueue(queue *new_queue, int item) {
    node *new_node = create_node(item);
    new_queue->size += 1;

    if (is_empty_queue(new_queue)) {
        new_queue->begin = new_queue->end = new_node;
    } else {
        new_queue->end->next = new_node;
        new_queue->end = new_node;
    }
}

int dequeue(queue *new_queue) {
    new_queue->size -= 1;
    int item;

    if (is_empty_queue(new_queue)) {
        printf("Fila vazia\n");
        return -1;
    } else if (new_queue->begin == new_queue->end) {
        node *new_node = new_queue->begin;
        item = new_node->key;
        new_queue->begin = new_queue->end = NULL;
        return item;
    } else {
        node *new_node = new_queue->begin;
        item = new_node->key;
        new_queue->begin = new_queue->begin->next;
        return item;
    }
}

