#include <stdio.h>
#include "stack.h"

/*
gcc.exe -o 2_data_structures.exe -w main.c stack.c -> -w will hide the warning messages...
.\2_data_structures.exe
*/

void run_stack_test(void);

int main()
{
    run_stack_test(); 
    return 0; 
}

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

    printf("Wrapper size: %d", Size(wrapper));
    printf("Wrapper is empty: %d", isEmpty(wrapper)); 
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

