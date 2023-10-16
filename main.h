#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED  2

/**
 *  struct format -  struct definition token
 * @unsign: if unsigned value
 * @plus_flag: on if plus_falg specified
 * @space_flag: on if hastg_flag
 * @hashtag_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 * @width: field width specified
 * @precision: field width specified
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 */

typedef struct format
{
	unsigned int width;

	unsigned int unsign		:1;
	unsigned int plus_flag		:1;
	unsigned int space_flag		:1;
	unsigned int hashtag_flag	:1;
	unsigned int zero_flag		:1;
	unsigned int minus_flag		:1;
	unsigned int precision;

	unsigned int h_modifier		:1;
	unsigned int l_modifier		:1;

} params_t;

/**
 * struct params_t - parameters for operation
 * @l_modifier: indicate if 'l' is used
 * @h_modifier: indicate if 'h' is used
 * @unsign: the value is unsign
 *
 */

struct params_t {
	int l_modifier;
	int h_modifier;
	int unsign;

};

/**
 * struct specifier - struct token
 * @specifier: format token
 * @f: function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;


/* _puts.c part */
int _puts(char *str);
int _putchar(int c);

/* print_functions.c part */
int print_char(va_list ap, params_t *params);
int print_int(va_list ap, params_t *params);
int print_string(va_list ap, params_t *params);
int print_percent(va_list ap, params_t *params);
int print_S(va_list ap, params_t *params);

/* number.c part */
char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list ap, params_t *params);
int print_address(va_list ap, params_t *params);

/* specifier.c part */
int (*get_specifier(char *s))(va_list ap, params_t *params);
int get_print_func(char *s, va_list ap, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
int *get_width(char *s, params_t *params, va_list ap);

/* convert_number.c part */
int print_hex(va_list ap, params_t *params);
int print_HEX(va_list ap, params_t *params);
int print_binary(va_list ap, params_t *params);
int print_octal(va_list ap, params_t *params);

/* simple_printers.c part */
int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list ap, params_t *params);
int print_rot13(va_list ap, params_t *params);

/* print_number.c part */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);

/* params.c part */
void init_params(params_t *params, va_list ap);


/* string_fields part */
char *get_precision(char *p, params_t *params, va_list ap);

/* _printf.c patr */
int _printf(const char *format, ...);

#endif

