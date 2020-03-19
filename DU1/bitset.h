// bitset.h
// IJC-DU1, 18.3.2020
// Karel Norek, xnorek01
// FIT VUT
// gcc 7.4

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include "error.h"

#ifndef BITSET_H
#define BITSET_H

#define BITSIZE_UL (sizeof(bitset_index_t) * CHAR_BIT)

typedef unsigned long bitset_index_t;
typedef bitset_index_t *bitset_t;

/**
 * Create bit array using stack size
 */
#define bitset_create(jmeno_pole, velikost)\
    bitset_index_t jmeno_pole[velikost / BITSIZE_UL + ((velikost % BITSIZE_UL) ? 1 : 0) + 1] = {velikost, 0};\
    static_assert(velikost > 0, "Velikost pole musi byt vetsi nez 0\n");\

/**
 * Create bit array using alloc
 */
#define bitset_alloc(jmeno_pole, velikost)\
    assert(velikost > 0);\
    bitset_index_t *jmeno_pole = calloc(velikost / BITSIZE_UL + ((velikost % BITSIZE_UL) ? 1 : 0) + 1, sizeof(bitset_index_t));\
    if (jmeno_pole == NULL) error_exit("bitset_alloc: Chyba alokace pameti\n");\
    else jmeno_pole[0] = velikost;\

#ifndef USE_INLINE

/**
 * Free allocated bit array
 */
#define bitset_free(jmeno_pole) free(jmeno_pole)

/**
 * Return size of bit array
 */
#define bitset_size(jmeno_pole) (bitset_index_t)jmeno_pole[0]

/**
 * Set bit to 1 or 0 depending on parameter "vyraz"
 */
#define bitset_setbit(jmeno_pole, index, vyraz)\
    if (index >= bitset_size(jmeno_pole)) error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, bitset_size(jmeno_pole));\
    (vyraz != 0) ?  (jmeno_pole[index / BITSIZE_UL  + 1] |= 1UL << (index % BITSIZE_UL)) :\
                    (jmeno_pole[index / BITSIZE_UL + 1] &= ~(1UL << (index % BITSIZE_UL)))\

/**
 * Get bit on index stored in bit array
 */
#define bitset_getbit(jmeno_pole, index)\
    (index >= bitset_size(jmeno_pole)) ?\
    (error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, bitset_size(jmeno_pole) - 1), 0):\
    (bitset_index_t) ((jmeno_pole[index / BITSIZE_UL + 1] & (1UL << (index % BITSIZE_UL))) != 0)

#else

inline void bitset_free(bitset_t jmeno_pole) {
    free(jmeno_pole);
}

inline unsigned long bitset_size(bitset_t jmeno_pole) {
    return jmeno_pole[0];
}

inline void bitset_setbit(bitset_t jmeno_pole, const bitset_index_t index, const int vyraz) {
    if (index >= bitset_size(jmeno_pole)) {
        error_exit("bitset_setbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, bitset_size(jmeno_pole));
    }
    if (vyraz) {
        jmeno_pole[index / BITSIZE_UL + 1] |= 1UL << (index % BITSIZE_UL);
    }
    else jmeno_pole[index / BITSIZE_UL + 1] &= ~(1UL << (index % BITSIZE_UL));
}

inline unsigned long bitset_getbit(bitset_t jmeno_pole, const bitset_index_t index) {
    if (index >= bitset_size(jmeno_pole)) {
        error_exit("bitset_getbit: Index %lu mimo rozsah 0..%lu\n", (unsigned long)index, bitset_size(jmeno_pole));
    }
    return (unsigned long) ((jmeno_pole[index / BITSIZE_UL + 1] & (1UL << (index % BITSIZE_UL))) != 0);
}

#endif //USE_LINE
#endif //BITSET_H