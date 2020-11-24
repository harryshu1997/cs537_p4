//
//  main.c
//  cs537_p4
//
//  Created by Zhihao Shu/Hanyuan Wu on 2020/11/24.
//

#include <stdio.h>
#include "HashTable.h"

int main(int argc, const char * argv[]) {
    //testing
    hash_table* ht = hs_create(1024);
    hs_insert(ht, "a", "1");
    hs_insert(ht, "b", "2");
    hs_insert(ht, "c", "3");
    hs_insert(ht, "d", "4");
    hs_insert(ht, "e", "5");
    hs_get(ht, "e");
    hs_get(ht, "f"); //should error
    hs_remove(ht, "e");
    hs_get(ht, "e"); // should error
    hs_destroy(ht);
    if(ht != NULL){
        printf("error!!");
    }
    
    
    return 0;
}
