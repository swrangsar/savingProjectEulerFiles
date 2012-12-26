#include <stdio.h>
#include <stdlib.h>
#include "prime.h"
#include "circularPrime.h"

#define NUMSIZE	10
#define BASE 10

static int breakNumber(char *digits, int number);
static int buildNumber(char *digits);
static void circularShift(char *digits);


static int breakNumber(char *digits, int number)
{
	/* breaks the number into digits rotates once(already) and returns length */
	int i = 0;
	int last = (number % BASE) + '0';
	number /= BASE;
	
	while ((number) && (i < NUMSIZE-1)) {
		digits[i++] = (number % BASE) + '0';
		number /= BASE;
	}
	digits[i++] = last;
	if (i < NUMSIZE) {
		digits[i] = '\0';
		return i;
	} else {
		digits[NUMSIZE-1] = '\0';
		printf("Number overflow!\n");
		exit(EXIT_FAILURE);
	}
}

static int buildNumber(char *digits)
{
	int number, i;
	number = i = 0;
	int multiplier = 1;

	while (digits[i]) {
		number += (digits[i++]-'0') * multiplier;
		multiplier *= BASE;
	}
	return number;
}

static void circularShift(char *digits)
{
	char prev, temp;
	int i = 0;
	prev = temp = 0;
	
	while (digits[i]) {
		temp = digits[i];
		digits[i++] = prev;
		prev = temp;
	}
	digits[0] = prev;
}

int isCircularPrime(int number)
{
	if (!isPrime(number)) return 0;
	char digits[NUMSIZE];
	int length = breakNumber(digits, number);
	int numberOfRotates = 1;
	if (!isPrime(buildNumber(digits))) return 0;
	
	while (numberOfRotates < length) {
		circularShift(digits);
		if (!isPrime(buildNumber(digits))) return 0;
		++numberOfRotates;
	}
	return 1;
}