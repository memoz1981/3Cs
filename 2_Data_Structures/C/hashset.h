#define ARRAY_SIZE_PRIME 251 //PRIME NUMBER

typedef struct HashSetNode {
    int value; 
    struct HashSetNode* next;
};

/* INITIALIZATION AND FREE MEMORY FUNCTIONS*/
struct HashSetNode** InitializeHashSet();

void FreeHashSet(struct HashSetNode** hashSet); 

/* HASHSET FUNCTIONS */
//returns 0 if yes, 1 if no
int HashSetContains(struct HashSetNode** hashSet, int key); 

int AddToHashSet(struct HashSetNode** hashSet, int key);

int RemoveFromHashSet(struct HashSetNode** hashSet, int key); 

/* PRINT */
void PrintHashSet(struct HashSetNode** hashSet); 

/* DEMO */
void RunHashSetInInteractiveMode(void);