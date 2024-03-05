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

struct QueueWrapper* InitializeQueueWrapper(struct Queue* head);
void FreeQueueWrapper(struct QueueWrapper* wrapper); 

/* QUEUE FUNCTION IMPLEMENTATIONS */
void Enqueue(struct QueueWrapper* wrapper, struct Queue* item);
void Enqueue(struct QueueWrapper* wrapper, int value); //will try overloading
struct Queue* Dequeue(struct QueueWrapper* wrapper); 
struct Queue* Peek(struct QueueWrapper* wrapper); 

int Size(struct QueueWrapper* wrapper); 
int isEmpty(struct QueueWrapper* wrapper); 

/* PRINT FUNCTIONS */
void PrintSingleQueueItem(struct Queue* item); 
void PrintFullQueue(struct QueueWrapper* wrapper); 

/* QUEUE DEMO */
void run_queue_test(void);

/*
QUEUE DEMO - Behind the Hoods - to be populated...

1) 
*/