#!/usr/local/bin/tcc -run
#include "dict.h"


#define PRINT_DELIMITER() printf("-------------\n");

int main()
{
    PRINT_DELIMITER()
    DICT_NEW(ls, int);
    DICT_ADD(ls,"sdf", 1);
    DICT_ADD(ls,"sdfg", 3);
    DICT_ADD(ls,"sdfgf", 2);
    printf("%d\n", ls.size);
    DICT_FOREACH(ls, k){
        printf("%s\n", *k);
    }
    int a;
    DICT_GET(ls, "sdf", a);
    printf("%d\n", a);
    PRINT_DELIMITER();
    return 0;
}