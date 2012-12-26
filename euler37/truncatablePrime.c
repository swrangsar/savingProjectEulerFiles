#include <stdio.h>
#include "prime.h"
#include "truncatablePrime.h"
#include "dbg.h"

#define BASE 10
#define NUMSIZE 40

int isTruncatablePrime(long number)
{
	if (!isPrime(number)) return 0;
	int i = 0;
	long newnumber = 0;
	int multiplier = 1;
	
	while (number) {
		++i;
		newnumber += ((number%BASE) * multiplier);
		if (!isPrime(newnumber)) return 0;
		number /= BASE;
		if (number && (!isPrime(number))) return 0;
		multiplier *= BASE;
	}
	return (i < 2)?0:1;		
}