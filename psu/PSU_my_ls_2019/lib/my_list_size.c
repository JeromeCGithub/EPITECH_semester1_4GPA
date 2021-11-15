/*
** EPITECH PROJECT, 2020
** my ls
** File description:
** list size
*/

#include <my.h>

int list_size(content_list_t *content_list)
{
    int nb = 0;
    content_list_t *list = content_list;

    for (nb = 0 ; list ; list = list->next)
        if (list->content->d_name[0] != '.')
            nb++;
    return (nb);
}
