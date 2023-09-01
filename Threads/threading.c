/**
 * @file threading.c
 * @author codeybank (ezeh.stanley.es@gmail.com)
 * @brief Introduction to multithreading in C
 * @version 0.1
 * @date 2023-09-01
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <malloc.h>
#include <unistd.h>

/*
    Function signature for pthread_creat
    int pthread_create(pthread_t *th, const pthread_attr_t *attr, void *(*func)(void *), void *arg)
\*/
// void *(*func)(void *)
void *printMessageThread(void *ptr);
void *task2(void *ptr);
void *task3MultipleArgs(void *ptr);
void *returnValFromThread(void *ptr);

/*
    Struct for multiple arguments
*/
#define MAX_MSG_SIZE 255
struct thread_args{
    int threadID;
    int data;
    char *msg;
};
typedef struct thread_args * thread_args_ptr; 

int main(void){
    pthread_t thread1, thread2, thread3, thread4;

    char *threadName1 = "Thread 1";
    char *threadName2 = "Another Thread";
    

    int ret1=0, ret2=0, ret3 = 0;
    
    ret1 = pthread_create(&thread1, NULL, printMessageThread, (void *)threadName1);
    ret2 = pthread_create(&thread2, NULL, task2, (void *)threadName2);

    // We expect the following thread to return a string to be saved in the retStr variable
    char *retStr;
    pthread_create(&thread4, NULL, returnValFromThread, NULL);


    // create arguments to be sent to the thread
    struct thread_args arg;
    arg.msg = (char *)malloc(sizeof(char)*MAX_MSG_SIZE); // needs to be created on the heap
    arg.threadID = 516;
    arg.data = 77777;
    arg.msg = "Multiple argument thread\n";

    ret3 = pthread_create(&thread3, NULL, task3MultipleArgs, (void *)&arg);

    /* Wait for the threads to finish before Main continues. Else Main would finish before the threads
        and we would have zombie threads
    */
    pthread_join(thread1, NULL);  //NULL because we are not sending anything to the exit function
    //(thread2, NULL);
    pthread_join(thread3, NULL);
    // the following thread will return data
    pthread_join(thread4, (void **)&retStr);

    printf("All threads are done\n");
    printf("Thread 4 returns: %s", retStr);
    printf("Thread 1 returns: %d\n", ret1);
    printf("Thread 2 returns: %d\n", ret2);
    pthread_exit(NULL);
    exit(0);
}

void *printMessageThread(void *ptr){
    char * msg = (char *)ptr;
    printf("Received message from %s\n", msg);
    
}

void *task2(void *ptr){
    pthread_detach(pthread_self());
    sleep(10);
    printf("Second task has been completed \n");
    pthread_exit(NULL);
}

void *task3MultipleArgs(void *ptr){
    struct thread_args *arg = (struct thread_args *)(ptr);
    char receivedMsg[MAX_MSG_SIZE];
    strcpy(receivedMsg, arg->msg);
    printf("\nReceived arg.threadID = %d\narg.data = %d\narg.message  = %s\n", arg->threadID, arg->data, receivedMsg); 
}

void *returnValFromThread(void *ptr){
    char *returnMsg = "Return Msg from Thread 4\n";
    return (void *)returnMsg;
}