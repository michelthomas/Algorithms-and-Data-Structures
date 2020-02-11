//
// Created by MichelT on 09/01/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

queue* create_queue()
{
    queue *new_queue = (queue*) malloc(sizeof(queue));
    new_queue->current_size = 0;
    new_queue->head = 0;
    new_queue->tail = MAX_QUEUE_SIZE - 1;
    return new_queue;
}

void enqueue(queue *queue, int item)
{
    if (is_full(queue)) {
        printf("QUEUE OVERFLOW!");
    } else {
        queue->tail = (queue->tail + 1) % MAX_QUEUE_SIZE;
        queue->items[queue->tail] = item;
        queue->current_size++;
    }
}

int dequeue(queue *queue)
{
    if (is_empty(queue)) {
        printf("QUEUE UNDERFLOW!");
        return -1;
    } else {
        int dequeued = queue->items[queue->head];
        queue->items[queue->head] = -1;
        queue->head = (queue->head + 1) % MAX_QUEUE_SIZE;
        queue->current_size--;
        return dequeued;
    }
}

int is_empty(queue *queue) {
    return (!queue->current_size);
}

int is_full(queue *queue) {
    return (queue->current_size >= MAX_QUEUE_SIZE);
}

void print_queue(queue *queue) {
    for (int i = queue->head; i <= queue->tail % MAX_QUEUE_SIZE; ++i) {
        printf("%d ", queue->items[i]);
    }
}


