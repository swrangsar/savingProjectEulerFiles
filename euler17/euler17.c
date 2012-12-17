#include <stdio.h>
#define LIMIT 1000

int wordlength(int natural);

int main()
{
	long sum;
	int i;
	i = 0;
	sum = 0;
	while (++i <= LIMIT) {
		printf("%d\n", wordlength(i));
		sum += (long) wordlength(i);
		if (!(i%10)) {
			printf("--- br ---\n");
		}
	}
	
	printf("The sum is: %ld\n", sum);
	return 0;	
}

int wordlength(int natural)
{
	char *ones = "335443554";
	char *tens = "366555766";
	char *teens = "668877988";
	int temp, length;
	temp = natural;
	length = 0;
	
	if ((temp % 10)) {
		length += ones[(temp%10)-1] - '0';
	}
	temp /= 10;
	
	if (temp%10 > 1) {
		length += tens[(temp%10)-1] - '0';
	} else if (temp%10 == 1) {
		if (natural%10) {
			length = teens[(natural%10)-1] - '0';
		} else {
			length = tens[(natural%10)] - '0';
		}
	} else {
		/* do nothing */
	}
	temp /= 10;
	
	if (temp%10) {
		if (length)
			length += 3; /* and */
		length += ones[(temp%10)-1]-'0';
		length += 7; /* hundred */
	}
	temp /= 10;
	if (temp == 1) {
		length = 11;
	}
	return length;	
}