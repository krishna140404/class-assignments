// focus1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable: 4996) 
struct FlightInfo {
    char* destination;
    char* date;
};


void fillFlightInfo(struct FlightInfo* flight, char* destination, char* date) 
{
    flight->destination = (char*)malloc(31);
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


void printFlightInfo(struct FlightInfo* flights)
{
    printf("%-35s%-35s\n", "Destination", "Date");
    for (int k = 0; k < 10; k++)
    {
        printf("%-35s%-35s\n", flights[k].destination, flights[k].date);
    }
}