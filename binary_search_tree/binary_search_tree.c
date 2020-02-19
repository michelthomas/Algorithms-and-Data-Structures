//
// Created by MichelT on 11/12/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"

bs_tree *create_empty_binary_tree() {
    return NULL;
}

bs_tree *create_binary_search_tree(int key, int data) {
    return create_binary_search_tree_all_params(key, data, 1, 0, 0, NULL, NULL, NULL);

}

bs_tree *create_binary_search_tree_all_params(int key, int data, int size, int height, int depth, bs_tree *parent,
                                              bs_tree *left_tree,
                                              bs_tree *right_tree) {

    bs_tree *new_tree = (bs_tree *) malloc(sizeof(bs_tree));

    new_tree->parent = parent;
    new_tree->key = key;
    new_tree->data = data;
    new_tree->size = size;
    new_tree->height = height;
    new_tree->depth = depth;
    new_tree->left = left_tree;
    new_tree->right = right_tree;

    return new_tree;
}

int is_empty(bs_tree *tree) {
    return (tree == NULL);
}

bs_tree *insert(bs_tree *parent_tree, bs_tree *tree) {
    bs_tree *y = NULL;
    bs_tree *x = parent_tree;

    while (!is_empty(x)) {
        y = x;

        y->size++;

        if (tree->key < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    tree->parent = y;

    if (is_empty(y)) {
        parent_tree = tree;
    } else if (tree->key < y->key) {
        y->left = tree;
    } else {
        y->right = tree;
    }

    return parent_tree;
}

bs_tree *add(bs_tree *parent_tree, int key, int data) {
    bs_tree *new_tree = create_binary_search_tree_all_params(key, data, 1, 0, 0, parent_tree, NULL, NULL);

    parent_tree = insert(parent_tree, new_tree);

    return parent_tree;
}


bs_tree *search(bs_tree *tree, int key) {
    if (is_empty(tree) || key == tree->key) {
        return tree;
    } else if (key < tree->key) {
        return search(tree->left, key);
    } else {
        return search(tree->right, key);
    }
}

/* On most computers, the iterative version is more efficient. Cormen - Introduction to Algorithms*/
bs_tree *iterative_search(bs_tree *tree, int key) {
    while (!is_empty(tree) || key != tree->key) {
        if (key < tree->key) {
            tree = tree->left;
        } else {
            tree = tree->right;
        }
    }
    return tree;
}

bs_tree *min(bs_tree *tree) {
    while (!is_empty(tree->left)) {
        tree = tree->left;
    }
    return tree;
}

bs_tree *max(bs_tree *tree) {
    while (!is_empty(tree->right)) {
        tree = tree->right;
    }
    return tree;
}


bs_tree *predecessor(bs_tree *tree) {
    if (!is_empty(tree->left)) {
        return max(tree->left);
    }

    bs_tree *parent = tree->parent;

    while (!is_empty(parent) && tree->key == parent->left->key) {
        tree = parent;
        parent = parent->parent;
    }

    return parent;
}

bs_tree *successor(bs_tree *tree) {
    if (!is_empty(tree->right)) {
        return min(tree->right);
    }

    bs_tree *parent = tree->parent;

    while (!is_empty(parent) && tree->key == parent->right->key) {
        tree = parent;
        parent = parent->parent;
    }

    return parent;
}

int size(bs_tree *tree) {
    if (is_empty(tree)) {
        return 0;
    }

    return size(tree->left) + size(tree->right) + 1;
}

bs_tree *update_size(bs_tree *tree) {
    if (is_empty(tree->parent)) {
        tree->size = size(tree);
        return tree;
    }

    tree->size = size(tree);

    return update_size(tree->parent);
}

int max_number(int x, int y) {
    return (x > y) ? x : y;
}

int height(bs_tree *tree) {
    if (is_empty(tree)) {
        return -1;
    }

    return max_number(height(tree->left), height(tree->right)) + 1;
}

bs_tree *update_height(bs_tree *tree) {
    tree->height = height(tree);
    return tree;
}

int depth(bs_tree *tree) {
    if (is_empty(tree)) {
        return -1;
    }

    return depth(tree->parent) + 1;
}

void deallocate(bs_tree *node) { // TODO fix this
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    free(node);
}

bs_tree *transplant(bs_tree *root, bs_tree *u, bs_tree *v) {
    if (is_empty(u->parent)) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }

    if (!is_empty(v)) {
        v->parent = u->parent;
    }

    return root;
}

bs_tree *remove_node(bs_tree *tree, int key) {
    bs_tree *node = search(tree, key);

    if (node) {
        tree = delete(tree, node);
    }

    return tree;
}

bs_tree *delete(bs_tree *root, bs_tree *node) {
    if (is_empty(node->left)) {
        root = transplant(root, node, node->right);
        root = update_size(node->parent);
        deallocate(node);
    } else if (is_empty(node->right)) {
        root = transplant(root, node, node->left);
        root = update_size(node->parent);
        deallocate(node);

    } else {
        bs_tree *successor = min(node->right);

        bs_tree *node_to_update = successor; // keep the successor parent to update size later

        if (successor->parent != node) { // check if successor isn't the direct child
            node_to_update = successor->parent;
            root = transplant(root, successor, successor->right);
            successor->right = node->right;
            successor->right->parent = successor;
        }

        root = transplant(root, node, successor);
        successor->left = node->left;
        successor->left->parent = successor;

        root = update_size(node_to_update);

        deallocate(node);
    }

    return root;
}

void print_pre_order(bs_tree *tree) {
    if (!is_empty(tree)) {
        printf("%d ", tree->key);
        print_pre_order(tree->left);
        print_pre_order(tree->right);
    }
}

void print_pre_order_with_parentheses(bs_tree *tree) {
    if (is_empty(tree)) {
        printf(" () ");
    } else {
        printf(" ( %d ", tree->key);
        print_pre_order_with_parentheses(tree->left);
        print_pre_order_with_parentheses(tree->right);
        printf(") ");
    }
}

void print_in_order(bs_tree *tree) {
    if (!is_empty(tree)) {
        print_in_order(tree->left);
        printf("%d ", tree->key);
        print_in_order(tree->right);
    }
}

void print_post_order(bs_tree *tree) {
    if (!is_empty(tree)) {
        print_post_order(tree->left);
        print_post_order(tree->right);
        printf("%d ", tree->key);
    }
}

int get_number_of_leafs(bs_tree *tree) {
    if (is_empty(tree)) {
        return 0;
    }
    if (is_empty(tree->left) && is_empty(tree->right)) {
        return 1;
    }

    return get_number_of_leafs(tree->left) + get_number_of_leafs(tree->right);
}

int is_leaf(bs_tree *tree) {
    if (is_empty(tree)) {
        return 0;
    } else if (is_empty(tree->left) && is_empty(tree->right)) {
        return 1;
    }

    return 0;
}

int get_number_of_one_children_tree(bs_tree *tree) {
    if (is_empty(tree) || is_leaf(tree)) {
        return 0;
    }

    if ((is_empty(tree->left) && !is_empty(tree->right)) || (is_empty(tree->right) && !is_empty(tree->left))) {
        return 1;
    }

    return get_number_of_one_children_tree(tree->left) + get_number_of_one_children_tree(tree->right);
}

bs_tree *get_parents_with_one_child(bs_tree *tree, bs_tree *parents_of_one_child_tree) {
    if (is_empty(tree) || is_leaf(tree)) {
        return parents_of_one_child_tree;
    }

    if ((is_empty(tree->left) && !is_empty(tree->right)) || (is_empty(tree->right) && !is_empty(tree->left))) {
        parents_of_one_child_tree = add(parents_of_one_child_tree, tree->key, tree->data);
    }

    parents_of_one_child_tree = get_parents_with_one_child(tree->left, parents_of_one_child_tree);
    parents_of_one_child_tree = get_parents_with_one_child(tree->right, parents_of_one_child_tree);

    return parents_of_one_child_tree;
}

int is_complete(bs_tree *tree) {
    if (tree->height == 0 ||
        ((get_number_of_one_children_tree(tree) == 0) && (tree->left->height == tree->right->height))) {
        return 1;
    }

    return 0;
}


bs_tree *create_binary_tree(int item, bs_tree *left, bs_tree *right) {
    bs_tree *new_bt = (bs_tree *) malloc(sizeof(bs_tree));

    new_bt->key = item;
    new_bt->height = 1;
    new_bt->left = NULL;
    new_bt->right = NULL;

    return new_bt;
}


bs_tree *generate_bs_tree(char *string, int *cont) {
    bs_tree *bt = NULL;

    char string_value[100];
    int string_to_number;

    while (string[*cont] == '(') {
        *cont += 1;
    }

    if (string[*cont] != ')') {
        int i = 0;

        while (string[*cont] != '(') {
            string_value[i++] = string[*cont];
            *cont += 1;
        }

        string_value[i] = '\0';
        string_to_number = atoi(string_value);

        bt = create_binary_tree(string_to_number, NULL, NULL);
        bt->left = generate_bs_tree(string, cont);
        bt->right = generate_bs_tree(string, cont);
        bt->height = height(bt);
    }

    *cont += 1;

    return bt;
}
