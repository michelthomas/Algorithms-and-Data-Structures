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

node *create_node(int key, int valor, void *data, b_tree *t) {
    node *new_node = (node *) malloc(sizeof(node));

    new_node->key = key;
    new_node->valor = valor;
    new_node->data = data;
    new_node->tree = t;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}

/*
node *add_ordered(node *head, int key, int valor) {
    node *new_node = create_node(key, valor, NULL);
    node *previous = NULL;
    node *current = head;

    if (head == NULL) {

        return new_node;

    } else if (head->key == key) {

        if (head->valor == valor) {
            return head;
        } else if (head->valor > valor) {
            new_node->next = head;
            head->prev = new_node;
            return new_node;
        } else {
            *//*new_node->prev = head;
            new_node->next = head->next;
            head->next = new_node;*//*
            head->next = add_ordered(head->next, key, valor);
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

            if (current->valor == valor) {
                return head;
            } else if (current->valor > valor) {
                new_node->next = current;
                current->prev = new_node;
                return head;
            } else {*//*
                new_node->prev = current;
                new_node->next = current->next;
                current->next = new_node;*//*
                current->next = add_ordered(current->next, key, valor);
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
}*/

node *add_ordered_huff_tree(node *head, b_tree *tree) {
    node *new_node = create_node(tree->freq, tree->key, NULL, tree);
    node *previous = NULL;
    node *current = head;

    if (head == NULL) {

        return new_node;

    } else if (head->key == tree->freq) {

        if (head->tree->key == tree->key) {
            return head;
        } else if (head->tree->key > tree->key) {
            new_node->next = head;
            head->prev = new_node;
            return new_node;
        } else {
            /*new_node->prev = head;
            new_node->next = head->next;
            head->next = new_node;*/
            head->next = add_ordered_huff_tree(head->next, tree);
            return head;
        }

    } else if (head->key > tree->freq) {

        new_node->next = head;
        head->prev = new_node;
        return new_node;

    }

    while (current != NULL && current->key < tree->freq) {
        previous = current;
        current = current->next;
    }

    if (current != NULL) {
        if (current->key == tree->freq) {

            if (current->valor == tree->key) {
                return head;
            } else if (current->valor > tree->key) {
                previous->next = new_node;
                new_node->prev = previous;
                new_node->next = current;
                current->prev = new_node;
                return head;
            } else {/*
                new_node->prev = current;
                new_node->next = current->next;
                current->next = new_node;*/
                current->next = add_ordered_huff_tree(current->next, tree);
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

node *add_ordered_internal_node(node *head, b_tree *tree) {
    node *new_node = create_node(tree->freq, tree->key, NULL, tree);
    node *previous = NULL;
    node *current = head;

    if (head == NULL) {

        return new_node;

    } else if (head->key >= tree->freq) {

        new_node->next = head;
        head->prev = new_node;
        return new_node;

    }

    while (current != NULL && current->key < tree->freq) {
        previous = current;
        current = current->next;
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


node *search_list(node *head, int key) {
    while (head != NULL) {
        if (head->key == key) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

node *dequeue(node *head) {
    return head->next;
}

node *remove_node_list(node *head, node *node_to_remove) {

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
    return remove_node_list(head, search_list(head, key));
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

int is_empty_list(node *head) {
    return (head == NULL);
}

void print_linked_list(node *head) {
    while (!is_empty_list(head)) {
        printf("%d(%c) ", head->key, (char) head->valor); // TODO change to pointer to function
        head = head->next;
    }
}