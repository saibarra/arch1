
all: ACME


clean: 
	rm -rf *.o *~ *# ACME_DEMO


ACME: input
	gcc ACME.o -o ACME_DEMO

input: 
	gcc -c ACME.c
