/* HEADER FILE FOR QUEUE */

//Define the queue
typedef struct Queue
{
    int value;
    struct Queue* next;
} Queue;

//Define the queue wrapper - this is required when the reference to head needs to be destructed
typedef struct QueueWrapper
{
    struct Queue* head;
    int size; 
} QueueWrapper;

/* INITIALIZATION AND MEMORY FREE-ING FUNCTIONS */
struct QueueWrapper* InitializeQueueWrapper();
void FreeQueueWrapper(struct QueueWrapper* wrapper); 

/* QUEUE FUNCTION IMPLEMENTATIONS */
void Enqueue(struct QueueWrapper* wrapper, int value);
int Dequeue(struct QueueWrapper* wrapper); 
int PeekQueue(struct QueueWrapper* wrapper); 

int QueueSize(struct QueueWrapper* wrapper); 
int isQueueEmpty(struct QueueWrapper* wrapper); 

/* PRINT FUNCTIONS */
void PrintQueue(struct QueueWrapper* wrapper); 

/*DEMO*/
void RunQueueInInteractiveMode(void); 