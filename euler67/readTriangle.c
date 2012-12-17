#include <stdio.h>
#include <ctype.h>
#include "readTriangle.h"

static int getdigit(long triangle[], int index)
{
	int c, i, sum;
	i = sum = 0;
	
	while (i < 2 && (c = getchar()) != EOF) {
		if (isdigit(c)) {
			sum = (sum * 10) + (c - '0');
			++i;
		}
	}
	
	if (c == EOF) {
		return 0;
	} else {
		triangle[index] = (long)sum;
		return 1;
	}
}

void readtriangle(long triangle[], int rows)
{
	int i, limit;
	i = 0;
	limit = (rows * (rows+1))/2;
	while (i < limit && getdigit(triangle, i))
		++i;
}