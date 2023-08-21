#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

/* List Data structure is a struct with a member that points
   to he next element in the list. In this way, the nodes/links
   in the list are not saved in a contiguous memory block in 
   contrast to arrays. 
*/

void insertAtBegining(pListNode *first, char item){
    // create a new node on the heap
    pListNode newItem = (malloc(sizeof(node_t)));
    newItem->value = item;
    newItem->pNext = *first;

    //update the first
    *first = newItem;
};

int insertAtEnd(pListNode *first, char item){
    // we need to find the pointer to the last item on the list
    pListNode currentNode = *first;

    /*  NodeHead -> Node2 -> Node3 -> ... NodeEnd->NULL*/
    if(currentNode != NULL){
        while(currentNode->pNext!= NULL){
            currentNode = currentNode->pNext;
        }
        // now currentNode holds the last node in the list (because its pNext is Null)
        // Simply create a new node on the heap and set the pNext to this node
        currentNode->pNext = (pListNode)malloc(sizeof(node_t));

        // malloc failed?
        if (currentNode->pNext ==NULL)
            return 1;
        currentNode->pNext->value = item;
        currentNode->pNext->pNext=NULL;
    }
    else{
        // if the list is empty, just create a new item place it inside
        currentNode = malloc(sizeof(node_t));
        currentNode->value = item;
        currentNode->pNext =NULL;
        *first =currentNode;
    }
    return 0;
}

int insert(pListNode *first, char item){
    pListNode pNewNode=NULL, pPreviousNode=NULL, pCurrentNode=NULL;

    pNewNode = (pListNode)malloc(sizeof(node_t));

    if(pNewNode != NULL){
        pNewNode->value = item; /* Assign the item to the node's value*/
        pNewNode->pNext = NULL; /* For now we dont know what it would link to*/

        /* Initialize the previous node to NULL and the current node to *first*/
        pPreviousNode = NULL;
        pCurrentNode = *first;

        /* ensure that the current value is alphabetically less than the value in next node*/
        while(pCurrentNode != NULL ){
            if(item < pCurrentNode->value){
                break;
            }
            pPreviousNode = pCurrentNode;
            pCurrentNode = pCurrentNode->pNext;
            
        }

        /* Check to see if after above operation, previousNode is not NULL */
        if (pPreviousNode == NULL){
            pNewNode->pNext = *first;
            *first = pNewNode;
        }
        else{
            /* insert the new node between the previousNode and the currentNode*/
            pPreviousNode->pNext = pNewNode;
            pNewNode->pNext = pCurrentNode;

        }

    }
    else{
        puts("Not enough memory to allocate\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}

int findItem(pListNode first, char item){
    int index=0;
    pListNode currentNode = first;
    while(currentNode !=NULL && currentNode->value !=item){
        currentNode = currentNode->pNext;
        index++;
    }
    if (currentNode == NULL){
        return -1;
    }

    return index;
}

void deleteAtBegining(pListNode *first){
    pListNode pTempNode = NULL;

    /*Check if the list is empty*/
    if(first == NULL){
        return;
    }
    else{
        pTempNode = *first;
        /* Detach the child node from the current head and make the detached child the head */
        *first = (*first)->pNext;
        /*free the memory used by the first node*/
        free (pTempNode);

    }
}

char delete(pListNode *first, char value){
    pListNode pPreviousNode, pCurrentNode, pTempNode;

    /* Check the first element in the list because when searching this node will not be searched*/

    /* If character is found in the first node, delete it and return the character*/
    if(value == (*first)->value){
        pTempNode = *first;
        (*first) = (*first)->pNext;
        free(pTempNode);
        return value;
    }
    else{

        pPreviousNode = *first;
        pCurrentNode = (*first)->pNext;

        /* Search through the list to find the character*/
        while(pCurrentNode->pNext != NULL && pCurrentNode->value !=value){
            pPreviousNode = pCurrentNode;
            pCurrentNode = pCurrentNode->pNext;
        }

        /* If we did find something to delete,delete it */
        if(pCurrentNode != NULL){
            pTempNode = pCurrentNode;
            pPreviousNode->pNext = pCurrentNode->pNext;
            free(pTempNode);
            return value;
        }
    }

    return '\0'; /* Return the null character if the character was not found in the list */
}

void displayList(pListNode pCurrentItem){

    /* Check if the list is empty */
    if (pCurrentItem ==NULL){
        fputs("List is empty \n",stderr);
        return;
    }
    else{
        /* Iterate until end of the list*/
        while(pCurrentItem != NULL){
            printf("| %c ", pCurrentItem->value);
            pCurrentItem = pCurrentItem->pNext;
        }
    }
    fputs("|\n",stdout);
}

int isEmpty(pListNode first){
    return first == NULL;
}

pListNode find(pListNode first, char searchValue){
    
    /* Check if the list is empty */
    if (first ==NULL){
        fputs("List is empty \n",stderr);
        return NULL;
    }

    pListNode pCurrentNode = first;
    if(pCurrentNode->value == searchValue){
        return pCurrentNode;
    }else{
        while(pCurrentNode != NULL && pCurrentNode->value !=searchValue){
            pCurrentNode = pCurrentNode->pNext;
        }
        /* Check to confirm that we found the value we searched for*/
        if(pCurrentNode == NULL){
            puts("Not found!\n");
            return pCurrentNode; 
        }
    }

    return pCurrentNode;

}

int size(pListNode first){
    /* Check if the list is empty */
    if (first ==NULL){
        fputs("List is empty \n",stderr);
        return 0;
    }

    int size = 1;
    while (first->pNext != NULL)
    {
        size ++;
        first = first->pNext;
    }
    
    return size;
}

int concat(pListNode pHeadFirstList, pListNode pHeadSecondList){
    if(pHeadFirstList ==NULL || pHeadSecondList==NULL){
        exit(EXIT_FAILURE);
    }

    pListNode pCurrentNode = pHeadFirstList;
    while(pCurrentNode->pNext != NULL){
        pCurrentNode = pCurrentNode->pNext;
    }
    // now the pCurrentNode holds the last item in the list
    pCurrentNode->pNext = pHeadSecondList;

   return 0;
}

char at(pListNode pHead, int index){
    /* can be used for index 1-n. index at 0 returns the value stored in the head already passed
       to the function so it is unnecessary*/
    int count = size(pHead);
    if(index ==0){
        return pHead->value;
    }
    if (index > count){
        puts("Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
    /* Support for negative indexing */
    if(index<0){
        index = count + index;
    }

    // temporary count value
    int n=0;
    pListNode pPreviousNode;
    pListNode pCurrentNode = pHead;
    while(pCurrentNode !=NULL){
        if (n==index) break;
        pPreviousNode = pCurrentNode;
        pCurrentNode = pCurrentNode->pNext;
        n++;
    }

    return pPreviousNode->value;
}

int updateNode(pListNode *first, char oldvalue, char newvalue){
    // test the find operation
    pListNode temp = find(*first, oldvalue);
    if (temp ==NULL){
        return 1;
    }
    temp->value = newvalue;
    return 0;
}

// int main(void){
//     pListNode test = NULL;
//     insertAtBegining(&test, 'A');
//     insertAtBegining(&test, 'b');
//     insertAtBegining(&test, 'c');
//     insertAtBegining(&test, 'M');
//     insertAtBegining(&test, 'n');
//     insertAtBegining(&test, 'P');

//     (void)updateNode(&test, 'n', 'w');
//     displayList(test);

//     return 0;

// }