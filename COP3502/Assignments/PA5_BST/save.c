/* COP 3502C Assignment 5
This program is written by: Kauan Lima */
// imports
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definitions
#define SIZE 31

// structs
typedef struct bstnode
{
    char fanName[SIZE];
    int numTickets;
    struct bstnode* left;
    struct bstnode* right;
}node;

// prototypes
// tree functions
node* createNode(char name[SIZE], int count);
node* insertNode(node* root, node* node);

// command functions
node* useNode(node* root, node* curr, int count, int* dC);
node* findNode(node* root, char name[SIZE]);
void heightBalance(node* root);
void meanTickets(node* root);
int countBefore(node* root, char name[SIZE]);

// output funtions
int findDepth(node* root, node* node);
int getHeight(node* root);
int getNodes(node* root);
int getTickets(node* root);
node* deleteNode(node* root, node* delNode);

// auxiliary functions
void deleteLeaf(node* root, node* delNode, node* par);
node* deleteHasOnlyLeftChild(node* delNode, node* par);
node* deleteHasOnlyRightChild(node* delNode, node* par);
node* deleteHasTwoChildren(node* root, node* delNode);

// helper functions
node* parent(node* root, node* node);
node* maxVal(node* root);
int isLeaf(node* node);
int hasOnlyLeftChild(node* node);
int hasOnlyRightChild(node* node);

// free all
void freeTree(node* root);

// void postOrder(node* root)
// {
//     if (root)
//     {
//         postOrder(root->left);
//         postOrder(root->right);
//         printf("%s %d, ", root->fanName, root->numTickets);
//     }
// }

// main
int main(void)
{
    // obtain number of commands
    int numCmd;
    scanf("%d", &numCmd);

    // declare necessary variables
    node *root = NULL, *newNode = NULL, *fNode = NULL, *uNode = NULL;
    int depth;

    for (int i = 0; i < numCmd; i++)
    {
        //postOrder(root);
        //printf("\n");

        // obtain primary command
        char cmd[SIZE];
        scanf("%s", cmd);
        if (strcmp(cmd, "mean_tickets") == 0)
        {
            // calculate the mean tickets of all nodes
            meanTickets(root);
            continue;
        }
        else if (strcmp(cmd, "height_balance") == 0)
        {
            // check the balance of the left and right subtrees
            heightBalance(root);
            continue;
        }

        // obtain name of node
        char name[SIZE];
        scanf("%s", name);
        if (strcmp(cmd, "find") == 0)
        {
            // find node in tree and report its information
            fNode = findNode(root, name);
            if (fNode)
            {
                depth = findDepth(root, fNode);
                printf("%s %d %d\n", fNode->fanName, fNode->numTickets, depth);
            }
            else
                printf("%s not found\n", name);
            continue;
        }
        else if (strcmp(cmd, "count_before") == 0)
        {
            // sum all tickets before or at a certain node
            printf("%d\n", countBefore(root, name));
            continue;
        }

        // obtain ticket count to manipulate
        int count;
        scanf("%d", &count);
        if (strcmp(cmd, "buy") == 0)
        {
            
            fNode = findNode(root, name);
            if (!fNode)
            {
                newNode = createNode(name, count);
                root = insertNode(root, newNode);
                fNode = newNode;
            }
            else
                fNode->numTickets += count;

            depth = findDepth(root, fNode);
            printf("%s %d %d\n", fNode->fanName, fNode->numTickets, depth);
        }
        else if (strcmp(cmd, "use") == 0)
        {
            uNode = findNode(root, name);
            int rootCheck = (root == uNode);
            if (uNode)
            {
                int deleteCheck;
                uNode = useNode(root, uNode, count, &deleteCheck);
                if (rootCheck && deleteCheck)
                    root = NULL;

                if (uNode && !deleteCheck)
                {
                    depth = findDepth(root, uNode);
                    printf("%s %d %d\n", uNode->fanName, uNode->numTickets, depth);
                }
            }
            else
                printf("%s not found\n", name);
        }
    }

    freeTree(root);
}

// functions
// create node in bst
node* createNode(char name[SIZE], int count)
{
    // allocate necessary size and fill in node
    node* n = (node*)malloc(sizeof(node));
    strcpy(n->fanName, name);
    n->numTickets = count;
    n->left = NULL;
    n-> right = NULL;
    return n;
}

