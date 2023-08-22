/**
 * @file testStacks.c
 * @author codeybank (ezeh.stanley.es@gmail.com)
 * @brief File to demonstrate the use of stacks
 * @version 0.1
 * @date 2023-08-21
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include "stack.h"
#include <stdio.h>


int main(void){
    stack_t s;
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);
    printf("Stack is %s empty\n", isEmpty(s)? "":"NOT");
    display(s);
    return 0;
}