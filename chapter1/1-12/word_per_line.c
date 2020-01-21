#include <stdio.h>

#define OUT 0
#define IN 1

/*
 * Exercise 1-12. Write a program that prints its input one word per line.
 */

int main()
{
	char c;
	int status = OUT;
	
	while ((c = getchar()) != EOF) {
		if (c != ' ' && c != '\t') {
			putchar(c);
			status = IN;
		} else if (status == IN) {
			putchar('\n');
			status = OUT;
		}
	} 
	return 0;
}

