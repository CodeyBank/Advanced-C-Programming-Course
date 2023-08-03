#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>

double sample_stddev(int count, ...);

int main()
{
    printf("%f\n", sample_stddev(4,25.0,27.3, 26.9, 25.7));
    return 0;
}

double sample_stddev(int count, ...){
    double sum = 0;
    va_list args1;
    va_start(args1, count);

    // we can now make a duplicate of the lists
    va_list args2;
    va_copy(args2, args1);

    // write a loop to go through the list
    for (int i=0; i<count; i++){
        double num = va_arg(args1, double);
        sum += num;
    }

    va_end(args1);

    // we have ended the args1 but we can use the copy, args2 for std deviation

    double mean = sum/count;
    double sum_sq_diff = 0;

    for (int i=0; i<count; ++i){
        double num = va_arg(args2, double);
        sum_sq_diff +=(num-mean) * (num-mean);
    }

    va_end(args2);

    return sqrt(sum_sq_diff/count);
}

