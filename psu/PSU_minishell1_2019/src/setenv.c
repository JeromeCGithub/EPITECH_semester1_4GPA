/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** setenv
*/

#include <minishell.h>

int env_size(char **env)
{
    int i = 0;

    for (i = 0 ; env[i] ; i++);
    return (i);
}

static int compare_it(char *s1, char *s2)
{
    int i = 0;

    for (i = 0 ; s1[i] == s2[i] ; i++);
    if (s1[i] == '=' && s2[i] == '\0')
        return (0);
    return (1);
}

char **swap_it(char **env, char *value, int i)
{
    char *new_str = NULL;
    int str_len = 0;
    int index = 0;

    for (str_len = 0 ; env[i][str_len] != '=' ; str_len++);
    for (int j = 0 ; value && value[j] ; j++, str_len++);
    new_str = malloc(sizeof(char) * (str_len + 2));
    for (index = 0 ; env[i][index] != '=' ; index++)
        new_str[index] = env[i][index];
    new_str[index] = '=';
    index++;
    for (int j = 0 ; value[j] ; j++, index++)
        new_str[index] = value[j];
    new_str[index] = '\0';
    env[i] = new_str;
    return (env);
}

char **my_engine_setenv(char **env, char **arg, char **new_env)
{
    int i = 0;

    for (int i = 0 ; env[i] ; i++)
        if (compare_it(env[i], arg[1]) == 0) {
            if (!arg[2])
                return (swap_it(env, "\0", i));
            env = swap_it(env, arg[2], i);
            return (env);
        }
    for (i = 0 ; env[i] ; i++)
        new_env[i] = my_strdup(env[i]);
    if (arg)
        new_env[i] = my_strdup(my_strcat(my_strcat(arg[1], "="), arg[2]));
    new_env[i + 1] = NULL;
    return (new_env);
}

char **my_setenv(char **env, char **arg)
{
    char **new_env = malloc(sizeof(char *) * (env_size(env) + 2));

    if (!arg[1]) {
        display_env(env);
        return (env);
    }
    if ((arg[1][0] < 'a' || arg[1][0] > 'z')
        && (arg[1][0] < 'A' || arg[1][0] > 'Z') && arg[1][0] != '_') {
        write(1, "setenv: Variable name must begin with a letter.\n", 48);
        return (env);
    } else if (!is_alpha(arg[1])) {
        write(1, "setenv: Variable name must contain alphanumeric \
characters.\n", 60);
        return (env);
    }
    if (env_size(arg) > 3) {
        write(1, "setenv: Too many arguments.\n", 28);
        return (env);
    }
    return (my_engine_setenv(env, arg, new_env));
}
