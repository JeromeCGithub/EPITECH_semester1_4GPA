/*
** EPITECH PROJECT, 2019
** bonus
** File description:
** main
*/

#include <my.h>

void mouse_move(sfRenderWindow *window, sfVector2f *view)
{
    sfVector2i fix_pos = {WIDTH / 2 + WIDTH, HEIGHT / 2};
    sfVector2i pos = {0, 0};

    pos = sfMouse_getPositionRenderWindow(window);
    if (pos.x > fix_pos.x)
        view->x += (pos.x - fix_pos.x) / 2.0;
    if (pos.x < fix_pos.x)
        view->x -= (fix_pos.x - pos.x) / 2.0;
    if (pos.y > fix_pos.y)
        view->y -= (pos.y - fix_pos.y);
    if (pos.y < fix_pos.y)
        view->y += (fix_pos.y - pos.y);
    sfMouse_setPositionRenderWindow(fix_pos, window);
}

static void window_event(sfRenderWindow *window, float view, sfVector2f *fp_mouse)
{
    sfEvent event;
    float angle = (view + 10) / 180.0 * M_PI;

    if (sfKeyboard_isKeyPressed(sfKeyZ)) {
        fp_mouse->x += cos(angle) * 10;
        fp_mouse->y += sin(angle) * 10;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        fp_mouse->x -= cos(angle) * 10;
        fp_mouse->y -= sin(angle) * 10;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        fp_mouse->x += cos(angle - M_PI / 2) * 10;
        fp_mouse->y += sin(angle - M_PI / 2) * 10;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        fp_mouse->x -= cos(angle - M_PI / 2) * 10;
        fp_mouse->y -= sin(angle - M_PI / 2) * 10;
    }
    if (sfKeyboard_isKeyPressed(sfKeyEscape))
        sfRenderWindow_close(window);
}

int main(int ac, char **av)
{
    sfVideoMode mode = {WIDTH * 2, HEIGHT, BPX};
    sfRenderWindow *window = sfRenderWindow_create(mode, "RayCasting", sfResize | sfClose, NULL);
    wall_t *walls = new_walls(av[1]);
    ray_t *rays = NULL;
    ray_t *look_at_wall = NULL;
    ray_t *wall_cast = NULL;
    pnt_t *pt_list = NULL;
    sfVector2f fp_mouse = {WIDTH / 2, HEIGHT / 2};
    sfVector2f view = {0, 0};
    
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        window_event(window, view.x, &fp_mouse);
        pt_list = find_intersections(walls, rays, fp_mouse);
        mouse_move(window, &view);
        destroy_rays(&rays);
        rays = new_rays(5, fp_mouse, view.x);
        look_at_wall = rays_on_wall(fp_mouse, pt_list);
        wall_cast = redirect_rays(fp_mouse, pt_list, view.y);
        display_pt(window, pt_list);
        display_walls(window, walls);
        display_rays(window, look_at_wall);
        display_rays(window, wall_cast);
        sfRenderWindow_display(window);
        destroy_rays(&look_at_wall);
        destroy_rays(&wall_cast);
        destroy_pt(pt_list);
    }
    sfRenderWindow_destroy(window);
    destroy_walls(walls);
    return (0);
}
