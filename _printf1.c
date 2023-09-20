#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
		{
			int num = va_arg(args, int);
			char buffer[12]; 

			count += _itoa(buffer, num);
			write(1, buffer, count);
			format += 2; 
			continue;
		}
		write(1, format, 1);
		count++;
		format++;
	}

	va_end(args);
	return (count);
}

/**
 * _itoa - Convert an integer to a string
 * @buffer: The destination buffer
 * @num: The integer to convert
 *
 * Return: The number of characters written to the buffer
 */
int _itoa(char *buffer, int num)
{
	int i = 0;

	if (num == 0)
	{
		buffer[i++] = '0';
	}
	else if (num < 0)
	{
		buffer[i++] = '-';
		num = -num;
	}

	while (num != 0)
	{
		buffer[i++] = num % 10 + '0';
		num /= 10;
	}

	buffer[i] = '\0';

	int start = 0;
	int end = i - 1;
	while (start < end)
	{
		char temp = buffer[start];
		buffer[start] = buffer[end];
		buffer[end] = temp;
		start++;
		end--;
	}

	return (i);
}
