#include <stdio.h>
#include "queue.h"

/* INITIALIZATION AND MEMORY FREE-ING FUNCTIONS */
struct Queue* InitializeQueue(int value)
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue)); 
    if(queue == NULL)
    {
        printf("Memory error when allocating memory for the queue.\n"); 
        return NULL; 
    }
    queue->value = value; 
    queue->next = NULL; 
    return queue; 
}

struct QueueWrapper* InitializeQueueWrapper()
{
    struct QueueWrapper* wrapper = (struct QueueWrapper*)malloc(sizeof(struct QueueWrapper)); 
    if(wrapper == NULL)
    {
        printf("Memory error when allocating memory for the queue wrapper.\n"); 
        return NULL; 
    }
    wrapper->head = NULL; 
    wrapper->size = 0; 
    return wrapper; 
}

void FreeQueueWrapper(struct QueueWrapper* wrapper)
{
    struct Queue* current = wrapper->head; 
    while (current != NULL) {
        struct Queue* temp = current;
        current = current->next;
        printf("\nFreeing following queue item: "); 
        PrintSingleQueueItem(temp);
        free(temp);
    }
    
    printf("\nFreeing wrapper\n"); 
    free(wrapper); 
}

/* QUEUE FUNCTION IMPLEMENTATIONS */
/*Enqueue function is O(n) - we need to add the element to the end of the queue*/
void Enqueue(struct QueueWrapper* wrapper, int value)
{
    struct Queue* item = InitializeQueue(value); 
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
Note: returning the value because of 2 reasons: 
1 - business doesn't need the address - just value is required
2 - we want to free memory for anything removed - this it's very practical to 
return value and free associated memory
*/
int Dequeue(struct QueueWrapper* wrapper)
{
    if(wrapper->head == NULL)
    {
        return -1; 
    }
    
    struct Queue* temp = wrapper->head; 
    int value = temp->value; 
    wrapper->size--; 
    wrapper->head = wrapper->head->next;
    free(temp); 
    return value; 
}

/*
PeekQueue is similar to dequeue function - it only returns without removing the item 
*/
int PeekQueue(struct QueueWrapper* wrapper)
{
    if(wrapper->head == NULL)
    {
        return -1; 
    }
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
        return; 
    }
    printf("{value: %d, address: %p}",  queue->value, (void*)(queue)); 
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
    printf("NULL\n"); 
}

/* QUEUE DEMO */
void RunQueueInInteractiveMode(void)
{
    struct QueueWrapper* wrapper = InitializeQueueWrapper(); 
    int result; 
    do{
        result = RunQueueInteractiveCycle(wrapper); 
    }
    while (result != -1);
    
    FreeQueueWrapper(wrapper); 
}

int RunQueueInteractiveCycle(struct QueueWrapper* wrapper)
{
    printf("\n\n\nINTERACTIVE QUEUE COMMANDS:\n"); 
    printf("[c] - for clearing the screen\n");
    printf("[r] - to print the queue\n");
    printf("[e] - to exit\n");
    printf("[+] - to add integer to the queue\n");
    printf("[d] - to dequeue\n");
    printf("[p] - to peek\n");
    printf("[s] - to print queue size\n");
    
    char command; 
    int value; 
    int result = 0; 
    int scanresult; 
    
    scanf(" %c", &command);
    printf("received %c\n", command); 
    // Process user input
        switch (command) {
            case 'c':
                system("cls"); 
                break;
            case 'r':
                PrintFullQueue(wrapper); 
                break;
            case 'e':
                return -1; 
                break;
            case 'd':
                int dequeued = Dequeue(wrapper); 
                printf("Dequeued %d", dequeued); 
                break;
            case 'p':
                int peeked = PeekQueue(wrapper);
                printf("Peeked %d", peeked); 
                break;
            case 's':
                int queueSize = QueueSize(wrapper);
                printf("Queue size is: %d\n", queueSize);
                break;
            case '+':
                printf("\nEnter the integer to add to the queue: ");
                scanresult = scanf("%d", &value); 
                if(scanresult != 1)
                {
                    printf("Entered value is not an integer.");
                    break; 
                }
                Enqueue(wrapper, value);
                break;
            default:
                printf("Invalid command\n");
                break; 
        }

    return result; 
}