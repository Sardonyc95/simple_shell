#include "simple-shell.h"
#include <unistd.h>
#include <string.h>

/**
 * main - A function that prints a text.
 * Description: A beautiful code that passes the betty checks.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *betty = "Hello, this is my betty check!"; /* Declaring
							   * variable
							   */

	write(STDOUT_FILENO, betty, strlen(betty)); /* Print the betty
						       * to STDOUT
						       * using write()
						       */

	return (0); /* Return 0 to indicate successful execution */
}
