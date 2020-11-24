//
//  HashTable.c
//  cs537_p4
//
//  Created by Zhihao Shu/Hanyuan Wu on 2020/11/24.
//

#include "HashTable.h"
#include <stdlib.h>


/*  calculate hash for keys.
    It's based on the DJB algorithm from Daniel J. Bernstein.
    The key must be ended by '\0' character.*/
static unsigned int calc_hash(char* key){
    unsigned int hash = 5381;
        int c;
        while ((c = *key++) != 0)
            hash = ((hash << 5) + hash) + c;
        return hash;
}

/*
 creat hash table with given capacity return a pointer to the table
 */
hash_table* hs_create(unsigned int capacity){
    hash_table* hstable = malloc(capacity * sizeof(hash_elem));
    if(!hstable)return NULL;
    if((hstable->table = malloc(capacity*sizeof(hash_elem*))) == NULL){
        free(hstable->table);
        return NULL;
    }
    hstable->capacity = capacity;
    hstable->numItem = 0;
    for(unsigned int i=0; i<capacity;i++){
        hstable->table[i] = NULL;
    }
    return hstable;
}

/*
 insert the data in the table, if the key already in it, replace the data with the new one and return
 else return NULL
 */
void* hs_insert(hash_table* hstable, char* key, void* data){
    if(data == NULL){
        return NULL;
    }
    unsigned int index = calc_hash(key)%hstable->capacity;
    hash_elem* elem = hstable->table[index];
    
    while(elem != NULL){
        if(!strcmp(elem->key,key)){ //they are equal
            void* temp = elem->data;
            elem->data = data;
            return temp;
        }
        elem = elem->next;
    }
    //if the key does not exist
    if((elem = malloc(sizeof(hash_elem) + strlen(key) + 1)) == NULL){
        printf("memory error");
        return 0;
    }
    strcpy(elem->key,key);
    elem->data = data;
    //add element at the beginning of the list
    elem->next = hstable->table[index];
    hstable->table[index] = elem;
    hstable->numItem++;
    return NULL;
}

/*
 get the data according to key return NULL for success
 */
void* hs_get(hash_table* hstable, char* key){
    unsigned int index = calc_hash(key)%hstable->capacity;
    hash_elem* elem = hstable->table[index];
    while(elem != NULL){
        if(!strcmp(elem->key,key)){
            return elem->data;
        }
        elem = elem->next;
    }
    return NULL;
}

/*
 remove data from the table return the data
 */
void* hs_remove(hash_table* hstable, char* key){
    unsigned int index = calc_hash(key)%hstable->capacity;
    hash_elem* elem = hstable->table[index];
    hash_elem* pre = NULL;
    while(elem != NULL){
        if(!strcmp(elem->key,key)){
            void* temp = elem->data;
            if(pre != NULL){
                pre->next = elem->next;
            }else{
                hstable->table[index] = elem->next;
            }
            free(elem);
            elem=NULL;
            hstable->numItem--;
            return temp;
        }
        pre = elem;
        elem = elem->next;
    }
    return NULL;
}


/*
 iterate through the table
 */
hash_elem* hs_iterate(table_it* it){
    while(it->celem == NULL){
        if(it->index < it->hstable->capacity-1){
            it->index++;
            it->celem = it->hstable->table[it->index];
        }else{
            return NULL;
        }
    }
    hash_elem* elem = it->celem;
    if(elem){
        it->celem = elem->next;
    }
    return elem;
}

/*
 iterate keys
 */
char* it_keys(table_it* it){
    hash_elem* e = hs_iterate(it);
    return (e==NULL ? NULL:e->key);
    
}


/* remove all data and free*/
void hs_clear(hash_table* hstable){
    table_it it = HS_ITERATE(hstable);
    char* key = it_keys(&it);
    while(key!=NULL){
        free(hs_remove(hstable, key));
        key = it_keys(&it);
    }
}

/*
 destory all table
 */
void hs_destroy(hash_table* hstable){
    hs_clear(hstable);
    free(hstable->table);
    free(hstable);
}
