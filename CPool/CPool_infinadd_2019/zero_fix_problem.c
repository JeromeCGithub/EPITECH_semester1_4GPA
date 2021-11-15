/*
** EPITECH PROJECT, 2019
** fix_zero
** File description:
** Fix probleme of zero
*/

#include "include/mylist.h"
#include <stdlib.h>
#include "include/my.h"

linked_list_t *delete_node(linked_list_t *begin, int counter)
{
    linked_list_t *actual = begin;
    linked_list_t *prev = malloc(sizeof(linked_list_t));

    for (int i = 0 ; i < counter ; i++) {
        prev = actual;
        actual = actual->next;
    }
    if (actual->data == 0)
        my_putchar('0');
    return (actual);
}

int number_zero(linked_list_t const *begin)
{
    linked_list_t const *act = begin;
    int counter = 0;

    while (act != NULL) {
        if (act->data == '0')
            counter++;
        else if (act->data != '0')
            counter = 0;
        act = act->next;
    }
    return (counter);
}
