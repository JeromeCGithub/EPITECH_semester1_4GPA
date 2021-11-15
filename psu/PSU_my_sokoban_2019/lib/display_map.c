/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** display map
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <curses.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"

void display_map(map_t *maps)
{
    clear();
    for (int i = 0 ; maps->map[i] != 0 ; i++) {
        printw(maps->map[i]);
        printw("\n");
    }
    refresh();
}
