#ifndef _MAIN_
#define _MAIN_
#include <unistd.h>
#include <stdio.h>

typedef struct
{
	int show_plus;
	int left_align;
	int zero_fill;
	int width;
} fmt_options;

int _printf(char *format, ...);
int _atoi(char *str);
int _pow(int x, int y);
int _putchar(char c);
#endif /** !_MAIN_ **/

