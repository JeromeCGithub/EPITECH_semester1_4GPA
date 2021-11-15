/*
** EPITECH PROJECT, 2019
** my runner
** File description:
** menu input
*/

#include <my.h>

void pause_input_souris(sfRenderWindow *window, sfEvent event, int *is_open)
{
    sfVector2f sprite = convert_vector2f(window, 90, 590);
    sfVector2f sprite_quit = convert_vector2f(window, 1190, 590);
    sfVector2i pos_souris = sfMouse_getPositionRenderWindow(window);

    if (event.type == sfEvtMouseButtonPressed) {
        if (pos_souris.x >= sprite.x + int_cv(window, 65, 0)
            && pos_souris.x <= sprite.x + int_cv(window, 580, 0)
            && pos_souris.y >= sprite.y + int_cv(window, 65, 1)
            && pos_souris.y <= sprite.y + int_cv(window, 175, 1)) {
            *is_open = 0;
        }
        else if (pos_souris.x >= sprite_quit.x + int_cv(window, 65, 0)
                && pos_souris.x <= sprite_quit.x + int_cv(window, 580, 0)
                && pos_souris.y >= sprite_quit.y + int_cv(window, 65, 1)
                && pos_souris.y <= sprite_quit.y + int_cv(window, 175, 1)) {
            sfRenderWindow_close(window);
        }
    }
}

void manage_pause_mouse_quit(sfRenderWindow *window, sfSprite **button)
{
    sfVector2f scale_origin = convert_vector2f(window, 0.2, 0.2);
    sfVector2f scale = convert_vector2f(window, 0.22, 0.22);
    sfVector2f sprite = convert_vector2f(window, 1190, 590);
    sfVector2i pos_souris = sfMouse_getPositionRenderWindow(window);

    if (pos_souris.x >= sprite.x + int_cv(window, 65, 0)
        && pos_souris.x <= sprite.x + int_cv(window, 580, 0)
        && pos_souris.y >= sprite.y + int_cv(window, 65, 1)
        && pos_souris.y <= sprite.y + int_cv(window, 175, 1)) {
        sfSprite_setScale(button[QUIT], scale);
        sfSprite_setPosition(button[QUIT], convert_vector2f(window, 1190, 590));
    }
    else {
        sfSprite_setScale(button[QUIT], scale_origin);
        sfSprite_setPosition(button[QUIT], convert_vector2f(window, 1200, 600));
    }
}

void manage_pause_mouse_play(sfRenderWindow *window, sfSprite **button)
{
    sfVector2f scale_origin = convert_vector2f(window, 0.2, 0.2);
    sfVector2f scale = convert_vector2f(window, 0.22, 0.22);
    sfVector2f sprite = convert_vector2f(window, 90, 590);
    sfVector2i pos_souris = sfMouse_getPositionRenderWindow(window);

    if (pos_souris.x >= sprite.x + int_cv(window, 65, 0)
        && pos_souris.x <= sprite.x + int_cv(window, 580, 0)
        && pos_souris.y >= sprite.y + int_cv(window, 65, 1)
        && pos_souris.y <= sprite.y + int_cv(window, 175, 1)) {
        sfSprite_setScale(button[PLAY], scale);
        sfSprite_setPosition(button[PLAY], convert_vector2f(window, 90, 590));
    }
    else {
        sfSprite_setScale(button[PLAY], scale_origin);
        sfSprite_setPosition(button[PLAY], convert_vector2f(window, 100, 600));
    }
    manage_pause_mouse_quit(window, button);
}
