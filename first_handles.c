#include "main.h"



/**
 * handle_int- handle integers
 * @param: list of arguments
 * Return: characters printed
 */
int handle_int(va_list param)
{
long int number = va_arg(param, int);
int count = 0;
if (number == 0)
{
	_putchar('0');
	return (count + 1);
}
if (number < 0)
{
	_putchar('-');
	number = (number) * (-1);
	count++;
}
count += print_digits(number, 10);
return (count);
}


/**
 * print_digits- print digits
 * @number: number to print
 * Return: count
 */
int print_digits(long int number, int base)
{
int i = 0;
int j = 0;
char temp;
char str[20];
int ind_z = 0;
int ind_l = 0;
long int rev_number = 0;
/*changes number to acii characters in a charater array(string)*/
while (number > 0)
{
	rev_number = number % base;
	str[i++] = (rev_number > 9) ? (rev_number - 10) + 'a' : rev_number + '0';
	number = number / base;
}
str[i] = '\0';

ind_l = i - 1;
while (ind_z < ind_l) /*reverse string */
{
	temp = str[ind_z];
	str[ind_z] = str[ind_l];
	str[ind_l] = temp;
	ind_z++;
	ind_l--;
}
while (str[j] != '\0') /*print number*/
{
	_putchar(str[j]);
	j++;
}
return (i);
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
char *n = "(null)";

if (s != NULL)
{
	for (a = 0; s[a] != '\0'; a++)
	{
		_putchar(s[a]);
	}
}
else
{
	while (n[a] != '\0')
	{
		_putchar(n[a]);
		a++;
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
	else if (format[*i] != 's')
	{
		_putchar('%');
		_putchar(format[*i]);
		return (2);
	}
	return (0);
}
