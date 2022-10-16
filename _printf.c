#include "main.h"

/**
 * _printf - This is our personal recreation of printf
 * @format: This the formatted strint to stdout
 * Return: Returns number of characters written
 */

int _printf(const char *format, ...)
{
	/* creating buffer structure and initializing */
	buffer bf;

	_init_buffer(&bf, format);
	va_start(bf.addrpnt, format);

	while (bf.format[bf.strpnt] != '\0')
	{
		_copy(&bf);
		if (bf.format[bf.strpnt] != '\0')
			_parse(&bf);
	}
	/* Writing buffer to stdout */
	if (bf.buffpnt > 0)
		write(1, bf.buff, bf.buffpnt);
	bf.printed += bf.buffpnt;

	va_end(bf.addrpnt);
	free(bf.buff);
	free(bf.tmpbuff);
	return (bf.printed);
}
