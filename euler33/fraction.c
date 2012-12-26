#include <stdio.h>
#include <stdlib.h>
#include "fraction.h"
#include "prime.h"
#define MIN(A, B) (A < B)?(A):(B)


fraction *createFraction(int a, int b)
{
	fraction *new = malloc(sizeof(fraction));
	if (!new) {
		printf("Fraction could not be allocated!\n");
		exit(EXIT_FAILURE);
	}
	new->numerator = a;
	new->denominator = b;
	return new;
}

void destroyFraction(fraction *input)
{
	if (input) free(input);	
}

void multiplyFractions(fraction *a, fraction *b)
{
	a->numerator *= b->numerator;
	a->denominator *= b->denominator;
	destroyFraction(b);
}

void showFraction(fraction *input)
{
	printf("fraction: %d/%d\n", input->numerator, input->denominator);
}

void reduceFraction(fraction *input)
{
	int a = input->numerator;
	int b = input->denominator;
	int i = 1;
	int min;
	
	while (++i <= (min = MIN(a,b))) {
		if (isPrime(i)) {
			while (!(a%i) && !(b%i)) {
				a /= i;
				b /= i;
			}
		}
	}
	input->numerator = a;
	input->denominator = b;
}

int isEqualFraction(fraction *a, fraction *b)
{
	reduceFraction(a);
	reduceFraction(b);
	
	if ((a->numerator == b->numerator) && (a->denominator == b->denominator))
		return 1;
	else
		return 0;
}
	