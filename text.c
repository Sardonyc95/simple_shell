#include "text.h"
#include "command.h"
#include "general.h"
#include "memory.h"
#include <signal.h>

/**
 * prompt - Print the prompt
 *
 * @infor: Struct of general information
 **/
void prompt(general_t *infor)
{
	if (infor->mode == NON_INTERACTIVE)
		return;

	print("$ ");
}

/**
 * read_my_prompt - Read lines in the prompt
 *
 * Return: Buffer readed or NULL if EOF was found
 **/
char *read_my_prompt()
{
	char *buff;
	int resp;
	size_t size;

	buff = NULL;

	resp = getline(&buff, &size, stdin);

	if (resp == EOF)
	{
		free_memory_p((void *) buff);
		return (NULL);
	}

	return (buff);
}

/**
 * start_my_prompt - Loop reading text
 *
 * @infor: Struct of general information
 *
 * Return: Buffer readed or NULL if EOF was found
 **/
void start_my_prompt(general_t *infor)
{
	char *buf;
	char **argus;
	char *path;

	signal(SIGINT, sigintHandler);
	while (1)
	{
		prompt(infor);

		path = _getenv("PATH");
		is_current_path(path, infor);

		infor->environment = path;
		buf = read_my_prompt();
		if (buf == NULL)
		{
			print(infor->mode == INTERACTIVE ? "exit\n" : "");
			free(path);
			break;
		}

		infor->n_commands++;
		if (buf[0] != '\n')
		{
			argus = split_words(buf, " \t\n");

			infor->argus = argus;
			infor->buffer = buf;
			analyze_patterns(infor, argus);
			analyze(argus, infor, buf);

			free_memory_pp((void *) argus);
		}

		free_memory_p((void *) buf);
		free_memory_p((void *) path);
	}

}

/**
 * sigintHandler - Handler for SIGINT
 *
 * @sig_num: Unused parameter
 **/
void sigintHandler(int sig_num)
{
	(void) sig_num;

	signal(SIGINT, sigintHandler);
	print("\n$ ");
	fflush(stdout);
}
