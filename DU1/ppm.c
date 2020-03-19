// ppm.c
// IJC-DU1, 18.3.2020
// Karel Norek, xnorek01
// FIT VUT
// gcc 7.4

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ppm.h"
#include "error.h"

#define MAX_LIMIT 8000

struct ppm *ppm_read(const char *filename) {
    unsigned xsize = 0;
    unsigned ysize = 0;
    unsigned rgb = 0;
    char format[2] = {0};

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        warning_msg("ppm: Nepodarilo se otevrit soubor\n");
        return NULL;
    }

    if (fscanf(fp, "%s \n%u %u \n%u\n", format, &xsize, &ysize, &rgb) != 4) {
        warning_msg("ppm: Neplatny format ppm\n");
        fclose(fp);
        return NULL;
    }

    if (strcmp("P6", format) != 0) {
        warning_msg("ppm: Neplatny format ppm\n");
        fclose(fp);
        return NULL;
    }

    if (xsize > MAX_LIMIT || ysize > MAX_LIMIT || rgb > 255) {
        warning_msg("ppm: Neplatny format ppm\n");
        fclose(fp);
        return NULL;
    }

    struct ppm *image = malloc(sizeof(char) * 3 * xsize * ysize + sizeof(struct ppm));
    if (image == NULL) {
        warning_msg("ppm: Chyba alokace pameti\n");
        fclose(fp);
        return NULL;
    }

    image->xsize = xsize;
    image->ysize = ysize;

    if (fread(image->data, sizeof(char), 3 * xsize * ysize, fp) != 3 * xsize * ysize) {
        warning_msg("ppm: Neplatny format ppm\n");
        fclose(fp);
        return NULL;
    }

    if (fgetc(fp) != EOF) {
        warning_msg("ppm: Neplatny format ppm\n");
        fclose(fp);
        return NULL;
    }

    fclose(fp);
    return image;
}

void ppm_free(struct ppm *p) {
    free(p);
}