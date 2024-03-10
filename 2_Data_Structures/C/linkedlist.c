#include "linkedlist.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct SinglyLinkedList* InitializeNode(int value);
void PrintNode(struct Node* node); 

/* INITIALIZATION AND MEMORY FREE-ING FUNCTIONS */
struct SinglyLinkedList* InitializeLinkedList()
{
    return (struct SinglyLinkedList*)malloc(sizeof(struct SinglyLinkedList)); 
}

void FreeLinkedList(struct SinglyLinkedList* list)
{
    struct Node* current = list->head; 
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        printf("\nFreeing following node: "); 
        PrintNode(temp);
        free(temp);
    }
    
    printf("\nFreeing the list\n"); 
    free(list); 
}

/* QUEUE FUNCTION IMPLEMENTATIONS */

//returns 0 for success, -1 if failed (O(n) for traversal)
int AddToLinkedList(struct SinglyLinkedList* list, int value)
{
    struct Node* node = InitializeNode(value); 

    //if head is NULL, point head to the node
    if(list->head == NULL)
    {
        list->head = node; 
        return 0; 
    }

    //otherwise traverse to end of the linked list add node there
    struct Node* iterator = list->head; 

    while(iterator->next != NULL)
        iterator = iterator->next; 
    
    iterator->next = node; 
    return 0; 
 }

//returns 0 for success, -1 if failed (O(n) for traversal)
//for simplicity assumed linked in contains only distinct elements
int RemoveFromLinkedList(struct SinglyLinkedList* list, int value)
{
    //if head is NULL, return failure
    if(list->head == NULL)
    {
        return -1; 
    }

    //otherwise traverse to end of the linked list add node there
    struct Node* iterator = list->head; 

    while(iterator->next != NULL)
    {
        //if value is found - item is removed from the list, and 0 returned. 
        //as the value is already specified in argument - no need to return it. 
        if(iterator->next->value == value)
        {
            iterator->next = iterator->next->next;
            return 0; 
        }

        iterator = iterator->next;
    }

    return -1; 
} 
//returns 0 for success, non zero otherwise
int IsLinkedListEmpty(struct SinglyLinkedList* list)
{
    return list->head != NULL; 
}

/* PRINT FUNCTIONS - it's actually a traversal implementation*/
void PrintLinkedList(struct SinglyLinkedList* list)
{
    printf("\nLinkedList:");
    if(list->head == NULL)
    {
        printf("empty");
        return; 
    }
    struct Node* iterator = list->head; 
    while(iterator != NULL)
    {
        PrintNode(iterator);
        printf(" -> ");
        iterator = iterator->next; 
    }
    printf("NULL\n");
}

/*DEMO*/
void RunLinkedListInInteractiveMode(void)
{
    struct SinglyLinkedList* list = InitializeLinkedList(); 
    int result; 
    do{
        result = RunLinkedListInteractiveCycle(list); 
    }
    while (result != -1);
    
    FreeLinkedList(list); 
}

int RunLinkedListInteractiveCycle(struct SinglyLinkedList* list)
{
    printf("\n\n\nINTERACTIVE SINGLY LINKED LIST COMMANDS:\n"); 
    printf("[c] - for clearing the screen\n");
    printf("[p] - to print the list\n");
    printf("[e] - to exit\n");
    printf("[+] - to add integer to the list\n");
    printf("[-] - to remove\n");
    printf("[0] - to print if list is empty\n");
    
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
            case 'p':
                PrintLinkedList(list); 
                break;
            case 'e':
                return -1; 
                break;
            case '+':
                printf("\nEnter the integer to add to the list: ");
                int result = scanf("%d", &value); 
                if(result != 0)
                {
                    printf("Entered text cannot be parsed to an integer\n");
                    break;
                }
                result = AddToLinkedList(list, value); 
                if(result != 0)
                {
                    printf("Failed to add\n");
                }
                break;
            case '-':
                printf("\nEnter the integer to remove from the list: ");
                int result = scanf("%d", &value); 
                if(result != 0)
                {
                    printf("Entered text cannot be parsed to an integer\n");
                    break;
                }
                result = RemoveFromLinkedList(list, value); 
                if(result != 0)
                {
                    printf("Failed to remove\n");
                }
                break;
            case '0':
                int isListEmpty = IsLinkedListEmpty(list);
                printf("List empty flag: %d\n", isListEmpty);
                break;
            default:
                printf("Invalid command\n");
                system("cls"); 
                break; 
        }

    return result; 
}

/* "PRIVATE" functions */
struct SinglyLinkedList* InitializeNode(int value)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node)); 
    node->next = NULL;
    node->value = value; 

    return node; 
}

void PrintNode(struct Node* node)
{
    printf("{value: %d, address: %p}", node->value, (void*)node); 
}