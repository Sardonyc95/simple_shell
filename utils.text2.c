#include "general.h"
#include "text.h"

/**
 * digits - Cout the numbe of digits of a number
 *
 * @n: Number
 *
 * Return: Digits
 **/
int digits(int n)
{
	int m;

	for (m = 0; n != 0; m++, n /= 10)
		;

	return (m);
}

/**
 * to_a_string - Conver @number to string
 *
 * @num: Number to convert
 *
 * Return: Number as string
 **/
char *to_a_string(int num)
{
	int n_digits, i;
	char *_num;

	n_digits = digits(num);
	_num = malloc(n_digits * sizeof(char) + 2);
	if (num == 0)
	{
		_num[0] = '0';
		_num[1] = '\0';
		return (_num);
	}
	/* Check NULL */

	_num[n_digits] = '\0';
	for (i = n_digits - 1; num != 0; num /= 10, i--)
		_num[i] = (num % 10) + '0';

	return (_num);
}


/**
 * is_numerical - Check if is a digit
 *
 * @m: Number
 *
 * Return: If is a number, return 1 else return 0
 */
int is_numerical(unsigned int m)
{
	return (m >= '0' && m <= '9');
}

/**
 * _atoi - Convert a string to a number
 *
 * @s: String to convert
 *
 * Return: Return the number
 */
int _atoi(char *s)
{
	unsigned int num, i;
	int sign;

	sign = 1;
	num = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (is_numerical(s[i]))
		{
			num = (s[i] - 48)	+ num * 10;

			if (s[i + 1] == ' ')
				break;
		}
		else if (s[i] == '-')
		{
			sign *= -1;
		}

	}

	return (num * sign);
}

/**
 * contains_my_letter - Search non-digits in a string
 *
 * @c: String for search
 *
 * Return: If a non-digits was found, return _TRUE
 * if not, return _FALSE
 **/
int contains_my_letter(char *c)
{
	int v;

	for (v = 0; c[v] != '\0'; v++)
	{
		if (is_numerical(c[v]) == _FALSE)
			return (_TRUE);
	}

	return (_FALSE);
}
