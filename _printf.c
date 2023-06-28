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
	int  i, state, width_cursor;
	va_list ap;
	fmt_options opts = {0, 0, 0, 0};
	print_buf p_buf;

	if (!format)
		return (-1);

	state = 0;
	width_cursor = 0;
	va_start(ap, format);
	p_buf.max_size = 1024;
	p_buf.bytes_filled = 0;
	p_buf.cursor = 0;
	for (i = 0; format[i]; i++)
	{
		if (state == 0)
		{
			if (format[i] == '%')
			{
				if (!format[i + 1])
				{
					write(1, p_buf.buf, p_buf.cursor);
					va_end(ap);
					return (-1);
				}
				state = 1;
			}
			else
			{
				fill_buf(&p_buf, format + i, 1);
			}
		} else if (state == 1)
		{
			if (format[i] == '+' && width_cursor == 0)/* opts */
				opts.show_plus = 1;
			else if (format[i] == ' ' && width_cursor == 0)
				opts.show_plus = 2;
			else if (format[i] == '-' && width_cursor == 0)
				opts.left_align = 1;
			else if (format[i] == '0' && width_cursor == 0)
				opts.zero_fill = 1;

			else if (format[i] > '0' && format[i] <= '9' && width_cursor == 0)/* width */
			{
				width_cursor = i;
			}
			else if (width_cursor > 0 && format[i] >= '0' && format[i] <= '9'){}
			else if (format[i] == 'c')/* specifiers */
			{
				opts.width = _atoi(format + width_cursor);
				/* print_opts(opts); */
				format_char(va_arg(ap, int), opts, &p_buf);
				state = 0;
				reset_opts(&opts);
				width_cursor = 0;
			}
			else if (format[i] == 's')
			{
				opts.width = _atoi(format + width_cursor);
				format_string(va_arg(ap, char *), opts, &p_buf);
				state = 0;
				reset_opts(&opts);
				width_cursor = 0;
			}
			else
			{
				if (format[i] != '%')
					fill_buf(&p_buf, "%", 1);
				fill_buf(&p_buf, format + i, 1);
				state = 0;
				reset_opts(&opts);
				width_cursor = 0;
			}
		}
	}
	write(1, p_buf.buf, p_buf.cursor);
	va_end(ap);
	return (p_buf.bytes_filled);
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

/**
 * print_opts - prints a fmt_options struct
 * @opts: the struct
 * Return: void
 */
/* void print_opts(fmt_options opts) */
/* { */
/* 	printf(".....................................\n"); */
/* 	printf("showplus: %d\n", opts.show_plus); */
/* 	printf("left_align: %d\n", opts.left_align); */
/* 	printf("zero_fill: %d\n", opts.zero_fill); */
/* 	printf("width: %d\n", opts.width); */
/* 	printf(".....................................\n"); */
/* } */
