// error.c
// IJC-DU1, 18.3.2020
// Karel Norek, xnorek01
// FIT VUT
// gcc 7.4

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "error.h"

void warning_msg(const char *fmt, ...) {
    va_list arg;
    va_start(arg, fmt);

    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, arg);

    va_end(arg);
}

void error_exit(const char *fmt, ...) {
    va_list arg;
    va_start(arg, fmt);

    fprintf(stderr, "CHYBA: ");
    vfprintf(stderr, fmt, arg);

    va_end(arg);
    exit(1);
}
