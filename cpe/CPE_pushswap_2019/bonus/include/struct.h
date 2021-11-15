/*
** EPITECH PROJECT, 2019
** my_pushswap
** File description:
** linked list struct
*/

#ifndef STRUCT_H_

typedef struct linked_list {
    int nb;
    sfRectangleShape *rect;
    struct linked_list *next;
    struct linked_list *prev;
} linked_list_t;

typedef struct char_list {
    char *print;
    struct char_list *next;
} char_list_t;

#endif
