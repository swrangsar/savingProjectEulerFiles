#include <stdio.h>
#define LIMIT 20

void initialize(long numArray[]);
void accumulate(long sumArray[], long numArray[]);
void show(long array[]);


int main()
{
	long numArray[LIMIT+1];
	long sumArray[LIMIT+1];
	initialize(numArray);
	
	int i;
	i = 0;
	while (i < LIMIT-1) {
		printf("--- Accumulation %d start ---\n", i+1);
		accumulate(sumArray, numArray);
		printf("--- Accumulation %d end ---\n", i+1);
		++i;
	}
	
	/* summing up sumArray */
	printf("...summing up sumArray...\n");
	long sum;
	i = 0;
	sum = 0;
	while (i <= LIMIT) {
		sum += sumArray[i++];
	}
	
	printf("The total no. of paths: %ld\n", sum);
	return 0;
}

void initialize(long numArray[])
{
	int i;
	i = 0;
	while (i <= LIMIT)
		numArray[i++] = 1;
	show(numArray);
	return;
}

void accumulate(long sumArray[], long numArray[])
{
	long sum;
	int i;
	sum = 0;
	i = 0;
	
	while (i <= LIMIT) {
		sum += numArray[i];
		sumArray[i++] = sum;
	}
	show(sumArray);
	/* copy sum to num */
	i = 0;
	while (i <= LIMIT) {
		numArray[i] = sumArray[i];
		++i;
	}
	/* show(numArray); */
}

void show(long array[])
{
	int i;
	i = 0;
	while (i <= LIMIT) {
		printf("(%2d) %ld\n", i+1, array[i]);
		++i;
	}
}