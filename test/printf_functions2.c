#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * print_char - Prints a character.
 * @c: The character to print.
 *
 * Return: 1 (the number of characters printed).
 */
int print_char(int c)
{
	_putchar(c);
	return (1);
}

/**
 * print_string - Prints a string.
 * @str: The string to print.
 *
 * Return: The number of characters printed.
 */
int print_string(char *str)
{
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		_putchar(*str);
		str++;
		count++;
	}

	return (count);
}

/**
 * print_int - Prints an integer.
 * @n: The integer to print.
 *
 * Return: The number of characters printed.
 */
int print_int(int n)
{
	int count = 0;

	if (n < 0)
	{
		_putchar('-');
		count++;
		n = -n;
	}

	if (n / 10)
		count += print_int(n / 10);

	_putchar((n % 10) + '0');
	count++;

	return (count);
}

/**
 * print_unsigned - Prints an unsigned integer.
 * @n: The unsigned integer to print.
 *
 * Return: The number of characters printed.
 */
int print_unsigned(unsigned int n)
{
	int count = 0;

	if (n / 10)
		count += print_unsigned(n / 10);

	_putchar((n % 10) + '0');
	count++;

	return (count);
}

/**
 * print_octal - Prints an unsigned integer in octal format.
 * @n: The unsigned integer to print.
 *
 * Return: The number of characters printed.
 */
int print_octal(unsigned int n)
{
	int count = 0;

	if (n / 8)
		count += print_octal(n / 8);

	_putchar((n % 8) + '0');
	count++;

	return (count);
}
