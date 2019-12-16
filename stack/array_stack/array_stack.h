//
// Created by MichelT on 10/12/2019.
//

#ifndef ARRAY_STACK_ARRAY_STACK_H
#define ARRAY_STACK_ARRAY_STACK_H
#define MAX_STACK_SIZE 10

typedef struct stack {
    int current_size;
    int items[MAX_STACK_SIZE];
} Stack;

Stack* create_stack();
void push(Stack* stack, int item);
int pop(Stack* stack);
int peek(Stack* stack);
int is_empty(Stack* stack);
int is_full(Stack *stack);



#endif //ARRAY_STACK_ARRAY_STACK_H
