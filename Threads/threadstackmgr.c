/**
 * @file threadstackmgr.c
 * @author codeybank (ezeh.stanley.es@gmail.com)
 * @brief demonstrate stack management 
 * @version 0.1
 * @date 2023-09-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

// Create a thread attribute
pthread_attr_t attrMain, attrWorker;

// create a task that will use the attribute we created
void *workerThread(void* threadID){
    long tID;
    size_t workerThreadStackSize;

    // merely for demonstration purpose. this may or may not be the true TID
    tID = *((long *)threadID);

    // get the thread stack size using the pthread_attr_getstacksize() API
    pthread_attr_getstacksize(&attrMain, &workerThreadStackSize);
    printf("ThreadID arg: %ld Stack size : %li bytes \n", tID, workerThreadStackSize);
    pthread_exit(NULL);
}

int main(void){
    pthread_t worker;
    size_t stacksize;
    long dummyArg= 45539;

    // Initialises the attribute structure to defalut values
    pthread_attr_init(&attrMain);
    // get the default threadstack size and display
    pthread_attr_getstacksize(&attrMain, &stacksize);
    printf("The default thread stack size is %ld\n", stacksize);

    // we can now adjust the stack size
    stacksize = 50000000;
    printf("Reallocating the default stack size to %ld\n", stacksize);
    //pthread_attr_setstacksize(&attrMain, stacksize);

    // now create a thread with the attribute we have now modified
    int ret = pthread_create(&worker, &attrMain, workerThread, (void *)&dummyArg);

    // check to see if the thread was successfully created
    if(ret){
        printf("ERROR: return code from  pthread_create() is %lu\n", ret);
        exit(EXIT_FAILURE);

    }

    pthread_exit(NULL);
    exit(0);
    
}