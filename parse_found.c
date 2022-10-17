#include "main.h"

/**
 * found_spec - Puts the correct items in the tags t struct for found spec
 * @bf: buffer struct
 * @t: tags struct
 * @table: parse table
 * @i: how far into the table we are
 */
void found_spec(buffer *bf, tags *t, parse *table, int i)
{
	t->spec = table[i].c;
	bf->tmpbuff[bf->tmppnt++] = table[i].c;
	bf->strpnt++;
}

/**
 * found_length - Puts the correct items in the tags t struct for found spec
 * @bf: buffer struct
 * @t: tags struct
 * @table: parse table
 * @i: how far into the table we are
 */

void found_length(buffer *bf, tags *t, parse *table, int i)
{
	t->len = table[i].c;
	bf->tmpbuff[bf->tmppnt++] = table[i].c;
	bf->strpnt++;
}

/**
 * found_prec - Puts the correct items in the tags t struct for found spec
 * @bf: buffer struct
 * @t: tags struct
 * @table: parse table
 * @i: how far into the table we are
 */

void found_prec(buffer *bf, tags *t, parse *table, int i)
{
	int tmp, j, len;
	char *s;

	bf->strpnt++;
	bf->tmpbuff[bf->tmppnt++] = table[i].c;
	tmp = t->prec = __atoi(bf->format, bf->strpnt);
	/* must include i to s here to put in t->scanned */
	s = _int_to_str(tmp);
	len = str_len(s);
	for (j = 0; j < len; j++)
		bf->tmpbuff[bf->tmppnt++] = s[j];
	while (tmp)
	{
		tmp /= 10;
		bf->strpnt++;
	}
	free(s);
}

/**
 * found_width - Puts the correct items in the tags t struct for found spec
 * @bf: buffer struct
 * @t: tags struct
 */

void found_width(buffer *bf, tags *t)
{
	int tmp, j, len;
	char *s;

	tmp = t->width = __atoi(bf->format, bf->strpnt);
	/* must include i to s here to put in t->scanned */
	s = _int_to_str(tmp);
	len = str_len(s);
	for (j = 0; j < len; j++)
		bf->tmpbuff[bf->tmppnt++] = s[j];
	while (tmp)
	{
		tmp /= 10;
		bf->strpnt++;
	}
	free(s);
}

/**
 * found_flag - Puts the correct items in the tags t struct for found spec
 * @b_r: buffer struct
 * @t: tags struct
 * @table: parse table
 * @i: how far into the table we are
 */
void found_flag(buffer *bf, tags *t, parse *table, int i)
{
	int j;

	bf->tmpbuff[bf->tmppnt++] = table[i].c;
	j = 0;
	while (1)
	{
		if (table[i].c == '0')
		{
			if (t->flags[j] == '1')														break;
		}
		else
		{
			if (t->flags[j] == table[i].c)
				break;
		}
		if (t->flags[j] == '\0')
		{
			if (table[i].c == '0')
				t->flags[j] = '1';
			else
				t->flags[j] = table[i].c;
			break;
																	}
		j++;
	}
	bf->strpnt++;
}
