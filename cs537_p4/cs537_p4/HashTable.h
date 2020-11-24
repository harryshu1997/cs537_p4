//
//  HashTable.h
//  cs537_p4
//
//  Created by Zhihao Shu/ Hanyuan Wu on 2020/11/24.
//

#ifndef HashTable_h
#define HashTable_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Capacity 4096

//structure for hashtable element
typedef struct hash_elem{
    struct hash_elem* next;
    void* data;
    char* key;
}hash_elem;


//structure for table
typedef struct {
    unsigned int capacity; //capacity of the table
    unsigned int numItem; //number of element in the table
    hash_elem** table; //pointer to the table
}hash_table;

//structure for iteration
typedef struct {
    hash_table* hstable; //table to be interated
    unsigned int index; //current index
    hash_elem* celem; //current element
}table_it;

//initialize hashtable iterator
#define HS_ITERATE(t) {t,0,t->table[0]}

static unsigned int calc_hash(char* key);
hash_table* hs_create(unsigned int capacity);
void* hs_insert(hash_table* hstable, char* key, void* data);
void* hs_get(hash_table* hstable, char* key);
void* hs_remove(hash_table* hstable, char* key);
hash_elem* hs_iterate(table_it* it);
char* it_keys(table_it* it);
void hs_clear(hash_table* hstable);
void hs_destroy(hash_table* hstable);

#endif /* HashTable_h */
