/*
** EPITECH PROJECT, 2019
** ray_casting
** File description:
** display
*/

#include <my.h>

void display_walls(sfRenderWindow *window, wall_t *walls)
{
    if (!walls)
        return;
    sfRenderWindow_drawVertexArray(window, walls->vertex, NULL);
    display_walls(window, walls->next);
}

void display_pt(sfRenderWindow *window, pnt_t *pt)
{
    if (!pt)
        return;
    sfRenderWindow_drawCircleShape(window, pt->cir, NULL);
    display_pt(window, pt->next);
}

void display_rays(sfRenderWindow *window, ray_t *ray)
{
    if (!ray || !ray->vertex)
        return;
    sfRenderWindow_drawVertexArray(window, ray->vertex, NULL);
    display_rays(window, ray->next);
}
