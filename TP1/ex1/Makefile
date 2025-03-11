CFLAGS=-std=c17 -pedantic -Wall -Wvla -Werror -D_DEFAULT_SOURCE

lire: lire.o utils_v1.o
	gcc $(CFLAGS) -o lire lire.o utils_v1.o

lire.o: lire.c ../utils_v1.h
	gcc $(CFLAGS) -c lire.c

utils_v1.o: ../utils_v1.c ../utils_v1.h
	gcc $(CFLAGS) -c ../utils_v1.c

clean:
	rm -f *.o
	rm -f lire test

test: lire
	./lastrace.sh ./lire