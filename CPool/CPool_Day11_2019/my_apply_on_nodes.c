/*
** EPITECH PROJECT, 2019
** my_apply_on_nodes
** File description:
** apply to nodes
*/

#include "include/mylist.h"
#include <stdlib.h>

int my_apply_on_nodes(linked_list_t *begin, int (*f)(void *))
{
    linked_list_t *element = begin;

    while (element != NULL)
    {
        (*f)(element->data);
        element = element->next;
    }
    return (0);
}
