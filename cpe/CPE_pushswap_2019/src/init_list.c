/*
** EPITECH PROJECT, 2019
** my_pushswap
** File description:
** init list
*/

#include "../include/my.h"
#include <stdlib.h>

void insert(linked_list_t **list, int nb)
{
    linked_list_t *new_node;
    linked_list_t *element;

    if (*list == NULL) {
        element = malloc(sizeof(linked_list_t));
        element->nb = nb;
        element->prev = element;
        element->next = element;
        *list = element;
        return;
    }
    element = (*list)->prev;
    new_node = malloc(sizeof(linked_list_t));
    new_node->nb = nb;
    new_node->next = *list;
    (*list)->prev = new_node;
    new_node->prev = element;
    element->next = new_node;
}

int is_sorted(linked_list_t *list)
{
    linked_list_t *element = list;

    while (element->next != list) {
        if (element->nb > element->next->nb)
            return (0);
        element = element->next;
    }
    return (1);
}

linked_list_t *init_list_a(int ac, char **av)
{
    linked_list_t *list = NULL;

    for (int i = 1 ; i < ac ; i++)
        insert(&list, my_getnbr(av[i]));
    return (list);
}
