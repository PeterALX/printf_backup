#include "main.h"
#include <string.h>

/**
 * format_string - formats a string based on format options
 * @str: the string to be formatted
 * @opts: the format options
 * @p_buf: the result is pushed to the print_buffer
 * Return: void
 */
void format_string(char *str, fmt_options opts, print_buf *p_buf)
{
	int len;
	int lenstr;
	int i;

	if (!str)
		str = "(null)";

	lenstr = _strlen(str);
	len = lenstr > opts.width ? lenstr : opts.width;
	if (opts.left_align)
	{
		/* strncpy(formatted_string, str, lenstr); */
		fill_buf(p_buf, str, lenstr);
		i = lenstr;
		while (i < len)
		{
			/* formatted_string[i] = ' '; */
			fill_buf(p_buf, " ", 1);
			i++;
		}

	}
	else
	{
		i = 0;
		while (i < len - lenstr)
		{
			/* formatted_string[i] = ' '; */
			fill_buf(p_buf, " ", 1);
			i++;
		}
		/* strncpy(formatted_string + i, str, lenstr); */
		fill_buf(p_buf, str, lenstr);
	}
}
