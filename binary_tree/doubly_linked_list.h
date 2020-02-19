//
// Created by MichelT on 06/12/2019.
//


#ifndef LINKED_LIST_DOUBLY_LINKED_LIST_H
#define LINKED_LIST_DOUBLY_LINKED_LIST_H

#include "binary_tree.h"

typedef struct node{
    int key;
    int valor;
    void *data;
    b_tree *tree;
    struct node *prev;
    struct node *next;
} node;

node* create_linked_list();
node *create_node(int key, int valor, void *data, b_tree *t);
node* get_tail(node *head);
node *add_ordered(node *head, int key, int valor);
node *add_ordered_huff_tree(node *head, b_tree *tree);
node *add_ordered_internal_node(node *head, b_tree *tree);
node* add_begin(node *head, int key);
node* add_end(node *head, int key);
node* search_list(node *head, int key);
node *dequeue(node *head);
node* remove_node_list(node *head, node *node_to_remove);
node* remove_node_by_key(node* head, int key);
node* remove_recursively (node *head, node *prev, node *current, int key);
int is_empty_list(node* head);
void print_linked_list(node *head);

#endif //LINKED_LIST_DOUBLY_LINKED_LIST_H
