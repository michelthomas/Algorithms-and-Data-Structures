#include <stdio.h>
#include "stack.h"

int main() {

    Stack *my_stack = create_stack();

    printf("pop: %d\n", pop(my_stack));
    printf("peek: %d\n", peek(my_stack));

    push(my_stack, 15);

    printf("pop: %d\n", pop(my_stack));
    printf("peek: %d\n", peek(my_stack));

    push(my_stack, 6);
    push(my_stack, 2);
    push(my_stack, 9);

    push(my_stack, 15);
    push(my_stack, 6);
    push(my_stack, 2);
    push(my_stack, 9);

    push(my_stack, 17);
    push(my_stack, 3);
    push(my_stack, 300);
    push(my_stack, 17);
    push(my_stack, 3);
    push(my_stack, 300);


    printf("pop: %d\n", pop(my_stack));
    printf("peek: %d\n", peek(my_stack));

    return 0;
}