#include <stdio.h>

#define MAXLINE 1000

/*
 * Exercise 1-18. Write a program to remove trailing blanks and tabs from each
 * line of input, and to delete entirley blanks line.
 */

int getline2(char line[], int maxline);

int main()
{
	int len;
	char line[MAXLINE];

	while ((len = getline2(line, MAXLINE)) > 0) {
		for (int i = 0; i < len; ++i) {
			if (line[i] != ' ' && line[i] != '\t')
				putchar(line[i]);
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
