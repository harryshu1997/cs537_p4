//
//  parse_line.h
//  cs537_p4
//
//  Created by HarryMac on 2020/11/27.
//

#ifndef parse_line_h
#define parse_line_h

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define DEFAULT_P 4096
#define DEFAULT_M 1


typedef struct {
    int fifo;
    int lru;
    int clock;
    unsigned int page;
    unsigned int mem;
}OptionFlags;

int setBinaryOption(int* flag);

int parseOption(int argc, char* argv[], OptionFlags* optionFlags);


#endif /* parse_line_h */
