/*
** EPITECH PROJECT, 2019
** my_list_size
** File description:
** find the list size
*/

#include "include/mylist.h"
#include <stdlib.h>

int my_list_size(linked_list_t const *begin)
{
    linked_list_t const *act = begin;
    int counter = 0;

    while (act != NULL)
    {
        counter++;
        act = act->next;
    }
    return (counter);
}
