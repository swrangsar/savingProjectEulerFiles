#include <stdio.h>
#include "distinctPower.h"

int main()
{
	int a, b, sum;
	sum = 0;
	a = 1;
	
	while (++a <= LIMIT) {
		b = 1;
		while (++b <= LIMIT) {
			if (isDistinctPower(a, b)) {
				++sum;
				printf("count: %5d distinct a: %3d b: %3d\n", sum, a, b);
			} else {
				printf("count: %5d not distinct a: %3d b: %3d\n", sum, a, b);
			}
		}
	}
	
	printf("\n\n###\nThe total count of distinct powers: %d\n", sum);
	return 0;
}