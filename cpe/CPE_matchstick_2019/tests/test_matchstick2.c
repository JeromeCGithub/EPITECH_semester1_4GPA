/*
** EPITECH PROJECT, 2020
** test
** File description:
** test 2
*/

#include <my.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(win_test, test6)
{
    int *tab = find_number_of_match(5);
    int *tab2 = find_number_of_match(5);

    cr_redirect_stdout();
    for (int i = 0 ; i < 5 ; i++)
        tab[i] = 0;
    cr_assert_eq(is_win_player(tab, 5), 1);
    cr_assert_eq(is_win_player(tab2, 5), 0);
    cr_assert_eq(is_win_ia(tab, 5), 1);
    cr_assert_eq(is_win_ia(tab2, 5), 0);
}

Test(ia_worst, test7)
{
    int nb_least = 0;
    game_t *game = malloc(sizeof(game_t));
    int *tab = find_number_of_match(5);

    game->line = 5;
    game->matchs = 5;
    cr_redirect_stdout();
    ia_worst(tab, &nb_least, game);
    cr_assert_eq(tab[0], 0);
    free(game);
}
