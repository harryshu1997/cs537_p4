//
//  schduler_lru.c
//  cs537_p4
//
//  Created by HarryMac on 2020/12/2.
//

#include "schduler_lru.h"
#define MAX 6

struct lqueue* lru_Queue(void){
    struct lqueue* pt = NULL;
    pt = (struct lqueue*)malloc(sizeof(struct lqueue));
    pt->front = 0;
    pt->intArray = (unsigned long*)malloc(MAX*sizeof(unsigned long));
    pt->rear = -1;
    pt->itemCount = 0;
    return pt;
}

unsigned long lru_peek(struct lqueue* q) {
   return q->intArray[q->front];
}

bool lru_isEmpty(struct lqueue* q) {
   return q->itemCount == 0;
}

bool lru_isFull(struct lqueue* q) {
   return q->itemCount == MAX;
}

int lru_size(struct lqueue* q) {
   return q->itemCount;
}

void lru_insert(struct lqueue* q, unsigned long data) {
    //check if data already exists
    bool isdata = false;
    int count = 0;
    for(int i=0;i<q->itemCount;i++){
        if(q->intArray[(q->front+i)%MAX] == data){
            count = i;
            isdata = true;
        }
    }
    if(isdata){
        int move = q->itemCount - count-1;
        for(int i=0;i<move;i++){
            q->intArray[(q->front+count+i)%MAX] = q->intArray[(q->front+count+i+1)%MAX];
        }
        q->rear--;
        q->itemCount--;
    }
    
   if(!lru_isFull(q)) {
      if(q->rear == MAX-1) {
         q->rear = -1;
      }
      q->intArray[++q->rear] = data;
      q->itemCount++;
   }
}

unsigned long lru_removeData(struct lqueue* q) {
   unsigned long data = q->intArray[q->front++];
    
   if(q->front == MAX) {
      q->front = 0;
   }
    
   q->itemCount--;
   return data;
}

void lru_destroy(struct lqueue* q){
    free(q->intArray);
    free(q);
    q = NULL;
}

//pseudo code for fifo
extern unsigned long page;
//insert into intarray queue
//insert(page);
//get the first entered one
//removeData()
