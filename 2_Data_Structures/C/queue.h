/* HEADER FILE FOR QUEUE */

//Define the queue
typedef struct Queue
{
    int value;
    struct Queue* next;
};

//Define the queue wrapper - this is required when the reference to head needs to be destructed
typedef struct QueueWrapper
{
    struct Queue* head;
    int size; 
};

/* INITIALIZATION AND MEMORY FREE-ING FUNCTIONS */
struct Queue* InitializeQueue(int value);
void FreeQueueItem(struct Queue* item); 

struct QueueWrapper* InitializeQueueWrapper();
void FreeQueueWrapper(struct QueueWrapper* wrapper); 

/* QUEUE FUNCTION IMPLEMENTATIONS */
void Enqueue(struct QueueWrapper* wrapper, struct Queue* item);
struct Queue* Dequeue(struct QueueWrapper* wrapper); 
struct Queue* PeekQueue(struct QueueWrapper* wrapper); 

int QueueSize(struct QueueWrapper* wrapper); 
int isQueueEmpty(struct QueueWrapper* wrapper); 

/* PRINT FUNCTIONS */
void PrintSingleQueueItem(struct Queue* item); 
void PrintFullQueue(struct QueueWrapper* wrapper); 

/* QUEUE DEMO */
void run_queue_test(void);

/*
QUEUE DEMO - Behind the Hoods - to be populated...

1) 
*/