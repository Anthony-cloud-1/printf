#include <limits.h>
#include <stdio.h>
#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - Custom printf function
 * @format: The format string
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;


	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					{
						char c = va_arg(args, int);

						write(1, &c, 1);
						printed_chars++;
						break;
					}

				case 's':
					{
						char *str = va_arg(args, char *);
						int i = 0;

						while (str[i])
						{
							write(1, &str[i], 1);
							printed_chars++;
							i++;
						}
						break;
					}

				case 'i':
					{
						int num = va_arg(args, int);
						printed_chars += print_integer(num);
						break;
					}

				case 'd':
					{
						int num = va_arg(args, int);
						printed_chars += print_integer(num);
						break;
					}

				case '%':
					write(1, "%", 1);
					printed_chars++;
					break;

				default:
					write(1, "%", 1);
					write(1, format, 1);
					printed_chars += 2;
					break;
			}
		}
		else
		{
			write(1, format, 1);
			printed_chars++;
		}
		format++;
	}

	va_end(args);
	return (printed_chars);
}
/**
 * print_integer - Print an integer
 * @n: The integer to print
 * Return: Number of characters printed
 */
int print_integer(int n)
{
	char buffer[12];
	int printed_chars = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	int i = 0;
	int is_negative = 0;

	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}

	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}

	if (is_negative)
	{
		buffer[i++] = '-';
	}

	for (int j = i - 1; j >= 0; j--)
	{
		write(1, &buffer[j], 1);
		printed_chars++;
	}

	return (printed_chars);
}
