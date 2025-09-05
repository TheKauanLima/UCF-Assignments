/* 
COP3223 Fall 2024 Assignment 1_1 
Copyright 2024 Kauan Lima 
*/
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    //run program while true
    bool run = true;
    do
    {
        //prompt for number of hours worked
        int hoursWorked;
        printf("Enter # of hours worked (-1 to end): ");
        scanf("%d", &hoursWorked);

        //exit the program if hoursWorked == -1
        if (hoursWorked == -1)
        {
            run = false;
            break;
        }

        //prompt for the pay rate
        float payRate;
        printf("Enter hourly rate of the worker ($00.00): ");
        scanf("%f", &payRate);

        //declare salary and straightTime to manage overtime
        float salary;
        int straightTime = 40;
    
        // pay normal rate if hoursWorked is less than or equal to straightTime
        if (hoursWorked <= straightTime)
            salary = hoursWorked * payRate;
        //pay normal rate + overtime bonus if hoursWorked is greater than straightTime
        else if (hoursWorked > straightTime)
        {
            salary = straightTime * payRate;
            salary = salary + (hoursWorked - straightTime) * (payRate * 1.5);
        }

        //print results
        printf("Salary is $%.2f\n\n", salary);
    } while (run);
}