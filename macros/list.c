#!/usr/local/bin/tcc -run
#include "list.h"

#define PRINT_DELIMITER() printf("-------------\n");

int main()
{
    struct test
    {
        int i;
    } montest = {1};
    LIST_OF(int) ml;
    LIST_INIT(ml);
    LIST_ADD(ml, 1);
    LIST_ADD(ml, 1);
    LIST_ADD(ml, 3);
    LIST_ADD(ml, 1);
    LIST_POP_INDEX(ml, 0);
    LIST_FOREACH(ml, elem)
    {
        printf("%d\n", *elem);
    }
    PRINT_DELIMITER();
    LIST_FREE(ml);

    LIST_OF(char *)
    mls;
    LIST_INIT(mls);
    LIST_SET_FREE_FUNC(mls, free);
    char *s1 = malloc(sizeof(char) * 3);
    char *s2 = malloc(sizeof(char) * 3);
    char *s3 = malloc(sizeof(char) * 3);
    LIST_ADD(mls, s1);
    LIST_ADD(mls, s2);
    LIST_ADD(mls, s3);
    LIST_FOR(mls, i)
    {
        printf("%d\n", i);
    }
    PRINT_DELIMITER();
    LIST_POP_INDEX(mls, 0);
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