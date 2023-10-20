#include "command.h"
#include "general.h"
#include "memory.h"
#include "text.h"

/**
 * analyze_patterns - Entry Point
 * @infor: input
 * @argus: input
**/

void analyze_patterns(general_t *infor, char **argus)
{
	int x;

	for (x = 0; argus[x] != NULL; x++)
		argus[x] = pattern_handler(infor, argus[x]);
}

/**
 * pattern_handler - Entry Point
 * @infor: input
 * @strg: input string
 * Return: strg
**/

char *pattern_handler(general_t *infor, char *strg)
{
	int q;

	for (q = 0; strg[q] != '\0'; q++)
	{
		if (strg[q] == '$' && strg[q + 1] != '\0')
			strg = replace_value(infor, &q, strg);
	}

	return (strg);
}

/**
 * replace_value - Entry Point
 * @infor: input
 * @index: input
 * @strg: input string
 * Return: strg
**/

char *replace_value(general_t *infor, int *index, char *strg)
{
	int n, new_s, old_s;
	char *value;

	n = *index;
	n++;

	value = replacement(infor, index, strg + n);
	if (value == NULL)
	{
		strg = _strcpy(strg, "");

		return (strg);
		;
	}

	old_s = _strlen(strg);
	new_s = _strlen(value) + 1;

	strg = _reallocate(strg, old_s, new_s);
	strg = _strcpy(strg, value);

	free_memory_p(value);
	*index = n;
	return (strg);
}
