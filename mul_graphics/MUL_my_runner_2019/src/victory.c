/*
** EPITECH PROJECT, 2019
** my runner
** File description:
** game over
*/

#include <my.h>

static void set_scale_vict(pause_t *pause, sfRenderWindow *window)
{
    sfVector2f position[] = {{100, 600}, {1200, 600}, {650, 600}, {650, 600}};
    sfVector2f scale[] = {{0.2, 0.2}, {0.2, 0.2}, {0.2, 0.2}, {0.2, 0.2}};

    for (int i = 1 ; i < 4 ; i++) {
        sfSprite_setScale(pause->element[i], scale[i]);
        sfSprite_setPosition(pause->element[i], position[i - 1]);
    }
}

void victory_souris_two(sfRenderWindow *window, sfEvent event, game_t *game)
{
    sfVector2f sprite = convert_vector2f(window, 640, 590);
    sfVector2i pos_souris = sfMouse_getPositionRenderWindow(window);

    if (event.type == sfEvtMouseButtonPressed) {
        if (pos_souris.x >= sprite.x + int_cv(window, 65, 0)
            && pos_souris.x <= sprite.x + int_cv(window, 580, 0)
            && pos_souris.y >= sprite.y + int_cv(window, 65, 1)
            && pos_souris.y <= sprite.y + int_cv(window, 175, 1)) {
            game->map->map = game->map->map_origin;
            game_loop(window, game->map, game->music, game->inf);
        }
    }
}

void victory_souris(sfRenderWindow *window, sfEvent event, game_t *game)
{
    sfVector2f sprite = convert_vector2f(window, 90, 590);
    sfVector2f sprite_quit = convert_vector2f(window, 1190, 590);
    sfVector2i pos_souris = sfMouse_getPositionRenderWindow(window);

    if (event.type == sfEvtMouseButtonPressed) {
        if (pos_souris.x >= sprite.x + int_cv(window, 65, 0)
            && pos_souris.x <= sprite.x + int_cv(window, 580, 0)
            && pos_souris.y >= sprite.y + int_cv(window, 65, 1)
            && pos_souris.y <= sprite.y + int_cv(window, 175, 1)) {
            game->map = next_map(game->map->map_name, game);
            game_loop(window, game->map, game->music, game->inf);
        }
        else if (pos_souris.x >= sprite_quit.x + int_cv(window, 65, 0)
                && pos_souris.x <= sprite_quit.x + int_cv(window, 580, 0)
                && pos_souris.y >= sprite_quit.y + int_cv(window, 65, 1)
                && pos_souris.y <= sprite_quit.y + int_cv(window, 175, 1)) {
            sfRenderWindow_close(window);
        }
    }
    victory_souris_two(window, event, game);
}

pause_t *init_victory(sfRenderWindow *window)
{
    pause_t *pause = malloc(sizeof(pause_t));
    sfTexture *spritesheet = sfTexture_createFromFile
        ("img/sprite_pause.png", NULL);
    sfVector2f scale = {1, 0.92};
    sfIntRect position[] = {{0, 0, 1920, 1080}, {10920, 0, 3000, 1000},
                            {4920, 0, 3000, 1000}, {7920, 0, 3000, 1000}};

    for (int i = 0 ; i < 4 ; i++)
        pause->element[i] = sfSprite_create();
    for (int i = 0 ; i < 4 ; i++)
        sfSprite_setTexture(pause->element[i], spritesheet, sfTrue);
    for (int i = 0 ; i < 4 ; i++)
        sfSprite_setTextureRect(pause->element[i], position[i]);
    sfSprite_scale(pause->element[0], scale);
    set_scale_vict(pause, window);
    return (pause);
}

void victory_menu(sfRenderWindow *window, game_t *game)
{
    sfEvent event;
    pause_t *victory = init_victory(window);

    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            victory_souris(window, event, game);
            (event.type == sfEvtClosed) ? sfRenderWindow_close(window) : event;
        }
        manage_victory_mouse_play(window, victory->element);
        display_game_menu(window, game);
        for (int i = 0 ; i < 4 ; i++)
            sfRenderWindow_drawSprite(window, victory->element[i], NULL);
        sfRenderWindow_display(window);
    }
}
