#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: A character string that specifies the format.
 * @...: Additional arguments corresponding to format specifiers.
 * Return: The number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	if (format && *format)
	{
		count = parse_format(format, args);
	}

	va_end(args);

	return (count);
}
