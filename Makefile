all: common.o binary.o name.o title.o principals.o a3.o
	gcc a3.o principals.o title.o name.o binary.o common.o -o a3

a3.o: a3.c
	gcc -Wall -ansi -pedantic a3.c -c -o a3.o

principals.o: principals.c
	gcc -Wall -ansi -pedantic -c principals.c -o principals.o

title.o: title.c
	gcc -Wall -ansi -pedantic -c title.c -o title.o

name.o: name.c
	gcc -Wall -ansi -pedantic -c name.c -o name.o

binary.o: binary.c
	gcc -Wall -ansi -pedantic -c binary.c -o binary.o

common.o: common.c
	gcc -Wall -ansi -pedantic -c common.c -o common.o

clean:
	rm *.o
	rm a3