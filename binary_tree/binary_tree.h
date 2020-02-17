//
// Created by MichelT on 09/01/2020.
//

#ifndef BINARY_TREE_BINARY_TREE_H
#define BINARY_TREE_BINARY_TREE_H


typedef struct b_tree {
    int key;
    int valor;
    struct b_tree *parent;
    struct b_tree *left;
    struct b_tree *right;
} b_tree;

b_tree *create_binary_tree(int item, int valor, b_tree *left, b_tree *right);

b_tree *search(b_tree *tree, int key);

int depth(b_tree *tree);

int is_empty(b_tree *tree);

int is_leaf(b_tree *tree);

void print_pre_order(b_tree *tree);

void print_pre_order_with_parentheses(b_tree *tree);

void print_in_order(b_tree *tree);

void print_post_order(b_tree *tree);

int is_binary_search_tree(b_tree *tree);

b_tree *create_binary_tree_from_string(char *str);

b_tree *create_binary_tree_from_arr(int arr[], int n);

#endif //BINARY_TREE_BINARY_TREE_H
