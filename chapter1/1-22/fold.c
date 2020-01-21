
#include <stdio.h>

#define NEXT_FOLD 10
#define TRUE 1
#define FALSE 0

/*
 *  Exercise 1-22. Write a program to "fold" long input lines into two or more
 *  shorter lines after the last non-blank character that occurs before the n-th
 *  column of input. Make sure your program does something intelligent with very
 *  long lines, and if there are no blanks or tabs before the specified column.
 */

int main()
{
	int lineCounter = 0;
    int isBeforeNextFold = TRUE;
    char c;

	while ((c = getchar()) != EOF) {
        if ((NEXT_FOLD - (lineCounter++ % NEXT_FOLD)) == 1) 
            isBeforeNextFold = TRUE;
            
        if ((c != ' ' && c != '\t') || isBeforeNextFold == FALSE) {
            putchar(c);
        } else {
            putchar('\n');
            isBeforeNextFold = FALSE; 
        }
    }

    return 0;
}
