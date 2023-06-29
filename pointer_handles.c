#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/**
 * handle_pointer - this function prints the address of a pointer
 * @take_pointer: address of the pointer
 * Return: the number of characters printed
 */

int handle_pointer(void *take_pointer)
{
	int i, count = 0;
	unsigned int *address = (unsigned int *)take_pointer;
	char pointer[20];

	if (take_pointer == NULL)
	{
		return (0);
	}
	sprintf(pointer, "%p", (void *)address);

	for (i = 0; pointer[i] != '\0'; i++)
	{
		_putchar(pointer[i]);
		count++;
	}
	return (count);
}
