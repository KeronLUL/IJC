// error.h
// IJC-DU1, 18.3.2020
// Karel Norek, xnorek01
// FIT VUT
// gcc 7.4

#ifndef ERROR_H
#define ERROR_H

/**
 * Write warning
 * @param fmt - error message
 * @param ... - variable
 */
void warning_msg(const char *fmt, ...);

/**
 * Write warning and exit program
 * @param fmt - error message
 * @param ... - variable
 */
void error_exit(const char *fmt, ...);

#endif