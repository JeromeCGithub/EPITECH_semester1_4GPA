/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** free all
*/

#include <stdlib.h>
#include "../include/my.h"

void free_all(map_t *maps)
{
    for (int i = 0 ; maps->map_originale[i] != 0 ; i++)
        free(maps->map_originale[i]);
    free(maps->map_originale);
    for (int i = 0 ; maps->map[i] != 0 ; i++)
        free(maps->map[i]);
    free(maps->map);
    free(maps);
}
