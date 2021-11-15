/*
** EPITECH PROJECT, 2019
** infinadd main
** File description:
** main of infinadd
*/

#include "include/my.h"
#include "include/mylist.h"
#include <stdlib.h>

linked_list_t *lensup(int **retenue, char *str1,
                        char *str2, linked_list_t *liste)
{
    char tmp = 0;
    int strlen1 = my_strlen(str1);
    int strlen2 = my_strlen(str2);

    for (int j = strlen2 - strlen1 - 1; j >= 0 ; j--) {
        tmp = str2[j] + (char)**retenue;
        **retenue = 0;
        if (tmp > 57) {
            **retenue = 1;
            tmp -= 10;
        }
        insert(&liste, tmp);
    }
    return (liste);
}

linked_list_t *leninf(int **retenue, char *str1,
                        char *str2, linked_list_t *liste)
{
    char tmp = 0;
    int strlen1 = my_strlen(str1);
    int strlen2 = my_strlen(str2);

    for (int j = strlen1 - strlen2 - 1; j >= 0 ; j--) {
        tmp = str1[j] + (char)**retenue;
        **retenue = 0;
        if (tmp > 57) {
            **retenue = 1;
            tmp -= 10;
        }
        insert(&liste, tmp);
    }
    return (liste);
}
linked_list_t *diff_strlen(int *retenue, char *str1,
                            char *str2, linked_list_t *liste)
{
    int strlen1 = my_strlen(str1);
    int strlen2 = my_strlen(str2);

    if (strlen1 < strlen2)
        liste = lensup(&retenue, str1, str2, liste);
    else if (strlen1 > strlen2)
        liste = leninf(&retenue, str1, str2, liste);
    return (liste);
}

void addinf(int strlen1, int strlen2, char *str1, char *str2)
{
    char tmp;
    int retenue = 0;
    int i = 0;
    linked_list_t *liste = malloc(sizeof(linked_list_t));

    for (i = 1 ; i <= strlen1 && i <= strlen2 ; i++) {
        tmp = str1[strlen1 - i] + (str2[strlen2 - i] - 48) + (char)retenue;
        retenue = 0;
        if (tmp > 57) {
            retenue = 1;
            tmp -= 10;
        }
        insert(&liste, tmp);
    }
    if (strlen1 != strlen2)
        liste = diff_strlen(&retenue, str1, str2, liste);
    if (retenue == 1)
        my_putchar('1');
    display_list(liste);
    free(liste);
}

int main(int ac, char **av)
{
    int strlen1 = 0;
    int strlen2 = 0;

    strlen1 = my_strlen(av[1]);
    strlen2 = my_strlen(av[2]);
    if (av[1][0] == '-' && av[2][0] == '-') {
        my_putchar('-');
        addinf(strlen1 - 1, strlen2 - 1, &av[1][1], &av[2][1]);
    }
    else if (av[1][0] == '-' || av[2][0] == '-') {
        if (av[1][0] == '-')
            my_supnbr(strlen1 - 1, strlen2, av[1], av[2]);
        else if (av[2][0] == '-')
            my_supnbr(strlen1, strlen2 - 1, av[1], av[2]);
    }
    else
        addinf(strlen1, strlen2, av[1], av[2]);
    return (0);
}
