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
		count += check_char_string(param, format[*i]);
		count += check_percent(format[*i]);
		count += check_int(param, format[*i]);
		count += check_bin(param, format[*i]);
		if  (count == 0)
			(handle_extra(format, i));
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
