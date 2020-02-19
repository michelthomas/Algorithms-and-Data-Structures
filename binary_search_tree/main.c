#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_search_tree.h"

void arvore_bin_completa();

// Inserção em Árvores de Busca Binária - Huxley p.783
void insercao();

// Madd Code
void madd_code();

int main() {
    madd_code();
    return 0;
}

void arvore_bin_completa() {
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

void madd_code() {
    char str_tree[] = {"MGTCKQWAEILORUY BDFHJNPSVXZ"};

    bs_tree *t = NULL;

    int i;


    for (i = 0; i < strlen(str_tree); ++i) {

        t = add(t, str_tree[i], str_tree[i]);

    }

    char str[1000];
    char msg[1000];

    scanf("%[^\n]", str);
    int j = 0;

    bs_tree *aux = t;

    for (i = 0; i < strlen(str); ++i) {
        switch (str[i]) {
            case '@':
                msg[j] = (char) t->key;
                j++;
                i++;
                break;
            case '*':
                msg[j] = (char) aux->key;
                j++;
                aux = t;
                break;
            case '-':
                aux = aux->left;
                break;
            case '|':
                aux = aux->right;
                break;
            default:
                printf("Erro!!");
        }
    }

    msg[j] = '\0';

    printf("\n%s", msg);


    //print_in_order(t);
}
