/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** change tab
*/

#include "../include/my.h"
#include <stdlib.h>
#include <unistd.h>

int check_lines2(int *tmp, int *compteur, int *last_compteur)
{
    *last_compteur = *compteur;
    *tmp = 1;
    *compteur = 0;
}

int check_lines(char *buff)
{
    int compteur = 0;
    int tmp = 0;
    int i = 0;
    int last_compteur = 0;

    for (i = 0 ; buff[i] != '\0' ; i++) {
        compteur++;
        if (buff[i] == '\n')
            compteur--;
        if (buff[i] == '\n' && compteur != last_compteur && tmp == 1)
            return (1);
        else if (buff[i] == '\n') {
            check_lines2(&tmp, &compteur, &last_compteur);
        }
    }
    if (buff[i - 1] == '\n')
        return (0);
    if (compteur != last_compteur)
        return (1);
    return (0);
}

void free_all(char **tab, int **tab_int)
{
    int i = 0;

    for (i = 0 ; tab_int[i][0] != -1 ; i++)
        free(tab_int[i]);
    free(tab_int[i]);
    for (i = 0 ; tab[i] != 0 ; i++)
        free(tab[i]);
    free(tab[i]);
}

char **remplace_tab(int x, int y, char **tab, int tmp)
{
    int tmp_x = x;
    int tmp_y = y;

    for (int i = 0 ; i < tmp ; i++) {
        tmp_x = x;
        for (int j = 0 ; j < tmp ; j++) {
            tab[tmp_y][tmp_x] = 'x';
            tmp_x--;
        }
        tmp_y--;
    }
    return (tab);
}

void change_tab(char **tab, int **tab_int)
{
    int tmp = 0;
    int tmp_coord_x = 0;
    int tmp_coord_y = 0;

    for (int y = 0 ; tab_int[y][0] != -1 ; y++) {
        for (int x = 0 ; tab_int[y][x] != -1 ; x++) {
            (tab_int[y][x] > tmp) ? tmp_coord_x = x : tmp_coord_x;
            (tab_int[y][x] > tmp) ? tmp_coord_y = y : tmp_coord_y;
            (tab_int[y][x] > tmp) ? tmp = tab_int[y][x] : tmp;
        }
    }
    remplace_tab(tmp_coord_x, tmp_coord_y, tab, tmp);
    for (int i = 0 ; tab[i] != 0 ; i++) {
        write(1, tab[i], my_strlen(tab[i]));
        my_putchar('\n');
    }
}
