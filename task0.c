#include "main.h"
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
		else if (format[*i] == 'd' || format[*i] == 'i')
		{
			count += handle_int(param);
		}
		else
			count += handle_extra(format, i);
	}
	else
	{
		_putchar(format[*i]); /* no conversion needed*/
		count++;
	}
	return (count);
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
		else
			count += check_format(format, &i, param);
		i++;
	}
	va_end(param);
	return (count);
}
