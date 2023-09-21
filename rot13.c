#include "main.h"
#include <stdlib.h>

/**
 * print_R - prints a string in rot13
 * @R: string to print
 *
 * Return: number of chars printed
 */
int print_R(va_list R)
{
	char *str;
	unsigned int i, n;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(R, char *);
	if (str == NULL)
		str = "(ahyy)";
	for (i = 0; str[i]; i++)
	{
		for (n = 0; in[n]; n++)
		{
			if (in[n] == str[i])
			{
				_putchar(out[n]);
				count++;
				break;
			}
		}
		if (!in[n])
		{
			_putchar(str[i]);
			count++;
		}
	}
	return (count);
}
