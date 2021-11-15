/*
** EPITECH PROJECT, 2019
** my_pushswap
** File description:
** swap
*/

#include <my.h>

void rra(linked_list_t **list, int list_size)
{
    (*list) = (*list)->prev;
    write(1, "rra ", 4);
}

void rotate(linked_list_t **list, int indice)
{
    (*list) = (*list)->next;
    write(1, "ra ", 3);
}
