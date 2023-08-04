/**
 * @file tmstructure.c
 * @author codeybanks (ezeh.stanley@gmail.com)
 * @brief Challenge to test understanding of the tm structure. Computes the number of seconds passed since the beginniing
 *        of the current month
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

#define secondsInMin 60
#define minsInHour 60
#define hoursInDay 24
int main(void){
    time_t now = time(NULL);
    struct tm * tmstruct;
    tmstruct = localtime(&now);

    int dayOfMonth = tmstruct->tm_mday -1;
    int currenthour = tmstruct->tm_hour;
    int currentMin = tmstruct->tm_min;
    int currentSecond = tmstruct->tm_sec;
    int totalElapsedSecsTillYesterday = dayOfMonth * (secondsInMin*minsInHour*hoursInDay);
    int elapsedSeconds =  totalElapsedSecsTillYesterday + (currenthour*minsInHour*secondsInMin) + (currentMin*secondsInMin) +currentSecond;
    printf("The elapsed seconds since this month = %dseconds \n",elapsedSeconds);

    // now = time(NULL);
    // struct tm *t = localtime(&now);
    // int seconds = t->tm_sec + t->tm_min * 60 + t->tm_hour * 3600 + (t->tm_mday - 1) * 86400;
    // printf("The elapsed seconds since this month - %d", seconds);
    return 0;
}