//
// Created by MichelT on 09/01/2020.
//

#ifndef PRIORITY_QUEUE_POINTER_PRIORITY_QUEUE_POINTER_H
#define PRIORITY_QUEUE_POINTER_PRIORITY_QUEUE_POINTER_H

typedef struct node {
    int item;
    int priority;
    struct node *next;
} node;

typedef struct priority_queue {
    node *head;
} p_queue;

p_queue* create_priority_queue();
void pq_enqueue(p_queue *pq, int i, int p);
node* pq_dequeue(p_queue *pq);
int maximum(p_queue *pq);
int pq_is_empty(p_queue *pq);
void print_priority_queue(p_queue *pq);

#endif //PRIORITY_QUEUE_POINTER_PRIORITY_QUEUE_POINTER_H
