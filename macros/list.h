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

#define LIST_INTERN_VAR(name) LIST_INTERNAL_VARIABLE_##name

#define LIST_DEFINE(name, type) \
    struct name##_LIST          \
    {                           \
        int size;               \
        type *list;             \
        void (*free_elem)(type); \
    } name

#define LIST_NEW(name, type) \
    LIST_DEFINE(name, type); \
    name.size = 0;           \
    name.list = NULL;        \
    name.free_elem = NULL

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

#define LIST_FREE(l)                \
    if (l.size != 0)                \
    {                               \
        if (l.free_elem != NULL)    \
        {                           \
            LIST_FOREACH(l, elem)   \
            {                       \
                l.free_elem(*elem); \
            }                       \
        }                           \
        free(l.list);               \
    }                               \
    l.size = 0;

#define LIST_FOR(l, index) \
    for (int index = 0; index < l.size; index++)

#define LIST_POP_INDEX(l, index)                                                                \
    if (l.free_elem != NULL)                                                                    \
    {                                                                                           \
        l.free_elem(l.list[index]);                                                             \
    }                                                                                           \
    for (int LIST_INTERN_VAR(i) = index; LIST_INTERN_VAR(i) < l.size - 1; LIST_INTERN_VAR(i)++) \
    {                                                                                           \
        l.list[LIST_INTERN_VAR(i)] = l.list[LIST_INTERN_VAR(i) + 1];                            \
    }                                                                                           \
    l.size--;                                                                                   \
    if (l.size > 0)                                                                             \
    {                                                                                           \
        l.list = (typeof(l.list))realloc(l.list, sizeof(l.list[0]) * l.size);                   \
    }                                                                                           \
    else                                                                                        \
    {                                                                                           \
        free(l.list);                                                                           \
    }

#define LIST_SET_FREE_FUNC(list, func) \
    list.free_elem = func

#endif