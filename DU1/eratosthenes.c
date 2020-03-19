// eratosthenes.c
// IJC-DU1, 18.3.2020
// Karel Norek, xnorek01
// FIT VUT
// gcc 7.4

#include <math.h>
#include <string.h>
#include "eratosthenes.h"

void Eratosthenes(bitset_t pole) {
    bitset_setbit(pole, 0, 1);
    bitset_setbit(pole, 1, 1);
    bitset_index_t max = sqrt(pole[0]);

    memset(&(pole[1]), 0x55, pole[0] / CHAR_BIT + 1);

    for (bitset_index_t i = 3; i < max; i++) {
        if (!(bitset_getbit(pole, i))) {
            for (bitset_index_t j = i * i; j < pole[0]; j += 2 * i) {
                bitset_setbit(pole, j, 1);
            }
        }
    }
}