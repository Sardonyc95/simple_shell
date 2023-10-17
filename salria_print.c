#include "shell.h"

/**
 * salria_print - A function that prints to the STDOUT
 * Description: Personal printf function.
 *
 * Return: void
 */
void salria_print(const char *text)
{
    write(STDOUT_FILENO, text, strlen(text));
}
