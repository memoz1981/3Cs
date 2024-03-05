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
    wrapper->size++; 

    if(iterator == NULL)
    {
        wrapper->head = item; 
        return; 
    }
 
    while(iterator->next != NULL)
    {
        iterator = iterator->next; 
    }

    iterator->next = item; 
}

struct Queue* Dequeue(struct QueueWrapper* wrapper)
{
    if(wrapper->head == NULL)
        return NULL; 
    
    wrapper->size--; 

    struct Queue* iterator = wrapper->head; 

    if(iterator->next == NULL)
    {
        wrapper->head = NULL;
        wrapper->size = 0; 
        return iterator; 
    }

    while(iterator->next->next != NULL)
    {
        iterator = iterator->next;  
    }

    struct Queue* lastElement = iterator->next; 
    iterator->next = NULL; 
    return lastElement; 
}

struct Queue* Peek(struct QueueWrapper* wrapper)
{
    if(wrapper->head == NULL)
        return NULL; 

    struct Queue* iterator = wrapper->head; 

    while(iterator->next != NULL)
        iterator = iterator->next; 
    
    return iterator; 
}

int Size(struct QueueWrapper* wrapper)
{
    return wrapper->size; 
}

int isEmpty(struct QueueWrapper* wrapper)
{
    return wrapper->size == 0; 
}

/* PRINT FUNCTIONS */
void PrintSingleQueueItem(struct Queue* queue)
{
    if(queue == NULL)
        printf("Queue is NULL\n"); 
    
    int nextvalue = -1;
    if(queue->next)
    {
        nextvalue = queue->next->value; 
    }

    printf("\nQueue value %d and address %p and next value is %d\n", queue->value, (void*)(&queue), nextvalue); 
}

void PrintFullQueue(struct QueueWrapper* wrapper)
{
    printf("\nQueue Wrapper is being printed with count of %d\n", wrapper->size);
    struct Queue* iterator = wrapper->head;

    while(iterator)
    {
        PrintStack(iterator); 
        iterator = iterator->next;
    }
    printf("\nQueue Wrapper print complete\n"); 
}

/* QUEUE DEMO */
void run_queue_test(void)
{
    printf("Defining queue array of 5 elements\n"); 
    struct Queue* queue[5];  

    printf("Defining queue wrapper\n");
    struct QueueWrapper* wrapper; 
    
    //Initialization
    printf("Queues are being initialized\n"); 
    for(int i=0; i<5; i++)
    {
        queue[i] = InitializeQueue(i); 
        PrintSingleQueueItem(queue[i]); 
    }
    
    printf("Queue Wrapper is being initialized\n"); 
    wrapper = InitializeQueueWrapper(); 
    PrintFullQueue(wrapper); 
    printf("Wrapper size: %d\n", Size(wrapper));
    printf("Wrapper is empty: %d\n", isEmpty(wrapper)); 
    Peek(wrapper); 

    //Actions
    Enqueue(wrapper, queue[0]); 
    Enqueue(wrapper, queue[1]); 
    Enqueue(wrapper, queue[2]); 
    Enqueue(wrapper, queue[3]); 
    struct Queue* dequeued1 = Dequeue(wrapper); 
    Enqueue(wrapper, queue[4]);
    struct Queue* dequeued2 = Dequeue(wrapper); 

    printf("Wrapper size: %d\n", Size(wrapper));
    printf("Wrapper is empty: %d\n", isEmpty(wrapper)); 
    Peek(wrapper); 
    
    PrintWrapper(wrapper); 
    FreeQueueWrapper(wrapper); 

    for(int i=0; i<5; i++)
    {
        FreeQueueItem(queue[i]);  
    }
    
    printf("Free-ing complete"); 
    return; 
}