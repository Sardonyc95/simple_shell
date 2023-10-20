#include "general.h"
#include "main.h"
#include "text.h"

/**
 * start - Handle the mode
 * Description: Mode can be INTERACTIVE or NON_INTERACTIVE
 *
 * @info: Struct of information about the shell
 **/
void start(general_t *infor)
{
	start_prompt(infor);
}
