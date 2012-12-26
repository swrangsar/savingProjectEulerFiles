#include <stdio.h>
#include <math.h>

int isPrime(long number)
{
	if (number < 0) number = -number;
	if (!(number & 1)) {
		return (number == 2)?1:0;
	} else {
		long root = (long)sqrt(number);
		long i = 1;
		while ((i += 2) <= root)
			if (!(number%i)) return 0;
		return 1;
	}
}

static long quadraticPrime(int number, int a, int b)
{
	return (long)((number * number)+(a * number)+ b);
}

int numberOfPrimes(int a, int b)
{
	int i = 0;
	
	while (isPrime(quadraticPrime(i, a, b)))
		++i;
	return i;	
}
