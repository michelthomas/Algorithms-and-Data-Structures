//
// Created by MichelT on 06/12/2019.
//


#ifndef LINKED_LIST_DOUBLY_LINKED_LIST_H
#define LINKED_LIST_DOUBLY_LINKED_LIST_H

typedef struct node{
    int key;
    struct node *prev;
    struct node *next;
} node;

node* create_linked_list();
node* get_tail(node *head);
node* add_begin(node *head, int key);
node* add_end(node *head, int key);
node* search(node *head, int key);
node* remove_node(node *head, node *node_to_remove);
node* remove_node_by_key(node* head, int key);
node* remove_recursively (node *head, node *prev, node *current, int key);
int is_empty(node* head);
void print_linked_list(node *head);

#endif //LINKED_LIST_DOUBLY_LINKED_LIST_H
