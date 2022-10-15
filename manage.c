#include "main.h"

/**
 * manage - This function manages and controls the format
 * @str: The format of the String
 * @list: The List of arguments
 * Return: Returns the total size of arguments passed and
 * total size of the base string
 */

int manage(const char *str, va_list list)
{
	int size, i, y;

	size = 0;
	for (i = 0; str[i] != 0; i++)
	{
		if (str[i] == '%')
		{
			y = manage_percent(str, list, &i);
			if (y == -1)
				return (-1);
			size += y;
			continue;
		}
		_putchar(str[i]);
		size = size + 1;
	}
	return (size);
}

/**
 * manage_percent - the manager for percent format
 * @str: The format of the string
 * @list: List of arguments
 * @i: The Iterator
 * Return: Returns size of the numbers of elements printed
 */

int manage_percent(const char *str, va_list list, int *i)
{
	int size, j, number_formats;
	format formats[] = {
		{'s', print_string}, {'c', print_char}
		{'d', print_integer}, {'i', print_integer},
		{'b', print_binary}, {'u', print_unsigned},
		{'o', print_octal}, {'x', print_hexadecimal_low},
		{'X', print_hexadecimal_upp}, {'p', print_pointer},
		{'r', print_rev_string}, {'R', print_rot}
	};
	*i = *i + 1;

	if (str[*i] == '\0')
		return (-1);
	if (str[*i] == '%')
	{
		_putchar('%');
		return (1);
	}
	number_formats = sizeof(formats) / sizeof(formats[0]);
	for (size = j = 0; j < number_formats; j++)
	{
		if (str[*i] == formats[j].type)
		{
			size = formats[j].f(list);
			return (size);
		}
	}
	_putchar('%'), _putchar(str[*i]);
	return (2);
}
