//
// Created by MichelT on 09/01/2020.
//

#include <stdio.h>
#include <stdlib.h>

#include "priority_queue_pointer.h"

p_queue* create_priority_queue() {
    p_queue *new_pq = (p_queue*) malloc(sizeof(p_queue));

    new_pq->head = NULL;

    return new_pq;
}

/**
 *
 * 100 80 90
 * 100 90 80
 *
 * 100 120 30 50
 * 120 100 30 50
 * 120 100 30 50
 *
 *
 *
 * */
void pq_enqueue(p_queue *pq, int i, int p) {
    node *new_node = (node*) malloc(sizeof(node));
    new_node->item = i;
    new_node->priority = p;
    if ((pq_is_empty(pq)) || (p > pq->head->priority)) {
        new_node->next = pq->head;
        pq->head = new_node;
    } else {
        node *current = pq->head;
        while ((current->next != NULL) &&
               (current->next->priority >= p)) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

node* pq_dequeue(p_queue *pq) {
    if (pq_is_empty(pq)) {
        printf("Priority Queue underflow");
        return NULL;
    } else {
        node *node = pq->head;
        pq->head = pq->head->next;
        node->next = NULL;
        return node;
    }
}

int maximum(p_queue *pq) {
    if (pq_is_empty(pq)) {
        printf("Priority Queue underflow");
        return -1;
    } else {
        return pq->head->item;
    }
}

int pq_is_empty(p_queue *pq) {
    return (!pq->head);
}

void print_priority_queue(p_queue *pq) {
    if (!pq_is_empty(pq)) {
        node *n = pq->head;

        while (n) {
            printf("<%d, %d> ", n->item, n->priority);
            n = n->next;
        }
    }
}