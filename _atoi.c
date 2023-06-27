#include "main.h"

/**
 * _atoi - converts ascii to an int;
 * @str: the string to be converted
 * Return: the converted int
 *
 * doesn't handle floating point yet. should it
 */
int _atoi(char *str)
{
	int place_value, result, i, len, is_negative = 0;

	if ((str[0] < '0' || str[0] > '9') && (str[0] != '+' && str[0] != '-'))
		return (0);
	if (str[0] == '-')
	{
		is_negative = 1;
		str += 1;
	}

	place_value = 0;
	i = 0;
	len = 0;
	while (str[len] >= '0' && str[len] <= '9')
	{
		len++;
	}
	place_value = _pow(10, len - 1);

	i = 0;
	result = 0;
	while (i < len)
	{
		result += (str[i] - '0') * place_value;
		place_value /= 10;
		i++;
	}

	return (is_negative ? result * -1 : result);
}
