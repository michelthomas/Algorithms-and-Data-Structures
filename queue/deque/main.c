#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#include "deque.h"

int main() {
    int i, num;
    scanf("%d", &num);

    deque_t* deque = construct();

    int vector[num];
    for(i = 0; i < num; ++i)
        scanf("%d", &vector[i]);

    for(i = 0; i < num; ++i)
        enqueue_rear(deque, vector[i]);

    printf("%d\n", front(deque));
    printf("%d\n", rear (deque));

    if(!empty(deque))
        printf("The size of the deque %d\n", size(deque));
    else
        printf("The deque is empty\n");

    scanf("%d", &num);
    for(i = 0; i < num; ++i)
        enqueue_front(deque, i);
    print(deque);
    dequeue_front(deque);
    print(deque);
    dequeue_rear (deque);
    print(deque);

    erase(deque);
    for(i = 0; i < 3; ++i)
        enqueue_rear(deque, i);

    print(deque);
    destruct(deque);

    return 0;
}
