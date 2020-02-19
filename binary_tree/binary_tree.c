//
// Created by MichelT on 09/01/2020.
//

#include <stdio.h>
#include <stdlib.h>

#include "binary_tree.h"

b_tree *create_binary_tree(int item, int freq, int valor, b_tree *left, b_tree *right) {
    b_tree *bt = (b_tree *) malloc(sizeof(b_tree));

    bt->key = item;
    bt->freq = freq;
    bt->valor = valor;
    bt->parent = NULL;
    bt->left = left;
    bt->right = right;

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
        printf("%c", tree->valor);
        print_pre_order(tree->left);
        print_pre_order(tree->right);
    }
}

void print_in_order(b_tree *tree) {
    if (!is_empty(tree)) {
        print_in_order(tree->left);
        printf("%c", tree->key);
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
    if (is_empty(tree)) {
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
    } else if (is_empty(tree->left) && is_empty(tree->right)) {
        return 1;
    }

    return 0;
}

int get_key_number(char *string, int *i) {
    char key_str[100];

    int j = 0;

    while (string[*i] != '(') {
        key_str[j] = string[*i];
        (*i)++;
        j++;
    }

    key_str[j] = '\0';

    return atoi(key_str);
}

b_tree *_create_binary_tree_from_string(char *str, int *i) {
/*
    if (str[*i] == ')') {
        return NULL;
    }

    if (str[*i] == ' ') {
        (*i)++;
    }
*/

    if (str[*i] == '(') {
        (*i)++;
    }

    b_tree *new_bt = NULL;

    if (str[*i] != ')') {
//        new_bt = create_binary_tree(get_key_number(str, i), 0, 0, NULL, NULL, 0);
        new_bt->left = _create_binary_tree_from_string(str, i);

        if (!is_empty(new_bt->left)) {
            new_bt->left->parent = new_bt;
        }

        new_bt->right = _create_binary_tree_from_string(str, i);

        if (!is_empty(new_bt->right)) {
            new_bt->right->parent = new_bt;
        }

    }

    (*i)++;

    return new_bt;
}

b_tree *create_binary_tree_from_string(char *str) {
    int i = 0;

    return _create_binary_tree_from_string(str, &i);
}


b_tree *_create_binary_tree_from_arr(b_tree *t, int arr[], int i, int n) {

    if (i > n) {
        return NULL;
    }

//    t = create_binary_tree(arr[i - 1], 0, arr[i - 1], NULL, NULL, 0);

    t->left = _create_binary_tree_from_arr(t, arr, 2 * i, n);
    t->right = _create_binary_tree_from_arr(t, arr, 2 * i + 1, n);

    return t;
}


b_tree *create_binary_tree_from_arr(int arr[], int n) {

    b_tree *t = NULL;

    return _create_binary_tree_from_arr(t, arr, 1, n);
}