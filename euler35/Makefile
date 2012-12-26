CFLAGS=-Wall -g -DNDEBUG

all: euler35
prime.o: prime.h
circularPrime.o: circularPrime.h
euler35: prime.o circularPrime.o euler35.o
clean:
	rm -f euler35 prime.o circularPrime.o euler35.o
