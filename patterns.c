#include "commands.h"
#include "general.h"
#include "memory.h"
#include "text.h"

/**
 * analyze_patterns - Entry Point
 * @info: input
 * @arguments: input
**/

void analyze_patterns(general_t *info, char **arguments)
{
	int b;

	for (b = 0; arguments[b] != NULL; b++)
		arguments[b] = pattern_handler(info, arguments[b]);
}

/**
 * pattern_handler - Entry Point
 * @info: input
 * @string: input
 * Return: string
**/

char *pattern_handler(general_t *info, char *string)
{
	int z;

	for (z = 0; string[z] != '\0'; z++)
	{
		if (string[z] == '$' && string[z + 1] != '\0')
			string = replace_value(info, &z, string);
	}

	return (string);
}

/**
 * replace_value - Entry Point
 * @info: input
 * @index: input
 * @string: input
 * Return: string
**/

char *replace_value(general_t *info, int *index, char *string)
{
	int d, new_s, old_s;
	char *value;

	d = *index;
	d++;

	value = replacement(info, index, string + d);
	if (value == NULL)
	{
		string = _strcpy(string, "");

		return (string);
		;
	}

	old_s = _strlen(string);
	new_s = _strlen(value) + 1;

	string = _realloc(string, old_s, new_s);
	string = _strcpy(string, value);

	free_memory_p(value);
	*index = d;
	return (string);
}
