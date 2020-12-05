#!/usr/local/bin/tcc -run
#include <stdio.h>

#define PRINT(x) _Generic((x), double: printf("double -> %f\n", x), \
                              default: printf("Unsupported type.\n"), \
                              int: printf("int -> %d\n", x), \
                              char *: printf("string -> %s\n", x))

int main()
{
    int a = 1;
    PRINT(a);
    PRINT("gogo");
    PRINT((char)'A');

    return 0;
}