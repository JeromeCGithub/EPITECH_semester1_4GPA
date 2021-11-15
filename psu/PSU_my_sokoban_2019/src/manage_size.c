/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** manage size
*/

#include "../include/my.h"
#include <curses.h>

static int find_line(char **map)
{
    int nb_line = 0;

    for (nb_line = 0 ; map[nb_line] != 0 ; nb_line++);
    return (nb_line);
}

void manage_size(map_t *maps, char *buff)
{
    int line = find_line(maps->map);
    int coll = find_coll(buff);
    char msg[] = "Enlarge terminal please.";
    int taille = my_strlen(msg);

    if (LINES < line || COLS < coll) {
        while (LINES < line || COLS < coll) {
            clear();
            mvprintw(LINES / 2, (COLS / 2) - (taille / 2), msg);
            refresh();
        }
    }
}
