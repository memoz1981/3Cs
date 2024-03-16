#include <stdio.h>
#include <stdlib.h>
#include "hashset.h"

int Hash(int key); 
struct HashSetNode* InitializeHashSetNode(int value); 
PrintHashSetNode(struct HashSetNode* node); 
int RunHashSetInteractiveCycle(struct HashSetNode** hashSet);
void AddElement(struct HashSetNode** hashSet); 
void RemoveElement(struct HashSetNode** hashSet); 
void SearchElement(struct HashSetNode** hashSet); 
int ScanElement(void); 

/* INITIALIZATION AND FREE MEMORY FUNCTIONS*/
struct HashSetNode** InitializeHashSet()
{
    struct HashSetNode* HashSet[ARRAY_SIZE_PRIME] = 
                (struct HashSetNode*)malloc(ARRAY_SIZE_PRIME * sizeof(struct HashSetNode));
    
    for(int i = 0; i < ARRAY_SIZE_PRIME; i++)
    {
        HashSet[i] = NULL; 
    }
}

void FreeHashSet(struct HashSetNode** hashSet)
{
    for(int i = 0; i < ARRAY_SIZE_PRIME; i++)
    {
        if(hashSet[i] == NULL)
            continue; 
        
        struct HashSetNode* temp = hashSet[i]; 
        while(temp != NULL)
        {
            hashSet[i] = hashSet[i]->next; 
            free(temp);
            temp = hashSet[i]; 
        }
    }

    free(hashSet); 
}

/* HASHSET FUNCTIONS */
//returns 0 if yes, -1 if no
int HashSetContains(struct HashSetNode** hashSet, int key)
{
    int index = Hash(key); 

    if(hashSet[index] == NULL)
        return -1; 
    
    //here implemented basic strategy to iterate... 
    //however this should be optimized... 
    struct HashSetNode* temp = hashSet[index]; 

    while(temp != NULL)
    {
        if(temp->value == key)
            return 0; 
        
        temp = temp->next; 
    }
    return -1; 
}

int AddToHashSet(struct HashSetNode** hashSet, int key)
{
    struct HashSetNode* node = InitializeHashSetNode(key); 

    int index = Hash(key); 
    struct HashSetNode* temp = hashSet[index];

    if(temp == NULL)
    {
        hashSet[index] = node; 
        return 0; 
    }

    while(temp->next != NULL)
        temp = temp->next; 
    
    temp->next = node;
    return 0; 
}

int RemoveFromHashSet(struct HashSetNode** hashSet, int key)
{
    int doesContain = Contains(hashSet, key); 

    if(doesContain != 0)
        return -1; 
    
    int index = Hash(key); 
    //no need to check for null, as we know that it contains the key
    struct HashSetNode* temp = hashSet[index]; 
    if(temp->value == key)
    {
        hashSet[index] = hashSet[index]->next; 
        free(temp); 
        return 0; 
    }
    while(temp->next->value != key)
    {
        temp = temp->next; 
    }

    struct HashSetNode* nodeToRemove = temp->next; 
    temp->next = temp->next->next;
    free(nodeToRemove); 
    
    return 0; 
}

/* PRINT */
void PrintHashSet(struct HashSetNode** hashSet)
{
    printf("\nPrinting HashSet: \n");
    for(int i = 0; i < ARRAY_SIZE_PRIME; i++)
    {
        if(hashSet[i] == NULL)
            continue; 
        printf("\n"); 
        struct HashSetNode* temp = hashSet[i]; 

        while(temp != NULL)
        {
            PrintHashSetNode(temp); 
            temp = temp->next; 
            printf(" -> "); 
        }
        printf("NULL"); 
    }
    printf("\n");
}

/* DEMO */
void RunHashSetInInteractiveMode(void)
{
    system("cls"); 
    int result; 
    struct HashSetNode** hashSet = InitializeHashSet(); 
    do{
        result = RunHashSetInteractiveCycle(hashSet); 
    }
    while (result != -1);
    
    FreeHashSet(hashSet); 
}

/* "PRIVATE" METHODS */

int Hash(int key)
{
    return key % ARRAY_SIZE_PRIME; 
}

struct HashSetNode* InitializeHashSetNode(int value)
{
    struct HashSetNode* node = (struct HashSetNode*)malloc(sizeof(struct HashSetNode));
    node->value = value; 
    node->next = NULL;

    return node; 
}

PrintHashSetNode(struct HashSetNode* node)
{
    printf("{value: %d, address: %p}", node->value, (void*)node); 
}

int RunHashSetInteractiveCycle(struct HashSetNode** hashSet)
{
    printf("\n\n\nINTERACTIVE LIST COMMANDS:\n"); 
    printf("[c] - for clearing the screen\n");
    printf("[p] - to print the hash set\n");
    printf("[e] - to exit\n");
    printf("[?] - to check if hashset contains an element\n");
    printf("[+] - to add an element to the hashset\n");
    printf("[-] - to remove an element from the hashset\n");
    
    char commandText[10];
    memset(commandText,'\0', 10);  
    char command; 
    int operationResult; 
    
    fgets(commandText, 10, stdin);
    command = commandText[0]; 

    // Process user input
        switch (command) {
            case 'c':
                system("cls"); 
                return 0;
            case 'p':
                PrintHashSet(hashSet); 
                return 0;
            case 'e':
                return -1; 
            case '+':
                AddElement(hashSet); 
                return 0;
            case '-':
                RemoveElement(hashSet); 
                return 0;
            case '?':
                SearchElement(hashSet);
            default:
                printf("Invalid command\n");
                return 0;
        }

    return 0; 
}

void AddElement(struct HashSetNode** hashSet)
{
    int value = ScanElement(); 

    int contains = HashSetContains(hashSet, value);

    if(contains == 0)
    {
        printf("Hash set already contains the element %d\n", value);
        return; 
    }

    int result = AddToHashSet(hashSet, value); 

    if(result != 0)
        printf("Failed to add...\n"); 
}
void RemoveElement(struct HashSetNode** hashSet)
{
    int value = ScanElement(); 

    int contains = HashSetContains(hashSet, value);

    if(contains != 0)
    {
        printf("Hash set doesn't contain the element %d\n", value);
        return; 
    }

    int result = RemoveFromHashSet(hashSet, value); 

    if(result != 0)
        printf("Failed to remove...\n"); 
}
void SearchElement(struct HashSetNode** hashSet)
{
    int value = ScanElement(); 

    int contains = HashSetContains(hashSet, value);

    if(contains == 0)
    {
        printf("Hash set contains the element %d\n", value); 
        return; 
    }
    printf("Hash set doesn't contain the element %d\n", value); 
}

int ScanElement(void)
{
    printf("Enter the integer:"); 
    int value; 
    int result = scanf("%d", value);

    if(result != 1)
    {
        printf("Entered text is not an integer.\n");
        exit(EXIT_FAILURE); 
    }
    return value; 
}
