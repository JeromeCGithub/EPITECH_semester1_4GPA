/*
** EPITECH PROJECT, 2019
** pong
** File description:
** background
*/

#include "../../include/my.h"

back_t *create_background(char const *path)
{
    back_t *back = malloc(sizeof(back_t));

    back->sprite = sfSprite_create();
    back->texture = sfTexture_createFromFile(path, NULL);
    sfSprite_setTexture(back->sprite, back->texture, sfTrue);
    return (back);
}

void destroy_background(back_t *back)
{
    sfSprite_destroy(back->sprite);
    sfTexture_destroy(back->texture);
    free(back);
}
