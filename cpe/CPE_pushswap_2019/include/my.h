/*
** EPITECH PROJECT, 2019
** my_pushswap
** File description:
** include pushswap
*/

#include <unistd.h>
#include "struct.h"
#include <stdlib.h>

#ifndef MY_H_

enum { A, B };

linked_list_t **delete_first_elem(linked_list_t **list);
linked_list_t **put_in_begin(linked_list_t **list, int nb);
void insert(linked_list_t **list, int nb);
void rra(linked_list_t **list, int list_size);
int radix_s(int ac, char **av);
void pa(linked_list_t **list_b, linked_list_t **list_a);
int get_last(linked_list_t *list);
void pb(linked_list_t **list_a, linked_list_t **list_b);
void rotate(linked_list_t **list, int indice);
int is_sorted(linked_list_t *list);
void my_putchar(char c);
void my_put_nbr(int nb);
int my_getnbr(char const *str);
linked_list_t *init_list_a(int ac, char **av);

#endif
