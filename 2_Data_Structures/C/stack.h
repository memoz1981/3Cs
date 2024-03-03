//Defining the stack
typedef struct Stack
{
    int value;
    struct Stack* next;
};

//Defining the stack wrapper - since the stack top (head) element constantly changes
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
struct Stack* Pop(struct StackWrapper* wrapper); 
void Push(struct StackWrapper* wrapper, struct Stack* stack);
struct ack* Peek(struct StackWrapper* wrapper); 
int isEmpty(struct StackWrapper* wrapper); 
int Size(struct StackWrapper* wrapper); 

void PrintWrapper(struct StackWrapper* wrapper); 
void PrintStack(struct Stack* stack); 
