/*
** EPITECH PROJECT, 2019
** my runner
** File description:
** pause menu
*/

#include <my.h>

void set_scale(pause_t *pause, sfRenderWindow *window)
{
    sfVector2f position[] = {{100, 600}, {1200, 600}, {650, 600}};
    sfVector2f scale[] = {{0.2, 0.2}, {0.2, 0.2}, {0.2, 0.2}};

    for (int i = 1 ; i < 3 ; i++) {
        sfSprite_setScale(pause->element[i], scale[i]);
        sfSprite_setPosition(pause->element[i], position[i - 1]);
    }
}

pause_t *init_pause(sfRenderWindow *window)
{
    pause_t *pause = malloc(sizeof(pause_t));
    sfTexture *spritesheet = sfTexture_createFromFile
        ("img/sprite_pause.png", NULL);
    sfVector2f scale = {1, 0.92};
    sfIntRect position[3] = {{0, 0, 1920, 1080}, {1920, 0, 3000, 1000},
                            {4920, 0, 3000, 1000}};

    for (int i = 0 ; i < 3 ; i++)
        pause->element[i] = sfSprite_create();
    for (int i = 0 ; i < 3 ; i++)
        sfSprite_setTexture(pause->element[i], spritesheet, sfTrue);
    for (int i = 0 ; i < 3 ; i++)
        sfSprite_setTextureRect(pause->element[i], position[i]);
    sfSprite_scale(pause->element[0], scale);
    set_scale(pause, window);
    return (pause);
}

void display_game_menu(sfRenderWindow *window, game_t *game)
{
    bird_t *the_bird = game->bird_fly;
    obstacle_t *obs = game->obs;

    sfRenderWindow_clear(window, sfWhite);
    for (int i = 0 ; i < NB_STACK ; i++)
        sfRenderWindow_drawSprite(window, game->bg->background[i], NULL);
    while (obs) {
        sfRenderWindow_drawSprite(window, obs->sprite_obs, NULL);
        obs = obs->next_obs;
    }
    while (the_bird) {
        sfRenderWindow_drawSprite(window, the_bird->bird_sprite, NULL);
        the_bird = the_bird->next;
    }
    sfRenderWindow_drawSprite(window, game->player->player_sprite, NULL);
    sfRenderWindow_drawText(window, game->score_txt, NULL);
}

void pause_menu(sfRenderWindow *window, game_t *game)
{
    int is_open = 1;
    sfEvent event;
    pause_t *pause = init_pause(window);

    if (game->inf)
        init_score(pause, window, game->score);
    while (sfRenderWindow_isOpen(window) && is_open) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            pause_input_souris(window, event, &is_open);
            (event.type == sfEvtClosed) ? sfRenderWindow_close(window) : event;
        }
        manage_pause_mouse_play(window, pause->element);
        display_game_menu(window, game);
        for (int i = 0 ; i < 3 ; i++)
            sfRenderWindow_drawSprite(window, pause->element[i], NULL);
        if (game->inf)
            display_score(window, pause);
        sfRenderWindow_display(window);
    }
}
