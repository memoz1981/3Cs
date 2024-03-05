#include <stdio.h>
#include "queue.h"

/* INITIALIZATION AND MEMORY FREE-ING FUNCTIONS */

struct Queue* InitializeQueue(int value)
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue)); 
    if(queue == NULL)
    {
        printf("Memory error when allocating memory for the queue. "); 
        return NULL; 
    }

    queue->value = value; 
    queue->next = NULL; 

    return queue; 
}

void Free(struct Queue* head)
{
    free(head); 
}

/* QUEUE FUNCTION IMPLEMENTATIONS */
void Enqueue(struct Queue* head, struct Queue* item)
{
    struct Queue* iterator = head; 

    while(iterator->next != NULL)
    {
        iterator = iterator->next; 
    }

    iterator->next = item; 
}

struct Queue* Dequeue(struct Queue* head)
{
    struct Queue* iterator = head; 

    while(iterator->next != NULL)
    {
        iterator = iterator->next; 
    }

    iterator->next = item; 
}