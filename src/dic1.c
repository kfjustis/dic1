/* Kynan Justis
 * kfjmbb
 * 14212450
 * 2/1/17
 * Digital Image Compression
 * Homework 1 - Problem 5
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h> // for UCHAR_MAX
#include <ctype.h>  // for isalpha()

int main (int argc, char *argv[]) {
	if (argc != 2) {
		printf("Invalid args!\nUsage: %s <text file path>\n", argv[0]);
		return EXIT_FAILURE;
	}

	// Open the file
	FILE *input = fopen(argv[1], "r");

	// Variables
	int ch = 0, i = 0, j = 0;

	// Array to store character frequencies
	unsigned long long counts[UCHAR_MAX + 1] = {0};

	// Stores total sum of characters
	unsigned long total = 0;

	// Array where each element is the probability of the ASCII
	// character with the index of its decimal value
	float probs[UCHAR_MAX + 1] = {0.0};	

	// Maintains the current value for entropy
	float entropy = 0.0;


	// Error check file
	if (input == NULL) {
		printf("ERROR: Could not open file!\n");
		return EXIT_FAILURE;
	}	

	// Read chars in from file and track frequencies and total
	while ((ch = fgetc(input)) != EOF) {
		counts[ch]++;
		total++;
	}	

	// Calculate probabilities and entropy
	for (j = 0; j <= UCHAR_MAX; j++) {
		probs[j] = (float)(counts[j]) / (float)total;
		printf("entropy:: %f\n", entropy);
		if (probs[j] != 0) {
			entropy += ((-probs[j]) * log2f(probs[j]));
		}
	}

	// Print frequencies, character sum, and entropy
	for (i = 0; i <= UCHAR_MAX; i++) {
		if (isalpha(i) && counts[i] > 0 || i >= 32 && i <= 126) {
			printf("%c :: %llu\n", i, counts[i]);
			printf("\tprob: %f\n", probs[i]);
		}
	}
	printf("\ntotal: %lu\n", total);
	printf("entropy: %f\n", entropy);

	fclose(input);

	return EXIT_SUCCESS;
}
