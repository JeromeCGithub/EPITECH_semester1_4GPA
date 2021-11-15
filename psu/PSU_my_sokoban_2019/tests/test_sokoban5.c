/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** test sokoban
*/

#include "../include/my.h"
#include <stdlib.h>
#include <criterion/criterion.h>

Test(check_moove, test_moove19)
{
    char buff[] = "# ###\n#X #\n#   #\n# O P##\n#####\n";
    char buff2[] = "# ###\n#X #\n#   #\n# P  ##\n#  ##\n";
    char **mapa = store_map(buff);
    char **map2 = store_map(buff2);
    map_t *maps = malloc(sizeof(map_t));

    maps->map = map2;
    maps->map_originale = mapa;
    maps->map = move_down(maps->map, maps->map_originale);
    cr_assert_str_eq(maps->map[3], "# O  ##");
    free(mapa);
}

Test(check_moove, test_moove20)
{
    char buff[] = "# ###\n#X #\n#   #\n# O P##\n#####\n";
    char buff2[] = "# ###\n#X #\n#   #\n# P  ##\n#  ##\n";
    char **mapa = store_map(buff);
    char **map2 = store_map(buff2);
    map_t *maps = malloc(sizeof(map_t));

    maps->map = map2;
    maps->map_originale = mapa;
    maps->map = move_left(maps->map, maps->map_originale);
    cr_assert_str_eq(maps->map[3], "#PO  ##");
    free(mapa);
}

Test(check_moove, test_moove21)
{
    char buff[] = "# ###\n#X #\n#   #\n# O P##\n#####\n";
    char buff2[] = "# ###\n#X #\n#   #\n# P  ##\n#  ##\n";
    char **mapa = store_map(buff);
    char **map2 = store_map(buff2);
    map_t *maps = malloc(sizeof(map_t));

    maps->map = map2;
    maps->map_originale = mapa;
    maps->map = move_right(maps->map, maps->map_originale);
    cr_assert_str_eq(maps->map[3], "# OP ##");
    free(mapa);
}

Test(check_store_map, test_storemapx)
{
    char buff[] = "# ###\n#X #\n#   #\n# O P##\n#####";
    char **mapa = store_map(buff);

    cr_assert_str_eq(mapa[0], "# ###");
}
