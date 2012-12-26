#include <stdio.h>
#include "pandigital.h"

#define START 123456789
#define LIMIT	987654321
#define STEP 9
#define INTCOUNT 100

void initializeProducts(int products[]);
void saveProduct(int products[], int *position, int product);

int main()
{
	int i = START;
	int products[INTCOUNT];
	int counter;
	long sum = 0;
	counter = 0;
	
	while (i <= LIMIT) {
		if (isPandigital(i) && hasPandigitalProduct(i)) {
			saveProduct(products, &counter, pandigitalProduct(i));
		}
		i += STEP;
	}
	
	i = 0;
	while (i < counter) {
		sum += products[i];
		printf("product: %d sum: %ld\n", products[i], sum);
		++i;
	}
	
	printf("The required sum is: %ld\n", sum);
	
	return 0;
}

void initializeProducts(int products[])
{
	int i = 0;
	while (i < INTCOUNT) {
		products[i++] = 0;
	}
}

void saveProduct(int products[], int *position, int product)
{
	int i = 0;
	while (i < INTCOUNT && i < *position) {
		if (products[i++] == product) return;
	}
	products[(*position)++] = product;
}
	
