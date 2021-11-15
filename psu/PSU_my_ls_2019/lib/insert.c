/*
** EPITECH PROJECT, 2019
** my_params_to_list
** File description:
** put param in chained list
*/

#include <my.h>

void insert_new(content_list_t *content, content_list_t **new_list)
{
    content_list_t *element = malloc(sizeof(content_list_t));

    element->path = content->path;
    element->content = content->content;
    element->next = *new_list;
    *new_list = element;
}

void insert(content_list_t **liste, struct dirent *content, char *path)
{
    content_list_t *element = malloc(sizeof(content_list_t));

    if (path[my_strlen(path) - 1] != '/')
        path = my_strcat(path, "/");
    element->content = content;
    element->path = my_strcat(path, element->content->d_name);
    element->next = *liste;
    *liste = element;
}
