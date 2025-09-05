// imports
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structs
typedef struct
{
    char **sentences;
    int numSentences;
    char *title;
    char *author;
} book_t;

typedef struct node_s
{
    int x;
    int y;
    struct node_s *next;
} node_t;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

// functions
void cleanUp(book_t *lib, int numBooks)
{
    for (int i = 0; i < numBooks; i++)
    {
        for (int j = 0; j < lib[i].numSentences; j++)
        {
            free(lib[i].sentences[j]);
        }
        free(lib[i].sentences);
        free(lib[i].title);
        free(lib[i].author);
    }
    free(lib);
}

node_t *merge2DCoordinates(node_t *ptr1, node_t *ptr2)
{
    if (!ptr1 || !ptr2 || ptr1->x >= ptr2)
        return NULL;

    node_t *retList;

    if (ptr1->x < ptr2->x)
        retList = ptr1;
    else if (ptr1->x > ptr2->x)
        retList = ptr2;
    else
    {
        if (ptr1->y < ptr2->y)
            retList = ptr1;
        else if (ptr1->y > ptr2->y)
            retList = ptr2;
    }

    merge2DCoordinates(ptr1->next, ptr2);
    return retList;
}

int sumAtDepth(node *root, int depth)
{
    if (!root)
        return NULL;
    if (depth == 0)
        return root->data;

    int left = sumAtDepth(root->left, depth - 1);
    int right = sumAtDepth(root->right, depth - 1);
    return left + right;
}

int isMinHeap(int arr[], int size)
{
    for (int i = 2; i < size; i++)
    {
        if (arr[i / 2] > arr[i])
            return 0;
    }
    return 1;
}

// main
int main(void)
{
}