#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void copyArray(int *fibNums, int *my_arr2, int size);

int main(int argc, char **argv) {
	int fibNums[20] = {0, 1}; // Int array size 20 with first two Fibonacci numbers
	// Fill array with remaining 18 numbers
	for(int i = 2; i<20; i++){
		fibNums[i] = fibNums[i-1] + fibNums[i-2];
	}
	printf("First 20 Fibonacci numbers:\n");
	// Print first 19 numbers
	for(int i = 0; i<19; i++){
		printf("%d, ", fibNums[i]);
	}
	printf("%d\n", fibNums[19]); // Print last number
	
	// New for problem 3
	int* my_arr2 = (int*)malloc(20*sizeof(int)); // allocate space for 20 ints and cast int pointer to it
	// Copy fibNums array into my_arr2 array
	copyArray(fibNums, my_arr2, 20);
	
	// Overwrite the contents of my_arr2 with the first 20 square numbers
	for(int i = 0; i<20; i++){
		*(my_arr2+i) = pow(i, 2);
	}
	// Print contents of my_arr2
	printf("First 20 square numbers:\n");
	for(int i = 0; i<19; i++){
		printf("%d, ", *(my_arr2+i));
	}
	printf("%d\n", *(my_arr2+19));
	
	free(my_arr2); // free memory allocation
	
	return 0;
}

void copyArray(int *fibNums, int *my_arr2, int size) {
 	memcpy(my_arr2, fibNums, size*sizeof(int));
}
