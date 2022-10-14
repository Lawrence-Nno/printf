#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
int bf(char c);
int manage(const char *str, va_list list);
int manage_percent(const char *str, va_list list, int *i);
int _strlen(const char *str);
int print_char(va_list list);
int print_string(va_list list);
int print(char *str);

/**
 * struct _format - A struct
 * @type: The format
 * @f: The associated function
 */
typedef struct _format
{
	char type;
	int (*f)(va_list);
} format;

#endif /* _MAIN_H_ */
