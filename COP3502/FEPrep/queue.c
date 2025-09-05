// imports
#include <stdio.h>
#include <stdlib.h>

// structs
typedef struct node
{
    int data;
    struct node *next;
} node;

typedef struct deque
{
    node *front;
    node *back;
} deque;

// functions
deque *makeEmptyDeque()
{
    deque *tmp = malloc(sizeof(deque));
    tmp->front = tmp->back = NULL;
    return tmp;
}

node *makeNode(int val)
{
    node *tmp = malloc(sizeof(node));
    tmp->data = val;
    tmp->next = NULL;
    return tmp;
}

void addFront(deque *myDeque, int val)
{
    node *newFront = makeNode(val);
    newFront->next = myDeque->front;
    myDeque->front = newFront;
    if (!myDeque->back)
        myDeque->back = newFront;
}

// main
int main(void)
{
}