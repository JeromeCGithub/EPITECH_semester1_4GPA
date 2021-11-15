/*
** EPITECH PROJECT, 2019
** ray_casting
** File description:
** rays
*/

#include <my.h>

ray_t *new_rays(size_t nb, sfVector2f p_mouse, float view)
{
    ray_t *rays = NULL;
    sfColor color = sfColor_fromRGBA(255, 255, 255, 1);
    sfVector2f pos = {0, 0};
    sfVector2f dir = {0, 0};

    for (float angle = view / 180.0 * M_PI; angle < (float)(ANGLE + view) / 180.0 * M_PI; angle += 0.001) {
        pos.x = p_mouse.x;
        pos.y = p_mouse.y;
        dir.x = cos(angle);
        dir.y = sin(angle);
        rays = create_ray(rays, pos, dir, color);
        rays->angle = angle;
    }
    return (rays);
}

ray_t *redirect_rays(sfVector2f fp_mouse, pnt_t *pt_list, float view)
{
    ray_t *ray = NULL;
    sfColor color;
    sfVector2f pos = {0, 0};
    sfVector2f dir = {0, HEIGHT};
    float i = 0;
    float d = 0;
    float d_max = sqrt(pow(WIDTH, 2) + pow(HEIGHT, 2));
    float nb_points = 0;
    float alpha = 0;

    for (pnt_t *pt = pt_list; pt; pt = pt->next, nb_points++);
    for (pnt_t *pt = pt_list; pt; pt = pt->next, i++) {
        d = dist(fp_mouse, pt->pos);
        d = d / d_max * HEIGHT;
        d = HEIGHT - d;
        alpha = d * ratio;
        if (alpha < 0)
            alpha = 0;
        if (alpha > 255)
            alpha = 255;
        color = sfColor_fromRGBA(pt->color.r, pt->color.g, pt->color.b, alpha);
        pos.x = i * WIDTH / nb_points + WIDTH;
        pos.y = HEIGHT / 2 - d / 2 + view;
        dir.x = pos.x;
        dir.y = HEIGHT / 2 + d / 2 + view;
        ray = create_ray(ray, pos, dir, color);
        sfVertexArray_destroy(ray->vertex);
        ray->vertex = create_vertex_array(pos, dir.x, dir.y, color);
    }
    return (ray);
}

ray_t *rays_on_wall(sfVector2f fp_mouse, pnt_t *pt_list)
{
    ray_t *ray = NULL;
    sfColor color = sfColor_fromRGBA(255, 255, 255, 50);
    sfVector2f pos = {fp_mouse.x, fp_mouse.y};
    sfVector2f dir = {0, 0};
    int i = 0;

    for (pnt_t *pt = pt_list; pt; pt = pt->next, i++) {
        dir.x = pt->pos.x - pos.x;
        dir.y = pt->pos.y - pos.y;
        ray = create_ray(ray, pos, dir, color);
    }
    return (ray);
}

ray_t *create_ray(ray_t *rays, sfVector2f pos, sfVector2f dir, sfColor color)
{
    ray_t *ray = malloc(sizeof(ray_t));

    ray->pos.x = pos.x;
    ray->pos.y = pos.y;
    ray->dir.x = dir.x;
    ray->dir.y = dir.y;
    ray->vertex = create_vertex_array(ray->pos, dir.x + pos.x, dir.y + pos.y, color);
    ray->next = rays;
    rays = ray;
    return (rays);
}

static void empty_rays(ray_t *rays)
{
    ray_t *next = NULL;

    for (ray_t *actual = rays->next; actual; actual = next) {
        next = actual->next;
        sfVertexArray_destroy(actual->vertex);
        free(actual);
    }
}

void destroy_rays(ray_t **rays)
{
    if (!*rays)
        return;
    empty_rays(*rays);
    free(*rays);
}
