#include <stdio.h>
#include "stack.h"

void InitializeStack(int value, struct Stack* stack)
{
    printf("Initializing the stack\n"); 
    stack = (struct Stack*)malloc(sizeof(struct Stack));
    *(stack->value) = value;
    stack->next = NULL;
    printf("Initialized the stack with value %d \n", *(stack->value)); 
    PrintStack(&stack); 
}

void InitializeStackList(struct StackList* stackList)
{
    printf("Initializing the stack list\n"); 
    stackList = (struct StackList*)malloc(sizeof(struct StackList));
    stackList->head = NULL; 
    stackList->count = 0; 
    printf("Initialized the stack list with count %d \n", stackList->count); 
}

struct Stack* Pop(struct StackList* list)
{
    if(list->head == NULL)
        return NULL; 

    struct Stack* stack = list->head;

    list->head = list->head->next;
    list->count = list->count - 1; 

    return stack; 
}

void Push(struct StackList* list, struct Stack** stack)
{
    struct Stack* stackToPush = *stack; 
    PrintStack(stack); 
    int currentValue; 
    struct Stack** head = &(list->head); 

    if(head == NULL)
        currentValue=0; 
    else
        currentValue = list->head->value; 

    printf("Pushing stack with value %d to list with head value of %d\n", *(stackToPush->value), currentValue); 
    
    stackToPush->next = list->head; 
    printf("List head value is %d", list->head->value); 

    list->head = stack; 
    list->count = list->count + 1; 
    printf("Pushed"); 
}

void Print(struct StackList* list)
{
    printf("Stack count: %d \n", list->count); 

    struct Stack* head = list->head;
    int i = 1; 
    while(head != NULL)
    {
        printf("%d'st element with value: %d\n", i, head->value); 
        i = i+1;
        head = head->next; 
    }
    puts("Finished printing the stack\n"); 
}

void PrintStack(struct Stack** stack)
{
    struct Stack* stackToPrint = *stack;
    struct Stack address = *stackToPrint; 
    printf("stack address %d size:%d", address, sizeof(struct Stack)); 
    int doesNextExist;
    if(stackToPrint->next == NULL)
        doesNextExist = 0; 
    else
        doesNextExist = 1; 

    int value = 0; 
    if(stackToPrint->value == NULL)
        value = 0; 
    else
        value = *(stackToPrint->value); 


    printf("Stack - value: %d; doesNextElementExist: %d\n", value, doesNextExist); 
}