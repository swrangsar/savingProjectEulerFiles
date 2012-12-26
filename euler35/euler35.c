#include <stdio.h>
#include "circularPrime.h"

#define LIMIT 1000000

int main()
{
	int i, count;
	count = 0;
	i = 1;
	
	while (++i < LIMIT) {
		if (isCircularPrime(i)) {
			++count;
			printf("%9d count: %7d\n", i, count);
		}
	}
	
	printf("The total count is: %d\n", count);
	return 0;
}