all:  a4.o
	gcc -g a4.o -o a4

a4.o: a4.c
	gcc -Wall -ansi -g -pedantic a4.c -c -o a4.o

clean:
	rm *.o
	rm a4
