/*
** EPITECH PROJECT, 2019
** mylist
** File description:
** my list chaine
*/

#ifndef MYLIST_H_
# define MYLIST_H_

typedef struct linked_list
{
    void *data;
    struct linked_list *next;
} linked_list_t;

void insert(linked_list_t **liste, char *nv);

#endif
