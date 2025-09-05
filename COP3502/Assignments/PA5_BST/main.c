/* COP 3502C Assignment 5
This program is written by: Kauan Lima */
//
// imports
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// definitions
//

#define SIZE 31

//
// structs
//

typedef struct bstnode
{
    char fanName[SIZE];
    int numTickets;
    struct bstnode* left;
    struct bstnode* right;
}node;

//
// prototypes
//

// tree functions
node* createNode(char name[SIZE], int count);
node* insertNode(node* root, node* node);

// command functions
void handleBuyCommand(node** rootPtr, char name[SIZE], int count, int* depth);
void handleUseCommand(node** rootPtr, char name[SIZE], int count, int* depth);
void handleFindCommand(node* root, char name[SIZE], int* depth);
void handleMeanTicketsCommand(node* root);
void handleHeightBalanceCommand(node* root);
void handleCountBeforeCommand(node* root, char name[SIZE]);

// output functions
node* getNode(node* root, char name[SIZE], int* depth);
node* useTickets(node** rootPtr, node* curr, int count);
void deleteNode(node** rootPtr, node* delNode);
int getNodeCount(node* root);
int getTickets(node* root);
int getHeight(node* root);
int countBefore(node* root, char name[SIZE]);

// auxiliary functions
void deleteLeaf(node** rootPtr, node* delNode, node* par);
void deleteHasOnlyLeftChild(node* delNode, node* par, node* saveNode);
void deleteHasOnlyRightChild(node* delNode, node* par, node* saveNode);
void deleteHasTwoChildren(node* root, node* delNode);

// helper functions
node* parent(node* root, node* node);
node* maxVal(node* root);
int isLeaf(node* node);
int hasOnlyLeftChild(node* node);
int hasOnlyRightChild(node* node);

// free binary search tree
void freeTree(node* root);

//
// main
//

int main(void)
{
    // obtain number of commands
    int numCmd;
    scanf("%d", &numCmd);

    // initialize root
    node *root = NULL;

    // iterate through each command
    for (int i = 0; i < numCmd; i++)
    {
        int depth = 0;

        // obtain primary command
        char cmd[SIZE];
        scanf("%s", cmd);
        // calculate the mean tickets of all nodes
        if (strcmp(cmd, "mean_tickets") == 0)
        {
            handleMeanTicketsCommand(root);
            continue;
        }
        // check the balance of the left and right subtrees
        else if (strcmp(cmd, "height_balance") == 0)
        {
            handleHeightBalanceCommand(root);
            continue;
        }

        // obtain name of node
        char name[SIZE];
        scanf("%s", name);
        // find fan in tree
        if (strcmp(cmd, "find") == 0)
        {
            handleFindCommand(root, name, &depth);
            continue;
        }
        // count all tickets before or at a fan node
        else if (strcmp(cmd, "count_before") == 0)
        {
            handleCountBeforeCommand(root, name);
            continue;
        }

        // obtain the count of tickets to manipulate
        int count;
        scanf("%d", &count);
        // buy tickets for or insert fan in tree
        if (strcmp(cmd, "buy") == 0)
            handleBuyCommand(&root, name, count, &depth);
        // use tickets for or remove fan in tree
        else if (strcmp(cmd, "use") == 0)
            handleUseCommand(&root, name, count, &depth);
    }

    // free all memory
    freeTree(root);
}

//
// functions
//

// create node in bst
node* createNode(char name[SIZE], int count)
{
    // allocate necessary size and fill up node
    node* n = (node*)malloc(sizeof(node));
    strcpy(n->fanName, name);
    n->numTickets = count;
    n->left = NULL;
    n-> right = NULL;
    return n;
}

// insert node to tree
node* insertNode(node* root, node* node)
{
    // if no root exists, root will be the node
    if (!root) return node;
    
    // insert node to left if name is alphabetically smaller than root
    if (strcmp(node->fanName, root->fanName) < 0)
    {
        if (root->left)
            root->left = insertNode(root->left, node);
        else
            root->left = node;
    }
    // insert node to right if name is alphabetically larger than root
    else
    {
        if (root->right)
            root->right = insertNode(root->right, node);
        else
            root->right = node;
    }
    // return the true root
    return root;
}

