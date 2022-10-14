#include "main.h"

/**
 * print_string - This function prints a string
 * @list: The valist
 * Return: Returns the string length
 */

int print_string(va_list list)
{
	char *ptr;
	int ptr_len;

	ptr = va_arg(list, char*);
	ptr_len = print((ptr != NULL) ? ptr : "(null)");
	return (ptr_len);
}
