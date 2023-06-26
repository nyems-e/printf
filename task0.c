#include <stdio.h>
#include "main.h"
#include <stdarg.h>
#include <string.h>

/**
 *check_format - this is checking for format specifier
 *@format: the format to be checked
 *@i: counter
 *@param: name of list
 *Return: count
 */
int check_format(const char *format, int *i, va_list param)
{
	int count = 0;

	if (format[*i] == '%')
	{
		(*i)++;
		if (format[*i] == 'c')
		{
			count += handle_char(param);
		}
		else if (format[*i] == 's')
		{
			count += handle_string(param);
		}
		else if (format[*i] == '%')
		{
			_putchar('%');
			count++;
		}
		else if (format[*i] == ' ')
		{
			count += handle_extra(format, i);
			return (count);
		}
		else
		{
			_putchar(format[*i]); /* no conversion needed*/
			count++;
		}
	}
	return (count);
}
/**
 *handle_char- handle character conversion
 *@param: list of printf parameters
 *Return: character count
 */
int handle_char(va_list param)
{
	int track = va_arg(param, int);

	_putchar(track);
	return (1);
}
/**
 *handle_string- handle string conversion
 *@param: list of printf parameters
 *Return: number characters printed
 */
int handle_string(va_list param)
{
	char *s = va_arg(param, char *);

	int a = 0;

if (s != NULL)
{
for (a = 0; s[a] != '\0'; a++)
{
_putchar(s[a]);
}
}
return (a);
}

/**
 * handle_extra - handle extra
 * @format: format passed to printf
 * @i: calling pointer i to reiterate over the format
 * Return: number of characters printed
 */
int handle_extra(const char *format, int *i)
{
	int count = 0;

	if (format[*i] == ' ')
	{
		_putchar(' ');
		return (1);
	}
	else
	{
		_putchar('%');
		_putchar(format[*i]); /*when conversion specifier is not handled*/
		count += 2;
		return (2);
	}
}
/**
 *_printf - this is printf replica
 *@format: the argument passed to printf
 *Return: total number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list param; /* name of list */
	int count = 0;
	int i = 0;

	va_start(param, format);

	if (format == NULL || strcmp(format, " ") == 0)
	{
		va_end(param);
		return (-1);
	}
	while (format[i] != '\0')
	{
		if (format[i + 1] == '\0' && format[i] == '%')
		{
			return (-1);
		}
		count += check_format(format, &i, param);
		i++;
	}
	va_end(param);
	return (count);
}
