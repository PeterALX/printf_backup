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
	char *buf;

} print_buf;

int _printf(char *format, ...);
int _atoi(char *str);
int _pow(int x, int y);
int _strlen(char *str);
int _putchar(char c);
char *format_string(char *str, fmt_options opts);
#endif /** !_MAIN_ **/

