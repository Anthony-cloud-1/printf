#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * print_hex - Prints an unsigned integer in hexadecimal format.
 * @n: The unsigned integer to print.
 * @uppercase: Whether to print uppercase (1) or lowercase (0) hex letters.
 *
 * Return: The number of characters printed.
 */
int print_hex(unsigned int n, int uppercase)
{
	int count = 0;
	char hex_chars[] = "0123456789abcdef";

	if (uppercase)
		hex_chars[10] = 'A';

	if (n / 16)
		count += print_hex(n / 16, uppercase);

	putchar(hex_chars[n % 16]);
	count++;

	return (count);
}

/**
 * print_ptr - Prints a pointer address.
 * @ptr: The pointer to print.
 *
 * Return: The number of characters printed.
 */
int print_ptr(void *ptr)
{
	int count = 0;
	unsigned long int p = (unsigned long int)ptr;

	putchar('0');
	putchar('x');
	count += 2;

	count += print_hex(p, 1);

	return (count);
}

/**
 * print_binary - Prints an unsigned integer in binary format.
 * @n: The unsigned integer to print.
 *
 * Return: The number of characters printed.
 */
int print_binary(unsigned int n)
{
	int count = 0;

	if (n / 2)
		count += print_binary(n / 2);

	putchar((n % 2) + '0');
	count++;

	return (count);
}

/**
 * print_custom_string - Prints a string with non-printable characters escaped.
 * @str: The string to print.
 *
 * Return: The number of characters printed.
 */
int print_custom_string(char *str)
{
	int count = 0;

	if (str == NULL)
		str = "(null)";

	while (*str)
	{
		if ((*str >= 1 && *str <= 31) || *str >= 127)
		{
			_putchar('\\');
			_putchar('x');
			count += 2;
			count += print_hex(*str, 1);
		}
		else
		{
			_putchar(*str);
			count++;
		}
		str++;
	}

	return (count);
}
