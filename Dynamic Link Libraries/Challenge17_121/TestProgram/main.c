#include <stdio.h>
#include <stdlib.h>


#include "../StringFunction/stringfunctions.h"

int main()
{
    char *c = "Hi i want to remove all the letters i in this string";

    // string count
    printf("\nNumber of characters is %d",strcount(c));
    char d [strcount(c)];

    // string copy test
    strCopy(c, d);
    printf("\n%s \n",d);

    // Substring test
    int numberOfCharcters = 9;
    char subString[numberOfCharcters];
    substring(c, -6, numberOfCharcters, subString);
    printf("%s\n", subString);

    // stringconcat test
    char left[100] = "I want to concatenate this";
    char *right = "with this second string";
    strConcat(left, right);
    printf("%s\n", left);

    // Remove character
    // (void)removeCharacterInString(left, 'i');
    // printf("%s", left);

    return 0;
}
