#include "main.h"
/**
* print_dec - function that prints an decimal
* @d: integer to print
* Descriptions: prints digit with _putchar
* Return: size the output
*/
int print_dec(va_list d)
{
	int bin, sc, j, sd, n, i = 0, vum;

	n = va_arg(d, int);
	if (n != 0)
	{
		if (n < 0)
		{
			_putchar('-');
			i++;
		}
		vum = n;
		bin = 0;
		while (vum != 0)
		{
			vum /= 10;
			bin++;
		}
		sc = 1;
		for (j = 1; j <= bin - 1; j++)
			sc *= 10;
		for (j = 1; j <= bin; j++)
		{
			sd = n / sc;
			if (n < 0)
				_putchar((sd * -1) + 48);
			else
				_putchar(sd + '0');
			i++;
			n -= sd * sc;
			sc /= 10;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (i);
}
