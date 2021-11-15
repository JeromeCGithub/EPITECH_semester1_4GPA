/*
** EPITECH PROJECT, 2019
** main
** File description:
** main program of the rush.
*/

#include "include/my.h"
#include <unistd.h>

int my_strlen_without_space(char *str)
{
    int number_of_letter = 0;

    for (int i = 0 ; str[i] != '\0' ; i++) {
        if ((str[i] <= 'z' && str[i] >= 'a')
            || (str[i] <= 'Z' && str[i] >= 'A'))
            number_of_letter++;
    }
    return (number_of_letter);
}

void print_it(char c, int percentage_ent, int percentage_dec, int occurence)
{
    my_putchar(c);
    my_putchar(':');
    my_put_nbr(occurence);
    my_putchar(' ');
    my_putchar('(');
    my_put_nbr(percentage_ent);
    my_putchar('.');
    if (percentage_dec == 0)
        my_put_nbr(0);
    my_put_nbr(percentage_dec);
    my_putchar('%');
    my_putchar(')');
    my_putchar('\n');
}

int occurence_of_the_letter(char c, char *av)
{
    int number_of_occurence = 0;
    int number_of_letter = 0;
    int percentage_ent = 0;
    int percentage_dec = 0;

    number_of_letter = my_strlen_without_space(av);
    if (c <= 'Z' && c >= 'A')
        my_strupcase(av);
    else if (c <= 'z' && c >= 'a')
        my_strlowcase(av);
    for (int i = 0 ; av[i] != '\0' ; i++) {
        if (av[i] == c)
            number_of_occurence++;
    }
    percentage_ent = number_of_occurence * 100 / number_of_letter;
    percentage_dec = number_of_occurence * 10000 / number_of_letter % 100;
    print_it(c, percentage_ent, percentage_dec, number_of_occurence);
    return (number_of_occurence * 100000 / number_of_letter);
}

int count_occurence_of_each_letter(char **av)
{
    int average = 0;

    for (int i = 2 ; av[i] != 0 ; i++)
        average = average + occurence_of_the_letter(av[i][0], av[1]);
    return (average);
}

int main(int argc, char **argv)
{
    int average_letter = 0;
    int av_en = 0;
    int av_fr = 0;
    int av_sp = 0;
    int av_ge = 0;

    if (is_error(argc, argv) == 1) {
        write(2, "Stop: there is an error in the arguments.\n", 42);
        return (84);
    }
    average_letter = count_occurence_of_each_letter(argv);
    av_en = en(argv);
    av_fr = fr(argv);
    av_sp = sp(argv);
    av_ge = ge(argv);
    compare_language(average_letter, av_en, av_fr, av_ge, av_sp);
    return (0);
}
