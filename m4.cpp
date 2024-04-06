
/*
* FILE : m4.cpp
* PROJECT : Major Assignment 4
* PROGRAMMER : krishna kachhiapatel
* FIRST VERSION : 2024-04-01
* DESCRIPTION : Write a program to display flight information where the least fare found for given source –
*               destination pair.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_DATA 100
#define MAX_LINE 80
#define MAX_NAME 30
#pragma warning (disable :4996)

//initialising structure 
struct Flight
{
    // initialising all variables.
    char source[MAX_NAME];
    char destination[MAX_NAME];
    int fare;
    char airline[MAX_NAME];
};

// prototypes of all the function. 
int parseLine(char* source, char* destination, int* fare, char* line);
int processFlight(char* filename, struct Flight flights[], int* count);
void displayLeastFareDetails(struct Flight flights[], int count);

int main(void)
{
    //initialising variables.
    FILE* fp;
    char filename[MAX_FILES][MAX_NAME];
    struct Flight flights[MAX_DATA];
    int count = 0;

    // open and read filenames from flights.txt
    fp = fopen("flights.txt", "r");
    //condition is put in order to find that file runs perfectly or not 
    if (fp == NULL)
    {
        printf("Error: Unable to open flights.txt\n");
        return 1;
    }
    while (count < MAX_FILES && fscanf(fp, "%s", filename[count]) != EOF)
    {
        count++;
    }
    fclose(fp);

    // Process each flight file
    int k, j, status;
    for (k = 0; k < count; k++)
    {
        status = processFlight(filename[k], flights, &j);
        // this purticular condition is used to find wether file is able to process or not. 
        if (status != 0)
        {
            printf("Error: Unable to process %s\n", filename[k]);
            continue;
        }
        if (j > 0)
        {
            // Display least fare details for first 100 datasets
            printf("\nFlight details for %s:\n", filename[k]);
            displayLeastFareDetails(flights, j);
        }
        else
        {
            printf("No flights available for %s\n", filename[k]);
        }
    }

    return 0;
}

/* FUNCTION: parseLine
*
* DESCRIPTION :  must parse (or extract information from) each flight result line
*
* PARAMETERS : char*source :a pointer to the source variable(char*)
*
*            : char*destination:a pointer to the destination variable(char*)
*
*            : int*fare:a pointer to the fare variable (int*)
*
*            :char*line:a pointer to line data read from the file(char*)
*
* RETURN : an int  :  indicating the day that was entereds in int ,or, in the case of the user not entering a
*                     valid day string, -1 indicating an error.
*/
int parseLine(char* source, char* destination, int* fare, char* line)
{
    //initialising variables
    char* token;
    int found = 0;

    //this token was meant for the source and line. 
    token = strtok(line, " -,$");
    if (token != NULL)
    {
        strcpy(source, token);
        found = 1;
    }

    //this token represent the destination 
    token = strtok(NULL, " -,$");
    if (token != NULL)
    {
        strcpy(destination, token);
        found = 1;
    }

    // this token is for fare 
    token = strtok(NULL, " -,$");
    if (token != NULL)
    {
        *fare = atoi(token);
        found = 1;
    }

    return found == 1 ? 0 : -1;
}

/* FUNCTION: processFlight
*
* DESCRIPTION :  to process each flight data file
*
* PARAMETERS : char*filename :a pointer to the source variable(char*)
*
*            : struct flight flights[]:an array of structure.
*
*            : int*count:a pointer to the count variable (int*)
*
* RETURN : an int  :  indicating the day that was entereds in int ,or, in the case of the user not entering a
*                     valid day string, -1 indicating an error.
*/
int processFlight(char* filename, struct Flight flights[], int* count)
{
    FILE* fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Error: Unable to open %s\n", filename);
        return 1;
    }

    char line[MAX_LINE];
    int flightCount = 0;

    while (fgets(line, MAX_LINE, fp) != NULL && flightCount < MAX_DATA)
    {
        if (parseLine(flights[flightCount].source, flights[flightCount].destination,
            &flights[flightCount].fare, line) != 0)
        {
            printf("Error: Unable to parse line in %s\n", filename);
            fclose(fp);
            return 1;
        }
        flightCount++;
    }

    fclose(fp);
    *count = flightCount;
    return 0;
}
/*
*FUNCTION: displayLeastFareDetails
*
*DESCRIPTION : display flight details only.
*
*PARAMETERS : : struct flight flights[] :an array of structure.
*
*            : int* count : a pointer to the count variable(int*)
*
*RETURN : nothing.
*/
void displayLeastFareDetails(struct Flight flights[], int count)
{
    // the condition is first put to checks that flight data is accessible. 
    if (count == 0)
    {
        printf("No flights available\n");
        return;
    }

    //initialising variables.
    int k, minIndex;
    struct Flight minFlight;

    // find the flight with the minimum fare
    minFlight = flights[0];
    minIndex = 0;
    for (k = 1; k < count && k < 100; k++)
    {
        if (flights[k].fare < minFlight.fare)
        {
            minFlight = flights[k];
            minIndex = k;
        }
    }

    // display all flights, highlighting the one with the minimum fare
    for (k = 0; k < count && k < 100; k++)
    {
        if (k == minIndex)
        {
            printf("%s to %s, Fare $%d\n",
                minFlight.source, minFlight.destination, minFlight.fare);
        }
        else
        {
            printf("%s to %s, Fare $%d\n",
                flights[k].source, flights[k].destination, flights[k].fare);
        }
    }
}
