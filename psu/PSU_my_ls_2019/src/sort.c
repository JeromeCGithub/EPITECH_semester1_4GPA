/*
** EPITECH PROJECT, 2020
** my ls
** File description:
** sort
*/

#include <my.h>

int is_sorted(content_list_t **content_l, content_list_t *content_list)
{
    struct stat sb1;
    struct stat sb2;

    for (int i = 0 ; i < list_size(content_list) - 1 ; i++) {
        lstat(content_l[i]->path, &sb1);
        lstat(content_l[i + 1]->path, &sb2);
        if (sb1.st_mtim.tv_sec > sb2.st_mtim.tv_sec)
            return (1);
    }
    return (0);
}

content_list_t **sort_tab(content_list_t **content_l,
                            content_list_t *content_list)
{
    struct stat sb1;
    struct stat sb2;
    content_list_t *tmp;

    while (is_sorted(content_l, content_list)) {
        for (int i = 0 ; i < list_size(content_list) - 1 ; i++) {
            compare_time(content_l, &i);
        }
    }
    return (content_l);
}

content_list_t *sort_list_t_flag(content_list_t *content_list)
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
    content_l = sort_tab(content_l, content_list);
    for (int i = 0 ; i < list_size(content_list) ; i++) {
        insert_new(content_l[i], &new_list);
    }
    return (new_list);
}

void my_cmp_swap(int i, int j, char **av)
{
    char *tmp;

    if (my_strcmp(my_strlowcase(my_strdup(av[j])),
                    my_strlowcase(my_strdup(av[i]))) == 1) {
        tmp = av[i];
        av[i] = av[j];
        av[j] = tmp;
    }
}

char **pre_sort(int ac, char **av)
{
    for (int i = 1 ; i < ac  ; i++) {
        for (int j = 1 ; j < ac ; j++) {
            my_cmp_swap(i, j, av);
        }
    }
    return (av);
}
