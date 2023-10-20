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
	int q;

	for (q = 0; n != 0; q++, n /= 10)
		;

	return (q);
}

/**
 * to_string - Conver @number to string
 *
 * @number: Number to convert
 *
 * Return: Number as string
 **/
char *to_string(int number)
{
	int n_digits, i;
	char *_number;

	n_digits = digits(number);
	_number = malloc(n_digits * sizeof(char) + 2);
	if (number == 0)
	{
		_number[0] = '0';
		_number[1] = '\0';
		return (_number);
	}
	/* Check NULL */

	_number[n_digits] = '\0';
	for (i = n_digits - 1; number != 0; number /= 10, i--)
		_number[i] = (number % 10) + '0';

	return (_number);
}


/**
 * is_numerical - Check if is a digit
 *
 * @n: Number
 *
 * Return: If is a number, return 1 else return 0
 */
int is_numerical(unsigned int n)
{
	return (n >= '0' && n <= '9');
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
	unsigned int number, f;
	int sign;

	sign = 1;
	number = 0;
	for (f = 0; s[f] != '\0'; f++)
	{
		if (is_numerical(s[f]))
		{
			number = (s[f] - 48)	+ number * 10;

			if (s[f + 1] == ' ')
				break;
		}
		else if (s[f] == '-')
		{
			sign *= -1;
		}

	}

	return (number * sign);
}

/**
 * contains_letter - Search non-digits in a string
 *
 * @s: String for search
 *
 * Return: If a non-digits was found, return _TRUE
 * if not, return _FALSE
 **/
int contains_letter(char *s)
{
	int v;

	for (v = 0; s[v] != '\0'; v++)
	{
		if (is_numerical(s[i]) == _FALSE)
			return (_TRUE);
	}

	return (_FALSE);
}
