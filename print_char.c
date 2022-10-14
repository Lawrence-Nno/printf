#include "main.h"

/**
 * print_char - prints a character
 * @list: The va_list
 * Return: Returns 1
 */

int print_char(va_list list)
{
	int y;

	y = va_arg(list, int);
	_putchar(y);
	return (1);
}
