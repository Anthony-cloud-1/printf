#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * parse_format - Parses and prints the format string.
 * @format: The format string to parse.
 * @args: The va_list of arguments.
 *
 * Return: The number of characters printed.
 */
int parse_format(const char *format, va_list args)
{
	int count = 0;

	if (format == NULL)
		return (-1);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == '%')
			{
				_putchar('%');
				count++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(args, int);

				_putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);

				if (s == NULL)
					s = "(null)";
				count += print_string(s);
			}
			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);

				count += print_integer(num);
			}
			else if (*format == 'u')
			{
				unsigned int num = va_arg(args, unsigned int);

				count += print_unsigned(num);
			}
			else if (*format == 'o')
			{
				unsigned int num = va_arg(args, unsigned int);

				count += print_octal(num);
			}
			else if (*format == 'x' || *format == 'X')
			{
				unsigned int num = va_arg(args, unsigned int);

				count += print_hexadecimal(num, (*format == 'X'));
			}
			else if (*format == 'p')
			{
				void *ptr = va_arg(args, void *);

				count += print_pointer(ptr);
			}
			else if (*format == 'b')
			{
				unsigned int num = va_arg(args, unsigned int);

				count += print_binary(num);
			}
			else if (*format == 'S')
			{
				char *s = va_arg(args, char *);

				if (s == NULL)
					s = "(null)";
				count += print_custom_string(s);
			}

			format++;
		}
		else
		{
			_putchar(*format);
			count++;
			format++;
		}
	}

	return (count);
}
