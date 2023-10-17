#include "main.h"
/**
* print_int - function that prints an integer
* @i: integer to print
* Descriptions: prints digit with _putchar
* Return: size
*/
int print_int(va_list i)
{
	int bin, sc, j, sd, n, k = 0, vum;

	n = va_arg(i, int);
	if (n != 0)
	{
		if (n < 0)
		{
			_putchar('-');
			k++;
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
			k++;
			n -= sd * sc;
			sc /= 10;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (k);
}
