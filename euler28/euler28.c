#include <stdio.h>
#define LIMIT 1001

int main()
{
	int i = 1;
	int step = 2;
	int times = 0;
	long sum = 0;
	sum += i;
	printf("spiral: %4d ", 1);
	printf("diagnum: %7d sum: %ld\n", i, sum);
	
	while (step < LIMIT) {
		times = 4;
		while (times--) {
			i += step;
			sum += i;
			printf("spiral: %4d ", step+1);
			printf("diagnum: %7d sum: %ld\n", i, sum);
		}
		step += 2;
	}
	
	printf("\n\n###\nThe sum of diagonal numbers is: %ld\n", sum);
	return 0;
}