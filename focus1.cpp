/*
* FILE : focus1.cpp
* PROJECT : focus Assignment 1
* PROGRAMMER : krishna kachhiapatel
* FIRST VERSION : 2024-05-17
* DESCRIPTION : Write a program to for memory allocation.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996) 
//defination of structure called flight 
struct FlightInfo
{   // intialising nessesary variables 
    char* destination;
    char* date;
};

// prototypes of function 
void fillFlightInfo(struct FlightInfo* flight, char*, char*);
void printFlightInfo(struct FlightInfo* flights);
//main function 
int main(void) 
{   // initialising structs and variables for better understandment 
    struct FlightInfo flights[10];
    char destination[30] = "";
    char date[30] = "";

    //displaying guiding lines 
    printf("Enter destination and date for 10 flights (each less than 30 characters):\n");
    //using for loop in order to enter data specific data from user  
    for (int k = 0; k < 10; k++) 
    {
        //writing code for entering data 
        printf("Flight %d:\n", k + 1);
        fgets(destination, sizeof(destination), stdin);
        fgets(date, sizeof(date), stdin);
        destination[strcspn(destination, "\n")] = '\0';
        date[strcspn(date, "\n")] = '\0';
        fillFlightInfo(&flights[k], destination, date);
    }

    //calling function
    printFlightInfo(flights); 

    //freeing up memories 
    free(flights->destination);
    free(flights->date);
    return 0;
}

/*
Function: fillFlightInfo()

Parameter: struct FlightInfo* flight : this parameter refer to the struct which contains the data of user info 
           char* destination : purticularlt refers to destination of flight 
           char* date : purticularly refers to the date of flight 

Return Value: none 

Description: this function describes memory allocation of the data of flights , date and , destination. 
*/
void fillFlightInfo(struct FlightInfo* flight, char* destination, char* date) 
{
    flight->destination = (char*)malloc(31);
    // using conditional statement to decide that wether the information of destination and date is entered 
    if (flight->destination != NULL)
    {
        strcpy(flight->destination, destination, strlen(destination) + 1);
    }
    flight->date = (char*)malloc(31);
    if (flight->date != NULL) 
    {
        strcpy(flight->date, date, strlen(date) + 1);
    }
}
/*
Function: PrintFlightInfo()

Parameter: struct FlightInfo* flight : this parameter refer to the struct which contains the data of user info

Return Value: none

Description: this function is created to serve the purpose of displaying all the information on screen. 
*/

void printFlightInfo(struct FlightInfo* flights)
{   //displaying all the information while using printf() function 
    printf("%-35s%-35s\n", "Destination", "Date");
    for (int k = 0; k < 10; k++)
    {
        printf("%-35s%-35s\n", flights[k].destination, flights[k].date);
    }
}