#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * print_octal - Prints an unsigned integer in octal format.
 * @num: The unsigned integer to print in octal.
 *
 * Return: The number of characters printed.
 */
int print_octal(unsigned int num)
{
	int count = 0;

	if (num == 0)
	{
		putchar('0');
		count++;
	}
	else
	{
		count += print_octal_recursive(num);
	}

	return (count);
}

/**
 * print_unsigned_recursive - Recursively prints an unsigned integer.
 * @num: The unsigned integer to print.
 *
 * Return: The number of characters printed.
 */
int print_unsigned_recursive(unsigned int num)
{
	int count = 0;

	if (num != 0)
	{
		count += print_unsigned_recursive(num / 10);
		putchar((num % 10) + '0');
		count++;
	}

	return (count);
}

/**
 * print_octal_recursive - Recursively prints an unsigned integer in octal.
 * @num: The unsigned integer to print in octal.
 *
 * Return: The number of characters printed.
 */
int print_octal_recursive(unsigned int num)
{
	int count = 0;

	if (num != 0)
	{
		count += print_octal_recursive(num / 8);
		putchar((num % 8) + '0');
		count++;
	}

	return (count);
}
