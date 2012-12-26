CFLAGS = -Wall -g -DNDEBUG

all: euler33
prime.o: prime.h
fraction.o: fraction.h
curiousFraction.o: curiousFraction.h
euler33: prime.o fraction.o curiousFraction.o euler33.o
clean:
	rm -f euler33 prime.o fraction.o curiousFraction.o euler33.o
