CFLAGS=-std=c17 -pedantic -Wall -Wvla -Werror -D_DEFAULT_SOURCE

PROGS= a b c

all: $(PROGS)

a: a.o utils_v2.o
	gcc $(CFLAGS) -o a a.o utils_v2.o

a.o: a.c ../utils_v2.h
	gcc $(CFLAGS) -c a.c

b: b.o utils_v2.o
	gcc $(CFLAGS) -o b b.o utils_v2.o

b.o: b.c ../utils_v2.h
	gcc $(CFLAGS) -c b.c

c: c.o utils_v2.o
	gcc $(CFLAGS) -o c c.o utils_v2.o
	
c.o: c.c ../utils_v2.h
	gcc $(CFLAGS) -c c.c

utils_v2.o: ../utils_v2.c ../utils_v2.h
	gcc $(CFLAGS) -c ../utils_v2.c

clean:
	rm -f *.o
	rm -f $(PROGS)