#include "main.h"
/**
* print_hex - function that prints an unsigned int in hexadecimal
* @n: unsigned to be printed
* @c: case of printing (0 = lower, 1 = upper)
* Descriptions: prints unsigned in hexadecimal with _putchar
* Return: size
*/
int print_hex(unsigned int n, unsigned int c)
{
	unsigned int bin, sc, j, sd, vum;
	int i = 0;
	char ful;

	if (n != 0)
	{
		vum = n;
		bin = 0;
		if (c)
			ful = 'A' - ':';
		else
			ful = 'a' - ':';
		while (vum != 0)
		{
			vum /= 16;
			bin++;
		}
		sc = 1;
		for (j = 1; j <= bin - 1; j++)
			sc *= 16;
		for (j = 1; j <= bin; j++)
		{
			sd = n / sc;
			if (sd < 10)
				_putchar(sd + '0');
			else
				_putchar(sd + '0' + ful);
			i++;
			n -= sd * sc;
			sc /= 16;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (i);
}
/**
* print_x - takes an unsigned int an prints it in lowercase hex
* @x: unsigned int to print
* Descriptions: prints in lowercase hex with _putchar
* Return: size of the output
*/
int print_x(va_list x)
{
	return (print_hex(va_arg(x, unsigned int), 0));
}
/**
* print_X - takes an unsigned int an prints it in uppercase hex
* @X: unsigned int to print
* Descriptions: prints in uppercase hex with _putchar
* Return: size of the output
*/
int print_X(va_list X)
{
	return (print_hex(va_arg(X, unsigned int), 1));
}
