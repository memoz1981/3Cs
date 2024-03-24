#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "queue.h"
#include "linkedlist.h"
#include "tree.h"
#include "list.h"
#include "hashset.h"

/*
gcc.exe -o 2_data_structures.exe -w main.c queue.c stack.c -> -w will hide the warning messages...
.\2_data_structures.exe
*/

int main(int argc, char *argv[])
{
    system("cls"); 
    int result; 
    do
    {
        result = RunDataStructuresDemo(); 
    } while (result != -1);

    return 0; 
}

int RunDataStructuresDemo()
{
    printf("\n\n\nDATA STRUCTURES C DEMO:\n"); 
    printf("[c] - to clear the screen\n");
    printf("[s] - for stack demo\n");
    printf("[q] - for queue demo\n");
    printf("[l] - for linked list demo\n");
    printf("[t] - for binary search tree demo\n");
    printf("[i] - for list demo\n");
    printf("[h] - for hashset demo\n");
    printf("[e] - to exit to the upper menu\n");

    char command[5]; 
    scanf("%s", command);

    if(strcmp(command, "c") == 0)
    {
        system("cls"); 
    }
    else if(strcmp(command, "s") == 0)
    {
        RunStackInInteractiveMode(); 
    }
    else if(strcmp(command, "q") == 0)
    {
        RunQueueInInteractiveMode(); 
    }
    else if(strcmp(command, "l") == 0)
    {
        RunLinkedListInInteractiveMode(); 
    }
    else if(strcmp(command, "t") == 0)
    {
        RunBstInInteractiveMode(); 
    }
    else if(strcmp(command, "i") == 0)
    {
        RunListInInteractiveMode(); 
    }
    else if(strcmp(command, "h") == 0)
    {
        RunHashSetInInteractiveMode(); 
    }
    else if(strcmp(command, "e") == 0)
    {
        return -1; 
    }
    else
    {
        printf("Invalid command...");
        return 0; 
    }
}





