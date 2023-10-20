#include "command.h"
#include "built.h"
#include "general.h"
#include "memory.h"
#include "text.h"

/**
 * analysis - Analyze	the arguments
 *
 * @argus: Commands and arguments to execute
 * @infor: General information about the shell
 * @buff: Line readed
 **/
void analysis(char **argus, general_t *infor, char *buff)
{
	char *command;
	int status;

	if (*argus == NULL || argus == NULL)
		return;

	command = argus[0];
	infor->command = command;
	if (check_built(infor, argus) == _TRUE)
		return;

	status = is_file(command);
	if (status == NON_PERMISSIONS)
	{
		infor->status_code = 126;
		infor->error_code = _CODE_EACCES;
		error(infor);
		return;
	}

	if (status == 1)
	{
		execute(command, argus, infor, buff);
		return;
	}

	if (current_directory(command, argus, buff, infor) == _TRUE)
		return;

	infor->value_path = which(command, infor);
	if (infor->value_path != NULL)
	{
		execute(infor->value_path, argus, infor, buff);
		free_memory_p((void *) infor->value_path);
		return;
	}

	infor->status_code = 127;
	infor->error_code = _CODE_CMD_NOT_EXISTS;
	error(infor);
}
