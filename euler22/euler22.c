#include <stdio.h>
#include "firstNames.h"

#define LIMIT 6000

int main()
{
	char *firstnames[LIMIT];
	int i, length;
	long sum, score;
	sum = score = 0;
	i = length = 0;
	
	printf("\n\nReading first names...\n");
	length = readFirstNames(firstnames);
	showFirstNames(firstnames);
	sortFirstNames(firstnames, 0, length-1);
	showFirstNames(firstnames);
	
	while (i < length) {
		score = (long)(alphaValue(firstnames[i]) * (i+1));
		printf("score: %ld\n", score);
		sum += score;
		++i;
	}
	
	printf("The total sum of name scores: %ld\n", sum);
	return 0;
}
