/**
 * @file challenge.c
 * @author Stanley Ezeh (ezeh.stanley.es@gmail.com)
 * @brief Challenge to understand threads, mutex and condition variables
 * @version 0.1
 * @date 2023-09-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define NBTHREADs 10
#define CONDITION NBTHREADs % 2

void *task(void *arg);

int counter =0;
pthread_mutex_t mut;
pthread_cond_t cond;
int number_evens_finished=0;

int main(void){
    // Create 10 separate threads
    pthread_t threads[NBTHREADs];
    int message[NBTHREADs] = {0,1,2,3,4,5,6,7,8,9};
    mut = PTHREAD_MUTEX_INITIALIZER;
    pthread_cond_init(&cond, NULL);

    for(int i=0; i<NBTHREADs; i++){

        if(pthread_create(&threads[i], NULL, task, (void*)&message[i]) !=0){
            fputs("Failed to create thread", stderr);
        }
    }

    for(int i=0; i<NBTHREADs; i++){
        if(pthread_join(threads[i], NULL) !=0){
            fputs("Failed to join thread", stderr);
        }
    }

    pthread_mutex_destroy(&mut);
    pthread_cond_destroy(&cond);
    pthread_exit(NULL);
    return 0;
}

void *task(void *arg){
    int msg = *(int*)(arg);

    // critical section
    pthread_mutex_lock(&mut);
    while((msg%2) !=0 && number_evens_finished != NBTHREADs/2){
        printf("Thread %d is now waiting ...\n",msg);
        number_evens_finished += 1;
        pthread_cond_wait(&cond, &mut);
    }
    
    counter += 1;
    printf("Thread: %3d - modified counter to %d\n",pthread_self(), counter);
    printf("Thread: %3d - Received: %2d Counter: %d\n", pthread_self(), msg, counter);
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&mut);
}