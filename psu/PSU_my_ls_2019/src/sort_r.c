/*
** EPITECH PROJECT, 2020
** my ls
** File description:
** sort r
*/

#include <my.h>

void compare_time(content_list_t **content_l, int *i)
{
    content_list_t *tmp;
    struct stat sb1;
    struct stat sb2;

    lstat(content_l[*i]->path, &sb1);
    lstat(content_l[*i + 1]->path, &sb2);
    if (sb1.st_mtim.tv_sec > sb2.st_mtim.tv_sec) {
        tmp = content_l[*i];
        content_l[*i] = content_l[*i + 1];
        content_l[*i + 1] = tmp;
        *i = 0;
    }
}

int is_sorted_alph(content_list_t **tab, content_list_t *content_list)
{
    for (int i = 0 ; i < list_size(content_list)  - 1 ; i++)
        if (my_strcmp(my_strlowcase(my_strdup(tab[i]->content->d_name)),
                    my_strlowcase(my_strdup(tab[i + 1]->content->d_name))) != 1)
            return (1);
    return (0);
}

static void compare_this_tab(content_list_t **tab, int *i)
{
    content_list_t *tmp;

    if (my_strcmp(my_strlowcase(my_strdup(tab[*i]->content->d_name)),
                my_strlowcase(my_strdup(tab[*i + 1]->content->d_name))) == -1) {
        tmp = tab[*i];
        tab[*i] = tab[*i + 1];
        tab[*i + 1] = tmp;
        *i = 0;
    }
}

content_list_t **sort_tab_alph(content_list_t **tab,
                                content_list_t *content_list)
{
    while (is_sorted_alph(tab, content_list)) {
        for (int i = 0 ; i < list_size(content_list) - 1 ; i++) {
            compare_this_tab(tab, &i);
        }
    }
    return (tab);
}

content_list_t *sort_list_alph(content_list_t *content_list)
{
    content_list_t *new_list = NULL;
    content_list_t *list = content_list;
    content_list_t **content_l = malloc
        (sizeof(content_list_t) * list_size(content_list));

    for (int i = 0 ; list ; ) {
        if (list->content->d_name[0] != '.') {
            content_l[i] = list;
            i++;
        }
        list = list->next;
    }
    content_l = sort_tab_alph(content_l, content_list);
    for (int i = 0 ; i < list_size(content_list) ; i++) {
        insert_new(content_l[i], &new_list);
    }
    return (new_list);
}
