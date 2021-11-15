/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** builtin
*/

#include <minishell.h>

void display_env(char **env)
{
    for (int i = 0 ; env[i] != NULL ; i++) {
        my_putstr(env[i]);
        write(1, "\n", 1);
    }
}

char **builtin_manage(char **arg_parsed, char **env, int *is_done)
{
    if (my_strcmp(arg_parsed[0], "cd") == 0) {
        *is_done = 1;
        env = cd_builtin(arg_parsed, env);
    }
    if (my_strcmp(arg_parsed[0], "setenv") == 0) {
        env = my_setenv(env, arg_parsed);
        *is_done = 1;
    }
    if (my_strcmp(arg_parsed[0], "unsetenv") == 0) {
        for (int i = 1 ; arg_parsed[i] ; i++)
            env = my_unsetenv(env, arg_parsed[i]);
        *is_done = 1;
    }
    if (my_strcmp(arg_parsed[0], "env") == 0) {
        display_env(env);
        *is_done = 1;
    }
    return (env);
}
