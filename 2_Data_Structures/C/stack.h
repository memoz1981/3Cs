/* HEADER FILE FOR STACK (AND ASSOCIATED WRAPPER STACKWRAPPER) */

//Define the stack
typedef struct Stack
{
    int value;
    struct Stack* next;
};

//Define the stack wrapper - since the stack top (head) element constantly changes
//need a wrapper to keep the reference to the stack
typedef struct StackWrapper
{
    struct Stack** top;
    int count; 
};

/* INITIALIZATION AND MEMORY FREE-ING FUNCTIONS */
struct Stack* InitializeStack(int value);
void Free(struct Stack* stack); 

struct StackWrapper* InitializeStackWrapper(void); 
void FreeWrapper(struct StackWrapper* wrapper); 

/* STACK FUNCTION IMPLEMENTATIONS */
void Push(struct StackWrapper* wrapper, struct Stack* stack);
struct Stack* Pop(struct StackWrapper* wrapper); 
struct Stack* Peek(struct StackWrapper* wrapper); 

int Size(struct StackWrapper* wrapper); 
int isEmpty(struct StackWrapper* wrapper); 

/* PRINT FUNCTIONS */
void PrintWrapper(struct StackWrapper* wrapper); 
void PrintStack(struct Stack* stack); 

/* STACK DEMO */
void run_stack_test(void);

/*
STACK DEMO - Behind the Hoods - to be populated...

1) 
*/
