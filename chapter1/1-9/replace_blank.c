#include <stdio.h>

#define TRUE 1
#define FALSE 0

/* 
 * Exercise 1-9. Write a program to copy its input to its output,
 * replacing string of one or more blanks by a single blank.
 */

int main()
{
	char c;
	int isFirstBlank = TRUE;

	while ((c = getchar()) != EOF) {
		if (c != ' ') {
			putchar(c);
			isFirstBlank = TRUE;
		} else if (isFirstBlank == TRUE) {
			putchar(' ');
			isFirstBlank = FALSE;
		}
	}

	return 0;
}

