/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** moove
*/

#include "../include/my.h"

coord_t test_position(char **map, int i, int j, coord_t coord)
{
    if (map[i][j] == 'P') {
        coord.x = i;
        coord.y = j;
    }
    return (coord);
}

char **move_up(char **map, char **map_org)
{
    coord_t coord;
    int i = 0;
    int j = 0;

    coord.x = 0;
    coord.y = 0;
    for (i = 0 ; map[i] != 0 ; i++)
        for (j = 0 ; map[i][j] != '\0' ; j++)
            coord = test_position(map, i, j, coord);
    if (check_moove(map, coord, 0) == 1 && check_moove2(map, coord, 0) == 1) {
        map = moove_case(map, coord, 0);
        if (map_org[coord.x][coord.y] == 'O')
            map[coord.x][coord.y] = 'O';
        else
            map[coord.x][coord.y] = ' ';
        map[coord.x - 1][coord.y] = 'P';
    }
    return (map);
}

char **move_down(char **map, char **map_org)
{
    coord_t coord;
    int i = 0;
    int j = 0;

    coord.x = 0;
    coord.y = 0;
    for (i = 0 ; map[i] != 0 ; i++)
        for (j = 0 ; map[i][j] != '\0' ; j++)
            coord = test_position(map, i, j, coord);
    if (check_moove(map, coord, 1) == 1 && check_moove2(map, coord, 1) == 1) {
        map = moove_case(map, coord, 1);
        if (map_org[coord.x][coord.y] == 'O')
            map[coord.x][coord.y] = 'O';
        else
            map[coord.x][coord.y] = ' ';
        map[coord.x + 1][coord.y] = 'P';
    }
    return (map);
}

char **move_left(char **map, char **map_org)
{
    coord_t coord;
    int i = 0;
    int j = 0;

    coord.x = 0;
    coord.y = 0;
    for (i = 0 ; map[i] != 0 ; i++)
        for (j = 0 ; map[i][j] != '\0' ; j++)
            coord = test_position(map, i, j, coord);
    if (check_moove(map, coord, 2) == 1 && check_moove2(map, coord, 2) == 1) {
        map = moove_case(map, coord, 2);
        if (map_org[coord.x][coord.y] == 'O')
            map[coord.x][coord.y] = 'O';
        else
            map[coord.x][coord.y] = ' ';
        map[coord.x][coord.y - 1] = 'P';
    }
    return (map);
}

char **move_right(char **map, char **map_org)
{
    coord_t coord;
    int i = 0;
    int j = 0;

    coord.x = 0;
    coord.y = 0;
    for (i = 0 ; map[i] != 0 ; i++)
        for (j = 0 ; map[i][j] != '\0' ; j++)
            coord = test_position(map, i, j, coord);
    if (check_moove(map, coord, 3) == 1 && check_moove2(map, coord, 3) == 1) {
        map = moove_case(map, coord, 3);
        if (map_org[coord.x][coord.y] == 'O')
            map[coord.x][coord.y] = 'O';
        else
            map[coord.x][coord.y] = ' ';
        map[coord.x][coord.y + 1] = 'P';
    }
    return (map);
}
