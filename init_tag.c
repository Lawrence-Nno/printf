#include "main.h"

/**
 * init_tag - This function initializes tag for parsing
 * @t: tags struct to fill in with tags
 */

void init_tag(tags *t)
{
	/*Initializes tag to default values*/
	t->spec = '\0';
	t->len = '\0';
	t->prec = -1;
	t->width = -1;
	t->flags[0] = '\0', t->flags[1] = '\0', t->flags[2] = '\0';
	t->flags[3] = '\0', t->flags[4] = '\0', t->flags[5] = '\0';
}

/**
 * init_buffer - This func initializes the buffer structure
 * @bf: A copy of the buffer address
 * @format: a copy of the format we will pasrse into
 */

void init_buffer(buffer *bf, const char *format)
{
	bf->format = format;
	bf->buff = malloc(1024);
	bf->tmpbuff = malloc(512);
	bf->strpnt = 0;
	bf->buffpnt = 0;
	bf->tmppnt = 0;
	bf->printed = 0;
}
