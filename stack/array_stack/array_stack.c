//
// Created by MichelT on 10/12/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include "array_stack.h"

void push(Stack *stack, int item) {
    if (!is_full(stack)) {

        stack->items[stack->current_size++] = item;

    } else {
        printf("STACK OVERFLOW!");
    }
}

int pop(Stack *stack) {
    if (!is_empty(stack)) {

        int itemToPop = stack->items[stack->current_size - 1];

        stack->items[stack->current_size - 1] = -1; // Or NULL

        stack->current_size--;

        return itemToPop;

    } else {
        printf("STACK UNDERFLOW!\n");
        return -1;
    }
}

int peek(Stack *stack) {
    if (!is_empty(stack)) {
        return stack->items[stack->current_size - 1];
    } else {
        printf("STACK UNDERFLOW\n");
        return -1;
    }
}

int is_empty(Stack *stack) {
    return (!stack->current_size);
}

int is_full(Stack *stack) {
    return (stack->current_size >= MAX_STACK_SIZE);
}

Stack *create_stack() {
    Stack *new_stack = (Stack*) malloc(sizeof(Stack));
    new_stack->current_size = 0;
    return new_stack;
}



