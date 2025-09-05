#include <stdio.h>
#include "main.h"
#define MAXSIZE 500

int main(void)
{
    struct Student students[MAXSIZE];
    int n;

    readData(students, &n);

    struct Student maxStudent = getMaxAverageStudent(students, n);
    printf("\nMaximum Average is %0.2f and the student is %d\n", maxStudent.average, maxStudent.student_ID);

    return 0;
}

void readData(struct Student *students, int *c)
{
    scanf("%d", c);

    for (int i = 0; i < *c; ++i)
    {
        scanf("%d", &students[i].student_ID);
        scanf("%d %d %d", &students[i].g1, &students[i].g2, &students[i].g3);

        students[i].average = (students[i].g1 + students[i].g2 + students[i].g3) / 3.0;

        printf("%d %d %d %d %0.2f\n",
            students[i].student_ID, students[i].g1, students[i].g2, students[i].g3, students[i].average);
    }
}

struct Student getMaxAverageStudent(struct Student *s, int n)
{
    float max = -1;
    int maxId = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i].average > max)
        {
            max = s[i].average;
            maxId = i;
        }
    }

    return s[maxId];
}