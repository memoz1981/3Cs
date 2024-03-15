#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Normally this value is higher, assigned 4 for easy testability */
#define DEFAULT_LIST_SIZE 4 

enum Type
{
    _integer, _float, _string, _char
}; 

typedef struct List
{
    int lastIndex; 
    size_t arraySize; 
    void** array; 
    enum Type type; 
};

struct List* InitializeList(enum Type type); 

void FreeList(struct List* list); 

void AddToList(struct List* list, void* value); 

void PrintList(struct List* list); 

void RunListInInteractiveMode(void);

int RemoveAtIndex(int index); 
