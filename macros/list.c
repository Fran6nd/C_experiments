#!/ usr / local / bin / tcc - run
#include <stdio.h>

#define LIST_DEFINE(TYPE, name) \
    struct name                 \
    {                           \
        int size;               \
        TYPE *list;             \
    }

#define LIST_NEW(name) \
    {                  \
        .size = 0,     \
        .list = NULL,  \
    }

LIST_DEFINE(int, maliste);

int main()
{
    struct maliste ml = LIST_NEW(maliste);
    return 0;
}