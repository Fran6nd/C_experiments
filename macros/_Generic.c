#!/usr/local/bin/tcc -run
#include <stdio.h>

/* This macro generate a different code if x is double, int... */
#define PRINT(x) _Generic((x), double: printf("double -> %f\n", x), \
                              default: printf("Unsupported type.\n"), \
                              int: printf("int -> %d\n", x), \
                              char *: printf("string -> %s\n", x))

struct a{
    int null;
};
struct b{
    int null;
};

/* This macro can check is a struct as an attribute null == 1, whatever the struct. */
#define IS_NULL(x) x.null == 1

int main()
{
    int a = 1;
    PRINT(a);
    PRINT("gogo");
    PRINT((char)'A');
    struct a A = {1};
    struct b B = {0};
    PRINT(IS_NULL(A));
    PRINT(IS_NULL(B));

    return 0;
}