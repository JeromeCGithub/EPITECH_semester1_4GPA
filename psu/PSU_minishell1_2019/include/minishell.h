/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** include
*/

#include <errno.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

char **cd_builtin(char **, char **);
int is_num(char const *);
int is_alpha(char const *);
int is_arg(char *, char *);
void display_env(char **);
int env_size(char **);
char **my_unsetenv(char **, char *);
char **my_setenv(char **, char **);
char **builtin_manage(char **, char **, int *);
int my_strcmp(char const *, char const *);
void my_putstr(char *);
char *my_get_env(char **, char *);
char *my_strcpy(char *, char const *);
char *get_next_line(int);
char **my_str_to_word_array(char const *);
char *my_strcat(char *, char *);
char *my_strdup(char const *);
int my_strlen(char const *);
