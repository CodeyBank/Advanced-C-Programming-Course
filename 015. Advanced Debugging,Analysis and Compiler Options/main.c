#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define DEBUGON
#if defined(DEBUGON)
 #define LI_EX_PRINT(LEVEL,fmt, ...) \
        if(LEVEL >1) fprintf(stderr, fmt, ##__VA_ARGS__)
#else
    LI_EX_PRINT(LEVEL,fmt, ...)
#endif

enum DEBUGLEVEL {
    MINIMAL=1,
    VERBOSE = 3
};

void foo(char **pString){
    *pString = malloc(255);
    strcpy(*pString, "Hi Handsome");

    /* recall that this is very wrong and results in a memory leak
       since pString is a copy of the passed argument
    */
}

int main(){

    #if defined(MY_TEST) && defined(MY_MACRO)
        printf("Compiled for my test \n");
    #endif


    char *pMainString = NULL;
    foo(&pMainString);
    printf("Printing\n");
    printf("%s\n",pMainString);

    free(pMainString) ;

    return 0;
}

