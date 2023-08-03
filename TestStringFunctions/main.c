#include <stdio.h>
#include <stdlib.h>


#include "StringFunctions.h"

int main()
{
    int i =0;
    char *c = "Hi i want to remove all the letters i in this string";

    // string count
    printf("\nNumber of characters is %d",strcount(c));
    char d [strcount(c)];

    // string copy test
    strCopy(c, d);
    printf("\n%s \n",d);

    return 0;
}
