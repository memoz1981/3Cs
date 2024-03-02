//Defining the stack
typedef struct Stack
{
    int* value;
    struct Stack* next;
};

typedef struct StackList
{
    struct Stack* head;
    int* count; 
};

void InitializeStack(int value, struct Stack* stack);
void InitializeStackList(struct StackList* stackList); 

struct Stack* Pop(struct StackList* list); 
void Push(struct StackList* list, struct Stack** stack);
struct ack* Peek(struct StackList* list); 
int isEmpty(struct StackList* list); 
int Size(struct StackList* list); 

void Print(struct StackList* list); 
void PrintStack(struct Stack** stack); 
