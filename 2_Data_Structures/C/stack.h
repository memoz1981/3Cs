/*
HEADER FILE FOR STACK (AND ASSOCIATED WRAPPER STACKWRAPPER)
*/

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

/*Stack initialization and freeing the memory*/
struct Stack* InitializeStack(int value);
void Free(struct Stack* stack); 

/*Stack wrapper initialization and freeing the memory*/
struct StackWrapper* InitializeStackWrapper(void); 
void FreeWrapper(struct StackWrapper* wrapper); 

/*Stack actions*/
void Push(struct StackWrapper* wrapper, struct Stack* stack);
struct Stack* Pop(struct StackWrapper* wrapper); 

int Size(struct StackWrapper* wrapper); 
struct Stack* Peek(struct StackWrapper* wrapper); 
int isEmpty(struct StackWrapper* wrapper); 

void PrintWrapper(struct StackWrapper* wrapper); 
void PrintStack(struct Stack* stack); 
