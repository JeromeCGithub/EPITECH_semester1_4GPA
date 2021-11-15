/*
** EPITECH PROJECT, 2019
** compare_language
** File description:
** compare the different language.
*/

#include "include/my.h"

void what_to_print(int tmp, int av_ge, int av_sp)
{
    if (tmp == av_ge)
        print_ge();
    else if (tmp == av_sp)
        print_sp();
}

void abss(int *abs1, int *abs2)
{
    if (*abs1 < 0)
        *abs1 = *abs1 * (-1);
    if (*abs2 < 0)
        *abs2 = *abs2 * (-1);
}

void compare_language(int av_let, int av_en, int av_fr, int av_ge, int av_sp)
{
    int tmp = av_en;
    int tab[4] = {av_en, av_fr, av_ge, av_sp};
    int abs1 = 0;
    int abs2 = 0;

    for (int i = 1 ; i < 4 ; i++) {
        abs1 = tab[i] - av_let;
        abs2 = tmp - av_let;
        abss(&abs1, &abs2);
        if (abs1 < abs2)
            tmp = tab[i];
    }
    if (tmp == av_en)
        print_en();
    else if (tmp == av_fr)
        print_fr();
    else
        what_to_print(tmp, av_ge, av_sp);
}