// return the depth of a node
int findDepth(node* root, node* node)
{
    // node not found
    if (!root)
        return -1;

    // node found
    if (node == root)
        return 0;
    
    // return depth
    int depth;
    if (strcmp(node->fanName, root->fanName) < 0)
        depth = findDepth(root->left, node);
    else
        depth = findDepth(root->right, node);

    if (depth == -1)
        return -1;

    return depth + 1;
}

// insert node to tree
node* insertNode(node* root, node* node)
{
    if (!root)
        return node;
    
    if (strcmp(node->fanName, root->fanName) < 0)
    {
        if (root->left)
            root->left = insertNode(root->left, node);
        else
            root->left = node;
    }
    else
    {
        if (root->right)
            root->right = insertNode(root->right, node);
        else
            root->right = node;
    }
    return root;
}

node* findNode(node* root, char name[SIZE])
{
    if (root)
    {
        if (strcmp(name, root->fanName) == 0)
            return root;
        else if (strcmp(name, root->fanName) < 0)
            return findNode(root->left, name);
        else
            return findNode(root->right, name);
    }
    return NULL;
}

int countBefore(node* root, char name[SIZE])
{
    if (!root)
        return 0;

    if (strcmp(name, root->fanName) >= 0)
        return root->numTickets + countBefore(root->left, name) + countBefore(root->right, name);
    else
        return countBefore(root->left, name);
}

int getHeight(node* root)
{
    if (!root) return -1;

    int lh = getHeight(root->left);
    int rh = getHeight(root->right);

    if (lh > rh)
        return lh + 1;
    return rh + 1;
}

void heightBalance(node* root)
{
    int lh = getHeight(root->left), rh = getHeight(root->right);

    printf("left height = %d ", lh);
    printf("right height = %d ", rh);
    if (lh == rh)
        printf("balanced");
    else
        printf("not balanced");
    printf("\n");
}

int getNodes(node* root)
{
    if (!root)
        return 0;
    return 1 + getNodes(root->left) + getNodes(root->right);
}

int getTickets(node* root)
{
    if (!root)
        return 0;
    return root->numTickets + getTickets(root->left) + getTickets(root->right);
}

// node* useNode(node* root, node* curr, int count, int* dC)
// {
//     curr->numTickets -= count;

//     if (curr->numTickets <= 0)
//     {
//         printf("%s deleted\n", curr->fanName);
//         curr = deleteNode(root, curr);
//         dC = 1;
//         return curr;
//     }

//     dC = 0;
//     return curr;
// }

node* useNode(node* root, node* curr, int count, int* deleteCheck)
{
    curr->numTickets -= count;

    if (curr->numTickets <= 0)
    {
        printf("%s deleted\n", curr->fanName);
        *deleteCheck = 1;
        return deleteNode(root, curr);
    }

    *deleteCheck = 0;
    return curr;
}

void deleteLeaf(node* root, node* delNode, node* par)
{
    if (!par)
        return;

    if (strcmp(delNode->fanName, par->fanName) < 0)
    {
        free(par->left);
        par->left = NULL;
    }
    else
    {
        free(par->right);
        par->right = NULL;
    }
}

node* deleteHasOnlyLeftChild(node* delNode, node* par)
{
    if (!par)
    {
        node* newRoot = delNode->left;
        free(delNode);
        return newRoot;
    }

    if (strcmp(delNode->fanName, par->fanName) < 0)
    {
        par->left = delNode->left;
    }
    else
    {
        par->right = delNode->left;
    }

    free(delNode);
    return NULL;
}

node* deleteHasOnlyRightChild(node* delNode, node* par)
{
    if (!par)
    {
        node* newRoot = delNode->right;
        free(delNode);
        return newRoot;
    }

    if (strcmp(delNode->fanName, par->fanName) < 0)
    {
        par->left = delNode->right;
    }
    else
    {
        par->right = delNode->right;
    }

    free(delNode);
    return NULL;
}

node* deleteHasTwoChildren(node* root, node* delNode)
{
    node* pred = maxVal(delNode->left);

    // Copy data from predecessor
    char nameCopy[SIZE];
    strcpy(nameCopy, pred->fanName);
    int ticketCopy = pred->numTickets;

    root = deleteNode(root, pred);  // Delete predecessor recursively

    strcpy(delNode->fanName, nameCopy);
    delNode->numTickets = ticketCopy;

    return root;
}

