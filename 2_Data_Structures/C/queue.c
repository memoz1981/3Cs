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

void FreeQueueItem(struct Queue* head)
{
    free(head); 
}

struct QueueWrapper* InitializeQueueWrapper()
{
    struct QueueWrapper* wrapper = (struct QueueWrapper*)malloc(sizeof(struct QueueWrapper)); 
    if(wrapper == NULL)
    {
        printf("Memory error when allocating memory for the queue. "); 
        return NULL; 
    }

    wrapper->head = NULL; 
    wrapper->size = 0; 

    return wrapper; 
}

void FreeQueueWrapper(struct QueueWrapper* wrapper)
{
    free(wrapper); 
}

/* QUEUE FUNCTION IMPLEMENTATIONS */
void Enqueue(struct QueueWrapper* wrapper, struct Queue* item)
{
    struct Queue* iterator = wrapper->head; 

    if(iterator == NULL)
        wrapper->head = item; 

    while(iterator->next != NULL)
    {
        iterator = iterator->next; 
    }

    iterator->next = item; 
}

struct Queue* Dequeue(struct Queue* head)
{
    struct Queue* iterator = head; 

    if(iterator->next == NULL)
    {
        return head; 
    }

    while(iterator->next != NULL)
    {
        iterator = iterator->next; 
    }

    iterator->next = item; 
}