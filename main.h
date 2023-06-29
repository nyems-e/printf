#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
int handle_extra(const char *format, int *i);
int _printf(const char *format, ...);
int _putchar(char c);
int check_format(const char *format, int *i, va_list parameter);
int handle_char(va_list param);
int handle_string(va_list param);
int handle_int(va_list param);
int handle_pointer(void *take_pointer);
int print_digits(long int number, int base);
int check_char_string(va_list param, char char_specifier);
int check_percent(char char_specifier);
int check_int(va_list param, char char_specifier);
int check_bin(va_list param, char char_specifier);
int handle_binary(unsigned int number);
#endif
