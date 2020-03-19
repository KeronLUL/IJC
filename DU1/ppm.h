// ppm.h
// IJC-DU1, 18.3.2020
// Karel Norek, xnorek01
// FIT VUT
// gcc 7.4

#ifndef PPM_H
#define PPM_H

/**
 * Structure for ppm image
 */
struct ppm {
    unsigned xsize;
    unsigned ysize;
    char data[];
};

/**
 * Function reads ppm file and loads it into structure
 * @param filename - ppm file
 * @return structure with image data loaded
 */
struct ppm *ppm_read(const char *filename);

/**
 * Free allocated structure
 * @param p - structure to be freed
 */
void ppm_free(struct ppm *p);

#endif
