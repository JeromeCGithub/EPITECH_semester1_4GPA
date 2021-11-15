/*
** EPITECH PROJECT, 2019
** my runner
** File description:
** resize
*/

#include <my.h>

void resize(sfRenderWindow *window, game_t *game, sfSprite **menu_button)
{
    sfVideoMode mode1 = {1920, 1080, 32};
    sfVideoMode mode2 = {1280, 720, 32};

    if (sfKeyboard_isKeyPressed(sfKeyA)) {
        sfRenderWindow_close(window);
        sfRenderWindow_destroy(window);
        window = sfRenderWindow_create(mode2, "Christmas runner",
                                        sfResize | sfClose, NULL);
        game = init_menu(window);
        menu_button = set_button(window);
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)) {
        sfRenderWindow_close(window);
        sfRenderWindow_destroy(window);
        window = sfRenderWindow_create(mode1, "Christmas runner",
                                        sfResize | sfClose, NULL);
        game = init_menu(window);
        menu_button = set_button(window);
    }
}
