all: test

test: test.cpp llistint.o
	g++ -g -Wall llistint.o test.cpp -o test
llistint.o: ../llistint.h ../llistint.cpp
	g++ -g -Wall -c ../llistint.cpp -o llistint.o
clean:
	rm llistint.o test   
