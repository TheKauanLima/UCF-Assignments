#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

void addN(struct node* list, int n)
{
    while (list != NULL)
    {
        list->data += n;
        list = list->next;
    }
}

struct node* deleteFirst(struct node* list)
{
    if (list == NULL) return NULL;
    struct node* newHead = list->next;
    free(list);
    return newHead;
}

struct node* copy(struct node* list)
{
    if (list == NULL) return NULL;

    struct node* head = list;
    struct node* newList = NULL;

    while (list != NULL)
    {
        newList = (struct node*)malloc(sizeof(struct node));
        
    }

    return newList;
}

int main(void)
{

}