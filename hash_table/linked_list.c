//
// Created by MichelT on 06/12/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

node* create_linked_list() {
    return NULL;
}

node* get_tail(node *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    return get_tail(head->next);
}

node *add_begin(node *head, int key, void *data) {
    node *new_node = (node*) malloc(sizeof(node));

    if (!new_node) {
        printf("Memory allocation error!\n");
        exit(1);
    }

    new_node->key = key;

    new_node->data = data;

    new_node->next = head;

    if (head != NULL) {
        head->prev = new_node;
    }

    new_node->prev = NULL;

    return new_node;
}

node *add_end(node *head, int key, void *data) {
    if(head == NULL) {
        return add_begin(head, key, NULL);
    }

    node *new_node = (node*) malloc(sizeof(node));

    if (!new_node) {
        printf("Memory allocation error!\n");
        exit(1);
    }

    new_node->key = key;

    new_node->data = data;

    node *tail = get_tail(head);

    if(tail != NULL) {
        tail->next = new_node;
    }

    new_node->prev = tail;
    new_node->next = NULL;

    return head;
}


node* search(node* head, int key) {
    while (head != NULL) {
        if (head->key == key) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}


node* get_node(node *head, int key) {
    while (head != NULL) {
        if (head->key == key) {
            node *getted = (node*) malloc(sizeof(node));

            if (!getted) {
                printf("Memory allocation error!\n");
                exit(1);
            }

            getted->key = head->key;
            getted->prev = NULL;
            getted->next = NULL;

            //TODO change later to pointer to void to support other data
            //getted->data = head->data;
            return getted;
        }
        head = head->next;
    }

    return NULL;
}

int contains(node *head, int key) {
    while (head != NULL) {
        if (head->key == key) {
            return 1;
        }
        head = head->next;
    }

    return 0;
}

node* remove_node(node *head, node *node_to_remove) {

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

node* remove_node_by_key(node* head, int key) {
    return remove_node(head, search(head, key));
}

node* remove_recursively (node *head, node *prev, node *current, int key) {
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

node* clear(node *head) {
    if (head == NULL) {
        return NULL; //TODO change to empty file with metadata...
    }

    node *next = head->next;

    head->prev = NULL;
    head->next = NULL;
    free(head);

    return clear(next);
}

int is_empty(node* head) {
    return (head == NULL);
}

void print_linked_list(node *head, void (*print_func)(void *data)) {
    while (!is_empty(head)) {
        //printf("%d ", head->key); // TODO change to pointer to function
        print_func(head->data);
        head = head->next;
    }
}

void print_linked_list_one_node_per_line(node *head) {
    while (!is_empty(head)) {
        printf("%d\n", head->key); // TODO change to pointer to function
        head = head->next;
    }
}