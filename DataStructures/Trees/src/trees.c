/**
 * @file trees.c
 * @author codeybank (ezeh.stanley.es@gmail.com)
 * @brief Source files for the binary tree structure
 * @version 0.1
 * @date 2023-08-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "trees.h"

void insertNode(pTree_t *pTree, int data){
    if(*pTree == NULL){
        *pTree = malloc(sizeof(pTree));
        if (*pTree != NULL)
        {
            (*pTree)->data = data;
            (*pTree)->pLeft = NULL;
            (*pTree)->pRight = NULL; 
        }
        else{
            printf("%d not inserted. Memory unavailable",data);
        }
        
    }
    else{
        if (data < (*pTree)->data){
            insertNode(&(*pTree)->pLeft, data);
        }
        else if (data > (*pTree)->data)
        {
            insertNode(&(*pTree)->pRight, data);
        }
        else{
            printf("%d is Duplicated",data);
        }
        

    }
}

void TraverseInOrder(pTree_t Tree){
    if(Tree != NULL){
        TraverseInOrder(Tree->pLeft); /* Left */
        printf("%3d", Tree->data); /* parent/root */
        TraverseInOrder(Tree->pRight); /* Right */
    }
    // else{
    //     puts("Empty tree");
    //     return;
    // }
}

void TraversePreOrder(pTree_t Tree){
    if(Tree != NULL){
        printf("%3d", Tree->data); /* parent/root */
        TraversePreOrder(Tree->pLeft); /* Left */
        TraversePreOrder(Tree->pRight); /* Right */
    }
    // else{
    //     puts("Empty tree");
    //     return;
    // }
}

void TraversePostOrder(pTree_t Tree){
    if(Tree != NULL){
        TraversePostOrder(Tree->pLeft); /* Left */
        TraversePostOrder(Tree->pRight); /* Right */
        printf("%3d", Tree->data); /* parent/root */
    }
    // else{
    //     puts("Empty tree");
    //     return;
    // }
}

int main(void){
    int i=0;
    int item=0;
    pTree_t root = NULL;

    srand(time(NULL));
    puts("Inserting the following randomly generated numbers");

    for(i=1; i<=10; i++){
        item = rand() % 50;
        printf("%3d ", item);
        insertNode(&root, item);
    }

    printf("\n\nPreorder Traversal is:\n");
    TraversePreOrder(root);

    printf("\n\nPostorder Traversal  is:\n");
    TraversePostOrder(root);

    printf("\n\nInOrder Traversal is:\n");
    TraverseInOrder(root);
    printf("Hello world");
    return 0;
}
