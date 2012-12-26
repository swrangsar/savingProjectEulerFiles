#include <stdio.h>
#include "doubleBasePalindrome.h"
#define LIMIT 1000000

int main()
{
	long sum = 0;
	int i = 0;
	
	while (++i < LIMIT) {
		if ((isPalindrome10(i)) && (isPalindrome2(i))) {
			sum += i;
			printf("Decimal: %7d sum: %ld\n", i, sum);
		}
	}
	
	printf("\nThe reqd sum is: %ld\n", sum);
	return 0;
}