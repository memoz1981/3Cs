#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

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
void PrintBstInOrder(struct BSTNode* tree)
{
    if(tree == NULL)
        return; 

    printf("%d\n", tree->value);
    PrintBstInOrder(tree->left);
    PrintBstInOrder(tree->right); 

}
void PrintBstPreOrder(struct BSTNode* tree)
{
    return ; 
} 
void PrintBstPostOrder(struct BSTNode* tree)
{
    return; 
}

/*DEMO*/
void RunBstInInteractiveMode(void)
{
    struct BSTNode* tree = NULL; 
    int result; 
    do{
        result = RunBstTreeInteractiveCycle(tree); 
    }
    while (result != -1);
    
    FreeBst(tree); 
}

int RunBstTreeInteractiveCycle(struct BSTNode* tree)
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
    if(command != '+' && command != 'c' && command == 'e' && tree == NULL)
    {
        printf("First add a value to tree to initialize"); 
        return 0; 
    }
    // Process user input
        switch (command) {
            case 'c':
                system("cls"); 
                break;
            case '0':
                PrintBstInOrder(tree); 
                break;
            case '1':
                PrintBstPreOrder(tree); 
                break;
            case '2':
                PrintBstPostOrder(tree); 
                break;
            case 'e':
                return -1; 
                break;
            case '+':
                
                printf("\nEnter the integer to add to the tree: ");
                operationResult = scanf("%d", &value); 
                if(operationResult != 1)
                {
                    printf("Entered text cannot be parsed to an integer\n");
                    break;
                }
                if(tree == NULL)
                {
                    tree = InitializeBst(value);
                    break;  
                }
                operationResult = InsertToBst(tree, value); 
                if(operationResult != 0)
                {
                    printf("Failed to add\n");
                }
                break;
            case '-':
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
                break;
            case 's':
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
                break;
            default:
                printf("Invalid command\n");
                break; 
        }

    return result; 
}