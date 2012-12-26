#include <stdio.h>
#include <math.h>
#include "digitFifthPowers.h"

#define BASESYSTEM 10
#define EXPONENT 5

int isSumOfDigitFifthPowers(int number)
{
	int numcopy, sum;
	numcopy = number;
	sum = 0;
	
	while (numcopy) {
		sum += (int) pow((numcopy%BASESYSTEM), EXPONENT);
		numcopy /= BASESYSTEM;
		if (sum > number) return 0;
	}
	return (number == sum)?1:0;
}