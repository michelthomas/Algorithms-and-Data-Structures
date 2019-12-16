//
// Created by MichelT on 10/12/2019.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

typedef struct node {
    int item;
    struct node *next;
} Node;

typedef struct stack {
    Node *top;
} Stack;

Stack* create_stack();
void push(Stack* stack, int item);
int pop(Stack* stack);
int peek(Stack* stack);
int is_empty(Stack* stack);
int is_full(Stack *stack);

#endif //STACK_STACK_H
