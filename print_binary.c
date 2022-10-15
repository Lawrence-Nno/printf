#include "main.h"

/**
 * print_binary - This function prints an integer in base 2
 * @list: The integer to print in base 2
 * Return: Returns the size of the numbers in base 2
 */

int print_binary(va_list list)
{
	char *ptr_bf;
	int size;

	ptr_bf = itoa(va_arg(list, unsigned int), 2);
	size = print(ptr_bf);
	return (size);
}
