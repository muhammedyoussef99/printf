#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/**
 * print_hex - Prints an unsigned integer as a hexadecimal number in lowercase.
 * @zp: A va_list containing the argument to print.
 * @para: A pointer to the parameters structure.
 *
 * Return: The number of characters printed.
 */
int print_hex(va_list zp, parat *para)
{
	char *str;
	int c = 0;
	unsigned long l;

	if (para->lzby)
		l = va_arg(zp, unsigned long);
	else if (para->hzby)
		l = (unsigned short int)va_arg(zp, unsigned int);
	else
		l = (unsigned int)va_arg(zp, unsigned int);

	str = convert(l, 16, CONV_UNSIGNED | CONV_LOWERCASE, para);
	if (para->hashf && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	para->unsign = 1;
	return (c += print_number(str, para));
}

/**
 * print_HEX - Prints an unsigned integer as a hexadecimal number in uppercase.
 * @zp: A va_list containing the argument to print.
 * @para: A pointer to the parameters structure.
 *
 * Return: The number of characters printed.
 */
int print_HEX(va_list zp, parat *para)
{
	char *str;
	int c = 0;
	unsigned long l;

	if (para->lzby)
		l = (unsigned long)va_arg(zp, unsigned long);
	else if (para->hzby)
		l = (unsigned short int)va_arg(zp, unsigned int);
	else
		l = (unsigned int)va_arg(zp, unsigned int);

	str = convert(l, 16, CONV_UNSIGNED, para);
	if (para->hashf && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	para->unsign = 1;

	return (c += print_number(str, para));
}

/**
 * print_binary - Prints an unsigned integer as a binary number.
 * @zp: A va_list containing the argument to print.
 * @para: A pointer to the parameters structure.
 *
 * Return: The number of characters printed.
 */
int print_binary(va_list zp, parat *para)
{
	int c = 0;
	unsigned int n = va_arg(zp, unsigned int);
	char *str = convert(n, 2, CONV_UNSIGNED, para);

	if (para->hashf && n)
		*--str = '0';
	para->unsign = 1;

	return (c += print_number(str, para));
}

/**
 * print_octal - Prints an unsigned integer as an octal number.
 * @zp: A va_list containing the argument to print.
 * @para: A pointer to the parameters structure.
 *
 * Return: The number of characters printed.
 */
int print_octal(va_list zp, parat *para)
{
	int c = 0;
	unsigned long l;
	char *str;

	if (para->lzby)
		l = (unsigned long)va_arg(zp, unsigned long);
	else if (para->hzby)
		l = (unsigned short int)va_arg(zp, unsigned int);
	else
		l = (unsigned int)va_arg(zp, unsigned int);

	str = convert(l, 8, CONV_UNSIGNED, para);

	if (para->hashf && l)
		*--str = '0';
	para->unsign = 1;

	return (c += print_number(str, para));
}
