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
    } name;                         \
    name.index.size = 0;            \
    name.index.list = NULL;         \
    name.index.free = free;         \
    name.data.size = 0;             \
    name.data.list = NULL;          \
    name.data.free = NULL

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
    }
#define DICT_FOREACH(dict, key) \
    LIST_FOREACH(dict.index, key)

#define DICT_GET(dict, key)                       \
    LIST_FOR(dict.index, i)                       \
    {                                             \
        if (strcmp(key, dict.index.list[i]) == 0) \
        {                                         \
        }                                         \
    }                                             \
    printf("Error: key unexisting.\n");           \
    exit(-1);

#endif