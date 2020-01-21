
#include <stdio.h>

#define TRUE 1
#define FALSE 0

/*
 * Exercise 1-23. Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constants properly.
 * C comments do not nest.
 */

int main()
{
    char input[2];
    int isInsideString = FALSE;
    int isInsideComment = FALSE;
    int isInsideSingleLineComment = FALSE;

    input[0] = getchar();

	while (input[0] != EOF && (input[1] = getchar()) != EOF) {
        switch (input[0])
        {
            case '"':
                if (isInsideComment == FALSE && isInsideSingleLineComment == FALSE) {
                    isInsideString = (isInsideString ? FALSE : TRUE);
                    putchar(input[0]);
                }
                break;
                           
            case '/':
                if (isInsideString == FALSE) {
                    if (input[1] == '*')
                        isInsideComment = TRUE;
                    if (input[1] == '/')
                        isInsideSingleLineComment = TRUE;
                }
                break;
                
            case '*':
                if (isInsideComment == TRUE) {
                    if (input[1] == '/')    
                        isInsideComment = FALSE;  
                }
                break;
                
            case '\n':
                isInsideSingleLineComment = FALSE;
                putchar(input[0]);
                break;
                
            default:
                if (isInsideComment == FALSE && isInsideSingleLineComment == FALSE)
                    putchar(input[0]);
                break;
            }
        
        input[0] = input[1];
    }

    return 0;
}