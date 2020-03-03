P11:  P11.o
	gcc P11.o -o P11

P11.o: P11.c
	gcc -c P11.c -o P11.o

a2: a2.c
	gcc  -c a2.c -o a2

clean:
	rm *.o
	rm main