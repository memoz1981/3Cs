#include <stdio.h>
#include "stack.h"

struct Stack* InitializeStack(int value);
void PrintStackItem(struct Stack* stack);

/* INITIALIZATION AND MEMORY FREE-ING FUNCTIONS */
struct StackWrapper* InitializeStackWrapper()
{
    struct StackWrapper* wrapper = (struct StackWrapper*)malloc(sizeof(struct StackWrapper));
    
    if (wrapper == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    
    wrapper->top = NULL; 
    wrapper->count = 0; 

    return wrapper; 
}

void FreeStackWrapper(struct StackWrapper* wrapper)
{
    struct Stack* current = wrapper->top; 
    
    while (current != NULL) {
        struct Stack* temp = current;
        current = current->next;
        printf("\nFreeing following stack item: "); 
        PrintStackItem(temp);
        free(temp);
    }
    
    printf("\nFreeing wrapper\n"); 
    free(wrapper); 
}

/* STACK FUNCTION IMPLEMENTATIONS */

void PushToStack(struct StackWrapper* wrapper, int value)
{
    struct Stack* stack = InitializeStack(value); 
    wrapper->count++;

    if(wrapper->top == NULL)
    {
        wrapper->top = stack; 
        return; 
    }

    stack->next = wrapper->top; 
    wrapper->top = stack; 
}

int PopFromStack(struct StackWrapper* wrapper)
{
    if(wrapper->top == NULL)
        return -1; 
    
    wrapper->count--;
    int value = wrapper->top->value; 
    struct Stack* temp =  wrapper->top;
    wrapper->top = wrapper->top->next; 
    free(temp); 

    return value; 
}

int PeekFromStack(struct StackWrapper* wrapper)
{
    if(wrapper->top == NULL)
        return -1; 
 
    return wrapper->top->value; 
}

int StackSize(struct StackWrapper* wrapper)
{
    if(!wrapper)
        return -1; 

    return wrapper->count; 
}

int isStackEmpty(struct StackWrapper* wrapper)
{
    if(!wrapper)
        return -1; 

    return wrapper->count == 0; 
}

/* PRINT FUNCTIONS */

void PrintStack(struct StackWrapper* wrapper)
{
    struct Stack* iterator = wrapper->top;
    printf("\nStack Wrapper: "); 
    if(wrapper->top == NULL)
    {
        printf("NULL\n"); 
        return; 
    }
    for(int i=0; i<wrapper->count; i++)
    {
        PrintStackItem(iterator); 
        printf(" -> "); 
        iterator = iterator->next;
    }
    printf("NULL\n"); 
} 

/* STACK DEMO */
void RunStackInInteractiveMode(void)
{
    printf("running interactive"); 
    struct StackWrapper* wrapper = InitializeStackWrapper(); 
    int result; 
    do{
        result = RunStackInteractiveCycle(wrapper); 
    }
    while (result != -1);
    
    FreeStackWrapper(wrapper); 
}

int RunStackInteractiveCycle(struct StackWrapper* wrapper)
{
    printf("\n\n\nINTERACTIVE STACK COMMANDS:\n"); 
    printf("[c] - for clearing the screen\n");
    printf("[r] - to print the stack\n");
    printf("[e] - to exit\n");
    printf("[+] - to push integer to the stack\n");
    printf("[d] - to pop\n");
    printf("[p] - to peek\n");
    printf("[s] - to print stack count\n");
    
    char command; 
    int value; 
    int result = 0; 
    
    scanf(" %c", &command);
    printf("received %c\n", command); 
    // Process user input
        switch (command) {
            case 'c':
                system("cls"); 
                break;
            case 'r':
                PrintStack(wrapper); 
                break;
            case 'e':
                return -1; 
                break;
            case 'd':
                int removed = PopFromStack(wrapper); 
                printf("Popped %d", removed); 
                break;
            case 'p':
                int peeked = PeekFromStack(wrapper);
                printf("Peeked %d", peeked); 
                break;
            case 's':
                int stackCount = StackSize(wrapper);
                printf("Stack count is: %d\n", stackCount);
                break;
            case '+':
                printf("\nEnter the integer to push to the stack: ");
                scanf("%d", &value); 
                PushToStack(wrapper, value);
                break;
            default:
                printf("Invalid command\n");
                break; 
        }

    return result; 
}

/* "PRIVATE" METHODS */
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

void PrintStackItem(struct Stack* stack)
{
    if(stack == NULL)
        printf("NULL STACK"); 
    
    printf("{value: %d, address: %p}",  stack->value, (void*)(stack)); 
}
