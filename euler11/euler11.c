#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int getNumber(void);
int buildNumberArray(int numbers[][20]);


int main()
{
	int numbers[20][20];
	if (!buildNumberArray(numbers)) {
		printf("Error: couldn't build array!\n");
		return 1;
	}
	int max, i, j, temp;
	max = i = j = 0;
	
	/* the horizontal */
	while (i < 20) {
		j = 0;
		while ((j+3) < 20) {
			if ((temp = (numbers[i][j]*numbers[i][j+1]*numbers[i][j+2]*numbers[i][j+3])) > max)
				max = temp;
			++j;
		}
		++i;
	}
	
	/* the vertical */
	i = 0;
	while ((i+3) < 20) {
		j = 0;
		while (j < 20) {
			if ((temp = numbers[i][j]*numbers[i+1][j]*numbers[i+2][j]*numbers[i+3][j]) > max)
				max = temp;
			++j;
		}
		++i;
	}
	
	/* diagonal topleft to bottomright */
	i = 0;
	while ((i+3) < 20) {
		j = 0;
		while ((j+3) < 20) {
			if ((temp = numbers[i][j]*numbers[i+1][j+1]*numbers[i+2][j+2]*numbers[i+3][j+3]) > max)
				max = temp;
			++j;
		}
		++i;
	}
	
	/* diagonal bottomleft to topright */
	i = 19;
	while ((i-3) >= 0) {
		j = 0;
		while ((j+3) < 20) {
			if ((temp = numbers[i][j]*numbers[i-1][j+1]*numbers[i-2][j+2]*numbers[i-3][j+3]) > max)
				max = temp;
			++j;
		}
		--i;
	}
	
	printf("The maximum product is: %d\n", max);
	return 0;
}

/* get 2-digit number */
int getNumber(void)
{
	int c, i;
	char number[3];
	i = 0;
	while (i < 2 && (c = getchar()) != EOF) {
		if (isdigit(c))
			number[i++] = c;  
	}
	number[i] = '\0';
	
	return atoi(number);
}


int buildNumberArray(int numbers[][20])
{
	int i, j;
	i = j = 0;
	while (i < 20) {
		j = 0;
		while (j < 20) {
			numbers[i][j++] = getNumber();
		}
		++i;
	}
	if(j == 20 && i == 20)
		return 1;
	else
		return 0;
}