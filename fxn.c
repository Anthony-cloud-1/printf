#include "main.h"
/**
 * print_char - Print a character
 * @args: The va_list containing the character to print
 *
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);
	return (_putchar(c));
}

/**
 * print_string - Print a string
 * @args: The va_list containing the string to print
 *
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int i = 0;
	int printed_chars = 0;

	if (str == NULL)
		str = "(null)";

	while (str[i])
	{
		printed_chars += _putchar(str[i]);
		i++;
	}

	return (printed_chars);
}

/**
 * print_percent - Print a percent character
 * @args: The va_list (not used)
 *
 * Return: Always returns 1 (the percent character)
 */
int print_percent(va_list args)
{
	(void)args;
	return (_putchar('%'));
}

/**
 * print_integer - Print an integer
 * @args: The va_list containing the integer to print
 *
 * Return: Number of characters printed
 */
int print_integer(va_list args)
{
	int n = va_arg(args, int);
	int printed_chars = 0;

	if (n < 0)
	{
		printed_chars += _putchar('-');
		n = -n;
	}

	printed_chars += print_unsgined_integer((unsigned int)n);

	return (printed_chars);
}
