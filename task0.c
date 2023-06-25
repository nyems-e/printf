#include <stdio.h>
#include "main.h"
#include <stdarg.h>

/**
 * check_format - this is checking for format specifier
 * @format: the format to be checked
 * @i: counter
 * @param: name of list
 * Return: count
 */
unsigned int check_format(const char *format, unsigned int *i, va_list param)
{
	unsigned int count = 0;
	unsigned int a = 0;

	char c;
	char *s;

	if (format[*i] == '%')
	{
		if (format[*i + 1] == '%')
		{
			_putchar('%');
			count++;
		}
		else if (format[*i + 1] == 'c')
		{
			c = (char)va_arg(param, int);
			_putchar(c);
			count++;
		}
		else if (format[*i + 1] == 's')
		{
			s = va_arg(param, char *);
			if (s != NULL)
			{
				for (a = 0; s[a] != '\0'; a++)
				{
					_putchar(s[a]);
					count++;
				}
			}
		}
		(*i)++;
	}
	else
	{
		_putchar(format[*i]);
		count++;
	}
	return (count);
}

/**
 * _printf - this is printf replica
 * @format: the argument passed to printf
 * Return: total number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list param; /* name of list */

	unsigned int count = 0;
	unsigned int i = 0;

	va_start(param, format);

	while (format[i] != '\0')
	{
		count += check_format(format, &i, param);
		i++;
	}
	va_end(param);
	return (count);
}
