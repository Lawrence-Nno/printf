#include "main.h"

/**
 * _copy - This func copies from format to buffer
 * @bf: This is the buffer structure
 */

void _copy(buffer *bf)
{
	while (bf->format[bf->strpnt] != '%' && bf->format[bf->strpnt] != '\0')
		_write(bf, bf->format[bf->strpnt]);
}
