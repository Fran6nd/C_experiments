#!/usr/local/bin/tcc -run
#include "dict.h"


#define PRINT_DELIMITER() printf("-------------\n");

int main()
{
    PRINT_DELIMITER()
    DICT_NEW(ls, int);
    DICT_ADD(ls,"sdf", 1);
    DICT_ADD(ls,"sdfg", 1);
    printf("%d\n", ls.index.size);
    DICT_FOREACH(ls, k){
        printf("%s\n", *k);
    }
    PRINT_DELIMITER();
    return 0;
}