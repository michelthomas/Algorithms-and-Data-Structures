//
// Created by MichelT on 10/01/2020.
//

#ifndef HASH_TABLE_HASH_TABLE_H
#define HASH_TABLE_HASH_TABLE_H

#include "linked_list.h"

#define MAX_ADDRESS 100

typedef struct hash_table{
    int address_size;
    node *table[MAX_ADDRESS];
} hash_table;

hash_table* create_hash_table(int address_size);
void put(hash_table *ht, int key, void *data);
void* get(hash_table *ht, int key);
void ht_remove(hash_table *ht, int key);
int contains_key(hash_table *ht, int key);
void print_hash_table(hash_table *ht);

#endif //HASH_TABLE_HASH_TABLE_H
