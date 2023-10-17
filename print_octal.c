#include "main.h"
/**
* print_octal - unsigned int argument is converted to unsigned octal
* @o: unsigned to be converted
* Descriptions: prints unsigned octal
* Return: size
*/
int print_octal(va_list o)
{
	unsigned int bin, sc, j, sd, n, vum;
	int i = 0;

	n = va_arg(o, unsigned int);
	if (n != 0)
	{
		vum = n;
		bin = 0;
		while (vum != 0)
		{
			vum /= 8;
			bin++;
		}
		sc = 1;
		for (j = 1; j <= bin - 1; j++)
			sc *= 8;
		for (j = 1; j <= bin; j++)
		{
			sd = n / sc;
			_putchar(sd + '0');
			i++;
			n -= sd * sc;
			sc /= 8;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (i);
}
