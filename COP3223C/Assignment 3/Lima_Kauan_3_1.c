/* 
COP3223 Fall 2024 Assignment 3_1 
Copyright 2024 Kauan Lima 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void expandArray(char*** names, int* maxArraySize);
void printList(char** names, int maxArraySize);
int findName(char** names, int numberOfNames, char* input);
int removeName(char*** names, int* numberOfNames, char* input);

int main(void)
{
    // declare a double pointer to hold the list of names
    char** names = NULL;
    int numberOfNames = 0;   // keeps track of the total number of names entered
    int maxArraySize = 4;    // defines the maximum size of the array, default is 4
    char input[20];          // determines the max length of user input (arbitrary value)

    // allocate initial memory for the array of strings
    names = (char**)malloc(maxArraySize * sizeof(char*));

    if (names == NULL)
    {
        // check if the memory allocation was successful
        printf("Memory allocation failed!\n");
        return 1;
    }

    // continuously prompt the user for names until "done" is entered
    while (1)
    {
        printf("Please enter the name: ");
        fgets(input, sizeof(input), stdin);
        
        input[strlen(input) - 1] = 0; // remove newline character

        // break the loop if the user enters "done"
        if (strcmp(input, "done") == 0)
            break;

        // allocate memory for the new name and store it in the array
        names[numberOfNames] = (char*)malloc((strlen(input) + 1) * sizeof(char));
        strcpy(names[numberOfNames], input); // Copy the input into the allocated space
        numberOfNames++; // Increment the count of names

        // check if the current array is full and needs to be expanded
        if (numberOfNames >= maxArraySize)
            expandArray(&names, &maxArraySize);
    }

    // print the list of names entered
    printList(names, numberOfNames);

    // prompt the user to search for a name
    printf("Please enter the name you want to find: ");
    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = 0; // remove newline character
    int findPos = findName(names, numberOfNames, input);

    // check if the name was found
    if (findPos != -1)
        printf("Found name at index %d\n", findPos);
    else
        printf("Name not found.\n");

    // prompt the user to remove a name
    printf("Please enter the name you want to remove: ");
    fgets(input, sizeof(input), stdin);
    input[strlen(input) - 1] = 0; // remove newline character
    int remPos = removeName(&names, &numberOfNames, input);

    // check if the name was removed successfully
    if (remPos != -1)
        printf("Removed name at index %d\n", remPos);
    else
        printf("Name not found.\n");

    // print the updated list after removal
    printList(names, numberOfNames);

    // free all allocated memory
    for (int i = 0; i < numberOfNames; i++)
        free(names[i]);
    free(names);

    return 0;
}

void expandArray(char*** names, int* maxArraySize)
{
    // double the maximum size
    *maxArraySize *= 2;

    // reallocate memory to accommodate the new size
    *names = (char**)realloc(*names, *maxArraySize * sizeof(char*));
    
    // check if reallocation was successful
    if (*names == NULL) {
        printf("Memory allocation failed during expansion!\n");
        exit(1);
    }
}

void printList(char** names, int numberOfNames)
{
    // print the whole list
    printf("The list has %d names:\n", numberOfNames);
    for (int i = 0; i < numberOfNames; i++)
        printf("%s\n", names[i]);
}

int findName(char** names, int numberOfNames, char* input)
{
    // loop through the list to find the matching name
    for (int i = 0; i < numberOfNames; i++)
        if (strcmp(names[i], input) == 0) // check if names[i] matches input
            return i; // return the index if found
    return -1; // return -1 if not found
}

int removeName(char*** names, int* numberOfNames, char* input)
{
    // find the index of the name to be removed
    int index = findName(*names, *numberOfNames, input);

    if (index == -1)
        return -1; // return -1 if the name is not found

    // free the memory allocated for the name to be removed
    free((*names)[index]);

    // shift the remaining names to fill the gap
    for (int i = index; i < *numberOfNames - 1; i++)
        (*names)[i] = (*names)[i + 1];

    // decrease the count of names
    (*numberOfNames)--;

    return index; // return the index of the removed name
}