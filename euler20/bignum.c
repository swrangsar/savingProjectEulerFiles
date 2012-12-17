#include <stdio.h>
#include "bignum.h"

static void add(char sum[], char num[])
{
	int i, sumflag, carry;
	i = sumflag = carry = 0;
	
	while (i < LIMIT && num[i]) {
		if (!sum[i]) {
			sumflag = 1;
			break;
		} else {
			int temp = (sum[i]-'0'+num[i]-'0') + carry;
			sum[i++] = temp%BASE + '0';
			carry = (temp < BASE)?0:(temp/BASE);
		}
	}
	if (sumflag) {
		while (num[i]) {
			int temp = num[i]-'0'+carry;
			sum[i++] = temp%BASE + '0';
			carry = (temp < BASE)?0:(temp/BASE);
		}
	} else {
		while (sum[i]) {
			int temp = sum[i]-'0'+carry;
			sum[i++] = temp%BASE + '0';
			carry = (temp < BASE)?0:(temp/BASE);
		}
	}
	if (carry) 
		sum[i++] = carry+'0';
	if (i < LIMIT)
		sum[i] = '\0';
	else {
		sum[LIMIT-1] = '\0';
		printf("Error: addition overflow!\n");
	}
}

static void multiply(char sum[], int digit)
{
	if (digit >= BASE) {
		printf("Error: can multiply only with a digit!\n");
		return;
	}
	if (digit == 1 && sum[0] != '\0') {
		return;
	}
	if (!*sum) {
		sum[0] = digit + '0';
		sum[1] = '\0';
		return;
	}
	int i, carry;
	i = carry = 0;
	while (sum[i]) {
		int temp;
		temp = (sum[i]-'0') * digit + carry;
		sum[i++] = temp%BASE+'0';
		carry = (temp < BASE)?0:(temp/BASE);
	}
	if (carry)
		sum[i++] = carry + '0';
	if (i < LIMIT)
		sum[i] = '\0';
	else {
		sum[LIMIT-1] = '\0';
		printf("Error: addition overflow!\n");
	}
}

static void shift(char sum[])
{
	int i;
	char temp, prev;
	i = 0;
	temp = prev = '0';
	while (sum[i]) {
		temp = sum[i];
		sum[i++] = prev;
		prev = temp;
	}
	if (i < LIMIT-1) {
		sum[i++] = prev;
		sum[i] = '\0';
	} else {
		sum[LIMIT-1] = '\0';
		printf("Error: shift overflow!\n");
	}	
}

static void copy(char s[], char t[])
{
	while ((*s++ = *t++))
		;
}

void product(char sum[], int digit)
{
	char original[LIMIT], addend[LIMIT];
	copy(original, sum);
	copy(addend, sum);
	
	multiply(sum, digit%BASE);
	digit /= BASE;
	int i, j;
	i = j = 0;
	while (digit) {
		j = ++i;
		copy(addend, original);
		multiply(addend, digit%BASE);
		while (j--) {
			shift(addend);
		}
		add(sum, addend);
		digit /= BASE;
	}
}

void show(char s[])
{
	int i;
	i = 0;
	while (s[i])
		++i;
	while(--i >= 0)
		putchar(s[i]);
	putchar('\n');
}

void getsum(char s[])
{
	int i;
	i = 0;
	long sum = 0;
	while (s[i] != '\0') {
		sum += s[i++]-'0';
	}
	printf("The sum of digits of the big number is: %ld\n", sum);	
}