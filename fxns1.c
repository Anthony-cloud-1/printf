#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * print_string - Prints a string and handles non-printable characters.
 * @str: The string to print.
 *
 * Return: The number of characters printed.
 */
int print_string(const char *str)
{
	int count = 0;

	while (*str)
	{
		if (*str >= 32 && *str < 127)
		{
			putchar(*str);
			count++;
		}
		else
		{
			putchar('\\');
			putchar('x');
			if (*str < 16)
			{
				putchar('0');
				count++;
			}
			count += 2;
			count += print_hex(*str);
		}
		str++;
	}

	return (count);
}

/**
 * print_hex - Prints a hexadecimal value.
 * @value: The value to print in hexadecimal.
 *
 * Return: The number of characters printed.
 */
int print_hex(int value)
{
	int count = 0;
	char hex_chars[] = "0123456789ABCDEF";

	if (value < 16)
	{
		putchar(hex_chars[value]);
		count++;
	}
	else
	{
		count += print_hex(value / 16);
		putchar(hex_chars[value % 16]);
		count++;
	}

	return (count);
}

/**
 * print_integer - Prints a signed integer.
 * @num: The integer to print.
 *
 * Return: The number of characters printed.
 */
int print_integer(int num)
{
	int count = 0;

	if (num < 0)
	{
		putchar('-');
		count++;
		num = -num;
	}

	count += print_unsigned((unsigned int)num);

	return (count);
}

/**
 * print_unsigned - Prints an unsigned integer.
 * @num: The unsigned integer to print.
 *
 * Return: The number of characters printed.
 */
int print_unsigned(unsigned int num)
{
	int count = 0;

	if (num == 0)
	{
		putchar('0');
		count++;
	}
	else
	{
		count += print_unsigned_recursive(num);
	}

	return (count);
}
