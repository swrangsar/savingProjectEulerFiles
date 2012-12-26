#include <stdio.h>
#include "truncatablePrime.h"
#include "prime.h"

#define MAXCOUNT 11

int main()
{
	long sum, i;
	int count = 0;
	i = sum = 0;
	
	while (count < MAXCOUNT) {
		if (isTruncatablePrime(++i)) {
			sum += i;
			++count;
			printf("count: %2d num: %ld sum: %ld\n", count, i, sum);
		}
	}
	
	printf("The reqd sum is: %ld\n", sum);
	return 0;
}