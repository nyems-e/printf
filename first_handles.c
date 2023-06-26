#include "main.h"
/**
 * handle_int- handle integers
 * @param: list of arguments
 * Return: characters printed
 */
int handle_int(va_list param)
{
int i = 0;
int count = 0;
int number = va_arg(param, int);
int rev_number = 0;
if (number < 0)
{
	_putchar('-');
	number = -number;
	count++;
}
for (i = 0; number > 0; i++) /*print number in reverse order*/
{
	rev_number = rev_number * 10 + (number % 10);
	_putchar('0' + (rev_number % 10));
	number = number / 10;
}
return (i + count);
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

	if (format[*i] == ' ')
	{
		_putchar(' ');
		return (1);
	}
	else
	{
		_putchar('%');
		_putchar(format[*i]);
		return (2);
	}
}
