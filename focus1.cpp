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
void fillFlightInfo(struct FlightInfo* flight, char*, char*);
void printFlightInfo(struct FlightInfo* flights);
int main() {
    struct FlightInfo flights[10];
    char destination[30] = "";
    char date[30] = "";

    printf("Enter destination and date for 10 flights (each less than 30 characters):\n");
    for (int i = 0; i < 10; i++) {

        printf("Flight %d:\n", i + 1);
        fgets(destination, sizeof(destination), stdin);
        fgets(date, sizeof(date), stdin);
        destination[strcspn(destination, "\n")] = '\0';
        date[strcspn(date, "\n")] = '\0';
        fillFlightInfo(&flights[i], destination, date);
    }

    printFlightInfo(flights); // Print flight information


    free(flights->destination);
    free(flights->date);
    return 0;
}


void fillFlightInfo(struct FlightInfo* flight, char* destination, char* date) {
    flight->destination = (char*)malloc(31);
    if (flight->destination != NULL) {
        strncpy(flight->destination, destination, strlen(destination) + 1);
    }
    flight->date = (char*)malloc(31);
    if (flight->date != NULL) {
        strncpy(flight->date, date, strlen(date) + 1);
    }
}


void printFlightInfo(struct FlightInfo* flights) {
    printf("%-35s%-35s\n", "Destination", "Date");
    for (int i = 0; i < 10; i++) {
        printf("%-35s%-35s\n", flights[i].destination, flights[i].date);
    }
}