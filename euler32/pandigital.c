#include <stdio.h>
#include "pandigital.h"
#define BASE 10

static int pandigitalFactors(int number);

int isPandigital(int number)
{
	char flags[BASE];
	int i = 0;
	flags[i++] = 0;
	while (i < BASE)
		flags[i++] = 1;
	while (number) {
		flags[number%BASE] = 0;
		number /= BASE;
	}
	
	i = 0;
	while (i < BASE) {
		if (flags[i++]) return 0;
	}
	return 1;
}

int pandigitalProduct(int number)
{
	return (number%10000);
}

static int pandigitalFactors(int number)
{
	return (number/10000);
}

int hasPandigitalProduct(int number)
{
	int product = pandigitalProduct(number);
	int factors = pandigitalFactors(number);
	int extractor = BASE;
	int a, b;
	
	while ((factors/extractor)) {
		a = factors/extractor;
		b = factors%extractor;
		if ((a*b) == product) {
			printf("%d x %d = %d\n", a, b, product);
			return 1;
		}
		extractor *= BASE;
	}
	return 0;
}