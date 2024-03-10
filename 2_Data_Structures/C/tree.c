#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

#define TREE_DEFAULT_VALUE 10

void PrintTreeItem(struct BSTNode* item); 

/* INITIALIZATION AND MEMORY FREE-ING FUNCTIONS */
struct BSTNode* InitializeBst(int value)
{
    struct BSTNode* node = (struct BSTNode*)malloc(sizeof(struct BSTNode)); 
    node->value = value; 
    node->left = NULL; 
    node->right = NULL; 

    return node; 
}

//recursive function
void FreeBst(struct BSTNode* tree)
{
    if(tree == NULL)
        return; 

    FreeBst(tree->left);
    FreeBst(tree->right);
    free(tree); 
}

/* BST FUNCTION IMPLEMENTATIONS */
// O(log2(n)) complexity - every time need to check left and right and find the right branch (and slot)
int InsertToBst(struct BSTNode* tree, int value)
{
    if(tree->value == value)
    {
        return -1; //we assume that no duplicates are accepted
    }
    
    //this should go to left
    if(value < tree->value)
    {
        if(tree->left != NULL)
            return InsertToBst(tree->left, value); 
        
        struct BSTNode* node = InitializeBst(value); 
        tree->left = node; 
    }

    //this should go to right
    if(value > tree->value)
    {
        if(tree->right != NULL)
            return InsertToBst(tree->right, value); 
        
        struct BSTNode* node = InitializeBst(value); 
        tree->right = node; 
    }
    return 0; 
}

int DeleteFromBst(struct BSTNode* tree, int value)
{
    return 0; 
} 
int SearchBst(struct BSTNode* tree, int value)
{
    return 0; 
}
int FindMinBst(struct BSTNode* tree)
{
    return 0; 
}
int FindMaxBst(struct BSTNode* tree)
{
    return 0; 
}

/* PRINT FUNCTIONS */
//In order traversal stands for left - middle - right
void PrintBstInOrder(struct BSTNode* tree)
{
    if(tree == NULL)
        return; 
    
    PrintBstInOrder(tree->left);
    PrintTreeItem(tree); 
    PrintBstInOrder(tree->right); 
}

//Pre order is when top element is visited first, followed by left and right consequtively
void PrintBstPreOrder(struct BSTNode* tree)
{
    if(tree == NULL)
        return; 
    
    PrintTreeItem(tree); 
    PrintBstPreOrder(tree->left);
    PrintBstPreOrder(tree->right); 
} 

void PrintBstPostOrder(struct BSTNode* tree)
{
    if(tree == NULL)
        return; 
    
    PrintBstPostOrder(tree->left);
    PrintBstPostOrder(tree->right); 
    PrintTreeItem(tree); 
}

/*DEMO*/
void RunBstInInteractiveMode(void)
{
    //this value will be over written when properly initializing the tree by the user...
    struct BSTNode* tree = InitializeBst(TREE_DEFAULT_VALUE); 
    //this flag will be set to 1 when the tree is initialized
    int hasTreeBeenInitializedByUser = 0; 
    
    int result = 0; 
    do{
        result = RunBstTreeInteractiveCycle(tree, hasTreeBeenInitializedByUser); 
        
        //this is rather a latched assignment, once the tree is initialized
        //it will always be there... (until full consumption)
        if(result == 1)
            hasTreeBeenInitializedByUser = 1; 
    }
    while (result != -1);
    
    FreeBst(tree); 
}

int RunBstTreeInteractiveCycle(struct BSTNode* tree, int hasTreeBeenInitializedByUser)
{
    printf("\n\n\nINTERACTIVE BINARY SEARCH TREE COMMANDS:\n"); 
    printf("[c] - for clearing the screen\n");
    printf("[0] - to print the tree with in-order traversal\n");
    printf("[1] - to print the tree with pre-order traversal\n");
    printf("[2] - to print the tree with post-order traversal\n");
    printf("[e] - to exit\n");
    printf("[+] - to add an element to the tree\n");
    printf("[-] - to remove an element from the tree\n");
    printf("[s] - to search an element in the tree\n");
    
    char command; 
    int value; 
    int result = 0; 
    int operationResult; 
    
    scanf(" %c", &command);
    // Process user input
        switch (command) {
            case 'c':
                system("cls"); 
                return 0;
            case '0':
                if(hasTreeBeenInitializedByUser == 0)
                {
                    printf("Please add elements to tree first...");
                    return 0; 
                }
                PrintBstInOrder(tree); 
                return 0;
            case '1':
                if(hasTreeBeenInitializedByUser == 0)
                {
                    printf("Please add elements to tree first...");
                    return 0; 
                }
                PrintBstPreOrder(tree); 
                return 0;
            case '2':
                if(hasTreeBeenInitializedByUser == 0)
                {
                    printf("Please add elements to tree first...");
                    return 0; 
                }
                PrintBstPostOrder(tree); 
                return 0;
            case 'e':
                return -1; 
            case '+':
                printf("\nEnter the integer to add to the tree: ");
                operationResult = scanf("%d", &value); 
                if(operationResult != 1)
                {
                    printf("Entered text cannot be parsed to an integer\n");
                    break;
                }
                if(hasTreeBeenInitializedByUser == 0)
                {
                    tree->value = value; 
                    return 1;   
                }
                operationResult = InsertToBst(tree, value); 
                if(operationResult != 0)
                {
                    printf("Failed to add\n");
                }
                return 0;
            case '-':
                if(hasTreeBeenInitializedByUser == 0)
                {
                    printf("Please add elements to tree first...");
                    return 0; 
                }
                printf("\nEnter the integer to remove from the list: ");
                operationResult = scanf("%d", &value); 
                if(operationResult != 1)
                {
                    printf("Entered text cannot be parsed to an integer\n");
                    break;
                }
                operationResult = DeleteFromBst(tree, value); 
                if(operationResult != 0)
                {
                    printf("Failed to remove\n");
                }
                return 0;
            case 's':
                if(hasTreeBeenInitializedByUser == 0)
                {
                    printf("Please add elements to tree first...");
                    return 0; 
                }
                printf("\nEnter the integer to search in the tree: ");
                operationResult = scanf("%d", &value); 
                if(operationResult != 1)
                {
                    printf("Entered text cannot be parsed to an integer\n");
                    break;
                }
                operationResult = SearchBst(tree, value); 
                if(operationResult != 0)
                {
                    printf("Failed to remove\n");
                }
                return 0;
            default:
                printf("Invalid command\n");
                return 0;
        }

    return 0; 
}

/* "PRIVATE" methods */
void PrintTreeItem(struct BSTNode* item)
{
    printf("\n{value: %d, addres: %p}\n", item->value, (void*)item);
}