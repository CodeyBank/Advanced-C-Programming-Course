#include<stdio.h>

//stanley
char * reverse(char * str);

char * reverse(char *str) {
    static int i = 0;
    static char rev[100];

    if (*str) {
        reverse(str + 1);
        rev[i++] = *str;
    }

    return rev;
}

