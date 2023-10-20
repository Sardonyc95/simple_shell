#ifndef COMMAND_H
#define COMMAND_H

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

#include "general.h"
#include "text.h"
#include "error.h"
#include "built.h"
#include "memory.h"

extern char **environ;

/* command.c */
void analysis(char **argus, general_t *infor, char *buff);

/* permissions.c */
int is_executable(char *filename);
int is_file(char *command);

/* environment.c */
char *_getenv(const char *envname);
char *what(char *filename, general_t *infor);
void is_current_path(char *path, general_t *infor);
void get_full_env(void);

/* execute.c */
void execute(char *command, char **argus, general_t *infor, char *buff);
int my_current_directory(char *command, char **argus, char *buff,
		general_t *infor);

#endif /* COMMAND_H */
