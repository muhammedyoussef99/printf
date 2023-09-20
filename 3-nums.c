#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * convert - Converts a number to a specified base and format.
 * @num: The number to convert.
 * @base: The base for conversion (e.g., 10 for decimal, 16 for hexadecimal).
 * @fl: Flags to control the conversion (e.g., CONVERT_UNSIGNED).
 * @para: A pointer to the parameters structure (not used in this function).
 *
 * Return: A string containing the converted number.
 */
char *convert(long int num, int base, int fl, parat *para)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)para;

	if (!(fl & CONV_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = fl & CONV_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;

	return (ptr);
}

/**
 * print_unsigned - Prints an unsigned number in decimal format.
 * @zp: A va_list containing the argument to print.
 * @para: A pointer to the parameters structure.
 *
 * Return: The number of characters printed.
 */
int print_unsigned(va_list zp, parat *para)
{
	unsigned long l;

	if (para->lzby)
		l = (unsigned long)va_arg(zp, unsigned long);
	else if (para->hzby)
		l = (unsigned short int)va_arg(zp, unsigned int);
	else
		l = (unsigned int)va_arg(zp, unsigned int);
	para->unsign = 1;

	return (print_number(convert(l, 10, CONV_UNSIGNED, para), para));
}

/**
 * print_address - Prints a memory address in hexadecimal format.
 * @zp: A va_list containing the argument to print.
 * @para: A pointer to the parameters structure.
 *
 * Return: The number of characters printed.
 */
int print_address(va_list zp, parat *para)
{
	unsigned long int n = va_arg(zp, unsigned long int);
	char *str;

	if (!n)
		return (_puts("(nil)"));

	str = convert(n, 16, CONV_UNSIGNED | CONV_LOWERCASE, para);
	*--str = 'x';
	*--str = '0';

	return (print_number(str, para));
}
