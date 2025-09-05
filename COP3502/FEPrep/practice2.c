// imports
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definitions
#define EMPTY 0
#define X 1
#define O 2

// structs
typedef struct
{
    char *name;
    int year;
    double price;
} videogame_t;

typedef struct node_s
{
    int data;
    struct node_s *next;
} node_t;

typedef struct
{
    node_t *top;
} stack_t;

typedef struct heap
{
    int *elements;
    int capacity;
    int size;
} heapStruct;

typedef struct trieNode
{
    int isWord;
    struct trieNode *children[26];
} trieNode;

// functions
videogame_t *getClassicGames(videogame_t *inventory, int n, int *ptrNumGames)
{
    videogame_t *res = malloc(n * sizeof(videogame_t));
    int nG = 0;
    for (int i = 0; i < n; i++)
    {
        if (inventory[i].year >= 1980 && inventory[i].year < 1990)
        {
            int len = strlen(inventory[i].name);
            res[nG].name = malloc(sizeof(char) * (len + 1));
            strcpy(res[nG].name, inventory[i].name);
            res[nG].year = inventory[i].year;
            res[nG].price = inventory[i].price;
            nG++;
        }
    }
    res = realloc(res, nG * sizeof(videogame_t));
    *ptrNumGames = nG;
    return res;
}

node_t *flipHalf(node_t *head, int n)
{
    node_t *backNode = head;
    while (backNode->next)
        backNode = backNode->next;
    backNode->next = head;
    for (int i = 1; i < n / 2; i++)
        head = head->next;
    node_t *retHead = head->next;
    head->next = NULL;
    return retHead;
}

int evens(int *arr, int len, int lowInd, int hiInd)
{
    if (lowInd > hiInd)
        return 0;

    int check = 0;
    if (arr[lowInd] % 2 == 0)
        check = 1;
    return check + evens(arr, len, lowInd + 1, hiInd);
}

void cellPress(int row, int col, int height, int width, int *grid)
{
    grid[row] ^= (1 << col);
    if (col)
        grid[row] ^= (1 << (col - 1));
    if (row)
        grid[row - 1] ^= (1 << (col));
    if (col < width - 1)
        grid[row] ^= (1 << (col + 1));
    if (row < height - 1)
        grid[row + 1] ^= (1 << (col));
}

node_t *moveHeadNearTail(node_t *head)
{
    node_t *oldHead = head;
    node_t *newHead = head->next;
    while (head->next->next)
        head = head->next;
    oldHead->next = head->next;
    head->next = oldHead;
    return newHead;
}

int computeScore(char *moves)
{
    stack_t s;
    init(&s);

    int x;
    int y;
    for (int i = 0; moves[i] != '\0'; i++)
    {
        if (strcmp(moves[i], '+') == 0)
        {
            x = pop(&s);
            y = pop(&s);
            push(&s, y);
            push(&s, x);
            push(&s, x + y);
            continue;
        }
        push(&s, moves[i]);
    }
    int sum = 0;
    while (!empty(&s))
        sum += pop(&s);
    return sum;
}

int removeMin(heapStruct *h);
int size(heapStruct *h);

int *heapSort(heapStruct *h)
{
    int heapSize = size(h);
    int *heapArray = malloc(sizeof(int) * heapSize);
    for (int i = 0; i < heapSize; i++)
        heapArray[i] = removeMin(h);
    return heapArray;
}

int num5LetterWrapper(trieNode *root)
{
    return num5Rec(root, 0);
}

int num5Rec(trieNode *root, int k)
{
    if (!root)
        return 0;

    if (k == 5)
        return root->isWord;

    int retVal = 0;
    for (int i = 0; i < 26; i++)
        retVal += num5Rec(root->children[i], k + 1);
    return retVal;
}

int XWin(int **board);
int XLose(int **board);
int tied(int **board);

int canXWin(int **board, int myTurn)
{
    if (tied(board) || XLose(board))
        return 0;
    if (XWin(board))
        return 1;
}

// main
int main(void)
{
}