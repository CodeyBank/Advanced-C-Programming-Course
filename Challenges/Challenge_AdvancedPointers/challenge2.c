#include <stdio.h> 
#include <malloc.h>

int allocateMemory(int *ptrMemory){
    ptrMemory = malloc(sizeof(int));
    printf("Allocated memory to pointer at address 0x%X\n",ptrMemory);
}

int main(){
    int *ptrInteger = NULL;
    allocateMemory(ptrInteger);
    *ptrInteger = 5;
    printf("Value pointed to: %d\n", *ptrInteger);

    free(ptrInteger);
}