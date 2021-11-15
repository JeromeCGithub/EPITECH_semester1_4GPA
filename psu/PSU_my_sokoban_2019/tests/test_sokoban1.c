/*
** EPITECH PROJECT, 2019
** my_sokoan
** File description:
** test unit
*/

#include <curses.h>
#include "../include/my.h"
#include <stdlib.h>
#include <criterion/criterion.h>

Test(store_map, test_store_map1)
{
    char buff[] = "#####\n# OO#\n# XX#\n# P #\n#####\n";
    char **map = store_map(buff);
    char *tab[] = {"#####", "# OO#", "# XX#", "# P #", "#####"};

    cr_assert_neq(map, NULL);
    cr_assert_str_eq(map[0], tab[0]);
    cr_assert_str_eq(map[1], tab[1]);
    cr_assert_str_eq(map[2], tab[2]);
    cr_assert_str_eq(map[3], tab[3]);
    cr_assert_str_eq(map[4], tab[4]);
    free(map);
}

Test(check_moove, test_moove)
{
    char buff[] = "#####\n# OO#\n# XX#\n# P #\n#####\n";
    char buff2[] = "#####\n# OO#\n# PX#\n#   #\n#####\n";
    char **mapa = store_map(buff);
    char **map2 = store_map(buff2);

    move_up(mapa, mapa);
    cr_assert_str_eq(mapa[0], map2[0]);
    cr_assert_str_neq(mapa[1], map2[1]);
    cr_assert_str_eq(mapa[2], map2[2]);
    cr_assert_str_eq(mapa[3], map2[3]);
    cr_assert_str_eq(mapa[4], map2[4]);
    free(mapa);
}

Test(check_moove, test_moove2)
{
    char buff[] = "#####\n# OO#\n# XX#\n# P #\n#####\n";
    char buff2[] = "#####\n# OO#\n# XX#\n# P #\n#####\n";
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

Test(check_moove, test_moove4)
{
    char buff[] = "#####\n# OO#\n# XX#\n# P #\n#####\n";
    char buff2[] = "#####\n# OO#\n# XX#\n#P  #\n#####\n";
    char **mapa = store_map(buff);
    char **map2 = store_map(buff2);

    move_left(mapa, mapa);
    cr_assert_str_eq(mapa[0], map2[0]);
    cr_assert_str_eq(mapa[1], map2[1]);
    cr_assert_str_eq(mapa[2], map2[2]);
    cr_assert_str_eq(mapa[3], map2[3]);
    cr_assert_str_eq(mapa[4], map2[4]);
    free(mapa);
}
Test(check_moove, test_moove5)
{
    char buff[] = "#####\n# OO#\n# XX#\n# P #\n#####\n";
    char buff2[] = "#####\n# OO#\n# XX#\n#  P#\n#####\n";
    char **mapa = store_map(buff);
    char **map2 = store_map(buff2);

    move_right(mapa, mapa);
    cr_assert_str_eq(mapa[0], map2[0]);
    cr_assert_str_eq(mapa[1], map2[1]);
    cr_assert_str_eq(mapa[2], map2[2]);
    cr_assert_str_eq(mapa[3], map2[3]);
    cr_assert_str_eq(mapa[4], map2[4]);
    free(mapa);
}
