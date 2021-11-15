/*
** EPITECH PROJECT, 2019
** my_find_node
** File description:
** find a node
*/

#include "include/mylist.h"
#include <stdlib.h>

linked_list_t *my_find_node(linked_list_t const *begin,
                            void const *data_ref, int (*cmp)())
{
    linked_list_t *element = begin;

    while (element != NULL)
    {
        if ((*cmp)(element->data, data_ref) == 0)
            return (element);
        element = element->next;
    }
    return (NULL);
}
