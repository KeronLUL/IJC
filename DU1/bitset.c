// bitset.c
// IJC-DU1, 18.3.2020
// Karel Norek, xnorek01
// FIT VUT
// gcc 7.4

#include "bitset.h"

#ifdef USE_INLINE
    extern void bitset_free(bitset_t jmeno_pole);
    extern unsigned long bitset_size(bitset_t jmeno_pole);
    extern void bitset_setbit(bitset_t jmeno_pole, const bitset_index_t index, const int vyraz);
    extern unsigned long bitset_getbit(bitset_t jmeno_pole, const bitset_index_t index);
#endif