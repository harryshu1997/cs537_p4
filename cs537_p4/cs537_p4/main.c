//
//  main.c
//  cs537_p4
//
//  Created by Zhihao Shu/Hanyuan Wu on 2020/11/24.
//

#include <stdio.h>
#include "uthash.h"
#include "schedules.h"

struct my_struct {
    unsigned long key;            /* we'll use this field as the key */
    unsigned long value;
    UT_hash_handle hh; /* makes this structure hashable */
};

struct my_struct *users = NULL;

void add_user(struct my_struct *s) {
    HASH_ADD_INT( users, key, s );
}

struct my_struct *find_user(unsigned long user_id) {
    struct my_struct *s;
    HASH_FIND_INT(users, &user_id, s );
    return s;
}

void delete_user(struct my_struct *user) {
    HASH_DEL( users, user);
}


int main(int argc, const char * argv[]) {
    //testing for hash table checked!
//    struct my_struct *s;
//    s = malloc(sizeof(struct my_struct));
//    s->key = 1234534534636;
//    s->value= 213424;
//    add_user(s);
//    printf("%lu",s->key);
//    printf("\n");
//    printf("%lu\n",s->value);
//    struct my_struct *s1 = find_user(1234534534636);
//    printf("%lu",s1->value);
    
    /* whenever reference a page insert it into the queue
     it does not allow duplicate pages
     removeData render the first entered page that should be discarded
     */
    printf("\n");
    printf("fifo testing\n");
    struct queue* fifo;
    fifo = fifo_Queue();
    //fifo_insert(fifo, 122314);
    //fifo_insert(fifo, 122314);
    fifo_insert(fifo, 34324535);
    fifo_insert(fifo, 1223);
    fifo_insert(fifo, 1223321314);
    fifo_insert(fifo, 1223143123);
    fifo_insert(fifo, 1223142131);
    fifo_insert(fifo, 1343423);
    fifo_insert(fifo, 122234243);
    fifo_insert(fifo, 12235756);
    
    printf("show size: %d\n", fifo_size(fifo));
    printf("show last: %lu\n",fifo_removeData(fifo));
    printf("show last: %lu\n",fifo_removeData(fifo));
    printf("show last: %lu\n",fifo_removeData(fifo));
    printf("show last: %lu\n",fifo_removeData(fifo));
    printf("show last: %lu\n",fifo_removeData(fifo));
    printf("show last: %lu\n",fifo_removeData(fifo));
    printf("show last: %lu\n",fifo_removeData(fifo));
    printf("show last: %lu\n",fifo_removeData(fifo));
    printf("show size: %d\n", fifo_size(fifo));
    
    /* whenever reference a page insert it into the queue
     if the page already in the queue move it to the front of the queue
     removeData render the least recently used page
     */
    printf("\n");
    printf("lru testing\n");
    struct lqueue* lru;
    lru = lru_Queue();
    lru_insert(lru, 1);
    lru_insert(lru, 2);
    lru_insert(lru, 3);
    lru_insert(lru, 4);
    lru_insert(lru, 5);
    lru_insert(lru, 3);
    lru_insert(lru, 1);
    lru_insert(lru, 2);
    lru_insert(lru, 3);
    printf("show size: %d\n", lru_size(lru));
    printf("show last: %lu\n",lru_removeData(lru));
    
    
    printf("\n");
    printf("clock testing\n");
    struct pageframe* clock;
    clock = Creat_frame();
    clock_insert(clock, 1);
    clock_insert(clock, 2);
    clock_insert(clock, 3);
    clock_insert(clock, 4);
    clock_insert(clock, 5);
    clock_insert(clock, 6);
    clock_insert(clock, 7);
    clock_insert(clock, 8);
    printf("kick out: %lu\n", clock_insert(clock, 1)->pageNum);
    printf("kick out: %lu\n", clock_insert(clock, 2)->pageNum);
    printf("kick out: %lu\n", clock_insert(clock, 3)->pageNum);
    printf("kick out: %lu\n", clock_insert(clock, 4)->pageNum);
    printf("kick out: %lu\n", clock_insert(clock, 2)->pageNum);
    printf("kick out: %lu\n", clock_insert(clock, 7)->pageNum);
    
    
    return 0;
}
