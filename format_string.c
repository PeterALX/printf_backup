#include "main.h"
#include <string.h>
char *format_string(char *str, fmt_options opts)
{
	int len;
	char *formatted_string;
	int i;

	len = _strlen(str) > opts.width ? _strlen(str) : opts.width;
	formatted_string = malloc(sizeof(char) * (len + 1));
	formatted_string[len + 1] = '\0';
	if (opts.left_align)
	{
		strncpy(formatted_string, str, _strlen(str));
		i = _strlen(str);
		while (i < len)
		{
			formatted_string[i] = ' ';
			i++;
		}

	}
	else
	{
		i = 0;
		while (i < len - _strlen(str))
		{
			formatted_string[i] = ' ';
			i++;
		}
		strncpy(formatted_string + i, str, _strlen(str));
	}
	return (formatted_string);

}
