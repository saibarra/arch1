<<<<<<< HEAD
all: ACME


clean: 
	rm -rf *.o *~ *#


ACME: input
	gcc ACME.o -o ACME_DEMO

input: 
	gcc -c ACME.c



=======
all: llDemo

CFLAGS=-g -O3

# Symbols helpful for understanding the productions
#   $@ is the production's target
#   $^ are the production's prerequisites

llDemo: llist.o llDemo.o
	cc -o $@ $^

llist.o: llist.c llist.h
	cc -c $(CFLAGS) llist.c

llDemo.o: llDemo.c llist.h
	cc -c $(CFLAGS) llDemo.c

clean:
	rm -f *.o llDemo

demo: llDemo
	(echo first; echo "second line"; echo "third and last") | ./llDemo
>>>>>>> d58520ead87ea0b7ca9c4906255cb646873c6f32

