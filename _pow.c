#include "main.h"

int _pow(int x, int y)
{
	int result = 1;
	while (y > 0)
	{
		result *= x;
		y--;
	}
	return (result);
}
