/* 
COP3223 Fall 2024 Assignment 2_3
Copyright 2024 Kauan Lima 
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Global seat array to check which seats are taken
int seats[6] = {0};

// Search function for seat assignment
int search_seat(int class)
{
    srand(time(NULL));
    int assign = 0;
    int classSwitchCheck = 0;
    bool cont = false;

    // Check if user wants first class and if seats are available
    if (class == 1 && (seats[0] == 0 || seats[1] == 0 || seats[2] == 0))
    {
        do {
            assign = 1 + rand() % 3;

            if (seats[assign - 1] == 1)
                cont = true;
            else
            {
                seats[assign - 1] = 1;
                cont = false;
            }
        } while (cont);
    }
    // Check if user wants economy and if seats are available
    else if (class == 2 && (seats[3] == 0 || seats[4] == 0 || seats[5] == 0))
    {
        do {
            assign = 4 + rand() % 3;

            if (seats[assign - 1] == 1)
                cont = true;
            else
            {
                seats[assign - 1] = 1;
                cont = false;
            }
        } while (cont);
    }
    // If both sections are fully booked
    else if (seats[0] == 1 && seats[1] == 1 && seats[2] == 1 &&
            seats[3] == 1 && seats[4] == 1 && seats[5] == 1)
    {
        printf("Next flight leaves in 3 hours\n");
        return 0; // No seat assigned
    }
    // If requested first class and it's full, offer economy
    else if (class == 1)
    {
        printf("no seat available in first class, do you want a seat in economy? ");
        scanf("%d", &classSwitchCheck);
        if (classSwitchCheck == 1)
            return 7; // Code for switching to economy
        else
            return 0; // Exit signal if user declines
    }
    // If requested economy and it's full, offer first class
    else if (class == 2) {
        printf("no seat available in economy, do you want a seat in first class? ");
        scanf("%d", &classSwitchCheck);
        if (classSwitchCheck == 1)
            return 8; // Code for switching to first class
        else
            return 0; // Exit signal if user declines
    }

    return assign;
}

// Print boarding pass
void print_boarding_pass(int assignment)
{
    //Separate the array into halves.
    if (assignment < 4)
        printf("Your seat is assigned to first class seat %d\n", assignment);
    else if (assignment >= 4)
        printf("Your seat is assigned to economy seat %d\n", assignment);
}

// Main function
int main(void)
{
    //let while loop continue
    int pass = 0;

    //loop program
    do {
        int seatClass;
        printf("Please type 1 for \"first class\"\n");
        printf("Please type 2 for \"economy\"\n");
        scanf("%d", &seatClass);

        int assigned = search_seat(seatClass);

        // Check if user declined to switch classes
        if (assigned == 0) {
            printf("Next flight leaves in 3 hours\n");
            break; // Exit program if no seat available and user declined
        }

        // Assign seat in alternative class if needed
        while (assigned > 6) {
            if (assigned == 7)
                assigned = search_seat(2);
            else if (assigned == 8)
                assigned = search_seat(1);
        }

        //Print boarding pass
        if (assigned != 0) 
            print_boarding_pass(assigned);

        //Prompt if everyone has boarded
        printf("Has everyone boarded? ");
        scanf("%d", &pass);
    } while (pass == 0);
}
