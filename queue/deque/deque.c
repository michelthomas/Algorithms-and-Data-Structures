//
// Created by MichelT on 09/01/2020.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

#include "deque.h"

//Cria um node que guarda os valores que são enfileirados no deque
node_t *node_new(int value) {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));

    new_node->value = value;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}

//Cria um deque dinamicamente e retorna seu endereço de memoria
deque_t *construct() {
    deque_t *new_deque = (deque_t *) malloc(sizeof(deque_t));

    new_deque->size = 0;
    new_deque->front = NULL;
    new_deque->rear = NULL;

    return new_deque;
}

//Libera a memória do conteúdo e do próprio deque
void destruct(deque_t *deque) {
    erase(deque);

    free(deque);
}

//Retorna o tamanho do deque
int size(deque_t *deque) {
    return deque->size;
}

//Retorna verdadeiro se o deque esta vazio, caso contrário, retorna falso
bool empty(deque_t *deque) {
    return (!deque->size);
}

//Retorna o valor da frente da lista, retorna int_min quando a lista estiver vazia
int front(deque_t *deque) {
    if (empty(deque)) {
        return INT_MIN;
    }

    return deque->front->value;
}


//Retorna o valor do fim da lista, retorna int_min quando a lista estiver vazia
int rear(deque_t *deque) {
    if (empty(deque)) {
        return INT_MIN;
    }

    return deque->rear->value;
}

//Cria um nó que guarda um valor e o adiciona ao fim do deque
void enqueue_rear(deque_t *deque, int value) {
    node_t *new_node = node_new(value);

    new_node->prev = deque->rear;

    if (empty(deque)) {
        deque->rear = new_node;
        deque->front = new_node;
    } else {
        deque->rear->next = new_node;
        deque->rear = new_node;
    }

    deque->size++;
}

//Cria um nó que guarda um valor e o adiciona ao inicio do deque
void enqueue_front(deque_t *deque, int value) {
    node_t *new_node = node_new(value);

    new_node->next = deque->front;

    if (empty(deque)) {
        deque->rear = new_node;
        deque->front = new_node;
    } else {
        deque->front->prev = new_node;
        deque->front = new_node;
    }

    deque->size++;
}

//Retira o valor do final caso não esteja vazia
void dequeue_rear(deque_t *deque) {
    if (empty(deque)) {
        printf("DEQUE UNDERFLOW!");
    } else {
        node_t *node_to_remove = deque->rear;

        deque->rear = deque->rear->prev;

        if (deque->rear != NULL) {
            deque->rear->next = NULL;
        }

        deque->size--;

        free(node_to_remove);
    }
}

//Retira o valor da frente caso não esteja vazia
void dequeue_front(deque_t *deque) {
    if (empty(deque)) {
        printf("DEQUE UNDERFLOW!");
    } else {
        node_t *node_to_remove = deque->front;

        deque->front = deque->front->next;

        if (deque->front != NULL) {
            deque->front->prev = NULL;
        }

        deque->size--;

        free(node_to_remove);
    }
}

//Limpa o conteudo do deque(deixa ele vazio)
void erase(deque_t *deque) {
    while (deque->front != NULL) {
        dequeue_front(deque);
    }
}

//Imprime o deque em uma unica linha, com os elementos separados por um espaço,
//terminando com um \n, lembrando de respeitar os conceitos de fila.
void print(deque_t *deque) {
    node_t *aux = deque->front;

    int i = front(deque);
    while (aux != NULL) {

        if (aux->next == NULL) {
            printf("%d\n", aux->value);
        } else {
            printf("%d ", aux->value);
        }

        aux = aux->next;
    }
}
