#include <stdio.h>
#include "abundant.h"

int main()
{
	printf("... printing numbers !sum of 2 abundant ...\n");
	long sum;
	sum = sumOfNotTwoAbundant();
	
	printf("The sum of !two-abundants: %ld\n", sum);
	return 0;
}