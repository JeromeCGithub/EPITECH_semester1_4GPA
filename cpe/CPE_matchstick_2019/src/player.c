/*
** EPITECH PROJECT, 2020
** matchstick
** File description:
** player turn
*/

#include <my.h>

void write_formalities(char *nb_match_read, char *nb_read)
{
    write(1, "Player removed ", 15);
    my_put_nbr(my_atoi(nb_match_read));
    write(1, " match(es) from line ", 21);
    my_put_nbr(my_atoi(nb_read));
    write(1, "\n", 1);
}

int player_turn(int *number_of_match, int line, int matchs)
{
    char *nb_match_read;
    char *nb_read;

    write(1, "Line: ", 6);
    if (!(nb_read = get_next_line(0)))
        return (84);
    if (is_error_line(nb_read, line, matchs, number_of_match))
        return (player_turn(number_of_match, line, matchs));
    write(1, "Matches: ", 9);
    if (!(nb_match_read = get_next_line(0)))
        return (84);
    if (is_error_match(number_of_match, nb_match_read,
                        my_atoi(nb_read), matchs))
        return (player_turn(number_of_match, line, matchs));
    number_of_match[my_atoi(nb_read) - 1] -= my_atoi(nb_match_read);
    write_formalities(nb_match_read, nb_read);
    return (1);
}
