
#include "main.h"
#include <string.h>

/**
 * format_char- formats a c based on format options
 * @c: the char to be formatted
 * @opts: the format options
 * @p_buf: the result is pushed to the print_buffer
 * Return: void
 */
void format_char(char c, fmt_options opts, print_buf *p_buf)
{
	int len;
	int i;
	
	c = c == '\0' ? '\n' : c;
	len = opts.width > 1 ? opts.width : 1;
	if (opts.left_align)
	{
		fill_buf(p_buf, &c, 1);
		i = 1;
		while (i < len)
		{
			fill_buf(p_buf, " ", 1);
			i++;
		}

	}
	else
	{
		i = 0;
		while (i < len - 1)
		{
			opts.zero_fill ? fill_buf(p_buf, "0", 1) : fill_buf(p_buf, " ", 1);
			i++;
		}
		fill_buf(p_buf, &c, 1);
	}
}
