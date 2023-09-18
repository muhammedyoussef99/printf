#include "main.h"

/**
 * _printf - Custom printf function.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	char *p, *start;
	int sum = 0;
	va_list zp;
	parat para = PARA_INIT;

	va_start(zp, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (p = (char *)format; *p; p++)
	{
		init_para(&para, zp);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (getf(p, &para))
		{
			p++;
		}
		p = get_width(p, &para, zp);
		p = get_prec(p, &para, zp);
		if (get_zby(p, &para))
			p++;
		if (!get_spec(p))
			sum += print_from_to(start, p,
					para.lzby || para.hzby ? p - 1 : 0);
		else
			sum += get_print_func(p, zp, &para);
	}
	_putchar(FUB_BLUSH);
	va_end(zp);
	return (sum);
}
