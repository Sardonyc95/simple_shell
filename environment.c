#include "command.h"
#include "general.h"
#include "text.h"
#include <string.h>
#include <sys/cdefs.h>
#include <unistd.h>

/**
 * _getenv - Get a environment variable
 *
 * @envname: Environment variable to get
 *
 * Return: On success value of @envname
 * On error, NULL
 **/
char *_getenv(const char *envname)
{
	char **env;
	char *aux, *token, *value;
	int size;

	size = _strlen((char *) envname);

	for (env = environ; *env; ++env)
	{
		aux = _strdup(*env);

		token = strtok(aux, "=");
		if (token == NULL)
		{
			free(aux);
			return (NULL);
		}

		if (_strlen(token) != size)
		{
			free(aux);
			continue;
		}

		if (_strcmp((char *) envname, aux) == 0)
		{
			token = strtok(NULL, "=");
			value = _strdup(token);

			free(aux);
			return (value);
		}

		free(aux);
	}

	return (NULL);
}

/**
 * what - Find the directory needed
 *
 * @filename: Command received
 * @infor: General info about the shell
 *
 * Return: pointer string with found path or NULL in failure.
 */
char *what(char *filename, general_t *infor)
{
	char *path, *tmp_path, *token;
	char *slash;
	int size;

	(void) infor;

	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);

	token = strtok(path, ":");

	size = _strlen(filename) + 2;
	slash = malloc(size * sizeof(char));
	slash = _strcpy(slash, "/");
	slash = _strcat(slash, filename);

	while (token != NULL)
	{
		tmp_path = malloc(_strlen(token) + size);
		tmp_path = _strcpy(tmp_path, token);
		tmp_path = _strcat(tmp_path, slash);

		if (is_executable(tmp_path) == PERMISSIONS)
		{
			free(slash);
			free(path);
			return (tmp_path);
		}
		token = strtok(NULL, ":");

		free(tmp_path);
	}

	free(path);
	free(slash);

	return (NULL);
}

/**
 * is_current_path - Check the order of the path
 *
 * @path: PATH to check
 * @infor: General information about the shell
 **/
void is_current_path(char *path, general_t *infor)
{
	infor->is_current_path = _FALSE;

	if (path == NULL)
		return;

	if (path[0] == ':')
		infor->is_current_path = _TRUE;
}

/**
 * get_full_env - Get all the environment
 **/
void get_full_env(void)
{
	char **tmp;
	int a;

	for (a = 0, tmp = environ; tmp[a] != NULL; a++)
	{
		print(tmp[a]);
		_putchar('\n');
	}
}
