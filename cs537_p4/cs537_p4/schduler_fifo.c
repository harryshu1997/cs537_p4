//
//  schduler_fifo.c
//  cs537_p4
//
//  Created by HarryMac on 2020/12/2.
//

#include "schduler_fifo.h"
#define MAX 6

struct queue* fifo_Queue(void){
    struct queue* pt = NULL;
    pt = (struct queue*)malloc(sizeof(struct queue));
    pt->front = 0;
    pt->intArray = (unsigned long*)malloc(MAX*sizeof(unsigned long));
    pt->rear = -1;
    pt->itemCount = 0;
    return pt;
}

unsigned long fifo_peek(struct queue* q) {
   return q->intArray[q->front];
}

bool fifo_isEmpty(struct queue* q) {
   return q->itemCount == 0;
}

bool fifo_isFull(struct queue* q) {
   return q->itemCount == MAX;
}

int fifo_size(struct queue* q) {
   return q->itemCount;
}

void fifo_insert(struct queue* q, unsigned long data) {
    for(int i=0;i<q->itemCount;i++){
        if(q->intArray[(q->front+i)%MAX] == data){
            return;
        }
    }
   if(!fifo_isFull(q)) {
      if(q->rear == MAX-1) {
         q->rear = -1;
      }
      q->intArray[++q->rear] = data;
      q->itemCount++;
   }
}

unsigned long fifo_removeData(struct queue* q) {
   unsigned long data = q->intArray[q->front++];
    
   if(q->front == MAX) {
      q->front = 0;
   }
    
   q->itemCount--;
    if(q->itemCount < 0){
        return 0;
    }
   return data;
}

void fifo_destory(struct queue* q){
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
