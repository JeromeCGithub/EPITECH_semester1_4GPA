/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** display
*/

#include <my.h>

void display_list(linked_list_t *list)
{
    linked_list_t *last = list;
    linked_list_t *element = list;

    if (list == NULL)
        return;
    while (element->next != last) {
        my_put_nbr(element->nb);
        write(1, ", ", 2);
        element = element->next;
    }
    my_put_nbr(element->nb);
}
