#include <stdio.h>
#define LIMIT 500

long triangleNumber(long index);
long numberOfDivisors(long triangleNumber);

int main()
{
	long i, max, temp;
	i = max = temp = 0;
	while ((temp = numberOfDivisors(triangleNumber(++i))) < LIMIT) {
		if (temp > max)
			max = temp;
		printf("Max: %ld\n", max);	
	}
	
	printf("The required triangle number is: %ld\n", triangleNumber(i));
	printf("The number of divisors is: %ld\n", numberOfDivisors(triangleNumber(i)));
	return 0;
}

long triangleNumber(long index)
{
	long sum;
	sum = ((index*(index+1))/2);
	printf("Triangle num: %ld\n", sum);
	return sum;
}

long numberOfDivisors(long triangleNumber)
{
	long i, num, highestFactor;
	i = num = 0;
	highestFactor = triangleNumber;
	while (++i < highestFactor) {
		if ((triangleNumber%i) == 0) {
			++num;
			highestFactor = triangleNumber / i;
			if (highestFactor != i)
				++num;
		}
	}
	printf("Divisors: %ld\n", num);
	return num;
}