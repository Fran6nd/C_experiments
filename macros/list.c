#!/usr/local/bin/tcc -run
#include "list.h"


#define PRINT_DELIMITER() printf("-------------\n");

LIST_DEFINE(int, maliste);

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
    return 0;
}