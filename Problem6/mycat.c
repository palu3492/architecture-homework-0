#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>

unsigned long long int packFrequencies(int* freqInts);
void itoa(unsigned long long int num, char* string);

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
		file = fopen(inputFile , "r"); // Open file for reading
		if(file == NULL) {
			printf ("Error opening file\n");
			return 1;
		}
		// Read each line
		int freqInts[4];
		int i = 0;
		char line[25];
		while(fgets(line, 25, file) != NULL){
			strcat(fileContents, line); // Add each line to file contents

			if(i < 4){
				char* endptr;
				freqInts[i] = round(strtof(line, &endptr)); // round to nearest int
			}
			i++;
		}
		// freqInts now contains the first four rounded CPU frequencies
		unsigned long long int packed = packFrequencies(freqInts);
		strcat(fileContents, "\nPacked freqs: ");
		// Append to print out
		char packedString[32];
		sprintf(packedString, "%lld", packed);
		strcat(fileContents, packedString);
		strcat(fileContents, "\n");		
		
		fclose(file);
		if(outputFile != NULL){
			file = fopen(outputFile , "w"); // Open file for writing
			fputs(fileContents, file); // Write to file
			fclose(file);
		} else {
			printf("%s", fileContents); // Print file
		}
	} else {
		printf ("Please provide an input file\n");
	}

	return 0;
}

unsigned long long int packFrequencies(int freqInts[]){
	unsigned long long int packed;
	packed = freqInts[3];
	for(int i = 2; i>=0; i--){
		packed = packed << 16;
		packed = packed | freqInts[i];
	}
	return packed;
}

void itoa(unsigned long long int num, char* string){
	int i = 0;
	while (num != 0) { 
        int rem = num % 10; 
        string[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0'; 
        num = num/10; 
    }
    
    // strrev(string, i);

}


