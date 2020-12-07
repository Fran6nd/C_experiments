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
        int * b;
        DICT_GET(ls, *k, b);
        printf("%s <=> %d\n", *k, *b);
    }
    PRINT_DELIMITER();
    DICT_POP(ls, "sdf");
    DICT_POP(ls, "sd");
    DICT_POP(ls, "sdfg");
    DICT_FOREACH(ls, k){
        int * b;
        DICT_GET(ls, *k, b);
        printf("%s <=> %d\n", *k, *b);
    }
    DICT_POP(ls, "sdfgf");
    PRINT_DELIMITER();
    DICT_FOREACH(ls, k){
        int * b;
        DICT_GET(ls, *k, b);
        printf("%s <=> %d\n", *k, *b);
    }
    DICT_FREE(ls);
    return 0;
}