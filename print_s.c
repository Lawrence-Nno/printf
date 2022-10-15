#include "main.h"

/**
 * print_S - prints a string and nonprintable character ASCII
 * @S: The string to print
 * Return: Returns number of characters printed
 */

int print_s(va_list s)
{
	unsigned int i;
	int count = 0;
	char *str = va_arg(s, char *);

	if (str == NULL)
		str = "(null)";
	for (i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			count += 2;
			count += print_hexadecimal_upp(str[i]);
		}
		else
		{
			_putchar(str[i]);
			count++;
		}
	}
	return (count);
}
