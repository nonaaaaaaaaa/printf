#include "main.h"

/**
 * get_specifier - find the function
 * @s: the string
 * Return: the number of char printed
 */

int (*get_specifier(char *s))(va_list ap; params_t *params)
{
	specifier_t specifiers[] = {
		{"c", print_char},
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++
	}
	return (NULL);
}


/**
 * get_print_func - find the func
 * @s: the string
 * @ap: argument pointer
 * @params: the parameter struct
 * Return: the number of char printed
 */

int get_print_func(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get specifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}

/**
 * get_flag - find the flag
 * @s: the string
 * @params: the parameter
 * Return: if flag return 1 else return 0
 */

int get_flag(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = params->plus_flag = 1;
			break;
		case ' ':
			i = params->space_flag = 1;
			break;
		case '#':
			i = params->hashtag_flag = 1;
			break;
		case '-':
			i = params->minus_flag = 1;
			break;
		case '0':
			i = params->zero_flag = 1;
			break;
	}
	return (i);
}


/**
 * get_modifier - find the modifier
 * @s: the string
 * @params: the parameter
 * Return: if modifier is valid
 */

int get_modifier(char *s, params_t *params)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = params->h_mosifier = 1;
			break;
		case 'l':
			i = params->l_modifier = 1;
			break;
	}
	return (i);
}

/**
 * get_width - get the width of string
 * @s: the string
 * @params: the parameters
 * @ap: the argument pointer
 * Return: new pointer
 */

char *get_width(char *s, params_t params, va_list ap)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	params->width = d;
	return (s);
}