CFLAGS = -Wall -g -DNDEBUG

all: euler67
readTriangle.o: readTriangle.h
sumTriangle.o: sumTriangle.h
euler67: readTriangle.o sumTriangle.o euler67.o

clean:
	rm -f readTriangle.o sumTriangle.o euler67.o euler67