CFLAGS=-std=c11 -pedantic -Wall -Wvla -Werror -D_DEFAULT_SOURCE

PROGS= a

all: $(PROGS)

a: a.o utils_v1.o
	gcc $(CFLAGS) -o a a.o utils_v1.o

a.o: a.c ../utils_v1.h
	gcc $(CFLAGS) -c a.c


utils_v1.o: ../utils_v1.c ../utils_v1.h
	gcc $(CFLAGS) -c ../utils_v1.c

clean:
	rm -f *.o
	rm -f $(PROGS)
