/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** man
*/

#include "../include/my.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <curses.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    char *buff;
    map_t *maps = malloc(sizeof(map_t));

    if (ac != 2)
        return (84);
    print_h(av);
    buff = read_it(av[1]);
    check_map(buff);
    maps->map = store_map(buff);
    maps->map_originale = store_map(buff);
    initscr();
    game(maps, buff);
    endwin();
    free_all(maps);
    return (0);
}
