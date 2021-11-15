/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** test sokoban
*/

#include "../include/my.h"
#include <stdlib.h>
#include <criterion/criterion.h>

Test(check_moove, test_moove14)
{
    char buff[] = "# ###\n#X #\n##  #\n# PX ##\n#####\n";
    char buff2[] = "#####\n X##\n#O  #\n# PX ##\n#####\n";
    char **mapa = store_map(buff);
    char **map2 = store_map(buff2);
    map_t *maps = malloc(sizeof(map_t));

    maps->map = map2;
    maps->map_originale = mapa;
    is_win(maps);
    cr_assert_eq(maps->case_dead, 1);
    free(mapa);
}

Test(check_moove, test_moove15)
{
    char buff[] = "# ###\n#X #\n##  #\n# PX ##\n#####\n";
    char buff2[] = "# ###\nXXX##\n### #\n# PX ##\n#####\n";
    char **mapa = store_map(buff);
    char **map2 = store_map(buff2);
    map_t *maps = malloc(sizeof(map_t));

    maps->map = map2;
    maps->map_originale = mapa;
    is_win(maps);
    cr_assert_eq(maps->case_dead, 3);
    free(mapa);
}

Test(check_moove, test_moove16)
{
    char buff[] = "# ###\n#X #\n##  #\n# PX ##\n#####\n";

    check_map(buff);
}

Test(check_moove, test_moove17, .exit_code = 84)
{
    char buff[] = "# ###\n#X #\n## d#\n# PX ##\n#####\n";

    check_map(buff);
}

Test(check_moove, test_moove18)
{
    char buff[] = "# ###\n#X #\n#   #\n# O P##\n#####\n";
    char buff2[] = "# ###\n#X #\n#   #\n# P  ##\n#####\n";
    char **mapa = store_map(buff);
    char **map2 = store_map(buff2);
    map_t *maps = malloc(sizeof(map_t));

    maps->map = map2;
    maps->map_originale = mapa;
    maps->map = move_up(maps->map, maps->map_originale);
    cr_assert_str_eq(maps->map[3], "# O  ##");
    free(mapa);
}
