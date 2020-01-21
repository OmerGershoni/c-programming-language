
#include <stdio.h>

#define MAXLINE 1000
#define NEXT_TAB_STOP 10

/*
 * Exercise 1-20. Write a program 'detab' that replaces tabs in the input with
 * the propper number of blanks to space to the next tab stop. Assume a fixed
 * set of tab stops, say every n columns.
 */

int getline2(char line[], int maxline);

int main()
{
	int len;
	char line[MAXLINE];

	while ((len = getline2(line, MAXLINE)) > 0) {
		for (int i = 0; i < len; ++i) {
			if (line[i] != '\t') {
				putchar(line[i]);
			} else {
				for (int j = 0; j < (NEXT_TAB_STOP - (i % NEXT_TAB_STOP)); ++j)
					putchar(' ');
			}			
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
