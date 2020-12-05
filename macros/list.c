#!/usr/local/bin/tcc -run
#include <stdio.h>
#include <stdlib.h>

#define LIST_DEFINE(TYPE, name) \
    typedef struct              \
    {                           \
        int size;               \
        int elm_size;           \
        TYPE *list;             \
    } name

#define LIST_NEW(name, l)     \
    l = malloc(sizeof(name)); \
    l->size = 0;              \
    l->list = NULL

#define LIST_ADD(l, element)                                   \
    l->size += 1;                                              \
    if (l->size == 1)                                          \
    {                                                          \
        l->list = malloc(sizeof(element));                     \
    }                                                          \
    else                                                       \
    {                                                          \
        l->list = realloc(l->list, sizeof(element) * l->size); \
    }                                                          \
    l->list[l->size - 1] = element

#define LIST_FREE(l)   \
    if (l->size != 0)  \
    {                  \
        free(l->list); \
    }                  \
    free(l)

LIST_DEFINE(int, maliste);

int main()
{
    maliste *ml;
    LIST_NEW(maliste, ml);
    LIST_ADD(ml, 1);
    LIST_FREE(ml);
    return 0;
}