/*
** EPITECH PROJECT, 2019
** my runner
** File description:
** menu
*/

#include <my.h>

static void display_menu(sfRenderWindow *window, game_t *game)
{
    sfRenderWindow_clear(window, sfWhite);
    for (int i = 0 ; i < NB_STACK ; i++)
        sfRenderWindow_drawSprite(window, game->bg->background[i], NULL);
}

static void manage_bg_menu_moove(game_t *game, sfRenderWindow *window)
{
    sfTime time;
    sfVector2f position;
    sfVector2f to_add;

    for (int i = 0 ; i < NB_STACK ; i++) {
        time = sfClock_getElapsedTime(game->bg->clock[i]);
        if (time.microseconds > 4000) {
            to_add.y = 0;
            to_add.x = game->bg->speed[i];
            sfSprite_move(game->bg->background[i], to_add);
            sfClock_restart(game->bg->clock[i]);
        }
        position = sfSprite_getPosition(game->bg->background[i]);
        if (position.x < int_pos_window(window, 1920, 0) * -1) {
            to_add.x = 0;
            sfSprite_setPosition(game->bg->background[i], to_add);
        }
    }
}

static void set_pos_scale_button(sfRenderWindow *window, sfSprite **menu_button)
{
    sfVector2f position[] = {convert_vector2f(window, 470, 100),
                            convert_vector2f(window, 100, 600),
                            convert_vector2f(window, 1200, 600),
                            convert_vector2f(window, 650, 600),
                            convert_vector2f(window, 650, 800)};
    sfVector2f scale[] = {convert_vector2f(window, 0.3, 0.3),
                            convert_vector2f(window, 0.2, 0.2),
                            convert_vector2f(window, 0.2, 0.2),
                            convert_vector2f(window, 0.2, 0.2),
                            convert_vector2f(window, 0.2, 0.2)};

    for (int i = 0 ; i < 4 ; i++) {
        sfSprite_setScale(menu_button[i], scale[i]);
        sfSprite_setPosition(menu_button[i], position[i]);
    }
}

sfSprite **set_button(sfRenderWindow *window)
{
    sfSprite **menu_button = malloc(sizeof(sfSprite *) * 6);
    sfIntRect rectint[] = {{0, 0, 3000, 1000},
                            {3000, 0, 3000, 1000},
                            {6000, 0, 3000, 1000},
                            {12000, 0, 3000, 1000}};
    sfTexture *texture = sfTexture_createFromFile
        ("img/spritesheet_menu.png", NULL);

    for (int i = 0 ; i < 4 ; i++) {
        menu_button[i] = sfSprite_create();
        sfSprite_setTexture(menu_button[i], texture, sfTrue);
        sfSprite_setTextureRect(menu_button[i], rectint[i]);
    }
    set_pos_scale_button(window, menu_button);
    return (menu_button);
}

void menu_loop(sfRenderWindow *window, map_t *map, int inf)
{
    game_t *game = init_menu(window);
    sfSprite **menu_button = set_button(window);
    sfEvent event;
    sfMusic *music = load_music("music/music.ogg");

    (inf) ? (map->inf = 1) : (map->inf = 0);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            (event.type == sfEvtClosed) ? sfRenderWindow_close(window) : event;
            input_souris(window, map, music, event);
        }
        manage_menu_mouse_play(window, menu_button);
        manage_bg_menu_moove(game, window);
        display_menu(window, game);
        for (int i = 0 ; i < 4 ; i++)
            sfRenderWindow_drawSprite(window, menu_button[i], NULL);
        sfRenderWindow_display(window);
    }
    destroy_bg(game->bg);
    destroy_music(music);
}
