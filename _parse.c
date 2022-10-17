#include "main.h"

/**
 * _parse - Take strings from % and parse tags into correct string for buffer
 * @bf: The buffer structure
 */

void _parse(buffer *bf)
{
	int i;
	tags t;
	parse table[] = {
		{'d', 5, _spec_d}, {'i', 5, _spec_d}, {'c', 5, _spec_c},
		{'s', 5, _spec_s}, {'u', 5, _spec_u}, {'o', 5, _spec_o},
		{'x', 5, _spec_x}, {'X', 5, _spec_X}, {'b', 5, _spec_b},
		{'S', 5, _spec_S}, {'p', 5, _spec_p}, {'R', 5, _spec_R},
		{'r', 5, _spec_r}, {'%', 5, _spec_pct},
		/* when no specifier is found */ {'\0', 5, _spec_nil},

		{'h', 4, _error}, {'l', 4, _error}, {'.', 3, _error},
		{'1', 2, _error}, {'2', 2, _error}, {'3', 2, _error},
		{'4', 2, _error}, {'5', 2, _error}, {'6', 2, _error},
		{'7', 2, _error}, {'8', 2, _error}, {'9', 2, _error},
		{'-', 1, _error}, {'+', 1, _error}, {' ', 1, _error},
		{'#', 1, _error}, {'0', 1, _error},
		/* End of Table */ {'\0', -1, _error}
	};

	/* We will only parse at %! */
	if (bf->format[bf->strpnt] != '%')
		write(1, "Error: Don't parse when not at '%'\n", 35);
	bf->tmppnt = 0;
	bf->tmpbuff[bf->tmppnt++] = '%';
	bf->strpnt++;

	init_tag(&t);
	_parse_tag(bf, &t, table);

	/* Calling the specifier function matching the specifier found */
	i = 0;
	while (table[i].lev == 5)
	{
		if (table[i].c == t.spec)
			table[i].spec_func(bf, &t);
		i++;
	}
	i = 0;
}
