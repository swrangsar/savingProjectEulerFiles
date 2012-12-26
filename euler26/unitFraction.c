#include <stdio.h>
#include <stdlib.h>
#include "unitFraction.h"

#define checkMemory(A, M)	{if (!A) {printf("ERROR: " M "\n"); exit(EXIT_FAILURE);}}


static int *createData(int number);
static void destroyData(int *number);
static int found(list *remainders, int number, int *length);

static int *createData(int number)
{
	int *new = malloc(sizeof(int));
	checkMemory(new, "Int could not be allocated!");
	*new = number;
	return new;
}

static void destroyData(int *number)
{
	if (number) free(number);
}

static int found(list *remainders, int number, int *length)
{
	node *conductor = remainders->head;
	*length = 0;
	while (conductor) {
		++*length;
		if (number == *(int *)(conductor->data)) {
			return 1;
		}
		conductor = conductor->next;
	}
	return 0;
}

int getRecurringLength(int natural)
{
	list *remainders = createList((void *)destroyData);
	int dividend = 1;
	int quotient = 0;
	int length = 0;
	
	printf("%4d: 0.", natural);
	do {
		enlist(remainders, createData(dividend));
		dividend *= 10;
		quotient = (dividend < natural)?0:(dividend/natural);
		dividend %= natural;
		putchar(quotient + '0');
	} while (!found(remainders, dividend, &length) && dividend);
	
	destroyList(remainders);
	if (dividend) {
		printf("R\tlength: %d\n", length);
		return length;
	}
	printf("\tlength: 0\n");
	return 0;
}