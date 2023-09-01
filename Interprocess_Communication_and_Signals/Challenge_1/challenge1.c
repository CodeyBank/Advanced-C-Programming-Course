#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int score = 0;

void end_game() {

   printf("\nFinal score: %d\n", score);
   exit(0); 
}

void error(char *msg)
{
   fprintf(stderr, "%s: %s\n", msg, strerror(errno));
   exit(1);
}

void sigINTHandler(int signum){
    printf("\nCaptured sigabort \n");
    exit(1);
}

void sigALMHandler(int signum){
   printf("Sorry you missed the 5sec deadline \n");   
   raise(SIGINT);
}
int main() {

   srand (time(0));
   signal(SIGINT, end_game);
   signal(SIGALRM, sigALMHandler);

   while(1) {
      int a = rand() % 11;
      int b = rand() % 11;

      char txt[4];
    
      printf("\nWhat is %d times %d: ", a, b);
      alarm(5);
      fgets(txt, 4, stdin);

      int answer = atoi(txt);

      if(answer == a * b)
         score++;
      else
         printf("\nWrong! Score: %d\n", score);
    }

    return 0;
} 
