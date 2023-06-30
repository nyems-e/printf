#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

/**
 * handle_pointer - this function prints the address of a pointer
 * @param: the name of list
 * @pointer: this is format passed to the printf
 * Return: the number of characters printed
 */

int handle_pointer(va_list param, char pointer)
{
	int count = 0;

	if (pointer == 'p')
	{
		void *take_pointer = va_arg(param, void *);
		int i;
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
	}
	return (count);
}
