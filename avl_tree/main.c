#include <stdio.h>
#include "avl_tree.h"

void insercao_avl();

int main() {
    insercao_avl();
    return 0;
}

void insercao_avl() {
    int x;

    avl_tree *t = NULL;

    while (scanf("%d", &x) != EOF) {
        printf("----\nAdicionando %d\n", x);
        t = add(t, x, x);
    }
    printf("----");
}