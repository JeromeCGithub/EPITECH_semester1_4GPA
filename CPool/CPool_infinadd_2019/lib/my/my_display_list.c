/*
** EPITECH PROJECT, 2019
** displayl ist
** File description:
** lol
*/

#include "../../include/mylist.h"
#include <stdlib.h>

void my_putchar(char c);

void display_list(linked_list_t *list)
{
    linked_list_t *actual = list;

    while (actual != NULL) {
        my_putchar(actual->data);
        actual = actual->next;
    }
    my_putchar('\n');
}
