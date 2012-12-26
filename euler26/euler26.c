#include <stdio.h>
#include "unitFraction.h"
#define LIMIT	1000

int main()
{
	int maxlength, maxnatural, i, length;
	maxlength = maxnatural = i = 0;
	printf("%4d: 1.0\n", 1);
	i++;
	
	while (++i <= LIMIT) {
		if ((length = getRecurringLength(i)) > maxlength) {
			maxlength = length;
			maxnatural = i;
		}
	}
	
	printf("The number with max recurring length is: %d\nwith length: %d\n", maxnatural, maxlength);
	getRecurringLength(maxnatural);
	
	return 0;
}