#include <stdarg.h>
#include <unistd.h>
#include "main.h"

#define BUFF_SIZE 1024

/**
 * struct FormatSpec - Structure for holding format specifiers
 * @flag: Flag character
 * @width: Width specifier
 * @precision: Precision specifier
 * @length: Length modifier
 * @specifier: Conversion specifier
 */
typedef struct FormatSpec
{
	char flag;
	int width;
	int precision;
	char length;
	char specifier;
} FormatSpec;

int _printf(const char *format, ...);

int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_integer(va_list args);
int print_binary(va_list args);

int _putchar(char c);

/**
 * _printf - Custom printf function
 * @format: The format string
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	int i = 0;
	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			FormatSpec spec = {0};
			int spec_length = 0;

			/* Parse format specifier
			*/
			while (strchr("-0# +", format[i]))
			{
				if (spec_length < 1)
				{
					spec.flag = format[i];
					spec_length++;
				}
				i++;
			}

			/* Parse width specifier
			*/
			if (format[i] >= '0' && format[i] <= '9')
			{
				spec.width = 0;
				while (format[i] >= '0' && format[i] <= '9')
				{
					spec.width = spec.width * 10 + (format[i] - '0');
					i++;
				}
			}

			/* Parse precision specifier
			*/
			if (format[i] == '.')
			{
				i++;
				spec.precision = 0;
				while (format[i] >= '0' && format[i] <= '9')
				{
					spec.precision = spec.precision * 10 + (format[i] - '0');
					i++;
				}
			}

			/* Parse length specifier (ignored in this example)
			*/

			/* Parse conversion specifier
			*/
			if (strchr("cspdiobxX%", format[i]))
			{
				spec.specifier = format[i];
				i++;

				/* Call the corresponding print function based on the specifier
				*/
				switch (spec.specifier)
				{
					case 'c':
						printed_chars += print_char(args);
						break;
					case 's':
						printed_chars += print_string(args);
						break;
					case '%':
						printed_chars += print_percent(args);
						break;
					case 'd':
					case 'i':
						printed_chars += print_integer(args);
						break;
					case 'b':
						printed_chars += print_binary(args);
						break;
						/* Handle other specifiers here if needed
						*/
					default:
						printed_chars += _putchar('%');
						printed_chars += _putchar(spec.specifier);
						break;
				}
			}
		}
		else
		{
			printed_chars += _putchar(format[i]);
			i++;
		}
	}

	va_end(args);
	return printed_chars;
}
