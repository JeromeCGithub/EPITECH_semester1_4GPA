/*
** EPITECH PROJECT, 2020
** lib csfml
** File description:
** check env
*/

#include <my.h>

int check_env(char **envp)
{
    if (envp[0] != NULL)
        return (0);
    else
        return (1);
}
