#include "main.h"

/**
 * _strlen - This function calculates the length of a string
 * @str: The string
 * Return: Returns the length
 */

int _strlen(const char *str)
{
	int i;

	for (i = 0; str[i] != 0; i++)
		;
	return (i);
}
