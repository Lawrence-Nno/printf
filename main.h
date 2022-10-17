#ifndef _MAIN_H_
#define _MAIN_H_

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

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
        char flags[6];
} tags;

/**
 * struct parse_table - Table used for parsing the %s
 * @c: The character found
 * @lev: The level from 5 to 1
 * @spec_func: This function puts the matched spec into the buffer
 */

typedef struct parse_table
{
        char c;
        int lev;
        void (*spec_func)();
} parse;


/* prototpes for _printf */
int _printf(const char *format, ...);
void _copy(buffer *bf);
void _parse_tag(buffer *bf, tags *t, parse *table);
void _parse(buffer *bf);
void init_tag(tags *t);
void init_buffer(buffer *bf, const char *format);
void _error(void);
int _isFlagMinus(tags *t);
int _isFlagPlus(tags *t);
int _isFlagSpace(tags *t);
int _isFlagHashtag(tags *t);
int _isFlagZero(tags *t);
void _spec_b(buffer *bf, tags *t);
void _spec_o(buffer *bf, tags *t);
void _spec_X(buffer *bf, tags *t);
void _spec_x(buffer *bf, tags *t);
void _spec_u(buffer *bf, tags *t);
void _spec_c(buffer *bf, tags *t);
void _spec_d(buffer *bf, tags *t);
int num_len(int n);
void _spec_nil(buffer *bf);
void _spec_p(buffer *bf, tags __attribute__((unused))(*t));
void _spec_pct(buffer *bf);
void _spec_r(buffer *bf, tags *t);
void _spec_R(buffer *bf, tags *t);
void _to_rot13(char *s);
void _spec_s(buffer *bf, tags *t);
void _spec_S(buffer *bf, tags *t);
char *_str_whelp(tags *t, char *hold, int hold_len);
char *_to_hex_unreadable(char *hold);
char *_uint_to_str(unsigned long int n);
char *_uint_to_hexstr(unsigned long int n);
char *_uint_to_caphexstr(unsigned long int n);
char *_uint_to_octstr(unsigned long int n);
char *_uint_to_binstr(unsigned long int n);
char *_int_to_str(long int n);
char *_int_to_hexstr(long int n);
char *_int_to_caphexstr(long int n);
char *_int_to_octstr(long int n);
char *_int_to_binstr(long int n);
void _write(buffer *bf, char c);
void _write_str(buffer *bf, char *s);
void _write_tmpbuf(buffer *bf);
void _spec_num_help(buffer *bf, tags *t, char *num_str, int minus);
void get_sign(tags *t, int minus, char *front);
char *check_prec(char *tmp_str, char *num_str, tags *t, int s_len);
void _out_of_time(char *buf_str, char *tmp_str, char *front, tags *t);
int __atoi(const char *s, int n);
int str_len(char *str);
void _revstr(char *s);
void found_spec(buffer *bf, tags *t, parse *table, int i);
void found_length(buffer *bf, tags *t, parse *table, int i);
void found_prec(buffer *bf, tags *t, parse *table, int i);
void found_width(buffer *bf, tags *t);
void found_flag(buffer *bf, tags *t, parse *table, int i);


#endif /* _MAIN_H_ */
