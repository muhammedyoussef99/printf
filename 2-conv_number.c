#include "main.h"

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
	int count = 0;
	unsigned long num;

	if (para->lzby)
		num = va_arg(zp, unsigned long);
	else if (para->hzby)
		num = (unsigned short int)va_arg(zp, unsigned int);
	else
		num = (unsigned int)va_arg(zp, unsigned int);

	str = convert(num, 16, CONV_UNSIGNED | CONV_LOWERCASE, para);
	if (para->hashf && num)
	{
		*--str = 'x';
		*--str = '0';
	}
	para->unsign = 1;
	return (count += print_number(str, para));
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
	int count = 0;
	unsigned long num;

	if (para->lzby)
		num = va_arg(zp, unsigned long);
	else if (para->hzby)
		num = (unsigned short int)va_arg(zp, unsigned int);
	else
		num = (unsigned int)va_arg(zp, unsigned int);

	str = convert(num, 16, CONV_UNSIGNED, para);
	if (para->hashf && num)
	{
		*--str = 'X';
		*--str = '0';
	}
	para->unsign = 1;

	return (count += print_number(str, para));
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
	int count = 0;
	unsigned int num = va_arg(zp, unsigned int);
	char *str = convert(num, 2, CONV_UNSIGNED, para);

	if (para->hashf && num)
		*--str = '0';
	para->unsign = 1;

	return (count += print_number(str, para));
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
	int count = 0;
	unsigned long num;
	char *str;

	if (para->lzby)
		num = va_arg(zp, unsigned long);
	else if (para->hzby)
		num = (unsigned short int)va_arg(zp, unsigned int);
	else
		num = (unsigned int)va_arg(zp, unsigned int);

	str = convert(num, 8, CONV_UNSIGNED, para);

	if (para->hashf && num)
		*--str = '0';
	para->unsign = 1;

	return (count += print_number(str, para));
}
