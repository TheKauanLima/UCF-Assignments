//Lab 6 Skeleton Code
//Original code modified by Adam Betinsky on 2/10/2025
//This code shows performing various operations on linked list recursively.
// insert, delete, free, display, copy

/* COP 3502C Lab 6
This program is finished by: Kauan Lima*/

#include<stdio.h>
#include <stdlib.h>
#include "leak_detector_c.h"//MAKE SURE TO GET THE MEMORY LEAK DETECTOR FILES!!

struct node {
    int data;
    struct node *next;
};

void freeList2(struct node *list)
{
    if (!list) return;
    freeList2(list->next);
    free(list);
}

struct node* insert(struct node* list,int item);

struct node* del(struct node* list,int item);
void print( struct node *list);
void freeList(struct node* list);
void copy (struct node *source, struct node **dest);

int main( )
{
    atexit(report_mem_leak); //for leak detector

    int number = 0, choice=0;
    struct node *pList=NULL;
    struct node *nList = NULL;

    // Let the user add values until they enter -1.
    while(choice!= 4)
    {
        // Get the operation.
        printf("\nDo you want to (1)insert, (2)delete, (3)Copy, (4)quit.\n");
        scanf("%d", &choice);

        printf("Your choice is %d\n", choice);

        // Execute the operation.
        if (choice == 1)
        {
            // Get the number.
            printf("Enter the value to insert\n");
            scanf("%d", &number);
            pList = insert(pList, number);
            // Look at the list.
            printf("Items in linked list: ");
            print(pList);
            //printf("\n");
        }
        else if (choice == 2)
        {    // Get the number.
            printf("Enter the value to delete.\n");
            scanf("%d", &number);
            pList = del(pList, number);
            // Look at the list.
            printf("Items in linked list: ");
            print(pList);
            //printf("\n");
        }
        else if (choice == 3)
        {
            if (nList)
                freeList(nList);

            copy(pList, &nList); //passing reference of nList as it is not returning anything
            // Look at the list.
            printf("Items in NEW linked list: ");
            print(nList);
            // printf("\n");
        }
        else
        {
            break;
        }

    }
    freeList2(nList);
    freeList2(pList);
    printf("\nBye..\n");
    return 0;
}


/* copies a linked list into another */
void copy (struct node *source, struct node **dest)
{
    if (source)
    {
        *dest = (struct node*)malloc(sizeof(struct node));
        (*dest)->data = source->data;
        (*dest)->next = NULL;

        copy(source->next, &(*dest)->next);
    }
}

// Recursively inserts item into the LL pointed to by list.
struct node* insert(struct node *list, int item)
{
    if(!list || item <= list->data)
    {
        struct node* pnew = (struct node*)malloc(sizeof(struct node));
        pnew->data = item;
        pnew->next = list;
        return pnew;
    }
    list->next = insert(list->next, item);
    return list;
}

// Recursively deletes the first node storing item in the list pointed to
// by list. If no such node exists, no changes are made. a pointer to the front
// of the resulting list is returned.
struct node* del(struct node *list, int item)
{
    if (!list)
        return NULL;

    if(list -> data == item)
    {
        struct node* rest = list->next;
        free(list);
        return rest;
    }
    list->next = del(list->next, item);
    return list;
}

//I will show you how to do this function ITERATIVELY. You need to complete it RECURSIVELY on your own
void print(struct node *list)
{
    if (!list)
        return;

    printf("->%d", list->data);
    print(list->next);
}

//I will show you how to do this function ITERATIVELY. You need to complete it RECURSIVELY on your own
void freeList(struct node* list)
{
    if (!list)
        return;

    freeList(list->next);
    free(list);
}
