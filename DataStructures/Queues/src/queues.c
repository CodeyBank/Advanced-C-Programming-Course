#include "queues.h"
#include <stdio.h>
#include <stdlib.h>

node_t createNode(int key)
{
    node_t temp = (node_t)malloc(sizeof(node_t));
    temp->key = key;
    temp->next = NULL;
    return temp;
}

queue_t createQueue(void)
{
    queue_t newQueue = (queue_t)malloc(sizeof(queue_t));
    /* Initialize both the head and tail to NULL */
    newQueue->head = newQueue->tail = NULL;
    return newQueue;
}

void enqueue(queue_t *queue, int key)
{
    node_t tempN = createNode(key);

    if ((*queue)->tail == NULL)
    {
        (*queue)->head = (*queue)->tail = tempN;
        return;
    }
    (*queue)->tail->next = tempN;
    /* Update the rear node to the new node */
    (*queue)->tail = tempN;
}

node_t dequeue(queue_t *queue)
{
    if ((*queue)->head == NULL)
    {
        return NULL;
    }

    /* Temporary store the current head and move the current front one step */
    node_t temp = (*queue)->head;
    (*queue)->head = (*queue)->head->next;

    /* If the new head is now a null value, update the tail as well*/
    if ((*queue)->head == NULL)
    {
        (*queue)->tail = NULL;
    }

    return temp;
}

void printQueue(queue_t queue)
{
    node_t temp = queue->head;
    if (temp == NULL)
    {
        puts("Queue is empty\n");
        return;
    }
    printf(":-->");

    do
    {
                printf("| %d ", temp->key);
        temp= temp->next;
    } while (temp != NULL);
    puts("|");
}

int isEmpty(queue_t queue) {
    return queue->head==NULL;
}

node_t peek(queue_t queue)
{
    if (queue->head == NULL)
    {
        puts("Empty queue");
        return NULL;
    }
    return queue->head;
}

void cleanUpQueue(queue_t queue)
{
    if (queue->head == NULL)
    {
        puts("empty queue. Nothing to do here\n");
        return;
    }
    

    while (queue->head != NULL)
    {
        node_t temp = queue->head;
        queue->head = queue->head->next;
        free(temp);
    }
    printf("Cleaning complete ...\n");
}
// tests

int main(void)
{
    queue_t queue = createQueue();

    for(int i=1; i<21; i++){
        enqueue(&queue, i);
    }
    printQueue(queue);
    (void)dequeue(&queue);
    printQueue(queue);
    dequeue(&queue);
    printQueue(queue);
    node_t peeked = peek(queue);
    printf("Peeked node has the value: %d\n", peeked->key);
    for(int i=1; i<16;i++) dequeue(&queue);
    printQueue(queue);
    cleanUpQueue(queue);
    printQueue(queue);
    return 0;
}