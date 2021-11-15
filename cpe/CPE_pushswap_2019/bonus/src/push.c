/*
** EPITECH PROJECT, 2019
** pushswap
** File description:
** manage list
*/

#include <my.h>

void pb(linked_list_t **list_a, linked_list_t **list_b)
{
    if (list_a == NULL)
        return;
    list_b = put_in_begin(list_b, (*list_a)->nb);
    list_a = delete_first_elem(list_a);
    write(1, "pb ", 3);
}

void pa(linked_list_t **list_b, linked_list_t **list_a)
{
    if (list_a == NULL)
        return;
    list_b = put_in_begin(list_b, (*list_a)->nb);
    list_a = delete_first_elem(list_a);
    write(1, "pa ", 3);
}

linked_list_t **delete_first_elem(linked_list_t **list)
{
    linked_list_t *element;

    if ((*list)->next == *list)
        element = NULL;
    else {
        element = (*list)->next;
        (*list)->prev->next = (*list)->next;
        (*list)->next->prev = (*list)->prev;
    }
    (*list) = element;
    return (list);
}

linked_list_t **put_in_begin(linked_list_t **list, int nb)
{
    linked_list_t *node = malloc(sizeof(linked_list_t));

    if (node == NULL)
        return (NULL);
    node->nb = nb;
    node->rect = sfRectangleShape_create();
    if (*list == NULL) {
        node->next = node;
        node->prev = node;
        *list = node;
    }
    else {
        node->next = (*list);
        node->prev = (*list)->prev;
        (*list)->prev->next = node;
        (*list)->prev = node;
        (*list) = node;
    }
    return (list);
}
