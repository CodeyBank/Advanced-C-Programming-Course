#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

void push(stack_t *top,int data){
    stack_t temp = malloc(sizeof(stack_t));
    if(temp !=NULL){
        temp->data = data;
        temp->link = *top;
        *top = temp;
    }
}

int isEmpty(stack_t top){
    return top == NULL;
}

int pop(stack_t *top){
    stack_t tmp;
    if(*top != NULL){
        tmp = *top;
        *top = tmp->link;
        tmp->link = NULL;
        free(tmp);
    }
    else{
        puts("Cannot pop an empty stack\n");
        return 1;
    }
    return 0;
}


int display(stack_t top){
    if(top==NULL){
        return 1;
    }
    stack_t tmp = top;

    while(tmp != NULL){
        printf(" %d:", tmp->data);
        tmp = tmp->link;
    }
    puts("eos\n");
    return 0;
}
