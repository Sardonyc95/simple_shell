#include "general.h"
#include "main.h"

/**
 * main - Entry Point
 * @argc: number of arguments received
 * @argv: arguments received
 * Return: 0
 **/

int main(int argc, char **argv)
{
	general_t *infor;
	int status_code;

	infor = malloc(sizeof(general_t));
	if (infor == NULL)
	{
		perror(argv[0]);
		exit(1);
	}

	infor->pid = getpid();
	infor->status_code = 0;
	infor->n_commands = 0;
	infor->argc = argc;
	infor->argv = argv;
	infor->mode = isatty(STDIN) == INTERACTIVE;
	start(infor);

	status_code = infor->status_code;

	free(infor);

	return (status_code);
}
