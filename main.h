#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int check_format(const char *format, int *i, va_list parameter);
int handle_char(va_list param);
int handle_string(va_list param);
#endif
