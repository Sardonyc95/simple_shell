#include "built.h"
#include "general.h"

/**
 * built_exit - Implementation of the exit built
 * Description: Free all the memory used and
 * exit with the last status_code
 *
 * @infor: Information about the shell
 * @argus: Arguments received
 **/
void built_exit(general_t *infor, char **argus)
{
	int status_code, status;

	status = _TRUE;
	if (argus[1] != NULL)
		status = number_controller(infor, argus[1]);

	if (status == _FALSE)
		return;

	status_code = infor->status_code;

	free_memory_pp((void **) argus);
	free_memory_p((void *) infor->buffer);
	free_memory_p((void *) infor->environment);
	free_memory_p((void *) infor);

	exit(status_code);
}

/**
 * num_controller - Control the argument of exit
 *
 * @infor: General information about the shell
 * @num: Argument of the built
 *
 * Return: If the actual argument is valid, return _TRUE
 * if not, return _FALSE
 **/
int num_controller(general_t *infor, char *num)
{
	int _num;

	_num = _atoi(num);

	if (_num < 0 || contains_letter(num))
	{
		infor->status_code = 2;
		infor->error_code = _CODE_ILLEGAL_NUMBER;
		errors_extra(infor, num);
		return (_FALSE);
	}

	if (_num > 255)
		infor->status_code = _num % 256;
	else
		infor->status_code = _num;

	return (_TRUE);
}
