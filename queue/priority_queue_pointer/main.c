#include <stdio.h>

#include "priority_queue_pointer.h"

int main() {
    p_queue *my_pq = create_priority_queue();

    int p[] = {100, 80, 90, 2, 5};
    for (int i = 0; i < 3; ++i) {
        pq_enqueue(my_pq, i, p[i]);
    }

    print_priority_queue(my_pq);
    return 0;

}
