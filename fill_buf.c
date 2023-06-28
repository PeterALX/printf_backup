#include "main.h"
#include <stdio.h>

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

	len = _strlen(str) < len ? _strlen(str) : len;

	/* if (len + p_buf->cursor >= p_buf->max_size) */
	/* { */
	/* 	write(1, p_buf->buf, p_buf->cursor); */
	/* 	p_buf->cursor = 0; */
	/* } */
	i = 0;
	while (i < len)
	{
		if (p_buf->cursor >= p_buf->max_size)
		{
			write(1, p_buf->buf, p_buf->cursor);
			p_buf->cursor = 0;
		}
		p_buf->buf[p_buf->cursor] = str[i];
		p_buf->cursor++;
		p_buf->bytes_filled++;
		i++;
	}
	/* printf("\ncursor: %d\n", p_buf->cursor); */
}
