#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_opts(fmt_options opts);
void reset_opts(fmt_options *opts);

/**
 * _printf - prints stuff based on a format string
 * @format: the format string
 * Return: the length of the printed string
 */
int _printf(char *format, ...)
{
	/* char buf[1024]; */
	int  i, state, width_cursor;
	va_list ap;
	fmt_options opts = {0, 0, 0, 0};
	print_buf p_buf;
	char *fmt;



	state = 0;
	width_cursor = 0;
	va_start(ap, format);
	p_buf.max_size = 1024;
	p_buf.cursor = 0;
	for (i = 0; format[i]; i++)
	{
		if (state == 0)
		{
			if (format[i] == '%')
			{
				state = 1;
			}
			else
			{
				/* p_buf.buf[p_buf.cursor] = format[i]; */
				/* len++; */
				fill_buf(&p_buf, format + i, 1);
			}
		} else if (state == 1)
		{
			/* opts */
			if (format[i] == '+' && width_cursor == 0)
				opts.show_plus = 1;
			else if (format[i] == ' ' && width_cursor == 0)
				opts.show_plus = 2;
			else if (format[i] == '-' && width_cursor == 0)
				opts.left_align = 1;
			else if (format[i] == '0' && width_cursor == 0)
				opts.zero_fill = 1;

			/* width */
			else if (format[i] > '0' && format[i] <= '9' && width_cursor == 0)
			{
				width_cursor = i;
			}
			else if (width_cursor > 0 && format[i] >= '0' && format[i] <= '9')
			{

			}

			/* specifiers */
			else if (format[i] == 'c')
			{
				opts.width = _atoi(format + width_cursor);
				/* print_opts(opts); */
				/* p_buf.buf[p_buf.cursor] = va_arg(ap, int); */
				/* p_buf.cursor += 1; */
				format_char(va_arg(ap,int), opts, &p_buf);

				state = 0;
				reset_opts(&opts);
				width_cursor = 0;
			}
			else if (format[i] == 's')
			{
				opts.width = _atoi(format + width_cursor);
				format_string(va_arg(ap, char *), opts, &p_buf);
				/* print_opts(opts); */
				state = 0;
				reset_opts(&opts);
				width_cursor = 0;
			}

			else
			{
				/* buf[len] = format[i]; */
				/* len++; */
				fill_buf(&p_buf, format + i, 1);
				state = 0;
				/* print_opts(opts); */
				reset_opts(&opts);
				width_cursor = 0;
				/* printf("unknown specifier\n"); */
			}
		}
	}
	write(0, p_buf.buf, p_buf.cursor);
	return (p_buf.cursor);
}

/**
 * reset_opts - reset fmt_options to default
 * @opts: the format options
 * Return: void
 */
void reset_opts(fmt_options *opts)
{
	opts->show_plus = 0;
	opts->left_align = 0;
	opts->zero_fill = 0;
	opts->width = 0;
}

