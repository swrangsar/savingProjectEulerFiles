#include <stdio.h>
#include "digitFifthPowers.h"

#define LIMIT 1000000

int main()
{
	int i = 100;
	long sum = 0;
	
	while (++i < LIMIT) {
		if (isSumOfDigitFifthPowers(i)) {
			sum += i;
			printf("num: %6d sum: %ld\n", i, sum);
		}
	}
	
	printf("The sum of digit fifth powers: %ld\n", sum);
	return 0;
}