/*
** EPITECH PROJECT, 2019
** my_pushswap
** File description:
** radix
*/

#include <my.h>

linked_list_t **sort_list(linked_list_t **list, int *len, int bit)
{
    int i = 0;

    while (i < len[A]) {
        if (((list[A])->nb >> bit & 1) == 0) {
            len[A] = len[A] - 1;
            len[B] = len[B] + 1;
            pb(&list[A], &list[B]);
        } else {
            rotate(&list[A], 0);
            i++;
        }
    }
    i = 0;
    while (i < len[B]) {
        len[B] -= 1;
        len[A] += 1;
        pa(&list[A], &list[B]);
    }
    return (list);
}

linked_list_t **manage_negative_number(linked_list_t **list, int len_a)
{
    int nb_neg = 0;
    linked_list_t *element = list[A];

    while (element->next != list[A]) {
        if (element->nb < 0)
            nb_neg++;
        element = element->next;
    }
    if (element->nb < 0)
        nb_neg++;
    for (int i = 0 ; i < nb_neg ; i++) {
        rra(&list[A], len_a);
    }
    return (list);
}

int radix_s(int ac, char **av)
{
    linked_list_t **list = malloc(sizeof(linked_list_t *) * 2);
    int *len = malloc(sizeof(int) * 2);

    len[A] = ac - 1;
    len[B] = 0;
    list[A] = init_list_a(ac, av);
    list[B] = NULL;
    if (is_sorted(list[A]) == 1) {
        write(1, "\n", 1);
        return (0);
    }
    for (int bit = 0 ; bit < 32 && !is_sorted(list[A]) ; bit++)
        list = sort_list(list, len, bit);
    list = manage_negative_number(list, len[A]);
    write(1, "sb\n", 3);
    return (0);
}
