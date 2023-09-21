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
