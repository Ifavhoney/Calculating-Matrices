all: main.o text.o
	gcc -Wall -ansi -pedantic main.o text.o -o gccApp

main.o: main.c
	gcc -Wall -ansi -pedantic main.c -c -o main.o

text.o: text.c
	gcc -Wall -ansi -pedantic text.c -c -o text.o

clean:
	rm *.o
	rm gccApp