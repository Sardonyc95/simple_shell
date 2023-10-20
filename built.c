#include "built.h"

/**
 * built - Check and execute the builtin
 *
 * @infor: Information about the shell
 * @argus: Commands and arguments
 *
 * Return: If the command passed is a builtin
 * return _TRUE if not return _FALSE
 **/
int built(general_t *infor, char **argus)
{
	int status;

	status = check_built(infor, argus);
	if (status == _FALSE)
		return (_FALSE);

	return (_TRUE);
}


/**
 * check_built - Check if the actual command is a builtin_t
 * or not
 *
 * @infor: General information about the shell
 * @argus: Arguments of the command
 *
 * Return: If the command is an actual built, return _TRUE
 * if not _FALSE
 **/
int check_built(general_t *infor, char **argus)
{
	int y, size;
	builtin_t built[] = {
		{"exit", built_exit},
		{"env", built_env}
	};

	size = sizeof(built) / sizeof(built[0]);
	for (y = 0; y < size; y++)
	{
		if (_strcmp(infor->command, built[y].command) == 0)
		{
			built[y].func(infor, argus);
			return (_TRUE);
		}
	}

	return (_FALSE);
}
