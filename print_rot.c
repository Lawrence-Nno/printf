#include "main.h"

/**
 * rot13 - This function encodes a string using rot13
 * @s: The string to encode
 * Return: Returns the encoded string
 */

int rot13(char *s)
{
	int a, b;
	char *usual, *rot13;

	usual = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	rot13 = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	for (a = 0; s[a] != '\0'; a++)
	{
		for (b = 0; usual[b] != '\0'; b++)
		{
			if (s[a] == usual[b])
			{
				_putchar(rot13[b]);
				break;
			}
		}
		if (!usual[b])
			_putchar(s[a]);
	}
	return (a);
}

/**
 * print_rot - This function prints the rot13 string
 * @list: The string to encode
 * Return: The length of the encoded string
 */

int print_rot(va_list list)
{
	char *ptr;
	int ptr_len;

	ptr = va_arg(list, char *);
	ptr_len = rot13((p != NULL) ? ptr : "(ahyy)");

	return (ptr_len);
}
