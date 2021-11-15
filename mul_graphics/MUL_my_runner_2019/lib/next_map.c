/*
** EPITECH PROJECT, 2019
** my runner
** File description:
** next mao
*/

#include <my.h>

map_t *next_map(char *file_name, game_t *game)
{
    if (file_name[8] < '7')
        file_name[8] += 1;
    if (file_name[8] < '7') {
        return (load_map(file_name, game->inf));
    }
    else
        game->map->map = game->map->map_origin;
    return (game->map);
}
