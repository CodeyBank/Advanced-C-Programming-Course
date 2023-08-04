#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* strtol can be used to extract and convert integers in a string */
/*Prototype long int strtol(const char *, char **end, int base)
    char * - string
    end - delimiter pointer. this will be redirected to point to the second half
          of the string
    base - the number base
    returns the integer
*/
void printarray(const int *array, size_t arraysize){
    for(size_t i=0; i<arraysize; i++){
        printf(" %d ", array[i]);
    }
        
}
int main(void){

    char str[30] = "20203304 Some other string";
    char *ptr = NULL;
    long ret = 0;

    ret = strtol(str, &ptr, 10);
    printf("Unsigned long integer in the string is %ld\n", ret);
    printf("Rest of the string is |%s|\n", ptr);

    /* Random numbers*/
    srand(time(0));

    for(int i=0; i<20; i++){
        printf(" %d ", rand() %100 +4);
    }
    printf("\n");

    /* System command*/
    char cmd[50];

    strcpy(cmd, "ls -lrt");
    system(cmd);

    /* memcpy*/
    #define N 10
    int source[N] = {1, 2 ,4, 6, 7, 1000 ,8 ,9 , 10, 55};
    int destination[N];
    printf("\nMemcpy() copying from source %p to destination %p \n", source, destination);
    memcpy(destination, source, N*sizeof(int));
    printarray(destination, N);

    puts("\n\nmemmove() showing overlaping");
    memmove(destination, destination+3, 4*sizeof(int));
    printarray(destination, N);


    return 0;
}