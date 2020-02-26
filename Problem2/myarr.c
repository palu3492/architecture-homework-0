#include <stdio.h>

int main (int argc, char **argv) {
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
	
	return 0;
}
