#include "main.h"
/**
* print_unsig - function that prints unsigned number
* @u: unsigned number
* Descriptions: prints unsigned number with putchar
* Return: size the output
*/
int print_unsig(va_list u)
{
	unsigned int length, powten, j, digit, n, num;
	int counter = 0;

	n = va_arg(u, unsigned int);
	if (n != 0)
	{
		num = n;
		length = 0;
		while (num != 0)
		{
			num /= 10;
			length++;
		}
		powten = 1;
		for (j = 1; j <= length - 1; j++)
			powten *= 10;
		for (j = 1; j <= length; j++)
		{
			digit = n / powten;
			_putchar(digit + '0');
			counter++;
			n -= digit * powten;
			powten /= 10;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (counter);
}
