// steg-decode.c
// IJC-DU1, 18.3.2020
// Karel Norek, xnorek01
// FIT VUT
// gcc 7.4

#include <stdio.h>
#include "bitset.h"
#include "ppm.h"
#include "error.h"
#include "eratosthenes.h"

void decode(struct ppm *image) {
    unsigned size = 3 * image->xsize * image->ysize;
    unsigned index = 0;

    bitset_alloc(pole, size);
    bitset_create(znak, CHAR_BIT + 1);
    Eratosthenes(pole);

    for (unsigned i = 23; i < size; i++) {
        if (!(bitset_getbit(pole, i))) {
            bitset_setbit(znak, index, (image->data[i] & 1));
            index++;
        }
        if (index == CHAR_BIT) {
            putchar(znak[1]);
            if (znak[1] == '\0') {
                break;
            }
            index = 0;
        }
    }
    fprintf(stdout, "\n");

    if (znak[1] != '\0') {
        warning_msg("decode: prava spatne ukoncena\n");
    }
    bitset_free(pole);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        error_exit("decode: Neplatny argument\n");
    }
    struct ppm *image = ppm_read(argv[1]);

    if (image == NULL) {
        return 1;
    }
    decode(image);
    ppm_free(image);
    return 0;
}