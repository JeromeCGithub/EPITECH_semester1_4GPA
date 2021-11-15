/*
** EPITECH PROJECT, 2019
** my_params_to_list
** File description:
** put param in chained list
*/

#include "../../include/mylist.h"
#include <stdlib.h>

void insert(linked_list_t **liste, char nv)
{
    linked_list_t *element = malloc(sizeof(element));

    element->data = nv;
    element->next = *liste;
    *liste = element;
}
