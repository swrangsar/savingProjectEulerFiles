#include <stdio.h>
#include "permute.h"

void initialize(char s[])
{
	int i;
	i = 0;
	while (i < NUMLEN) {
		s[i] = i + '0';
		++i;
	}
	s[i] = '\0';
}

/* return 0 if there is overflow */
int increment(char s[])
{
	int i, carry, increase;
	carry = 0;
	increase = STEP;
	i = NUMLEN;
	while (--i >= 0) {
		int temp;
		temp = s[i] - '0' + increase + carry;
		increase = 0;
		s[i] = temp%10 + '0';
		carry = temp/10;
	}
	return (carry)?0:1;	
}

static int found(char s[], int digit)
{
	int i;
	i = 0;
	while (i < NUMLEN) {
		if (digit == (s[i++] - '0')) return 1;
	}
	return 0;
}

int isPermutation(char s[])
{
	int i;
	i = 0;
	while (i < NUMLEN) {
		if (!found(s, i++)) return 0;
	}
	return 1;
}

void show(char s[], int count)
{
	printf("%s : %d\n", s, count);
}
