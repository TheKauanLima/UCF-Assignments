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

//global struct
coords pos;

// prototypes
coords* ReadData(coords** h, int* nSt, int* nS, int* t);
int compareTo(coords* ptrPt1, coords* ptrPt2);
void printStadiums(coords* s, int nSt);
void printInfo(coords* s, int nSe, int nSt, coords* h);
int binSearch(coords* arr, int left, int right, coords* key);
void insertionSort(coords* arr, int l, int r);
void merge(coords* arr, int left, int mid, int right);
void mergeSort(coords* arr, int left, int right, int t);
void sort(coords* arr, int size, int t);

// main
int main(void)
{
    // declare all necessary variables and arrays
    int numStadiums, numSearches, threshold;
    coords* hold = NULL;
    coords* stadiums = ReadData(&hold, &numStadiums, &numSearches, &threshold);

    // sort array and print all data
    sort(stadiums, numStadiums, threshold);
    printStadiums(stadiums, numStadiums);
    printInfo(stadiums, numSearches, numStadiums, hold);

    // free allocated memory
    free(stadiums);
    free(hold);
}

//functions
// read all user data
coords* ReadData(coords** h, int* nSt, int* nSe, int* t)
{
    // scan the first line
    scanf("%d %d %d %d %d", &pos.x, &pos.y, nSt, nSe, t);

    // allocate memory for all stadiums and coords to hold
    coords* s = (coords*)malloc(sizeof(coords) * (*nSt));
    *h = (coords*)malloc(sizeof(coords) * (*nSe));

    // variables for each new coordinate
    int stadX, stadY;

    // read all the stadium locations
    for (int i = 0; i < *nSt; i++)
    {
        scanf("%d %d", &stadX, &stadY);
        s[i].x = stadX;
        s[i].y = stadY;

        // calculate the distance from the global coordinate
        s[i].distance = sqrt(pow(stadX - pos.x, 2) + pow(stadY - pos.y, 2));
    }

    // read all the holding coordinates
    for (int i = 0; i < *nSe; i++)
    {
        scanf("%d %d", &stadX, &stadY);
        (*h)[i].x = stadX;
        (*h)[i].y = stadY;

        // calculate the distance from the global coordinate
        (*h)[i].distance = sqrt(pow(stadX - pos.x, 2) + pow(stadY - pos.y, 2));
    }

    // return the stadiums array
    return s;
}

// search algorithm
int binSearch(coords* s, int left, int right, coords* key)
{
    // return -1 if stadium not found
    if (left > right)
        return -1;

    // divide array in half for each new iteration
    int mid = (left + right) / 2;

    // check if hold position corresponds to the current stadium
    if (key->x == s[mid].x && key->y == s[mid].y)
        return mid;
    // check for position relative to mid using compareTo
    else if (compareTo(&(*key), &s[mid]) < 0)
        return binSearch(s, left, mid - 1, key);
    else
        return binSearch(s, mid + 1, right, key);
}

// wrapper function
void sort(coords* s, int size, int t)
{
    mergeSort(s, 0, size - 1, t);
}

// print the stadiums array
void printStadiums(coords* s, int nSt)
{
    for (int i = 0; i < nSt; i++)
    {
        printf("%d %d\n", s[i].x, s[i].y);
    }
}

// print the stadiums info
void printInfo(coords* s, int nSe, int nSt, coords* h)
{
    for (int i = 0; i < nSe; i++)
    {
        int index = binSearch(s, 0, nSt, &h[i]);
        if (index > -1)
            h[i] = s[index];
        if (index == -1)
            printf("%d %d: no stadium found at this location", h[i].x, h[i].y);
        else
            printf("%d %d: stadium found at rank %d in the sorted order", h[i].x, h[i].y, index + 1);
        printf("\n");
    }
}

// compare stadium A to stadium B to decide the correct sorted order
int compareTo(coords* ptrPt1, coords* ptrPt2)
{
    // get distance, x, and y for both stadiums
    double p1d = ptrPt1->distance, p2d = ptrPt2->distance;
    int p1x = ptrPt1->x, p2x = ptrPt2->x;
    int p1y = ptrPt1->y, p2y = ptrPt2->y;
    
    // p1 comes first if distance is less than p2
    if (p1d < p2d) return -1;
    // 0 if these are the same
    else if (ptrPt1 == ptrPt2) return 0;
    // p1 comes second if distance is greater than p2
    else if (p1d > p2d) return 1;
    // if distances are the same
    else if (p1d == p2d)
    {
        // p1 comes first if x is smaller
        if (p1x < p2x) return -1;
        // p2 comes first if x is smaller
        else if (p1x > p2x) return 1;
        // if x are the same
        else
        {
            // p1 comes first if y is smaller
            if (p1y < p2y) return -1;
            // p2 comes first if y is smaller
            else if (p1y > p2y) return 1;
        }
    }
}

// fast algorithm for small arrays
void insertionSort(coords* s, int l, int r)
{
    int i, j;

    // iterate from left point to right point
    for (i = l + 1; i <= r; i++)
    {
        coords hand = s[i];

        // check for each index below until the left point is reached
        for (j = i - 1; j >= l; j--)
        {
            // use compareTo to determine correct order
            if (compareTo(&hand, &s[j]) < 0)
                s[j + 1] = s[j];
            else
                break;
        }
        s[j + 1] = hand;
    }
}

// merge algorithm
void merge(coords* s, int left, int mid, int right)
{
    // set all necessary variables and arrays
    int sizeL = mid - left + 1;
    int sizeR = right - mid;

    coords* L = (coords*)malloc(sizeof(coords) * sizeL);
    coords* R = (coords*)malloc(sizeof(coords) * sizeR);

    for (int i = 0; i < sizeL; i++)
        L[i] = s[left + i];
    for (int i = 0; i < sizeR; i++)
        R[i] = s[(mid + 1) + i];

    int i = 0, j = 0, k = left;

    // compare each value of left and right arrays using compareTo
    // to determine correct order
    while (i < sizeL && j < sizeR)
    {
        if (compareTo(&L[i], &R[j]) <= 0)
            s[k++] = L[i++];
        else
            s[k++] = R[j++];
    }

    // ensure remaining values in L and R arrays are accounted
    while (i < sizeL)
        s[k++] = L[i++];

    while (j < sizeR)
        s[k++] = R[j++];

    // free allocated memory
    free(L);
    free(R);
}

// optimized merge algorithm
void mergeSort(coords* s, int left, int right, int t)
{
    // perform insertion for arrays with a size <= t
    if (right - left + 1 <= t)
    {
        insertionSort(s, left, right);
        return;
    }

    // perform standard merge sort
    // merge only called for arrays of size above t
    if (left < right)
    {
        int mid = (left + right) / 2;

        mergeSort(s, left, mid, t);
        mergeSort(s, mid+1, right, t);
        merge(s, left, mid, right);
    }
}