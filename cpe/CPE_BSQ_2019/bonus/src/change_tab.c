/*
** EPITECH PROJECT, 2019
** bsq
** File description:
** change tab
*/

#include "../include/my.h"
#include <stdlib.h>
#include <unistd.h>

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

int is_x(char *tab)
{
    for (int i = 0 ; tab[i] != '\0' ; i++)
        if (tab[i] == 'x')
            return (1);
    return (0);
}

void write_x(char *tab)
{
    char space = ' ';

    for (int i = 0 ; tab[i] != '\0' && tab[i] != '\n' ; i++) {
        if (tab[i] == 'x') {
            write(1, "\e[1;31m", 8);
            write(1, &tab[i], 1);
            (tab[i + 1] == 'x') ? write(1, &space, 1) : space;
            write(1, "\033[0m", 7);
        }
        else
            write(1, &tab[i], 1);
        //write(1, " ", 1);
    }
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
        if (is_x(tab[i]) == 1) {
            write_x(tab[i]);
        }
        else {
            write(1, tab[i], my_strlen(tab[i]));
        }
        my_putchar('\n');
    }
}
