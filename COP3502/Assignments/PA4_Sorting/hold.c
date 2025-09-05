/* COP 3502C Programming Assignment 4
This program is written by: Kauan Lima */

// necessary imports
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// structs
typedef struct coordinates{
    int x;
    int y;
    double distance;
}coords;

//global variables
coords pos;

// prototypes


// functions


int compareTo(coords* ptrPt1, coords* ptrPt2)
{
    double p1d = ptrPt1->distance, p2d = ptrPt2->distance;
    int p1x = ptrPt1->x, p2x = ptrPt2->x;
    int p1y = ptrPt1->y, p2y = ptrPt2->y;
    
    if (p1d < p2d) return -1;
    else if (ptrPt1 == ptrPt2) return 0;
    else if (p1d > p2d) return 1;
    else if (p1d == p2d)
    {
        if (p1x < p2x) return -1;
        else if (p1x > p2x) return 1;
        else
        {
            if (p1y < p2y) return -1;
            else if (p1y > p2y) return 1;
        }
    }
}

int binSearch(coords* arr, int left, int right, coords* key)
{
    if (left > right)
        return -1;

    int mid = (left + right) / 2;

    if (key->x == arr[mid].x && key->y == arr[mid].y)
        return mid;
    else if (compareTo(&(*key), &arr[mid]) < 0)
        return binSearch(arr, left, mid - 1, key);
    else
        return binSearch(arr, mid + 1, right, key);
}

coords* ReadData(coords** h, int* nSt, int* nS, int* t)
{
    scanf("%d %d %d %d %d", &pos.x, &pos.y, nSt, nS, t);

    coords* s = (coords*)malloc(sizeof(coords) * (*nSt));
    *h = (coords*)malloc(sizeof(coords) * (*nS));

    int stadX, stadY;
    for (int i = 0; i < *nSt; i++)
    {
        scanf("%d %d", &stadX, &stadY);
        s[i].x = stadX;
        s[i].y = stadY;
        s[i].distance = sqrt(pow(stadX - pos.x, 2) + pow(stadY - pos.y, 2));
    }

    for (int i = 0; i < *nS; i++)
    {
        scanf("%d %d", &stadX, &stadY);
        (*h)[i].x = stadX;
        (*h)[i].y = stadY;
        (*h)[i].distance = sqrt(pow(stadX - pos.x, 2) + pow(stadY - pos.y, 2));
    }

    return s;
}

void insertionSort(coords* arr, int r)
{
    int i, j;

    for (i = 1; i < r; i++)
    {
        coords hand = arr[i];

        for (j = i - 1; j >= 0; j--)
        {
            if (compareTo(&hand, &arr[j]) < 0)
                arr[j + 1] = arr[j];
            else
                break;
        }
        arr[j + 1] = hand;
    }
}

void merge(coords* arr, int left, int mid, int right)
{
    int sizeL = mid - left + 1;
    int sizeR = right - mid;

    coords* L = (coords*)malloc(sizeof(coords) * sizeL);
    coords* R = (coords*)malloc(sizeof(coords) * sizeR);

    for (int i = 0; i < sizeL; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < sizeR; i++)
        R[i] = arr[(mid + 1) + i];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < sizeL && j < sizeR)
    {
        if (compareTo(&L[i], &R[j]) < 0)
        {
            arr[k] = L[i];
            i++;
            k++;
        }
        else if (compareTo(&L[i], &R[j]) > 0)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    while (i < sizeL)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < sizeR)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void mergeSort(coords* arr, int left, int right, int t)
{
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid, t);
        mergeSort(arr, mid+1, right, t);
        merge(arr, left, mid, right);
    }
}

void sort(coords* arr, int size, int t)
{
    mergeSort(arr, 0, size - 1, t);
}

// main
int main(void)
{
    int numStadiums;
    int numSearches;
    int threshold;
    coords* hold = NULL;
    coords* stadiums = ReadData(&hold, &numStadiums, &numSearches, &threshold);

    sort(stadiums, numStadiums, threshold);

    for (int i = 0; i < numStadiums; i++)
    {
        printf("%d %d\n", stadiums[i].x, stadiums[i].y);
    }
    for (int i = 0; i < numSearches; i++)
    {
        int index = binSearch(stadiums, 0, numStadiums, &hold[i]);
        if (index > -1)
            hold[i] = stadiums[index];
        if (index == -1)
            printf("%d %d: no stadium found at this location", hold[i].x, hold[i].y);
        else
            printf("%d %d: stadium found at rank %d in the sorted order", hold[i].x, hold[i].y, index + 1);
        printf("\n");
    }

    free(stadiums);
    free(hold);
}