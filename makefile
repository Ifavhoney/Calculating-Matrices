P11:  P11.o
	gcc P11.o -o P11

P11.o: P11.c
	gcc -c P11.c -o P11.o

P12:  P12.o
	gcc P12.o -o P12

P12.o: P12.c
	gcc -c P12.c -o P12.o

P21:  P21.o
	gcc P21.o -o P21

P21.o: P21.c
	gcc -c P21.c -o P21.o

P22:  P22.o
	gcc P22.o -o P22

P22.o: P22.c
	gcc -c P22.c -o P22.o

P23:  P23.o
	gcc P23.o -o P23

P23.o: P23.c
	gcc -c P23.c -o P23.o
clean:
	rm *.o
	rm  P11 P12 P22 P21 P23