node* deleteNode(node* root, node* delNode)
{
    node* par = parent(root, delNode);

    if (isLeaf(delNode))
    {
        if (par == NULL)  // deleting root and it's the only node
        {
            free(delNode);
            return NULL;
        }
        deleteLeaf(root, delNode, par);
        return root;
    }
    else if (hasOnlyLeftChild(delNode))
    {
        node* newRoot = deleteHasOnlyLeftChild(delNode, par);
        return (par == NULL) ? newRoot : root;
    }
    else if (hasOnlyRightChild(delNode))
    {
        node* newRoot = deleteHasOnlyRightChild(delNode, par);
        return (par == NULL) ? newRoot : root;
    }

    return deleteHasTwoChildren(root, delNode);
}

// node* deleteNode(node* root, node* delNode)
// {
//     node *par = NULL, *saveNode = NULL;
//     par = parent(root, delNode);

//     if(isLeaf(delNode))
//     {
//         deleteLeaf(root, delNode, par);
//         return NULL;
//     }
//     else if (hasOnlyLeftChild(delNode))
//     {
//         saveNode = deleteHasOnlyLeftChild(delNode, par, saveNode);
//         return saveNode;
//     }
//     else if (hasOnlyRightChild(delNode))
//     {
//         saveNode = deleteHasOnlyRightChild(delNode, par, saveNode);
//         return saveNode;
//     }

//     saveNode = deleteHasTwoChildren(root, delNode, saveNode);
//     return saveNode;
// }

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


void meanTickets(node* root)
{
    int nodes = getNodes(root);
    if (nodes == 0)
    {
        printf("0.00\n");
        return;
    }
    printf("%.2f\n", getTickets(root) / (double)nodes);
}

// auxiliary functions
// void deleteLeaf(node* root, node* delNode, node* par)
// {
//     if (!par)
//     {
//         free(root);
//         return;
//     }

//     if (strcmp(delNode->fanName, par->fanName) < 0)
//     {
//         free(par->left);
//         par->left = NULL;
//     }
//     else
//     {
//         free(par->right);
//         par->right = NULL;
//     }
// }

// node* deleteHasOnlyLeftChild(node* delNode, node* par, node* saveNode)
// {
//     if (par == NULL)
//     {
//         saveNode = delNode->left;
//         free(delNode);
//         return saveNode;
//     }
//     if (strcmp(delNode->fanName, par->fanName) < 0)
//     {
//         saveNode = par->left;
//         par->left = par->left->left;
//         free(saveNode);
//     }
//     else
//     {
//         saveNode = par->right;
//         par->right = par->right->right;
//         free(saveNode);
//     }
//     return NULL;
// }

// node* deleteHasOnlyRightChild(node* delNode, node* par, node* saveNode)
// {
//     if (par == NULL)
//     {
//         saveNode = delNode->right;
//         free(delNode);
//         return saveNode;
//     }
//     if (strcmp(delNode->fanName, par->fanName) < 0)
//     {
//         saveNode = par->left;
//         par->left = par->left->right;
//         free(saveNode);
//     }
//     else
//     {
//         saveNode = par->right;
//         par->right = par->right->right;
//         free(saveNode);
//     }
//     return NULL;
// }

// node* deleteHasTwoChildren(node* root, node* delNode, node* saveNode)
// {
//     node* newNode = maxVal(delNode->left);
//     saveNode = newNode;
//     char saveName[SIZE];
//     strcpy(saveName, newNode->fanName);
//     int saveTickets = newNode->numTickets;

//     deleteNode(root, saveNode);

//     strcpy(delNode->fanName, saveName);
//     delNode->numTickets = saveTickets;
//     return delNode;
// }

// helper functions
node* parent(node* root, node* node)
{
    if (!root || root == node)
        return NULL;
    if (root->left == node || root->right == node)
        return root;
    if (strcmp(node->fanName, root->fanName) < 0)
        return parent(root->left, node);
    else if (strcmp(node->fanName, root->fanName) > 0)
        return parent(root->right, node);
    return NULL;
}

node* maxVal(node* root)
{
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

// if (!par)
        // {
        //     saveNode = delNode->left;
        //     free(delNode);
        //     return saveNode;
        // }
        // if (strcmp(delNode->fanName, par->fanName) < 0)
        // {
        //     saveNode = par->left;
        //     par->left = par->left->left;
        //     free(saveNode);
        // }
        // else
        // {
        //     saveNode = par->right;
        //     par->right = par->right->left;
        //     free(saveNode);
        // }
        // return root;