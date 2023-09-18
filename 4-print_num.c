#include "main.h"

/**
 * _isdigit - if a character is a digit.
 * @c: Check the character.
 *
 * Return: 1 if c is a digit, 0 otherwise.
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - Calculates the length of a string.
 * @s: The string to calculate the length of.
 *
 * Return: The length of the string.
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s++)
		i++;

	return (i);
}

/**
 * print_number - Prints a formatted number.
 * @str: The number as a string.
 * @para: A pointer to the parameters structure.
 *
 * Return: The number of characters printed.
 */
int print_number(char *str, parat *para)
{
	unsigned int i = _strlen(str);
	int neg = (!para->unsign && *str == '-');

	if (!para->prec && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (para->prec != UINT_MAX)
		while (i++ < para->prec)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!para->minusf)
		return (print_number_right_shift(str, para));
	else
		return (print_number_left_shift(str, para));
}

/**
 * print_number_right_shift - Prints a right-justified formatted number.
 * @str: The number as a string.
 * @para: A pointer to the parameters structure.
 *
 * Return: The number of characters printed.
 */
int print_number_right_shift(char *str, parat *para)
{
	char pad_char = ' ';
	unsigned int n = 0, neg, neg2, i = _strlen(str);

	if (para->zerof && !para->minusf)
		pad_char = '0';
	neg = neg2 = (!para->unsign && *str == '-');
	if (neg && i < para->width && pad_char == '0' && !para->minusf)
		str++;
	else
		neg = 0;
	if ((para->plusf && !neg2) ||
			(!para->plusf && para->spacef && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (para->plusf && !neg2 && pad_char == '0' && !para->unsign)
		n += _putchar('+');
	else if (!para->plusf && para->spacef && !neg2 &&
			!para->unsign && para->zerof)
		n += _putchar(' ');
	while (i++ < para->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (para->plusf && !neg2 && pad_char == ' ' && !para->unsign)
		n += _putchar('+');
	else if (!para->plusf && para->spacef && !neg2 &&
			!para->unsign && !para->zerof)
		n += _putchar(' ');
	n += _puts(str);

	return (n);
}

/**
 * print_number_left_shift - Prints a left-justified formatted number.
 * @str: The number as a string.
 * @para: A pointer to the parameters structure.
 *
 * Return: The number of characters printed.
 */
int print_number_left_shift(char *str, parat *para)
{
	char pad_char = ' ';
	unsigned int n = 0, neg, neg2, i = _strlen(str);

	if (para->zerof && !para->minusf)
		pad_char = '0';
	neg = neg2 = (!para->unsign && *str == '-');
	if (neg && i < para->width && pad_char == '0' && !para->minusf)
		str++;
	else
		neg = 0;

	if (para->plusf && !neg2 && !para->unsign)
		n += _putchar('+'), i++;
	else if (para->spacef && !neg2 && !para->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < para->width)
		n += _putchar(pad_char);

	return (n);
}
