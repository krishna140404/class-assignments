
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_DATA 100
#define MAX_LINE 80
#define MAX_NAME 30
#pragma warning (disable :4996)

struct Flight 
{
    char source[MAX_NAME];
    char destination[MAX_NAME];
    int fare;
    char airline[MAX_NAME];
};

int parseLine(char* line, Flight* flight);
int processFlight(char* filename, Flight flights[], int* count);
void displayLeastFareDetails(Flight flights[], int count);


int main(void)
{
    FILE* fp;
    char filename[MAX_FILES][MAX_NAME];
    Flight flights[MAX_DATA];
    int count = 0;

    // Read filenames from flights.txt
    fp = fopen("flights.txt", "r");
    if (fp == NULL)
    {
        printf("Error: Unable to open flights.txt\n");
        return 1;
    }
    while (fscanf(fp, "%s\n", filename[count]) != EOF && count < MAX_FILES)
    {
        count++;
    }
    fclose(fp);

    // Process each flight file and parse data
    int k, j, status;
    for (k = 0; k < count; k++)
    {
        status = processFlight(filename[k], flights, &j);
        if (status != 0)
        {
            printf("Error: Unable to process %s\n", filename[k]);
            continue;
        }
        if (j > 0)
        {
            // Display least fare details for first 100 datasets
            printf("\nFlight details for first 100 datasets:\n");
            displayLeastFareDetails(flights, j);
        }
    }

    return 0;
}

int parseLine(char* line, Flight* flight)
{
    char* token;
    int found = 0;

    token = strtok(line, " -,$");
    if (token != NULL) 
    {
        strcpy(flight->source, token);
        found = 1;
    }
    token = strtok(NULL, " -,$");
    if (token != NULL) 
    {
        strcpy(flight->destination, token);
        found = 1;
    }
    token = strtok(NULL, " -,$");
    if (token != NULL) 
    {
        flight->fare = atoi(token);
        found = 1;
    }
    if (found)
    {
        token = strtok(line, " -,$");
        if (token != NULL) 
        {
            strcpy(flight->airline, token);
        }
    }

    return found;
}

int processFlight(char* filename, Flight flights[], int* count)
{
    FILE* fp;
    char line[MAX_LINE];
    Flight flight;
    int k = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) 
    {
        return 1;
    }
    while (fgets(line, sizeof(line), fp) != NULL && k < MAX_DATA)
    {
        if (parseLine(line, &flight) && strcmp(flight.airline, "") != 0)
        {
            strcpy(flights[k].source, flight.source);
            strcpy(flights[k].destination, flight.destination);
            flights[k].fare = flight.fare;
            strcpy(flights[k].airline, filename);
            k++;
        }
    }
    fclose(fp);
    *count = k;

    return 0;
}

void displayLeastFareDetails(Flight flights[], int count)
{
    int k, j, minIndex;
    Flight minFlight;

    for (k = 0; k < count && k < 100; k++) 
    {
        if (k == 0) 
        {
            minFlight = flights[k];
            minIndex = k;
        }
        else 
        {
            if (flights[k].fare < minFlight.fare) 
            {
                minFlight = flights[k];
                minIndex = k;
            }
        }
    }

    for (j = 0; j < k && j < 100; j++)
    {
        if (j == minIndex) 
        {
            printf("%s: %s to %s, Fare $%d\n",
                minFlight.airline, minFlight.source, minFlight.destination, minFlight.fare);
        }
        else
        {
            printf("%s: %s to %s, Fare $%d\n",
                flights[j].airline, flights[j].source, flights[j].destination, flights[j].fare);
        }
    }
}