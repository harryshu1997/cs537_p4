//
//  schduler_clock.h
//  cs537_p4
//
//  Created by HarryMac on 2020/12/2.
//

#ifndef schduler_clock_h
#define schduler_clock_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


//extern long frameSize;

//extern unsigned long* pageframe; //circular page frame for clock algorithm (should like a circular double array)

typedef struct pageframe{
    struct page** pages;
    int cur;
    int numItem;
}pageframe;


typedef struct page{
    int stateBit;
    unsigned long pageNum;
}page;

struct pageframe* Creat_frame(void);
int clock_getNumItem(struct pageframe* frame);
int clock_getcur(struct pageframe* frame);
struct page* clock_insert(struct pageframe* frame, unsigned long data);
void clock_destory(struct pageframe* frame);

#endif /* schduler_clock_h */
