#include <stdio.h>
#include "stack.h"

/*
gcc.exe -o 2_data_structures.exe -w main.c stack.c -> -w will hide the warning messages...
.\2_data_structures.exe
*/

int main()
{
    struct Stack stack1, stack2, stack3, stack4, stack5;  
    struct StackList list; 
    //Initialization
    InitializeStack(1, &stack1); 
    InitializeStack(2, &stack2); 
    InitializeStack(3, &stack3); 
    InitializeStack(4, &stack4); 
    InitializeStack(5, &stack5); 
    InitializeStackList(&list); 

    //Actions
    Push(&list, &stack1); 
    Push(&list, &stack2); 
    Push(&list, &stack3); 
    Push(&list, &stack4); 
    Push(&list, &stack5);
    Print(&list);  
}