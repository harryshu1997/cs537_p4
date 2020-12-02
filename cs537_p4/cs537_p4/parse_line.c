//
//  parse_line.c
//  cs537_p4
//
//  Created by HarryMac on 2020/11/27.
//

#include "parse_line.h"

int setBinaryOption(int* const flag){
    if(optarg != NULL && strcmp(optarg, "-") == 0){
        *flag = 0;
    }
    else if(optarg == NULL){
        *flag = 1;
    }
    else{
        return 1;
    }
    return 0;
}


int parseOption(const int argc, char* argv[], OptionFlags* const optionFlags){
    const char* const optStr = "p:m:";
    int opt;
    int argFlag = 0;
    opterr = 0;
    while((opt=getopt(argc, argv, optStr)) != -1){
        switch(opt){
            case 'p':
                break;
          
            case 'm':
                break;
        }
       
        if(argFlag != 0) {
            printf("Invalid argument for option -%s\n", optarg);
            return 1;
        }
    }
    return 0;
}
