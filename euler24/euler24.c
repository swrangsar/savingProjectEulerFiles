#include <stdio.h>
#include "permute.h"

#define LIMIT 1000000

int main()
{
	char number[NUMLEN+1];
	int count;
	count = 0;
	initialize(number);
	show(number, ++count);
	
	while (count < LIMIT) {
		if (!increment(number)) {
			printf("ERROR: there was a number overflow!\n");
			break;
		}
		if (isPermutation(number)) {
			++count;
			show(number, count);
		}	
	}
	
	return 0;
}