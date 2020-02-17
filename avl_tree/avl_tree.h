//
// Created by MichelT on 15/12/2019.
//

#ifndef AVL_TREE_AVL_TREE_H
#define AVL_TREE_AVL_TREE_H

typedef struct avl_tree avl_tree;

struct avl_tree {
    int key;
    int data; // TODO change later to void*
    int size;
    int height;
    int depth;
    avl_tree *parent;
    avl_tree *left;
    avl_tree *right;
};

avl_tree *create_binary_tree(int key, int data, int size, int height, int depth, avl_tree *parent, avl_tree *left_tree,
                             avl_tree *right_tree);

avl_tree *insert(avl_tree *parent_tree, avl_tree *tree);

avl_tree *add(avl_tree *parent_tree, int key, int data);


void deallocate(avl_tree *node);

avl_tree *transplant(avl_tree *root, avl_tree *u, avl_tree *v);

avl_tree *delete(avl_tree *root, avl_tree *node);

avl_tree *remove_node(avl_tree *tree, int key);


avl_tree *search(avl_tree *tree, int key);

avl_tree *iterative_search(avl_tree *tree, int key);

avl_tree *min(avl_tree *tree);

avl_tree *max(avl_tree *tree);

avl_tree *predecessor(avl_tree *tree);

avl_tree *successor(avl_tree *tree);

int size(avl_tree *tree);

avl_tree *update_size(avl_tree *tree);

int height(avl_tree *tree);

avl_tree *update_height(avl_tree *tree);

int depth(avl_tree *tree);


avl_tree *left_rotate(avl_tree *tree, avl_tree *x);

avl_tree *right_rotate(avl_tree *tree, avl_tree *x);

int is_balanced(avl_tree *tree, avl_tree *node);

avl_tree *rebalance(avl_tree *tree, avl_tree *node);


void print_pre_order(avl_tree *tree);

void print_pre_order_with_parentheses(avl_tree *tree);

void print_in_order(avl_tree *tree);

void print_post_order(avl_tree *tree);

int is_empty(avl_tree *tree);

#endif //AVL_TREE_AVL_TREE_H
