/* COP 3502C Assignment 6
This program is written by: Kauan Lima */
// imports
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definitions
#define MAXSTLEN 29
#define TABLESIZE 300007

// global vars
int budget = 100000;
int complexity = 0;

// structs
typedef struct merchandise
{
    char name[MAXSTLEN + 1]; // e.g., "braziljersey"
    int quantity;            // stock available
    int price;               // sale price per item
} merchandise;

typedef struct inventoryNode
{
    merchandise *merchPtr;
    struct inventoryNode *next;
} inventoryNode;

typedef struct inventoryTable
{ // Hash table
    inventoryNode **lists;
    int size; // number of buckets (table size)
} inventoryTable;

// prototypes
merchandise *createMerch(char name[MAXSTLEN + 1], int quantity);
inventoryNode *insertNode(inventoryNode *front, merchandise *m);
void initTable(inventoryTable *table);
int hashfunction(char *word, int size);
void insertTable(inventoryTable *t, merchandise *m, int hashVal);
void buy(inventoryTable *t, char item[], int quantity, int totalPrice, int hashVal);
void handleBuyCmd(inventoryTable *t, char item[], int quantity, int totalPrice);
void sell(inventoryNode *front, char item[], int quantity);
void handleSellCmd(inventoryTable *t, char item[], int quantity);
void ChangePrice(inventoryNode *front, char item[], int newPrice);
void handleChangePriceCmd(inventoryTable *t, char item[], int newPrice);
void dellist(inventoryNode *i);
void freeTable(inventoryTable *t);

int main(void)
{
    // create the hashTable
    inventoryTable table;
    initTable(&table);

    // obtain the # of iterations
    int numCmd;
    scanf("%d", &numCmd);

    // declare necessary variables
    char cmd[MAXSTLEN + 1], item[MAXSTLEN + 1];
    int quantity, totalPrice, newPrice;

    // loop through the program
    for (int i = 0; i < numCmd; i++)
    {
        // scan the common elements between each command
        scanf("%s %s", cmd, item);

        // handle commands
        if (strcmp(cmd, "buy") == 0)
        {
            scanf("%d %d", &quantity, &totalPrice);
            handleBuyCmd(&table, item, quantity, totalPrice);
        }
        else if (strcmp(cmd, "change_price") == 0)
        {
            scanf("%d", &newPrice);
            handleChangePriceCmd(&table, item, newPrice);
        }
        else if (strcmp(cmd, "sell") == 0)
        {
            scanf("%d", &quantity);
            handleSellCmd(&table, item, quantity);
        }
    }

    // print final budget and complexity
    printf("%d\n", budget);
    printf("%d\n", complexity);

    // free memory
    freeTable(&table);
}

// functions
merchandise *createMerch(char name[MAXSTLEN + 1], int quantity)
{
    // return a newly created merchandise
    merchandise *m = (merchandise *)malloc(sizeof(merchandise));
    strcpy(m->name, name);
    m->quantity = quantity;
    m->price = 0;
    return m;
}

inventoryNode *insertNode(inventoryNode *front, merchandise *m)
{
    // return a newly created node
    inventoryNode *i = (inventoryNode *)malloc(sizeof(inventoryNode));
    i->merchPtr = m;
    i->next = front;
    return i;
}

void initTable(inventoryTable *table)
{
    // allocate memory for array
    table->lists = (inventoryNode **)calloc(TABLESIZE, sizeof(inventoryNode *));
    table->size = TABLESIZE;
}

int hashfunction(char *word, int size)
{
    int len = strlen(word);
    int hvalue = 0;
    for (int i = 0; i < len; i++)
        hvalue = (1151 * hvalue + (word[i] - 'a')) % size;
    return hvalue;
}

void insertTable(inventoryTable *t, merchandise *m, int hashVal)
{
    // insert item in linked list at hashVal and print
    t->lists[hashVal] = insertNode(t->lists[hashVal], m);
    printf("%s %d %d\n", m->name, m->quantity, budget);
}

void buy(inventoryTable *t, char item[], int quantity, int totalPrice, int hashVal)
{
    int k = 1;
    inventoryNode *front = t->lists[hashVal];

    // walk through linked list
    while (front)
    {
        merchandise *currMerch = front->merchPtr;

        // when item found, update quantity and complexity
        if (strcmp(front->merchPtr->name, item) == 0)
        {
            complexity += k;
            currMerch->quantity += quantity;
            budget -= totalPrice;
            printf("%s %d %d\n", currMerch->name, currMerch->quantity, budget);
            return;
        }
        front = front->next;
        k++;
    }
    // if item not found, create new item
    merchandise *merch = createMerch(item, quantity);
    budget -= totalPrice;
    complexity += k;
    insertTable(t, merch, hashVal);
}

void handleBuyCmd(inventoryTable *t, char item[], int quantity, int totalPrice)
{
    // calculate hash and buy item
    int hashVal = hashfunction(item, t->size);
    buy(t, item, quantity, totalPrice, hashVal);
}

void sell(inventoryNode *front, char item[], int quantity)
{
    int k = 1;

    // walk through linked list
    while (front)
    {
        merchandise *currMerch = front->merchPtr;
        int stock = quantity;
        // when item found, update quantity and complexity
        if (strcmp(currMerch->name, item) == 0)
        {
            complexity += k;
            if (currMerch->quantity - quantity < 0)
            {
                stock = currMerch->quantity;
                currMerch->quantity = 0;
            }
            else
                currMerch->quantity -= quantity;
            budget += (stock * currMerch->price);
            printf("%s %d %d\n", currMerch->name, currMerch->quantity, budget);
            return;
        }
        front = front->next;
        k++;
    }
}

void handleSellCmd(inventoryTable *t, char item[], int quantity)
{
    // calculate hash and sell item
    int hashVal = hashfunction(item, t->size);
    sell(t->lists[hashVal], item, quantity);
}

void ChangePrice(inventoryNode *front, char item[], int newPrice)
{
    int k = 1;

    // walk through linked list
    while (front)
    {
        merchandise *currMerch = front->merchPtr;

        // when item found, update price and complexity
        if (strcmp(currMerch->name, item) == 0)
        {
            complexity += k;
            currMerch->price = newPrice;
            return;
        }
        // iterate
        front = front->next;
        k++;
    }
}

void handleChangePriceCmd(inventoryTable *t, char item[], int newPrice)
{
    // calculate hash and change price of specified item
    int hashVal = hashfunction(item, t->size);
    ChangePrice(t->lists[hashVal], item, newPrice);
}

// free linked list memory
void dellist(inventoryNode *i)
{
    // iterate to end of list and free from back
    if (i)
    {
        dellist(i->next);
        free(i->merchPtr);
        free(i);
    }
}

// free table memory
void freeTable(inventoryTable *t)
{
    // iterate through table to delete present linked lists
    for (int i = 0; i < TABLESIZE; i++)
        dellist(t->lists[i]);
    // free table
    free(t->lists);
}