#include "command.h"
#include "general.h"

/**
 * is_executed - Check if a filename have permissions
 * for run
 *
 * @filename: Filename to check
 *
 * Return: On success, PERMISSIONS
 * On error, NON_PERMISSIONS
 **/
int is_executed(char *filename)
{
	struct stat stats;

	if (stat(filename, &stats) == 0)
	{
		if (stats.st_mode & X_OK)
			return (PERMISSIONS);
		else
			return (NON_PERMISSIONS);
	}

	return (NON_FILE);
}

/**
 * is_my_file - Check if is a file or binary
 * Description: Lool for excute permissions and
 * if is a file
 *
 * @file: File to check
 *
 * Return: If is a file with the correct permissions, PERMISSIONS
 * If is a file but not have permissions or doesn't exists, NON_PERMISSIONS
 * If is not a file, NON_FILE
 **/
int is_my_file(char *file)
{
	int z, size;

	size = _strlen(file);
	for (z = 0; z < size; z++)
		if (file[z] == '/')
			return (is_executed(file));

	return (NON_FILE);
}
