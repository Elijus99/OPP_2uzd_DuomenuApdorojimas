CXX = clang++
CC = clang

all:	main

test:	all
	./main

clean:
	rm -f *.o main
