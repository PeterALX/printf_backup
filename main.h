#ifndef _MAIN_
#define _MAIN_
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int show_plus;
	int left_align;
	int zero_fill;
	int width;
} fmt_options;

typedef struct
{
	int cursor;
	int max_size;
	char buf[1024];

} print_buf;

void fill_buf(print_buf *p_buf, char *str, int len);
int _printf(char *format, ...);
int _atoi(char *str);
int _pow(int x, int y);
int _strlen(char *str);
int _putchar(char c);
void format_string(char *str, fmt_options opts, print_buf *p_buf);
#endif /** !_MAIN_ **/

