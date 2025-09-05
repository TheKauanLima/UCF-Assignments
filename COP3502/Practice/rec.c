#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

void printView(char view[][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%c ", view[i][j]);
        }
        printf("\n");
    }
}

void floodFillRec(char view[][SIZE], int sR, int sC, char oC, char nC)
{
    if (sR < 0 || sC < 0 || sR == SIZE || sC == SIZE)
        return;

    if (view[sR][sC] != oC)
        return;
    view[sR][sC] = nC;

    floodFillRec(view, sR - 1, sC, oC, nC);
    floodFillRec(view, sR, sC - 1, oC, nC);
    floodFillRec(view, sR, sC + 1, oC, nC);
    floodFillRec(view, sR + 1, sC, oC, nC);
}

void floodFill(char view[][SIZE], int sR, int sC, char nC)
{
    char oldChar = view[sR][sC];
    floodFillRec(view, 2, 2, oldChar, nC);
}

void printPerm(int* perm, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", perm[i]);
    }
    printf("\n");
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void permute(int* arr, int k, int n)
{
    if (k == n)
    {
        printPerm(arr, n);
        return;
    }

    for (int i = k; i < n; i++)
    {
        swap(&arr[i], &arr[k]);
        permute(arr, k + 1, n);
        swap(&arr[i], &arr[k]);
    }
}

void printUsedPerm(int* perm, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", perm[i]);
    }
    printf("\n");
}

void permuteUsed(int* perm, int* used, int k, int n)
{
    if (k == n)
    {
        printUsedPerm(perm, n);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (used[i])
            continue;

        used[i] = 1;
        perm[k] = i;
        permuteUsed(perm, used, k + 1, n);
        used[i] = 0;
    }
}

void towerOfHanoi(int nDisks, char fR, char tR, char aR)
{
    if (nDisks == 1)
    {
        printf("Disk %d from %c to %c \n", nDisks, fR, tR);
        return;
    }

    towerOfHanoi(nDisks-1, fR, aR, tR);
    printf("Disk %d from %c to %c \n", nDisks, fR, tR);
    towerOfHanoi(nDisks-1, aR, tR, fR);
}

int fastExponent(int b, int p)
{
    if (p == 0)
        return 1;
    if (p == 1)
        return b;

    if (p % 2 == 0)
        return fastExponent(b*b, p/2);
    else
        return fastExponent(b*b, p/2) * b;
}

int fibonacci(int n)
{
    if (n == 1 || n == 2)
        return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(void)
{
    char view[8][8] = { { '*', '*', '*', '*', '*', '*', '*', '*' },
                        { '*', ' ', '*', ' ', '*', '*', ' ', '*' },
                        { '*', ' ', ' ', ' ', ' ', ' ', ' ', '*' },
                        { '*', ' ', ' ', ' ', '*', ' ', ' ', '*' },
                        { '*', ' ', ' ', ' ', '*', ' ', ' ', '*' },
                        { '*', ' ', ' ', ' ', '*', ' ', ' ', '*' },
                        { '*', ' ', ' ', '*', '*', '*', ' ', '*' },
                        { '*', '*', '*', '*', '*', '*', '*', '*' } };

    floodFill(view, 2, 2, '~');
    printView(view);

    int arr[] = { 0, 1, 2 };
    int perm[] = { 0, 1, 2 };
    int used[] = { 0, 0, 0 };
    printf("\nswap method:\n");
    permute(arr, 0, 3);

    printf("\nused method:\n");
    permuteUsed(perm, used, 0, 3);

    printf("\nTower of Hanoi:\n");
    towerOfHanoi(4, 'A', 'C', 'B');

    printf("\nFast Exponent:\n");
    printf("%d", fastExponent(7, 57));

    printf("\nFibonacci:\n");
    printf("%d", fibonacci(14));
}