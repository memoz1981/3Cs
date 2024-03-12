#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/*Normally this value is higher, assigned 4 for easy testability */
#define DEFAULT_LIST_SIZE 4 

typedef struct GenericList
{
    int count; 
    int arraySize; 
    struct GenericListValue** array; 
};

typedef struct GenericListValue
{
    void* value; 
};

struct GenericList* InitializeGenericList(); 

void AddToGenericList(struct GenericList* list, void* value); 

void PrintGenericList(struct GenericList* list); 

void FreeGenericList(struct GenericList* list); 

void RunGenericListInInteractiveMode(void);
