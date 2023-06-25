#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - this is a printf replica
 * @format: the argument passed to _printf
 * Return: the total number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list param;
	static char buffer[BUFFER_SIZE];
	static int buff_ind = 0;
	int count = 0;
	int i = 0;

	va_start(param, format);
	if (format == NULL || strcmp(format, " ") == 0)
	{
		return (-1);
	}
	while (format[i] != '\0')
	{
		if (buff_ind == BUFFER_SIZE)
		{
			/* Buffer is full, flush it */
			write(1, buffer, buff_ind);
			count += buff_ind;
			buff_ind = 0;
		}

	
		if (format[i] == '%')
		{			/* Handle format specifier */
			count += check_format(format, &i, param);
			i++;
		}
		else
		{
			/* Add character to buffer */
			buffer[buff_ind++] = format[i];
			count++;
			i++;
		}
	}
	/* Flush remaining contents of the buffer */
	write(1, buffer, buff_ind);
	count += buff_ind;
	va_end(param);
	return (count);
}
