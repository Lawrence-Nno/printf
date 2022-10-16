#include "main.h"
/**
 * _spec_c - sends va_arg with appropriate tags into buffer
 * @bf: a pointer to the struct buffer
 * @t: a pointer to the struct tags
 */
void _spec_c(buffer *bf, tags *t)
{
	char hold;
	char *b_str;
	int i, j, b_str_size;

	/* get arg from va_arg and store */
	hold = va_arg(bf->addrpnt, int);
	/* if width if found */
	if (t->width > 1)
	{
		b_str_size = t->width;
		b_str = malloc(b_str_size * sizeof(char));
		i = 0;
		/*- flag found, hold left most */
		if (_isFlagMinus(t))
		{
			b_str[i++] = hold;
			while (i < b_str_size)
				b_str[i++] = ' ';
		}
		/* - flag not found, hold right most*/
		else
		{
			while (i < b_str_size - 1)
				b_str[i++] = ' ';
			b_str[i] = hold;
		}
	}
		/* no width given */
	else
		{
			b_str_size = 1;
			b_str = malloc(b_str_size * sizeof(char));
			b_str[0] = hold;
		}
	for (j = 0; j < b_str_size; j++)
		_write(bf, b_str[j]);
	free(b_str);
}
