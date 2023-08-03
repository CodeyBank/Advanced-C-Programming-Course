#include <stdio.h>
#include <stdlib.h>
#define NUM_OF_ITERATIONS 10000000
typedef enum{
    false = 0,
    true = !false
} bool;

int add(int n){
    return 6*n+1;
}

int subtract(int n){
    return 6*n-1;
}

bool isPrimeNumber(int num){

    // check if the number is negative
    if (num<1) return false;
    if ((num == 2)|| (num == 3)) return true;

    // prime numbers can only be divided by it self and one.
    // prime numbers can be found by 6n+1 or 6n-1

    int n=1;

    while(n < NUM_OF_ITERATIONS){
        if( (add(n)== num) || (subtract(n)==num) ) {
            return true;
        };
        n++;
    }

    return false;
};
bool isEvenNumber(int num){
    if (num<1)return false;
    return num%2 == 0;
}

bool isOddNumber(int num){
    if (num<1)return false;
    return num%2 != 0;
}


int main(int argc, char *argv[])
{
    // check that there are exactly two input arguments
    if(argc != 2)
    {
        fprintf(stderr,"Usage: file path\n");
        exit(1);
    }

    // create a file object and store
    FILE * fp = NULL;
    fp = fopen(argv[1], "r");
    if (fp == NULL){
        fprintf(stderr, "Unable to open file\n");
        exit(1);
    }
    printf("%s opened successfully\n\n", argv[1]);

    // use fscanf to read from file and format into integers
    int val, retval;
    retval = fscanf(fp, "%d", &val);

    do{
        if (isPrimeNumber(val)) printf("Found prime Number: %d \n",val);
        else if (isEvenNumber(val)) printf("Found an even number: %d \n",val);
        else if(isOddNumber(val)) printf("Found an odd number: %d \n",val);
//        else printf("Value is not valid\n");

        retval = fscanf(fp, "%d", &val);
    }while(retval !=EOF);

    // check to see if the value read is an prime even or odd


    fclose(fp);
    return 0;
}
