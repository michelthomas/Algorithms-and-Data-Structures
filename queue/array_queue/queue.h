//
// Created by MichelT on 09/01/2020.
//

#ifndef ARRAY_QUEUE_QUEUE_H
#define ARRAY_QUEUE_QUEUE_H

#define MAX_QUEUE_SIZE 100

typedef struct queue {
    int current_size;
    int head;
    int tail;
    int items[MAX_QUEUE_SIZE];
} queue;

queue* create_queue();
void enqueue(queue *queue, int item);
int dequeue(queue *queue);
int is_empty(queue *queue);
int is_full(queue *queue);
void print_queue(queue *queue);

#endif //ARRAY_QUEUE_QUEUE_H
