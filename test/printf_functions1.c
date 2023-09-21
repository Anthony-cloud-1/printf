#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing format specifiers.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	int i = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else
		{
			i++;
			if (format[i] == '\0')
				break;
			switch (format[i])
			{
				case 'c':
					count += print_char(va_arg(args, int));
					break;
				case 's':
					count += print_string(va_arg(args, char *));
					break;
				case 'd':
				case 'i':
					count += print_int(va_arg(args, int));
					break;
				case 'u':
					count += print_unsigned(va_arg(args, unsigned int));
					break;
				case 'o':
					count += print_octal(va_arg(args, unsigned int));
					break;
				case 'x':
					count += print_hex(va_arg(args, unsigned int), 0);
					break;
				case 'X':
					count += print_hex(va_arg(args, unsigned int), 1);
					break;
				case 'p':
					count += print_ptr(va_arg(args, void *));
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				case 'b':
					count += print_binary(va_arg(args, unsigned int));
					break;
				case 'S':
					count += print_custom_string(va_arg(args, char *));
					break;

				default:
					_putchar('%');
					_putchar(format[i]);
					count += 2;
			}
		}
		i++;
	}

	va_end(args);

	return (count);
}
