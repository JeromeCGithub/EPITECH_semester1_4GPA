/*
** EPITECH PROJECT, 2020
** minshell
** File description:
** unsetenv
*/

#include <minishell.h>

int is_arg(char *env, char *arg)
{
    int i = 0;

    for (i = 0 ; env[i] == arg[i] ; i++);
    if (env[i] == '=' && arg[i] == '\0')
        return (0);
    return (1);
}

char **my_unsetenv(char **env, char *arg)
{
    int index = 0;
    int j = 0;
    char **new_env = malloc(sizeof(char *) * (env_size(env) + 1));

    for (j = 0 ; env[j] ; j++)
        if (is_arg(env[j], arg)) {
            new_env[index] = my_strdup(env[j]);
            index++;
        }
    new_env[index] = NULL;
    return (new_env);
}
