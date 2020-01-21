#include <stdio.h>

/*
 * Exercise 1-4. Write a program to print the corresponding
 * Celsius to Fahrenheit table.
 */

int main() 
{

	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("celsius fahr\n");
	fahr = lower;
	while (celsius <= upper) {
		fahr = (9.0 / 5.0) * (celsius + 32.0);
		printf("%6.1f %3.0f\n", celsius, fahr);
		celsius = celsius + step;
	}
	return 0;
}

