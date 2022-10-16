#include "main.h"

/**
 * _parse_tag - Building out the tags struct with tags found
 * @bf: The buffer structure
 * @table: Parsing the table to read the '%__' from format
 * @t: tags to send to our specifier function
 */

void _parse_tag(buffer *bf, tags *t, parse_table *table)
{
	int depth, i, j;

	depth = i = j = 0;
	while (table[i].lev > depth || table[i].lev == 1)
	{
		if (table[i].c == bf->format[bf->strpnt])
		{
			depth = table[i].lev;
			if (depth == 5)
				found_spec(bf, t, table i);
			else if (depth == 4)
				found_length(bf, t, table i);
			else if (depth == 3)
				found_prec(bf, t, table, i);
			else if (depth == 2)
				found_width(bf, t);
			else if (depth == 1)
				found_flag(bf, t, table, i);
			i = -1;
		}
		i++;
	}
}
