#include <stdio.h>
#include <stdlib.h>
#include "curiousFraction.h"
#define BASE 10


curiousFraction *createCuriousFraction(char a, char b, char c)
{
	curiousFraction *new = malloc(sizeof(curiousFraction));
	if (!new) {
		printf("Curious fraction could not be allocated.\n");
		exit(EXIT_FAILURE);
	}
	new->a = a;
	new->b = b;
	new->c = c;
	return new;
}

void destroyCuriousFraction(curiousFraction *input)
{
	if (input) free(input);
}

int isCuriousFraction(curiousFraction *input)
{
	int flag = 0;
	fraction *raw = createFraction(((input->a*BASE) + input->b), ((input->b*BASE) + input->c));
	fraction *cancelled = createFraction(input->a, input->c);
	flag = isEqualFraction(raw, cancelled);
	destroyFraction(raw);
	destroyFraction(cancelled);
	return flag;
}

fraction *curiousToFraction(curiousFraction* input)
{
	fraction *new = createFraction(input->a, input->c);
	reduceFraction(new);
	return new;
}

void showCuriousFraction(curiousFraction *input)
{
	printf("curious fraction: %d%d/%d%d\n", input->a, input->b, input->b, input->c);
}