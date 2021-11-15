/*
** EPITECH PROJECT, 2019
** ray_casting
** File description:
** intersect
*/

#include <my.h>

static pnt_t *intersect(wall_t *wall, ray_t *ray)
{
    sfVector2f p1 = {wall->start.x, wall->start.y};
    sfVector2f p2 = {wall->end.x, wall->end.y};
    sfVector2f p3 = {ray->pos.x, ray->pos.y};
    sfVector2f p4 = {ray->dir.x + ray->pos.x, ray->dir.y + ray->pos.y};
    float t = 0;
    float u = 0;
    float den = (p1.x - p2.x) * (p3.y - p4.y) - (p1.y - p2.y) * (p3.x - p4.x);

    if (den == 0)
        return (NULL);
    t = ((p1.x - p3.x) * (p3.y - p4.y) - (p1.y - p3.y) * (p3.x - p4.x)) / den;
    u = -((p1.x - p2.x) * (p1.y - p3.y) - (p1.y - p2.y) * (p1.x - p3.x)) / den;
    if (u > 0 && t < 1 && t > 0)
        return (create_point(p1.x + t * (p2.x - p1.x), p1.y + t * (p2.y - p1.y), wall->color));
    return (NULL);
}

pnt_t *find_intersections(wall_t *walls, ray_t *rays, sfVector2f fp_mouse)
{
    float d = 0;
    float a = 0;
    float record = 2147483647;
    pnt_t *closest = NULL;
    pnt_t *pt_list = NULL;
    pnt_t *pt = NULL;

    for (ray_t *ray = rays; ray; ray = ray->next) {
        record = 2147483647;
        closest = NULL;
        for (wall_t *wall = walls; wall; wall = wall->next) {
            pt = intersect(wall, ray);
            if (pt) {
                d = dist(pt->pos, fp_mouse);
                a = rays->angle - ray->angle;
                d *= cos(a);
                if (d < record) {
                    record = d;
                    closest = pt;
                }
            }
        }
        if (closest) {
            closest->next = pt_list;
            pt_list = closest;
        }
    }
    return (pt_list);
}
