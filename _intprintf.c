#include "main.h"
/**
 * print_integer - Print an integer
 * @n: The integer to print
 *
 * Return: Number of characters printed
 */
int print_integer(int n)
{
	char buffer[12]; 
	int printed_chars = 0;
	int is_negative = 0;

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}

	int i = 0;

	while (n > 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}

	if (is_negative)
		buffer[i++] = '-';

	for (int j = i - 1; j >= 0; j--)
	{
		write(1, &buffer[j], 1);
		printed_chars++;
	}

	return (printed_chars);
}
