//
// Created by MichelT on 11/12/2019.
//

#ifndef BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H

typedef struct binary_search_tree bs_tree;

struct binary_search_tree {
    int key;
    int data; // TODO change later to void*
    int size;
    int height;
    int depth;
    bs_tree *parent;
    bs_tree *left;
    bs_tree *right;
};

bs_tree *create_binary_search_tree(int key, int data, int size, int height, int depth, bs_tree *parent, bs_tree *left_tree,
                                   bs_tree *right_tree);
bs_tree *create_binary_tree(int item, bs_tree *left, bs_tree *right);
bs_tree* insert(bs_tree *parent_tree, bs_tree* tree);
bs_tree *add(bs_tree *parent_tree, int key, int data);

void deallocate(bs_tree *node);
bs_tree *transplant(bs_tree *root, bs_tree *u, bs_tree *v);
bs_tree *delete(bs_tree *root, bs_tree* node);
bs_tree* remove_node(bs_tree *tree, int key);

bs_tree* search(bs_tree *tree, int key);
bs_tree* iterative_search(bs_tree *tree, int key);
bs_tree* min(bs_tree *tree);
bs_tree* max(bs_tree *tree);
bs_tree* predecessor(bs_tree *tree);
bs_tree* successor(bs_tree *tree);
int size(bs_tree *tree);
bs_tree* update_size(bs_tree *tree);
int height(bs_tree *tree);
bs_tree* update_height(bs_tree *tree);
int depth(bs_tree *tree);

void print_pre_order(bs_tree *tree);
void print_in_order(bs_tree *tree);
void print_post_order(bs_tree *tree);
int is_empty(bs_tree *tree);
int is_complete(bs_tree *tree);
int get_number_of_one_children_tree(bs_tree *tree);
bs_tree* get_parents_with_one_child(bs_tree *tree, bs_tree *parents_of_one_child_tree);
int is_leaf(bs_tree *tree);
int get_number_of_leafs(bs_tree *tree);


bs_tree* generate_bs_tree(char *string, int *cont);


#endif //BINARY_SEARCH_TREE_BINARY_SEARCH_TREE_H
