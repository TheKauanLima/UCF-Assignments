/* 
COP3223 Fall 2024 Assignment 3_2
Copyright 2024 Kauan Lima 
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// define student structure
typedef struct {
    char studentFirstName[20];
    char studentLastName[20];
    int studentId;
    char studentGrade;
} Student;

void search_id(Student students[], int size, int id, bool exists);
void search_firstname(Student students[], int size, char* firstName, bool exists);
void search_lastname(Student students[], int size, char* lastName, bool exists);

int main(void) {
    // initialize studentsList with students
    Student studentsList[] = {
        {"John", "Johnson", 895645, 'A'},
        {"Jake", "Michaelson", 236598, 'A'},
        {"Sally", "Weber", 225584, 'C'},
        {"Tou", "Xiong", 364875, 'B'},
        {"Jacquelyn", "Jackson", 984587, 'D'},
        {"John", "White", 560258, 'C'}
    };
    int structSize = sizeof(studentsList) / sizeof(studentsList[0]);

    int inputChoice; // determines which search method will be used
    char inputString[20]; // search with String (first name, last name)
    int inputId; // seach with id
    bool exists = false; // determine if a record exists

    // prompt for search type by number
    printf("Please enter your search type (0: ID, 1: First Name, 2: Last Name): ");
    scanf("%d", &inputChoice);
    getchar();

    // switch case for each choice
    switch (inputChoice)
    {
        // search by id (0)
        case 0:
            // prompt for id
            printf("Please enter the ID you want to search: ");
            scanf("%d", &inputId);

            search_id(studentsList, structSize, inputId, exists);
            break;
        // search by first name (1)
        case 1:
            // prompt for last name
            printf("Please enter the first name you want to search: ");
            fgets(inputString, sizeof(inputString), stdin);
            inputString[strlen(inputString) - 1] = 0; // remove newline character

            search_firstname(studentsList, structSize, inputString, exists);
            break;
        // search by last name (2)
        case 2:
            // prompt for last name
            printf("Please enter the last name you want to search: ");
            fgets(inputString, sizeof(inputString), stdin);
            inputString[strlen(inputString) - 1] = 0; // remove newline character

            search_lastname(studentsList, structSize, inputString, exists);
            break;
        // default case
        default:
            printf("Invalid search type!\n");
            break;
    }
}

void search_id(Student studentsList[], int size, int id, bool exists)
{
    // search array for specific id and print
    for (int i = 0; i < size; i++)
        if (studentsList[i].studentId == id) {
            printf("Found record: %s %s, ID: %d, Grade: %c\n", 
                studentsList[i].studentFirstName, 
                studentsList[i].studentLastName,
                studentsList[i].studentId, 
                studentsList[i].studentGrade);
            exists = true;
        }

    // if not found, alert user
    if (!exists) printf("No records found with ID: %d\n", id);
}

void search_firstname(Student studentsList[], int size, char* firstName, bool exists)
{
    // search array for specific first name and print
    for (int i = 0; i < size; i++)
        if (strcmp(studentsList[i].studentFirstName, firstName) == 0)
        {
            printf("Found record: %s %s, ID: %d, Grade: %c\n", 
                studentsList[i].studentFirstName, 
                studentsList[i].studentLastName,
                studentsList[i].studentId, 
                studentsList[i].studentGrade);
            exists = true;
        }

    // if not found, alert user
    if (!exists) printf("No records found with first name: %s\n", firstName);
}

void search_lastname(Student studentsList[], int size, char* lastName, bool exists)
{
    // search array for specific last name and print
    for (int i = 0; i < size; i++)
        if (strcmp(studentsList[i].studentLastName, lastName) == 0) {
            printf("Found record: %s %s, ID: %d, Grade: %c\n", 
                studentsList[i].studentFirstName, 
                studentsList[i].studentLastName,
                studentsList[i].studentId, 
                studentsList[i].studentGrade);
            exists = true;
        }

    // if not found, alert user
    if (!exists) printf("No records found with last name: %s\n", lastName);
}