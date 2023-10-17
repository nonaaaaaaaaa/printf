#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * print_string - writes the character c to stdout
 * @s: The string to print
 *
 * Return: 1.
 */
int print_string(va_list s)
{
	char *my_string;
	int  i = 0;

	my_string = va_arg(s, char *);
	if (my_string == NULL)
		my_string = "(null)";
	while (my_string[i])
	{
		if (my_string[i] < 32 || my_string[i] >= 127)
			print_custom(my_string[i];
		else
			_putchar(my_string[i]);
		i++;
	}
	return (i);
}

/**
 * print_custom - print non printable char
 * @v: int
 * Return: void
 */

void print_custom(int v)
{
	int hi = v / 16;
	int lo = v % 16;

	putchar('\\');
	putchar('x');
	putchar(hi < 10 ? '0' + hi : 'A' + hi - 10);
	putchar(lo < 10 ? '0' + lo : 'A' + lo - 10);
}
