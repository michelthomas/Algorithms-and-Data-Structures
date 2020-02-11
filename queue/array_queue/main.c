#include <stdio.h>
#include "queue.h"
#include "priority_queue_pointer.h"


// teste
void teste();

// Fila do Recreio Huxley p.414
void fila_recreio();

int main() {
    fila_recreio();
    return 0;
}

void teste() {
    queue *my_queue = create_queue();

    for (int i = 0; i < MAX_QUEUE_SIZE; ++i) {
        enqueue(my_queue, i);
    }

    print_queue(my_queue);
    printf("\n");

    dequeue(my_queue);
    dequeue(my_queue);
    dequeue(my_queue);

    for (int i = 0; i < MAX_QUEUE_SIZE; ++i) {
        dequeue(my_queue);
    }

    printf("\n%d %d", my_queue->head, my_queue->tail);
    printf("\n");
    print_queue(my_queue);
    printf("\n");
}

void fila_recreio() {
    int n;
    scanf("%d", &n);

    int m;
    int p;
    int trocadas = 0;

    queue *q = create_queue();
    p_queue *pq = create_priority_queue();

    for (int i = 0; i < n; ++i) {
        scanf("%d", &m);

        for (int j = 0; j < m; ++j) {
            scanf("%d", &p);

            pq_enqueue(pq, i, p);
            enqueue(q, p);
        }

        /*print_priority_queue(pq);
        printf("\n");
        print_queue(q);*/

        for (int k = 0; k < m; ++k) {
            if (dequeue(q) != pq_dequeue(pq)->priority) {
                trocadas++;
            }
        }

        printf("%d\n", m - trocadas);

        trocadas = 0;
    }
}

