/*
** EPITECH PROJECT, 2019
** ray_casting
** File description:
** pt
*/

#include <my.h>

pnt_t *create_point(float x, float y, sfColor color)
{
    pnt_t *pt = malloc(sizeof(pnt_t));
    sfVector2f origin = {5, 5};

    pt->color = color;
    pt->pos.x = x;
    pt->pos.y = y;
    pt->cir = sfCircleShape_create();
    sfCircleShape_setOrigin(pt->cir, origin);
    sfCircleShape_setPosition(pt->cir, pt->pos);
    sfCircleShape_setRadius(pt->cir, 5);
    sfCircleShape_setFillColor(pt->cir, color);
    return (pt);
}

void destroy_pt(pnt_t *pt)
{
    pnt_t *next = NULL;

    for (pnt_t *actual = pt; actual; actual = next) {
        next = actual->next;
        sfCircleShape_destroy(actual->cir);
        free(actual);
    }
}
