CFLAGS=-Wall -g -DNDEBUG

all: euler37
prime.o: prime.h
truncatablePrime.o: truncatablePrime.h dbg.h
euler37: prime.o truncatablePrime.o euler37.o
clean:
	rm -f euler37 prime.o truncatablePrime.o euler37.o