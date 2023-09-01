#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

void example3()
{
    puts("-----*-- Example 3 -----*----");
    int x = 1;
    // pid_t pid = getpid();
    pid_t child;
    if ((child = fork()) == 0)
        printf("Child PID is %d and has x = %d\n", getpid(), ++x);
    else
        printf("Parent has x = %d\n", --x);
    
    printf("________ END OF PROCESS for %d____________\n", getpid());
}

#define MAX_COUNT 10
#define BUFFER_SIZE 100
void example2(void){
    puts("-----*-- Example 2 -----*----");
    pid_t pid;
    char buf[BUFFER_SIZE];

    fork(); // creates a new child process
    pid = getpid(); // each process gets a copy of this PID

    for (int i=1; i<=MAX_COUNT; i++){
        sprintf(buf, "From PID %d, value = %d\n", (int)pid, i);
        write(1, buf, strlen(buf));
    }
    puts("________ END OF PROCESS 2____________");
}

void example1(void){
    puts("-----*-- Example 1 -----*----");
        /* Makes two processes which run the same program after this instruction*/
    pid_t childPID;
    if ((childPID = fork()) <0 )
    {
        printf("Failed to create subprocess\n");
    }
   
    printf("Main Application with PID %d \n", (int)getpid());
    printf("Main Application with PID %d \n", (int)getpid());
    puts("________ END OF PROCESS 1____________");
}

int main(void){



    //example1();
    //example2();
    example3();
    //kill();
    return 0;
}