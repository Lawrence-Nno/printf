#include "main.h"

/**
 * _putchar - This function writes a character to standard out stdout
 * @c: The character to write to stdout
 * Return: Returns 1 if successful or -1 if otherwise
 */

int _putchar(char c)
{
	return (bf(c));
}

/**
 * bf - Saves a character in a buffer
 * @c: The character to save
 *
 * Return: Returns 1 if successful
 */

int bf(char c)
{
	static char buffer[1024];
	static int i;

	if (c == -1 || i == 1024)
	{
		write (1, buffer, i);
		i = 0;
	}
	if (c != -1)
		buffer[i++] = c;
	return (1);
}
