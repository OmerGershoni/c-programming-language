
#include <stdio.h>

#define ASCII_TABLE_SIZE 256

/*
 * Exercise 1-14. Write a program to print a histogram of the frequencies
 * of different characters in its input;
 */

int main() 
{
	int frquencies[ASCII_TABLE_SIZE] = { 0 };
	int maxFrq = 0;
	char c;

	// Count the number of different characters from input
	while ((c = getchar()) != EOF) {	
		if (c != ' ' && c != '\t' && c != '\n')
			++frquencies[c];	
		if (maxFrq < frquencies[c])
			maxFrq = frquencies[c];
	}

	// Print histogram
	putchar('\n');
	for (int i = maxFrq; i > 0; --i) {
		for (int j = 0; j < ASCII_TABLE_SIZE; ++j) {
			if (frquencies[j] >= i) {
				printf("* ");
			} else if (frquencies[j] > 0) {
				printf("  ");
			}
		}	
		putchar('\n');
	}
	
	for (int i = 0; i < ASCII_TABLE_SIZE ; ++i) {
		if (frquencies[i] > 0) 
			printf("%c ", i);
	}
	putchar('\n');

	return 0;
}

