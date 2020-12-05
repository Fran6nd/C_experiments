#!/usr/local/bin/tcc -run
#include <stdio.h>
#include <stdlib.h>

#define LIST_DEFINE(TYPE, name) \
    typedef struct                 \
    {                           \
        int size;               \
        TYPE *list;             \
    } name

#define LIST_INIT(name) \
    {                  \
        .size = 0,     \
        .list = NULL,  \
    }
#define LIST_NEW(name, l) \
    l = malloc(sizeof(name));\
    l->size = 0; \
    l->list = NULL
    
#define LIST_ADD(list, element) \


LIST_DEFINE(int, maliste);

int main()
{
    maliste * ml;
    LIST_NEW(maliste, ml);
    return 0;
}