#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>


int _printf(const char *format, ...);
int _putchar(char c);
unsigned int check_format(const char *format, unsigned int *i, va_list parameter);
#endif
