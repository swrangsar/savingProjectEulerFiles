#ifndef CURIOUSFRACTION_H
#define CURIOUSFRACTION_H

#include "fraction.h"

typedef struct curiousFraction {
	char a;
	char b;
	char c;
} curiousFraction;

curiousFraction *createCuriousFraction(char a, char b, char c);
void destroyCuriousFraction(curiousFraction *input);
int isCuriousFraction(curiousFraction *input);
fraction *curiousToFraction(curiousFraction* input);
void showCuriousFraction(curiousFraction *input);

#endif