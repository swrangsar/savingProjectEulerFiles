#include <stdio.h>
#include <math.h>
#include "prime.h"

int isPrime(long number)
{
	if (number < 0) number = -number;
	if (number < 2) return 0;
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