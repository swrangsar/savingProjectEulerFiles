#include <stdio.h>

#define LIMIT 1000
#define BASE 10

void multiply(char number[], int digit);
void show(char number[]);
long sum(char number[]);


int main()
{
	char number[LIMIT];
	int i;
	*number = '\0';
	i = 0;
	while (i++ < LIMIT)
		multiply(number, 2);
	
	printf("The sum of digits is: %ld\n", sum(number));
	return 0;	
}

void multiply(char number[], int digit)
{
	int i, carry;
	i = 0;
	if (number[i] == '\0') {
		number[i++] = digit + '0';
		number[i] = '\0';
		show(number);
		return;
	}
	
	carry = 0;
	while (number[i] != '\0') {
		int temp;
		temp = ((number[i]-'0') * digit) + carry;
		if (temp < BASE) {
			number[i++] = temp + '0';
			carry = 0;
		} else {
			number[i++] = temp%BASE + '0';
			carry = temp/BASE;				
		}
	}
	if (carry) {
		number[i++] = carry + '0';
		if (i < LIMIT) {
			number[i] = '\0';
		} else {
			number[--i] = '\0';
			printf("Error: There was a number overflow!\n");
		}
	}
	show(number);
}

void show(char number[])
{
	int i;
	i = 0;
	while (number[i] != '\0' && i < LIMIT)
		++i;
	while (--i >= 0)
		putchar(number[i]);
	putchar('\n');
}

long sum(char number[])
{
	int i;
	long sum;
	i = 0;
	sum = 0;
	while (number[i] != '\0')
		sum += (number[i++]-'0');
	return sum;
}