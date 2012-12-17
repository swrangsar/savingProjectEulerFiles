#include <stdio.h>
#include <stdlib.h>

#define START 1900
#define END 2000
#define WEEK 7

int isLeap(int year);
int days(int year, int *carry, const char daytable[][13]);


int main()
{
	const char daytable[2][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	int *carry, sum, year;
	carry = malloc(sizeof(int));
	*carry = sum = 0;
	year = START;
	
	while (year <= END) {
		sum += days(year, carry, daytable);
		printf("Sum: %d\n", sum);
		++year;
	}
	
	printf("The total number of month first sundays: %d\n", sum);
	
	if (carry) free(carry);
	return 0;
}

int isLeap(int year)
{
	if ((year%4 == 0 && year%100 != 0) || (year%400 == 0))
		return 1;
	else 
		return 0;
}

int days(int year, int *carry, const char daytable[][13])
{
	int leap, i, sum;
	leap = isLeap(year);
	i = sum = 0;
	
	while (++i < 13) {
		if (*carry == (WEEK-1) && year > START) {
			sum += 1;
		}
		*carry = (*carry + daytable[leap][i])%WEEK;
	}
	printf("%d: leap: %d carry: %d sum: %d\n", year, leap, *carry, sum);
	return sum;
}
