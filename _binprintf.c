#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format != '\0')
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

				case '%':
					write(1, "%", 1);
					printed_chars++;
					break;

				case 'b':
					{
						unsigned int num = va_arg(args, unsigned int);

						printed_chars += print_binary(num);
						break;
					}

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
 * print_binary - Print an unsigned integer in binary format
 * @num: The unsigned integer to print
 * Return: Number of characters printed
 */
int print_binary(unsigned int num)
{
	int printed_chars = 0;
	int binary[32];

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	for (int i = 0; i < 32; i++)
	{
		binary[i] = num & 1;
		num >>= 1;
	}

	int leading_zeros = 1;

	for (int i = 31; i >= 0; i--)
	{
		if (binary[i] == 1)
			leading_zeros = 0;
		if (!leading_zeros)
		{
			char digit = binary[i] + '0';

			write(1, &digit, 1);
			printed_chars++;
		}
	}

	return (printed_chars);
}
