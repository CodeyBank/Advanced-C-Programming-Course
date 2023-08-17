/**
 * @file linkedlist.h
 * @author codeybank (ezeh.stanley.es@gmail.com)
 * @brief Header file for the linkedlist library
 * @version 0.1
 * @date 2023-08-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#pragma once


typedef struct node{
    char value;
    struct node * pNext;
}node_t;

// simplify
typedef node_t * pListNode;

/**
 * @brief Inserts element at the begining of a list structure
 * 
 * @param first pointer to the head of the list
 * @param item value to be inserted at the begining
 */
void insertAtBegining(pListNode *first, char item);

/**
 * @brief Inserts element at the end of a list structure
 * 
 * @param first Pointer to the head of the list
 * @param item Value to be inserted at the end of the list
 * @return int 0 for success and 1 for failure
 */
int insertAtEnd(pListNode *first, char item);

/**
 * @brief Inserts element alphabetically. Element is placed in a slot in ascending order
 * 
 * @param first Pointer to the head of the list
 * @param item value to be inserted into the list
 * @return int returns 0 for success and 1 for failure
 */
int insert(pListNode *first, char item);

/**
 * @brief Removes the first item in a list
 * 
 * @param first Pointer to the first item on the list
 */
void deleteAtBegining(pListNode *first);

/**
 * @brief Deletes specified value from the list
 * @param first Pointer to the head of the list
 * @param value Value to be deleted
 * @return char Returns value deleted
 */
char delete(pListNode *first, char value);

/**
 * @brief Prints out the content of the list to the console starting
 *        from the current item
 *
 * @param pCurrentItem Pointer indicating where the printing should start
 */
void displayList(pListNode pCurrentItem);

/**
 * @brief Checks if the list is empty
 * 
 * @param first Pointer to the first item on the list
 * @return int 0-Success 1-failure
 */
int isEmpty(pListNode first);

/**
 * @brief Finds an element in a list
 * 
 * @param first Pointer to the first element in the list
 * @param searchValue Value to be searched for in the list
 * @return pListNode returns the list object with the value searched for
 */
pListNode find(pListNode first, char searchValue);

/**
 * @brief Find the index of an element
 * 
 * @param first List structure to be searched
 * @param item Item in the list to be searched
 * @return int returns index to the element if found. else returns -1
 */
int findItem(pListNode first, char item);

/**
 * @brief 
 * 
 * @param first 
 * @return int 
 */
int size(pListNode first);

/**
 * @brief Concatenates two lists. The second list is joined to the first
 *        list. To see the concatenated list, display the first list.
 *  
 * @param pHeadFirstList Pointer to the first list
 * @param pHeadSecondList Pointer to the second list
 * @return int 0-success 1-failure
 */
int concat(pListNode pHeadFirstList, pListNode pHeadSecondList);

/**
 * @brief returns the value stored in the list structure at given index
 * 
 * @param pHead Pointer to the head of the list
 * @param index Index of element to be searched for 
 * @return char character stored in the list structure at given index
 */
char at(pListNode pHead, int index);