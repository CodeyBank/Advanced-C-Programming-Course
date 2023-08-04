#include <stdio.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

int main(void){
    time_t calendar = time(NULL);

    struct tm * time_date;
    /* Array to parse date time values*/
    const char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    const char *months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    time_date = localtime(&calendar);

    printf("Today's date is %s %s %d %d\n", days[time_date->tm_wday], months[time_date->tm_mon], time_date->tm_mday, time_date->tm_year+1900);

    puts("Using asctime() \n");
    const time_t time_ptr = time(NULL);
    printf("Current date and time =%s",asctime(localtime(&time_ptr)));

    return 0;
}