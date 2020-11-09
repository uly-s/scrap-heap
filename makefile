all: oucat.c ouecho.c ouhead.c outail.c ouseq.c ouwc.c
	gcc -o oucat oucat.c
	gcc -o ouecho ouecho.c
	gcc -o ouhead ouhead.c
	gcc -o outail outail.c
	gcc -o ouseq ouseq.c -lm
	gcc -o ouwc ouwc.c

oucat:
	gcc -o oucat oucat.c

ouecho:
	gcc -o ouecho ouecho.c

ouhead:
	gcc -o ouhead ouhead.c

outail:
	gcc -o outail outail.c

ouseq:
	gcc -o ouseq ouseq.c -lm

ouwc:
	gcc -o ouwc ouwc.c

clean:
	-rm *.o oucat ouecho ouhead outail ouseq ouwc
