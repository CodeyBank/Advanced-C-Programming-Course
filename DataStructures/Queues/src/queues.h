/**
 * @file queues.h
 * @author codeybank (ezeh.stanley.es@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2023-08-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/* A queue is a FIFO data structure and the exact opposite of a stack 
   data structure which is basically a LIFO. It can be implemented using
   arrays or pointers. When implemented using arrays, the size is fixed
    */
struct QNode{
    int key;
    struct QNode * next;
};

struct Queue{
    struct QNode *head, *tail;
};

typedef struct QNode * node_t;
typedef struct Queue * queue_t;

/**
 * @brief creates a node
 * 
 * @param key 
 * @return queue_t pointer to node object
 */
node_t createNode(int key);

/**
 * @brief Create a Queue object
 * 
 * @return queue_t returns pointer to the head of the queue
 */
queue_t createQueue(void);

/**
 * @brief inserts value to the tail of the queue
 * 
 * @param queue queue into which the key should be added
 * @param key value of the node to be inserted at the end of the queue
 */
void enqueue(queue_t *queue, int key);

/**
 * @brief removes a node from the top/front of the queue. You must free this
 * memory after it is used.
 * 
 * @param queue queue from which the key should be removed
 * @return node_t pointer to the node in the queue. NULL if empty
 */
node_t dequeue(queue_t *queue);

/**
 * @brief Display the content of the queue
 * 
 * @param queue queue to display
 */
void printQueue(queue_t queue);

/**
 * @brief Clean up the entire queue and free up memory
 * 
 * @param queue Queue to be cleaned
 */
void cleanUpQueue(queue_t queue);

/**
 * @brief Returns a copy of the head of the queue without removing it
 * 
 * @param queue queue to be peeked at
 * @return node_t head of the queue
 */
node_t peek(queue_t queue);

/**
 * @brief Check if the queue is empty
 * 
 * @param queue queue to check
 * @return int 0 not empty 1 empty
 */
int isEmpty(queue_t queue);