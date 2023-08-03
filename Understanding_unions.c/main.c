#include <stdio.h>
#include <stdlib.h>

// below is an anonymous struct. the literal, data represents the global variable table of
// type struct. notice that both the struct and the unions are the same

struct {
    char *name;
    union {
        int i;
        float f;
        char c;
    }data;
}table;

int main()
{
    table.data.c = 'f';
    table.name = "employee table";

    printf("Hello world!\n");
    return 0;
}
