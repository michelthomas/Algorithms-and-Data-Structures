#include <stdio.h>
#include <string.h>

#include "hash_table.h"

// Array Hash - Huxley p.316
void arr_hash();
int get_alphabetic_value(char c);

// Hash Tables - Huxley p.242
void hash_tables();


int main() {
    hash_tables();
    return 0;
}

void arr_hash() {
    int n;
    scanf("%d", &n);

    int i;
    int l;
    int hash_value;

    char str[50];

    for (i = 0; i < n; i++) {
        scanf("%d", &l);

        hash_value = 0;

        memset(str, '\0', 50);

        for (int j = 0; j < l; ++j) {
            scanf(" %s", str);

            for (int k = 0; k < strlen(str); ++k) {
                hash_value += get_alphabetic_value(str[k]) + j + k;
            }


        }

        printf("%d\n", hash_value);
    }
}
int get_alphabetic_value(char c) {
    return c - 65;
}

void hash_tables() {
    int n, m, c, key;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &m, &c);

        hash_table *ht = create_hash_table(m);

        for (int j = 0; j < c; ++j) {
            scanf("%d", &key);

            put(ht, key, NULL);

        }

        print_hash_table(ht);
        printf("\n");

    }
}