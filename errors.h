#ifndef ERRORS_H
#define ERRORS_H

#include "general.h"
#include "text.h"

/* errors.c */
char *message_selector(general_t infor);
void errors(general_t *infor);
void errors_extra(general_t *infor, char *extra);

#endif /* ERRORS_H */
