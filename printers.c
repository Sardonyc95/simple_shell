#include "general.h"
#include "text.h"
#include <unistd.h>

/**
 * _putchar_to_sf - Print a character to a specific file
 * descriptor
 *
 * @c: Character to print
 * @sf: Place to print the character
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 **/
int _putchar_to_sf(char c, int sf)
{
	return (write(sf, &c, 1));
}


/**
 * print_to_sf - Print a string
 *
 * @msg: Strin to print in the sf specified
 * @sf: File descriptor to print
 *
 * Return: On success numbers of bytes printed.
 * On error, -1 is returned, and errno is set appropriately.
 **/
int print_to_sf(char *msg, int sf)
{
	int field_size;

	file_size = _strlen(msg);

	return (write(sf, msg, size));
}
