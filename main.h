#ifndef _MAIN_H_
#define _MAIN_H_

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

/* prototpes for _printf */
int _printf(const char *format, ...);
void _copy(buffer *bf);
void _parse_tag(buffer *bf, tags *t, parse_table *table);
void _parse(buffer *bf);
void init_tag(tags *t);
void init_buffer(buffer *bf, const char *format);
void error_(void);
int _isFlagMinus(tags *t);
int _isFlagPlus(tags *t);
int _isFlagSpace(tags *t);
int _isFlagHashtag(tags *t);
int _isFlagZero(tags *t);

/**
 * struct buffer - The buffer structure for implementation of our printf
 * @buff: Buffer to write characters to
 * @tmpbuff: tmp buffer to write to before transfering to buffer
 * @string: The string passed to printf
 * @addrpnt: Variadic address point
 * @buffpnt: Current point in the buffer
 * @tmppnt: Current point in the tmp bufer
 * @strpnt: Current point in the string
 * @printed: THe number of chars printed from _write
 */

typedef struct buffer
{
	char *buff;
	char *tmpbuff;
	const char *format;
	va_list addrpnt;
	int buffpnt;
	int tmppnt;
	int strpnt;
	unsigned int printed;
} buffer;

/**
 * struct tags - Format tags after %
 * @spec: The specifier
 * @len: The length
 * @prec: The precision
 * @width: The width
 * @flag: The flags
 */

typedef struct tags
{
	char spec;
	char len;
	int prec;
	int width;
	char flag[6];
} tags;

/**
 * struct parse - Table used for parsing the %s
 * @c: The character found
 * @lev: The level from 5 to 1
 * @spec_func: This function puts the matched spec into the buffer
 */

typedef struct parse
{
	char c;
	int lev;
	void (*spec_func)();
} parse;

#endif /* _MAIN_H_ */
