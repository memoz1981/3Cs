/* HEADER FILE FOR QUEUE */

//Define the queue
typedef struct Queue
{
    int value;
    struct Queue* next;
};

/* INITIALIZATION AND MEMORY FREE-ING FUNCTIONS */
struct Queue* InitializeQueue(int value);
void Free(struct Queue* item); 

/* QUEUE FUNCTION IMPLEMENTATIONS */
void Enqueue(struct Queue* head, struct Queue* item);
void Enqueue(struct Queue* head, int value); //will try overloading
struct Queue* Dequeue(struct Queue* head); 
struct Queue* Peek(struct Queue* head); 

int Size(struct Queue* head); 
int isEmpty(struct Queue* head); 

/* PRINT FUNCTIONS */
void PrintSingleQueueItem(struct Queue* item); 
void PrintFullQueue(struct Queue* head); 

/* QUEUE DEMO */
void run_queue_test(void);

/*
QUEUE DEMO - Behind the Hoods - to be populated...

1) 
*/