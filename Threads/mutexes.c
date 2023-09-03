/**
 * @file mutexes.c
 * @author Stanley Ezeh (ezeh.stanley.es@gmail.com)
 * @brief Example file to show the use of mutexes in c
 * @version 0.1
 * @date 2023-09-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <pthread.h>
#include <stdio.h>

#define NTHREADs 10

void *task(void*);

pthread_mutex_t mut1 = PTHREAD_MUTEX_INITIALIZER;  // Static initializatiion of mutexes. Initialized to -1
pthread_mutex_t mut2;

// pthread_mutex_init(&mut2, NULL); // dynamically

int counter = 0;

int main(void){
    pthread_t threadIDs[NTHREADs];
    int i, j;

    // create NTHREADs threads
    for(i=0; i<NTHREADs; i++){
        pthread_create(&threadIDs[i], NULL, task, NULL);
    }

    // make the main thread wait for all the threads
    for ( j = 0; j < NTHREADs; j++)
    {
        pthread_join(threadIDs[j], NULL);
    }

    printf("The final counter value: %d\n", counter);

    return 0;
    
}

void *task(void *arg){
    // Print out the thread Number to identify what thread this is 
    printf("ThreadID: %ld\n", pthread_self());
    pthread_mutex_lock(&mut1);
    counter++;
    pthread_mutex_unlock(&mut1);
}