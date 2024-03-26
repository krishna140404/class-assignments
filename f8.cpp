#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 21

#pragma warning (disable:4996)

struct MyData
{
    int howMany;
    char theText[MAX_LENGTH];
    char directoryPath[MAX_LENGTH];
    char filename[MAX_LENGTH];

};

int main(int argc, char* argv[])
{

    if (argc != 5)
    {
        fprintf(stderr, "Error: Incorrect number of arguments. Please provide exactly four arguments.\n");
        return 1;
    }


    // Parse arguments into MyData struct
    struct MyData myArgs;
    myArgs.howMany = atoi(argv[1]);
    strncpy(myArgs.theText, argv[2], MAX_LENGTH - 1);
    myArgs.theText[MAX_LENGTH - 1] = '\0';
    strncpy(myArgs.directoryPath, argv[3], MAX_LENGTH - 1);
    myArgs.directoryPath[MAX_LENGTH - 1] = '\0';
    strncpy(myArgs.filename, argv[4], MAX_LENGTH - 1);
    myArgs.filename[MAX_LENGTH - 1] = '\0';

    char fullPath[MAX_LENGTH + MAX_LENGTH];
    printf(fullPath, sizeof(fullPath), "%s/%s", myArgs.directoryPath, myArgs.filename);

    FILE* outFile = fopen(myArgs.filename, "w");
    if (!outFile)
    {
        printf("Error: Failed to create file");
        return 1;
    }

    for (int i = 0; i < myArgs.howMany; ++i)
    {
        fprintf(outFile, "%s\n", myArgs.theText);
    }

    fclose(outFile);
    printf("Text file created successfully :");


    return 0;
}