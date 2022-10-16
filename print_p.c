#include "main.h"
#include <stdio.h>
/**
 * _spec_p - sends va_arg with appropirate tags into buffer
 * @bf: a pointer to the struct buffer
 * @t: a pointer to the struct tags
 */
void _spec_p(buffer *bf, tags __attribute__((unused))(*t))
{
	size_t hold;
	char *s;
	int i;

	s = va_arg(bf->addrpnt, void *);

	if (s == NULL)
	{
		s = "(nil)";
		for (i = 0; s[i] != '\0'; i++)
			_write(bf, s[i]);
	}
	else
	{
		hold = (size_t)s;
		s = _uint_to_hexstr(hold);

		_write(bf, '0');
		_write(bf, 'x');

		for (i = 0; s[i] != '\0'; i++)
			_write(bf, s[i]);
		free(s);
	}
}
