#include <stdio.h>
#include <string.h>
#include "sortFirstNames.h"

static void swap(char *names[], i, j)
{
	char *temp;
	temp = names[i];
	names[i] = names[j];
	names[j] = temp;
}

void sortFirstNames(char *names[], int left, int right)
{
	/* using quicksort algorithm */
	int i, divider;
	
	if (left >= right) return;
	swap(names, left, ((left+right)/2));
	divider = left;
	i = left;
	while (++i <= right) {
		if (strcmp(names[i], names[left]) < 0)
			swap(names, ++divider, i);		
	}
	swap(names, left, divider);
	sortFirstNames(names, left, divider-1);
	sortFirstNames(names, divider+1, right);
}

void showFirstNames(char *names[])
{
	int i;
	i = 0;
	printf("... printing first names ...");
	while (names[i]) 
		printf("%s\n", names[i++]);
	printf("... printing job done :) ...");
}

int alphaValue(char name[])
{
	int sum, i;
	sum = i = 0;
	while (name[i])
		sum += (name[i++]-'A') + 1;
	return sum;
}
	