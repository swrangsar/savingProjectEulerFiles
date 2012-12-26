#include <stdio.h>
#include "curiousFraction.h"

#define BASE 10

int main()
{
	char i, j, k;
	fraction *product;
	i = j = k = 1;
	product = createFraction(1, 1);
	printf("Product ");
	showFraction(product);
	
	while (++j < BASE) {
		i = 0;
		while (++i < j) {
			k = i;
			while (++k < BASE) {
				curiousFraction *tempCurious = createCuriousFraction(i, j, k);
				if (isCuriousFraction(tempCurious)) {
					showCuriousFraction(tempCurious);
					fraction *tempFraction = curiousToFraction(tempCurious);
					showFraction(tempFraction);
					multiplyFractions(product, tempFraction);
					printf("Product ");
					showFraction(product);
				}
				destroyCuriousFraction(tempCurious);
			}
		}
	}
	
	printf("The reduced product: ");
	reduceFraction(product);
	showFraction(product);
	printf("The reqd denominator: %d\n", product->denominator);
	destroyFraction(product);
	
	return 0;
}