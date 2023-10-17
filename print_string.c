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

int print_custom(int v)
{
	int hi = v / 16;
	int lo = v % 16;

	_putchar('\\');
	_putchar('x');
	_putchar(hi < 10 ? '0' + hi : 'A' + hi - 10);
	_putchar(lo < 10 ? '0' + lo : 'A' + lo - 10);
	return (4);
}
/**
 * custom_print - print custom
 * @s: string
 * Return: void
 */
int custom_print(va_list s)
{
	char *b;
	int i = 0;

	b = va_arg(s, char *);
	while (*b)
	{
		if (*b < 32 || *b >= 127)
		{
			i += print_custom(*b);
		} else
		{
			i += _putchar(*b);
		}
		b++;
	}
	return (i);
}
