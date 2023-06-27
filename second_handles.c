#include "main.h"
#include <stdio.h>

/**
 * handle_binary - this function converts and prints an int in the binary
 * @number: the argument passed to _printf
 * Return: number of characters printed
 */

int handle_binary(int number)
{
	char store_remainder[32];
	int index = 0; /* index to increase the iterating to store the remainder */
	int i;
	int count = 0;

	while (number > 0)
	{
		store_remainder[index] = number % 2;
		store_remainder[index] = '0' + (number % 2);
		number /= 2;
		index++;
	}
	/**
	 *reversing the remainders stored
	 */
	for (i = index - 1; i >= 0; i--)
	{
		_putchar(store_remainder[i]);
		count++;
	}
	return (count);
}
