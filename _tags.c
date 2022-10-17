#include "main.h"

/**
 * _spec_num_help - This func applies the appropriate tags to a number
 * @bf: pointer pointing to struct buffer
 * @t: pointer, points to the struct tag
 * @num_str: points to a number converted to a string
 * @minus: indicates if number is minus
 */

void _spec_num_help(buffer *bf, tags *t, char *num_str, int minus)
{
	int i, j, k, s_len;
	char *tmp_str;
	char *buf_str;
	char front[] = "\0\0\0";

	tmp_str = num_str;
	s_len = str_len(num_str);
	tmp_str = check_prec(tmp_str, num_str, t, s_len);

	get_sign(t, minus, front);
	if ((str_len(front) + str_len(tmp_str)) < t->width)
	{
		buf_str = malloc(t->width * sizeof(char));
		_out_of_time(buf_str, tmp_str, front, t);
	}
	else
	{
		buf_str = malloc((str_len(tmp_str) + 1 + str_len(front)) * sizeof(char));
		k = i = 0;
		while (front[k] != '\0')
			buf_str[k] = front[k], k++;
		while (k < (str_len(tmp_str) + str_len(front)))
			buf_str[k++] = tmp_str[i++];
		buf_str[k] = '\0';
	}
	for (j = 0; j < str_len(buf_str); j++)
		_write(bf, buf_str[j]);
	free(buf_str);
}

/**
 * get_sign - adds sign to the the front string
 * @t: struct tag
 * @minus: minus sign
 * @front: The char to store the sign
 */

void get_sign(tags *t, int minus, char *front)
{
	if(t->spec == 'd' || t->spec == 'i' || t->spec == 'p')
	{
		if (minus == 1)
			front[0] = '-';
		else if (_isFlagPlus(t) == 1)
			front[0] = '+';
		else if (_isFlagSpace(t) == 1)
			front[0] = ' ';
	}
	else if ((t->spec == 'o' || t->spec == 'X' || t->spec == 'x') &&
			_isFlagHashtag(t) == 1)
	{
		front[0] = '0';
		if (t->spec == 'X')
			front[1] = 'X';
		else if (t->spec == 'x')
			front[1] = 'x';
	}
}

/**
 * check_prec - Checks if there is prec and remove 0 flag
 * @tmp_str: pointer to tmp_str
 * @num_str: Points to the number string
 * @t: struct tag
 * @s_len: Length of num_str
 * Return: points to tmp_str
 */

char *check_prec(char *tmp_str, char *num_str, tags *t, int s_len)
{
	int i, j, l;

	j = l = 0;
	if (t->prec != -1)
	{
		for (i = 0; t->flags[i] != '\0'; i++)
		{
			if (t->flags[i] == '1')
				t->flags[i] = '2';
		}
		if (t->prec > s_len)
		{
			tmp_str = malloc(t->prec * sizeof(char));
			while (j < (t->prec - s_len))
			{
				tmp_str[j++] = '0';
			}
			while (j < t->prec)
			{
				tmp_str[j++] = num_str[l++];
			}
		}
	}
	return (tmp_str);
}

/**
 * _out_of_time - applies the format tags to and pushes to buf_str
 * @buf_str: empty string to be filled
 * @tmp_str: prec format tag + the num_to_str
 * @front: sign for num_to_str
 * @t: points to struct tag
 */

void _out_of_time(char *buf_str, char *tmp_str, char *front, tags *t)
{
	int i, k;

	i = k = 0;
	if (_isFlagZero(t) == 1 && _isFlagMinus(t) == 0)
	{
		while (front[k] != '\0')
			buf_str[k] = front[k], k++;
		while (k < (t->width - str_len(tmp_str) - str_len(front)))
		{
			buf_str[k++] = '0';
		}
		while (k < t->width)
			buf_str[k++] = tmp_str[i++];
	}
	else if (_isFlagMinus(t) == 1)
	{
		while (front[k] != '\0')
			buf_str[k] = front[k], k++;
		while (k < str_len(tmp_str) + str_len(front))
			buf_str[k++] = tmp_str[i++];
		while (k < t->width)
			buf_str[k++] = ' ';
	}
	else
	{
		while (k < (t->width - str_len(tmp_str) -
					str_len(front + 1)))
			buf_str[k++] = ' ';
		while (front[k] != '\0')
			buf_str[k] = front[k], k++;
		while (k < (t->width))
				buf_str[k++] = tmp_str[i++];
	}
	buf_str[k] = '\0';
}