//
// command functions
//

void handleBuyCommand(node** rootPtr, char name[SIZE], int count, int* depth)
{
    // find node
    node* fNode = getNode(*rootPtr, name, depth);

    // create new node if not exists
    if (!fNode)
    {
        node* newNode = createNode(name, count);
        *rootPtr = insertNode(*rootPtr, newNode);
        fNode = newNode;
    }
    // add tickets to node if exists
    else
        fNode->numTickets += count;

    // display node name, ticket count, and depth
    printf("%s %d %d\n", fNode->fanName, fNode->numTickets, *depth);
}

void handleUseCommand(node** rootPtr, char name[SIZE], int count, int* depth)
{
    // find node
    node* uNode = getNode(*rootPtr, name, depth);

    // declare not found if not exists
    if (!uNode)
    {
        printf("%s not found\n", name);
        return;
    }

    // use <count> tickets 
    uNode = useTickets(rootPtr, uNode, count);

    // if node is deleted then return
    if (!uNode) return;

    // if node still exists, print name, new ticket count, and depth
    printf("%s %d %d\n", uNode->fanName, uNode->numTickets, *depth);
}

void handleFindCommand(node* root, char name[SIZE], int* depth)
{
    // find node
    node* fNode = getNode(root, name, depth);

    // declare not found if not exists
    if (!fNode)
    {
        printf("%s not found\n", name);
        return;
    }

    // if found, print name, tickets, and depth
    printf("%s %d %d\n", fNode->fanName, fNode->numTickets, *depth);
}

void handleMeanTicketsCommand(node* root)
{
    // obtain number of nodes in tree
    int nodes = getNodeCount(root);

    // if nodes == 0, display "0.00" to avoid division by 0
    if (nodes == 0)
    {
        printf("0.00\n");
        return;
    }

    // display value of mean tickets
    printf("%.2f\n", getTickets(root) / (double)nodes);
}

void handleHeightBalanceCommand(node* root)
{
    // calculate the heights of the left and right subtrees
    int lh = getHeight(root->left), rh = getHeight(root->right);

    // print the tree heights
    printf("left height = %d right height = %d ", lh, rh);

    // output the balance
    if (lh == rh)
        printf("balanced\n");
    else
        printf("not balanced\n");
}

void handleCountBeforeCommand(node* root, char name[SIZE])
{
    // print the number of tickets before or at <name>
    printf("%d\n", countBefore(root, name));
}

//
// output functions
//

node* getNode(node* root, char name[SIZE], int* depth)
{
    // if no tree exists, return null
    if (!root) return NULL;

    // if name is equal to current node, then return this node
    if (strcmp(name, root->fanName) == 0)
        return root;

    // increase depth counter
    (*depth)++;

    // search through bst
    if (strcmp(name, root->fanName) < 0)
        return getNode(root->left, name, depth);
    else
        return getNode(root->right, name, depth);
}

node* useTickets(node** rootPtr, node* curr, int count)
{
    // decrement ticket count
    curr->numTickets -= count;

    // if fan has no more tickets, delete
    if (curr->numTickets <= 0)
    {
        printf("%s deleted\n", curr->fanName);
        deleteNode(rootPtr, curr);
        return NULL;
    }

    // return node again if not deleted
    return curr;
}

void deleteNode(node** rootPtr, node* delNode)
{
    // find parent of delNode
    node* par = parent(*rootPtr, delNode);
    node* saveNode = NULL;

    // handle different cases for delNode
    if(isLeaf(delNode))
    {
        deleteLeaf(rootPtr, delNode, par);
        return;
    }
    else if (hasOnlyLeftChild(delNode))
    {
        deleteHasOnlyLeftChild(delNode, par, saveNode);
        return;
    }
    else if (hasOnlyRightChild(delNode))
    {
        deleteHasOnlyRightChild(delNode, par, saveNode);
        return;
    }

    deleteHasTwoChildren(*rootPtr, delNode);
}

int getHeight(node* root)
{
    // return -1 if tree has no height
    if (!root) return -1;

    // find heights of each side of tree
    int lh = getHeight(root->left);
    int rh = getHeight(root->right);

    // return the largest value
    if (lh > rh)
        return lh + 1;
    return rh + 1;
}

