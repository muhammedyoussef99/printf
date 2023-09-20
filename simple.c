#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

/**
 * print_from_to - print range of chars addresses
 * @start: start the address
 * @stop: stop the address
 * @except: except the address
 * Return: number of bytes to print
*/

int print_from_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * print_rev - print the string in reverse
 * @zp: a string
 * @para: parameters struction
 * Return: number of bytes to print
*/

int print_rev(va_list zp, parat *para)
{
	int len, sum = 0;
	char *str = va_arg(zp, char *);

	(void)para;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}

/**
 * print_rot13 - print string in rot13
 * @zp: a string
 * @para: parameters struction
 * Return: number of bytes to print
*/

int print_rot13(va_list zp, parat *para)
{
	int i, index;
	int count = 0;
	char arr[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(zp, char *);
	(void)para;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(arr[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
