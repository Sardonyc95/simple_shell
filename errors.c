#include "errors.h"
#include "general.h"
#include "text.h"

/**
 * message_selector - Select the message that match with the error_code
 *
 * @infor: General information about the shell
 *
 * Return: Error message
 **/
char *message_selector(general_t infor)
{
	int z, n_options;
	error_t messages[] = {
		{_ENOENT, _CODE_ENOENT},
		{_EACCES, _CODE_EACCES},
		{_CMD_NOT_EXISTS, _CODE_CMD_NOT_EXISTS},
		{_ILLEGAL_NUMBER, _CODE_ILLEGAL_NUMBER}
	};

	n_options = sizeof(messages) / sizeof(messages[0]);
	for (z = 0; z < n_options; z++)
		if (infor.error_code == messages[z].code)
			return (messages[z].message);

	return ("");
}

/**
 * errors - Print the errors
 *
 * @infor: General information about the shell
 **/
void errors(general_t *infor)
{
	char *message;
	char *num;
	char *aux;
	int size_num, size_message;

	num = NULL;
	message = message_selector(*infor);
	num = to_string(infor->n_commands);

	size_num = _strlen(num);
	size_message = _strlen(infor->argv[0]);

	aux = malloc(size_message + size_num + 3);

	aux = _strcpy(aux, infor->argv[0]);
	aux = _strcat(aux, ": ");
	aux = _strcat(aux, num);

	message = join_words(aux, infor->command, message, ": ");
	print_err(message);

	free(message);
	free(num);
	free(aux);
}

/**
 * errors_extra - Print the errors with extra information
 *
 * @infor: General information about the shell
 * @extra: Extra information
 **/
void errors_extra(general_t *infor, char *extra)
{
	char *message, *num, *aux, *aux2;
	int size_num, size_message, size_extra;

	num = NULL;
	message = message_selector(*infor);
	num = to_string(infor->n_commands);

	size_num = _strlen(num);
	size_message = _strlen(infor->argv[0]);
	size_extra = _strlen(extra);

	aux = malloc(size_message + size_num + 3);
	aux = _strcpy(aux, infro->argv[0]);
	aux = _strcat(aux, ": ");
	aux = _strcat(aux, num);

	aux2 = malloc(_strlen(message) + size_extra + 3);
	aux2 = _strcpy(aux2, message);
	aux2 = _strcat(aux2, ": ");
	aux2 = _strcat(aux2, extra);

	message = join_words(aux, infor->command, aux2, ": ");
	print_err(message);

	free(message);
	free(num);
	free(aux);
	free(aux2);
}
