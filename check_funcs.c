#include "main.h"

/**
 * check_char_string- check if it matches string or char
 * @param: list
 * @char_specifier: character
 * Return: count
 */
int check_char_string(va_list param, char char_specifier)
{
int count = 0;
if (char_specifier == 'c')
{
	count += handle_char(param);
}
else if (char_specifier == 's')
{
	count += handle_string(param);
}
return (count);
}


/**
 * check_percent- check if it matches percent
 * @char_specifier: character
 * Return: count
 */
int check_percent(char char_specifier)
{
int count = 0;
if (char_specifier == '%')
{
	_putchar('%');
	count++;
}
return (count);
}


/**
 * check_int- check if it matches int
 * @param: list
 * @char_specifier: character
 * Return: count
 */
int check_int(va_list param, char char_specifier)
{
int count = 0;
if (char_specifier == 'd' || char_specifier == 'i')
{
	count += handle_int(param);
}
return (count);
}


/**
 * check_bin - check if it matches binary
 * @param: list
 * @char_specifier: character
 * Return: count
 */
int check_bin(va_list param, char char_specifier)
{
int number;
int count = 0;
if (char_specifier == 'b')
{
	number = va_arg(param, unsigned int);
	count += handle_binary(number);
}
return (count);
}


