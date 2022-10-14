#include "main.h"

/**
 * _printf - This functions displays a formatted output
 * @format: The format string
 * Return: Returns the number of characters inputted
 */

int _printf(const char *format, ...)
{
	int size;
	va_list argvs;

	if (format == NULL)
		return (-1);
	size = _strlen(format);
	if (size <= 0)
		return (0);
	va_start(argvs, format);
	size = manage(format, argvs);
	_putchar(-1);
	va_end(argvs);
	return (size);
}
