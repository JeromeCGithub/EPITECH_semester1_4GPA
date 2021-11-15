/*
** EPITECH PROJECT, 2019
** btree_create_node
** File description:
** create node
*/

#include <stdlib.h>
#include <stdio.h>
#include <btree.h>

btree_t *btree_create_node(void *item)
{
    btree_t *node = malloc(sizeof(btree_t));
    
    node->item = item;
    node->left = NULL;
    node->right = NULL;
    return (node);
}
