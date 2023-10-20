#include "text.h"

/**
 * print_error - Print a message to STDERR
 *
 * @msg: Message to print
 *
 * Return: Number of bytes printed
 **/
int print_error(char *msg)
{
	return (print_to_sf(msg, STDERR));
}
