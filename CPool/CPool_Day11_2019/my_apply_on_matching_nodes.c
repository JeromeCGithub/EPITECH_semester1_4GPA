/*
** EPITECH PROJECT, 2019
** my_apply_on_matching_nodes
** File description:
** matching nodes applwy
*/

#include "include/mylist.h"
#include <stdlib.h>

int my_apply_on_matching_nodes(linked_list_t *begin, int (*f)(),
                                void const *data_ref, int (*cmp)())
{
    linked_list_t *element = begin;

    while (element != NULL) {
        if ((*cmp)(element->data, data_ref) == 0) {
            (*f)(element->data);
        }
        element = element->next;
    }
    return (0);
}
