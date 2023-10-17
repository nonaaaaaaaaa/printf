#include <stdarg.h>
#include <stdio.h>
#include "main.h"
/**
* print_bin - convert to binary
* @b: number in decinal
* Return: number of chars printed
*/
int print_bin(va_list b)
{
	unsigned int bin, sc, j, sd, n, vum;
	int count = 0;

	n = va_arg(b, unsigned int);
	if (n != 0)
	{
		vum = n;
		bin = 0;
		while (vum != 0)
		{
			vum /= 2;
			bin++;
		}
		sc = 1;
		for (j = 1; j <= bin - 1; j++)
			sc *= 2;
		for (j = 1; j <= bin; j++)
		{
			sd = n / sc;
			_putchar(sd + '0');
			count++;
			n -= sd * sc;
			sc /= 2;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
