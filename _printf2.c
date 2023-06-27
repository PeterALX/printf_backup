#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_opts(fmt_options opts);
void fill_buf(char *buf);
void reset_opts(fmt_options *opts);

int _printf(char *format, ...)
{
	char buf[1024];
	int len, i, state, width_cursor;
	va_list ap;
	fmt_options opts = {0, 0, 0, 0};
	print_buf p_buf;
	char *fmt;



	len = 0;
	state = 0;
	width_cursor = 0;
	va_start(ap, format);
	p_buf.max_size = 1024;
	p_buf.cursor = 0;
	p_buf.buf = malloc(sizeof(char) * p_buf.max_size);
	
	for (i = 0; format[i]; i++)
	{
		if (state == 0)
		{
			if (format[i] == '%')
			{
				state = 1;
			} else
			{
				buf[len] = format[i];
				len++;
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
				print_opts(opts);
				buf[len] = va_arg(ap, int);
				len++;
				state = 0;
				reset_opts(&opts);
				width_cursor = 0;
			}
			else if (format[i] == 's')
			{
				opts.width = _atoi(format + width_cursor);
				format_string(va_arg(ap, char *), opts);
				/* print_opts(opts); */
				state = 0;
				reset_opts(&opts);
				width_cursor = 0;
			}

			else
			{
				buf[len] = format[i];
				len++;
				state = 0;
				print_opts(opts);
				reset_opts(&opts);
				width_cursor = 0;
				printf("unknown specifier\n");
			}
		}
	}
	write(0, buf, len);
	return (len);
}
void fill_buf(char *buf) {}
void reset_opts(fmt_options *opts)
{
	opts->show_plus = 0;
	opts->left_align = 0;
	opts->zero_fill = 0;
	opts->width = 0;
}
void print_opts(fmt_options opts)
{
	printf(".....................................\n");
	printf("showplus: %d\n", opts.show_plus);
	printf("left_align: %d\n", opts.left_align);
	printf("zero_fill: %d\n", opts.zero_fill);
	printf("width: %d\n", opts.width);
	printf(".....................................\n");
}
