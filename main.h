#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

#define OUTPUT_FUB_SIZE 1024
#define FUB_BLUSH -1

#define NULL_STR "(null)"

#define PARA_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONV_LOWERCASE	1
#define CONV_UNSIGNED	2

/**
 * struct para - parameters
 * Description: flags
 *
 * @unsign: in case of unsigned value
 * @plusf: in case of its specified
 * @spacef: in case hashf specified
 * @hashf: in case _fzby specified
 * @zerof: as above
 * @minusf: as above
 * @width: width
 * @prec: precision
 * @hzby: modifier
 * @lzby: modfier
*/

typedef struct para
{
	unsigned int unsign	: 1;

	unsigned int plusf	: 1;
	unsigned int spacef	: 1;
	unsigned int hashf	: 1;
	unsigned int zerof	: 1;
	unsigned int minusf	: 1;

	unsigned int hzby	: 1;
	unsigned int lzby	: 1;

	unsigned int width;
	unsigned int prec;

} parat;

/**
 * struct spec - token specifier
 *
 * @spec: format token
 * @f: function
*/

typedef struct spec
{
	char *spec;
	int (*f)(va_list, parat *);
} spect;

int _puts(char *str);
int _putchar(int c);

int print_char(va_list zp, parat *para);
int print_int(va_list zp, parat *para);
int print_string(va_list zp, parat *para);
int print_percent(va_list zp, parat *para);
int print_S(va_list zp, parat *para);

char *convert(long int num, int base, int fl, parat *para);
int print_unsigned(va_list zp, parat *para);
int print_address(va_list zp, parat *para);

int (*get_spec(char *s))(va_list zp, parat *para);
int get_func(char *s, va_list zp, parat *para);
int getf(char *s, parat *para);
int get_zby(char *s, parat *para);
char *get_width(char *s, parat *para, va_list zp);

int print_hex(va_list zp, parat *para);
int print_HEX(va_list zp, parat *para);
int print_binary(va_list zp, parat *para);
int print_octal(va_list zp, parat *para);

int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list zp, parat *para);
int print_rot13(va_list zp, parat *para);

int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, parat *para);
int print_number_right_shift(char *str, parat *para);
int print_number_left_shift(char *str, parat *para);

void init_para(parat *para, va_list zp);

char *get_prec(char *p, parat *para, va_list zp);

int _printf(const char *format, ...);


#endif
