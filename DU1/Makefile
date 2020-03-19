# Makefile
# IJC-DU1, 18.3.2020
# Karel Norek, xnorek01
# FIT VUT
# gcc 7.4

CC=gcc
CFLAGS=-O2 -g -std=c11 -Wall -Wextra -pedantic
LDFLAGS=-lm

all: primes primes-i steg-decode

run: primes primes-i
	ulimit -s 65000 && ./primes
	ulimit -s 65000 && ./primes-i

primes: primes.o eratosthenes.o error.o
	$(CC) $(CFLAGS) primes.o eratosthenes.o error.o -o primes $(LDFLAGS)

primes-i: primes-i.o eratosthenes-i.o error.o bitset-i.o
	$(CC) $(CFLAGS) primes-i.o eratosthenes-i.o bitset-i.o error.o -o primes-i $(LDFLAGS)

steg-decode: steg-decode.o eratosthenes.o error.o ppm.o
	$(CC) $(CFLAGS) steg-decode.o eratosthenes.o error.o ppm.o -o steg-decode $(LDFLAGS)

#primes
primes.o: primes.c eratosthenes.h bitset.h error.h
	$(CC) $(CFLAGS) -c primes.c -o primes.o

eratosthenes.o: eratosthenes.c eratosthenes.h bitset.h error.h
	$(CC) $(CFLAGS) -c eratosthenes.c -o eratosthenes.o

#primes-i (USE_INLINE)
primes-i.o: primes.c eratosthenes.h bitset.h error.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c primes.c -o primes-i.o

eratosthenes-i.o: eratosthenes.c eratosthenes.h bitset.h error.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c eratosthenes.c -o eratosthenes-i.o

bitset-i.o: bitset.c bitset.h error.h
	$(CC) $(CFLAGS) -DUSE_INLINE -c bitset.c -o bitset-i.o

#steg-decode
steg-decode.o: steg-decode.c bitset.h error.h ppm.h eratosthenes.h
	$(CC) $(CFLAGS) -c steg-decode.c -o steg-decode.o

ppm.o: ppm.c ppm.h
	$(CC) $(CFLAGS) -c ppm.c -o ppm.o

#error
error.o: error.c error.h
	$(CC) $(CFLAGS) -c error.c -o error.o

clean:
	rm -f primes primes-i steg-decode *.o

zip:
	zip xnorek01.zip *.h *.c Makefile
