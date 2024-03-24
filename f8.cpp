#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996) 

struct MyData {
	int howMany;
	char theText[21];
	char directoryPath[21];
	char filename[21];
};
int main(int argc, char** argv) {
	if (argc != 5) {
		printf("invalid amount of arguments");
		return 0;
	}
	struct MyData myArgs;
	myArgs.howMany = atoi(argv[1]);
	strncpy(myArgs.theText, argv[2], sizeof(myArgs.theText) - 1);
	strncpy(myArgs.directoryPath, argv[3], sizeof(myArgs.directoryPath) - 1);
	strncpy(myArgs.filename, argv[4], sizeof(myArgs.filename) - 1);

	FILE* file;
	file = fopen(myArgs.filename, "w");
	if (!file) {
		printf("unable to create a the file");
		return 0;
	}
	for (int i = 0; i < myArgs.howMany; i++) {
		fprintf(file, "%s\n", myArgs.theText);
	}
	return 0;
}

