/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** main
*/

#include <my.h>

int *find_number_of_match(int size)
{
    int *tab = malloc(sizeof(int) * (size + 1));
    int nb = -1;

    for (int i = 0 ; i < size ; i++) {
        nb += 2;
        tab[i] = nb;
    }
    return (tab);
}

void print_board(int *origin, int *tab, int size_tab)
{
    int nb = 0;
    int j = 0;

    for (int i = 0 ; i < origin[size_tab - 1] + 2; i++)
        write(1, "*", 1);
    write(1, "\n", 1);
    for (int i = 0 ; i < size_tab ; i++) {
        write(1, "*", 1);
        for (j = 0 ; j < origin[size_tab - 1] / 2 - origin[i] / 2; j++)
            write(1,  " ", 1);
        for (j = 0 ; j < tab[i] ; j++)
            write(1, "|", 1);
        nb = origin[i] - tab[i];
        for (j = 0 ; j < (origin[size_tab - 1] - origin[i]) / 2 + nb ; j++)
            write(1,  " ", 1);
        write(1, "*", 1);
        write(1, "\n", 1);
    }
    for (int i = 0 ; i < origin[size_tab - 1] + 2; i++)
        write(1, "*", 1);
}

int game_engine(char **av, game_t *game)
{
    int is_win = 1;
    size_t nb = 0;
    int *number_of_match = find_number_of_match(my_atoi(av[1]));
    int *origin = find_number_of_match(my_atoi(av[1]));

    print_board(origin, number_of_match, my_atoi(av[1]));
    while (is_win && is_win != 84) {
        write(1, "\n\nYour turn:\n", 13);
        is_win = player_turn(number_of_match, my_atoi(av[1]), my_atoi(av[2]));
        if (is_win == 84)
            return (0);
        print_board(origin, number_of_match, my_atoi(av[1]));
        if (is_win_ia(number_of_match, my_atoi(av[1])))
            return (2);
        is_win = my_ia(number_of_match, game);
        print_board(origin, number_of_match, my_atoi(av[1]));
        if (is_win_player(number_of_match, my_atoi(av[1])))
            return (1);
    }
    return (0);
}

int matchstick(int ac, char **av)
{
    game_t *game = malloc(sizeof(game_t));

    if (ac != 3)
        return (84);
    if (my_atoi(av[1]) <= 1 || my_atoi(av[1]) >= 100 || my_atoi(av[2]) < 1)
        return (84);
    game->line = my_atoi(av[1]);
    game->matchs = my_atoi(av[2]);
    return (game_engine(av, game));
}
