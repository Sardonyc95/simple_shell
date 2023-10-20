#ifndef TEXT_H
#define TEXT_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "general.h"
#include "memory.h"

/* text.c */
void start_my_prompt(general_t *infor);
void prompt(general_t *infor);
char *read_my_prompt();
void sigintHandler(int sig_num);

/* utils_text.c */
int _strlen(char *msg);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *srg1, char *srg2);

/* utils_text2.c */
char *to_my_string(int num);
int is_numerical(unsigned int n);
int _atoi(char *s);
int contains_my_letter(char *c);

/* printers.c */
int _putchar_to_sf(char c, int sf);
int print_to_sf(char *msg, int sf);

/* printers_out.c */
int _putchar(char a);
int print(char *msg);

/* printers_error.c */
int print_error(char *msg);

/* tokenization.c */
char **split_words(char *line, const char *sep);
char *join_words(char *word1, char *word2, char *word3, const char *sep);

/* patterns.c */
void analyze_patterns(general_t *info, char **arguments);
char *pattern_handler(general_t *info, char *string);
char *replace_value(general_t *info, int *index, char *string);

/* patterns_replacer.c */
char *replacement(general_t *info, int *index, char *string);
char *replace_env(general_t *info, char *environment);
#endif /* TEXT_H */
