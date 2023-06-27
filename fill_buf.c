#include "main.h"

/**
 * fill_buf - pushes a string to the print_buffer 
 * @p_buf: the print_buffer being appended into
 * @str: the string to fill it with
 * @len: the length of the string to be filled
 * Return: void
 */
void fill_buf(print_buf *p_buf, char *str, int len)
{
	int i;

	i = 0;
	while (str[i] && i < len)
	{
		p_buf->buf[i + p_buf->cursor] = str[i];
		i++;
	}
	p_buf->cursor += i;
}
