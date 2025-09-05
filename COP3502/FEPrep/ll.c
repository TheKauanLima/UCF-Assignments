// imports
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structs
typedef struct node
{
    int data;
    struct node *next;
} node;

// functions
node *createNode(int val)
{
    node *n = malloc(sizeof(node));
    n->data = val;
    n->next = NULL;
    return n;
}

node *insertToList(node *front, node *n)
{
    if (!front)
        return n;

    node *walker = front;
    while (walker)
    {
        if (walker->next)
            walker = walker->next;
        walker->next = n;
    }
    return front;
}

void printList(node *front)
{
    while (front)
    {
        printf("%d - > ", front->data);
        front = front->next;
    }
}

int numDirChange(node *front)
{
    int sum = 0;
    if (!front || !front->next || !front->next->next)
        return 0;

    while (front->next->next)
    {
        if (front > front->next)
            if (front->next < front->next->next)
                sum++;
        if (front < front->next)
            if (front->next > front->next->next)
                sum++;
        front = front->next;
    }
    return sum;
}

// main
int main(void)
{
    node *front = NULL;
    node *node = NULL;

    int numCmd;
    scanf("%d", &numCmd);
    for (int i = 0; i < numCmd; i++)
    {
        int val;
        scanf("%d", &val);
        node = createNode(val);
        front = insertToList(front, node);
    }
    printList(front);
}