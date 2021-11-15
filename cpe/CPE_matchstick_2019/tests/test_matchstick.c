/*
** EPITECH PROJECT, 2020
** test unitaire
** File description:
** test
*/

#include <my.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(print_board, test1)
{
    game_t *game = malloc(sizeof(game_t));
    int *tab = find_number_of_match(5);

    game->line = 5;
    game->matchs = 5;
    cr_redirect_stdout();
    print_board(tab, tab, 5);
    my_ia(tab, game);
    my_ia(tab, game);
    my_ia(tab, game);
    my_ia(tab, game);
}

Test(formalities, test2)
{
    cr_redirect_stdout();
    write_formalities("2", "2");
    cr_assert_stdout_eq_str("Player removed 2 match(es) from line 2\n");
}

Test(test_ia_lib, test3)
{
    int nb = 0;
    game_t *game = malloc(sizeof(game_t));
    int *tab = find_number_of_match(3);

    cr_redirect_stdout();
    game->matchs = 5;
    game->line = 3;
    for (int i = 0 ; i < 3 ; i++)
        tab[i] = 1;
    my_ia(tab, game);
    cr_assert_eq(tab[0], 1);
}

Test(test_ia_lib, test4)
{
    int nb = 0;
    game_t *game = malloc(sizeof(game_t));
    int *tab = find_number_of_match(3);

    cr_redirect_stdout();
    game->matchs = 5;
    game->line = 3;
    tab[1] = 1;
    my_ia(tab, game);
    cr_assert_eq(tab[2], 1);
}

Test(test_error, test5)
{
    int nb = 0;
    game_t *game = malloc(sizeof(game_t));
    int *tab = find_number_of_match(5);

    cr_redirect_stdout();
    game->matchs = 5;
    game->line = 3;
    cr_assert_eq(is_error_match(tab, "6", 5, 5), 1);
    cr_assert_eq(is_error_match(tab, "re6", 5, 5), 1);
    cr_assert_eq(is_error_match(tab, "0", 5, 5), 1);
    cr_assert_eq(is_error_match(tab, "30", 4, 35), 1);
    cr_assert_eq(is_error_match(tab, "1", 3, 5), 0);
    cr_assert_eq(is_error_line("3", 5, 5, tab), 0);
    cr_assert_eq(is_error_line("3de", 5, 5, tab), 1);
    cr_assert_eq(is_error_line("50", 5, 5, tab), 1);
    cr_assert_eq(is_error_line("-50", 5, 5, tab), 1);
    cr_assert_eq(is_error_line("", 5, 5, tab), 1);
}
