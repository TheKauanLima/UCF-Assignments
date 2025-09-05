#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "leak_detector_c.h"

typedef struct student
{
    char *lname; //this will require DMA to store a string
    int assignment;
    int finalExam;
    int total;
    int *quizzes;//this will require DMA to store quizzes
}student;

student** readCourses(int *C, int *N, int *M);

void release_memroy(student ** st, int C, int N, int M);

void printHighestTotal(student** courses, int C, int N, int M);

int main()
{
    atexit(report_mem_leak); //for memory leak detector.
    student **courseList;

    int i, j,C, N, M;

    //passing reference of C, N, and M so that we get to know what we have in the first line
    courseList = readCourses(&C, &N, &M);
    printHighestTotal(courseList, C, N, M);
    release_memroy(courseList, C, N, M);

    //free(ptr);
    return 0;
}

student** readCourses(int *C, int *N, int *M)
{
    scanf("%d %d %d", C, N, M);

    student** school = (student**)malloc(*C * sizeof(student*));

    for (int cI = 0; cI < *C; cI++)
    {
        school[cI] = (student*)malloc(*N * sizeof(student));

        for (int sI = 0; sI < *N; sI++)
        {
            char tempName[51];
            int tempTotal = 0;
            scanf("%s %d", tempName, &school[cI][sI].assignment);
            
            school[cI][sI].quizzes = (int*)malloc(*M * sizeof(int));

            for (int qI = 0; qI < *M; qI++)
            {
                scanf("%d", &school[cI][sI].quizzes[qI]);

                tempTotal += school[cI][sI].quizzes[qI];
            }

            int nameLen = strlen(tempName) + 1;
            school[cI][sI].lname = (char*)malloc(nameLen*sizeof(char));
            strcpy(school[cI][sI].lname, tempName);
            scanf("%d", &school[cI][sI].finalExam);

            school[cI][sI].total = tempTotal + school[cI][sI].assignment + school[cI][sI].finalExam;
        }
    }

    return school;
}

void release_memroy(student ** st, int C, int N, int M)
{
    for (int cI = 0; cI < C; cI++)
    {
        for (int sI = 0; sI < N; sI++)
        {
            free(st[cI][sI].quizzes);
            free(st[cI][sI].lname);
        }
        free(st[cI]);
    }
    free(st);
}

void printHighestTotal(student** courses, int C, int N, int M)
{
    int maxTotal = -1;
    int maxCourseIndex = 0;
    int maxStudentIndex = 0;

    for (int cI = 0; cI < C; cI++)
    {
        for (int sI = 0; sI< N; sI++)
        {
            if (courses[cI][sI].total > maxTotal)
            {
                maxTotal = courses[cI][sI].total;
                maxCourseIndex = cI;
                maxStudentIndex = sI;
            }
        }
    }

    printf("Name: %s\n", courses[maxCourseIndex][maxStudentIndex].lname);
    printf("Assignment: %d\n", courses[maxCourseIndex][maxStudentIndex].assignment);
    printf("Quizzes: ");
    for (int i = 0; i < M; i++)
    {
        printf("%d ", courses[maxCourseIndex][maxStudentIndex].quizzes[i]);
    }
    printf("\nFinal exam: %d\n", courses[maxCourseIndex][maxStudentIndex].finalExam);
    printf("Total: %d\n", courses[maxCourseIndex][maxStudentIndex].total);
    printf("Course number: %d", maxCourseIndex + 1);
}
