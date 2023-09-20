#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/**
 * get_prec - Parses and retrieves
 *		the precision field from a format string.
 * @p: A pointer to the format string.
 * @para: A pointer to the parameters structure.
 * @zp: A va_list containing the arguments.
 *
 * Return: A pointer to the next character in the format string after parsing.
 */
char *get_prec(char *p, parat *para, va_list zp)
{
	int d = 0;

	if (*p != '.')

		return (p);
	p++;
	if (*p == '*')
	{
		d = va_arg(zp, int);
		p++;

	}
	else
	{
		while (_isdigit(*p))
			d = d * 10 + (*p++ - '0');
	}
	para->prec = d;

	return (p);
}
