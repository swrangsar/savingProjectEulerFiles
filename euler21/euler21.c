#include <stdio.h>
#include <math.h>
#define LIMIT 10000

int sumOfDivisors(int number);

int main()
{
	long sum;
	int i, a, b;
	i = a = b = 0;
	sum = 0;
	
	while (++i < LIMIT) {
		b = sumOfDivisors(i);
		if (b > i && b < LIMIT) {
			a = sumOfDivisors(b);
			if (i == a) {
				sum += (long)(a+b);
				printf("a: %d b: %d\nsum: %ld\n", a, b, sum);
			}
		}		
	}
	
	printf("The sum of amicable numbers is: %ld\n", sum);
	return 0;
}

int sumOfDivisors(int number)
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