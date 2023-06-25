#include <unistd.h>
#include "main.h"

/**
 * _putchar - this function returns a character c to the stdout
 * @c: this is the character to print to stdout
 * Return: 1 when success, else -1 and set errno appropriately
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
