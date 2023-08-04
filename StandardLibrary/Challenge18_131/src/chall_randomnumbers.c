/**
 * @file chall_randomnumbers.c
 * @author maestrocodey (you@domain.com)
 * @brief Generate 50 random numbers between 0.5 and -0.5
 * @version 0.1
 * @date 2023-08-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define  NUM_OF_RAND 50
int main(void){
    srand(time(0));
    double lowerbound = -0.5, upperbound= 0.5;
    printf("Generating %d random numbers\n", NUM_OF_RAND);
    for(int i=0; i<NUM_OF_RAND; i++){
        double random = (rand () % 1001 - 500) / 1000.f;
        printf("%2.1f\n", random);
    }

    return 0;
}