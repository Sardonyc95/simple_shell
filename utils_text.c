#include "text.h"

/**
 * _strlen - Return the length of a string
 *
 * @msg: String to calculate length
 *
 * Return: Length of the string
 **/
int _strlen(char *msg)
{
	int i;

	for (i = 0; msg[i] != '\0'; i++)
		;

	return (i);
}

/**
 * _strcat - Concatenates two strings
 *
 * @dest: String concatenate
 * @src: Source string
 *
 * Return: A string concatenate
 */
char *_strcat(char *dest, char *src)
{
	int l_dest, x;

	l_dest = _strlen(dest);

	for (x = 0; src[x] != '\0'; x++, l_dest++)
		dest[l_dest] = src[x];

	dest[l_dest] = '\0';

	return (dest);
}

/**
 * _strcpy - Copy a string to another
 *
 * @dest: Destination copy
 * @src: Source for copy
 *
 * Return: Return the value of dest
 */
char *_strcpy(char *dest, char *src)
{
	int p;

	for (p = 0; src[p] != '\0'; p++)
		dest[p] = src[p];

	dest[p] = '\0';

	return (dest);
}


/**
 * _strdup - Pointer to a newly allocated space in memory
 *
 * @str: String to copy
 *
 * Return: String copied
 **/
char *_strdup(char *str)
{
	int size, s;
	char *dest;

	if (str == NULL)
		return (NULL);

	size = _strlen(str) + 1;
	dest = malloc(size * sizeof(char));
	if (dest == NULL)
		return (NULL);

	for (s = 0; s < size; s++)
		*(dest + s) = *(str + s);

	/* (dest + s) = 0; */

	return (dest);
}

/**
 * _strcmp - Compare two strings
 *
 * @srg1: String 1
 * @srg2: String 2
 *
 * Return: Integer
 */
int _strcmp(char *srg1, char *srg2)
{
	int b;

	for (b = 0; srg1[b] != '\0'; b++)
	{
		if (srg1[b] != srg2[b])
			return (srg1[b] - srg2[b]);
	}

	return (0);
}
