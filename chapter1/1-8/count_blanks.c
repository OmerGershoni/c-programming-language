#include <stdio.h>

/* 
 * Exercise 1-8. Write a program to count blanks,
 * tabs, and newlines.
 */

int main()
{
	char c;
	unsigned int count = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '	' || c == '\n') 
			++count;
	}

	printf("\n%u\n", count);
	return 0;
}

