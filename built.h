#ifndef BUILTIN_H
#define BUILTIN_H

#include "general.h"
#include "text.h"
#include "memory.h"
#include "commands.h"

/* built.c */
int built(general_t *infor, char **argus);
int check_built(general_t *info, char **argus);

/* exit.c */
void built_exit(general_t *infor, char **argus);
int num_controller(general_t *infor, char *num);

/* env.c */
void built_env(general_t *infor, char **argus);

/* echo.c */
void bin_echo(general_t *info, char **arguments);
void echo_printer(int index, char *text, char **arguments);


#endif /* BUILTIN_H */
