#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "list.h"

/* INITIALIZATION AND MEMORY FREE-ING FUNCTIONS */
struct List* InitializeList(enum Type type)
{
    /* Firt initialize the parent data type for the list */
    struct List* list = (struct List*)malloc(sizeof(struct List)); 
    
    list->lastIndex = 0; 
    list->arraySize = DEFAULT_LIST_SIZE;
    list->type = type; 
    list->array = (void**)malloc(sizeof(void*)); 

    for(int i = 0; i < list->arraySize; i++)
    {
        list->array[i] = NULL; 
    }
    
    printf("Initialized list with following details: last index: %d, array size %d", 
        list->lastIndex, list->arraySize);
}

void FreeList(struct List* list)
{
    for(int i=0; i < list->lastIndex; i++)
    {
        free(list->array[i]); 
    }
    
    free(list->array);
    
    free(list);
}

void PrintList(struct List* list)
{
    printf("\nList - size: %d, last index: ", list->arraySize, list->lastIndex); 

    for(int i = 0; i < list->lastIndex; i++)
    {
        PrintInt(list->array[i]); 
        printf(" -> ");
    }
    printf("NULL");
}

void PrintInt(void* pointer)
{
    int number = (int)pointer; 
    printf("{value: %d, address: %p}", number, pointer); 
}

void AddToList(struct List* list, void* value)
{
    int index = list->lastIndex; //initial implementation
    list->array[index] = value; 
    list->lastIndex++;
}

void RunListInInteractiveMode(void)
{
    struct List* list = InitializeList(_integer); 
    
    int result = 0; 
    do{
        printf("\nrecursive function returned %d\n", result); 
        result = RunListInteractiveCycle(list); 
    }
    while (result != -1);
    
    FreeList(list); 
}

int RunListInteractiveCycle(struct List* list)
{
    printf("\n\n\nINTERACTIVE GENERIC LIST COMMANDS (integer based):\n"); 
    printf("[c] - for clearing the screen\n");
    printf("[p] - to print the list\n");
    printf("[e] - to exit\n");
    printf("[+] - to add an element to the list\n");
    printf("[-] - to remove an element from the list\n");
    printf("[s] - to search an element in the list\n");
    
    char command; 
    int value; 
    int result = 0; 
    int operationResult; 
    
    scanf(" %c\n", &command);
    printf("received %c", command); 
    // Process user input
        switch (command) {
            case 'c':
                system("cls"); 
                return 0;
            case 'p':
                PrintList(list); 
                return 0;
            case 'e':
                return -1; 
            case '+':
                printf("\nEnter the integer to add to the list: ");
                operationResult = scanf("%d", &value); 
                if(operationResult != 1)
                {
                    printf("Entered text cannot be parsed to an integer\n");
                    break;
                }
                int* value = (int)malloc(sizeof(int)); 
                AddToList(list, value); 
                return 0;
            case '-':
                return 0;
            case 's':
                return 0;
            default:
                printf("Invalid command\n");
                return 0;
        }

    return 0; 
}