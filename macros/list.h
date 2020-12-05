/*
 *
 * list.h is a single header library intended to help
 * to deal with dynamic lists in C. It will work for
 * some common needs but is still work in progress.
 * 
 * You can easily build a list of anything and then add elements,
 * pop them or free the list.
 *
 */

#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

 /* How many lists are active and need to be freed. */
int LIST_COUNT = 0;

/* 
 * Generate the header of the list.
 *
 * type: the type of stored elements.
 * name: the name of the declared struct.
 */

#define LIST_DEFINE(type, name) \
    typedef struct              \
    {                           \
        int size;               \
        int elm_size;           \
        type *list;             \
        int (*free)(type);      \
    } name

/*
 * Create a new instance of a list.
 *
 * name: the name of the struct to intantiate (given at the LIST_DEFINE).
 * l: the  pointer of the list (type: name*).
 */

#define LIST_NEW(name, l)     \
    LIST_COUNT++;             \
    l = malloc(sizeof(name)); \
    l->size = 0;              \
    l->list = NULL;           \
    l->free = NULL

#define LIST_ADD(l, element)                                                    \
    l->size += 1;                                                               \
    if (l->size == 1)                                                           \
    {                                                                           \
        l->list = malloc(sizeof(element));                                      \
    }                                                                           \
    else                                                                        \
    {                                                                           \
        l->list = (typeof(l->list))realloc(l->list, sizeof(element) * l->size); \
    }                                                                           \
    l->list[l->size - 1] = element;                                             \
    l->size - 1

#define LIST_FOREACH(l, elem) \
    for (typeof(l->list) elem = l->list; elem < l->list + l->size; elem++)

#define LIST_FREE(l)              \
    LIST_COUNT--;                 \
    if (l->size != 0)             \
    {                             \
        if (l->free != NULL)      \
        {                         \
            LIST_FOREACH(l, elem) \
            {                     \
                l->free(elem);    \
            }                     \
        }                         \
        free(l->list);            \
    }                             \
    l->size = 0;                  \
    free(l)

#define LIST_FOR(l, index) \
    for (int index = 0; index < l->size; index++)

#define LIST_POP_INDEX(l, index)                                                   \
    if (l->free != NULL)                                                           \
    {                                                                              \
        l->free(l->list[index]);                                                   \
    }                                                                              \
    for (int i = index; i < l->size - 1; i++)                                      \
    {                                                                              \
        l->list[i] = l->list[i + 1];                                               \
    }                                                                              \
    l->size--;                                                                     \
    if (l->size > 0)                                                               \
    {                                                                              \
        l->list = (typeof(l->list))realloc(l->list, sizeof(l->list[0]) * l->size); \
    }                                                                              \
    else                                                                           \
    {                                                                              \
        free(l->list);                                                             \
    }

#define LIST_SET_FREE_FUNC(list, func) \
    list->free = func

#endif