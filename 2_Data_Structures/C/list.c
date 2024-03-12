#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "list.h"

struct GenericListValue** InitializeListArray(int size);
/* INITIALIZATION AND MEMORY FREE-ING FUNCTIONS */
struct GenericList* InitializeGenericList()
{
    struct GenericList* list = (struct GenericList*)malloc(sizeof(struct GenericList)); 
    
    list->count = 0; 
    list->arraySize = DEFAULT_LIST_SIZE;
    list->array = InitializeListArray(list->arraySize); 
    printf("Initialized list with following details: count: %d, array size %d", 
        list->count, list->arraySize);
}

/* "PRIVATE" methods */
struct GenericListValue** InitializeListArray(int size)
{
    return (struct GenericListValue**)malloc(size * sizeof(struct GenericListValue));
}

void FreeGenericList(struct GenericList* list)
{
    for(int i=0; i<list->count; i++)
    {
        struct GenericListValue* element = list->array[i];
        void* value = element->value; 
        free(value); 
        element->value = NULL; 
    }
    free(list->array);
    free(list);
}

void PrintGenericList(struct GenericList* list)
{
    printf("\nList - size: %d, count: ", list->arraySize, list->count); 

    for(int i = 0; i < list->count; i++)
    {
        struct GenericListValue* element = list->array[i]; 
        PrintValue(element); 
        printf(" -> ");
    }
    printf("NULL");
}

void PrintValue(struct GenericListValue* element)
{
    printf("{value: %d, address: %p}", element, element); 
}

void AddToGenericList(struct GenericList* list, void* value)
{
    int size = list->count; //initial implementation
    list->array[size]->value = value; 
    list->count++;
}

void RunGenericListInInteractiveMode(void)
{
    struct GenericList* list = InitializeGenericList(); 
    
    int result = 0; 
    do{
        result = RunGenericListInteractiveCycle(list); 
        
    }
    while (result != -1);
    
    FreeGenericList(list); 
}

int RunGenericListInteractiveCycle(struct GenericList* list)
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
    
    scanf(" %c", &command);
    // Process user input
        switch (command) {
            case 'c':
                system("cls"); 
                return 0;
            case 'p':
                PrintGenericList(list); 
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
                AddToGenericList(list, value); 
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