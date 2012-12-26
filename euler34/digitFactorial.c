#include <stdio.h>
#include <stdlib.h>
#include "digitFactorial.h"
#define BASE 10

static int factorial(int number)
{
	if (number < 0) {
		printf("Factorial undefined for -ve integers!\n");
		exit(EXIT_FAILURE);
	}
	if (!number) return 1;
	return number*factorial(number-1);	
}

int isDigitFactorial(int number)
{
	int sum, numcopy;
	sum = 0;
	numcopy = number;
	while (numcopy) {
		sum += factorial(numcopy % BASE);
		numcopy /= BASE;
		if (sum > number) return 0;
	}	
	return (number == sum)?1:0;
}