int getNodeCount(node* root)
{
    // find the number of nodes in the tree
    if (!root)
        return 0;
    return 1 + getNodeCount(root->left) + getNodeCount(root->right);
}

int getTickets(node* root)
{
    // find the sum of tickets in the tree
    if (!root)
        return 0;
    return root->numTickets + getTickets(root->left) + getTickets(root->right);
}

int countBefore(node* root, char name[SIZE])
{
    // if no tree exists, return 0
    if (!root)
        return 0;

    // obtain the total number of tickets for all nodes before ,name.
    if (strcmp(name, root->fanName) >= 0)
        return root->numTickets + countBefore(root->left, name) + countBefore(root->right, name);
    else
        return countBefore(root->left, name);
}

//
// auxiliary functions
//

void deleteLeaf(node** rootPtr, node* delNode, node* par)
{
    // if node is root node
    if (!par)
    {
        // free the tree and make the root NULL
        free(*rootPtr);
        *rootPtr = NULL;
        return;
    }
    // if node is left of parent
    if (strcmp(delNode->fanName, par->fanName) < 0)
    {
        // free node and make parent NULL
        free(par->left);
        par->left = NULL;
    }
    // if node is right of parent
    else
    {
        // free node and make parent NULL
        free(par->right);
        par->right = NULL;
    }
}

void deleteHasOnlyLeftChild(node* delNode, node* par, node* saveNode)
{
    // if node is root node
    if (!par)
    {
        // replace root with the left child
        saveNode = delNode->left;
        free(delNode);
        return;
    }
    // if node is left of parent
    if (strcmp(delNode->fanName, par->fanName) < 0)
    {
        // replace left of parent with left of deleted node
        saveNode = par->left;
        par->left = par->left->left;
    }
    // if node is right of parent
    else
    {
        // replace right of parent with left of deleted node
        saveNode = par->right;
        par->right = par->right->left;
    }
    free(saveNode);
    return;
}

void deleteHasOnlyRightChild(node* delNode, node* par, node* saveNode)
{
    // if node is root node
    if (!par)
    {
        // replace root with the right child
        saveNode = delNode->right;
        free(delNode);
        return;
    }
    // if node is left of parent
    if (strcmp(delNode->fanName, par->fanName) < 0)
    {
        // replace left of parent with right of deleted node
        saveNode = par->left;
        par->left = par->left->right;
    }
    // if node is right of parent
    else
    {
        // replace right of parent with right of deleted node
        saveNode = par->right;
        par->right = par->right->right;
    }
    free(saveNode);
    return;
}

void deleteHasTwoChildren(node* root, node* delNode)
{
    // find the max value of the left subtree to replace the deleted node
    node* leftMaxNode = maxVal(delNode->left);

    // save the values of the node found
    char saveName[SIZE];
    strcpy(saveName, leftMaxNode->fanName);
    int saveTickets = leftMaxNode->numTickets;

    // delete the max found node
    deleteNode(&root, leftMaxNode);

    // replace the "deleted" node's values with leftMaxVal
    strcpy(delNode->fanName, saveName);
    delNode->numTickets = saveTickets;
}

//
// free functions
//

// free all nodes in tree (post-order)
void freeTree(node* root)
{
    if (root)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

//
// helper functions
//

// return the parent of node
node* parent(node* root, node* node)
{
    // return null if no tree exists or node is the root
    if (!root || root == node)
        return NULL;
    // return the current root if either child is node
    if (root->left == node || root->right == node)
        return root;
    // search through tree if above cases do not match
    if (strcmp(node->fanName, root->fanName) < 0)
        return parent(root->left, node);
    else
        return parent(root->right, node);
    // return null if node does not exist
    return NULL;
}

node* maxVal(node* root)
{
    // return the max value of tree
    if (!root->right)
        return root;
    return maxVal(root->right);
}

int isLeaf(node* node)
{
    return (!node->left && !node->right);
}

int hasOnlyLeftChild(node* node)
{
    return (node->left && !node->right);
}

int hasOnlyRightChild(node* node)
{
    return (!node->left && node->right);
}