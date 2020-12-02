//
//  schduler_fifo.h
//  cs537_p4
//
//  Created by HarryMac on 2020/12/2.
//

#ifndef schduler_fifo_h
#define schduler_fifo_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//should include incoming page

typedef struct queue{
    //queue for the schduler
    unsigned long *intArray;
    int front;
    int rear;
    int itemCount;
}fifo_queue;

struct queue* fifo_Queue(void); //size is 6

unsigned long fifo_peek(struct queue* q);
bool fifo_isEmpty(struct queue* q) ;
bool fifo_isFull(struct queue* q);
int fifo_size(struct queue* q);
void fifo_insert(struct queue* q, unsigned long data);
unsigned long fifo_removeData(struct queue* q);
void fifo_destory(struct queue* q);

//whenever a page is referenced 

#endif /* schduler_fifo_h */
