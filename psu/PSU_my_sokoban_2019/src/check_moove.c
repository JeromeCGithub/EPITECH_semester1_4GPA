/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** check mouvement
*/

#include "../include/my.h"

char **moove_box(char **map, coord_t pos, int mouvement)
{
    switch (mouvement) {
    case 0:
        if (map[pos.x - 2][pos.y] != '#' && map[pos.x - 2][pos.y] != 'X')
            map[pos.x - 2][pos.y] = 'X';
        return (map);
    case 1:
        if (map[pos.x + 2][pos.y] != '#' && map[pos.x + 2][pos.y] != 'X')
            map[pos.x + 2][pos.y] = 'X';
        return (map);
    case 2:
        if (map[pos.x][pos.y - 2] != '#' && map[pos.x][pos.y - 2] != 'X')
            map[pos.x][pos.y - 2] = 'X';
        return (map);
    case 3:
        if (map[pos.x][pos.y + 2] != '#' && map[pos.x][pos.y + 2] != 'X')
            map[pos.x][pos.y + 2] = 'X';
        return (map);
    }
}

char **moove_case(char **ma, coord_t po, int mou)
{
    switch (mou) {
    case 0:
        return ((ma[po.x - 1][po.y] == 'X') ? moove_box(ma, po, mou) : ma);
    case 1:
        return ((ma[po.x + 1][po.y] == 'X') ? moove_box(ma, po, mou) : ma);
    case 2:
        return ((ma[po.x][po.y - 1] == 'X') ? moove_box(ma, po, mou) : ma);
    case 3:
        return ((ma[po.x][po.y + 1] == 'X') ? moove_box(ma, po, mou) : ma);
    }
}

int check_moove2(char **map, coord_t pos, int mouvement)
{
    switch (mouvement) {
    case 0:
        return ((map[pos.x - 1][pos.y] == 'X'
                && (map[pos.x - 2][pos.y] == '#'
                || map[pos.x - 2][pos.y] == 'X')) ? 0 : 1);
    case 1:
        return ((map[pos.x + 1][pos.y] == 'X'
                && (map[pos.x + 2][pos.y] == '#'
                || map[pos.x + 2][pos.y] == 'X')) ? 0 : 1);
    case 2:
        return ((map[pos.x][pos.y - 1] == 'X'
                && (map[pos.x][pos.y - 2] == '#'
                || map[pos.x][pos.y - 2] == 'X')) ? 0 : 1);
    case 3:
        return ((map[pos.x][pos.y + 1] == 'X'
                && (map[pos.x][pos.y + 2] == '#'
                || map[pos.x][pos.y + 2] == 'X')) ? 0 : 1);
    }
}

int check_moove(char **map, coord_t pos, int mouvement)
{
    switch (mouvement) {
    case 0:
        return ((map[pos.x - 1][pos.y] == '#') ? 0 : 1);
    case 1:
        return ((map[pos.x + 1][pos.y] == '#') ? 0 : 1);
    case 2:
        return ((map[pos.x][pos.y - 1] == '#') ? 0 : 1);
    case 3:
        return ((map[pos.x][pos.y + 1] == '#') ? 0 : 1);
    }
}
