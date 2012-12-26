#ifndef FRACTION_H
#define FRACTION_H

typedef struct fraction {
	int numerator;
	int denominator;
} fraction;

fraction *createFraction(int a, int b);
void destroyFraction(fraction *input);
void multiplyFractions(fraction *a, fraction *b);
void showFraction(fraction *input);
void reduceFraction(fraction *input);
int isEqualFraction(fraction *a, fraction *b);

#endif