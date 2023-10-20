#include "built.h"

/**
 * built_env - Implementation for the env built
 *
 * @infor: General information about the shell
 * @argus: Command
 **/
void built_env(general_t *infor, char **argus)
{
	(void) infor;
	(void) argus;

	get_full_env();
}
