#include "main.h"

/**
 * format_int - formats a int based on format options
 * @str: the int to be formatted
 * @opts: the format options
 * @p_buf: the result is pushed to the print_buffer
 * Return: void
 */
void format_int(int k, fmt_options opts, print_buf *p_buf)
{
	int len = 0;
	int i;
	int is_negative = 0;
	char cur_char;
	int place_value;

	if (k < 0)
	{
		k = -k;
		is_negative = 1;
	}

	i = k;
	while (i > 0)
	{
		i /= 10;
		len++;
	}
	if (k == 0)
		len = 1;

	if (is_negative)
	{
		fill_buf(p_buf, "-", 1);
	}
	i = len;
	place_value = _pow(10, len - 1);
	while (i > 0)
	{
		/* cur_char = k / _pow(10, i - 1) + '0'; */
		cur_char = k / place_value + '0';
		/* k %= _pow(10, i - 1); */
		k %= place_value;
		/* printf("%c ", cur_char); */
		fill_buf(p_buf, &cur_char, 1);
		i--;
		place_value /= 10;
	}
	/* printf("\n"); */
	/* printf("len %d: %d\n", k, len); */
	/* printf("first: %d\n", k / _pow(10, len - 1)); */
	/* printf("first as char: %c\n", k / _pow(10, len - 1) + '0'); */
}
