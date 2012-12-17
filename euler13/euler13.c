#include <stdio.h>
#include <ctype.h>
#define MAX 1000
#define LIMIT 50

void reverse(char *s);
int getNumber(char *s);
void updateSum(char *sum, char *number);

int main()
{
	char sum[MAX];
	char number[LIMIT+1];
	*sum = '\0';
	int count;
	count = 0;
	while (getNumber(number)) {
		updateSum(sum, number);
		count++;
	}
	printf("Reversed sum: %s\n", sum);
	reverse(sum);
	printf("Sum: %s\n", sum);
	printf("First ten digits of sum: ");
	int i;
	i = 0;
	while (i < 10) {
		putchar(sum[i++]);
	}
	putchar('\n');
	printf("Count: %d\n", count);
	
	return 0;
}

void reverse(char *s)
{
	char *t, temp;
	t = s;
	while (*t)
		++t;
	--t;
	while (s < t) {
		temp = *s;
		*s = *t;
		*t = temp;
		++s;
		--t;
	}
}

int getNumber(char *s)
{
	int c, i;
	i = 0;
	while (i < LIMIT && (c = getchar()) != EOF) {
		if (isdigit(c)) {
			s[i++] = c;
		}
	}
	s[i] = '\0';
	printf("got number: %s\n", s);
	reverse(s);
	printf("got revnum: %s\n", s);
	if (c == EOF)
		return 0;
	else 
		return 1;
}

void updateSum(char *sum, char *number)
{
	if (!*sum) {
		int i = 0;
		while (number[i]) {
			sum[i] = number[i];
			++i;
		}
		sum[i] = '\0';	
	} else {
		int i, carry, temp;
		i = carry = 0;
		while (i < LIMIT) {
			if ((temp = sum[i]-'0'+number[i]-'0' + carry) < 10) {
				sum[i] = temp + '0';
				carry = 0;
			} else {
				sum[i] = '0'+temp-10;
				carry = 1;
			}
			++i;
		}
		if (carry) {
			while (sum[i] != '\0') {
				if ((temp = sum[i]- '0' + carry) < 10) {
					sum[i] = temp + '0';
					carry = 0;
				} else {
					sum[i] = temp-10 + '0';
					carry = 1;
				}
				++i;
			}
			if (carry) {
				sum[i++] = carry + '0';
				sum[i] = '\0';
			}
		}
	}
	printf("update sum: %s\n\n", sum);
}