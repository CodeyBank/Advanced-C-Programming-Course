/**
 * @file printcurrenttime.c
 * @author codeybanks (ezeh.stanley@gmail.com)
 * @brief Print out the current time using asctime and time functions
 * @version 0.1
 * @date 2023-08-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

int main(void){
    time_t calendar = time(NULL);
    const time_t time_ptr = time(NULL);
    printf("Current date and time =%s",asctime(localtime(&time_ptr)));

    return 0;
}