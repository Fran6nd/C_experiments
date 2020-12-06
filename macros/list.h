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

#define LIST_DEFINE(name, type) \
    struct name##_LIST          \
    {                           \
        int size;               \
        type *list;             \
        int (*free)(type);      \
    } name

#define LIST_NEW(name, type) \
    LIST_DEFINE(name, type); \
    name.size = 0;           \
    name.list = NULL;        \
    name.free = NULL

#define LIST_ADD(l, element)                                                \
    l.size += 1;                                                            \
    if (l.size == 1)                                                        \
    {                                                                       \
        l.list = malloc(sizeof(element));                                   \
    }                                                                       \
    else                                                                    \
    {                                                                       \
        l.list = (typeof(l.list))realloc(l.list, sizeof(element) * l.size); \
    }                                                                       \
    l.list[l.size - 1] = element;

#define LIST_FOREACH(l, elem) \
    for (typeof(l.list) elem = l.list; elem < l.list + l.size; elem++)

#define LIST_FREE(l)              \
    LIST_COUNT--;                 \
    if (l.size != 0)              \
    {                             \
        if (l.free != NULL)       \
        {                         \
            LIST_FOREACH(l, elem) \
            {                     \
                l.free(*elem);    \
            }                     \
        }                         \
        free(l.list);             \
    }                             \
    l.size = 0;

#define LIST_FOR(l, index) \
    for (int index = 0; index < l.size; index++)

#define LIST_POP_INDEX(l, index)                                              \
    if (l.free != NULL)                                                       \
    {                                                                         \
        l.free(l.list[index]);                                                \
    }                                                                         \
    for (int i_pop = index; i_pop < l.size - 1; i_pop++)                      \
    {                                                                         \
        l.list[i_pop] = l.list[i_pop + 1];                                    \
    }                                                                         \
    l.size--;                                                                 \
    if (l.size > 0)                                                           \
    {                                                                         \
        l.list = (typeof(l.list))realloc(l.list, sizeof(l.list[0]) * l.size); \
    }                                                                         \
    else                                                                      \
    {                                                                         \
        free(l.list);                                                         \
    }

#define LIST_SET_FREE_FUNC(list, func) \
    list.free = func

#endif