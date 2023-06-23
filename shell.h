#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/*_cd.c*/

char *c_strcat(char *dest, char *src);
int c_setenv(list_t **env, char *name, char *dir);
void cd_only(list_t *env, char *current);
int cd_execute(list_t *env, char *current, char *dir, char *str, int num);
int _cd(char **str, list_t *env, int num);

/*_execve.c*/

void c_exit(char **str, list_t *env);
int _execve(char **s, list_t *env, int num);

/*_exit.c*/

int c_atoi(char *s);
int __exit(char **str, list_t *env, int num, char **command);

/*_getline.c*/

size_t get_line(char **str);

/*_strtok.c*/

int t_strlen(char *str, int pos, char delm);
int t_size(char *str, char delm);
char *ignore_delm(char *str, char delm);
char **_str_tok(char *str, char *delm);

/*_which.c*/

char *_which(char *str, list_t *env);

/*env_linked_list.c*/

list_t *env_linked_list(char **env);
int _env(char **str, list_t *env);

/*get_env.c*/

char *c_strdup(char *str, int cs);
char *get_env(char *str, list_t *env);

/*prompt.c*/

void ctrl_c(int n);
int built_in(char **token, list_t *env, int num, char **command);
char *ignore_space(char *str);
void ctrl_D(int i, char *command, list_t *env);
int prompt(char **en);

/*set_unset_env.c*/

int find_env(list_t *env, char *str);
int _unsetenv(list_t **env, char **str);
int _setenv(list_t **env, char **str);


#endif
