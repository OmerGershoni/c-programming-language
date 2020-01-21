
#include <stdio.h>

#define MAXLINE 1000
#define NEXT_TAB_STOP 15
#define TAB_SPACES 8

/*
 * Exercise 1-21. Write a program entab that replaces strings of blanks by the
 * minimum number of tabs and blanks to achieve the same spacing. Use the
 * same tab stops as for detab.
 */

int getline2(char line[], int maxline);
void entab_print(int i);

int main()
{
	int len;
	char line[MAXLINE];

	while ((len = getline2(line, MAXLINE)) > 0) {
		for (int i = 0; i < len; ++i) {
			if (line[i] != '\t' && line[i] != ' ') {
				putchar(line[i]);
			} else {
                entab_print(i);         
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

void entab_print(int i)
{
    int nextTabStop = NEXT_TAB_STOP - (i % NEXT_TAB_STOP);
    for (int j = 0; j < nextTabStop; ++j) {
        if ((j + TAB_SPACES) <= nextTabStop) {
            putchar('\t');
            j += (TAB_SPACES - 1);
        } else {
            putchar(' ');
        }
    }
}
