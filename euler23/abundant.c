#include <stdio.h>
#include <math.h>
#include "abundant.h"

static int sumOfProperDivisors(int number)
{
	int i, sum, root, otherFactor;
	i = sum = 0;
	root = (int)sqrt((double)number);
	
	while (++i <= root) {
		if ((number)%i == 0) {
			sum += i;
			otherFactor = number/i;
			if (otherFactor < number && otherFactor != i)
				sum += otherFactor;
		}
	}
	return sum;
}

static int isAbundant(int number)
{
	return (sumOfProperDivisors(number) > number)?1:0;		
}

static int isSumOfTwoAbundant(int number)
{
	int i, limit;
	i = 0;
	limit = number/2;
	while (++i <= limit) {
		if (isAbundant(i)) {
			if (isAbundant(number-i))
				return 1;
		}
	}
	return 0;
}

long sumOfNotTwoAbundant(void)
{
	int i;
	long sum;
	i=0;
	sum=0;
	while (++i <= LIMIT) {
		if (!isSumOfTwoAbundant(i)) {
			sum += i;
			printf("%d\nsum: %ld\n", i, sum);			
		}
	}
	return sum;
}