all: a2 main.o
	gcc main.o a2 -o main

main.o: main.c
	gcc -c main.c -o main.o

a2: a2.c
	gcc  -c a2.c -o a2

clean:
	rm *.o
	rm main