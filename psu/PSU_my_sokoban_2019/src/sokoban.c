/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** main
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <curses.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "../include/my.h"

map_t *moove(int key, map_t *maps)
{
    switch (key) {
    case KEY_RIGHT:
        maps->map = move_right(maps->map, maps->map_originale);
        break;
    case KEY_LEFT:
        maps->map = move_left(maps->map, maps->map_originale);
        break;
    case KEY_UP:
        maps->map = move_up(maps->map, maps->map_originale);
        break;
    case KEY_DOWN:
        maps->map = move_down(maps->map, maps->map_originale);
        break;
    }
    return (maps);
}

void game(map_t *maps, char *buff)
{
    int key = 0;

    display_map(maps);
    keypad(stdscr, TRUE);
    while (key != KEY_EXIT) {
        manage_size(maps, buff);
        refresh();
        is_win(maps);
        key = getch();
        (key == ' ') ? (maps->map = store_map(buff)) : maps->map;
        maps = moove(key, maps);
        display_map(maps);
    }
}
