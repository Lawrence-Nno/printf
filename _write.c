#include "main.h"

/**
 * _write - Writes char to buffer amd reset if full
i * @bf: The buffer to write to
 * @c: The character to write
 */

void _write(buffer *bf, char c)
{
	if (bf->buffpnt == 1024)
	{
		write(1, bf->buff, bf->buffpnt);
		bf->printed += bf->buffpnt;
		bf->buffpnt = 0;
	}
	bf->buff[bf->buffpnt++] = c;
}

/*
 * _write_str - Writes string to buffer and reset if full
 * @bf: The buffer to write
 * @s: The string to write
 */

void _write_str(buffer *bf, char *s)
{
	while (*s != '\0')
	{
		if (bf->buffpnt == 1024)
		{
			write(1, bf->buff, bf->buffpnt);
			bf->printed += bf->buffpnt;
			bf->buffpnt = 0;
		}
		bf->buff[bf->buffpnt++] = *s++;
	}
}

/**
 * _write_tmpbuf - Adds tmpbuff to buffer, wite and reset if full
 * @bf: The Buffer to write
 */

void _write_tmpbuff(buffer *bf)
{
	int i;

	i = 0;
	while (i < bf->tmppnt)
	{
		if (bf->buffpnt == 1024)
		{
			write(1, bf->buff, bf->buffpnt);
			bf->printed += bf->buffpnt;
			bf->buffpnt = 0;
		}
		bf->buff[bf->buffpnt++] = bf->tmpbuff[i];
	}
}
