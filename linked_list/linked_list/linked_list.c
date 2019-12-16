//
// Created by MichelT on 06/12/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

node* create_linked_list() {
    return NULL;
}

node* add(node* head, int item) {
    node *new_node = (node*) malloc(sizeof(node));

    new_node->item = item;

    new_node->next = head;

    return new_node;
}
node* search(node* head, int item) {
    while (head != NULL) {
        if (head->item == item) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

node* remove_node(node* head, int item) {
    node *previous = NULL;
    node *current = head;

    while (current != NULL && current->item != item) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        return head;
    }

    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);

    return head;
}

node* remove_recursively (node *head, node *prev, node *current, int item) {
    if (current == NULL) {
        return head;
    }

    if (current->item == item) {
        prev->next = current->next;
        current->next = NULL;

        free(current);

        return head;
    }

    return remove_recursively(head, current, current->next, item);
}

int is_empty(node* head) {
    return (head == NULL);
}

void print_linked_list(node *head) {
    while (!is_empty(head)) {
        printf("%d ", head->item); // TODO change to pointer to function
        head = head->next;
    }
}