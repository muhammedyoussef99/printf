#include "main.h"

/**
 * get_precision - Parses and retrieves
 *		the precision field from a format string.
 * @p: A pointer to the format string.
 * @para: A pointer to the parameters structure.
 * @zp: A va_list containing the arguments.
 *
 * Return: A pointer to the next character in the format string after parsing.
 */
char *get_precision(char *p, parat *para, va_list zp)
{
	int k = 0;

	if (*p != '.')

		return (p);
	p++;
	if (*p == '*')
	{
		k = va_arg(zp, int);
		p++;

	}
	else
	{
		while (_isdigit(*p))
			k = k * 10 + (*p++ - '0');
	}
	para->prec = k;

	return (p);
}
