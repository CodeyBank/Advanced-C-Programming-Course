#include <signal.h>
#include <stdlib.h>
#include <time.h>
#include<stdio.h>


void errorhandler(int signum);
int main(void){
    void (*sigHandler)(int);  // this is the return type for the signal
    sigHandler = signal(SIGINT, errorhandler);
    srand(clock());
    
    for(int i=0; i<20; i++)
    {
        int random = 1+rand()%100;
        if(random == 45 || random == 20 || random == 10){

            // raise a SIGINT when any of the above numbers are generated
            raise(SIGINT);

            // compare the return value of the signal function
            if (sigHandler == SIG_DFL){
                printf("\nFound SIG_ERR\n");
            }
        }
        // print the generated random number
        printf("%3d ", random);
    }
    
}

void errorhandler(int signum){
    printf("\nCaught a SIGINT exception for %d\n", signum);
}