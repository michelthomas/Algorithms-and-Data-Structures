//
// Created by MichelT on 15/12/2019.
//

#include <stdio.h>
#include <stdlib.h>
#include "avl_tree.h"


avl_tree *create_binary_tree(int key, int data, int size, int height, int depth, avl_tree *parent, avl_tree *left_tree,
                             avl_tree *right_tree) {

    avl_tree *new_tree = (avl_tree*) malloc(sizeof(avl_tree));

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

int is_empty(avl_tree *tree) {
    return (tree == NULL);
}

avl_tree* insert(avl_tree *parent_tree, avl_tree* tree) {
    avl_tree *y = NULL;
    avl_tree *x = parent_tree;

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

avl_tree *add(avl_tree *parent_tree, int key, int data) {
    avl_tree *new_tree = create_binary_tree(key, data, 1, 0, 0, parent_tree, NULL, NULL);

    parent_tree = insert(parent_tree, new_tree);

    parent_tree = rebalance(parent_tree, new_tree);

    return parent_tree;
}



avl_tree* search(avl_tree *tree, int key) {
    if (is_empty(tree) || key == tree->key) {
        return tree;
    } else if (key < tree->key) {
        return search(tree->left, key);
    } else {
        return search(tree->right, key);
    }
}

/* On most computers, the iterative version is more efficient. Cormen - Introduction to Algorithms*/
avl_tree* iterative_search(avl_tree *tree, int key) {
    while (!is_empty(tree) || key != tree->key) {
        if (key < tree->key) {
            tree = tree->left;
        } else {
            tree = tree->right;
        }
    }
    return tree;
}

avl_tree* min(avl_tree *tree) {
    while (!is_empty(tree->left)) {
        tree = tree->left;
    }
    return tree;
}

avl_tree* max(avl_tree *tree) {
    while (!is_empty(tree->right)) {
        tree = tree->right;
    }
    return tree;
}


avl_tree* predecessor(avl_tree *tree) {
    if (!is_empty(tree->left)) {
        return max(tree->left);
    }

    avl_tree *parent = tree->parent;

    while (!is_empty(parent) && tree->key == parent->left->key) {
        tree = parent;
        parent = parent->parent;
    }

    return parent;
}

avl_tree* successor(avl_tree *tree) {
    if (!is_empty(tree->right)) {
        return min(tree->right);
    }

    avl_tree *parent = tree->parent;

    while (!is_empty(parent) && tree->key == parent->right->key) {
        tree = parent;
        parent = parent->parent;
    }

    return parent;
}

int size(avl_tree *tree) {
    if (is_empty(tree)) {
        return 0;
    }

    return size(tree->left) + size(tree->right) + 1;
}

avl_tree* update_size(avl_tree *tree) {
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

int height(avl_tree *tree) {
    if (is_empty(tree)) {
        return -1;
    }

    return max_number(height(tree->left), height(tree->right)) + 1;
}

avl_tree* update_height(avl_tree *tree) {
    tree->height = height(tree);
    return tree;
}

int depth(avl_tree *tree) {
    if (is_empty(tree)) {
        return -1;
    }

    return depth(tree->parent) + 1;
}

void deallocate(avl_tree *node) {
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    free(node);
}

avl_tree *transplant(avl_tree *root, avl_tree *u, avl_tree *v) {
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

avl_tree* remove_node(avl_tree *tree, int key) {
    avl_tree *node = search(tree, key);

    if (node) {
        tree = delete(tree, node);
    }

    return tree;
}

avl_tree *delete(avl_tree *root, avl_tree* node) {
    if (is_empty(node->left)) {
        root = transplant(root, node, node->right);
        root = update_size(node->parent);
        root = rebalance(root, node->parent);
        deallocate(node);
    } else if (is_empty(node->right)) {
        root = transplant(root, node, node->left);
        root = update_size(node->parent);
        root = rebalance(root, node->parent);
        deallocate(node);

    } else {
        avl_tree *successor = min(node->right);

        avl_tree *node_to_update = successor; // keep the successor parent to update size later

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
        root = rebalance(root, node_to_update);

        deallocate(node);
    }

    return root;
}

avl_tree* left_rotate(avl_tree *tree, avl_tree *x) {
    avl_tree *y = x->right;
    y->parent = x->parent;

    if (is_empty(y->parent)) {
        tree = y;
    } else {
        if (y->parent->left == x) {
            y->parent->left = y;
        } else if (y->parent->right == x) {
            y->parent->right = y;
        }
    }

    x->right = y->left;

    if (!is_empty(x->right)){
        x->right->parent = x;
    }

    y->left = x;
    x->parent = y;

    tree = update_height(x);
    tree = update_height(y);

    return tree;
}

avl_tree* right_rotate(avl_tree *tree, avl_tree *x) {
    avl_tree *y = x->left;
    y->parent = x->parent;

    if (is_empty(y->parent)) {
        tree = y;
    } else {
        if (y->parent->left == x) {
            y->parent->left = y;
        } else if (y->parent->right == x) {
            y->parent->right = y;
        }
    }

    x->left = y->right;

    if (!is_empty(x->left)){
        x->left->parent = x;
    }

    y->right = x;
    x->parent = y;

    tree = update_height(x);
    tree = update_height(y);

    return tree;
}

avl_tree* rebalance(avl_tree *tree, avl_tree *node) {
    while (!is_empty(node)) {
        tree = update_height(node);
        if (height(node->left) >= 2 + height(node->right)) {
            if (height(node->left->left) >= height(node->left->right)) {
                tree = right_rotate(tree, node);
            }
            else {
                tree = left_rotate(tree, node->left);
                tree = right_rotate(tree, node);
            }
        } else if (height(node->right) >= 2 + height(node->left)) {
            if (height(node->right->right) >= height(node->right->left)) {
                tree = left_rotate(tree, node);
            }
            else {
                tree = right_rotate(tree, node->right);
                tree = left_rotate(tree, node);
            }
        }
        tree = update_size(node);
        node = node->parent;
    }

    return tree;
}

void print_pre_order(avl_tree *tree) {
    if (!is_empty(tree)) {
        printf("%d ", tree->key);
        print_pre_order(tree->left);
        print_pre_order(tree->right);
    }
}

void print_in_order(avl_tree *tree) {
    if (!is_empty(tree)) {
        print_in_order(tree->left);
        printf("%d ", tree->key);
        print_in_order(tree->right);
    }
}

void print_post_order(avl_tree *tree) {
    if (!is_empty(tree)) {
        print_post_order(tree->left);
        print_post_order(tree->right);
        printf("%d ", tree->key);
    }
}