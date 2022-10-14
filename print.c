#include "main.h"

/**
 * print - This function prints a string
 * @str: The string to print
 * Return: Returns the length of the string
 */

int print(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; ++i)
		_putchar(str[i]);
	return (i);
}
