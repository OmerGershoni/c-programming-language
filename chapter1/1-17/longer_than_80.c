
#include <stdio.h>

#define MAXLINE 1000
#define MIN_LENGTH_TO_PRINT 80

/*
 * Exercise 1-17. Write a program to print all input lines that
 * are no longer than 80 characters.
 */

int getline2(char line[], int maxline);

int main()
{
	int len;
	char line[MAXLINE];

	while ((len = getline2(line, MAXLINE)) > 0) {
		if (len > MIN_LENGTH_TO_PRINT) {
			printf("\nLine: %sLength: %d\n\n", line, len);
		}
	}

	return 0;
}

// getline: read a line into s, return length
int getline2(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) 
			s[i] = c;

	if (c == '\n') {
		s[i] = c;
		++i;
	}

	s[i] = '\0';
	return i;
}
