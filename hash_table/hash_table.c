//
// Created by MichelT on 10/01/2020.
//

#include <stdio.h>
#include <stdlib.h>

#include "hash_table.h"
#include "linked_list.h"

hash_table* create_hash_table(int address_size) {
    hash_table *ht = (hash_table*) malloc(sizeof(hash_table));

    ht->address_size = address_size;

    for (int i = 0; i < address_size; ++i) {
        ht->table[i] = NULL;
    }

    return ht;
}

int hashing(hash_table *ht, int key) {
    return key % ht->address_size;
}

void put(hash_table *ht, int key, void *data) {
    int h = hashing(ht, key);

    ht->table[h] = add_end(ht->table[h], key, data);

}

void* get(hash_table *ht, int key) {
    int h = hashing(ht, key);

    node *list = ht->table[h];

    while (!is_empty(list)) {
        if (list->key == key) {
            return list->data;
        }
        list = list->next;
    }

    return NULL;
}

void ht_remove(hash_table *ht, int key) {
    int h = hashing(ht, key);

    node *list = ht->table[h];

    remove_node_by_key(list, key);
}

int contains_key(hash_table *ht, int key) {
    int h = hashing(ht, key);

    node *list = ht->table[h];

    while (!is_empty(list)) {
        if (list->key == key) {
            return 1;
        }
        list = list->next;
    }

    return 0;
}

void print_hash_table(hash_table *ht) {
    for (int i = 0; i < ht->address_size; ++i) {
        printf("%d -> ", i);

        while (!is_empty(ht->table[i])) {
            printf("%d -> ", ht->table[i]->key);
            ht->table[i] = ht->table[i]->next;
        }

        printf("\\\n");
    }
}