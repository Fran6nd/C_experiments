#!/usr/local/bin/tcc -run
#include "list.h"


#define PRINT_DELIMITER() printf("-------------\n");

LIST_DEFINE(int, maliste);
LIST_DEFINE(char *, maliste_string);

int main()
{
    maliste *ml;
    LIST_NEW(maliste, ml);
    LIST_ADD(ml, 1);
    LIST_ADD(ml, 1);
    LIST_ADD(ml, 3);
    LIST_ADD(ml, 1);
    LIST_FOREACH(ml, elem)
    {
        printf("%d\n", *elem);
    }
    PRINT_DELIMITER();
    LIST_FREE(ml);
    LIST_NEW(maliste, ml);
    LIST_ADD(ml, 1);
    LIST_ADD(ml, 4);
    LIST_ADD(ml, 3);
    LIST_ADD(ml, 13);
    LIST_FOR(ml, i)
    {
        printf("%d\n", ml->list[i]);
    }
    PRINT_DELIMITER()
    LIST_POP_INDEX(ml, 1);
    LIST_FOREACH(ml, elem)
    {
        printf("%d\n", *elem);
    }
    PRINT_DELIMITER()
    LIST_FREE(ml);
    LIST_NEW(maliste, ml);
    LIST_ADD(ml, 1);
    LIST_POP_INDEX(ml, 0);
    LIST_ADD(ml, 2);
    LIST_FOR(ml, i)
    {
        printf("%d\n", ml->list[i]);
    }
    PRINT_DELIMITER();
    LIST_FREE(ml);
    printf("%d\n", LIST_COUNT);
    PRINT_DELIMITER();
    maliste_string * mls;
    LIST_NEW(maliste_string, mls);
    LIST_SET_FREE_FUNC(mls, free);
    char * s1 = malloc(sizeof(char) * 3);
    char * s2 = malloc(sizeof(char) * 3);
    char * s3 = malloc(sizeof(char) * 3);
    LIST_ADD(mls, s1);
    LIST_ADD(mls, s2);
    LIST_ADD(mls, s3);
    LIST_FOR(mls, i)
    {
        printf("%d\n", i);
    }
    PRINT_DELIMITER();
    LIST_POP_INDEX(mls, 1);
    LIST_FOR(mls, i)
    {
        printf("%d\n", i);
    }
    LIST_FOREACH(mls, ELEM)
    {
        printf("--\n");
    }
    PRINT_DELIMITER();
    LIST_FREE(mls);

    return 0;
}