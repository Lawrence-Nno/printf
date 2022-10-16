#include "main.h"

/**
 * __atoi - This function converts string to number
 * @s: THe string to read
 * @n: Position the number starts to read
 * Return: Returns the parsed number
 */

int __atoi(const char *s, int n)
{
	int number, i;

	i = number = 0;
	while (s[n + i] <= '9' && s[n + i] >= '0')
	{
		if (i > 0)
			number *= 10;
		number += s[n + i] - '0';
		i++;
	}
	return (number);
}

/**
 * str_len - Finds the string length
 * @str: The pointer to the string length
 * Return: Returns length of string
 */

int str_len(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/**
 * _revstr - Finds the string length
 * @s: pointer to the string
 * Return: length of string
 */

void _revstr(char *s)
{
	int len, i;
	char tmp;

	i = 0;
	len = str_len(s) - 1;
	while (i <= len / 2)
	{
		tmp = s[len - i];
		s[len - i] = s[i];
		s[i++] = tmp;
	}
}
