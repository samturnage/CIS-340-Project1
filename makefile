cc = gcc
cc_flags = -std=gnu99 -c -g -Wall -I

all: main

main: main.o node.o
	$(cc) main.o node.o -o main

main.o: main.c
	$(cc) $(cc_flags) main.c 

node.o: node.c
	$(cc) $(cc_flags) node.c 

clean:
	$(RM) *.o main
