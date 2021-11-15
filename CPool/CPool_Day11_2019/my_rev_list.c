/*
** EPITECH PROJECT, 2019
** my_params_to_list
** File description:
** put param in chained list
*/

#include "include/mylist.h"
#include <stdlib.h>

void my_rev_list(linked_list_t **begin)
{
    linked_list_t *previous = malloc(sizeof(linked_list_t));
    linked_list_t *curent = malloc(sizeof(linked_list_t));
    linked_list_t *after = malloc(sizeof(linked_list_t));

    previous = NULL;
    curent = *begin;
    after = NULL;
    while (curent != NULL)
    {
        after = curent->next;
        curent->next = previous;
        previous = curent;
        curent = after;
    }
    *begin = previous;
}
