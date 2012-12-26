#include <stdio.h>
#include "dbg.h"

#define DECSIZE 10
#define BINSIZE	30
#define DECIMAL 10
#define BINARY	2

int isPalindrome10(int number)
{
	char digits[DECSIZE];
	int i, j, length;
	i = j = 0;
	while (number && (i < DECSIZE)) {
		digits[i++] = (number%DECIMAL) + '0';
		number /= DECIMAL;
	}
	
	checkError((i < DECSIZE), "Decimal number overflow!");
	digits[i] = '\0';
	length = i;
	
	i = 0;
	j = length-1;
	while (i < j) {
		if (digits[i++] != digits[j--]) return 0;
	}
	return 1;
}

int isPalindrome2(int number)
{
	char digits[BINSIZE];
	int i, j, length;
	i = j = 0;
	while (number && (i < BINSIZE)) {
		digits[i++] = (number%BINARY) + '0';
		number /= BINARY;
	}
	
	checkError((i < BINSIZE), "Binary number overflow!");
	digits[i] = '\0';
	length = i;
	
	i = 0;
	j = length-1;
	while (i < j) {
		if (digits[i++] != digits[j--]) return 0;
	}
	printf("Binary: %s ", digits);
	return 1;
}

