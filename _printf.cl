#include <stdarg.h>
#include "main.h"
#include <stdlib.h>
#include <string.h>
void print_opts(fmt_options opts);
int _printf(char *format, ...) {
	char buf[1024];
	int len, i, state, width_cursor;
	va_list ap;
	fmt_options opts = {0, 0, 0, 0};

	len = 0;
	state = 0;
	va_start(ap, format);
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
				buf[len] = format[i];
				len++;
			}
		}
		else if (state == 1)
		{
			/* opts */
			if (format[i] == '+')
				opts.show_plus = 1;
			else if(format[i] == ' ')
				opts.show_plus = 2;
			else if (format[i] == '-')
				opts.left_align = 1;
			else if (format[i] == '0')
				opts.zero_fill = 1;

			/* specifiers */
			else if (format[i] == 'c')
			{
				print_opts(opts);
				buf[len] = va_arg(ap, int);
				len++;
				state = 0;
			}
			else if (format[i] == 's')
			{
				print_opts(opts);
				state = 0;
			}

			/* width */
			else if (format[i] > '0' && format[i] <= '9')
			{
				width_cursor = i;
				state = 2;
			}
			else
			{
				buf[len] = format[i];
				state = 0;
				printf("unknown specifier\n");
			}
		}
		else if (state == 2)
		{
			if (format[i] == 'c')
			{
				print_opts(opts);
				buf[len] = va_arg(ap, int);
				len++;
				state = 0;
			}
			else if (format[i] == 's')
			{
				print_opts(opts);
				state = 0;
			}
			else if (format[i] >= '0' && format[i] <= '9')
			{

			}
			else
			{
				buf[len] = format[i];
				len++;
				state = 0;
				printf("unknown specifier\n");
			}

		}
	}
	write(0, buf, len);
	return (len);
}

void print_opts(fmt_options opts)
{
	printf("showplus: %d\n", opts.show_plus);
	printf("left_align: %d\n", opts.left_align);
	printf("zero_fill: %d\n", opts.zero_fill);
	printf("width: %d\n", opts.width);
}
