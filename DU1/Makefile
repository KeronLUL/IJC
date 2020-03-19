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
		$(CC) $(CFLAGS) primes.o eratosthenes.o error.o -o primes -lm

primes-i: primes-i.o eratosthenes-i.o error.o bitset-i.o
		$(CC) $(CFLAGS) primes-i.o eratosthenes-i.o bitset-i.o error.o -o primes-i -lm

steg-decode: steg-decode.o eratosthenes.o error.o ppm.o
		$(CC) $(CFLAGS) steg-decode.o eratosthenes.o error.o ppm.o -o steg-decode -lm

%-i.o: %.c
	$(CC) $(CFLAGS) -DUSE_INLINE -c -o $@ $< $(LDFLAGS)

clean:
	rm -f primes primes-i steg-decode *.o

zip:
	zip xnorek01.zip *.h *.c Makefile
