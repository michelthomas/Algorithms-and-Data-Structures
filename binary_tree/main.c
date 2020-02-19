#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "binary_tree.h"
#include "doubly_linked_list.h"

// Árvore de Busca Binária - Huxley p.546
void arv_busc_b();


// Profundidade de um nó em uma árvore binária - Huxley p.547
void profundidade_no();


// Em cada nível da árvore - Huxley p.949
void nivel_arvore();

b_tree *construct_tree(int tree_m[][3], int i);

void get_levels(int n, b_tree *tree, int tree_matrix[][3], int values[][n], int level, int index_column[n]);


// Ache o P1 dessa árvore - Huxley p.150
void p1_da_arvore();


// Somando Árvores - Huxley p.596
void somando_arvores();

int contem_soma(b_tree *t, int soma);


void different_tree();

void difefrent_tree_2();


int main() {

    different_tree();

    return 0;
}


b_tree *create_huffman_tree(node *pq) {

    b_tree *l = NULL;
    b_tree *r = NULL;

    while (!is_empty_list(pq->next)) {

/*
        if (pq->data == NULL) {
            l = create_binary_tree(pq->valor, 0, pq->key, NULL, NULL, 0);
        } else {
            l = create_binary_tree('*', 0, pq->key, NULL, NULL, 0);
        }*/

        l = pq->tree;
        pq = pq->next;

        /*if (pq->data == NULL) {
            r = create_binary_tree(pq->valor, 0, pq->key, NULL, NULL, 0);
        } else {
            r = create_binary_tree('*', 0, pq->key, NULL, NULL, 0);
        }
        */
        r = pq->tree;
        pq = pq->next;

        printf("\nl: %c --- r: %c\n", l->key, r->key);

        b_tree *parent_tree = create_binary_tree('*', l->freq + r->freq, 0, l, r);

        printf("parent: %d %c %c\n", parent_tree->freq, parent_tree->left->key, parent_tree->right->key);
        pq = add_ordered_internal_node(pq, parent_tree);

        print_linked_list(pq);
        printf("\n\n");
    }


    b_tree *t = pq->tree;

    return t;
}

void map_paths(b_tree *tree, char fake_hash[][500], char *path, int i) {

    if (!is_empty(tree))
    {
        if (is_leaf(tree))
        {
            path[i] = '\0';

            char *finish_path = (char *) malloc(sizeof(char) * (strlen(path) + 1));

            strcpy(finish_path, path);

            strcpy(fake_hash[tree->key], finish_path);
        }
        else
        {
            if (!is_empty(tree->left))
            {
                path[i] = '0';
                map_paths(tree->left, fake_hash, path, i + 1);
            }

            if (!is_empty(tree->right))
            {
                path[i] = '1';
                map_paths(tree->right, fake_hash, path, i + 1);
            }
        }
    }

}

void different_tree() {

    char str[257];

    scanf("%[^\n]", str);

    int freq[256];

    int i;

    for (i = 0; i < 256; ++i) {
        freq[i] = 0;
    }
    for (i = 0; i < strlen(str); ++i) {
        freq[(int) str[i]]++;
    }


    int qtd_char = 0;
    for (int j = 0; j < 256; ++j) {
        if (freq[j]) {
            qtd_char++;
            printf("%c: %d\n", j, freq[j]);
        }
    }

    printf("\nqtdchar: %d\n", qtd_char);

    node *pq = create_linked_list();

    b_tree *aux = NULL;
    for (i = 0; i < strlen(str); ++i) {
        aux = create_binary_tree((int) str[i], freq[(int) str[i]], 0,NULL, NULL);

//        printf("aux: %c %d\n\n", aux->key, aux->freq);
        pq = add_ordered_huff_tree(pq, aux);
        printf("\n");
        print_linked_list(pq);
        printf("\n");
    }

    print_linked_list(pq);

    b_tree *t = create_huffman_tree(pq);

    char fake_hash[256][500];
    char path[500];

    map_paths(t, fake_hash, path, 0);




    printf("Tree\t-\t");
    print_in_order(t);
    for (i = 0; i < 256; ++i) {
        if (freq[i]) {
            printf("\n%c\t-\t%s", i, fake_hash[i]);
        }
    }


}


void print_post_order(b_tree *tree) {

}
/*
b_tree *get_tree(char str[], int inStrt, int inEnd,  int *p_index) {
    // Base case
    if (inStrt > inEnd)
        return NULL;

    /* Pick current node from Postorder traversal using
       postIndex and decrement postIndex */
    b_tree* node = create_binary_tree(str[*p_index]);
    (*p_index)--;

    /* If this node has no children then return */
    if (inStrt == inEnd)
        return node;

    /* Else find the index of this node in Inorder
       traversal */
    int iIndex = search(in, inStrt, inEnd, node->data);

    /* Using index in Inorder traversal, construct left and
       right subtress */
    node->right = get_tree(str, iIndex + 1, inEnd, p_index);
    node->left = get_tree(post, inStrt, iIndex - 1, p_index);

    return node;
} */
b_tree *get_tree_post_order(b_tree *t, char str, int n) {

    if (n < 0) {
        return t;
    }

    if (str[n] == '*') {

        t->left = create_binary_tree(str[n ])

    }

    b_tree *l, *r;

    l->left = get_tree_post_order(t, str, n - 1);
    r->right = get_tree_post_order(t, str, n - 1);

    return t;

}
void difefrent_tree_2() {

    char str[500];
    scanf("%s", str);

    //get_tree_post_order(str, n)

}