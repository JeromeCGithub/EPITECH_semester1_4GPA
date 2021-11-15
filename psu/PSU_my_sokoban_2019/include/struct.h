/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** stuct
*/

typedef struct coord {
    int x;
    int y;
} coord_t;

typedef struct map {
    char **map;
    char **map_originale;
    int cas;
    int cas_k;
    int case_dead;
} map_t;
