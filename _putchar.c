#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes a char to stdout
 * @c: the char
 * Return: ?
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
