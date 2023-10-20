#include "general.h"
#include "text.h"
#include "command.h"

/**
 * replacement - Entry point
 * @infor: input
 * @index: input
 * @strg: input string
 * Return: strg
**/

char *replacement(general_t *infor, int *index, char *strg)
{
	char *tmp;
	char symb;

	(void) index;

	symb = *strg;
	if (symb != '?' && symb != '$')
	{
		tmp = replace_env(infor, strg);
		return (tmp);
	}

	tmp = (symb == '$') ? to_strg(infor->pid) :
		to_strg(infor->status_code);

	return (tmp);
}

/**
 * replace_env - Entry Point
 * @infor: input
 * @environment: input
 * Return: strg
**/

char *replace_env(general_t *infor, char *environment)
{
	char *env;

	(void) infor;

	env = _getenv(environment);
	if (env != NULL)
		return (env);

	return (NULL);
}
