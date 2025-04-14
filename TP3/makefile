CFLAGS=-std=c11 -pedantic -Wall -Wvla -Werror -D_DEFAULT_SOURCE

PROGS= ex3a ex3b

all: $(PROGS)

ex3a: ex3a.o
	gcc $(CFLAGS) -o ex3a ex3a.o

ex3a.o: ex3a.c
	gcc $(CFLAGS) -c ex3a.c

ex3b: ex3b.o
	gcc $(CFLAGS) -o ex3b ex3b.o

ex3b.o: ex3b.c
	gcc $(CFLAGS) -c ex3b.c

utils_v1.o: ../utils_v1.c ../utils_v1.h
	gcc $(CFLAGS) -c ../utils_v1.c

clean:
	rm -f *.o
	rm -f $(PROGS)
