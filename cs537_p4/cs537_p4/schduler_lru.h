//
//  schduler_lru.h
//  cs537_p4
//
//  Created by HarryMac on 2020/12/2.
//

#ifndef schduler_lru_h
#define schduler_lru_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct lqueue{
    unsigned long *intArray;
    int front;
    int rear;
    int itemCount;
}lru_queue;

struct lqueue* lru_Queue(void); //size is 6

unsigned long lru_peek(struct lqueue* q);
bool lru_isEmpty(struct lqueue* q) ;
bool lru_isFull(struct lqueue* q);
int lru_size(struct lqueue* q);
void lru_insert(struct lqueue* q, unsigned long data);
unsigned long lru_removeData(struct lqueue* q);

#endif /* schduler_lru_h */
