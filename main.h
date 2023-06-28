#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
int handle_extra(const char *format, int *i);
int handle_binary(unsigned int number);
int _printf(const char *format, ...);
int _putchar(char c);
int check_format(const char *format, int *i, va_list parameter);
int handle_char(va_list param);
int handle_string(va_list param);
int handle_int(va_list param);
int print_digits(int number, int base);
#endif
