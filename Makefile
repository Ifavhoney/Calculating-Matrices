all: text.o main.o
	gcc main.o text.o -o main

main.o: main.c
	gcc -Wall -ansi -pedantic main.c -c -o main.o

text.o: text.c
	gcc -Wall -ansi -pedantic -c text.c -o text.o

clean:
	rm *.o
	rm main