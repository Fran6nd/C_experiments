#!/usr/local/bin/tcc -run
#include <stdio.h>
#include <stdlib.h>

#define LIST_DEFINE(TYPE, name) \
    typedef struct              \
    {                           \
        int size;               \
        TYPE *list;             \
    } name

#define LIST_NEW(name, l)     \
    l = malloc(sizeof(name)); \
    l->size = 0;              \
    l->list = NULL

#define LIST_ADD(list, element)

#define LIST_FREE(l) \
    if(l->size != 0)\
    {\
     \
\
    } \
    free(l)

LIST_DEFINE(int, maliste);

int main()
{
    maliste *ml;
    LIST_NEW(maliste, ml);
    LIST_FREE(ml);
    return 0;
}