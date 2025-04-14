CC=gcc

CCFLAGS=-std=c17 -pedantic -Wall -Wvla -Werror -Wno-unused-variable -D_DEFAULT_SOURCE

client : client.o utils_v2.o
	$(CC) $(CCFLAGS) -o client client.o utils_v2.o
client.o: client.c
	$(CC) $(CCFLAGS) -c client.c

utils_v2.o: ../utils_v2.c ../utils_v2.h
	$(CC) $(CCFLAGS) -c ../utils_v2.c

clean:
	rm -f *.o
	rm -f client		