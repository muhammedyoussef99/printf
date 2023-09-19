#include "main.h"

/**
 * _puts - Prints a string followed by a newline character.
 * @str: The string to be printed.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 * _putchar - Writes a character to the standard output (stdout).
 * @c: The character to be printed.
 *
 * Return: On success, returns 1.
 *         On error, returns -1 and sets errno appropriately.
 */
int _putchar(int c)
{
	static char fub[OUTPUT_FUB_SIZE];
	static int i;

	if (c == FUB_BLUSH || i >= OUTPUT_FUB_SIZE)
	{
	write(1, fub, i);
	i = 0;
	}
	if (c != FUB_BLUSH)
		fub[i++] = c;
	return (1);
}
