CFLAGS = -Wall -g -DNDEBUG

all: euler18
readTriangle.o: readTriangle.h
sumTriangle.o: sumTriangle.h
euler18: readTriangle.o sumTriangle.o euler18.o

clean:
	rm -f readTriangle.o sumTriangle.o euler18.o euler18