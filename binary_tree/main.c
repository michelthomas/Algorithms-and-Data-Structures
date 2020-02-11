#include <stdio.h>

#include "binary_tree.h"

// Árvore de Busca Binária - Huxley p.546
void arv_busc_b();

// Profundidade de um nó em uma árvore binária - Huxley p.547
void profundidade_no();

// Em cada nível da árvore - Huxley p.949
void nivel_arvore();
b_tree *construct_tree(int tree_m[][3], int i);


void get_levels(int n, b_tree *tree, int tree_matrix[][3], int values[][n], int level, int index_column[n]);

int main() {
    nivel_arvore();
    return 0;
}

void profundidade_no() {
    char str[1000];
    scanf("%[^\n]", str);

    int n = 0;
    scanf("%d", &n);

    int i = 0; // TODO change to two functions

    b_tree *t = create_binary_tree_from_string(str, &i);

    /*print_pre_order(t);
    printf("\n");
    print_in_order(t);
    printf("\n");
    print_post_order(t);
    printf("\n");*/

    b_tree *t_n = search(t, n);

    if (is_empty(t_n)) {
        printf("NAO ESTA NA ARVORE\n-1");
    } else {
        printf("ESTA NA ARVORE\n%d", depth(t_n));
    }
}

void arv_busc_b() {
    char str[1000];
    scanf("%[^\n]", str);

    int i = 0; // TODO change to two functions

    b_tree *t = create_binary_tree_from_string(str, &i);

    /*print_pre_order(t);
    printf("\n");
    print_in_order(t);
    printf("\n");
    print_post_order(t);
    printf("\n");*/

    if (is_binary_search_tree(t)) {
        printf("VERDADEIRO");
    } else {
        printf("FALSO");
    }
}

void nivel_arvore() {
    int n = 0;
    scanf("%d", &n);

    if (n > 0) {
        int tree_matrix[6][3];
        int i, j;

        for (i = 0; i < 6; ++i) {
            scanf("%d", &tree_matrix[i][0]);
            scanf("%d", &tree_matrix[i][1]);
            scanf("%d", &tree_matrix[i][2]);
        }

        b_tree *t = NULL;

        t = construct_tree(tree_matrix, 0);
        /*print_pre_order(t);
        printf("\n");*/

        // (n / 2) + 1 = max nodes of last level
        int values_per_level[n][n];

        int levels, index_n;

        int indexes_column[n];

        for (i = 0; i < n; ++i) {
            indexes_column[i] = -1;
            for (j = 0; j < n; ++j) {
                values_per_level[i][j] = -1;
            }
        }


        get_levels(n, t, tree_matrix, values_per_level, 0, indexes_column);

        /*for (i = 0; i < n; ++i) {
            printf("%d ", indexes_column[i]);
        }
        printf("\n");*/

        int max, min;

        for (i = 0; values_per_level[i][0] != -1; ++i) {

            max = min = values_per_level[i][0];

            for (j = 1; j <= indexes_column[i]; ++j) {
                //printf("%d ", values_per_level[i][j]);

                if(values_per_level[i][j] > max) {
                    max = values_per_level[i][j];
                } else if (values_per_level[i][j] < min) {
                    min = values_per_level[i][j];
                }
            }

            printf("Nivel %d: Maior = %d, Menor = %d", i + 1, max, min);

            printf("\n");
        }
    }
}

void get_levels(int n, b_tree *tree, int tree_matrix[][3], int values[][n], int level, int index_column[n]) {
    if (tree != NULL) {
        (index_column[level])++;
        values[level][index_column[level]] = tree->valor;

        level++;

        get_levels(n, tree->left, tree_matrix, values, level, index_column);
        get_levels(n, tree->right, tree_matrix, values, level, index_column);
    }
}

b_tree *construct_tree(int tree_m[][3], int i) {
    if (i == -1) {
        return NULL;
    }

    b_tree *t = create_binary_tree(i, tree_m[i][0], NULL, NULL);

    t->left = construct_tree(tree_m, tree_m[i][1]);
    t->right = construct_tree(tree_m, tree_m[i][2]);

    return t;
}
