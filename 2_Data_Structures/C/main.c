#include <stdio.h>
#include "stack.h"

/*
gcc.exe -o 2_data_structures.exe -w main.c stack.c -> -w will hide the warning messages...
.\2_data_structures.exe
*/

int main()
{
    struct Stack* stack[5];  
    struct StackWrapper* wrapper; 
    //Initialization
    for(int i=0; i<5; i++)
    {
        stack[i] = InitializeStack(i); 
    }

    for(int i = 0; i < 5; i++)
    {
        if(stack[i])
        {
            PrintStack(stack[i]); 
        }
        else
        {
            printf("Stack %d is empty", i); 
        }
    }
    
    wrapper = InitializeStackWrapper(); 
    printf("Wrapper initialized\n"); 
    
    //Actions
    Push(wrapper, stack[0]); 
    Push(wrapper, stack[1]); 
    Push(wrapper, stack[2]); 
    Push(wrapper, stack[3]); 
    struct Stack* popped = Pop(wrapper); 
    Push(wrapper, stack[4]);
    
    PrintWrapper(wrapper); 

    FreeWrapper(wrapper); 

    for(int i=0; i<5; i++)
    {
        Free(stack[i]);  
    }
 
    return 0; 
}

