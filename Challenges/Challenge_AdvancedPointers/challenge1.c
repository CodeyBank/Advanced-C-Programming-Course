#include <stdio.h>
// #include "challenges.h"


// void challenge_one(){
//     int normal = 5;
//     int *pSingle = NULL;
//     int **pDouble;

//     pSingle = &normal;
//     pDouble = &pSingle;
//     printf("Value of normal variable reference: \t%d\n", normal);
//     printf("Value of normal variable From single pointer: \t%d\n",*pSingle);
//     printf("Value of normal variable From double Pointer \t%d\n", **pDouble);

//     printf("Address Normal variable: \t0x%X\n", &normal);
//     printf("Address Normal variable from single Pointer: \t0x%X\n", pSingle);
//     printf("Address Normal variable from double Pointer: \t0x%X\n", *pDouble);

//     printf("Value of a single pointer variable: \t0x%X\n",pSingle);
//     printf("Value of a single pointer from double pointer: \t0x%X\n", *pDouble);

//     printf("Double pointer value: %d and address: 0x%X\n", *pDouble, &pDouble);

// }

    int main()
    {
        int *p = NULL;
        void *vp = NULL;
        if (vp == p)
            printf("equal\n");
        return 0;
    }