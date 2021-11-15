/*
** EPITECH PROJECT, 2019
** subinf
** File description:
** subinf dot c
*/

#include "include/my.h"
#include "include/mylist.h"
#include <stdlib.h>

linked_list_t *lennsup(int **retenue, char *str1,
                        char *str2, linked_list_t *liste)
{
    char tmp = 0;
    int strlen1 = my_strlen(str1);
    int strlen2 = my_strlen(str2);

    for (int j = strlen2 - strlen1 - 1 ; j >= 0 ; j--) {
        tmp = str2[j] - (char)**retenue;
        **retenue = 0;
        if (tmp < 48) {
            **retenue = 1;
            tmp += 10;
        }
        insert(&liste, tmp);
    }
    return (liste);
}

linked_list_t *lenninf(int **retenue, char *str1,
                        char *str2, linked_list_t *liste)
{
    char tmp = 0;
    int strlen1 = my_strlen(str1);
    int strlen2 = my_strlen(str2);

    for (int j = strlen1 - strlen2 - 1 ; j >= 0 ; j--) {
        tmp = str1[j] - (char)**retenue;
        **retenue = 0;
        if (tmp < 48) {
            **retenue = 1;
            tmp += 10;
        }
        insert(&liste, tmp);
    }
    return (liste);
}

linked_list_t *difff_strlen(int *retenue, char *str1,
                            char *str2, linked_list_t *liste)
{
    int strlen1 = my_strlen(str1);
    int strlen2 = my_strlen(str2);

    if (strlen1 < strlen2)
        liste = lennsup(&retenue, str1, str2, liste);
    else if (strlen1 > strlen2)
        liste = lenninf(&retenue, str1, str2, liste);
    return (liste);
}

void fix_bug(linked_list_t *liste)
{
    int counter = 0;

    my_rev_list(&liste);
    counter = number_zero(liste);
    my_rev_list(&liste);
    liste = delete_node(liste, counter);
    display_list(liste);
}

void subinf(int strlen1, int strlen2, char *str1, char *str2)
{
    char tmp;
    int retenue = 0;
    int i = 0;
    linked_list_t *liste = malloc(sizeof(linked_list_t));

    for (i = 1 ; i <= strlen1 && i <= strlen2 ; i++) {
        tmp = str1[strlen1 - i] - (str2[strlen2 - i] - 48) - (char)retenue;
        retenue = 0;
        if (tmp < 48) {
            retenue = 1;
            tmp += 10;
        }
        insert(&liste, tmp);
    }
    if (strlen1 != strlen2)
        liste = difff_strlen(&retenue, str1, str2, liste);
    fix_bug(liste);
    free(liste);
}
