#include "main.h"

/**
 * itoa - This function converts an integer to ascii
 * @num: The number to convert
 * @base: The base to convert to
 * Return: Returns a pointer to the converted number
 */

char *itoa(long int num, int base)
{
	static char *array = "0123456789abcdef";
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (num < 0)
	{
		n = -num;
		sign = '-';
	}
	ptr = &buffer[49];
	*ptr = '\0';

	do 
	{
		*--ptr = array[n % base];
		n /= base;
	}
	while (n != 0);
	if (sign)
		*--ptr = sign;
	return (ptr);
}
