/**
 * @brief 
 * 
 */

#pragma once
typedef struct Node{
    int data;
    struct Node* link;
} node_t;


typedef node_t * stack_t;

/**
 * @brief Push data to top of stack
 * 
 * @param top Pointer to top of stack
 * @param data Data to be pushed to top of stack
 */
void push(stack_t *top,int data);

/**
 * @brief Check if the stack is empty
 * 
 * @param top Top of stack
 * @return int 1-empty 0-has some content
 */
int isEmpty(stack_t top);

/**
 * @brief Remove item from top of stack
 * 
 * @param top Pointer to the top of the stack
 * @return int 0- Success, 1-fail
 */
int pop(stack_t *top);

/**
 * @brief Display the contents of the stack
 * 
 * @param top top of the stack
 * @return int 0-Success 1-failure
 */
int display(stack_t top);