#include <stdio.h>
#include <stdlib.h>
#include "binary_search_tree.h"

void teste();

// Inserção em Árvores de Busca Binária - Huxley p.783
void insercao();

int main() {
    insercao();
    return 0;
}

void teste() {
    bs_tree *my_bt = NULL;

    char string[100];
    int cont = 0;

    scanf("%[^\n]s", string);

    my_bt = generate_bs_tree(string, &cont);

    print_in_order(my_bt);

    int is_complete_bt = is_complete(my_bt);
    printf("\n%s\n", is_complete_bt ? "completa" : "nao completa");

    if (is_complete_bt) {
        printf("total de nos: %d", size(my_bt));
    } else {
        printf("nos com um filho: ");
        print_in_order(get_parents_with_one_child(my_bt, NULL));
    }
}

void insercao() {
    int n;

    bs_tree *t = create_empty_binary_tree();

    printf("----\n");
    while (scanf(" %d", &n) != EOF) {

        t = add(t, n, n);

        printf("Adicionando %d\n", n);
        printf("   ");
        print_pre_order_with_parentheses(t);
        printf("\n----\n");
    }
}
