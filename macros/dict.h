/* WORK IN PROGRESS, NOT WORKING AT 100% YET! */

#ifndef DICT_H
#define DICT_H

#include "list.h"
#include <string.h>
#include <stdlib.h>

#define DICT_NEW(name, type)        \
    struct name##_DICT              \
    {                               \
        LIST_DEFINE(index, char *); \
        LIST_DEFINE(data, type);    \
        int size;                   \
    } name;                         \
    name.index.size = 0;            \
    name.index.list = NULL;         \
    name.index.free = free;         \
    name.data.size = 0;             \
    name.data.list = NULL;          \
    name.data.free = NULL;          \
    name.size = 0;

#define DICT_ADD(dict, key, elem)                                    \
    {                                                                \
        char *key_malloc = malloc((strlen(key) + 1) * sizeof(char)); \
        strcpy(key_malloc, key);                                     \
        LIST_FOREACH(dict.index, key1)                               \
        {                                                            \
            if (strcmp(key_malloc, *key1) == 0)                      \
            {                                                        \
                printf("Error: key already existing.\n");            \
                exit(-1);                                            \
            }                                                        \
        }                                                            \
        LIST_ADD(dict.index, key_malloc);                            \
        LIST_ADD(dict.data, elem);                                   \
        dict.size++;                                                 \
    }

#define DICT_FOREACH(dict, key) \
    LIST_FOREACH(dict.index, key)

#define DICT_GET(dict, key, dest_ptr)                      \
    dest_ptr = NULL;                                       \
    LIST_FOR(dict.index, i_dict_get)                       \
    {                                                      \
        if (strcmp(key, dict.index.list[i_dict_get]) == 0) \
        {                                                  \
            dest_ptr = &dict.data.list[i_dict_get];        \
        }                                                  \
    }

#define DICT_POP(dict, key)                                    \
    {                                                          \
        LIST_FOR(dict.index, i_dict_pop)                       \
        {                                                      \
            if (strcmp(key, dict.index.list[i_dict_pop]) == 0) \
            {                                                  \
                LIST_POP_INDEX(dict.index, i_dict_pop);        \
                LIST_POP_INDEX(dict.data, i_dict_pop);         \
                dict.size--;                                   \
                break;                                         \
            }                                                  \
        }                                                      \
    }

#define DICT_FREE(dict)    \
    LIST_FREE(dict.index); \
    LIST_FREE(dict.data);  \
    dict.size = 0;

#endif