#include "main.h"
/**
* _spec_b - sends va-arg with appropriat tags into buffer
* @bf: a pointer to the struct buffer
* @t: a pointer to the struct tags
*/
void _spec_b(buffer *bf, tags *t)
{
	unsigned int n_hold;
	char *num_str;

	n_hold = va_arg(bf->addrpnt, unsigned int);

	num_str = _uint_to_binstr(n_hold);
	_spec_num_help(bf, t, num_str, 0);
	free(num_str);
}
/**
* _spec_o - sends va-arg with appropriat tags into buffer
* @bf: a pointer to the struct buffer
* @t: a pointer to the struct tags
*/
void _spec_o(buffer *bf, tags *t)
{
	int n_hold;
	char *num_str;

	n_hold = va_arg(bf->addrpnt, int);

	num_str = _int_to_octstr(n_hold);
	_spec_num_help(bf, t, num_str, 0);
	free(num_str);
}
/**
* _spec_X - sends va-arg with appropriat tags into buffer
* @bf: a pointer to the struct buffer
* @t: a pointer to the struct tags
*/
void _spec_X(buffer *bf, tags *t)
{
	unsigned int n_hold;
	char *num_str;

	n_hold = va_arg(bf->addrpnt, unsigned int);

	num_str = _uint_to_caphexstr(n_hold);
	_spec_num_help(bf, t, num_str, 0);
	free(num_str);
}
/**
* _spec_x - sends va-arg with appropriat tags into buffer
* @bf: a pointer to the struct buffer
* @t: a pointer to the struct tags
*/
void _spec_x(buffer *bf, tags *t)
{
	unsigned int n_hold;
	char *num_str;

	n_hold = va_arg(bf->addrpnt, unsigned int);

	num_str = _uint_to_hexstr(n_hold);
	_spec_num_help(bf, t, num_str, 0);
	free(num_str);
}
/**
* _spec_u - sends va-arg with appropriat tags into buffer
* @bf: a pointer to the struct buffer
* @t: a pointer to the struct tags
*/
void _spec_u(buffer *bf, tags *t)
{
	unsigned int n_hold;
	char *num_str;

	n_hold = va_arg(bf->addrpnt, unsigned int);

	num_str = _uint_to_str(n_hold);
	_spec_num_help(bf, t, num_str, 0);
	free(num_str);
}
