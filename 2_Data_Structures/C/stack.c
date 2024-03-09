#include <stdio.h>
#include "stack.h"

/* INITIALIZATION AND MEMORY FREE-ING FUNCTIONS */
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
    *(wrapper->top) = NULL; 
    free(wrapper); 
}

/* STACK FUNCTION IMPLEMENTATIONS */

void Push(struct StackWrapper* wrapper, struct Stack* stack)
{
    printf("Pushing stack with value of %d to wrapper\n", stack->value); 
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
    {
        printf("Popped null stack from wrapper\n");
        return NULL;  
    }

    struct Stack* top = *(wrapper->top); 
    *(wrapper->top) = top->next;  
    
    printf("Popped stack with value of %d to wrapper\n", top->value); 
    wrapper->count--; 
    return top; 
}

struct Stack* Peek(struct StackWrapper* wrapper)
{
    if(*(wrapper->top) == NULL)
    {
        printf("Peeked null stack from wrapper\n");
        return NULL; 
    }

    printf("Peeked stack with value of %d from wrapper\n", (*(wrapper->top))->value); 
    return *(wrapper->top); 
}

int Size(struct StackWrapper* wrapper)
{
    if(!wrapper)
        return -1; 

    return wrapper->count; 
}

int isEmpty(struct StackWrapper* wrapper)
{
    if(!wrapper)
        return -1; 

    return wrapper->count == 0; 
}

/* PRINT FUNCTIONS */

void PrintWrapper(struct StackWrapper* wrapper)
{
    printf("\nWrapper is being printed with count of %d\n", wrapper->count);
    struct Stack* stack = *(wrapper->top);

    while(stack)
    {
        PrintStack(stack); 
        stack = stack->next;
    }
    printf("\nWrapper print complete\n"); 
} 

void PrintStack(struct Stack* stack)
{
    if(stack == NULL)
    printf("Stack is NULL\n"); 
    int nextvalue = -1;
    if(stack->next)
    {
        nextvalue = stack->next->value; 
    }

    printf("\nStack value %d and address %p and next value is %d\n", stack->value, (void*)(&stack), nextvalue); 
}

/* STACK DEMO */
void run_stack_test(void)
{
    printf("Defining stack array of 5 elements\n"); 
    struct Stack* stack[5];  
    printf("Defining stack wrapper\n");
    struct StackWrapper* wrapper; 
    
    //Initialization
    printf("Stacks are being initialized\n"); 
    for(int i=0; i<5; i++)
    {
        stack[i] = InitializeStack(i); 
        PrintStack(stack[i]); 
    }
    
    printf("Stack Wrapper is being initialized\n"); 
    wrapper = InitializeStackWrapper(); 
    PrintWrapper(wrapper); 
    printf("Wrapper size: %d\n", Size(wrapper));
    printf("Wrapper is empty: %d\n", isEmpty(wrapper)); 
    Peek(wrapper); 

    //Actions
    Push(wrapper, stack[0]); 
    Push(wrapper, stack[1]); 
    Push(wrapper, stack[2]); 
    Push(wrapper, stack[3]); 
    struct Stack* popped1 = Pop(wrapper); 
    Push(wrapper, stack[4]);
    struct Stack* popped2 = Pop(wrapper); 

    printf("Wrapper size: %d\n", Size(wrapper));
    printf("Wrapper is empty: %d\n", isEmpty(wrapper)); 
    Peek(wrapper); 
    
    PrintWrapper(wrapper); 
    FreeWrapper(wrapper); 

    for(int i=0; i<5; i++)
    {
        Free(stack[i]);  
    }
    
    printf("Free-ing complete"); 
    return; 
}