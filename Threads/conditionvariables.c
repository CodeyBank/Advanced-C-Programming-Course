/**
 * @file conditionvariables.c
 * @author Stanley Ezeh (ezeh.stanley.es@gmail.com)
 * @brief Illustrating the use of condition variables
 * @version 0.1
 * @date 2023-09-03
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define NBTHREADs 5
/*
    Two things are required
    1. mutex
    2. condition variable
*/

pthread_mutex_t fuelMutex;
pthread_cond_t fuelCond;

// Global shared resource
int fuelVolume = 0;
int fuelConsumed = 0;

#define CONDITION 40 < fuelVolume && 100 > fuelVolume
#define CARTANKVOLUME 400
#define FUELINTANKVOLUME 2000

void *fillFuelTank(void *arg)
{

    while (FUELINTANKVOLUME > fuelVolume)
    {
        pthread_mutex_lock(&fuelMutex);
        fuelVolume += 50;
        printf("Filling Fuel. Current volume: %d\n", fuelVolume);
        pthread_mutex_unlock(&fuelMutex);
        // pthread_cond_signal(&fuelCond);
        pthread_cond_broadcast(&fuelCond);
        sleep(1);
    }
    puts("Fueling  tank  is  now full. Exiting ...");
    pthread_exit(NULL);
}

void *consumeFuel(void *arg)
{
    for (;;)
    {
        pthread_mutex_lock(&fuelMutex);
        while (fuelVolume < 40)
        {
            puts("No fuel to consume. waiting ...");
            pthread_cond_wait(&fuelCond, &fuelMutex); // Frees the fuelMutex and puts the thread to sleep while waiting
        }
        fuelVolume -= 30;
        fuelConsumed += 30;
        printf("Car_%d Consuming Fuel. Current consumed volume: %d  Fuel Tank: %d\n", pthread_self(),fuelConsumed, fuelVolume);
        pthread_mutex_unlock(&fuelMutex);
        if (fuelConsumed == CARTANKVOLUME){
            printf("Car_%d tank is full. exiting Consume thread\n", pthread_self());
            pthread_exit(NULL);
        }
    }

}

int main(void)
{
    // initialize and create Array of threads
    pthread_t threads[NBTHREADs];
    pthread_mutex_init(&fuelMutex, NULL);
    pthread_cond_init(&fuelCond, NULL);

    for (int i = 0; i < NBTHREADs; i++)
    {
        if (i == 0)
        {
            if (pthread_create(&threads[i], NULL, fillFuelTank, NULL) != 0)
                puts("Failed to create fillFuelTank (producer) thread");
        }
        else
        {
            if (pthread_create(&threads[i], NULL, consumeFuel, NULL) != 0)
            {
                puts("Failed to create consumeFuel (consmer) thread");
            }
        }
    }

    // wait on threads
    for (int i = 0; i < NBTHREADs; i++)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            puts("Failed to join thread");
        }
    }

    pthread_mutex_destroy(&fuelMutex);
    pthread_cond_destroy(&fuelCond);
    // pthread_exit(NULL);
    return 0;
}