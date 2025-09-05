/* COP 3502C Assignment 3
This program is written by: Kauan Lima */

// imports
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// definitions
#define SIZE 20
#define SEAT_SPEC 2

// structs
typedef struct numFans{
    char* name;
    int hasSnacks;
}Fan;

// global variables
Fan** fList;
int numFans = 0, numConditions = 0;
int* sList = NULL;
Fan** noSit = NULL;

// prototypes
void initArrays(int**, int**);
void initFans();
void initConditions();
Fan* createFan(char*, int);
void freeFan(Fan*);
Fan* findFan(char*);
int isInNoSit(Fan*, Fan*);
int checkPerm(int*, int);
void reset(int*);
void permute(int*, int*, int, int*);
void freeAll(int*, int*);

// main
int main(void)
{
    // scan base user inputs for fans and conditions
    scanf("%d %d", &numFans, &numConditions);

    // allocate memory for all necessary arrays
    int* perm = NULL;
    int* used = NULL;
    initArrays(&perm, &used);

    // initialize all fans and fan arrays
    initFans();

    // initialize the sitting conditions
    initConditions();

    // permute and display all possible iterations
    int ctr = 0;
    permute(perm, used, 0, &ctr);
    printf("%d", ctr);

    // free all memory
    freeAll(perm, used);
}

// functions
// initialize global arrays and permutation arrays
void initArrays(int** perm, int** used)
{
    fList = (Fan**)malloc(sizeof(Fan*) * numFans);
    sList = (int*)malloc(sizeof(int) * numFans);
    noSit = (Fan**)malloc(sizeof(Fan*) * numConditions);

    *perm = (int*)calloc(numFans, sizeof(int));
    *used = (int*)calloc(numFans, sizeof(int));
}

// initialize each fan
void initFans()
{
    for (int i = 0; i < numFans; i++)
    {
        char name[SIZE];
        int hasSnacks = 0;
        scanf("%s %d", name, &hasSnacks);

        fList[i] = createFan(name, hasSnacks);

        sList[i] = fList[i]->hasSnacks;
    }
}

// initialize each condition
void initConditions()
{
    for (int i = 0; i < numConditions; i++)
    {
        noSit[i] = (Fan*)malloc(sizeof(Fan) * SEAT_SPEC);

        for (int j = 0; j < SEAT_SPEC; j++)
        {
            char findName[SIZE];
            scanf("%s", findName);

            noSit[i][j] = *findFan(findName);
        }
    }
}

// create Fan struct
Fan* createFan(char* name, int hasSnacks)
{
    Fan* f = (Fan*)malloc(sizeof(Fan));

    int length = strlen(name) + 1;
    f->name = (char*)malloc(sizeof(char) * length);
    strcpy(f->name, name);

    f->hasSnacks = hasSnacks;
    return f;
}

// free Fan struct
void freeFan(Fan* f)
{
    free(f->name);
    free(f);
}

// find Fan by name
Fan* findFan(char* fName)
{
    for (int i = 0; i < numFans; i++)
    {
        if (strcmp(fName, fList[i]->name) != 0)
            continue;
        return fList[i];
    }

    return NULL;
}

// return whether given fan has a condition with another
int isInNoSit(Fan* f1, Fan* f2)
{
    for (int i = 0; i < numConditions; i++)
        if (strcmp(f1->name, noSit[i][0].name) == 0 && strcmp(f2->name, noSit[i][1].name) == 0 ||
            strcmp(f1->name, noSit[i][1].name) == 0 && strcmp(f2->name, noSit[i][0].name) == 0)
            return 1;
    return 0;
}

// check if perutation is valid
int checkPerm(int* perm, int i)
{
    // return 1 for valid perm
    if (i == 0)
        return 1;

    // check if someone without snacks is next to seomeone with
    // assign value 2 to person without snacks
    if (sList[perm[i]] == 1 && sList[perm[i - 1]] == 0)
        sList[perm[i - 1]] = 2;
    else if (sList[perm[i]] == 0 && sList[perm[i - 1]] == 1)
        sList[perm[i]] = 2;

    // edge cases
    // check for 0s at the end of array and in middle if fan is not 2
    if (i < numFans - 1)
        if (sList[perm[i]] == 0 || sList[perm[i + 1]] == 0)
            return 0;

    // check if first in array has snacks next to or not
    if (i == 1 && sList[perm[i - 1]] == 0)
        return 0;

    // iterate
    return checkPerm(perm, i - 1);
}

void reset(int* perm)
{
    for (int i = 0; i < numFans; i++)
        sList[i] = fList[i]->hasSnacks;
}

// permutation
void permute(int* perm, int* used, int k, int* ctr)
{
    // base case if numFans is reached
    if(k == numFans)
    {
        // check if permutation is valid, increase ctr
        if (checkPerm(perm, numFans - 1))
            (*ctr)++;

        // reset snacks for each fan
        reset(perm);
        return;
    }

    // permute
    for(int i = 0; i < numFans; i++)
    {
        if(used[i])
            continue;

        used[i] = 1;
        perm[k] = i;

        // check for valid sitting conditions
        if (k > 0)
            if (isInNoSit(fList[perm[k]], fList[perm[k - 1]]))
            {
                used[i] = 0;
                continue;
            }

        permute(perm, used, k+1, ctr);

        used[i] = 0;
    }
}

// free all memory
void freeAll(int* perm, int* used)
{
    for (int i = 0; i < numFans; i++)
        freeFan(fList[i]);
    for (int i = 0; i < numConditions; i++)
        free(noSit[i]);
    free(fList);
    free(noSit);
    free(sList);
    free(perm);
    free(used);
}