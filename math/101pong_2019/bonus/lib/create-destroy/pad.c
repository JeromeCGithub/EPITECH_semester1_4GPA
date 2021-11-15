/*
** EPITECH PROJECT, 2019
** pong
** File description:
** pad
*/

#include "../../include/my.h"

pad_t *create_pad(float x, float y, float x1, float y1)
{
    pad_t *pad = malloc(sizeof(pad_t));

    pad->pnts = 0;
    pad->size.x = x1;
    pad->size.y = y1;
    pad->rect = sfRectangleShape_create();
    pad->pos.x = x;
    pad->pos.y = y;
    sfRectangleShape_setFillColor(pad->rect, sfWhite);
    sfRectangleShape_setSize(pad->rect, pad->size);
    sfRectangleShape_setPosition(pad->rect, pad->pos);
    return (pad);
}

void destroy_pad(pad_t *pad)
{
    sfRectangleShape_destroy(pad->rect);
    free(pad);
}
