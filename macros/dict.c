//#!/usr/local/bin/tcc -run
#include "dict.h"


#define PRINT_DELIMITER() printf("-------------\n");

int main()
{
    DICT_NEW(ls, int);
    DICT_ADD(ls,"sdf", 1);
    DICT_ADD(ls,"sdf", 1);
    printf("%d\n", ls.index.size);
    return 0;
}