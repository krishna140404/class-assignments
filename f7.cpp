/*
* FILE : f7.cpp
* PROJECT : focus Assignment 7
* PROGRAMMER : krishna kachhiapatel
* FIRST VERSION : 2024-03-19
* DESCRIPTION : Write a program to give you practice at creating text and binary files.
*/
#include <stdio.h>

#pragma warning(disable:4996) 

int main(void)
{
    // declaring an array 
    const unsigned short kBinaryData[] = { 26946, 24942, 31090, 25632, 29793, 8289, 28518, 8306, 28537, 33141, 39308 };

    // creating and opening a text file in write mode. 
    FILE* textFile = fopen("myTextFile.txt", "w");
    if (!textFile)
    {
        // it willl display if there s an error in the file opening 
        printf("Error opening text file\n");
        return 1;
    }
    fprintf(textFile, "This is line 1.\nThis is line 2.\n");
    fclose(textFile);

  

    return 0;
}
