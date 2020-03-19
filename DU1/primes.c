// primes.c
// IJC-DU1, 18.3.2020
// Karel Norek, xnorek01
// FIT VUT
// gcc 7.4

#include <stdio.h>
#include <time.h>
#include "eratosthenes.h"
#include "bitset.h"

#define SIEVE 500000001

void print_primes(bitset_t pole){
    bitset_index_t primes = 10;
    bitset_index_t N = bitset_size(pole);
    unsigned long array[10];

    for (bitset_index_t i = N - 1; primes > 0; i--) {
        if (!(bitset_getbit(pole, i))) {
            array[primes - 1] = i;
            primes--;
        }
    }
    for (int j = 0; j < 10; j++) {
        printf("%lu\n", array[j]);
    }
}

int main() {
    clock_t start = clock();
    bitset_create(pole, SIEVE);
    Eratosthenes(pole);
    print_primes(pole);
    fprintf(stderr, "Time=%.3g\n", (double)(clock()-start)/CLOCKS_PER_SEC);
    return 0;
}
