#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "list.h"

void ResizeListArrayAndCopyElements(struct List* list); 
int RunListInteractiveCycle(struct List* list, char* dataTypeName); 
void PrintInt(void* pointer, int index);
void PrintFloat(void* pointer, int index);
void PrintString(void* pointer, int index);
void PrintChar(void* pointer, int index);
enum Type ReturnTypeForChar(char tp);
void AddElement(struct List* list, char* dataTypeName);
char* ReturnDataTypeName(enum Type type);

/* INITIALIZATION AND MEMORY FREE-ING FUNCTIONS */
struct List* InitializeList(enum Type type)
{
    /* Firt initialize the parent data type for the list */
    struct List* list = (struct List*)malloc(sizeof(struct List)); 
    
    list->lastIndex = 0; 
    list->arraySize = DEFAULT_LIST_SIZE;
    list->type = type; 
    list->array = (void**)malloc(list->arraySize * sizeof(void*)); 
    
    printf("\nInitialized - last index: %d, array size: %d, type : %d", 
        list->lastIndex, list->arraySize, list->type);
    
    return list; 
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
    //Will be printed for all lists
    printf("\nList-last index: %d; size: %d; type : %d; array: ", 
        list->lastIndex, list->arraySize, list->type);
    
    //if no elements exist - return
    if(list->lastIndex == 0)
        return; 
    
    for(int i = 0; i < list->lastIndex; i++)
    {
        switch(list->type)
        {
            case _integer:
            PrintInt(list->array[i], i); 
            break; 

            case _float:
            PrintFloat(list->array[i], i); 
            break; 

            case _string:
            PrintString(list->array[i], i); 
            break; 

            case _char:
            PrintChar(list->array[i], i); 
            break; 

            default:
            printf("Unsupported type...");
            break; 
        }
        
        printf(" -> ");
    }
    printf("NULL");
}

void PrintInt(void* pointer, int index)
{
    int* intPtr = (int*)pointer; 
    printf("{value: %d, index: %d, address: %p}", *intPtr, index, pointer); 
}

void PrintFloat(void* pointer, int index)
{
    float* fltPtr = (float*)pointer; 
    printf("{value: %f, index: %d, address: %p}", *fltPtr, index, pointer); 
}

void PrintString(void* pointer, int index)
{
    char* strPtr = (char*)pointer; 
    printf("{value: %s, index: %d, address: %p}", *strPtr, index, pointer); 
}

void PrintChar(void* pointer, int index)
{
    char* charPtr = (char*)pointer; 
    printf("{value: %c, index: %d, address: %p}", *charPtr, index, pointer);
}

void AddToList(struct List* list, void* value)
{
    //if current array if full, double array size
    if(list->lastIndex >= list->arraySize - 1)
    {
        ResizeListArrayAndCopyElements(list); 
    }

    int index = list->lastIndex; 
    list->array[index] = value; 
    list->lastIndex++;
    return; 
}

void RunListInInteractiveMode(void)
{
    system("cls"); 

    printf("Enter [1] for integer type, [2] for float, [3] for string, [4] for char type.");
    char value[5];
    fgets(value, 4, stdin); 
    char tp = value[0]; 
    enum Type type = ReturnTypeForChar(tp); 
    struct List* list = InitializeList(type); 
    char* dataTypeName = ReturnDataTypeName(type);

    printf("Running list in interactive mode for data type %s", dataTypeName); 
    
    int result = 0; 
    do{
        result = RunListInteractiveCycle(list, dataTypeName); 
    }
    while (result != -1);
    
    FreeList(list); 
}

char* ReturnDataTypeName(enum Type type)
{
    if(type == _integer)
        return "integer";
    else if(type == _float)
        return "float";
    else if(type == _string)
        return "string";
    else if(type == _char)
        return "char";
    else
        exit(-1); 
}

enum Type ReturnTypeForChar(char tp)
{
    if(tp == '1')
        return _integer;
    else if(tp == '2')
       return _float; 
    else if(tp == '3')
        return _string; 
    else if(tp == '4')
        return _char; 
    else
        exit(-1); 
}


/* "PRIVATE" methods */
void ResizeListArrayAndCopyElements(struct List* list)
{
    //define new array as twice the size of current list
    void** resizedArray = (void**)malloc(list->arraySize * 2 * sizeof(void*)); 

    //copy all list elements to the new array
    for(int i = 0; i < list->lastIndex; i++)
    {
        resizedArray[i] = list->array[i];
    }

    //assign list array to temp
    void** temp = list->array; 

    //assign new array to list and update list array size
    list->array = resizedArray; 
    list->arraySize = list->arraySize * 2; 

    //free memory for old array and return
    free(temp); 
}

int RunListInteractiveCycle(struct List* list, char* dataTypeName)
{
    printf("\n\n\nINTERACTIVE LIST COMMANDS:\n"); 
    printf("[c] - for clearing the screen\n");
    printf("[p] - to print the list\n");
    printf("[e] - to exit\n");
    printf("[+] - to add an element to the list\n");
    printf("[-] - to remove an element from the list\n");
    printf("[s] - to search an element in the list\n");
    
    char commandText[10];
    memset(commandText,'\0', 10);  
    char command; 
    int operationResult; 
    
    fgets(commandText, 10, stdin);
    command = commandText[0]; 

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
                AddElement(list, dataTypeName); 
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

void AddElement(struct List* list, char* dataTypeName)
{
    printf("\nEnter the %s to add to the list: ", dataTypeName);

    if(list->type == _integer)
    {
        int* intPtr = (int*)malloc(sizeof(int)); 
        int result = scanf("%d", intPtr);
        if(result != 1)
            exit(-1); 
        AddToList(list, intPtr); 
    }

    else if(list->type == _float)
    {
        float* fltPtr = (float*)malloc(sizeof(float)); 
        float result = scanf("%f", fltPtr);
        if(result != 1)
            exit(-1); 
        AddToList(list, fltPtr); 
    }

    else if(list->type == _string)
    {
        char* ptr = (char*)malloc(10 * sizeof(char)); 
        memset(ptr, '\0', 10); 
        int result = scanf("%9s", ptr);
        if(result != 1)
            exit(-1); 
        AddToList(list, ptr); 
    }

    else if(list->type == _string)
    {
        char* ptr = (char*)malloc(sizeof(char)); 
        int result = scanf("%c", ptr);
        if(result != 1)
            exit(-1); 
        AddToList(list, ptr); 
    }
    
    else
        exit(EXIT_FAILURE); 
}