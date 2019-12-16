//
// Created by MichelT on 06/12/2019.
//


#ifndef LINKED_LIST_LINKED_LIST_H
#define LINKED_LIST_LINKED_LIST_H

typedef struct node{
    int item;
    struct node *next;
} node;

node* create_linked_list();
node* add(node* head, int item);
node* search(node* head, int item);
node* remove_node(node* head, int item);
node* remove_recursively (node *head, node *prev, node *current, int item);
int is_empty(node* head);
void print_linked_list(node *head);

#endif //LINKED_LIST_LINKED_LIST_H
