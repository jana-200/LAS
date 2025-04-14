CFLAGS=-std=c11 -pedantic -Wall -Wvla -Werror -D_DEFAULT_SOURCE

PROGS= a b d e

all: $(PROGS)

a: a.o 
	gcc $(CFLAGS) -o a a.o

a.o: a.c
	gcc $(CFLAGS) -c a.c

b: b.o 
	gcc $(CFLAGS) -o b b.o

b.o: b.c
	gcc $(CFLAGS) -c b.c

d: d.o 
	gcc $(CFLAGS) -o d d.o

d.o: d.c
	gcc $(CFLAGS) -c d.c

e: e.o 
	gcc $(CFLAGS) -o e e.o

e.o: e.c
	gcc $(CFLAGS) -c e.c

clean:
	rm -f *.o
	rm -f $(PROGS)
