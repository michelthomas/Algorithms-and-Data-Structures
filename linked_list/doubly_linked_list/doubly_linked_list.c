//
// Created by MichelT on 06/12/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

node *create_linked_list() {
    return NULL;
}

node *get_tail(node *head) {
    if (head->next == NULL) {
        return head;
    }

    return get_tail(head->next);
}

node *create_node(int key, int data) {
    node *new_node = (node *) malloc(sizeof(node));

    new_node->key = key;
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}

node *add_ordered(node *head, int key, int data) {
    node *new_node = create_node(key, data);
    node *previous = NULL;
    node *current = head;

    if (head == NULL) {

        return new_node;

    } else if (head->key == key) {

        if (head->data == data) {
            return head;
        } else if (head->data > data) {
            new_node->next = head;
            head->prev = new_node;
            return new_node;
        } else {
            /*new_node->prev = head;
            new_node->next = head->next;
            head->next = new_node;*/
            head->next = add_ordered(head->next, key, data);
            return head;
        }

    } else if (head->key > key) {

        new_node->next = head;
        head->prev = new_node;
        return new_node;

    }

    while (current != NULL && current->key < key) {
        previous = current;
        current = current->next;
    }

    if (current != NULL) {
        if (current->key == key) {

            if (current->data == data) {
                return head;
            } else if (current->data > data) {
                new_node->next = current;
                current->prev = new_node;
                return head;
            } else {/*
                new_node->prev = current;
                new_node->next = current->next;
                current->next = new_node;*/
                current->next = add_ordered(current->next, key, data);
                return head;
            }

        }
    }

    if (previous->next != NULL) {

        previous->next = new_node;
        new_node->next = current;
        new_node->prev = previous;

    } else {

        previous->next = new_node;
        new_node->prev = previous;

    }

    return head;
}

node *add_begin(node *head, int key) {
    node *new_node = (node *) malloc(sizeof(node));

    if (!new_node) {
        printf("Memory allocation error!\n");
        exit(1);
    }

    new_node->key = key;

    new_node->next = head;

    if (head != NULL) {
        head->prev = new_node;
    }

    new_node->prev = NULL;

    return new_node;
}

node *add_end(node *head, int key) {
    node *new_node = (node *) malloc(sizeof(node));

    if (!new_node) {
        printf("Memory allocation error!\n");
        exit(1);
    }

    new_node->key = key;

    node *tail = get_tail(head);

    tail->next = new_node;

    new_node->prev = tail;
    new_node->next = NULL;

    return head;
}


node *search(node *head, int key) {
    while (head != NULL) {
        if (head->key == key) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

node *remove_node(node *head, node *node_to_remove) {

    if (node_to_remove == NULL) {
        return head;
    }

    if (node_to_remove->prev != NULL) {
        node_to_remove->prev->next = node_to_remove->next;
    } else {
        head = node_to_remove->next;
    }

    if (node_to_remove->next != NULL) {
        node_to_remove->next->prev = node_to_remove->prev;
    }

    free(node_to_remove);

    return head;
}

node *remove_node_by_key(node *head, int key) {
    return remove_node(head, search(head, key));
}

node *remove_recursively(node *head, node *prev, node *current, int key) {
    if (current == NULL) {
        return head;
    }

    if (current->key == key) {
        prev->next = current->next;
        current->next = NULL;

        free(current);

        return head;
    }

    return remove_recursively(head, current, current->next, key);
}

int is_empty(node *head) {
    return (head == NULL);
}

void print_linked_list(node *head) {
    while (!is_empty(head)) {
        printf("%d ", head->key); // TODO change to pointer to function
        head = head->next;
    }
}