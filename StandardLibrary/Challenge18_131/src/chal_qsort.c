/**
 * @file chal_qsort.c
 * @author codeybanks (ezeh.stanley@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/// @brief generate an array of randomly generated doubles
/// @param arr 
/// @param n 
void fillarray(double arr[], int n);


/// @brief Display the sorted array
/// @param arr 
/// @param n 
void showarray(const double arr[], int n);

int comparison(const void*, const void*);

int main(void){
    // create the array and fill with random doubles
    #define arraysize 50

    double arrOfDoubles[arraysize];
    fillarray(arrOfDoubles, arraysize);

    puts("-------------Unsorted array of doubles----------- \n");
    showarray(arrOfDoubles, arraysize);

    printf("\n\n---------- Sorted Array of Doubles ------------\n");
    qsort(arrOfDoubles, arraysize, sizeof(double), comparison);
    showarray(arrOfDoubles, arraysize);

    return 0;
}

int comparison(const void* v1, const void* v2){
    double val1 = *(const double *)(v1);
    double val2 = *(const double *)(v2);
    return val1 - val2;
}

void fillarray(double arr[], int n){
    srand(time(NULL));

    for(int i=0; i<n; i++){
        double rnd = ((double) rand() / RAND_MAX) * (20.0 - 1.0) + 1.0;
        arr[i] = rnd;
    }
}

void showarray(const double arr[], int n){
    int printBlockSize = 10;
    for(int i=1; i<n; i++){
        if((i % printBlockSize) != 0)
            printf("%2.4f\t", arr[i-1]);
        else
            printf("\n");
    }       
}