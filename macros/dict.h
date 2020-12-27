/* WORK IN PROGRESS, NOT WORKING AT 100% YET! */

#ifndef DICT_H
#define DICT_H

#include "list.h"
#include <string.h>
#include <stdlib.h>

#define DICT_INTERN_VAR(name) DICT_INTERNAL_VARIABLE_##name

static inline void free_str(char *str)
{
    free((void *)str);
}

#define DICT_OF(type)                     \
    struct CAT(LIST_##type_, UNIQUE_ID()) \
    {                                     \
        LIST_OF(char *)                   \
        index;                            \
        LIST_OF(type)                     \
        data;                             \
        int size;                         \
    }

#define DICT_INIT(name)              \
    LIST_INIT(name.index);           \
    LIST_INIT(name.data);            \
    name.index.free_elem = free_str; \
    name.size = 0

#define DICT_ADD(dict, key, elem)                                                         \
    {                                                                                     \
        char *DICT_INTERN_VAR(key_mallocated) = malloc((strlen(key) + 1) * sizeof(char)); \
        strcpy(DICT_INTERN_VAR(key_mallocated), key);                                     \
        LIST_FOREACH(dict.index, key1)                                                    \
        {                                                                                 \
            if (strcmp(DICT_INTERN_VAR(key_mallocated), *key1) == 0)                      \
            {                                                                             \
                printf("Error: key already existing.\n");                                 \
                exit(-1);                                                                 \
            }                                                                             \
        }                                                                                 \
        LIST_ADD(dict.index, DICT_INTERN_VAR(key_mallocated));                            \
        LIST_ADD(dict.data, elem);                                                        \
        dict.size++;                                                                      \
    }

#define DICT_FOREACH(dict, key) \
    LIST_FOREACH(dict.index, key)

#define DICT_GET(dict, key, dest_ptr)                              \
    dest_ptr = NULL;                                               \
    LIST_FOR(dict.index, DICT_INTERN_VAR(i))                       \
    {                                                              \
        if (strcmp(key, dict.index.list[DICT_INTERN_VAR(i)]) == 0) \
        {                                                          \
            dest_ptr = &dict.data.list[DICT_INTERN_VAR(i)];        \
        }                                                          \
    }

#define DICT_POP(dict, key)                                            \
    {                                                                  \
        LIST_FOR(dict.index, DICT_INTERN_VAR(i))                       \
        {                                                              \
            if (strcmp(key, dict.index.list[DICT_INTERN_VAR(i)]) == 0) \
            {                                                          \
                LIST_POP_INDEX(dict.index, DICT_INTERN_VAR(i));        \
                LIST_POP_INDEX(dict.data, DICT_INTERN_VAR(i));         \
                dict.size--;                                           \
                break;                                                 \
            }                                                          \
        }                                                              \
    }

#define DICT_FREE(dict)    \
    LIST_FREE(dict.index); \
    LIST_FREE(dict.data);  \
    dict.size = 0;

#endif