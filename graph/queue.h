//
// Created by MichelT on 14/02/2020.
//

#ifndef GRAPH_QUEUE_H
#define GRAPH_QUEUE_H

#include "list.h"

typedef struct queue {
    int size;
    node *end;
    node *begin;
} queue;

queue *create_queue();

int is_empty_queue(queue *new_queue);

void enqueue(queue *new_queue, int item);

int dequeue(queue *new_queue);

#endif //GRAPH_QUEUE_H
