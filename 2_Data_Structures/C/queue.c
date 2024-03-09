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
/*Enqueue function is O(n) - we need to add the element to the end of the queue*/
void Enqueue(struct QueueWrapper* wrapper, struct Queue* item)
{
    printf("\nEnqueueing value %d\n", item->value); 
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

/*
Dequeue function is O(1) - we just return the head
This is the main purpose of the wrapper - every time we dequeue the queue, we loose the 
reference to the queue
*/
struct Queue* Dequeue(struct QueueWrapper* wrapper)
{
    printf("\nDequeueing...\n"); 
    if(wrapper->head == NULL)
    {
        printf("\nDequeued NULL.\n"); 
        return NULL; 
    }
    
    struct Queue* head = wrapper->head; 
    wrapper->size--; 
    wrapper->head = wrapper->head->next;

    printf("\nDequeued value of %d.\n", head->value); 
    return head->value; 
}

/*
PeekQueue is similar to dequeue function - it only returns without removing the item 
*/
struct Queue* PeekQueue(struct QueueWrapper* wrapper)
{
    printf("\nPeeking...\n"); 
    if(wrapper->head == NULL)
    {
        printf("\nPeeked NULL.\n"); 
        return NULL; 
    }

    printf("\nDequeued value of %d.\n", wrapper->head->value); 
    return wrapper->head->value; 
}

/*
Returns the size of the queue
Normally it's O(n) - but with the cost of one additional operation at each 
enqueue/dequeue action and 4 bytes of memory to store the size
we can return it with O(1) operation
*/
int QueueSize(struct QueueWrapper* wrapper)
{
    return wrapper->size; 
}

/*Comments for QueueSize apply here*/
int isQueueEmpty(struct QueueWrapper* wrapper)
{
    return wrapper->size == 0; 
}

/* PRINT FUNCTIONS */
void PrintSingleQueueItem(struct Queue* queue)
{
    if(queue == NULL)
    {
        printf("Queue is NULL"); 
        return; 
    }

    printf("{value: %d, address: %p}",  queue->value, (void*)(&queue)); 
}

void PrintFullQueue(struct QueueWrapper* wrapper)
{
    struct Queue* iterator = wrapper->head;

    printf("\nQueue Wrapper: "); 
    if(wrapper->head == NULL)
    {
        printf("NULL\n"); 
        return; 
    }

    for(int i=0; i<wrapper->size; i++)
    {
        PrintSingleQueueItem(iterator); 
        printf(" -> "); 
        iterator = iterator->next;
    }

    printf("\n"); 
}

/* QUEUE DEMO */
void run_queue_test(void)
{
    struct Queue* queue[5];  
    struct QueueWrapper* wrapper; 
    
    //Initialization
    for(int i=0; i<5; i++)
    {
        queue[i] = InitializeQueue(i); 
        PrintSingleQueueItem(queue[i]); 
    }
    
    printf("\n4.Queue Wrapper is being initialized\n"); 
    wrapper = InitializeQueueWrapper(); 
    PrintFullQueue(wrapper); 
    printf("\n5.Wrapper size: %d\n", Size(wrapper));
    printf("\n6.Wrapper empty flag: %d\n", isEmpty(wrapper)); 

    PeekQueue(wrapper); 

    //Actions
    printf("\n7.Actions: \n"); 
    Enqueue(wrapper, queue[0]); 
    Enqueue(wrapper, queue[1]); 
    Enqueue(wrapper, queue[2]); 
    Enqueue(wrapper, queue[3]); 
    struct Queue* dequeued1 = Dequeue(wrapper); 
    Enqueue(wrapper, queue[4]);
    struct Queue* dequeued2 = Dequeue(wrapper); 

    printf("Wrapper size: %d\n", Size(wrapper));
    printf("Wrapper empty flag: %d\n", isEmpty(wrapper)); 

    PeekQueue(wrapper); 
    
    PrintFullQueue(wrapper); 
    FreeQueueWrapper(wrapper); 

    for(int i=0; i<5; i++)
    {
        FreeQueueItem(queue[i]);  
    }
    
    printf("Free-ing complete"); 
    return; 
}