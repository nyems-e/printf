#include <stdio.h>
#include "main.h"
#include <stdarg.h>
#include <string.h>

/**
 * check_format - this is checking for format specifier
 * @format: the format to be checked
 * @i: counter
 * @param: name of list
 * Return: count
 */
int check_format(const char *format, int *i, va_list param)
{
	int count = 0;
	int a = 0;
	char *s;

	if (format[*i] == '%')
	{
		if (format[*i + 1] == ' ')
			return (-1);
		if (format[*i + 1] == '%')
		{
			_putchar('%');
			count++;
		}
		else if (format[*i + 1] == 'c')
		{
			_putchar(va_arg(param, int));
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
		else
			return (-1);
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

	int count = 0;
	int i = 0;

	va_start(param, format);

	if (format == NULL || strcmp(format, " ") == 0)
	{
		return (-1);
	}
	while (format[i] != '\0')
	{
		count += check_format(format, &i, param);
		i++;
	}
	va_end(param);
	return (count);
}

