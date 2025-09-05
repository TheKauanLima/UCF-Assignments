#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct heap
{
    int *heapArray;
    int capacity;
    int size;
} heap;

int numElements;

heap *init()
{
    heap *h = (heap *)malloc(sizeof(heap));
    h->heapArray = (int *)malloc(sizeof(int) * (SIZE + 1));
    h->capacity = SIZE;
    h->size = 0;
    return h;
}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void percolateUp(heap *h, int ind)
{
    if (ind > 1)
    {
        if (h->heapArray[ind / 2] > h->heapArray[ind])
        {
            swap(&(h->heapArray[ind / 2]), &(h->heapArray[ind]));
            percolateUp(h, ind / 2);
        }
    }
}

int insert(heap *h, int val)
{
    if (h->size == h->capacity)
    {
        h->heapArray = (int *)realloc(h->heapArray, sizeof(int) * (2 * h->capacity + 1));

        if (!h->heapArray)
            return 0;
        h->capacity *= 2;
    }

    (h->size)++;
    h->heapArray[h->size] = val;
    percolateUp(h, h->size);
}

int minimum(int valLeft, int indLeft, int valRight, int indRight)
{
    if (valLeft < valRight)
        return indLeft;
    return indRight;
}

void percolateDown(heap *h, int index)
{
    if (h->size >= (index * 2 + 1))
    {
        int min = minimum(h->heapArray[index * 2], index * 2,
                          h->heapArray[index * 2 + 1], index * 2 + 1);
        if (h->heapArray[min] < h->heapArray[index])
        {
            swap(&(h->heapArray[min]), &(h->heapArray[index]));
            percolateDown(h, min);
        }
    }
    else
    {
        if (h->heapArray[index * 2] > h->heapArray[index])
            swap(&(h->heapArray[index * 2]), &(h->heapArray[index]));
    }
}

int removeMin(heap *h)
{
    if (h->size > 0)
    {
        int retval = h->heapArray[1];
        h->heapArray[1] = h->heapArray[h->size];
        (h->size)--;
        percolateDown(h, 1);
    }
}

int *heapSort(heap *h)
{
    int *a = malloc(h->size * sizeof(int));
    int n = h->size;
    for (int i = 0; i < n; i++)
        a[i] = removeMin(h);
    return a;
}

int main(void)
{
    // define numElements and create heap
    scanf("%d", &numElements);
    heap *pHeap = init();

    // create tree
    for (int i = 0; i < numElements; i++)
    {
        int val;
        scanf("%d", &val);
        int outcome = insert(pHeap, val);
        if (!outcome)
            break;
    }
}