/* HEADER FILE FOR BINARY SEARCH TREE */

//For simplicity assuming Binary Search Tree doesn't accept any duplicates
//Define the tree node - we don't need a wrapper for this. 
typedef struct BSTNode
{
    int value;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

/* INITIALIZATION AND MEMORY FREE-ING FUNCTIONS */
struct BSTNode* InitializeBst(int value);
void FreeBst(struct BSTNode* tree); 

/* BST FUNCTION IMPLEMENTATIONS */
int InsertToBst(struct BSTNode* tree, int value);
int DeleteFromBst(struct BSTNode* tree, int value); 
int SearchBst(struct BSTNode* tree, int value); 
int FindMinBst(struct BSTNode* tree);
int FindMaxBst(struct BSTNode* tree);

/* PRINT FUNCTIONS */
void PrintBstInOrder(struct BSTNode* tree); 
void PrintBstPreOrder(struct BSTNode* tree); 
void PrintBstPostOrder(struct BSTNode* tree); 

/*DEMO*/
void RunBstInInteractiveMode(void); 