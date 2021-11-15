/*
** EPITECH PROJECT, 2019
** btree
** File description:
** btree dot h
*/

typedef struct btree
{
    struct btree *left;
    struct btree *right;
    void *item;
} btree_t;
