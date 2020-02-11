//
// Created by MichelT on 09/01/2020.
//

#include <stdio.h>
#include <stdlib.h>

#include "binary_tree.h"

b_tree *create_binary_tree(int item, int valor, b_tree *left, b_tree *right) {
    b_tree *bt = (b_tree*) malloc(sizeof(b_tree));

    bt->key = item;
    bt->valor = valor;
    bt->parent = NULL;
    bt->left = NULL;
    bt->right = NULL;

    return bt;
}

b_tree *search(b_tree *tree, int key) {

    if (is_empty(tree)) {
        return NULL;
    }
    if (tree->key == key) {
        return tree;
    }

    b_tree *r;

    r = search(tree->left, key);

    if (is_empty(r)) {
        r = search(tree->right, key);
    }

    return r;
}

int depth(b_tree *tree) {
    if (is_empty(tree)) {
        return -1;
    }

    return depth(tree->parent) + 1;
}

int is_empty(b_tree *tree) {
    return (tree == NULL);
}


void print_pre_order(b_tree *tree) {
    if (!is_empty(tree)) {
        printf("%d ", tree->key);
        print_pre_order(tree->left);
        print_pre_order(tree->right);
    }
}

void print_in_order(b_tree *tree) {
    if (!is_empty(tree)) {
        print_in_order(tree->left);
        printf("%d ", tree->key);
        print_in_order(tree->right);
    }
}

void print_post_order(b_tree *tree) {
    if (!is_empty(tree)) {
        print_post_order(tree->left);
        print_post_order(tree->right);
        printf("%d ", tree->key);
    }
}

void print_pre_order_with_parentheses(b_tree *tree) {
    if (is_empty(tree)) {
        printf("()");
    } else {
        printf("(%d", tree->key);
        print_pre_order_with_parentheses(tree->left);
        print_pre_order_with_parentheses(tree->right);
        printf(")");
    }
}


void aux_is_binary_search_tree(b_tree *tree, int *list, int *i) {
    if (!is_empty(tree)) {
        aux_is_binary_search_tree(tree->left, list, i);
        list[*i] = tree->key;
        (*i)++;
        aux_is_binary_search_tree(tree->right, list, i);
    }
}

int is_binary_search_tree(b_tree *tree) {
    if (is_empty(tree)){
        return 1;
    }

    int list[100];
    int n = 0;

    aux_is_binary_search_tree(tree, list, &n);

    for (int i = 0; i < n - 1; ++i) {
        if (list[i] > list[i + 1]) {
            return 0;
        }
        //printf("%d ", list[i]);
    }

    return 1;
}

int is_leaf(b_tree *tree) {
    if (is_empty(tree)) {
        return 0;
    } else if (is_empty(tree->left) && is_empty(tree->right)){
        return 1;
    }

    return 0;
}

int get_key_number(char *string, int *i) {
    char key_str[10];

    int j = 0;

    while (string[*i] != '(') {
        key_str[j] = string[*i];
        (*i)++;
        j++;
    }

    key_str[j] = '\0';

    return atoi(key_str);
}

b_tree* create_binary_tree_from_string(char *string, int *i) {
    if (string[*i] == ')') {
        return NULL;
    }

    if (string[*i] == ' ') {
        (*i)++;
    }

    if (string[*i] == '(') {
        (*i)++;
    }

    b_tree *new_bt = NULL;

    if (string[*i] != ')') {
        new_bt = create_binary_tree(get_key_number(string, i), 0, NULL, NULL);
        new_bt->left = create_binary_tree_from_string(string, i);

        if(!is_empty(new_bt->left)) {
            new_bt->left->parent = new_bt;
        }

        new_bt->right = create_binary_tree_from_string(string, i);

        if(!is_empty(new_bt->right)) {
            new_bt->right->parent = new_bt;
        }

    }

    (*i)++;

    return new_bt;
}