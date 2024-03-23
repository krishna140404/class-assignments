
#include <stdio.h>

#pragma warning(disable:4996) 

int main(void)
{
    const unsigned short kBinaryData[] = { 26946, 24942, 31090, 25632, 29793, 8289, 28518, 8306, 28537, 33141, 39308 };

 . 
    FILE* textFile = fopen("myTextFile.txt", "w");
    if (!textFile)
    {
  
        printf("Error opening text file\n");
        return 1;
    }
    fprintf(textFile, "This is line 1.\nThis is line 2.\n");
    fclose(textFile);

  
    FILE* binaryFile = fopen("myEvenDataList.data", "wb");
    if (!binaryFile)
    {
        printf("Error opening binary file\n");
        return 1;
    }
  
    for (int i = 0; i < sizeof(kBinaryData) / sizeof(kBinaryData[0]); ++i)
    {
        if (kBinaryData[i] % 2 == 0)
        {
            if (fwrite(&kBinaryData[i], sizeof(short), 1, binaryFile) != 1)
            {
                printf("Error writing to binary file\n");
                fclose(binaryFile);
                return 1;
            }
        }
    }
    fclose(binaryFile);
  

    return 0;
}
