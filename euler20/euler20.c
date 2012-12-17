#include <stdio.h>
#include "bignum.h"

#define MAXNUM 100

int main()
{
	char sum[LIMIT];
	*sum = '\0';
	int i;
	i = 0;
	while (++i <= MAXNUM) {
		product(sum, i);
		show(sum);
	}
	
	getsum(sum);
	return 0;
}