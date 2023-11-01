
/* There are two threads - a producer that is producing a byte stream, and a consumer that is consuming the byte stream.
 * Task is to implement the body of the functions below, necessary structures.
 * NOTE: There is no need to write main function, threads, etc.
 */

/**
 * @brief
 * 
 * @params
 * 
 * @ret Returns the number of bytes successfully copied. 0 if nothing is copied. If source is null, exit with status 1
 * */
#include <pthread.h>
#include <stdio.h>
#define MAXQUEUESIZE 10000

typedef struct buffer_t{
  unsigned int size;  // size of the queue
  char * data;
  //char data[MAXQUEUESIZE];// buffer to hold the data on the queue
  unsigned int currentSize; // how much data is currently in the queue
} buffer_t;

volatile buffer_t samplebuffer;


int send_to_queue(buffer_t *buffer_p, unsigned int size, const char *source_p) {
	int status = 0;
  // grab the mutex
  
  //check if the buffer is valid and not full
  if(buffer_p != NULL){
		fputs(stderr,"Invalid buffer");
    return status;
  }
  if (buffer_p-> size  == buffer_p->currentSize){
		fputs(stderr, " Cannot add to full queue");
    return -2;
  }
  // Check if source is not null
  if(source_p == NULL){
  	exit(1);
  }
  
  // allocate memory for the data if there is no data is there
  if(buffer_p->data == NULL){
    fputf(stdout, "allocating memory for data ...");
    buffer_p->data = (char *)malloc(sizeof(char)*size);
  }
  
  // verify that the malloc operation was successful
  if (buffer_p->data == NULL){
    fputs(stderr, "Unable to allocate memory");
    return -1;
  }
  
  // move the pointer to the next free space
  for(unsigned int i=0; i<= buffer_p->currentSize; i++){
    buffer_p->data++;
  }
  
  // iterate through  the number of given characters one byte at a time
  
  for (unsigned int i=0; i< buffer_p->size; i++){
    (*buffer_p->data) = *source_p;
  
    // increment to next byte
    buffer_p->data++;
    source_p++;
    status = i;
    buffer_p->currentSize+=1;
  }

  return status;
}

/**
 * @param buffer_p Pointer to the buffer structure
 * @param size size of the data to
 * */
int receive_from_queue(buffer_t *buffer_p, unsigned int size, char *destination_p) {
  // check if buffer has some content or points to valid data
  int status = 0;
  if (buffer_p == NULL || destination_p == NULL ){
    exit(1);
  }
  
  //Check if the buffer is empty
  if (buffer_p->size == buffer_p->currentSize){
		fputs(stderr, "Queue empty");
    return 0;
  }
  
  // iterate through buffer and copy data one byte at time
  for (unsigned int i=0; i<size; i++){
    *destination_p = *buffer_p->data;
    buffer_p->data = '\0';
    destination_p++;
    buffer_p->data--;
    status++;
  }
  return status;
}
