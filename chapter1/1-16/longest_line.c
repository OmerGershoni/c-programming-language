#include <stdio.h>

#define MAXLINE 10

/*
 * Exercise 1-16. Revise the main routine of the longest-line program so it will
 * correctly print the length of arbitrarily long input lines, and as much as possible
 * of the text.
 */

int getline2(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = getline2(line, MAXLINE)) > 0) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}

	if (max > 0)
		printf("\nLine :%sLength: %d\n", longest, max);

	return 0;
}

// getline: read a line into s, return length
int getline2(char s[], int lim)
{
	int c, i, endIdx = 0;

	for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
		if (i < lim-1) {
			endIdx = i;
			s[i] = c;
		}
	}

	if (c == '\n') {
		s[endIdx] = c;
		++endIdx;
	}
		
	s[endIdx] = '\0';
	return i;
}

// copy: copy 'from' into 'to'; assume to is big enough
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from [i]) != '\0')
		++i;
}

