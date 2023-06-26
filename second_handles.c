#include "main.h"
#include <stdio.h>

/**
 * handle_binary - this function converts and prints an int in the binary
 * @number: the argument passed to _printf
 * Return: number of characters printed
 */

int handle_binary(int number)
{
	int count = 0;
	char store_remainder[32]; /* char to store remainder after the division */
	int index = 0; /* index to increase the iterating to store the remainder */
	int i;

	while (number > 0)
	{
		store_remainder[index] = '0' + (number % 2);
		number /= 2;
		index++;
	}
	/**
	 *reversing the remainders stored
	 */
	if (store_remainder[index] != ' ')
	{
		for (i = index - 1; i >= 0; i--)
		{

			_putchar(store_remainder[i]);
			count++;
		}
	}
	return (count);
}
