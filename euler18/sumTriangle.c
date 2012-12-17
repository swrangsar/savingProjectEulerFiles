#include <stdio.h>
#include <stdlib.h>
#include "sumTriangle.h"
#define MAX(a, b) (a > b)?(a):(b)

static int index(int row, int column)
{
	int sum;
	if (column > row) {
		printf("Illegal index: column cannot be greater than row!\n");
		printf("NOTE: indices start at 1.\n");
		exit(1);
	}
		
	sum = ((row-1)*row) / 2;
	sum += column;	
	return (sum-1);
}

static void updaterow(long triangle[], int row)
{
	int i;
	long addend;
	i = 0;
	addend = 0;
	
	while (++i <= row) {
		addend = MAX(triangle[index(row+1, i)], triangle[index(row+1, i+1)]);
		triangle[index(row, i)] += addend;
	}
}

void sumtriangle(long triangle[], int rows)
{
	while (--rows > 0) {
		updaterow(triangle, rows);
	}
	printf("The triangle has been summed up :)\n");
}

static void printrow(long triangle[], int row)
{
	int i;
	i = 0;
	
	while (++i <= row) {
		printf("%ld ", triangle[index(row, i)]);
	}
	putchar('\n');
}

void printtriangle(long triangle[], int rows)
{
	int i;
	i = 0;
	printf("... printing triangle started ...\n");
	while (++i <= rows) {
		printrow(triangle, i);
	}
	printf("... printing triangle ends ...\n");		
}

