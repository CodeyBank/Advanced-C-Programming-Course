#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAXSIZE 100000
typedef struct data{
    int num;
    char * letters;
    int currentLevel;
} data_t;

enum errorcodes{
    EMPTYSOURCE = -1,
    INVALID_DESTINAION = -2,
    BUFFEREMPTY = -3,
    BUFFERFULL = -4,
};

typedef struct buffer{
    int currentIndex;
    char data[MAXSIZE];
}buffer_t;

typedef data_t * data_ptr;

int produce(buffer_t *buffer, char * source, long int size){
    int status = 0;
    // check if the source is a valid cstyle string
    if (source == NULL){
    
        fputs("source location is null", stderr);
        return EMPTYSOURCE;
    }

    // check if the buffer is full
    if (buffer->currentIndex == MAXSIZE-1){
        fputs("Buffer full", stderr);
        return BUFFERFULL;
    }

    // check if the data to be copied is more than the available buffer
    if (size > (MAXSIZE -buffer->currentIndex)){
        fputs("Data to be copied is greater than available space",stdout);
        // update the number of byte streams to be copied
        size = MAXSIZE - buffer->currentIndex;
    }

    // initialize the start point of copying
    long int start  = buffer->currentIndex;

    for (size_t i = 0; i < size; i++)
    {
        buffer->data[i+start] = source[i];
        buffer->currentIndex ++;
        status++;
    }

    return status;
}

int consume(char* destination, buffer_t * source, int size){

    int status = 0;
    // check if destination is valid
    if (destination == NULL){
        fputs("Destination is invalid", stderr);
        return INVALID_DESTINAION;
    }
    // check if the source buffer is valid and has data
    if (source->currentIndex == 0){
        fputs("Cannot consume data from empty buffer", stderr);
        return BUFFEREMPTY; 
    }

    // check to see that the amount of data to be copied is less than what is available
    if (size > source->currentIndex+1)
    {     
        char msg[200];
        size =  source->currentIndex;
        sprintf(msg, "Requested more data than is available. Will not consume %ld bytes of data\n", size);   
        fputs( msg , stderr);
    }
    
    // start copying data
    for (size_t i = 0; i < size; i++)
    {
        destination[i] = source->data[i];
        // null oout the data and decrement currentIndex
        source->data[i] = '\0';
        source->currentIndex --;
        // destination++;
        status +=1;
    }
    return status;
}

int main(int argc , char* argv[]){
    struct data newData= {.num=5, .letters = (char*)malloc(sizeof(char)* 5), .currentLevel =1};
    newData.letters = "Hello world\n";
    printf("Stored in structure: %s", newData.letters);
    printf("Current level is %d\n", newData.currentLevel);

    char * source = "Hello worldssss";
    buffer_t newValue= {.currentIndex =0};
    produce(&newValue, source, strlen(source));

    printf("Buffer: %s\n", newValue.data);
    printf("Current index: %ld\n", newValue.currentIndex);

    char destination[600];
    consume(destination, &newValue, 21);

    printf("Destination: %s\n", destination);
    printf("New buffer size is %ld", newValue.currentIndex);
}