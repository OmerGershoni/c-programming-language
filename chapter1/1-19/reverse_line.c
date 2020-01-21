
#include <stdio.h>

#define MAXLINE 1000

/*
 * Exercise 1-19. Write a function reverse(s) that reverses the character string s.
 * Use it to write a program that reverse its input a line at a time.
 */

int getline2(char line[], int maxline);
void reverse(char line[], int len);

int main()
{
	int len;
	char line[MAXLINE];

	while ((len = getline2(line, MAXLINE)) > 0) {
		if (line[len-1] == '\n')
			reverse(line, len-1);
		else
			reverse(line, len);
		printf("%s", line);
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


void reverse(char line[], int len)
{
	int start = 0;
	int end = len -1;
	char temp;

	while (start < end && len > 0) {
		temp = line[start];
		line[start] = line[end];
		line[end] = temp;
		++start;
		--end;
	}
}

