//
// Created by MichelT on 10/12/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


Stack *create_stack() {
    Stack *new_stack = (Stack*) malloc(sizeof(Stack));
    new_stack->top = NULL;
    return new_stack;
}

void push(Stack *stack, int item) {
    Node *new_top = (Node*) malloc(sizeof(Node));
    new_top->item = item;
    new_top->next = stack->top;
    stack->top = new_top;
}

int pop(Stack *stack) {
    if (!is_empty(stack)) {

        Node *top_pop = stack->top;

        int item_pop = top_pop->item;

        stack->top = top_pop->next;

        free(top_pop);

        return item_pop;

    } else {
        printf("STACK UNDERFLOW!\n");
        return -1;
    }
}

int peek(Stack *stack) {
    if (!is_empty(stack)) {
        return stack->top->item;
    } else {
        printf("STACK UNDERFLOW!\n");
        return -1;
    }
}

int is_empty(Stack *stack) {
    return (!stack->top);
}


