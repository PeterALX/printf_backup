#include "main.h"

/**
 * _strlen - return length of a string
 * @str: the string
 * Return: the length of the string
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;

	return (i);
}
