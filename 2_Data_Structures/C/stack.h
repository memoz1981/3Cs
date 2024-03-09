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
    struct Stack* top;
    int count; 
};

/* INITIALIZATION AND MEMORY FREE-ING FUNCTIONS */
struct StackWrapper* InitializeStackWrapper(void); 
void FreeStackWrapper(struct StackWrapper* wrapper); 

/* STACK FUNCTION IMPLEMENTATIONS */
void PushToStack(struct StackWrapper* wrapper, int value);
int PopFromStack(struct StackWrapper* wrapper); 
int PeekFromStack(struct StackWrapper* wrapper); 

int StackSize(struct StackWrapper* wrapper); 
int isStackEmpty(struct StackWrapper* wrapper); 

/* PRINT FUNCTIONS */
void PrintStack(struct StackWrapper* wrapper); 

/* STACK DEMO */
void RunStackInInteractiveMode(void); 

