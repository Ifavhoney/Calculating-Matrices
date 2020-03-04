P11:  P11.o
	gcc P11.o -o P11

P11.o: P11.c
	gcc -c P11.c -o P11.o

P12:  P12.o
	gcc P12.o -o P12

P12.o: P12.c
	gcc -c P12.c -o P12.o

clean:
	rm *.o
	rm  P11 P12