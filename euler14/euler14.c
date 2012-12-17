#include <stdio.h>
#define LIMIT 1000000

long sequenceLength(long natural);

int main()
{
	int natural, maxNatural;
	long length, maxLength;
	natural = maxNatural = 0;
	length = maxLength = 0;
	
	while (++natural < LIMIT) {
		if ((length = sequenceLength((long)natural)) > maxLength) {
			maxLength = length;
			maxNatural = natural;
		}
		printf("Natural: %d\n", natural);
		printf("Length: %ld\n", length);
		printf("Max length: %ld\n", maxLength);
	}
	
	printf("The number with max length is: %d\n", maxNatural);
	printf("Its length: %ld\n", maxLength);
	
	return 0;
}


long sequenceLength(long natural)
{
	long length;
	length = 1;
	while (natural != 1) {
		if (natural & 1) {
			natural = (natural * 3) + 1;
		} else {
			natural /= 2;
		}
		++length;
	}
	return length;
}