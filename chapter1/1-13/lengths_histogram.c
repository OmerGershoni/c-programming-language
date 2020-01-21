#include <stdio.h>

#define MAX_WORDS 100
#define IN 1
#define OUT 0

/*
 * Exercise 1-13. Write a program to print a histogram of the lengths
 * of words in its input. It is easy to draw the histogram with the
 * bars horizonal; a vertical orientation is more challenging.
 */

int main() 
{
	int lengths[MAX_WORDS] = { 0 };
	int currWord = 0;
	int maxLen = 0;
	int status = OUT;
	char c;

	// Count the lengths of words from input
	while ((c = getchar()) != EOF) {
		if (c != ' ' && c != '\t' && c != '\n') {
			status = IN;
			++lengths[currWord];
		} else if (status == IN) {
			if (maxLen < lengths[currWord])
				maxLen = lengths[currWord];
			status = OUT;
			++currWord;
		}
	} 
	
	// Print histogram
	putchar('\n');
	for (int i = maxLen; i > 0; --i) {
		for (int j = 0; j < currWord; ++j) {
			if (lengths[j] >= i) {
				printf("* ");
			} else {
				printf("  ");
			}
		}	
		putchar('\n');
	}
	
	return 0;
}

