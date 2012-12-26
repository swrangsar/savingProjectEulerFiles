#include <stdio.h>
#include <math.h>
#include "distinctPower.h"

static int getExponent(int number, int base)
{
	int count = 0;
	while (number > base) {
		if ((number%base == 0))
			++count;
		else
			return 0;
		number /= base;
	}
	return (number == base)?(count+1):0;
}


static int checkLowerPowers(int a, int b, int base)
{
	int exponent = getExponent(a, base);
	if (!exponent) return 0;
	
	b *= exponent;
	if (b <= LIMIT) return 1;
	int i = 2;
	while ((int)pow(base, i) < a) {
		if ((b%i == 0) && ((b/i) <= LIMIT)) return 1;
		++i;
	}
	return 0;		
}

int isDistinctPower(int a, int b)
{
	int i = 1;

	while (++i <= (int) sqrt(a)) {
		if (checkLowerPowers(a, b, i)) return 0;
	}
	return 1;
}