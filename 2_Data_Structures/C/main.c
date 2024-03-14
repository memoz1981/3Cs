#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "queue.h"
#include "linkedlist.h"
#include "tree.h"
#include "list.h"

/*
gcc.exe -o 2_data_structures.exe -w main.c queue.c stack.c -> -w will hide the warning messages...
.\2_data_structures.exe
*/

int main(int argc, char *argv[])
{
    int arg = 1; 

    int isStackCalled = strcmp(argv[0], "stack.exe"); 
    int isQueueCalled = strcmp(argv[0], "queue.exe"); 
    int isLinkedListCalled = strcmp(argv[0], "linkedlist.exe"); 
    int isBinarySearchTreeCalled = strcmp(argv[0], "tree.exe"); 
    int isListCalled = strcmp(argv[0], "list.exe"); 
    
    if(isStackCalled == 0)
    {
        RunStackInInteractiveMode(); 
    }
    else if(isQueueCalled == 0)
    {
        RunQueueInInteractiveMode(); 
    }
    else if(isLinkedListCalled == 0)
    {
        RunLinkedListInInteractiveMode(); 
    }
    else if(isBinarySearchTreeCalled == 0)
    {
        RunBstInInteractiveMode(); 
    }
    else if(isListCalled == 0)
    {
        RunListInInteractiveMode(); 
    }
    else
    {
        return -1; 
    }
}





