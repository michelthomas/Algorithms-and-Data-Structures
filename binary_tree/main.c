#include <stdio.h>
#include <math.h>

#include "binary_tree.h"

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


int main() {

    somando_arvores();

    return 0;
}

void profundidade_no() {
    char str[1000];
    scanf("%[^\n]", str);

    int n = 0;
    scanf("%d", &n);

    b_tree *t = create_binary_tree_from_string(str);

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

    b_tree *t = create_binary_tree_from_string(str);

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

                if (values_per_level[i][j] > max) {
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

int max(int x, int y) {
    return x > y ? x : y;
}

int p1(b_tree *t) {

    if (is_leaf(t)) {
        return t->key;
    }

    return max(t->key * p1(t->left), t->key * p1(t->right));
}

void p1_da_arvore() {
    int h;
    scanf("%d", &h);

    int qtd_node = (int) pow(2, h) - 1;

    int arr[qtd_node];

    for (int i = 0; i < qtd_node; ++i) {
        scanf("%d", &arr[i]);
    }

    b_tree *t = create_binary_tree_from_arr(arr, qtd_node);

    printf("%d", p1(t));

}

int _contem_soma(b_tree *t, int soma_atual, int soma) {

    if (is_empty(t)) {
        return 0;
    }

    if (is_leaf(t)) {

        if (t->key + soma_atual == soma) {
            return 1;
        }

        return 0;
    }

    if (_contem_soma(t->left, t->key + soma_atual, soma)) {
        return 1;
    }

    return _contem_soma(t->right, t->key + soma_atual, soma);
}

int contem_soma(b_tree *t, int soma) {

    if (is_empty(t)) {
        return 0;
    }

    return _contem_soma(t, 0, soma);
}

void get_string(char *str) {

    char c;

    int i = 0;
    int qtd_parenteses = 0;

    do {
        scanf("%c", &c);

        if (c != ' ' && c != '\n') {
            str[i] = c;
            i++;

            if (c == ')') {
                qtd_parenteses--;
            } else if (c == '(') {
                qtd_parenteses++;
            }
        }
    } while (qtd_parenteses);

    str[i] = '\0';
}

void somando_arvores() {
    int soma = 0;
    char str[10000];

    scanf("%d ", &soma);

    while (soma != -1000) {

        get_string(str);

        //printf("%s\n---\n", str);

        b_tree *t = create_binary_tree_from_string(str);

        //print_pre_order_with_parentheses(t);

        if (contem_soma(t, soma)) {
            printf("sim\n");
        } else {
            printf("nao\n");
        }

        scanf("%d ", &soma);
    }
}