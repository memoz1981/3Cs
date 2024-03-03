#include <stdio.h>
#include "stack.h"

struct Stack* InitializeStack(int value)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    
    stack->value = value;
    stack->next = NULL;

    return stack; 
}

void Free(struct Stack* stack)
{
    free(stack); 
}

struct StackWrapper* InitializeStackWrapper()
{
    struct StackWrapper* wrapper = (struct StackWrapper*)malloc(sizeof(struct StackWrapper));
    *(wrapper->top) = NULL; 
    wrapper->count = 0; 

    return wrapper; 
}

void FreeWrapper(struct StackWrapper* wrapper)
{
    free(wrapper); 
}


void Push(struct StackWrapper* wrapper, struct Stack* stack)
{
    if(*(wrapper->top) == NULL)
    {
        stack->next = NULL; 
        *(wrapper->top) = stack; 
        wrapper->count = 1; 
        return; 
    }

    stack->next = *(wrapper->top); 
    *(wrapper->top) = stack; 
    wrapper->count++; 
}

struct Stack* Pop(struct StackWrapper* wrapper)
{
    if(*(wrapper->top) == NULL)
        return NULL; 

    struct Stack* top = *(wrapper->top); 
    *(wrapper->top) = top->next;  

    return top; 
}

void PrintWrapper(struct StackWrapper* wrapper)
{
    printf("\nList is being printed with count of %d", wrapper->count);
    struct Stack* stack = *(wrapper->top);

    while(stack)
    {
        PrintStack(stack); 
        stack = stack->next;
    }
    printf("\nList print complete"); 
} 

void PrintStack(struct Stack* stack)
{
    int nextvalue = -1;
    if(stack->next)
    {
        nextvalue = stack->next->value; 
    }

    printf("\nStack value %d and address %p and next value is %d\n", stack->value, (void*)(&stack), nextvalue); 
}

int Size(struct StackWrapper* wrapper)
{
    if(!wrapper)
        return -1; 

    return wrapper->count; 
}

struct Stack* Peek(struct StackWrapper* wrapper)
{
    if(*(wrapper->top) == NULL)
        return NULL; 

    return *(wrapper->top); 
}

int isEmpty(struct StackWrapper* wrapper)
{
    if(!wrapper)
        return -1; 

    return wrapper->count == 0; 
}

