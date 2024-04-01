/* HEADER FILE FOR Linked Lists */

//Define the linked list node
typedef struct Node
{
    int value;
    struct Node* next;
} Node;

//Define the singly linked list wrapper objexct
typedef struct SinglyLinkedList
{
    struct Node* head;
} SinglyLinkedList;

/* INITIALIZATION AND MEMORY FREE-ING FUNCTIONS */
struct SinglyLinkedList* InitializeLinkedList();
void FreeLinkedList(struct SinglyLinkedList* list); 

/* QUEUE FUNCTION IMPLEMENTATIONS */
int AddToLinkedList(struct SinglyLinkedList* list, int value); //returns 0 for success, -1 if failed
int RemoveFromLinkedList(struct SinglyLinkedList* list, int value); //returns 0 for success, -1 if failed

int IsLinkedListEmpty(struct SinglyLinkedList* list); //returns 0 for success, -1 if failed

/* PRINT FUNCTIONS */
void PrintLinkedList(struct SinglyLinkedList* list); 

/*DEMO*/
void RunLinkedListInInteractiveMode(void); 