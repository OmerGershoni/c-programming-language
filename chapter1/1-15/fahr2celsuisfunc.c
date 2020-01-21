
#include <stdio.h> 

/*
 * Exercise 1-15. Rewrite the temperature conversion program of Section
 * 1.2 to use a function for conversion.
 */

float fahr2celsius(float fahr);

int main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("fahr  celsius\n");
	fahr = lower;
	while (fahr <= upper) {
		celsius = fahr2celsius(fahr);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	return 0;
}


float fahr2celsius(float fahr)
{
	return (5.0 / 9.0) * (fahr - 32.0);
} 

