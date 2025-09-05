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

typedef struct Monster
{

} Monster;

typedef struct Monster_List
{
    Monster **mArray;
    int numMonsters;
} Monster_List;

typedef struct StringType
{
    char *string;
    int length;
} StringType;

typedef struct Employee
{
    StringType *ename;
    double salary;
} Employee;

// functions
void freeList(node *front)
{
    if (front != NULL)
        free(front);
    if (front->next != NULL)
        freeList(front->next);
}

int **triangularSum(int *base, int n)
{
    int **trisum = malloc(sizeof(int *) * n);

    for (int i = 0; i < n; i++)
    {
        trisum[i] = malloc(sizeof(int) * (n - i));
        trisum[0][i] = base[i];
    }

    for (int row = 1; row < n; row++)
        for (int i = 0; i < n - row; i++)
            trisum[row][i] = trisum[row - 1][i] + trisum[row - 1][i + 1];
    return trisum;
}

void initializeMonster(Monster *mPtr)
{
}

Monster_List *getDefaultMonsters(int n)
{
    Monster_List *ml = malloc(sizeof(Monster_List));
    ml->numMonsters = n;
    ml->mArray = malloc(sizeof(Monster *) * n);
    for (int i = 0; i < n; i++)
    {
        ml->mArray[i] = malloc(sizeof(Monster));
        initializeMonster(ml->mArray[i]);
    }
    return ml;
}

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

Employee *createEmployees(char names[][50], double *salaries, int empCount)
{
    Employee *e = malloc(sizeof(Employee) * empCount);
    for (int i = 0; i < empCount; i++)
    {
        e[i].ename = malloc(sizeof(StringType));
        int len = strlen(names[i]);
        e[i].ename->string = malloc(sizeof(char) * (len + 1));
        strcpy(e[i].ename->string, names[i]);
        e[i].ename->length = len;
        e[i].salary = salaries[i];
    }
    return e;
}

void print2Darray(int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            printf("%d, ", arr[i][j]);
        }
        printf("\n");
    }
}

// main
int main(void)
{
    char nameList[][50] = {"Adam", "Josh", "Kyle", "Ali", "Mohammed"};
    double salaries[5] = {15.80, 13.5, 20.9, 12.99, 10.5};
    Employee *employees = createEmployees(nameList, salaries, 5);

    int arr[5] = {1, 2, 3, 4, 5};
    int **trisum = triangularSum(arr, 5);
    print2Darray(trisum, 5);
    return 0;
}