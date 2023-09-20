#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/**
 * print_char - print character
 * @zp: arg pointer
 * @para: parameters struction
 * Return: number chars to print
*/

int print_char(va_list zp, parat *para)
{
	char pad_char = ' ';
	unsigned int pad = 1, sum = 0, ch = va_arg(zp, int);

	if (para->minusf)
		sum += _putchar(ch);

	while (pad++ < para->width)
		sum += _putchar(pad_char);

	if (!para->minusf)
		sum += _putchar(ch);

	return (sum);
}

/**
 * print_int - print integers
 * @zp: arg pointer
 * @para: parameters struction
 * Return: number chars to print
*/

int print_int(va_list zp, parat *para)
{
	long l;

	if (para->lzby)
		l = va_arg(zp, long);

	else if (para->hzby)
		l = (short int)va_arg(zp, int);

	else
		l = (int)va_arg(zp, int);

	return (print_number(convert(l, 10, 0, para), para));
}

/**
 * print_string - print string
 * @zp: arg pointer
 * @para: parameters struction
 * Return: number chars to print
*/

int print_string(va_list zp, parat *para)
{
	char *str = va_arg(zp, char *), pad_char = ' ';
	unsigned int pad = 0, sum = 0, i = 0, j;

	(void)para;

	switch ((int)(!str))
		case 1:
			str = NULL_STR;

	j = pad = _strlen(str);

	if (para->prec < pad)
		j = pad = para->prec;

	if (para->minusf)
	{
		if (para->prec != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);

		else
			sum += _puts(str);
	}

	while (j++ < para->width)
		sum += _putchar(pad_char);

	if (!para->minusf)
	{
		if (para->prec != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);

		else
			sum += _puts(str);
	}
	return (sum);
}

/**
 * print_percent - print string
 * @zp: arg pointer
 * @para: parameters struction
 * Return: number chars to print
*/

int print_percent(va_list zp, parat *para)
{
	(void)zp;
	(void)para;
	return (_putchar('%'));
}

/**
 * print_S - custom format specifier
 * @zp: arg pointer
 * @para: parameters struction
 * Return: number chars to print
*/

int print_S(va_list zp, parat *para)
{
	char *str = va_arg(zp, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STR));

	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, para);

			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}
