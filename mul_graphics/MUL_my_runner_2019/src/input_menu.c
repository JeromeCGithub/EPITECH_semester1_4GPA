/*
** EPITECH PROJECT, 2019
** mr runner
** File description:
** input menu
*/

#include <my.h>

void input_souris(sfRenderWindow *window, map_t *map,
                    sfMusic *music, sfEvent event)
{
    sfVector2f sprite = convert_vector2f(window, 90, 590);
    sfVector2f sprite_quit = convert_vector2f(window, 1190, 590);
    sfVector2i pos_souris = sfMouse_getPositionRenderWindow(window);

    if (event.type == sfEvtMouseButtonPressed) {
        if (pos_souris.x >= sprite.x + int_cv(window, 65, 0)
            && pos_souris.x <= sprite.x + int_cv(window, 580, 0)
            && pos_souris.y >= sprite.y + int_cv(window, 65, 1)
            && pos_souris.y <= sprite.y + int_cv(window, 175, 1)) {
            game_loop(window, map, music, 0);
        }
        else if (pos_souris.x >= sprite_quit.x + int_cv(window, 65, 0)
                && pos_souris.x <= sprite_quit.x + int_cv(window, 580, 0)
                && pos_souris.y >= sprite_quit.y + int_cv(window, 65, 1)
                && pos_souris.y <= sprite_quit.y + int_cv(window, 175, 1)) {
            sfRenderWindow_close(window);
        }
    }
    input_souris_two(window, map, music, event);
}

void input_souris_two(sfRenderWindow *window, map_t *map,
                    sfMusic *music, sfEvent event)
{
    sfVector2f sprite = convert_vector2f(window, 640, 590);
    sfVector2i pos_souris = sfMouse_getPositionRenderWindow(window);

    if (event.type == sfEvtMouseButtonPressed) {
        if (pos_souris.x >= sprite.x + int_cv(window, 65, 0)
            && pos_souris.x <= sprite.x + int_cv(window, 580, 0)
            && pos_souris.y >= sprite.y + int_cv(window, 65, 1)
            && pos_souris.y <= sprite.y + int_cv(window, 175, 1)) {
            game_loop(window, map, music, 1);
        }
    }
}
