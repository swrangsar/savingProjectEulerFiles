#include <stdio.h>
#include "quadraticPrimes.h"

#define LIMIT 1000

int main()
{
	int a, b, maxprimes, maxA, maxB;
	a = maxprimes = maxA = maxB = 0;
	b = 1;
	
	while ((b += 2) < LIMIT) {
		if (isPrime((long) b)) {
			a = -(LIMIT + 1);
			while ((a += 2) < LIMIT) {
				int primes = numberOfPrimes(a, b);
				if (primes > maxprimes) {
					maxA = a;
					maxB = b;
					maxprimes = primes;
				}
				printf("a: %3d b: %3d maxA: %3d maxB: %3d", a, b, maxA, maxB);
				printf(" primes: %3d maxprimes: %d\n", primes, maxprimes);
			}
		}		
	}
	
	printf("\n###\nThe no. of quadratic primes is max when a: %d b: %d\n", maxA, maxB);
	printf("The max product is: %d\n", maxA*maxB);
		
	return 0;	
}