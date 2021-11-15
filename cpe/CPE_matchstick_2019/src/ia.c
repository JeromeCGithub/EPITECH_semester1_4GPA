/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** my ia
*/

#include <my.h>

void ia_engine(int *tab, int *nb_least, game_t *game, int bit)
{
    int i = 0;
    int tmp = 0;

    tmp = find_line(tab, game->line, bit);
    while (is_balanced(tab, game->line) >= 0 && i < game->matchs) {
        tab[tmp] -= 1;
        *nb_least += 1;
        i++;
    }
    write(1, "AI removed ", 11);
    my_put_nbr(*nb_least);
    write(1, " match(es) from line ", 21);
    my_put_nbr(tmp + 1);
    write(1, "\n", 1);
}

void ia_finish_him(int *tab, int *nb_least, game_t *game)
{
    for (int i = 0 ; i < game->line ; i++) {
        if (tab[i] == 1) {
            tab[i] -= 1;
            *nb_least += 1;
            write(1, "AI removed ", 11);
            my_put_nbr(*nb_least);
            write(1, " match(es) from line ", 21);
            my_put_nbr(i + 1);
            write(1, "\n", 1);
            break;
        }
    }
}

void ia_worst(int *tab, int *nb_least, game_t *game)
{
    int tmp = 0;

    for (tmp = 0 ; tab[tmp] < 1 ; tmp++);
    tab[tmp] -= 1;
    *nb_least += 1;
    write(1, "AI removed ", 11);
    my_put_nbr(*nb_least);
    write(1, " match(es) from line ", 21);
    my_put_nbr(tmp + 1);
    write(1, "\n", 1);
}

void ia_prefinish_him(int *tab, int *nb_least, game_t *game, int *is_one)
{
    int nb_one_line = 0;

    nb_one_line = find_nb_one_all(tab, game->line);
    if (nb_one_line % 2 == 0)
        paire_coup(tab, game, nb_least);
    else
        impaire_coup(tab, game, nb_least);
    *is_one = 1;
}

int my_ia(int *tab, game_t *game)
{
    int nb_least = 0;
    int tmp = 0;
    int bit = 0;
    static int is_one = 0;

    write(1, "\n\nAI's turn...\n", 15);
    if (end_of_game(tab, game->line) && !is_one)
        ia_prefinish_him(tab, &nb_least, game, &is_one);
    else if ((bit = is_balanced(tab, game->line)) >= 0)
        ia_engine(tab, &nb_least, game, bit);
    else
        ia_finish_him(tab, &nb_least, game);
    if (nb_least == 0)
        ia_worst(tab, &nb_least, game);
    return (1);
}
