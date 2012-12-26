#include <stdio.h>

#define TARGET 200

int main()
{
	int one, two, five, ten;
	int twenty, fifty, hundred, twohundred;
	int money, count;

	count = 0;
	twohundred = 2;
	while (--twohundred >= 0) {
		if ((twohundred * 200) == 200) {
			++count;
			printf("count: %7d twopound: %d\n", count, twohundred);
			continue;
		}
		hundred = 3;
		while (--hundred >= 0) {
			money = (twohundred * 200 + hundred * 100);
			if (money == 200) {
				++count;
				printf("count: %7d twopound: %d pound: %d\n", count, twohundred, hundred);
				continue;
			}
			fifty = 5;
			while (--fifty >= 0) {
				money = (twohundred*200 + hundred*100 + fifty*50);
				if (money == 200) {
					++count;
					printf("count: %7d twopound: %d pound: %d fifty: %d\n", count, twohundred, hundred, fifty);
					continue;
				}
				twenty = 11;
				while (--twenty >= 0) {
					money = (twohundred*200 + hundred*100 + fifty*50 + twenty*20);
					if (money == 200) {
						++count;
						printf("count: %7d twopound: %d pound: %d fifty: %d twenty: %d\n", count, twohundred, hundred, fifty, twenty);
						continue;
					}
					ten = 21;
					while (--ten >= 0) {
						money = (twohundred*200 + hundred*100 + fifty*50 + twenty*20 + ten*10);
						if (money == 200) {
							++count;
							printf("count: %7d twopound: %d pound: %d ", count, twohundred, hundred);
							printf("fifty: %d twenty: %d ten: %d\n", fifty, twenty, ten);
							continue;
						}
						five = 41;
						while (--five >= 0) {
							money = (twohundred*200 + hundred*100 + fifty*50 + twenty*20 + ten*10 + five*5);
							if (money == 200) {
								++count;
								printf("count: %7d twopound: %d pound: %d ", count, twohundred, hundred);
								printf("fifty: %d twenty: %d ten: %d ", fifty, twenty, ten);
								printf("five: %d\n", five);
								continue;
							}
							two = 101;
							while (--two >= 0) {
								money = (twohundred*200 + hundred*100 + fifty*50 + twenty*20 + ten*10 + five*5 + two*2);
								if (money == 200) {
									++count;
									printf("count: %7d twopound: %d pound: %d ", count, twohundred, hundred);
									printf("fifty: %d twenty: %d ten: %d ", fifty, twenty, ten);
									printf("five: %d two: %d\n", five, two);
									continue;	
								}
								one = 201;
								while (--one >= 0) {
									money = (twohundred*200 + hundred*100 + fifty*50 + twenty*20 + ten*10 + five*5 + two*2 + one);
									if (money == 200) {
										++count;
										printf("count: %7d twopound: %d pound: %d ", count, twohundred, hundred);
										printf("fifty: %d twenty: %d ten: %d ", fifty, twenty, ten);
										printf("five: %d two: %d one: %d\n", five, two, one);
										break;		
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	printf("The number of combinations is: %d\n", count);
	return 0;
}