#include "command.h"
#include "general.h"
#include "memory.h"

/**
 * execute - Execute a command in other process
 *
 * @command: Command to execute
 * @argus: Arguments of the @command
 * @infor: General info about the shell
 * @buff: Line readed
 **/
void execute(char *command, char **argus, general_t *infor, char *buff)
{
	int status;
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		execve(command, argus, environ);
		perror("./sh");

		free_memory_pp((void *) argus);

		if (infor->value_path != NULL)
		{
			free(infor->value_path);
			infor->value_path = NULL;
		}

		free(infor);
		free(buff);
		exit(1);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			infor->status_code = WEXITSTATUS(status);
	}
}


/**
 * my_current_directory - Execute the command if the order require
 *
 * @command: Command to execute
 * @argus: Arguments of the command
 * @buff: Line readed
 * @infor: General info about the shell
 *
 * Return: Status of the operations
 **/
int my_current_directory(char *command, char **argus, char *buff, general_t *infor)
{

	if (infor->is_current_path == _FALSE)
		return (_FALSE);

	if (is_executable(command) == PERMISSIONS)
	{
		execute(command, argus, infor, buff);
		return (_TRUE);
	}

	return (_FALSE);
}
