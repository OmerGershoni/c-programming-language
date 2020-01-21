
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_STACK_SIZE 1000

char leftSideSymbols[MAX_STACK_SIZE] = {'\0'}; 
int top = -1;

void push(char c);
char pop();

/*
 * Exercise 1-24. Write a program to check a C program for rudimentary syntax
 * errors like unbalanced parentheses, brackets and braces. Don't forget about
 * quotes, both single and double, escape sequences, and comments.
 * (This program is hard if you do it in full generality.)
 */

int main()
{
    char input[2];
    int isInsideString = FALSE;
    int isInsideComment = FALSE;
    int isInsideSingleLineComment = FALSE;
    int isErrorFound = FALSE;
    int lineCounter = 1;
    char lastLeftSymbols[2] = {'\0'};

    input[0] = getchar();

	while (input[0] != EOF && (input[1] = getchar()) != EOF) {
        if (isErrorFound == TRUE) 
            break;

        switch (input[0])
        {
            case '"':
            case '\'':
                if (isInsideComment == FALSE && isInsideSingleLineComment == FALSE) {
                    if (isInsideString == FALSE) {
                        push(input[0]);
                        isInsideString = TRUE;
                    } else {
                        lastLeftSymbols[0] = pop();
                        lastLeftSymbols[1] = '\0';
                        if (input[0] != leftSideSymbols[0])
                            isErrorFound = FALSE;
                    }
                }
                break;
                           
            case '/':
                if (isInsideString == FALSE) {
                    if (input[1] == '*') {
                        isInsideComment = TRUE;
                        push(input[0]);
                        push(input[1]);
                    }

                    if (input[1] == '/')
                        isInsideSingleLineComment = TRUE;
                }
                break;
                
            case '*':
                if (isInsideComment == TRUE) {
                    if (input[1] == '/') {
                        isInsideComment = FALSE;  
                        lastLeftSymbols[0] = pop();
                        lastLeftSymbols[1] = pop();

                        if (lastLeftSymbols[0] != input[0] || lastLeftSymbols[1] != input[1])
                            isErrorFound = TRUE;
                    }   
                }
                break;
                
            case '\n':
                isInsideSingleLineComment = FALSE;
                ++lineCounter;
                break;
                
            case '(':
            case '[':
            case '{':
                if (isInsideComment == FALSE && isInsideSingleLineComment == FALSE && isInsideString == FALSE) 
                    push(input[0]);
                break;

            case ')':
                if (isInsideComment == FALSE && isInsideSingleLineComment == FALSE && isInsideString == FALSE) {
                    lastLeftSymbols[0] = pop();
                    lastLeftSymbols[1] = '\0';
                    if (lastLeftSymbols[0] != '(')
                        isErrorFound = TRUE;
                }
                break;

            case '}':
                if (isInsideComment == FALSE && isInsideSingleLineComment == FALSE && isInsideString == FALSE) {
                    lastLeftSymbols[0] = pop();
                    lastLeftSymbols[1] = '\0';
                    if (lastLeftSymbols[0] != '{')
                        isErrorFound = TRUE;
                }
                break;

            case ']':
                if (isInsideComment == FALSE && isInsideSingleLineComment == FALSE && isInsideString == FALSE) {
                    lastLeftSymbols[0] = pop();
                    lastLeftSymbols[1] = '\0';
                    if (lastLeftSymbols[0] != '[')
                        isErrorFound = TRUE;
                }
                break;
            
            default:
                break;
            }
        
        input[0] = input[1];
    }

    if (isErrorFound == TRUE) {
        printf("Syntax error: missing \'%s\' to line %d!\n", lastLeftSymbols, lineCounter);
    } else if (pop() != FALSE) {
        printf("Syntax error: unnecessary last closing symbol!");
    } else {
        printf("Syntax is valid.");
    }
    
    return 0;
}

void push(char c)
{
    if (top == MAX_STACK_SIZE-1) {
        fprintf(stderr, "Error: stack overflow!\n");
        exit(1);
    }

    leftSideSymbols[++top] = c;
}

char pop()
{
    if (top == -1)
        return FALSE;

    return leftSideSymbols[top--];
}
