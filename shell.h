#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>

/* struct for program information */
typedef struct info_s
{
    char **envp;
} info_t;

#define INFO_INIT {NULL}

/* main loop for interactive mode */
void hsh(void);

/* get input line from stdin */
char *get_input(info_t *info);

/* execute command from input line */
void execute_line(info_t *info, char *line);

/* execute external command */
void execute_external(info_t *info, char **args);

/* execute builtin command */
void execute_builtin(info_t *info, char **args);

/* check if command is a builtin */
int is_builtin(char *cmd);

/* tokenize input line */
char **tokenize(char *line);

/* free tokens */
void free_tokens(char **tokens);

/* print environment variables */
void print_env(char **envp);

/* set environment variable */
void set_env(char ***envp, char *name, char *value);

/* unset environment variable */
void unset_env(char ***envp, char *name);

/* populate env list */
void populate_env_list(info_t *info);

/* remove comments from input line */
void remove_comments(char *line);

/* replace variables in input line */
void replace_vars(info_t *info, char **line);

/* print string to stdout */
ssize_t _puts(char *str);

/* compare two strings */
int _strcmp(char *s1, char *s2);

/* convert string to integer */
int _atoi(char *s);

/* free info struct */
void free_info(info_t *info);

#endif /* SHELL_H */
