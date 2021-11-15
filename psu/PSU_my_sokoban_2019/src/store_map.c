/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** store map
*/

#include "../include/my.h"
#include <stdlib.h>

char **store_map(char *buff)
{
    int col = 0;
    int collumn = 0;
    char **tab;
    int i = 0;
    int line = 0;

    for (i = 0 ; buff[i] != '\0' ; i++)
        if (buff[i] == '\n')
            line++;
    if (buff[i - 1] != '\n')
        line++;
    tab = malloc(sizeof(char *) * (line + 2));
    if (tab == NULL)
        exit(84);
    tab[line + 1] = 0;
    collumn = find_coll(buff);
    tab = complete_tab(collumn, tab, buff, line);
    return (tab);
}

char **complete_tab(int collumn, char **tab, char *buff, int line)
{
    int p = 0;
    int j = 0;
    int i = 0;

    for (i = 0 ; i < line ; i++) {
        tab[i] = malloc(sizeof(char) * (collumn + 1));
        if (tab[i] == NULL)
            exit(84);
        for (p = 0 ; buff[j] != '\n' && buff[j] != '\0' ; j++) {
            tab[i][p] = buff[j];
            p++;
        }
        tab[i][p] = '\0';
        j++;
    }
    tab[i] = '\0';
    return (tab);
}
