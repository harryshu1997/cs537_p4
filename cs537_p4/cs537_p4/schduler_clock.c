//
//  schduler_clock.c
//  cs537_p4
//
//  Created by HarryMac on 2020/12/2.
//

#include "schduler_clock.h"
//for testing; set framesize to 6
int frameSize = 6;


struct pageframe* Creat_frame(void){
    struct pageframe* frame = NULL;
    frame = (struct pageframe*)malloc(sizeof(struct pageframe));
    frame->cur = 0;
    frame->pages = (struct page**)malloc(frameSize*sizeof(struct page*));
    for(int i=0;i<frameSize;i++){
        frame->pages[i] = NULL;
    }
    frame->numItem = 0;
    return frame;
}

int clock_getNumItem(struct pageframe* frame){
    return frame->numItem;
}

int clock_getcur(struct pageframe* frame){
    return frame->cur;
}

struct page* clock_insert(struct pageframe* frame, unsigned long data){
   //initialize a new page with state bit
    struct page* newPage = NULL;
    newPage = malloc(sizeof(struct page));
    newPage->stateBit = 1;
    newPage->pageNum = data;
    for(int i=0;i<frame->numItem;i++){
        if(frame->pages[(frame->cur+i)%frameSize]->pageNum == data){
            //duplicate page
            frame->pages[(frame->cur+i)%frameSize]->stateBit = 1;
            return frame->pages[(frame->cur+i)%frameSize];
        }
    }
    if(frame->numItem < frameSize){ //frame is not full
        frame->pages[frame->numItem] = newPage;
        frame->numItem++;
        
        return newPage;
    }
    //if the frame is full run the clock algorithm and kick the least used one out
    while(1){
        if(frame->pages[frame->cur]){
            
        }
        if(frame->pages[frame->cur]->stateBit == 0){
            struct page* temp = frame->pages[frame->cur];
            frame->pages[frame->cur] = newPage;
            frame->numItem++;
            return temp;
        }
        frame->pages[frame->cur]->stateBit = 0;
        frame->cur++;
        frame->cur %= frameSize;
    }
}

void clock_destory(struct pageframe* frame){
    struct page** pages = frame->pages;
    for(int i=0;i<frame->numItem;i++){
        free(pages[i]);
    }
    free(pages);
    pages=NULL;
    free(frame);
    frame=NULL;
}
