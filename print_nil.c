#include "main.h"
/**
 * _spec_nil - sends t.scanned into buffer
 * @bf: a pointer to the buffer
 */
void _spec_nil(buffer *bf)
{
	int i;

	/* if we started parsing but found end of string, print nothing */
	if (bf->string[bf->strpnt] != '\0')
	{
		for (i = 0; i < bf->tmppnt; i++)
			_write(bf, bf->tmpbuff[i]);
	}
	bf->tmppnt = 0;
}
