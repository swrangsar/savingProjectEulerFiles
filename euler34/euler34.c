#include <stdio.h>
#include "digitFactorial.h"
#define LIMIT 10000000
int main()
{
	int i = 9;
	long sum = 0;
	while (++i < LIMIT) {
		if (isDigitFactorial(i)) {
			sum += i;
			printf("num: %7d sum: %ld\n", i, sum);
		}
	}
	
	printf("The reqd sum: %ld\n", sum);
	return 0;
}