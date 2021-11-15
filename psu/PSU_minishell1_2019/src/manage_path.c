/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** manage path
*/

#include <minishell.h>

char *find_good_path(char *arg, char *my_env)
{
    char *path = NULL;
    int j = 0;

    do {
        if (path)
            free(path);
        for (j = 0 ; my_env[j] && my_env[j] != ':' ; j++);
        path = malloc(sizeof(char) * (j + 1));
        for (j = 0 ; my_env[0] != '\0' && my_env[0] != ':' ; j++) {
            path[j] = my_env[0];
            my_env++;
        }
        path[j] = '\0';
        if (my_env[0] != '\0')
            my_env++;
        if (access(my_strcat(my_strcat(path, "/"), arg), 0) == F_OK)
            return (my_strcat(my_strcat(path, "/"), arg));
    } while (my_env[0] != '\0');
    return (arg);
}

char *my_get_env(char **env, char *arg)
{
    int position = 0;
    int j = 0;
    char *my_env = NULL;
    char index[] = "PATH=";

    for (int i = 0 ; env[i] ; i++) {
        for (j = 0 ; env[i][j] == index[j] ; j++);
        if (j == 5)
            position = i;
    }
    my_env = my_strdup(&env[position][5]);
    return (find_good_path(arg, my_env));
}
