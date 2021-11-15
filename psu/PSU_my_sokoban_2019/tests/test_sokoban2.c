/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** test 2
*/

#include <criterion/criterion.h>
#include "../include/my.h"

Test(my_strlen, my_len)
{
    cr_assert_str_eq(read_it("tests/file1"), "lol");
    cr_assert_eq(my_strlen("test"), 4);
}

Test(Test_read, test_rear, .exit_code = 84)
{
    read_it("tests/file2");
}

Test(check_moove, test_moove6)
{
    char buff[] = "#####\n# OO#\n# XX#\n#  P#\n#####\n";
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

Test(check_moove, test_moove7)
{
    char buff[] = "#####\n# OO#\n# XX#\n# XP  #\n#####\n";
    char buff2[] = "#####\n# OO#\n# XX#\n#XP   #\n#####\n";
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

Test(check_moove, test_moove8)
{
    char buff[] = "#####\n# OO#\n# XX#\n# PX #\n#####\n";
    char buff2[] = "#####\n# OO#\n# XX#\n#  PX#\n#####\n";
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
