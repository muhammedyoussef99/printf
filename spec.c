#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/**
 * get_spec - find format function
 * @s: format string
 * Return: numbers of bytes to print
*/

int (*get_spec(char *s))(va_list zp, parat * para)
{
	spect specs[] = {
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

	while (specs[i].spec)
	{
		if (*s == specs[i].spec[0])
		{
			return (specs[i].f);
		}
		i++;
	}
	return (NULL);
}

/**
 * get_func - find function format
 * @s: strind format
 * @zp: arg pointer
 * @para: parameters struction
 * Return: number of bytes to be print
*/

int get_func(char *s, va_list zp, parat *para)
{
	int (*f)(va_list, parat *) = get_spec(s);

	if (f)
		return (f(zp, para));
	return (0);
}

/**
 * getf - find flag function
 * @s: format string
 * @para: parameters struction
 * Return: if flag is true
*/

int getf(char *s, parat *para)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = para->plusf = 1;
			break;
		case ' ':
			i = para->spacef = 1;
			break;
		case '#':
			i = para->hashf = 1;
			break;
		case '-':
			i = para->minusf = 1;
			break;
		case '0':
			i = para->zerof = 1;
			break;
	}
	return (i);
}

/**
 * get_zby - finds modifier function
 * @s: format string
 * @para: parameters struction
 * Return: if modifier is true
*/

int get_zby(char *s, parat *para)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = para->hzby = 1;
			break;
		case 'l':
			i = para->lzby = 1;
			break;
	}
	return (i);
}

/**
 * get_width - width from format string
 * @s: format string
 * @para: parameters struction
 * @zp: arg pointer
 * Return: new pointer
*/

char *get_width(char *s, parat *para, va_list zp)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(zp, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	para->width = d;
	return (s);
}
