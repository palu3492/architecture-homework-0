#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
	char *inputFile = NULL;
	char *outputFile = NULL;
	
	int c;
	opterr = 0;
	
	while ((c = getopt(argc, argv, "fo")) != -1) {
		switch(c) {
			case 'f':
				inputFile = argv[optind];
				break;
			case 'o':
				outputFile = argv[optind];
				break;
			case '?':
				// ignore
				break;
		}
	}
	// printf("input: %s, output: %s\n", inputFile, outputFile);
	FILE *file;
	char fileContents[500];
	if(inputFile != NULL){
		file = fopen(inputFile , "r"); // open file for reading
		if(file == NULL) {
			printf ("Error opening file\n");
			return 1;
		}
		char line[25];
		while(fgets(line, 25, file) != NULL){
			strcat(fileContents, line);
		}
		fclose(file);
		if(outputFile != NULL){
			file = fopen(outputFile , "w"); // open file for writing
			fputs(fileContents, file);
			fclose(file);
		} else {
			printf("%s", fileContents);
		}
	} else {
		printf ("Please provide an input file\n");
	}

	return 0;
}
