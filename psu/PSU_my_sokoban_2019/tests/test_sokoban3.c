/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** test 3
*/

#include <criterion/criterion.h>
#include "../include/my.h"
#include <stdlib.h>

Test(check_moove, test_moove10)
{
    char buff[] = "#####\n# OO#\n# XX#\n# PX #\n#####\n";
    char buff2[] = "#####\n# OO#\n# XX#\n# PX #\n#####\n";
    char **mapa = store_map(buff);
    char **map2 = store_map(buff2);

    move_down(mapa, mapa);
    cr_assert_str_eq(mapa[0], map2[0]);
    cr_assert_str_eq(mapa[1], map2[1]);
    cr_assert_str_eq(mapa[2], map2[2]);
    cr_assert_str_eq(mapa[3], map2[3]);
    cr_assert_str_eq(mapa[4], map2[4]);
    free(mapa);
}

Test(check_moove, test_moove11)
{
    char buff[] = "#####\n#POO#\n#XXX#\n#  #\n#####\n";
    char buff2[] = "#####\n# OO#\n#PXX#\n#X #\n#####\n";
    char **mapa = store_map(buff);
    char **map2 = store_map(buff2);

    move_down(mapa, mapa);
    cr_assert_str_eq(mapa[0], map2[0]);
    cr_assert_str_eq(mapa[1], map2[1]);
    cr_assert_str_eq(mapa[2], map2[2]);
    cr_assert_str_eq(mapa[3], map2[3]);
    cr_assert_str_eq(mapa[4], map2[4]);
    free(mapa);
}

Test(check_moove, test_moove12, .exit_code = 0)
{
    char buff[] = "#####\n# OO#\n#   #\n# P  #\n#####\n";
    char buff2[] = "#####\n# XX#\n#   #\n#P   #\n#####\n";
    char **mapa = store_map(buff);
    char **map2 = store_map(buff2);
    map_t *maps = malloc(sizeof(map_t));

    maps->map = map2;
    maps->map_originale = mapa;
    is_win(maps);
    free(mapa);
}

Test(check_moove, test_moove13, .exit_code = 1)
{
    char buff[] = "#####\n# OO#\n# XX#\n# PX #\n#####\n";
    char buff2[] = "#####\n#X  #\n#   #\n#P   #\n#####\n";
    char **mapa = store_map(buff);
    char **map2 = store_map(buff2);
    map_t *maps = malloc(sizeof(map_t));

    maps->map = map2;
    maps->map_originale = mapa;
    is_win(maps);
    free(mapa);
}
