/**
 * @file testLinkedList.c
 * @author codeybank (ezeh.stanley.es@gmail.com)
 * @brief Use this file to test the functions in the Linkedlist Library
 * @version 0.1
 * @date 2023-08-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "linkedlist.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void displayOptions(void){
    printf("\n---------------------------------\n");
    printf("\nOperations on a linked list\n");
    printf("\n---------------------------------\n");
    printf("\n1.Insert node at beginning");
    printf("\n2.Insert node at end");
    printf("\n3.Insert node at a specific position alphabetically");
    printf("\n4.Delete Node from any Position");
    printf("\n5.Delete node at begining");
    printf("\n6.Search Element in the linked list");
    printf("\n7.Display List");
    printf("\n8.Is list empty?");
    printf("\n9.What is the size of the list?");
    printf("\n10.What character is at position?");
    printf("\n11.Concatenate two lists");
    printf("\n12.Exit\n");
    printf("\n0.Show menu again");
    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

int main(void)
{
    int ch = '\0';
    char item = '\0';
    pListNode firstList = NULL, secondList = NULL;
    displayOptions();

    while (true)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            printf("Item to insert at begining? ");
            scanf(" %c", &item);
            insertAtBegining(&firstList, item);
            break;
        }

        case 2:
            fflush(stdin);
            printf("Item to insert at end?");
            scanf(" %c", &item);
            insertAtEnd(&firstList, item);
            break;
        case 3:
            fflush(stdin);
            printf("Item to insert alphabetically?");
            scanf(" %c", &item);
            insert(&firstList, item);
            break;
        case 4:
            fflush(stdin);
            printf("Item to delete from list?");
            scanf(" %c", &item);
            delete (&firstList, item);
            break;
        case 5:
            printf("Delete first item in the list");
            deleteAtBegining(&firstList);
            break;
        case 6:
            fflush(stdin);
            printf("What element are you looking for?");
            scanf(" %c", &item);
            int i = findItem(firstList, item);
            printf("The element is %s at index %d", i < 0 ? "NOT Found!" : "found",
                   i);
            break;
        case 7:
            displayList(firstList);
            break;
        case 8:
            printf("\n...Exiting...\n");
            return 0;

        case 9:
            isEmpty(firstList);
            break;
        case 10:
            printf("What position do you want to check?");
            scanf("%d", item);
            printf("Element in %d is %c", item, at(firstList, item));
            break;
        case 0:
            displayOptions();
            break;

        default:
            printf("\n...Invalid Choice...\n");
            break;
        }

    }

    return 0;
}
