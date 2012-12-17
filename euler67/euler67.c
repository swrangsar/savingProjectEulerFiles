#include <stdio.h>
#include "readTriangle.h"
#include "sumTriangle.h"

#define ROWS 100

int main()
{
	long triangle[(ROWS * (ROWS+1))/2];
	
	printf("\n\nprogram started...\n");
	readtriangle(triangle, ROWS);
	printtriangle(triangle, ROWS);
	sumtriangle(triangle, ROWS);
	printtriangle(triangle, ROWS);
	
	printf("*** RESULTS ***\n");
	printf("The largest sum is: %ld\n", triangle[0]);
	return 0;
}