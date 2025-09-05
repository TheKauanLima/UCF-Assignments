// imports
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// definitions

// structs
typedef struct node
{
    char letter;
    struct node *next;
} node_1;

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

// functions
int **getPascalsTriangle(int n)
{
    int **pt = malloc(sizeof(int *) * n);

    for (int i = 0; i < n; i++)
    {
        pt[i] = malloc(sizeof(int) * (i + 1));
        pt[i][0] = 1;
        pt[i][i] = 1;
        for (int j = 1; j < i; j++)
            pt[i][j] = pt[i - 1][j - 1] + pt[i - 1][j];
    }
    return pt;
}

void printMixed(node_1 *word1, node_1 *word2)
{
    while (word1 && word2)
    {
        printf("%c", word1->letter);
        printf("%c", word2->letter);
        word1 = word1->next;
        word2 = word2->next;
    }

    while (word1)
    {
        printf("%c", word1->letter);
        word1 = word1->next;
    }

    while (word2)
    {
        printf("%c", word2->letter);
        word2 = word2->next;
    }
}

node *prune(node *root)
{
    if (!root)
        return NULL;

    if (!root->left && !root->right)
    {
        free(root);
        return NULL;
    }

    root->left = prune(root->left);
    root->right = prune(root->right);

    return root;
}

// main
int main(void)
{
}