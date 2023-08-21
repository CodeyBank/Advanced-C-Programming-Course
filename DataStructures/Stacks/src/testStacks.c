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
    display(s);
    return 0;
}