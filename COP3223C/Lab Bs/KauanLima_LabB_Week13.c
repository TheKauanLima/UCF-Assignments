#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char phoneNumberString[20];

    printf("Enter a phone number in the format (555) 555-5555: ");
    fgets(phoneNumberString, sizeof(phoneNumberString), stdin);
    phoneNumberString[strcspn(phoneNumberString, "\n")] = '\0';

    char* areaCodeString = strtok(phoneNumberString, " ()-");
    char* firstThree = strtok(NULL, " ()-");
    char* lastFour = strtok(NULL, " ()-");

    char fullNumber[8];
    snprintf(fullNumber, sizeof(fullNumber), "%s%s", firstThree, lastFour);

    int areaCode = atoi(areaCodeString);
    int phoneNumber = atoi(fullNumber);

    printf("Area Code: %d\n", areaCode);
    printf("Phone Number: %d\n", phoneNumber);
}
