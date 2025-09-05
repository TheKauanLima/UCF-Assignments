// imports
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// definitions

// structs
typedef struct student
{
    char first[20];
    char last[20];
    int ID;
} student;

// functions
int numJumps(int n, int u, int d)
{
    if (n - u <= 0)
        return 1;
    return 1 + numJumps(n - u + d, u, d);
}

void sort(student **list, int len)
{
    int i, j;
    for (i = len - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (cmp(list[j], list[j + 1]) > 0)
            {
                student *tmp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = tmp;
            }
        }
    }
}

int cmp(student *a, student *b)
{
    if (strcmp(a->last, b->last) == 0)
    {
        if (strcmp(a->first, b->first) == 0)
        {
            if (a->ID > b->ID)
                return 1;
            else
                return -1;
        }
        else
            return strcmp(a->first, b->first);
    }
    else
        return strcmp(a->last, b->last);
}

void printlucky(int n)
{
    int *odom = malloc(n * sizeof(int));
    printluckyrec(odom, 0, n);
    free(odom);
}

int numd(int *odometer, int n, int d)
{
    int res = 0;
    for (int i = 0; i < n; i++)
        res += (odometer[i] == d);
    return res;
}

void print(int *odometer, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", odometer[i]);
    printf("\n");
}

void printluckyrec(int *odometer, int k, int n)
{
    if (k == n)
    {
        if (numd(odometer, n, 7) > 1)
            print(odometer, n);
        return;
    }

    odometer[k] = 0;
    for (int i = k; i < n; i++)
    {
        odometer[k]++;
        printluckyrec(odometer, k + 1, n);
    }
}

int weightedSum(int numbers[], int n)
{
    if (n == 0)
        return numbers[n];
    return (n + 1) * numbers[n] + weightedSum(numbers, n - 1);
}

int f(int t)
{
    return (int)(2 * sqrt(t) + log(t));
}

int minPlay(int target)
{
    return minPlayRec(target, 0, 1000000000);
}

int minPlayRec(int target, int low, int high)
{
    if (low == high)
        return low;
    int mid = (low + high) / 2;
    int pts = f(mid);
    if (pts < target)
        return minPlayRec(target, mid + 1, high);
    return minPlayRe(target, low, mid);
}

// return eval(values, perm, n)
// !used[i]
// 1
// k+1
// n
// 0

// n-1
// values[perm[i]]
// values[perm[i+1]]
// 1

int productDigits(int n)
{
    if (n == 0)
        return 1;
    int digit = n % 10;
    return digit * productDigits(n / 10);
}

// 0
// 0
// 1
// 0
// inbounds(sx+1, sy)
// sx + 1, sy, ex, ey, allowed
// inbounds(sx, sy+1)
// sx, sy + 1, ex, ey, allowed

// !inbounds(row, col)
// row, col, 1
// row - DR[i];
// col - DC[i];
// grid[nextR][nextC] < grid[row][col]

#define SIZE 20
int score(int preferences[], int applicant)
{
    int res = 0;
    for (int i = 0; i < SIZE; i++)
    {
        if (applicant & (1 << preferences[i]) == 0)
            return res;
        res++;
    }
    return res;
}

// main
int main(void)
{
    printf("%d", numJumps(10, 10, 3));
}