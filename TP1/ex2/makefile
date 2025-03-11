CFLAGS=-std=c17 -pedantic -Wall -Wvla -Werror -D_DEFAULT_SOURCE

lireEtEcrire: lireEtEcrire.o utils_v1.o
	gcc $(CFLAGS) -o lireEtEcrire lireEtEcrire.o utils_v1.o

lireEtEcrire.o: lireEtEcrire.c ../utils_v1.h
	gcc $(CFLAGS) -c lireEtEcrire.c

utils_v1.o: ../utils_v1.c ../utils_v1.h
	gcc $(CFLAGS) -c ../utils_v1.c

clean:
	rm -f *.o
	rm -f lireEtEcrire test

test: lire
	../lastrace.sh ../lireEtEcrire