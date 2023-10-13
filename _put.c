#include "main.h"

/**
 * _puts - print a string
 * @str: the string
 * Return: void
 */

int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 * _putchar - write the char to stdout
 * @c: the char
 * Return: 1 on seccess -1 on error
 */

int _putchar(int c)
{
	static int i;

	static char buf(OUTPUT_BUF_SIZE);

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BIF_FLISH)
		buf[i++] = c;
	return (1);
}
