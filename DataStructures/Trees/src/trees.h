/**
 * @file trees.h
 * @author codeybank (ezeh.stanley.es@gmail.com)
 * @brief drivers for binary trees
 * @version 0.1
 * @date 2023-08-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/* Tree structure
                            Root
                             /\
                            /  \
                         Left   Right
                          /\    /\
                         /  \  /  \
                        /   NULL   \
                    NULL          NULL

*/

struct treeNode{
    int data; /* Can be changed to any datatype of choice*/
    struct treeNode *pLeft; /* Pointer to the left subtree*/
    struct treeNode *pRight; /* Pointer to the right subtree*/
};

typedef struct  treeNode tree_t;
typedef tree_t * pTree_t;

/* Function prototypes */
/**
 * @brief 
 * 
 * @param pTree Pointer to the ROOT of the tree node
 * @param data Data to be inserted
 */
void insertNode( pTree_t *pTree, int data);

/**
 * @brief Traverse the nodes in the tree inOrder. Left->Root->Right
 * 
 * @param Tree  Tree structure
 */
void TraverseInOrder(pTree_t Tree);

/**
 * @brief Traverse the nodes in the tree inOrder. Root->Left->Right
 * 
 * @param Tree  Tree structure
 */
void TraversePreOrder(pTree_t Tree);

/**
 * @brief Traverse the nodes in the tree inOrder. Left->Right->Root
 * 
 * @param Tree  Tree structure
 */
void TraversePostOrder(pTree_t Tree);

